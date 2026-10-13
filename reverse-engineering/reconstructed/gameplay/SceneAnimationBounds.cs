// Recovered PC bounds producer5ea660/5df480, after animated transform updates.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class SceneAnimationBoundsRecord
    {
        public readonly float[] Values=new float[8];
        // Native stores uninitialized stack data in unused W lanes. The portable
        // contract marks those lanes unknown and preserves their existing bytes.
        public byte KnownMask=255;
    }
    public sealed class SceneAnimationBoundsOwner
    {
        public uint Flags;
        public SceneAnimationBoundsRecord[] Records;
    }
    public sealed class SceneAnimationBoundsReference
    {
        public bool HasScene=true,HasDisplay=true,HasNormalInstance;
        public SceneAnimationBoundsOwner Owner;
        public uint DisplayFlags;
        public int BoundsIndex;
        public float[] LocalMinimum,LocalMaximum;
        public float[] DisplayTransform,DisplayAnimatedTransform;
        // Null represents both native display animation sentinel0 and-1.
        // A normal instance uses only null as its native fallback selector.
        public float[] InstanceTransform,InstanceAnimatedTransform;
    }
    public static class SceneAnimationBounds
    {
        struct W
        {
            PlaybackWide exact;double approx;
            public W(double v){exact=PlaybackWide.FromDouble(v);approx=v;}
            static W Make(PlaybackWide x,double a){return new W{exact=x,approx=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approx+b.approx);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(b.exact,PlaybackWide.From(-1))),a.approx-b.approx);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approx*b.approx);}
            public float Store(){float v=exact.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approx)<0?0x80000000u:0u):v;}
        }
        static W N(double v){return new W(v);}static W S(W v){return N(v.Store());}
        static void Size(float[] v,int count){if(v==null||v.Length!=count)throw new ArgumentException("Invalid scene bounds array");foreach(float x in v)if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite scene bounds inputs required");}
        // 0x5b30a0 point transformation, with all input components read before
        // outputs. Native permits the output to alias the input point.
        public static float[] TransformPoint(float[] matrix,float[] point)
        {
            Size(matrix,16);Size(point,3);float[] result=new float[3];for(int c=0;c<3;++c)result[c]=(N(matrix[c])*N(point[0])+N(matrix[4+c])*N(point[1])+N(matrix[8+c])*N(point[2])+N(matrix[12+c])).Store();return result;
        }
        // 0x5df480: valid resolved owner, display and bounds record. The final
        // native603a10->5f7490 callback is a true no-op in this PC executable.
        public static void Rebuild(SceneAnimationBoundsReference reference)
        {
            if(reference==null||!reference.HasScene||!reference.HasDisplay||reference.Owner==null||reference.Owner.Records==null||reference.BoundsIndex<0||reference.BoundsIndex>=reference.Owner.Records.Length)throw new ArgumentException("Valid scene bounds reference required");
            float[] matrix=reference.HasNormalInstance?(reference.InstanceAnimatedTransform??reference.InstanceTransform):(reference.DisplayAnimatedTransform??reference.DisplayTransform);Size(matrix,16);Size(reference.LocalMinimum,3);Size(reference.LocalMaximum,3);
            float[] half=new float[3],local=new float[3],extent=new float[3];
            for(int i=0;i<3;++i){half[i]=(S(N(reference.LocalMaximum[i])-N(reference.LocalMinimum[i]))*N(.5)).Store();local[i]=(S(N(reference.LocalMinimum[i])+N(reference.LocalMaximum[i]))*N(.5)).Store();}
            for(int c=0;c<3;++c)extent[c]=(N(Math.Abs(matrix[c]))*N(half[0])+N(Math.Abs(matrix[4+c]))*N(half[1])+N(Math.Abs(matrix[8+c]))*N(half[2])).Store();
            float[] center=TransformPoint(matrix,local);float sum=(N(extent[1])+N(extent[0])+N(extent[2])).Store();
            // Original0x5c0240 returns0 for negative input, otherwise sqrtf.
            // This auxiliary W value uses sqrt(ex+ey+ez), not geometric radius.
            float auxiliary=sum<0?0:(float)Math.Sqrt(sum);bool centerFormat=(reference.Owner.Flags&0x4000)!=0;
            var record=reference.Owner.Records[reference.BoundsIndex];if(record==null)throw new ArgumentException("Valid target bounds record required");
            for(int i=0;i<3;++i){record.Values[i]=centerFormat?center[i]:(N(center[i])-N(extent[i])).Store();record.Values[4+i]=centerFormat?extent[i]:(N(center[i])+N(extent[i])).Store();}
            record.KnownMask=(byte)(centerFormat?0x7f:0x77);if(centerFormat)record.Values[3]=auxiliary;
        }
        // 0x5ea660: ownerflag0x10000 gates update; displaydirtybit0x400 is
        // written before the complete native bounds rebuild runs.
        public static bool Notify(SceneAnimationBoundsReference reference)
        {
            if(reference==null||!reference.HasDisplay||!reference.HasScene||reference.Owner==null||(reference.Owner.Flags&0x10000)==0)return false;
            reference.DisplayFlags|=0x400;Rebuild(reference);return true;
        }
    }
}
