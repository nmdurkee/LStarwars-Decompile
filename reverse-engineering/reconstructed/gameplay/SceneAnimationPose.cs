// Recovered PC ANI4/ANI5 scenery scalar and matrix path. Original observations:
// reports/scene-animation-pose-tests.json. No Unity or renderer dependency.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    // Source payload starts at ANI4/ANI5 magic. ANI5 pointers are field-relative;
    // ANI4 pointers are payload offsets. Native absolute pointers are not accepted.
    // The trailing readable padding used by the native packed-key sampler must
    // accompany the payload, even when the final interpolation fraction is zero.
    public sealed class SceneAnimationClip
    {
        internal readonly byte[] Raw;
        internal readonly int KeyCount, KeyStride, FrameCount, FirstFrame;
        internal readonly int Scales, Constants, Types, Keys;
        public readonly byte Flags;
        public SceneAnimationClip(byte[] payload)
        {
            if(payload==null)throw new ArgumentNullException("payload");Raw=(byte[])payload.Clone();
            uint magic=U32(0);if(magic!=0x414e4934&&magic!=0x414e4935)throw new ArgumentException("ANI4/ANI5 payload required");
            KeyCount=U16(6);KeyStride=U16(8);FrameCount=U16(10);FirstFrame=U16(14);
            if(U16(4)!=1||U16(12)!=9||KeyCount<1||(KeyCount>1&&FrameCount<2))throw new ArgumentException("Single-node nine-channel scenery clip required");
            Scales=Pointer(36,magic);Constants=Pointer(40,magic);Types=Pointer(44,magic);Keys=Pointer(48,magic);Flags=At(Pointer(52,magic));
            Range(Types,27);for(int i=0;i<9;++i){int t=U16(Types+2*i);if(t!=6&&t!=7&&t<16)throw new ArgumentException("Unsupported scene curve type");}
        }
        internal void Range(int p,int count){if(p<0||count<0||p>Raw.Length-count)throw new ArgumentException("Scene payload range exceeds source bytes");}
        internal byte At(int p){Range(p,1);return Raw[p];}
        internal int U16(int p){Range(p,2);return Raw[p]|Raw[p+1]<<8;}
        internal uint U32(int p){Range(p,4);return(uint)Raw[p]|(uint)Raw[p+1]<<8|(uint)Raw[p+2]<<16|(uint)Raw[p+3]<<24;}
        internal float Float(int p){return PcObjectImage.FromBits(U32(p));}
        int Pointer(int p,uint magic){uint v=U32(p);if(v==0)return 0;long result=magic==0x414e4935?(long)unchecked((int)v)+p:v;if(result<0||result>=Raw.Length)throw new ArgumentException("Invalid source-relative animation pointer");return(int)result;}
    }
    public sealed class SceneAnimationPoseBinding
    {
        public ScenePlaybackInstance Instance;
        public SceneAnimationClip Clip;
        public float[] CachedMatrix, TargetMatrix, BaseTranslation;
        // 0x5ea660/0x5df480 bounds and renderer effects are an explicit host step.
        public Action RefreshBounds;
    }
    public static class SceneAnimationPose
    {
        // The shared precision engine normalizes zero. Retain a parallel finite
        // double expression only for the sign when the final float store is zero.
        // Nonzero values and integer truncation always use 64-significand math.
        struct W
        {
            public PlaybackWide Exact;public double Approx;
            public W(double v){Exact=PlaybackWide.FromDouble(v);Approx=v;}
            static W Make(PlaybackWide v,double a){return new W{Exact=v,Approx=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.Exact,b.Exact),a.Approx+b.Approx);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.Exact,PlaybackWide.Multiply(b.Exact,PlaybackWide.From(-1))),a.Approx-b.Approx);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.Exact,b.Exact),a.Approx*b.Approx);}
            public static W operator /(W a,W b){return Make(PlaybackWide.Divide(a.Exact,b.Exact),a.Approx/b.Approx);}
            public float Store(){float v=Exact.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(Approx)<0?0x80000000u:0u):v;}
            public int Truncate(){return Exact.TruncateInt32();}
        }
        static W N(double v){return new W(v);}static W S(W v){return N(v.Store());}
        static void Finite(float v){if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite scene-pose inputs required");}
        static void Size(float[] v,int n){if(v==null||v.Length!=n)throw new ArgumentException("Invalid scene-pose array size");for(int i=0;i<n;++i)Finite(v[i]);}
        static int Word(byte[] raw,int p){if(raw==null||p<0||p>raw.Length-2)throw new ArgumentException("Packed key range exceeds source bytes");return raw[p]|raw[p+1]<<8;}
        static int Factor16(byte[] raw,int p,int q){int a=Word(raw,p+2),b=Word(raw,p+4),c=Word(raw,p+6);return q==3?((b&0xf000)>>8)|((c&0xf000)>>4)|(a>>12):(q==0?a:q==1?b:c)&4095;}
        // 0x5ca830 for valid subkeys0..3 and finite values. Both endpoint values
        // are stored to float32 in the fourth-subkey path before interpolation.
        public static float SamplePacked16(byte[] raw,int offset,int subkey,int stride,float fraction,float scale,float minimum)
        {
            if(subkey<0||subkey>3||stride<1||offset<0||(long)offset+2L*stride+8>Int32.MaxValue)throw new ArgumentException("Invalid packed key shape");
            Finite(fraction);Finite(scale);Finite(minimum);W a=N(Word(raw,offset)),b=N(Word(raw,offset+stride)),v;
            if(subkey<3)
            {W ratio=S((N(Factor16(raw,offset,subkey))+N(fraction)*(N(Factor16(raw,offset,subkey+1))-N(Factor16(raw,offset,subkey))))/N(4095));v=a+ratio*(b-a);}
            else
            {W first=S(a+N(Factor16(raw,offset,3))*(b-a)/N(4095));W second=S(b+N(Factor16(raw,offset+stride,0))*(N(Word(raw,offset+2*stride))-b)/N(4095));v=first+N(fraction)*(second-first);}
            return(v*N(scale)+N(minimum)).Store();
        }
        static W Factor6(SceneAnimationClip c,int p,int q){return S(N((c.U32(p)>>(8+6*q))&63)*N(0.015873020514845848));}
        // Bounded 0x5ce350: one node, all nine channels, no channel mask, and the
        // global forced-end sampling switch off. This is the shipped GSC shape.
        public static float[] Sample(SceneAnimationClip clip,float frame)
        {
            if(clip==null)throw new ArgumentNullException("clip");Finite(frame);
            float key=0;if(clip.KeyCount>1){key=S(S(S(N(frame)-N(clip.FirstFrame))*N(clip.KeyCount-1))/N(clip.FrameCount-1)).Store();key=Math.Max(0,Math.Min(clip.KeyCount-1,key));}
            int whole=(int)key,q=whole&3,p=checked(clip.Keys+(whole/4)*clip.KeyStride),sc=clip.Scales;float fraction=(float)(key-whole);float[] output=new float[9];
            for(int i=0;i<9;++i)
            {
                int t=clip.U16(clip.Types+2*i);float f=(clip.At(clip.Types+18+i)&1)!=0?0:fraction;
                if(t>=16){output[i]=(N(clip.U16(checked(clip.Constants+2*(t-16+clip.At(17)))))*N(clip.Float(32))+N(clip.Float(28))).Store();continue;}
                float scale=clip.Float(sc),minimum=clip.Float(sc+4);sc+=8;
                if(t==7){output[i]=SamplePacked16(clip.Raw,p,q,clip.KeyStride,f,scale,minimum);p+=8;continue;}
                W a=N(clip.At(p)),b=N(clip.At(checked(p+clip.KeyStride))),fa=Factor6(clip,p,q),v;
                if(q<3)v=a+S(fa+N(f)*(Factor6(clip,p,q+1)-fa))*(b-a);
                else{W first=S(a+fa*(b-a));W second=S(b+(N(clip.At(checked(p+2*clip.KeyStride)))-b)*Factor6(clip,p+clip.KeyStride,0));v=first+N(f)*(second-first);}
                output[i]=(v*N(scale)+N(minimum)).Store();p+=4;
            }
            return output;
        }
        static float Sin(int angle,float[] table){float v=table[(angle>>1)&32767];Finite(v);return v;}
        static W Cos(int angle,float[] table){return N(Sin(unchecked(angle+16384),table));}
        // 0x5b5300: integer-angle native lookup convention, row-major row-vector.
        public static float[] Rotation(int x,int y,int z,float[] sineTable)
        {
            if(sineTable==null||sineTable.Length!=32768)throw new ArgumentException("Original 32768-entry sine table required");
            W sx=N(Sin(x,sineTable)),sy=N(Sin(y,sineTable)),sz=N(Sin(z,sineTable)),cx=Cos(x,sineTable),cy=Cos(y,sineTable),cz=Cos(z,sineTable);
            return new float[]{(cy*cz).Store(),(sz*cy).Store(),-Sin(y,sineTable),0,(sx*sy*cz-sz*cx).Store(),(cz*cx+sz*(sx*sy)).Store(),(cy*sx).Store(),0,(sz*sx+cz*(sy*cx)).Store(),((sy*cx)*sz-cz*sx).Store(),(cy*cx).Store(),0,0,0,0,1};
        }
        // 0x5b4c30, finite nonaliased matrix/three-component scale arrays.
        public static void ScaleRows(float[] matrix,float[] scale)
        {Size(matrix,16);Size(scale,3);for(int r=0;r<3;++r)for(int c=0;c<3;++c)matrix[r*4+c]=(N(matrix[r*4+c])*N(scale[r])).Store();}
        // 0x5b4900, finite nonaliased matrix/three-component translation arrays.
        public static void Translate(float[] matrix,float[] translation)
        {Size(matrix,16);Size(translation,3);for(int i=0;i<3;++i)matrix[12+i]=(N(matrix[12+i])+N(translation[i])).Store();}
        // The scene consumer treats channels3..5 as Euler radians regardless of
        // the raw ANI5 format flag. Translation is applied even with flagsbit2off.
        public static float[] Build(float[] values,byte flags,float[] sineTable)
        {
            Size(values,9);float[] matrix=(flags&1)!=0?Rotation((N(values[3])*N(10430.3779296875)).Truncate(),(N(values[4])*N(10430.3779296875)).Truncate(),(N(values[5])*N(10430.3779296875)).Truncate(),sineTable):new float[]{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
            if((flags&8)!=0)ScaleRows(matrix,new float[]{values[6],values[7],values[8]});Translate(matrix,new float[]{values[0],values[1],values[2]});
            foreach(int i in new int[]{2,6,8,9,11,14})matrix[i]=-matrix[i];return matrix;
        }
        // 0x5ea390 (and forwarding thunk0x5f3390) within the bounded clip domain.
        public static float[] Evaluate(SceneAnimationClip clip,float frame,float[] sineTable)
        {if(clip==null)throw new ArgumentNullException("clip");return Build(Sample(clip,(N(frame)-N(1)).Store()),clip.Flags,sineTable);}
        // Matrix tail of0x5f4b90. Reuses the cached curve matrix on unchanged
        // frames, then copies and adds the source special's base translation.
        public static void ApplyWork(ScenePlaybackEvaluation work,SceneAnimationPoseBinding binding,float[] sineTable)
        {
            if(work==null||binding==null||work.Instance!=binding.Instance)throw new ArgumentException("Matching scene-pose work binding required");
            if(work.EvaluatePose)binding.CachedMatrix=Evaluate(binding.Clip,work.Frame,sineTable);
            if(work.CopyPose){Size(binding.CachedMatrix,16);binding.TargetMatrix=(float[])binding.CachedMatrix.Clone();Translate(binding.TargetMatrix,binding.BaseTranslation);}
        }
        // 0x552760 after resolving the native target, clip and base-transform
        // pointers. The bounds callback is ordered after cache and target writes.
        public static bool EvaluateChangedFrame(SceneAnimationPoseBinding binding,float frame,float[] sineTable)
        {
            if(binding==null||binding.Instance==null||binding.Instance.Target==null||binding.Clip==null)return false;
            Finite(frame);if(binding.Instance.PreviousEvaluation==frame)return false;
            binding.TargetMatrix=Evaluate(binding.Clip,frame,sineTable);binding.Instance.PreviousEvaluation=frame;
            binding.CachedMatrix=(float[])binding.TargetMatrix.Clone();Translate(binding.TargetMatrix,binding.BaseTranslation);
            if(binding.RefreshBounds!=null)binding.RefreshBounds();return true;
        }
    }
}
