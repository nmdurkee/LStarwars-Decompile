using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class CorridorPath
    {
        public uint ContextIdentity;
        public byte Marker78;
        public byte[] RefreshedBits=new byte[32];
        public ReinitializationRecord[] Points;
        public float[] Sine;
        //0x51af40 remains an explicit mutable attached-point refresh service.
        public Action<CorridorPath,ReinitializationRecord> Refresh;
    }
    public static class PathCorridor
    {
        static PlaybackWide W(float v){return PlaybackWide.From(v);}
        static PlaybackWide M(PlaybackWide a,PlaybackWide b){return PlaybackWide.Multiply(a,b);}
        static PlaybackWide A(PlaybackWide a,PlaybackWide b){return PlaybackWide.Add(a,b);}
        static PlaybackWide Sub(PlaybackWide a,PlaybackWide b){return A(a,M(W(-1),b));}
        static int Compare(PlaybackWide a,PlaybackWide b)
        {double difference=Sub(a,b).StoreDouble();return difference<0?-1:difference>0?1:0;}
        static float Sub(float a,float b){return a==0&&b==0?PcObjectImage.FromBits(PcObjectImage.ToBits(a)&~PcObjectImage.ToBits(b)&0x80000000u):Sub(W(a),W(b)).Store();}
        static float Mul(float a,float b)
        {return a==0||b==0?PcObjectImage.FromBits((PcObjectImage.ToBits(a)^PcObjectImage.ToBits(b))&0x80000000u):M(W(a),W(b)).Store();}
        static float Products(float a,float b,float c,float d)
        {
            if((a==0||b==0)&&(c==0||d==0))return PcObjectImage.FromBits(PcObjectImage.ToBits(Mul(a,b))&PcObjectImage.ToBits(Mul(c,d))&0x80000000u);
            return A(M(W(a),W(b)),M(W(c),W(d))).Store();
        }
        static SpawnVector Rotate(CorridorPath path,float x,float z,int angle)
        {
            float s=path.Sine[(angle>>1)&32767],c=path.Sine[((angle+16384)>>1)&32767];
            return new SpawnVector(Products(z,s,x,c),0,Products(z,c,-x,s));
        }
        static SpawnVector Position(ReinitializationRecord p){return new SpawnVector(p.F32(4),p.F32(8),p.F32(12));}
        static PlaybackWide Distance(SpawnVector query,ReinitializationRecord point,bool store)
        {
            SpawnVector p=Position(point);float dx=Sub(query.X,p.X),dz=Sub(query.Z,p.Z);PlaybackWide value=A(M(W(dx),W(dx)),M(W(dz),W(dz)));
            return store?W(value.Store()):value;
        }
        static bool Height(ReinitializationRecord point,float y){return point.F32(0x18)<=y&&y<=point.F32(0x20);}
        static ushort U16(ReinitializationRecord r,int p){return (ushort)(r.U8(p)|r.U8(p+1)<<8);}
        static void Refresh(CorridorPath p,int index,ReinitializationRecord point)
        {
            if(point.U8(0x2a)==0||(p.RefreshedBits[index>>3]&(1<<(index&7)))!=0)return;
            if(p.Refresh==null)throw new ArgumentException("Dynamic attached point requires explicit refresh service.");p.Refresh(p,point);
        }
        //0x51b1f0. Original argument5 and8 are unused. stampMode is tested as
        // raw DWORD nonzero, not a float comparison (negative-zero bits count).
        // Finite geometry, positive horizontal length, stable query storage.
        public static bool Contains(CorridorPath path,ReinitializationRecord edge,SpawnVector query,ReinitializationRecord previous,uint route,float margin,uint stampMode,ReinitializationRecord hit)
        {
            if(stampMode!=0){if(edge.U8(0x17)==path.Marker78)return false;edge.Set8(0x17,path.Marker78);}
            int first=edge.U8(0x10),second=edge.U8(0x11);uint count=route&255,mask=count<16?1u<<(int)count:0;
            if(route!=255&&previous!=null&&(U16(edge,0x14)&mask)==0)
            {
                int common=previous.U8(0x10);if(common!=first&&common!=second){common=previous.U8(0x11);if(common!=first&&common!=second)return false;}
                if((U16(path.Points[common],0x5a)&mask)==0)return false;
            }
            ReinitializationRecord p0=path.Points[first],p1=path.Points[second];PlaybackWide threshold=A(W(margin),W(0.05000000074505806f));
            bool small0=Compare(W(p0.F32(0x10)),threshold)<=0,small1=Compare(W(p1.F32(0x10)),threshold)<=0;
            float radius0=small0?p0.F32(0x10):Sub(p0.F32(0x10),margin),radius1=small1?p1.F32(0x10):Sub(p1.F32(0x10),margin);
            Refresh(path,first,p0);Refresh(path,edge.U8(0x11),p1);
            SpawnVector pos=Position(p0);float length=edge.F32(0x1c);if(!(length>0))throw new ArgumentException("Positive finite horizontal length required.");
            SpawnVector local=Rotate(path,Sub(query.X,pos.X),Sub(query.Z,pos.Z),-(short)U16(edge,0x12));PlaybackWide difference=Sub(W(radius1),W(radius0));bool inside;
            if(Math.Abs(difference.Store())<=length)
            {
                if((Math.Abs(local.X)>radius0&&Math.Abs(local.X)>radius1)||local.Z< -radius0||Compare(W(local.Z),A(W(length),W(radius1)))>0)return false;
                short angle=unchecked((short)PathArcSine.Evaluate(PlaybackWide.Divide(difference,W(length)).Store()));SpawnVector rotated=Rotate(path,Math.Abs(local.X),local.Z,-angle);
                if(rotated.Z<0)inside=Height(p0,query.Y)&&Compare(Distance(query,p0,false),M(W(radius0),W(radius0)))<=0;
                else if(Mul(path.Sine[((angle+16384)>>1)&32767],length)<rotated.Z)inside=Height(p1,query.Y)&&Compare(Distance(query,p1,false),M(W(radius1),W(radius1)))<=0;
                else
                {
                    float lower,upper;
                    if(radius0>local.Z){lower=p0.F32(0x18);upper=p0.F32(0x20);}
                    else if(Compare(W(local.Z),Sub(W(length),W(radius1)))>0){lower=p1.F32(0x18);upper=p1.F32(0x20);}
                    else
                    {
                        float amount=PlaybackWide.Divide(Sub(W(local.Z),W(radius0)),Sub(W(length),A(W(radius0),W(radius1)))).Store();PlaybackWide one=Sub(W(1),W(amount));
                        lower=A(M(W(p1.F32(0x18)),W(amount)),M(W(p0.F32(0x18)),one)).Store();upper=A(M(W(p1.F32(0x20)),W(amount)),M(W(p0.F32(0x20)),one)).Store();
                    }
                    inside=lower<=query.Y&&query.Y<=upper&&rotated.X<radius0;
                }
            }
            else
            {
                ReinitializationRecord point=radius0<radius1?p1:p0;float radius=radius0<radius1?radius1:radius0;
                inside=Height(point,query.Y)&&Compare(Distance(query,point,true),M(W(radius),W(radius)))<=0;
            }
            if(inside&&hit!=null)
            {
                hit.Set32(4,edge.Identity);hit.Set8(8,0);ushort flags=(ushort)((U16(hit,0xe)&~8)|(small0||small1?8:0)|1);hit.Set8(0xe,flags);hit.Set8(0xf,flags>>8);
                float progress=local.Z==0?PcObjectImage.FromBits((PcObjectImage.ToBits(local.Z)^PcObjectImage.ToBits(length))&0x80000000u):PlaybackWide.Divide(W(local.Z),W(length)).Store();hit.Set32(0x10,PcObjectImage.ToBits(progress));hit.Set32(0x14,PcObjectImage.ToBits(local.X));
            }
            return inside;
        }
    }
}
