using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class TargetingPath
    {
        public uint Identity;
        public byte PointCount,CandidateCount;
        // Original loops can read index==count before their next entry gate.
        // Supply the observed extra backing row/entry; do not infer its value.
        public ReinitializationRecord[] Points;
        public byte[] CandidateIndices;
        public uint[][] PointConnections;
        public readonly Dictionary<uint,RoutingConnection> Connections=new Dictionary<uint,RoutingConnection>();
    }
    public static class PathTargeting
    {
        const int P=0x2c8;
        static SpawnVector Position(ReinitializationRecord point)
        {return new SpawnVector(point.F32(4),point.F32(8),point.F32(12));}
        static float Distance(TargetingPath path,int index,SpawnVector query)
        {return LocatorCommands.DistanceSquared(Position(path.Points[index]),query,false);}
        //0x51d310: native packet in ESI, path in EDI, query pointer on stack.
        public static void Scan(TargetingPath path,PcObjectImage actor,SpawnVector query)
        {
            float best=Single.MaxValue;bool subset=path.CandidateCount!=0&&(actor.U8(P+0x1ec)&4)!=0;
            if(actor.U8(P+0x143)>=path.PointCount)actor.Set8(P+0x143,255);
            byte limit=subset?path.CandidateCount:path.PointCount;
            if(actor.U8(P+0x142)>=limit)actor.Set8(P+0x142,0);
            if(actor.U8(P+0x143)<path.PointCount)best=Distance(path,actor.U8(P+0x143),query);
            byte start=actor.U8(P+0x142);
            for(int remaining=4;remaining>0;remaining--)
            {
                byte cursor=actor.U8(P+0x142);
                // The subset branch compares selected POINT ID with ORDINAL,
                // not with CandidateIndices[cursor]. Preserve this PC quirk.
                if(!subset||actor.U8(P+0x143)!=cursor)
                {
                    int point=subset?path.CandidateIndices[cursor]:cursor;float distance=Distance(path,point,query);
                    if(distance<best){actor.Set8(P+0x143,point);best=distance;}
                }
                byte next=unchecked((byte)(cursor+1));actor.Set8(P+0x142,next>limit?0:next);
                if(subset&&actor.U8(P+0x142)==start)return;
            }
        }
        //0x51d500: native packet in ECX. No allocation or world callbacks.
        public static bool Materialize(TargetingPath path,PcObjectImage actor)
        {
            byte selected=actor.U8(P+0x143);ReinitializationRecord point=path.Points[selected];
            if(point.U8(0x28)==0)return false;
            for(int i=0;i<3;i++)actor.Set32(P+0x1b4+i*4,point.U32(4+i*4));
            actor.Set32(P+0x1c0,0);
            PlaybackWide radius=PlaybackWide.Add(PlaybackWide.From(point.F32(0x10)),PlaybackWide.From(-1));
            actor.SetFloat(P+0x1c4,point.F32(0x10)<=2?1:radius.Store());
            for(int at=0x1cc;at<=0x1e0;at+=4)actor.Set32(P+at,0);
            actor.Set32(P+0x1cc,path.Identity);uint connection=path.PointConnections[selected][0];actor.Set32(P+0x1d0,connection);
            bool first=path.Connections[connection].Endpoint0==selected;
            actor.Set8(P+0x1d4,first?1:0);actor.SetFloat(P+0x1dc,first?0:1);return true;
        }
        //0x51d750: native packet in EAX. 0=existing target,1=new target,-1=none.
        public static int EnsureTarget(TargetingPath path,PcObjectImage actor)
        {
            if(actor.U32(P+0x158)==actor.U32(P+0x1cc)&&actor.U32(P+0x1d0)!=0)return 0;
            Scan(path,actor,new SpawnVector(actor.F32(P+0x1b4),actor.F32(P+0x1b8),actor.F32(P+0x1bc)));
            return actor.U8(P+0x143)<path.PointCount&&Materialize(path,actor)?1:-1;
        }
        //0x51f6b0. Output is optional and disjoint from native graph backing.
        // The existing routing consumer retains its cache writes/diagnostics.
        public static bool TryNextPoint(RoutingPath path,ReinitializationRecord[] points,uint currentConnection,uint targetConnection,byte direction,byte selectedRoute,int? destination,uint[] output)
        {
            if(currentConnection==targetConnection)return false;
            uint nextDirection=0;uint next=PathRouting.NextConnection(path,currentConnection,direction,selectedRoute,destination,ref nextDirection);
            if(next==0)return false;
            if(output!=null)
            {
                RoutingConnection edge=path.Connections[next];int point=nextDirection==0?edge.Endpoint1:edge.Endpoint0;
                for(int i=0;i<3;i++)output[i]=points[point].U32(4+i*4);
            }
            return true;
        }
    }
}
