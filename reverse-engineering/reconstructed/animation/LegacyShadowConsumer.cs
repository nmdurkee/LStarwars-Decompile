// PC legacy104-byte shadow queue scheduling and direction preparation.
using System;
using Recovered.Gameplay;
namespace Recovered.Animation
{
    public sealed class LegacyShadowDirectionState
    {
        public ushort[] AngleTable;
        public float[] SineTable;
        public float[][] Circle=new float[8][]; //9715b0, eight3-float rows
    }
    public sealed class LegacyShadowShapeCall
    {
        public int RecordIndex;
        public uint NativeEntry,Resource,First,Second;
        public float[] Direction;
        public float Upper,Lower;
    }
    public sealed class LegacyShadowConsumerState
    {
        public float[] Camera;
        public LegacyShadowDirectionState Direction;
        public uint GeneratedValue; //971878; shape generators may update it
        public Func<uint,uint[]> ReadPair;
        public Action<LegacyShadowShapeCall> Emit;
    }
    public static class LegacyShadowConsumer
    {
        // The shared wide value merges exact zero signs. These scalar vector
        // formulas retain IEEE zero signs separately through exact operations.
        struct N
        {
            PlaybackWide value;bool negative;
            public N(float v){value=PlaybackWide.From(v);negative=(PcObjectImage.ToBits(v)&0x80000000u)!=0;}
            static N Make(PlaybackWide v,bool z){double d=v.StoreDouble();return new N{value=v,negative=d<0||(d==0&&z)};}
            public static N operator +(N a,N b){return Make(PlaybackWide.Add(a.value,b.value),a.negative&&b.negative);}
            public static N operator -(N a,N b){return Make(PlaybackWide.Add(a.value,PlaybackWide.Multiply(b.value,PlaybackWide.From(-1))),a.negative&&!b.negative);}
            public static N operator *(N a,N b){return Make(PlaybackWide.Multiply(a.value,b.value),a.negative!=b.negative);}
            public float Store(){float v=value.Store();if(Single.IsInfinity(v)||Single.IsNaN(v))throw new ArgumentException("Finite stored shadow values required.");return v==0&&value.StoreDouble()==0?PcObjectImage.FromBits(negative?0x80000000u:0u):v;}
        }
        static void Vector(float[] v){if(v==null||v.Length!=3)throw new ArgumentException("Three finite vector values required.");foreach(float x in v)if(Single.IsNaN(x)||Single.IsInfinity(x))throw new ArgumentException("Finite vector required.");}
        static float Neg(float v){return PcObjectImage.FromBits(PcObjectImage.ToBits(v)^0x80000000u);}
        static float Root(float v){return BuildEffectSound.SquareRoot(v);}
        //0x5e4600. Outputs are pitch then yaw, in native integer-angle units
        //stored as float. Output backing is disjoint from the input vector.
        public static float[] Angles(float[] vector,ushort[] angleTable)
        {
            Vector(vector);if(angleTable==null||angleTable.Length!=513)throw new ArgumentException("Original513-word angle table required.");
            int yaw=PathAngles.Direction(vector[0],vector[2],angleTable);
            float planar=Root((new N(vector[0])*new N(vector[0])+new N(vector[2])*new N(vector[2])).Store());
            return new[]{(float)PathAngles.Direction(Neg(vector[1]),planar,angleTable),(float)yaw};
        }
        static float Sin(float angle,int add,float[] sine)
        {
            int index=PlaybackWide.Add(PlaybackWide.From(angle),PlaybackWide.From(add)).TruncateInt32();return sine[(index>>1)&32767];
        }
        //0x5e4670. In-place pitch then yaw, with the intermediate projectedZ
        //explicitly rounded to float32 before the yaw stage.
        public static void Rotate(float[] vector,float pitch,float yaw,float[] sine)
        {
            Vector(vector);if(sine==null||sine.Length!=32768)throw new ArgumentException("Original sine table required.");
            N sp=new N(Sin(pitch,0,sine)),cp=new N(Sin(pitch,16384,sine)),sy=new N(Sin(yaw,0,sine)),cy=new N(Sin(yaw,16384,sine));
            N x=new N(vector[0]),y=new N(vector[1]),z=new N(vector[2]);float projected=(cp*z+sp*y).Store();
            vector[1]=(y*cp-sp*z).Store();vector[2]=(cy*new N(projected)-sy*x).Store();vector[0]=(new N(projected)*sy+cy*x).Store();
        }
        //0x5e4740. Clamps native pitch to8192, keeps vector magnitude,
        //and regenerates the shared eight-vector ring around that direction.
        public static void Prepare(LegacyShadowDirectionState state,float[] vector)
        {
            if(state==null)throw new ArgumentNullException("state");float[] angles=Angles(vector,state.AngleTable);if(angles[0]<8192)angles[0]=8192;
            float length=Root((new N(vector[1])*new N(vector[1])+new N(vector[0])*new N(vector[0])+new N(vector[2])*new N(vector[2])).Store());
            vector[0]=0;vector[1]=0;vector[2]=length;Rotate(vector,angles[0],angles[1],state.SineTable);
            if(state.Circle==null||state.Circle.Length!=8)throw new ArgumentException("Eight ring rows required.");
            for(int i=0;i<8;++i){float[] row=new[]{state.SineTable[((i*8192+16384)>>1)&32767],Neg(state.SineTable[(i*4096)&32767]),0f};Rotate(row,angles[0],angles[1],state.SineTable);state.Circle[i]=row;}
        }
        static uint U(byte[] b,int p){return(uint)b[p]|(uint)b[p+1]<<8|(uint)b[p+2]<<16|(uint)b[p+3]<<24;}
        static float F(byte[] b,int p){return PcObjectImage.FromBits(U(b,p));}
        //0x5e4840. Shape generation remains an explicit service boundary.
        //Services may update GeneratedValue; they must not mutate queue/camera,
        //direction/ring state, or their supplied argument arrays in this bound.
        //The original routine does not clear queue Count or its records.
        public static void Process(CharacterShadowQueueState queue,LegacyShadowConsumerState state)
        {
            if(queue==null||state==null)throw new ArgumentNullException();state.GeneratedValue=0;
            if(queue.Count<=0)return;if(queue.Count>280||queue.Records==null||queue.Records.Length<queue.Count*104)throw new ArgumentException("Backed native capacity required.");
            Vector(state.Camera);int last=-1;bool accepted=false;float[] direction=null;float upper=10000000,lower=-10000000;byte[] b=queue.Records;
            for(int i=0;i<queue.Count;++i)
            {
                int p=i*104,sequence=b[p+103];
                if(sequence!=last)
                {
                    last=sequence;upper=10000000;lower=-10000000;
                    N x=new N(F(b,p+48))-new N(state.Camera[0]),y=new N(F(b,p+52))-new N(state.Camera[1]),z=new N(F(b,p+56))-new N(state.Camera[2]);
                    float distance=(y*y+x*x+z*z).Store(),maximum=F(b,p+96),fade=F(b,p+92);new N(maximum);new N(fade);
                    accepted=distance<(double)maximum*maximum;if(!accepted)continue;
                    if(F(b,p+76)>=65536)
                    {
                        direction=new[]{0f,-1f,0f};Prepare(state.Direction,direction);direction[1]=-4;
                        upper=F(b,p+80);lower=F(b,p+84);
                    }
                    else
                    {
                        direction=new[]{F(b,p+76),F(b,p+80),F(b,p+84)};Prepare(state.Direction,direction);
                        for(int j=0;j<3;++j)direction[j]=(new N(direction[j])*new N(4)).Store();
                    }
                    //Original computes and discards this fade-region square root.
                    if((double)fade*fade<distance)Root(distance);
                }
                if(!accepted)continue;
                uint resource=U(b,p+68);
                if(resource!=0)for(int j=0;j<b[p+101];++j)state.Emit(new LegacyShadowShapeCall{RecordIndex=i,NativeEntry=0x5e2920,Resource=unchecked(resource+(uint)j*64),Direction=(float[])direction.Clone()});
                resource=U(b,p+64);
                if(resource!=0)for(int j=0;j<b[p+100];++j)state.Emit(new LegacyShadowShapeCall{RecordIndex=i,NativeEntry=0x5e3b50,Resource=unchecked(resource+(uint)j*48),Direction=(float[])direction.Clone(),Upper=upper,Lower=lower});
                resource=U(b,p+72);
                if(resource!=0)for(int j=0;j<b[p+102];++j)
                {
                    //No pair-pointer increment: each iteration rereads same pair.
                    uint[] pair=state.ReadPair(resource);if(pair==null||pair.Length!=2)throw new ArgumentException("Resolved two-word shape pair required.");
                    state.Emit(new LegacyShadowShapeCall{RecordIndex=i,NativeEntry=0x5e4280,First=pair[0],Second=pair[1],Direction=(float[])direction.Clone()});
                }
            }
        }
    }
}
