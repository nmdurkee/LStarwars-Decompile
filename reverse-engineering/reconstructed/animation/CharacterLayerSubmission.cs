// PC character render-layer selection and matrix handoffs. GPU consumers external.
using System;
using System.Collections.Generic;
namespace Recovered.Animation
{
    public sealed class CharacterRenderHandle
    {
        public uint Identity,Scene,DisplaySpecial;
    }
    public sealed class CharacterRenderLayer
    {
        public CharacterRenderHandle[] Rigid,AlternateRigid;
        public CharacterRenderHandle Smooth,AlternateSmooth;
    }
    public sealed class CharacterRenderModel
    {
        public CharacterRenderLayer[] Layers;
        public float[][] InverseBind;
        public float[] BoundsMinimum,BoundsMaximum;
    }
    public sealed class CharacterSkinPalette
    {
        public uint Address;
        public float[][] Matrices;
    }
    public sealed class CharacterSubmissionState
    {
        // Original806ccc,966384,9715a0 and*9736e0 respectively.
        public int CachedVisibility,SecondaryVisibilityCount;
        public uint SubmissionFlag,ArenaCursor;
        // Host representation of matrix bytes allocated during submissions.
        public readonly List<CharacterSkinPalette> Palettes=new List<CharacterSkinPalette>();
    }
    public delegate uint CharacterLayerSubmitter(CharacterRenderHandle handle,float[] transform,int mode,CharacterSkinPalette skin,uint morphIdentity);
    public sealed class CharacterSubmissionServices
    {
        // Native5da980 /5ea6a0 and5f9fa0 boundaries, respectively.
        public Func<CharacterRenderModel,float[],float[][],int> ResolveVisibility;
        public Func<float[],float[],int,int> SecondaryVisibility;
        public Action<CharacterRenderModel,float[],float[][]> SubmitAttachments;
        // Native5f0f00. Calls are ordered and return flags are ORed.
        public CharacterLayerSubmitter Submit;
    }
    public static class CharacterLayerSubmission
    {
        static uint Align(uint p,uint unit){return checked(p+unit-1)&~(unit-1);}
        static bool Valid(CharacterRenderHandle h){return h!=null&&h.Scene!=0&&h.DisplaySpecial!=0;}
        //0x5c0500 with the explicitly selected originalD3DX9_35 scalar policy.
        public static float[] Concatenate(float[] local,float[] parent)
        {return SkeletalPose.D3dx9_35ScalarMultiply(local,parent);}
        //0x5c0350. Native advances each matrix pointer by64 per iteration.
        // Portable owned outputs exclude pointer-overlap and negative counts.
        public static float[][] PrepareSkin(float[][] inverseBind,float[][] joints,int count)
        {
            if(count<0||count>256||inverseBind==null||joints==null||count>inverseBind.Length||count>joints.Length)throw new ArgumentException("Valid bounded matrix arrays required");
            var output=new float[count][];for(int i=0;i<count;++i)output[i]=Concatenate(inverseBind[i],joints[i]);return output;
        }
        static float[] Point(float[] p,float[] m)
        {
            if(p==null||p.Length<3||m==null||m.Length!=16)throw new ArgumentException("Point and matrix required");var result=new float[3];
            for(int i=0;i<3;++i)
            {
                var value=PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(p[0]),PlaybackWide.From(m[i])),PlaybackWide.Multiply(PlaybackWide.From(p[1]),PlaybackWide.From(m[4+i]))),PlaybackWide.Multiply(PlaybackWide.From(p[2]),PlaybackWide.From(m[8+i]))),PlaybackWide.From(m[12+i]));result[i]=value.Store();
                if(result[i]==0){double signed=((double)p[0]*m[i]+(double)p[1]*m[4+i])+(double)p[2]*m[8+i]+m[12+i];result[i]=PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(signed)<0?0x80000000u:0u);}
            }
            return result;
        }
        static uint Rigid(CharacterRenderHandle[] handles,float[][] joints,float[] world,CharacterSubmissionServices services)
        {
            if(handles==null)return 0;if(handles.Length<joints.Length)throw new ArgumentException("Per-joint handles required");uint result=0;
            for(int i=0;i<joints.Length;++i)if(handles[i]!=null)
            {
                float[] matrix=Concatenate(joints[i],world);if(Valid(handles[i]))result|=services.Submit(handles[i],matrix,0,null,0);
            }
            return result;
        }
        //0x5f4ff0. Layermap null selects layer0 once when requestedCount>0.
        // Morph pointers are indexed by selection ordinal, not layer ID.
        public static uint Submit(CharacterRenderModel model,float[] world,float[][] joints,int requestedCount,short[] layerMap,uint[] morphIdentities,CharacterSubmissionState state,CharacterSubmissionServices services)
        {
            if(model==null||model.Layers==null||joints==null||joints.Length>256||state==null||services==null||services.Submit==null||services.SubmitAttachments==null)throw new ArgumentException("Resolved model,state and explicit services required");
            if(requestedCount>1000000||requestedCount>0&&layerMap!=null&&requestedCount>layerMap.Length)throw new ArgumentException("Valid bounded selection required");
            int visible=state.CachedVisibility;
            if(visible==-1){if(services.ResolveVisibility==null)throw new ArgumentNullException("ResolveVisibility");visible=services.ResolveVisibility(model,world,joints);}
            int secondary=0;if(state.SecondaryVisibilityCount>0){if(services.SecondaryVisibility==null)throw new ArgumentNullException("SecondaryVisibility");secondary=services.SecondaryVisibility(Point(model.BoundsMinimum,world),Point(model.BoundsMaximum,world),1);}
            int saved=state.CachedVisibility;if(visible==0&&secondary==0){state.SubmissionFlag=0;return 0;}
            state.CachedVisibility=visible;services.SubmitAttachments(model,world,joints);uint flags=0;int count=layerMap==null&&requestedCount>0?1:requestedCount;
            for(int ordinal=0;ordinal<count;++ordinal)
            {
                int id=layerMap==null?0:layerMap[ordinal];if(layerMap!=null&&(id<0||id>=model.Layers.Length))continue;if(id>=model.Layers.Length)throw new ArgumentException("Default layer0 must exist");var layer=model.Layers[id];if(layer==null)throw new ArgumentException("Resolved layer required");
                bool smooth=layer.Smooth!=null||layer.AlternateSmooth!=null;uint paletteAddress=0;
                if(smooth){state.ArenaCursor=Align(state.ArenaCursor,16);paletteAddress=Align(state.ArenaCursor,128);state.ArenaCursor=checked(paletteAddress+(uint)joints.Length*64);}
                uint morph=0;if(morphIdentities!=null){if(ordinal>=morphIdentities.Length)throw new ArgumentException("Morph output required per selection ordinal");morph=morphIdentities[ordinal];}
                flags|=Rigid(layer.Rigid,joints,world,services);flags|=Rigid(layer.AlternateRigid,joints,world,services);
                if(smooth)
                {
                    var palette=new CharacterSkinPalette{Address=paletteAddress,Matrices=PrepareSkin(model.InverseBind,joints,joints.Length)};state.Palettes.Add(palette);
                    if(Valid(layer.Smooth))flags|=services.Submit(layer.Smooth,world,2,palette,morph);
                    if(Valid(layer.AlternateSmooth))flags|=services.Submit(layer.AlternateSmooth,world,2,palette,morph);
                }
            }
            state.CachedVisibility=saved;state.SubmissionFlag=0;return flags;
        }
    }
}
