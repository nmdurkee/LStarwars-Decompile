// PC55d2b0: predicted center, collision extents and context-adjusted query point.
using System;
namespace Recovered.Animation
{
    public sealed class CharacterBoundsEnvironment
    {
        public float PredictionSeconds; //925018
        public sbyte PrimaryPoint,FallbackPoint; //characterData->gameData+10f/+10d
        public uint[] PointEnabledSlots; //model+14,16 words
        public uint ContextFlags; //CInfo[signed object+7b5].flags at+8
    }
    public static class CharacterPredictedBounds
    {
        // The shared wide representation intentionally merges exact zero signs.
        // Track exact-zero signs separately; rounded double cancellation cannot
        // determine the sign of an x87 zero reliably.
        struct Number
        {
            public PlaybackWide Wide;public bool Negative;
            static Number Make(PlaybackWide w,bool negativeZero){double v=w.StoreDouble();return new Number{Wide=w,Negative=v<0||(v==0&&negativeZero)};}
            public static Number From(float v){return new Number{Wide=PlaybackWide.From(v),Negative=(PcObjectImage.ToBits(v)&0x80000000u)!=0};}
            public static Number operator +(Number a,Number b){return Make(PlaybackWide.Add(a.Wide,b.Wide),a.Negative&&b.Negative);}
            public static Number operator -(Number a,Number b){return Make(PlaybackWide.Add(a.Wide,PlaybackWide.Multiply(b.Wide,PlaybackWide.From(-1))),a.Negative&&!b.Negative);}
            public static Number operator *(Number a,Number b){return Make(PlaybackWide.Multiply(a.Wide,b.Wide),a.Negative!=b.Negative);}
            public float Store(){float v=Wide.Store();if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite stored character bounds required.");if(v==0&&Wide.StoreDouble()==0)v=PcObjectImage.FromBits(Negative?0x80000000u:0u);return v;}
        }
        static Number N(float v){return Number.From(v);}static Number F(PcObjectImage o,int p){return N(o.F32(p));}
        static float[] Read(PcObjectImage o,int p,int count){var v=new float[count];for(int i=0;i<count;++i)v[i]=o.F32(p+i*4);return v;}
        static void Write(PcObjectImage o,int p,float[] v){for(int i=0;i<v.Length;++i)o.SetFloat(p+i*4,v[i]);}
        //0x5b3200. Matrix translation is ignored; output is newly owned.
        public static float[] TransformDirection(float[] vector,float[] matrix)
        {
            if(vector==null||vector.Length!=3||matrix==null||matrix.Length!=16)throw new ArgumentException("Vector and4x4 matrix required.");var output=new float[3];
            for(int i=0;i<3;++i)output[i]=((N(vector[0])*N(matrix[i])+N(vector[1])*N(matrix[4+i]))+N(vector[2])*N(matrix[8+i])).Store();return output;
        }
        //0x5b37d0. Owned output excludes shifted pointer overlap.
        public static float[] AddVectors(float[] first,float[] second)
        {if(first==null||second==null||first.Length!=3||second.Length!=3)throw new ArgumentException("Two vectors required.");var result=new float[3];for(int i=0;i<3;++i)result[i]=(N(first[i])+N(second[i])).Store();return result;}
        static bool Enabled(PcObjectImage o,CharacterBoundsEnvironment e,int slot)
        {
            if(o.U32(0x50)==0||slot<0||slot>=16||e.PointEnabledSlots==null||e.PointEnabledSlots.Length!=16)throw new ArgumentException("Valid model and resolved point slot required.");return e.PointEnabledSlots[slot]!=0;
        }
        //0x55d2b0. This consumes already-written POI matrices at804+slot*64;
        // their translation begins834. It does not generate the skeletal pose.
        public static void Update(PcObjectImage o,CharacterBoundsEnvironment e)
        {
            if(o==null||e==null)throw new ArgumentNullException();Number dt=N(e.PredictionSeconds);uint flags=o.U32(0x1f8)|0x100;o.Set32(0x1f8,flags);bool fallback=true;
            if(o.U8(0x1079)!=0)
            {
                int primary=e.PrimaryPoint;
                if(primary!=-1&&o.U32(0x50)!=0&&Enabled(o,e,primary))
                {
                    fallback=false;
                    if((o.U8(0xe24)&8)!=0)
                    {
                        int point=0x834+primary*64;
                        o.SetFloat(0x80,(F(o,0x74)*dt+F(o,point)).Store());
                        o.SetFloat(0x84,((F(o,0xff4)+F(o,0xff0))*F(o,0xa8)*N(0.5f)+(F(o,0x78)*dt+F(o,point+4))).Store());
                        o.SetFloat(0x88,(F(o,0x7c)*dt+F(o,point+8)).Store());
                    }
                    else
                    {
                        float bottom=PcObjectImage.FromBits(o.U32(0xff0)^0x80000000u);
                        Write(o,0x80,AddVectors(TransformDirection(new[]{0f,bottom,0f},Read(o,0xb8,16)),Read(o,0x5c,3)));
                    }
                    // The primary-POI branch above intentionally predicts twice.
                    for(int i=0;i<3;++i)o.SetFloat(0x80+i*4,(F(o,0x74+i*4)*dt+F(o,0x80+i*4)).Store());
                }
                else if(o.F32(0xd30)==1&&e.FallbackPoint!=-1&&Enabled(o,e,e.FallbackPoint)&&o.U8(0x28c)!=0)
                {fallback=false;for(int i=0;i<3;++i)o.Set32(0x80+i*4,o.U32(0x834+e.FallbackPoint*64+i*4));}
            }
            if(fallback)
            {
                o.Set32(0x1f8,flags^0x100);
                o.SetFloat(0x80,(F(o,0x74)*dt+F(o,0x5c)).Store());
                o.SetFloat(0x84,((F(o,0xff4)+F(o,0xff0))*F(o,0xa8)*N(0.5f)+(F(o,0x78)*dt+F(o,0x60))).Store());
                o.SetFloat(0x88,(F(o,0x7c)*dt+F(o,0x64)).Store());
            }
            o.SetFloat(0x178,(F(o,0x80)-F(o,0x1dc)).Store());o.SetFloat(0x184,(F(o,0x1dc)+F(o,0x80)).Store());
            o.SetFloat(0x180,(F(o,0x88)-F(o,0x1dc)).Store());o.SetFloat(0x18c,(F(o,0x1dc)+F(o,0x88)).Store());
            float low=(F(o,0x84)-F(o,0x1e0)).Store(),high=(F(o,0x1e0)+F(o,0x84)).Store();o.SetFloat(0x17c,low);o.SetFloat(0x188,high);
            foreach(int p in new[]{0x190,0x19c,0x1a8}){o.SetFloat(p,(F(o,0x74)*dt+F(o,0x5c)).Store());o.SetFloat(p+8,(F(o,0x7c)*dt+F(o,0x64)).Store());}
            o.SetFloat(0x194,high);o.SetFloat(0x1a0,low);o.SetFloat(0x1ac,(F(o,0x78)*dt+N(low)).Store());for(int i=0;i<3;++i)o.Set32(0x414+i*4,o.U32(0x1a8+i*4));
            if((e.ContextFlags&0x80000)!=0&&(o.U32(0x7bc)&0x800)!=0)
            {float height=(N(high)-N(low)).Store();o.SetFloat(0x418,(N(height)+F(o,0x418)).Store());return;}
            if((e.ContextFlags&0x100000)!=0)
            {for(int i=0;i<3;++i)o.Set32(0x414+i*4,o.U32(0x5c+i*4));return;}
            float y=(F(o,0x418)-F(o,0xd7c)).Store();o.SetFloat(0x418,y);
            if(y<o.F32(0x21c)&&(F(o,0xb4)+F(o,0x1ac)-F(o,0x21c)).Wide.StoreDouble()>0)o.Set32(0x418,o.U32(0x21c));
        }
    }
}
