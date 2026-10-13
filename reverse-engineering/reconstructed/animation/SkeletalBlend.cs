// Finite original-PC Euler blend branch; quaternion alternatives are excluded.
// Exact native observations: reports/animation-skeletal-blend-tests.json.
using System;
namespace Recovered.Animation
{
    public static class SkeletalBlend
    {
        struct W
        {
            PlaybackWide exact;double approx;
            public W(double v){if(Double.IsNaN(v)||Double.IsInfinity(v))throw new ArgumentException("Finite skeletal blend inputs required");exact=PlaybackWide.FromDouble(v);approx=v;}
            static W Make(PlaybackWide v,double a){return new W{exact=v,approx=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approx+b.approx);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(b.exact,PlaybackWide.From(-1))),a.approx-b.approx);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approx*b.approx);}
            public static W operator /(W a,W b){return Make(PlaybackWide.Divide(a.exact,b.exact),a.approx/b.approx);}
            public float Store(){float v=exact.Store();if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite skeletal blend stores required");return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approx)<0?0x80000000u:0u):v;}
            public int Truncate(){return exact.TruncateInt32();}
        }
        static W N(double v){return new W(v);}
        // 0x5cdd50, Euler input/output and target sourceframe through its endpoint.
        // Native frameCount1 division behavior is outside the finite domain.
        // rootTranslation, when supplied, receives unblended target root XYZ with
        // Z negated; it stays untouched if start>0 or no nodes are processed.
        public static int Blend(SkeletalClip clip,float frame,SkeletalEulerBuffer output,float weight,int count,int start,float[] rootTranslation)
        {
            if(clip==null||output==null)throw new ArgumentNullException();N(frame);N(weight);
            if(output.Quaternion||clip.FrameCount<2||frame>clip.FirstFrame+clip.FrameCount-1)throw new ArgumentException("Finite Euler blend endpoint domain required");
            int take=Math.Min(count,clip.NodeCount);if(count<0||start<0||start>clip.NodeCount-take||output.Values.Length<clip.NodeCount)throw new ArgumentException("Invalid Euler blend range");
            if(rootTranslation!=null&&rootTranslation.Length!=3)throw new ArgumentException("Three root-translation values required");
            var sampled=new SkeletalEulerBuffer(clip.NodeCount);SkeletalPose.Sample(clip,frame,sampled,clip.NodeCount,0);float inverseWeight=(N(1)-N(weight)).Store();
            for(int n=start;n<start+take;++n)
            {
                byte flags=sampled.Flags[n];output.Flags[n]|=flags;
                if(output.Values[n]==null||output.Values[n].Length!=9)throw new ArgumentException("Nine Euler values required");
                for(int i=0;i<9;++i)
                {
                    float old=output.Values[n][i],target=sampled.Values[n][i];bool active=(flags&new int[]{2,1,8}[i/3])!=0;
                    if(active)
                    {
                        float delta=(N(target)-N(old)).Store();
                        if(i>=3&&i<6&&(delta>3.1415927410125732||delta< -3.1415927410125732))
                        {
                            int angle=(N(delta)*N(65536)/N(6.2831854820251465)).Truncate()&65535;if(angle>=32768)angle-=65536;delta=(N(angle)*N(9.58738019107841e-05)).Store();
                        }
                        output.Values[n][i]=(N(delta)*N(weight)+N(old)).Store();
                    }
                    else output.Values[n][i]=i>=6?(N(old)*N(inverseWeight)+N(weight)).Store():(N(old)*N(inverseWeight)).Store();
                    if(rootTranslation!=null&&start==0&&n==0&&i<3)rootTranslation[i]=active?(i==2?-target:target):0;
                }
            }
            return 0;
        }
        // 0x5ebb90 computational branch for equal-node-count Euler clips, mode
        // stack depth<4, initial conversion mode0, and no adjustment/root callback.
        // Managed ownership replaces native scratch and global mode-stack writes.
        public static SkeletalPoseResult Evaluate(SkeletalClip source,float sourceFrame,SkeletalClip target,float targetFrame,float weight,SkeletalJoint[] joints,float[] sineTable,SkeletalMatrixConcatenator concatenate)
        {
            if(source==null||target==null||joints==null)throw new ArgumentNullException();if(source.NodeCount!=target.NodeCount)throw new ArgumentException("Equal-node-count clips required for bounded blend wrapper");
            var buffer=new SkeletalEulerBuffer(source.NodeCount);SkeletalPose.Sample(source,(N(sourceFrame)-N(1)).Store(),buffer,joints.Length,0);Blend(target,(N(targetFrame)-N(1)).Store(),buffer,weight,joints.Length,0,null);return SkeletalPose.Build(buffer,joints,source.NodeCount,sineTable,concatenate);
        }
    }
}
