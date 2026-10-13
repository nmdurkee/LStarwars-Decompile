// Bounded original-PC Euler sampling and skeletal matrix construction.
// Exact native evidence: reports/animation-skeletal-tests.json. This module
// does not select clips, perform quaternion blending, or implement DLL dispatch.
using System;
using Recovered.Gameplay;
namespace Recovered.Animation
{
    public sealed class SkeletalClip
    {
        internal readonly byte[] Raw;
        public readonly int NodeCount;
        internal readonly int KeyCount,KeyStride,FrameCount,FirstFrame,Scales,Constants,Types,Keys,Flags;
        // Source adapter, not a reconstruction of the native file loader.
        // Accepts ANI4 payload offsets or a complete wrapped ANI5 source carrier.
        public SkeletalClip(byte[] source)
        {
            if(source==null)throw new ArgumentNullException("source");Raw=(byte[])source.Clone();
            if(U32(0)!=0x414e4934)
            {
                if(U32(4)!=0x414e4935)throw new ArgumentException("Euler ANI4 or wrapped ANI5 required");
                byte[] payload=new byte[Raw.Length-4];Array.Copy(Raw,4,payload,0,payload.Length);Raw=payload;
                Put(0,0x414e4934);foreach(int p in new int[]{36,40,44,48,52,56}){uint v=U32(p);if(v!=0){long at=(long)unchecked((int)v)+p;if(at<0||at>=Raw.Length)throw new ArgumentException("Invalid ANI5 source pointer");Put(p,(uint)at);}}
            }
            NodeCount=U16(4);KeyCount=U16(6);KeyStride=U16(8);FrameCount=U16(10);FirstFrame=U16(14);
            if((At(19)&1)!=0||U16(12)!=9||NodeCount<1||NodeCount>256||KeyCount<1||(KeyCount>1&&FrameCount<2))throw new ArgumentException("Unsupported Euler clip shape");
            Scales=Offset(36);Constants=Offset(40);Types=Offset(44);Keys=Offset(48);Flags=Offset(52);Range(Flags,NodeCount);Range(Types,NodeCount*18);
            for(int n=0;n<NodeCount;++n)for(int i=0;i<9;++i)if((At(Flags+n)&new int[]{2,1,8}[i/3])!=0){int type=U16(Types+2*(n*9+i));if(type<16&&type!=6)throw new ArgumentException("Unsupported active Euler curve type");}
        }
        internal void Range(int p,int count){if(p<0||count<0||p>Raw.Length-count)throw new ArgumentException("Euler payload range exceeds source bytes");}
        internal byte At(int p){Range(p,1);return Raw[p];}
        internal int U16(int p){Range(p,2);return Raw[p]|Raw[p+1]<<8;}
        internal uint U32(int p){Range(p,4);return(uint)Raw[p]|(uint)Raw[p+1]<<8|(uint)Raw[p+2]<<16|(uint)Raw[p+3]<<24;}
        internal float Float(int p){return PcObjectImage.FromBits(U32(p));}
        void Put(int p,uint v){Range(p,4);for(int i=0;i<4;++i)Raw[p+i]=(byte)(v>>(8*i));}
        int Offset(int p){uint v=U32(p);if(v>Int32.MaxValue)throw new ArgumentException("Invalid Euler source offset");return(int)v;}
    }
    // Nine meaningful values per node: translationXYZ, EulerXYZ, scaleXYZ.
    // Native 48-byte records contain three untouched padding words, not values.
    public sealed class SkeletalEulerBuffer
    {
        public readonly float[][] Values;
        public readonly byte[] Flags;
        public bool Quaternion;
        public SkeletalEulerBuffer(int nodes)
        {if(nodes<0||nodes>256)throw new ArgumentOutOfRangeException("nodes");Values=new float[nodes][];Flags=new byte[nodes];for(int i=0;i<nodes;++i)Values[i]=new float[9];}
    }
    public sealed class SkeletalJoint
    {
        public byte Parent;
        public float[] AnimationBindMatrix;
    }
    public sealed class SkeletalPoseResult
    {
        public float[][] WorldMatrices;
        // Only animated nodes have a newly written native cumulative scale.
        public float[][] CumulativeScales;
    }
    public delegate float[] SkeletalMatrixConcatenator(float[] local,float[] parent);
    public static class SkeletalPose
    {
        struct W
        {
            PlaybackWide exact;double approx;
            public W(double v){exact=PlaybackWide.FromDouble(v);approx=v;}
            static W Make(PlaybackWide v,double a){return new W{exact=v,approx=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approx+b.approx);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(b.exact,PlaybackWide.From(-1))),a.approx-b.approx);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approx*b.approx);}
            public static W operator /(W a,W b){return Make(PlaybackWide.Divide(a.exact,b.exact),a.approx/b.approx);}
            public float Store(){float v=exact.Store();if(Single.IsInfinity(v)||Single.IsNaN(v))throw new ArgumentException("Finite skeletal stores required");return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approx)<0?0x80000000u:0u):v;}
            public int Truncate(){return exact.TruncateInt32();}
        }
        static W N(double v){if(Double.IsNaN(v)||Double.IsInfinity(v))throw new ArgumentException("Finite skeletal inputs required");return new W(v);}
        static W S(W v){return N(v.Store());}
        static void Size(float[] v,int n){if(v==null||v.Length!=n)throw new ArgumentException("Invalid skeletal vector size");for(int i=0;i<n;++i)N(v[i]);}
        static float[] Identity(){return new float[]{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};}
        static W Factor(SkeletalClip c,int p,int q){return S(N((c.U32(p)>>(8+6*q))&63)*N(0.015873020514845848));}
        // 0x5cc0d0 with formatbit0 clear and global0x9737de zero. Per-curve
        // interpolation masks and header constantIndex are not read on this path.
        // start/count refer to native node positions, preserving unselected data.
        public static int Sample(SkeletalClip clip,float frame,SkeletalEulerBuffer output,int count,int start)
        {
            if(clip==null||output==null)throw new ArgumentNullException();N(frame);
            if(count<0||start<0||output.Values.Length<clip.NodeCount)throw new ArgumentException("Invalid Euler output range");int take=Math.Min(count,clip.NodeCount);if(start>clip.NodeCount-take)throw new ArgumentException("Euler start plus clamped count exceeds clip");
            float key=0;if(clip.KeyCount>1){key=S(S(S(N(frame)-N(clip.FirstFrame))*N(clip.KeyCount-1))/N(clip.FrameCount-1)).Store();key=Math.Max(0,Math.Min(clip.KeyCount-1,key));}
            int whole=(int)key,q=whole&3,p=checked(clip.Keys+(whole/4)*clip.KeyStride),sc=clip.Scales;float fraction=(float)(key-whole);output.Quaternion=false;
            for(int n=0;n<start+take;++n)
            {
                byte flag=clip.At(clip.Flags+n);if(n>=start){Size(output.Values[n],9);output.Flags[n]=flag;}
                for(int i=0;i<9;++i)
                {
                    int t=clip.U16(clip.Types+2*(n*9+i));bool active=(flag&new int[]{2,1,8}[i/3])!=0;
                    if(n<start){if(active&&t<16){p=checked(p+4);sc=checked(sc+8);}continue;}
                    if(!active){output.Values[n][i]=i>=6?1:0;continue;}
                    if(t>=16){output.Values[n][i]=(N(clip.U16(checked(clip.Constants+2*(t-16))))*N(clip.Float(32))+N(clip.Float(28))).Store();continue;}
                    W a=N(clip.At(p)),b=N(clip.At(checked(p+clip.KeyStride))),fa=Factor(clip,p,q),v;
                    if(q<3)v=a+S(fa+N(fraction)*(Factor(clip,p,q+1)-fa))*(b-a);
                    else{W first=S(a+fa*(b-a)),second=S(b+(N(clip.At(checked(p+2*clip.KeyStride)))-b)*Factor(clip,p+clip.KeyStride,0));v=first+N(fraction)*(second-first);}
                    output.Values[n][i]=(v*N(clip.Float(sc))+N(clip.Float(sc+4))).Store();p=checked(p+4);sc=checked(sc+8);
                }
            }
            return 0;
        }
        // 0x5b5700: upper3x3 product, zeros outside it except matrix[15]=1.
        public static float[] MultiplyLinear(float[] left,float[] right)
        {Size(left,16);Size(right,16);float[] m=Identity();for(int r=0;r<3;++r)for(int c=0;c<3;++c)m[r*4+c]=((N(left[r*4])*N(right[c])+N(left[r*4+1])*N(right[4+c]))+N(left[r*4+2])*N(right[8+c])).Store();return m;}
        // 0x5b4a50: column-scale all four rows, including translation.
        public static void ScaleColumns(float[] matrix,float[] scale)
        {Size(matrix,16);Size(scale,3);for(int r=0;r<4;++r)for(int c=0;c<3;++c)matrix[r*4+c]=(N(matrix[r*4+c])*N(scale[c])).Store();}
        // Identified original d3dx9_35.dll scalar implementation, RVA0x163599,
        // SHA2562198022938156b790e9cfb0f7997494b66a11a1ad49b395be58251d635b66b26.
        // Explicit policy: this does not reconstruct live DLL CPU/config dispatch.
        public static float[] D3dx9_35ScalarMultiply(float[] local,float[] parent)
        {Size(local,16);Size(parent,16);float[] m=new float[16];for(int r=0;r<4;++r)for(int c=0;c<4;++c)m[r*4+c]=(((N(local[r*4])*N(parent[c])+N(local[r*4+1])*N(parent[4+c]))+N(local[r*4+2])*N(parent[8+c]))+N(local[r*4+3])*N(parent[12+c])).Store();return m;}
        // 0x5e9d90 Euler branch, no root/override callbacks. Parent indices must
        // be topological or255. Matrix concatenation policy is supplied explicitly.
        public static SkeletalPoseResult Build(SkeletalEulerBuffer buffer,SkeletalJoint[] joints,int clipNodeCount,float[] sineTable,SkeletalMatrixConcatenator concatenate)
        {
            if(buffer==null||joints==null||concatenate==null)throw new ArgumentNullException();if(buffer.Quaternion||joints.Length>256||clipNodeCount<0||clipNodeCount>256)throw new ArgumentException("Bounded Euler hierarchy required");
            int count=Math.Min(joints.Length,clipNodeCount);if(buffer.Values.Length<count)throw new ArgumentException("Insufficient sampled nodes");var result=new SkeletalPoseResult{WorldMatrices=new float[joints.Length][],CumulativeScales=new float[count][]};
            for(int i=0;i<joints.Length;++i)
            {
                if(i>=count){result.WorldMatrices[i]=Identity();continue;}var joint=joints[i];if(joint==null||(joint.Parent!=255&&joint.Parent>=i))throw new ArgumentException("Invalid joint parent");
                Size(joint.AnimationBindMatrix,16);float[] v=buffer.Values[i];Size(v,9);byte flag=buffer.Flags[i];int parent=joint.Parent;float[] ps=parent==255?new float[]{1,1,1}:result.CumulativeScales[parent];float[] m;
                if((flag&1)!=0){m=SceneAnimationPose.Rotation((N(v[3])*N(10430.3779296875)).Truncate(),(N(v[4])*N(10430.3779296875)).Truncate(),(N(v[5])*N(10430.3779296875)).Truncate(),sineTable);if((flag&32)!=0)m=MultiplyLinear(m,joint.AnimationBindMatrix);}
                else m=(flag&32)!=0?(float[])joint.AnimationBindMatrix.Clone():Identity();
                float[] scale=(float[])ps.Clone();
                if((flag&8)!=0){SceneAnimationPose.ScaleRows(m,new float[]{v[6],v[7],v[8]});for(int k=0;k<3;++k)scale[k]=(N(ps[k])*N(v[6+k])).Store();}
                if((flag&16)!=0)
                {
                    float[] inv=new float[3];if(ps[0]==0||ps[1]==0||ps[2]==0)scale=new float[3];else for(int k=0;k<3;++k){inv[k]=(N(1)/N(ps[k])).Store();scale[k]=(N(scale[k])*N(inv[k])).Store();}ScaleColumns(m,inv);
                }
                if((flag&2)!=0)SceneAnimationPose.Translate(m,new float[]{v[0],v[1],v[2]});foreach(int k in new int[]{2,6,8,9,11,14})m[k]=-m[k];
                if(parent==255&&(flag&64)!=0)scale=new float[]{1,1,1};result.CumulativeScales[i]=scale;result.WorldMatrices[i]=parent==255?m:concatenate(m,result.WorldMatrices[parent]);Size(result.WorldMatrices[i],16);
            }
            return result;
        }
        // 0x5eb790 single-clip computational branch: external frame starts at1.
        // Native scratch push/pop is replaced by managed buffer ownership; root
        // and adjustment callbacks are absent, as in the verified native branch.
        public static SkeletalPoseResult Evaluate(SkeletalClip clip,float frame,SkeletalJoint[] joints,float[] sineTable,SkeletalMatrixConcatenator concatenate)
        {
            if(clip==null||joints==null)throw new ArgumentNullException();var buffer=new SkeletalEulerBuffer(clip.NodeCount);Sample(clip,(N(frame)-N(1)).Store(),buffer,joints.Length,0);return Build(buffer,joints,clip.NodeCount,sineTable,concatenate);
        }
    }
}
