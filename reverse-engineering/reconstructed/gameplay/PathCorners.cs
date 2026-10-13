using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public static class PathCorners
    {
        const int P=0x2c8;
        struct W
        {
            PlaybackWide exact;double approximate;
            public W(float v){exact=PlaybackWide.From(v);approximate=v;}
            static W Make(PlaybackWide v,double a){return new W{exact=v,approximate=a};}
            public static W operator +(W a,W b){return Make(PlaybackWide.Add(a.exact,b.exact),a.approximate+b.approximate);}
            public static W operator -(W a,W b){return Make(PlaybackWide.Add(a.exact,PlaybackWide.Multiply(PlaybackWide.From(-1),b.exact)),a.approximate-b.approximate);}
            public static W operator *(W a,W b){return Make(PlaybackWide.Multiply(a.exact,b.exact),a.approximate*b.approximate);}
            public static W operator /(W a,W b){return Make(PlaybackWide.Divide(a.exact,b.exact),a.approximate/b.approximate);}
            public float Store(){float v=exact.Store();return v==0?PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(approximate)<0?0x80000000u:0u):v;}
        }
        static SpawnVector Position(ReinitializationRecord p){return new SpawnVector(p.F32(4),p.F32(8),p.F32(12));}
        static SpawnVector Add(SpawnVector a,SpawnVector b){return new SpawnVector((new W(a.X)+new W(b.X)).Store(),(new W(a.Y)+new W(b.Y)).Store(),(new W(a.Z)+new W(b.Z)).Store());}
        static SpawnVector Subtract(SpawnVector a,SpawnVector b){return new SpawnVector((new W(a.X)-new W(b.X)).Store(),(new W(a.Y)-new W(b.Y)).Store(),(new W(a.Z)-new W(b.Z)).Store());}
        static SpawnVector Scale(SpawnVector v,float s){return new SpawnVector((new W(v.X)*new W(s)).Store(),(new W(v.Y)*new W(s)).Store(),(new W(v.Z)*new W(s)).Store());}
        static SpawnVector Rotate(SpawnVector v,int angle,float[] sine)
        {W s=new W(sine[(angle>>1)&32767]),c=new W(sine[((angle+16384)>>1)&32767]);return new SpawnVector((new W(v.Z)*s+new W(v.X)*c).Store(),v.Y,(new W(v.Z)*c-new W(v.X)*s).Store());}
        static int Heading(ReinitializationRecord e){return unchecked((short)(e.U8(0x12)|e.U8(0x13)<<8));}
        static float Radius(ReinitializationRecord p,W margin){float r=(new W(p.F32(0x10))-margin).Store();return r<0?0:r;}
        //0x51c150. Original custom ABI also receives actor in EAX, first edge
        //in ECX and first outer point in EDI. Values are explicit here.
        public static bool Construct(float[] sine,ReinitializationRecord firstEdge,ReinitializationRecord secondEdge,ReinitializationRecord shared,ReinitializationRecord firstOuter,ReinitializationRecord secondOuter,int firstHeading,int secondHeading,float bodyRadius,ref SpawnVector output)
        {
            W margin=new W(bodyRadius)+new W(0.05000000074505806f);float ra=Radius(firstOuter,margin),rc=Radius(shared,margin),rb=Radius(secondOuter,margin),la=firstEdge.F32(0x1c),lb=secondEdge.F32(0x1c);
            int a=PathCornerMath.AddAngles(firstHeading,unchecked((short)PathArcSine.Evaluate(((new W(rc)-new W(ra))/new W(la)).Store()))),b=PathCornerMath.DifferenceAngles(secondHeading,unchecked((short)PathArcSine.Evaluate(((new W(rc)-new W(rb))/new W(lb)).Store())));
            SpawnVector pa=Position(firstOuter),pb=Position(secondOuter),sa=Add(Rotate(new SpawnVector(ra,0,0),a,sine),pa),ea=Add(Rotate(new SpawnVector(ra,0,la),a,sine),pa),sb=Add(Rotate(new SpawnVector(-rb,0,0),b,sine),pb),eb=Add(Rotate(new SpawnVector(-rb,0,lb),b,sine),pb),da=Subtract(ea,sa),db=Subtract(eb,sb);float u,v;
            if(!PathCornerMath.LineParameters(sa,da,sb,db,out u,out v)||u<0||v<0||u>1||v>1)return false;
            sa.Y=(new W(shared.F32(8))*new W(u)+(new W(1)-new W(u))*new W(firstOuter.F32(8))).Store();output=Add(sa,Scale(da,u));return true;
        }
        static SpawnVector Read(PcObjectImage a,int offset){return new SpawnVector(a.F32(P+offset),a.F32(P+offset+4),a.F32(P+offset+8));}
        static void Write(PcObjectImage a,int offset,SpawnVector v){a.SetFloat(P+offset,v.X);a.SetFloat(P+offset+4,v.Y);a.SetFloat(P+offset+8,v.Z);}
        //0x51c430. Cache key is the ordered pair of edge identities only.
        //The caller supplies the path matching packet158; scene backing valid.
        public static bool Update(CorridorPath path,PcObjectImage actor,ReinitializationRecord firstEdge,ReinitializationRecord secondEdge)
        {return Update(path,actor,firstEdge,secondEdge,actor.F32(0xac));}
        //Caller composition can supply a distinct PC reference's body radius.
        public static bool Update(CorridorPath path,PcObjectImage actor,ReinitializationRecord firstEdge,ReinitializationRecord secondEdge,float bodyRadius)
        {
            if(actor.U32(P+0x190)==firstEdge.Identity&&actor.U32(P+0x194)==secondEdge.Identity)return (actor.U32(P+0x1e8)&0x60)!=0;
            actor.Set32(P+0x1e8,actor.U32(P+0x1e8)&~0x60u);actor.Set32(P+0x190,firstEdge.Identity);actor.Set32(P+0x194,secondEdge.Identity);
            int a0=firstEdge.U8(0x10),a1=firstEdge.U8(0x11),b0=secondEdge.U8(0x10),b1=secondEdge.U8(0x11),aa=Heading(firstEdge),ab=Heading(secondEdge),common,first,second;
            if(a0==b0){common=a0;first=a1;second=b1;aa=PathCornerMath.AddAngles(aa,32768);ab=PathCornerMath.AddAngles(ab,32768);}
            else if(a0==b1){common=a0;first=a1;second=b0;aa=PathCornerMath.AddAngles(aa,32768);}
            else if(a1==b0){common=a1;first=a0;second=b1;ab=PathCornerMath.AddAngles(ab,32768);}
            else if(a1==b1){common=a1;first=a0;second=b0;}
            else return false;
            ReinitializationRecord shared=path.Points[common],outerA=path.Points[first],outerB=path.Points[second];
            if(PathCorridor.Contains(path,firstEdge,Position(outerB),firstEdge,actor.U8(P+0x13c),0,1,null))return false;
            SpawnVector output=Read(actor,0x198);bool valid=Construct(path.Sine,firstEdge,secondEdge,shared,outerA,outerB,aa,ab,bodyRadius,ref output);if(valid)Write(actor,0x198,output);actor.Set32(P+0x1e8,(actor.U32(P+0x1e8)&~0x20u)|(valid?0x20u:0));
            output=Read(actor,0x1a4);valid=Construct(path.Sine,secondEdge,firstEdge,shared,outerB,outerA,ab,aa,bodyRadius,ref output);if(valid)Write(actor,0x1a4,output);actor.Set32(P+0x1e8,(actor.U32(P+0x1e8)&~0x40u)|(valid?0x40u:0));return (actor.U32(P+0x1e8)&0x60)!=0;
        }
    }
}
