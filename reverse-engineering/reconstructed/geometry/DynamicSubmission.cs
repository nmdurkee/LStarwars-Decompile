// Bounded normal PC5f0f00 submission, composing recovered CPU helpers.
// Original-x86/Python evidence is separate from pending managed execution.
using System;
using System.Collections.Generic;
using Wide=Recovered.Animation.PlaybackWide;
namespace Recovered.Geometry
{
    public sealed class DynamicSubmissionState
    {
        public int ForcedVisibility=-1,ForcedLod,FilterMode,ShadowCount,ShadowMetadataDisabled;
        public uint ShadowMask,GlobalOverride,OverrideTable,OverrideFirst,OverrideScalarWord;
        public uint AllocatorControl,Shader,SignedByteDescriptor,TokenBase,ScaleScratch,TranslationScratch,CacheScratch,OutputScratch;
        public uint[] ScratchInputs;
        public float[] CameraPosition;
        public DynamicBoxState Box;
    }
    public sealed class DynamicSubmissionResult
    {
        public int Visibility,SelectedLod=-1;
        public float DistanceSquared;
        // Diagnostic material/index/writer tuples, not an original allocation.
        public readonly List<uint[]> Draws=new List<uint[]>();
        public readonly List<uint> DrawRecords=new List<uint>();
    }
    // Logical native addresses retain the resource identity; typed mesh and
    // palette decoding belongs in the explicit packet adapter.
    public sealed class DynamicPacketRequest
    {
        public uint Record,Material,CommandIndex,Command,Matrix,Cache,Output;
        public uint SkinPalette,MorphWeights,AlphaWord;
        public int Metadata;
    }
    public delegate uint DynamicPacketWriter(RenderPacketMemory memory,DynamicSubmissionState state,DynamicPacketRequest request);
    public sealed class DynamicShadowServices
    {
        // Original96d9d0 context addresses and96e550 masks. Evaluate implements
        //5ea6a0(refresh=0), updating Masks and state.ShadowMask(9715a0).
        public uint[] Contexts,Masks;
        public Func<DynamicSubmissionState,float[],float[],int> Evaluate;
    }
    public static class DynamicObjectSubmission
    {
        private static float Finite(float value)
        {if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite dynamic submission math required.");return value;}
        private static float[] Floats(RenderPacketMemory m,uint p,int count)
        {float[] values=new float[count];for(int i=0;i<count;++i)values[i]=Finite(BitConverter.ToSingle(BitConverter.GetBytes(m.Dword(p+(uint)i*4)),0));return values;}
        private static float Distance(float[] a,float[] b)
        {
            if(b==null||b.Length!=3)throw new ArgumentException("Three finite camera coordinates required.");
            Wide sum=Wide.From(0);for(int i=0;i<3;++i){float d=Finite((float)((double)a[i]-Finite(b[i])));Wide x=Wide.From(d);sum=Wide.Add(sum,Wide.Multiply(x,x));}return Finite(sum.Store());
        }
        // Native handle/header/display/LOD/material fields remain logical
        // addresses. Fixed globals and transient stack slots become explicit.
        // Supported: scalar visibility, finite center/distance, ordinary and
        // prefix packets, same-layout material overrides, acyclic chains.
        // Basic entrypoints exclude shadows, sway, active distance fade and
        // billboard packets. Overloads accept explicit CPU service adapters.
        public static DynamicSubmissionResult Submit(RenderPacketMemory m,DynamicSubmissionState s,uint handle,uint matrix)
        {return SubmitWithMaterialMerge(m,s,handle,matrix,null);}
        // Same normal CPU path with explicit5e5020 material-merge service.
        // MaterialLifecycle.Merge is the separately verified composed service;
        // shader factory/device creation remain boundaries in that dependency.
        public static DynamicSubmissionResult SubmitWithMaterialMerge(RenderPacketMemory m,DynamicSubmissionState s,uint handle,uint matrix,Func<uint,uint,uint> mergeMaterial)
        {return SubmitWithPackets(m,s,handle,matrix,0,0,mergeMaterial,null);}
        // PC5f0f00's third stack argument is unused in this normal branch.
        // The fourth (skin palette) selects skin packets independently of the
        // fifth (morph weights). A callback composes SkinMeshPacketDispatch
        // with typed resource resolution; it returns a diagnostic writer ID.
        public static DynamicSubmissionResult SubmitWithPackets(RenderPacketMemory m,DynamicSubmissionState s,uint handle,uint matrix,uint skinPalette,uint morphWeights,Func<uint,uint,uint> mergeMaterial,DynamicPacketWriter packetWriter)
        {return SubmitWithDistanceFade(m,s,handle,matrix,skinPalette,morphWeights,mergeMaterial,packetWriter,null);}
        // Original5df7b0 is exposed as a numeric service. The recovered
        // SceneSubmission.DistanceFade supplies the established finite domain.
        // The previous overloads retain their inactive-fade contract.
        public static DynamicSubmissionResult SubmitWithDistanceFade(RenderPacketMemory m,DynamicSubmissionState s,uint handle,uint matrix,uint skinPalette,uint morphWeights,Func<uint,uint,uint> mergeMaterial,DynamicPacketWriter packetWriter,Func<float,float,float,float> distanceFade)
        {return SubmitWithSway(m,s,handle,matrix,skinPalette,morphWeights,mergeMaterial,packetWriter,distanceFade,null);}
        // The original temporary64-byte sway matrix is projected into a
        // caller-owned disjoint scratch slot returned by this explicit service.
        public static DynamicSubmissionResult SubmitWithSway(RenderPacketMemory m,DynamicSubmissionState s,uint handle,uint matrix,uint skinPalette,uint morphWeights,Func<uint,uint,uint> mergeMaterial,DynamicPacketWriter packetWriter,Func<float,float,float,float> distanceFade,Func<uint,int,int,uint> swayMatrix)
        {return SubmitWithShadows(m,s,handle,matrix,skinPalette,morphWeights,mergeMaterial,packetWriter,distanceFade,swayMatrix,null);}
        // CPU shadow scheduling only. Native volume/record layouts stay in the
        // bounded logical image; visibility math is the recovered explicit
        // service. The GPU shadow backend is outside this method.
        public static DynamicSubmissionResult SubmitWithShadows(RenderPacketMemory m,DynamicSubmissionState s,uint handle,uint matrix,uint skinPalette,uint morphWeights,Func<uint,uint,uint> mergeMaterial,DynamicPacketWriter packetWriter,Func<float,float,float,float> distanceFade,Func<uint,int,int,uint> swayMatrix,DynamicShadowServices shadows)
        {
            if(m==null||s==null)throw new ArgumentNullException();DynamicSubmissionResult result=new DynamicSubmissionResult();if(handle==0)return result;
            if(s.ShadowCount<0||s.ShadowCount>128)throw new ArgumentException("Bounded nonnegative shadow context count required.");
            if(s.ShadowCount!=0&&shadows==null)throw new NotSupportedException("Shadow context and visibility services required.");
            uint special=m.Dword(handle+8);int sway=unchecked((short)m.Word(special+0xca));
            if(sway!=0){if(swayMatrix==null)throw new NotSupportedException("Sway matrix service required.");matrix=swayMatrix(matrix,sway,unchecked((short)m.Word(special+0xc8)));}
            float[] minimum=Floats(m,special+0x80,3),maximum=Floats(m,special+0x90,3),transform=Floats(m,matrix,16);
            int visible=s.ForcedVisibility==-1?DynamicBounds.Classify(s.Box,minimum,maximum,transform,0):s.ForcedVisibility;result.Visibility=visible;
            uint owner=m.Dword(m.Dword(handle)+0x110),instance=m.Dword(special+0xc0),flags=m.Dword(owner+0x48);byte instanceFlags=m.Byte(flags+instance);
            uint priorShadowFlag=0;int shadowVisible=0;
            if((instanceFlags&0x20)!=0&&s.ShadowCount>0)
            {
                priorShadowFlag=s.ShadowMask;if(shadows.Evaluate==null)throw new ArgumentException("Secondary visibility evaluator required.");
                shadowVisible=shadows.Evaluate(s,DynamicBounds.TransformPoints(minimum,transform),DynamicBounds.TransformPoints(maximum,transform));
            }
            if(visible==0&&shadowVisible==0)return result;
            float[] center=new float[3];for(int i=0;i<3;++i)center[i]=Finite((float)((double)Finite((float)((double)minimum[i]+maximum[i]))*0.5));
            center=DynamicBounds.TransformPoints(center,transform);float distance=Distance(center,s.CameraPosition);if(distance<0)distance=0;result.DistanceSquared=distance;
            uint threshold=m.Dword(special+0xbc);List<float> values=new List<float>();
            do {if(values.Count>=1000000)throw new ArgumentException("Bounded terminated LOD list required.");values.Add(Floats(m,threshold+(uint)values.Count*4,1)[0]);} while(values[values.Count-1]!=0);
            int lod=DynamicSelection.SelectLod(values.ToArray(),distance,s.ForcedLod);result.SelectedLod=lod;uint model=m.Dword(special+0xb0)+(uint)lod*12;
            uint alphaWord=0x3f800000,fadeRanges=m.Dword(owner+12);
            if(fadeRanges!=0&&(instanceFlags&0x40)!=0)
            {
                if(distanceFade==null)throw new NotSupportedException("Active distance fade requires the explicit recovered numeric service.");
                float[] range=Floats(m,checked(fadeRanges+instance*8),2);float alpha=distanceFade(distance,range[0],range[1]);
                if(alpha==0){result.Visibility=0;return result;} // no cleanup
                alphaWord=BitConverter.ToUInt32(BitConverter.GetBytes(alpha),0);
            }
            uint count=m.Dword(model);if(count>1000000)throw new ArgumentException("Bounded LOD part count required.");m.Dword(s.CacheScratch,0);
            for(uint i=0;i<count;++i)
            {
                uint materialIndex=m.Dword(m.Dword(model+4)+i*4),source=m.Dword(m.Dword(owner+0x50)+materialIndex*4);
                uint chosen=DynamicSelection.ChooseMaterial(m,source,s.GlobalOverride,s.OverrideTable,mergeMaterial);
                foreach(uint material in DynamicSelection.FilterChain(m,chosen,s.FilterMode))
                {
                    uint commandIndex=m.Dword(m.Dword(model+8)+i*4),command=checked(m.Dword(owner+8)+commandIndex*16);
                    if(visible!=0)
                    {
                        uint record=m.Dword(material+0x3c),materialOwner=m.Dword(record),index=m.Dword(record+4);if(index>1000000)throw new ArgumentException("Nonnegative bounded material index required.");
                        uint ownerFlags=m.Dword(materialOwner+0x74)|2;m.Dword(materialOwner+0x74,ownerFlags);uint bitset=m.Dword(materialOwner+0x58+((ownerFlags>>15)&1)*4),bitAddress=bitset+index/8;m.Byte(bitAddress,(byte)(m.Byte(bitAddress)|(1<<(int)(index&7))));
                        DynamicCommandSupport.SetOverride(m,s.Shader,s.OverrideFirst,s.OverrideScalarWord,material);ShaderContextEmission.Emit(m,s.AllocatorControl,record,s.Shader,s.SignedByteDescriptor,s.TokenBase);
                        EmitPacket(m,s,result,packetWriter,record,material,commandIndex,command,matrix,skinPalette,morphWeights,alphaWord,(instanceFlags&0x20)!=0&&s.ShadowMetadataDisabled==0?1:0);
                    }
                    uint shadowClass=(m.Dword(material+0x40)>>14)&3;
                    if(shadowVisible!=0&&s.ShadowMetadataDisabled==0&&shadowClass!=1&&shadowClass!=3)
                    {
                        if(shadows.Contexts==null||shadows.Contexts.Length<s.ShadowCount||(s.ShadowMask!=0&&(shadows.Masks==null||shadows.Masks.Length<s.ShadowCount)))throw new ArgumentException("Resolved shadow contexts and masks required.");
                        for(int ci=0;ci<s.ShadowCount;++ci)
                        {
                            uint context=shadows.Contexts[ci];int volumes=unchecked((int)m.Dword(context+0x710));if(volumes<0||volumes>128)throw new ArgumentException("Bounded shadow volume count0..128 required.");
                            uint mask=s.ShadowMask==0?UInt32.MaxValue:shadows.Masks[ci];
                            for(int vi=0;vi<volumes;++vi)if(((mask>>(vi&31))&1)!=0)
                            {
                                uint record=checked(context+(uint)vi*0x380+0x2a4+(m.Byte(material+0x268)!=0?0x44u:0));m.Dword(record,owner);
                                DynamicCommandSupport.Reserve(m,s.AllocatorControl,record,1);uint p=m.Dword(record+0x24);m.Byte(p,0x80);m.Byte(p+1,3);m.Dword(p+4,material);m.Dword(record+0x24,p+16);
                                ShadowContextEmission.Emit(m,s.AllocatorControl,record,s.Shader,s.SignedByteDescriptor);
                                EmitPacket(m,s,result,packetWriter,record,material,commandIndex,command,matrix,skinPalette,morphWeights,alphaWord,1);
                            }
                        }
                    }
                }
            }
            DynamicCommandSupport.SetOverride(m,s.Shader,0,0,0);if(priorShadowFlag==0)s.ShadowMask=0;return result;
        }
        private static void EmitPacket(RenderPacketMemory m,DynamicSubmissionState s,DynamicSubmissionResult result,DynamicPacketWriter packetWriter,uint record,uint material,uint commandIndex,uint command,uint matrix,uint skinPalette,uint morphWeights,uint alphaWord,int metadata)
        {
            uint packetFlags=0;byte opcode=m.Byte(command),previous=0;
            if(opcode!=0x8f&&skinPalette==0){packetFlags=m.Dword(material+0xb4);if((packetFlags&0x80000000)!=0&&unchecked((int)commandIndex)>1)previous=m.Byte(command-32);}
            uint writer=DynamicCommandSupport.SelectPacketRoutine(opcode,previous,packetFlags,unchecked((int)commandIndex),skinPalette==0?0:1);
            if(writer==0x5e0490&&packetWriter==null)throw new NotSupportedException("Billboard packet camera/resource adapter required.");
            if(packetWriter!=null)
            {
                DynamicPacketRequest request=new DynamicPacketRequest();request.Record=record;request.Material=material;request.CommandIndex=commandIndex;request.Command=command;request.Matrix=matrix;request.Cache=s.CacheScratch;request.Output=s.OutputScratch;request.SkinPalette=skinPalette;request.MorphWeights=morphWeights;request.AlphaWord=alphaWord;request.Metadata=metadata;
                uint actualWriter=packetWriter(m,s,request);if(actualWriter!=writer)throw new InvalidOperationException("Packet adapter disagrees with original5e0530 dispatch.");
            }
            else if(writer==0x5e0200)OrdinaryMeshPackets.BuildOrdinary(m,s.AllocatorControl,record,command,matrix,s.CacheScratch,s.OutputScratch,alphaWord,metadata,s.ScaleScratch,s.TranslationScratch,s.ScratchInputs);
            else if(writer==0x5e02b0)OrdinaryMeshPackets.BuildWithPrefix(m,s.AllocatorControl,record,command,matrix,s.CacheScratch,s.OutputScratch,alphaWord,s.ScaleScratch,s.TranslationScratch,s.ScratchInputs);
            else throw new NotSupportedException("Skin packet resource adapter required.");
            result.Draws.Add(new uint[]{material,commandIndex,writer});result.DrawRecords.Add(record);
        }
    }
}
