// Character layers and secondary/shadow packets with explicit billboard camera inputs.
using System;
using Recovered.Geometry;
namespace Recovered.Animation
{
    public static class CharacterBillboardPacketPipeline
    {
        static void Store(RenderPacketMemory m,uint address,float[] values)
        {for(int i=0;i<values.Length;++i)m.Block(checked(address+(uint)i*4),BitConverter.GetBytes(values[i]));}
        static void StorePalette(RenderPacketMemory m,CharacterSkinPalette palette)
        {for(int i=0;i<palette.Matrices.Length;++i)Store(m,checked(palette.Address+(uint)i*64),palette.Matrices[i]);}
        // Refines5f4ff0. Character state owns966384 count and9715a0 flag;
        // secondary holds its planes/masks, and contextAddresses identifies
        // the same volumes' packet records in the bounded logical memory.
        // This bridge requires inactive sway/fade. View/forward are read only by
        // billboard packets; normal mesh resources retain the previous adapter.
        public static uint Submit(CharacterRenderModel model,float[] world,float[][] joints,int requestedCount,short[] layerMap,uint[] morphIdentities,CharacterSubmissionState state,CharacterPacketEnvironment e,SecondaryVisibilityState secondary,uint[] contextAddresses,float[] view,float[] cameraForward)
        {
            if(e==null||e.Memory==null||e.Dynamic==null||state==null||secondary==null)throw new ArgumentNullException();
            if(state.SecondaryVisibilityCount<0||state.SecondaryVisibilityCount>128)throw new ArgumentException("Bounded nonnegative secondary count required.");
            RenderPacketMemory memory=e.Memory;DynamicSubmissionState dynamic=e.Dynamic;int firstPalette=state.Palettes.Count;
            dynamic.ShadowCount=state.SecondaryVisibilityCount;secondary.Count=state.SecondaryVisibilityCount;secondary.CacheFlag=state.SubmissionFlag;
            var shadowServices=new DynamicShadowServices{Contexts=contextAddresses,Masks=secondary.Masks};
            shadowServices.Evaluate=delegate(DynamicSubmissionState s,float[] first,float[] second)
            {
                secondary.Count=s.ShadowCount;secondary.CacheFlag=s.ShadowMask;int visible=SecondaryVisibility.Evaluate(secondary,first,second,0);
                s.ShadowMask=secondary.CacheFlag;state.SubmissionFlag=s.ShadowMask;return visible;
            };
            var environment=new CharacterPipelineEnvironment{Camera=dynamic.Box,CenterBoundsOnRoot=e.CenterBoundsOnRoot,Shadows=e.Shadows,ShadowBindings=e.ShadowBindings,SuppressShadow=e.SuppressShadow};
            environment.Submit=delegate(CharacterRenderHandle handle,float[] transform,int mode,CharacterSkinPalette palette,uint morph)
            {
                memory.Dword(dynamic.AllocatorControl,state.ArenaCursor);dynamic.ForcedVisibility=state.CachedVisibility;dynamic.ShadowMask=state.SubmissionFlag;
                Store(memory,e.MatrixScratch,transform);if(palette!=null)StorePalette(memory,palette);
                DynamicSubmissionResult result=DynamicObjectSubmission.SubmitWithShadows(memory,dynamic,handle.Identity,e.MatrixScratch,palette==null?0:palette.Address,morph,e.MergeMaterial,
                    delegate(RenderPacketMemory m,DynamicSubmissionState s,DynamicPacketRequest request)
                    {
                        if(m.Byte(request.Command)==0x8f)
                            return SkinMeshPacketDispatch.BuildWithBillboards(m,s.AllocatorControl,request.Record,request.Material,unchecked((int)request.CommandIndex),request.Command,request.Matrix,request.Cache,request.Output,null,null,null,request.AlphaWord,request.Metadata,s.ScaleScratch,s.TranslationScratch,s.ScratchInputs,view,cameraForward);
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
                    },null,null,shadowServices);
                e.Submissions.Add(result);state.ArenaCursor=memory.Dword(dynamic.AllocatorControl);state.SubmissionFlag=dynamic.ShadowMask;secondary.CacheFlag=state.SubmissionFlag;return unchecked((uint)result.Visibility);
            };
            uint flags=CharacterSecondaryPipeline.Submit(model,world,joints,requestedCount,layerMap,morphIdentities,state,environment,secondary);
            for(int i=firstPalette;i<state.Palettes.Count;++i)StorePalette(memory,state.Palettes[i]);
            memory.Dword(dynamic.AllocatorControl,state.ArenaCursor);dynamic.ForcedVisibility=state.CachedVisibility;dynamic.ShadowMask=state.SubmissionFlag;secondary.CacheFlag=state.SubmissionFlag;
            return flags;
        }
    }
}
