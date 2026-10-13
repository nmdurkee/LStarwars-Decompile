// Original packet-to-pose dispatch in the default-layer, no-morph/no-POI branch.
using System;
using System.Collections.Generic;
namespace Recovered.Animation
{
    public sealed class SkeletalPacketModel
    {
        public SkeletalJoint[] Joints;
        public float[][] LocalBindMatrices;
        // The array length represents the native global animation-slot count;
        // null entries preserve missing per-model loaded clips.
        public SkeletalClip[] Clips;
        public int LayerCount;
    }
    public enum SkeletalRequestKind { BindPose, Single, Blend }
    public sealed class SkeletalPoseRequest
    {
        public SkeletalRequestKind Kind;
        public int SourceClip=-1,TargetClip=-1;
        public float SourceFrame,TargetFrame,TargetWeight;
    }
    public static class SkeletalPacketDispatch
    {
        // 0x62e190: original default selector. Null model selects no layers.
        public static int[] SelectLayers(SkeletalPacketModel model,uint mask)
        {
            var result=new List<int>();if(model!=null)for(int i=0;i<Math.Min(32,model.LayerCount);++i)if((mask&(1u<<i))!=0)result.Add(i);return result.ToArray();
        }
        static bool Has(SkeletalClip[] clips,int index){return index>=0&&index<clips.Length&&clips[index]!=null;}
        // Selection sub-contract of0x62e290 after at least one layer was selected.
        // Byte31 is tested for any nonzero value, not just a particular flagbit.
        public static SkeletalPoseRequest Select(AnimationPacket packet,SkeletalClip[] clips)
        {
            if(packet==null||clips==null)throw new ArgumentNullException();
            if(packet.Byte(0x31)!=0)
            {
                int source=packet.Short(0x32),target=packet.Short(0x34);
                if(Has(clips,source)&&Has(clips,target))
                {
                    float numerator=packet.Float(8),denominator=packet.Float(12),weight=PlaybackWide.Divide(PlaybackWide.From(numerator),PlaybackWide.From(denominator)).Store();if(Single.IsNaN(weight)||Single.IsInfinity(weight))throw new ArgumentException("Finite nonzero blend denominator required");if(weight==0)weight=PcObjectImage.FromBits((PcObjectImage.ToBits(numerator)^PcObjectImage.ToBits(denominator))&0x80000000u);
                    return new SkeletalPoseRequest{Kind=SkeletalRequestKind.Blend,SourceClip=source,TargetClip=target,SourceFrame=packet.Float(0x10),TargetFrame=packet.Float(0x14),TargetWeight=weight};
                }
                if(Has(clips,target))return new SkeletalPoseRequest{Kind=SkeletalRequestKind.Single,SourceClip=target,SourceFrame=packet.Float(0x14)};
                if(Has(clips,source))return new SkeletalPoseRequest{Kind=SkeletalRequestKind.Single,SourceClip=source,SourceFrame=packet.Float(0x10)};
            }
            else
            {
                int current=packet.Short(0x36);if(Has(clips,current))return new SkeletalPoseRequest{Kind=SkeletalRequestKind.Single,SourceClip=current,SourceFrame=packet.Float(0)};
            }
            return new SkeletalPoseRequest{Kind=SkeletalRequestKind.BindPose};
        }
        // 0x5d36d0 no-override branch. The native byte loop requires fewer than
        // 256 joints. These are local bind matrices at hierarchy+170, distinct
        // from animation-bind matrices in the96-byte joint records.
        public static SkeletalPoseResult BindPose(SkeletalJoint[] joints,float[][] localBindMatrices,SkeletalMatrixConcatenator concatenate)
        {
            if(joints==null||localBindMatrices==null||concatenate==null)throw new ArgumentNullException();if(joints.Length>=256||localBindMatrices.Length!=joints.Length)throw new ArgumentException("Bounded bind hierarchy required");
            var result=new SkeletalPoseResult{WorldMatrices=new float[joints.Length][],CumulativeScales=new float[0][]};
            for(int i=0;i<joints.Length;++i)
            {
                var joint=joints[i];float[] local=localBindMatrices[i];if(joint==null||(joint.Parent!=255&&joint.Parent>=i)||local==null||local.Length!=16)throw new ArgumentException("Invalid bind hierarchy");
                foreach(float value in local)if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite bind matrix required");
                result.WorldMatrices[i]=joint.Parent==255?(float[])local.Clone():concatenate(local,result.WorldMatrices[joint.Parent]);
            }
            return result;
        }
        // 0x62e290 with original default layer selector, morph outputnull and both
        // POI outputsnull. Null return means no layers selected, so the caller's
        // existing matrix destination must remain unchanged. Packet bytes are
        // never changed. Renderer62fbf0 and root/override callbacks are separate.
        public static SkeletalPoseResult Evaluate(AnimationPacket packet,SkeletalPacketModel model,uint layerMask,float[] sineTable,SkeletalMatrixConcatenator concatenate)
        {
            if(SelectLayers(model,layerMask).Length==0)return null;
            var request=Select(packet,model.Clips);
            if(request.Kind==SkeletalRequestKind.BindPose)return BindPose(model.Joints,model.LocalBindMatrices,concatenate);
            if(request.Kind==SkeletalRequestKind.Single)return SkeletalPose.Evaluate(model.Clips[request.SourceClip],request.SourceFrame,model.Joints,sineTable,concatenate);
            return SkeletalBlend.Evaluate(model.Clips[request.SourceClip],request.SourceFrame,model.Clips[request.TargetClip],request.TargetFrame,request.TargetWeight,model.Joints,sineTable,concatenate);
        }
    }
}
