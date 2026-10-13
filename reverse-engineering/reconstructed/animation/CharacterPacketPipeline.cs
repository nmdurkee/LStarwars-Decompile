// Host bridge of original character layers -> normal dynamic object -> packets.
using System;
using System.Collections.Generic;
using Recovered.Geometry;
namespace Recovered.Animation
{
    public sealed class CharacterPacketEnvironment
    {
        public RenderPacketMemory Memory;
        public DynamicSubmissionState Dynamic;
        public uint MatrixScratch;
        public bool CenterBoundsOnRoot;
        public CharacterShadowQueueState Shadows;
        public CharacterShadowBinding[] ShadowBindings;
        public byte SuppressShadow;
        public Func<uint,uint,uint> MergeMaterial;
        // Logical mesh address -> borrowed buffer/delta data. No file loader
        // or graphics-device ownership is implied by this resolved adapter.
        public Func<uint,MorphMeshResource> ResolveMesh;
        public readonly List<DynamicSubmissionResult> Submissions=new List<DynamicSubmissionResult>();
    }
    public static class CharacterPacketPipeline
    {
        static void Store(RenderPacketMemory m,uint address,float[] values)
        {for(int i=0;i<values.Length;++i)m.Block(checked(address+(uint)i*4),BitConverter.GetBytes(values[i]));}
        static void StorePalette(RenderPacketMemory m,CharacterSkinPalette palette)
        {for(int i=0;i<palette.Matrices.Length;++i)Store(m,checked(palette.Address+(uint)i*64),palette.Matrices[i]);}
        // Refines5f4ff0; CharacterLayerSubmission owns the selection loop.
        // Scratch storage, allocator arena, input arrays and mesh records must
        // be disjoint and valid. The two typed states represent shared native
        // globals: the character state is authoritative at entry and exit.
        public static uint Submit(CharacterRenderModel model,float[] world,float[][] joints,int requestedCount,short[] layerMap,uint[] morphIdentities,CharacterSubmissionState state,CharacterPacketEnvironment e)
        {
            if(e==null||e.Memory==null||e.Dynamic==null||state==null)throw new ArgumentNullException();
            if(state.SecondaryVisibilityCount!=0||e.Dynamic.ShadowCount!=0)throw new NotSupportedException("Secondary visibility and dynamic shadows are outside the normal packet bridge.");
            RenderPacketMemory memory=e.Memory;DynamicSubmissionState dynamic=e.Dynamic;
            int firstPalette=state.Palettes.Count;
            var environment=new CharacterPipelineEnvironment{Camera=dynamic.Box,CenterBoundsOnRoot=e.CenterBoundsOnRoot,Shadows=e.Shadows,ShadowBindings=e.ShadowBindings,SuppressShadow=e.SuppressShadow};
            environment.Submit=delegate(CharacterRenderHandle handle,float[] transform,int mode,CharacterSkinPalette palette,uint morph)
            {
                // The native layer reserves smooth storage before its rigid
                // calls, then fills it immediately before smooth submission.
                memory.Dword(dynamic.AllocatorControl,state.ArenaCursor);
                dynamic.ForcedVisibility=state.CachedVisibility;dynamic.ShadowMask=state.SubmissionFlag;
                Store(memory,e.MatrixScratch,transform);if(palette!=null)StorePalette(memory,palette);
                DynamicSubmissionResult result=DynamicObjectSubmission.SubmitWithPackets(memory,dynamic,handle.Identity,e.MatrixScratch,palette==null?0:palette.Address,morph,e.MergeMaterial,
                    delegate(RenderPacketMemory m,DynamicSubmissionState s,DynamicPacketRequest request)
                    {
                        if(m.Byte(request.Command)==0x8f)throw new NotSupportedException("Billboard caller composition is not included in this bridge.");
                        MorphMeshResource resource=null;float[] weights=null;byte[][] matrices=null;
                        if(request.SkinPalette!=0)
                        {
                            if(palette==null||request.SkinPalette!=palette.Address)throw new InvalidOperationException("Skin pointer forwarding changed.");
                            uint mesh=m.Dword(request.Command+4);if(e.ResolveMesh==null)throw new ArgumentNullException("ResolveMesh");resource=e.ResolveMesh(mesh);
                            if(resource==null||resource.SourceAddress!=mesh)throw new ArgumentException("Resolved mesh identity differs.");
                            matrices=new byte[palette.Matrices.Length][];for(int i=0;i<matrices.Length;++i)matrices[i]=m.Block(checked(request.SkinPalette+(uint)i*64),64);
                            uint count=m.Dword(mesh+40);if(count>1000000)throw new ArgumentException("Bounded morph count required.");
                            if(request.MorphWeights!=0){weights=new float[count];for(uint i=0;i<count;++i)weights[i]=BitConverter.ToSingle(m.Block(checked(request.MorphWeights+8+i*4),4),0);}
                        }
                        return SkinMeshPacketDispatch.BuildWithBillboards(m,s.AllocatorControl,request.Record,request.Material,unchecked((int)request.CommandIndex),request.Command,request.Matrix,request.Cache,request.Output,resource,weights,matrices,request.AlphaWord,request.Metadata,s.ScaleScratch,s.TranslationScratch,s.ScratchInputs,null,null);
                    });
                e.Submissions.Add(result);state.ArenaCursor=memory.Dword(dynamic.AllocatorControl);state.SubmissionFlag=dynamic.ShadowMask;return unchecked((uint)result.Visibility);
            };
            uint flags=CharacterRenderPipeline.Submit(model,world,joints,requestedCount,layerMap,morphIdentities,state,environment);
            // Native also fills a reserved palette when every smooth handle
            // is invalid. Such palettes never enter the draw closure above.
            for(int i=firstPalette;i<state.Palettes.Count;++i)StorePalette(memory,state.Palettes[i]);
            memory.Dword(dynamic.AllocatorControl,state.ArenaCursor);dynamic.ForcedVisibility=state.CachedVisibility;dynamic.ShadowMask=state.SubmissionFlag;
            return flags;
        }
    }
}
