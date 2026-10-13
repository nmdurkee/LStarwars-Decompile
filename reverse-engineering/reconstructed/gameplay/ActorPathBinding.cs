// Original PC connection binding and round-robin subroute selection.
// No movement, traversal scheduler or collision response is implied.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public sealed class ActorPathSet
    {
        public byte RouteCount;
        public ReinitializationRecord[] Points;
    }
    public sealed class ActorPathBindingWorld
    {
        public float[] Sine;
        public readonly Dictionary<uint,ActorPathSet> Paths=new Dictionary<uint,ActorPathSet>();
        public readonly Dictionary<uint,ReinitializationRecord> Connections=new Dictionary<uint,ReinitializationRecord>();
    }
    public static class ActorPathBinding
    {
        const int P=0x2c8;
        static ushort Shift16(int count){count&=255;return count<16?(ushort)(1<<count):(ushort)0;}
        static ushort Word(ReinitializationRecord r,int at){return (ushort)(r.Bytes[at]|r.Bytes[at+1]<<8);}
        static float Negate(float value){return PcObjectImage.FromBits(PcObjectImage.ToBits(value)^0x80000000u);}
        static float Add(float x,float y)
        {if(x==0&&y==0)return PcObjectImage.FromBits(PcObjectImage.ToBits(x)&PcObjectImage.ToBits(y)&0x80000000u);return PlaybackWide.Add(PlaybackWide.From(x),PlaybackWide.From(y)).Store();}
        static PlaybackWide Product(float x,float y){return PlaybackWide.Multiply(PlaybackWide.From(x),PlaybackWide.From(y));}
        static float SumProducts(float a,float b,float c,float d)
        {
            if((a==0||b==0)&&(c==0||d==0))return PcObjectImage.FromBits((PcObjectImage.ToBits(a)^PcObjectImage.ToBits(b))&(PcObjectImage.ToBits(c)^PcObjectImage.ToBits(d))&0x80000000u);
            return PlaybackWide.Add(Product(a,b),Product(c,d)).Store();
        }
        static float Divide(float value,float divisor)
        {
            if(divisor==0||Single.IsNaN(divisor)||Single.IsInfinity(divisor))throw new ArgumentException("Finite nonzero connection length required.");
            if(value==0)return PcObjectImage.FromBits((PcObjectImage.ToBits(value)^PcObjectImage.ToBits(divisor))&0x80000000u);
            return PlaybackWide.Divide(PlaybackWide.From(value),PlaybackWide.From(divisor)).Store();
        }
        //0x51b7f0: select from current connection routeMask AND actor membership.
        // Starts at cursor13d, wraps at routeCount, leaves state if none eligible.
        public static void SelectRoute(ActorPathBindingWorld w,PcObjectImage actor)
        {
            ActorPathSet path=w.Paths[actor.U32(P+0x158)];int count=path.RouteCount;uint current=actor.U32(P+0x15c);
            if(count==0||current==0)return;
            ushort mask=(ushort)(Word(w.Connections[current],0x14)&actor.U16(P+0x13a));if(mask==0)return;
            int start=actor.U8(P+0x13d);if(start>=count)start=0;int candidate=start;
            do
            {
                if((Shift16(candidate)&mask)!=0){actor.Set8(P+0x13c,candidate);actor.Set8(P+0x13d,candidate+1);return;}
                if(++candidate>=count)candidate=0;
            }while(candidate!=start);
        }
        //0x51b890: finite valid connection records; direction selects an existing
        // DWORD. Normal authored forward/reverse indices are0/1. Native scalar
        // IDs persist in the image; no address is dereferenced by managed code.
        public static void Bind(ActorPathBindingWorld w,PcObjectImage actor,float x,float z,uint identity,uint direction)
        {
            if(identity==0||actor.U32(P+0xd0)==0){actor.Set32(P+0x15c,identity);actor.Set8(P+0x13c,255);actor.Set8(P+0x13d,0);return;}
            uint old=actor.U32(P+0x15c);ushort flags=actor.U16(P+0x166);
            if(old==identity&&actor.U8(P+0x160)==direction&&((flags&1)==0||(flags&4)!=0))return;
            ReinitializationRecord edge=w.Connections[identity];if(direction>8||edge.Bytes.Length<0x24)throw new ArgumentException("Direction word must fit a36-byte connection record.");
            uint required=edge.U32((int)direction*4);
            if(required!=0)
            {
                // This selects on the OLD current connection; it never assigns
                // the newly requested edge in this branch.
                if((required&0x98000000u)!=0){SelectRoute(w,actor);return;}
                if((actor.U32(P+0x1f4)&required)==0)return;
            }
            if(old!=identity||actor.U8(P+0x160)!=direction)
            {
                actor.Set8(P+0x160,(int)direction);actor.Set32(P+0x15c,identity);actor.Set8(P+0x139,0);
                ReinitializationRecord point=w.Paths[actor.U32(P+0x158)].Points[edge.U8(0x10)];
                float dx=Add(x,Negate(point.F32(4))),dz=Add(z,Negate(point.F32(12)));
                uint angle=unchecked((uint)-(short)Word(edge,0x12));
                if(w.Sine==null||w.Sine.Length!=32768)throw new ArgumentException("Original32768-entry sine table required.");
                float sin=w.Sine[(int)((angle>>1)&32767)],cos=w.Sine[(int)(((angle+16384u)>>1)&32767)];
                float rx=SumProducts(sin,dz,cos,dx),rz=SumProducts(dz,cos,Negate(dx),sin);
                actor.Set16(P+0x166,actor.U16(P+0x166)&~4);actor.SetFloat(P+0x168,Divide(rz,edge.F32(0x1c)));actor.SetFloat(P+0x16c,rx);
            }
            flags=actor.U16(P+0x166);
            if((flags&1)!=0&&(flags&4)==0)
            {
                byte selected=actor.U8(P+0x13c);
                if(selected!=255&&(Shift16(selected)&Word(w.Connections[actor.U32(P+0x15c)],0x14))==0)actor.Set8(P+0x13c,255);
                if(actor.U8(P+0x13c)==255)SelectRoute(w,actor);
                actor.Set16(P+0x166,actor.U16(P+0x166)|4);
            }
        }
    }
    // Host composition only: routes the recovered41c120 BindPath service into
    // the real recovered51b890 body. Every other lifecycle service is forwarded.
    public sealed class PathBindingReinitializationServices:ActorReinitializationServices
    {
        public readonly ActorPathBindingWorld Paths;
        public readonly ActorReinitializationServices Remaining;
        public PathBindingReinitializationServices(ActorPathBindingWorld paths,ActorReinitializationServices remaining)
        {Paths=paths;Remaining=remaining;}
        public override void Invoke(ReinitializationOperation op,ActorReinitializationWorld world,PcObjectImage actor,params uint[] args)
        {
            if(op==ReinitializationOperation.BindPath)
            {
                if(args.Length!=4||args[0]!=world.ActorIdentity+0x2c8||args[1]!=world.ActorIdentity+0x5c)throw new ArgumentException("Expected embedded creature and actor position.");
                ActorPathBinding.Bind(Paths,actor,actor.F32(0x5c),actor.F32(0x64),args[2],args[3]);
            }
            else{if(Remaining==null)throw new ArgumentException("Remaining lifecycle service required.");Remaining.Invoke(op,world,actor,args);}
        }
    }
}
