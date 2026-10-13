// Recovered finite PC BSA constants/type1/type2 curves and morph output branch.
using System;
namespace Recovered.Animation
{
    public sealed class MorphClip
    {
        internal readonly byte[] Raw;
        internal readonly int Header,Curves,Types,Chunks;
        internal readonly uint PointerBase;
        public readonly int LayerCount,ChannelCount;
        public readonly float Duration;
        // Serialized legacy-v2 BSA carrier, not a live absolute-pointer image.
        public MorphClip(byte[] raw)
        {
            if(raw==null)throw new ArgumentNullException("raw");Raw=(byte[])raw.Clone();
            if(U32(0)!=2)throw new ArgumentException("Legacy-v2 BSA required");PointerBase=U32(4);Header=Pointer(8);
            Duration=Float(Header);LayerCount=I16(Header+4);ChannelCount=I16(Header+6);Chunks=I16(Header+8);Curves=Pointer(Header+12);Types=Pointer(Header+16);
            if(Single.IsNaN(Duration)||Single.IsInfinity(Duration)||Duration<1||LayerCount<1||ChannelCount<1||Chunks<1)throw new ArgumentException("Finite positive legacy dimensions required");
            int count=checked(LayerCount*ChannelCount);Range(Curves,checked(count*4));Range(Types,count);for(int i=0;i<count;++i)if(Raw[Types+i]>2)throw new ArgumentException("Only shipped BSA types0,1,2 are supported");
        }
        internal void Range(int p,int n){if(p<0||n<0||p>Raw.Length-n)throw new ArgumentException("Legacy source range exceeded");}
        internal byte Byte(int p){Range(p,1);return Raw[p];}
        internal sbyte SignedByte(int p){return unchecked((sbyte)Byte(p));}
        internal int U16(int p){Range(p,2);return Raw[p]|Raw[p+1]<<8;}
        internal short I16(int p){return unchecked((short)U16(p));}
        internal uint U32(int p){Range(p,4);return(uint)Raw[p]|(uint)Raw[p+1]<<8|(uint)Raw[p+2]<<16|(uint)Raw[p+3]<<24;}
        internal float Float(int p){float v=PcObjectImage.FromBits(U32(p));if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite morph values required");return v;}
        internal int Pointer(int p){long at=(long)U32(p)-PointerBase;if(at<0||at>=Raw.Length)throw new ArgumentException("Invalid serialized legacy pointer");return(int)at;}
    }
    public sealed class MorphTime
    {
        public float Frame,LocalFrame;
        public int Chunk,Mask,ByteIndex,Subframe;
    }
    public static class MorphWeights
    {
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
        }
        static W N(double v){return new W(v);}static W S(W v){return N(v.Store());}
        static void Finite(float v){if(System.Single.IsNaN(v)||System.Single.IsInfinity(v))throw new ArgumentException("Finite morph input required");}
        static int Pop(uint v){int n=0;while(v!=0){v&=v-1;++n;}return n;}
        // Legacy branch0x5c9c40. Duration1 early return leaves native local-frame
        // and subframe lanes untouched; these two fields are not claimed there.
        public static MorphTime PrepareTime(MorphClip clip,float frame)
        {
            if(clip==null)throw new ArgumentNullException("clip");Finite(frame);
            if(frame>=clip.Duration){if(clip.Duration==1)return new MorphTime{Frame=1,Chunk=0,Mask=1,ByteIndex=0};frame=(N(clip.Duration)-N(.01)).Store();}
            else if(frame<1)frame=1;
            if(frame>Int32.MaxValue-64)throw new ArgumentException("Native truncation range exceeded");
            int chunk=Math.Min(((int)frame-1)>>5,clip.Chunks-1);float local=(N(frame)-N(chunk<<5)).Store();int sub=(int)local-1;
            if(sub<0||sub>31)throw new ArgumentException("Valid legacy chunk time required");
            return new MorphTime{Frame=frame,LocalFrame=local,Chunk=chunk,Mask=((1<<((sub%8)+1))-1)&255,ByteIndex=sub/8,Subframe=sub};
        }
        //0x5c9520 branches1/2, with type0 read performed by the morph caller.
        public static float SampleCurve(MorphClip clip,int index,MorphTime time)
        {
            if(clip==null||time==null)throw new ArgumentNullException();if(index<0||index>=clip.LayerCount*clip.ChannelCount)throw new ArgumentException("Invalid curve index");
            int at=clip.Curves+index*4,kind=clip.Byte(clip.Types+index);if(kind==0)return clip.Float(at);
            int d=clip.Pointer(at),masks=clip.Pointer(d),offsets=clip.Pointer(d+4),data=clip.Pointer(d+8);uint packed=clip.U32(masks+4*time.Chunk);int active=0;
            for(int i=0;i<time.ByteIndex;++i)active+=Pop((packed>>(8*i))&255);active+=Pop(((packed>>(8*time.ByteIndex))&255)&(uint)time.Mask);int key=clip.U16(offsets+2*time.Chunk)+active;
            W a,b,u,m0,m1;
            if(kind==1)
            {
                at=checked(data+(key-1)*16);a=N(clip.Float(at+8));b=N(clip.Float(at+24));u=S((N(time.Frame)-N(clip.Float(at)))*N(clip.Float(at+4)));W span=S(N(clip.Float(at+16))-N(clip.Float(at)));m0=S(span*N(clip.Float(at+12)));m1=S(span*N(clip.Float(at+28)));
            }
            else
            {
                at=checked(data+4+key*4);W span=N(clip.Byte(at+7)-clip.Byte(at+3)),reciprocal=span.Store()!=0?S(N(1)/span):N(0),tangent=N(clip.Float(data)),scale=N(clip.Float(data+4));
                m0=S(N(clip.SignedByte(at+2))*span*tangent);m1=S(N(clip.SignedByte(at+6))*span*tangent);a=S(N(clip.I16(at))*scale);b=S(N(clip.I16(at+4))*scale);u=S((N(time.Frame)-N(1)-N(clip.Byte(at+3)))*reciprocal);
            }
            W delta=a-b,coefficient=S(((u*((delta*N(2)+m0)+m1)-delta*N(3))-m0*N(2))-m1);float value=((coefficient*u+m0)*u+a).Store();Finite(value);return value;
        }
        static float[] Layer(MorphClip clip,int layer,MorphTime time)
        {
            if(layer<0)throw new ArgumentException("Nonnegative selected layers required");if(clip==null||layer>=clip.LayerCount)return new float[0];var row=new float[clip.ChannelCount];for(int i=0;i<row.Length;++i)row[i]=SampleCurve(clip,layer*clip.ChannelCount+i,time);return row;
        }
        //0x5d3a20 successful-allocation branch. Null layer map selects only0.
        // Empty map or null clip returnsnull; out-of-range layer yields emptyrow.
        // Managed owned arrays replace native pool allocations, not their layout.
        public static float[][] Single(MorphClip clip,float frame,int[] layers)
        {
            if(clip==null||(layers!=null&&layers.Length==0))return null;MorphTime time=PrepareTime(clip,frame);int[] ids=layers??new int[]{0};var output=new float[ids.Length][];for(int i=0;i<ids.Length;++i)output[i]=Layer(clip,ids[i],time);return output;
        }
        //0x5d3dc0 successful-allocation branch, nonnegative selected layer IDs.
        // Missing source/target channels contributezero; retain double1-weight.
        public static float[][] Blend(MorphClip source,float sourceFrame,MorphClip target,float targetFrame,float weight,int[] layers)
        {
            if((source==null&&target==null)||(layers!=null&&layers.Length==0))return null;Finite(weight);MorphTime st=source==null?null:PrepareTime(source,sourceFrame),tt=target==null?null:PrepareTime(target,targetFrame);int[] ids=layers??new int[]{0};var output=new float[ids.Length][];W inverse=N(1.0-(double)weight);
            for(int i=0;i<ids.Length;++i){float[] a=Layer(source,ids[i],st),b=Layer(target,ids[i],tt);output[i]=new float[Math.Max(a.Length,b.Length)];for(int j=0;j<output[i].Length;++j){float v=(N(j<b.Length?b[j]:0)*N(weight)+N(j<a.Length?a[j]:0)*inverse).Store();Finite(v);output[i][j]=v;}}
            return output;
        }
        static bool Valid(MorphClip[] clips,int i){return i>=0&&i<clips.Length&&clips[i]!=null;}
        // Morph branch0x62e290, default layer selector. A false return means no
        // selected layers: preserve the caller's previous output. True+null means
        // selected layers but no applicable morphclip: native writesnull.
        public static bool EvaluatePacket(AnimationPacket packet,MorphClip[] clips,int layerCount,uint mask,out float[][] weights)
        {
            weights=null;if(packet==null||clips==null)throw new ArgumentNullException();var ids=new System.Collections.Generic.List<int>();for(int i=0;i<Math.Min(layerCount,32);++i)if((mask&(1u<<i))!=0)ids.Add(i);if(ids.Count==0)return false;int[] layers=ids.ToArray();
            if(packet.Byte(49)!=0)
            {
                int a=packet.Short(50),b=packet.Short(52);
                if(Valid(clips,a)&&Valid(clips,b)){float denominator=packet.Float(12);Finite(denominator);Finite(packet.Float(8));if(denominator==0)throw new ArgumentException("Nonzero finite blend denominator required");float w=(N(packet.Float(8))/N(denominator)).Store();weights=Blend(clips[a],packet.Float(16),clips[b],packet.Float(20),w,layers);}
                else if(Valid(clips,b))weights=Single(clips[b],packet.Float(20),layers);
                else if(Valid(clips,a))weights=Single(clips[a],packet.Float(16),layers);
            }
            else{int i=packet.Short(54);if(Valid(clips,i))weights=Single(clips[i],packet.Float(0),layers);}return true;
        }
    }
}
