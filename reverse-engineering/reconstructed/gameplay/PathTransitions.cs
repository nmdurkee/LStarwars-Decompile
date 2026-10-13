using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class TransitionPath
    {
        public uint Identity;
        public ReinitializationRecord[] Points;
        //These arrays project the byte7a count and4-byte8c rows.
        public byte[] Candidates;
        public short[] GroupIndices;
    }
    public sealed class PathTransitionWorld
    {
        public ActorReinitializationWorld Binding;
        public readonly Dictionary<uint,TransitionPath> Paths=new Dictionary<uint,TransitionPath>();
        public readonly Dictionary<uint,ReinitializationRecord> Connections=new Dictionary<uint,ReinitializationRecord>();
        //Original group lookup is signed16-bit, then stride8; negative keys may
        //be supplied only when the corresponding native backing was valid.
        public readonly Dictionary<short,uint[]> Groups=new Dictionary<short,uint[]>();
    }
    public static class PathTransitions
    {
        const int P=0x2c8;
        static SpawnVector Position(ReinitializationRecord p){return new SpawnVector(p.F32(4),p.F32(8),p.F32(12));}
        static float Score(float distance,float adjustment)
        {return PlaybackWide.Add(PlaybackWide.From(distance),PlaybackWide.From(-adjustment)).Store();}
        //0x51d1f0. Full candidate list, strict smaller wins, unchanged outputs
        //on failure. The input/output buffers are represented as disjoint values.
        public static bool Nearest(TransitionPath path,SpawnVector query,ref uint point,ref float distance)
        {
            float best=Single.MaxValue;int selected=-1;
            foreach(byte index in path.Candidates){float value=LocatorCommands.DistanceSquared(Position(path.Points[index]),query,false);if(value<best){best=value;selected=index;}}
            if(selected<0)return false;point=(uint)selected;distance=best;return true;
        }
        //0x51d5e0. Finite coordinates and valid original path/group backing.
        public static bool Select(PathTransitionWorld world,PcObjectImage actor,PcObjectImage reference)
        {
            TransitionPath current=world.Paths[actor.U32(P+0x158)];ReinitializationRecord edge=world.Connections[actor.U32(P+0x15c)],first=current.Points[edge.U8(0x10)],second=current.Points[edge.U8(0x11)];
            SpawnVector position=new SpawnVector(reference.F32(0x5c),reference.F32(0x60),reference.F32(0x64));float firstScore=Score(LocatorCommands.DistanceSquared(position,Position(first),false),first.F32(0x14)),secondScore=Score(LocatorCommands.DistanceSquared(position,Position(second),false),second.F32(0x14));
            ReinitializationRecord selected=secondScore<=firstScore?second:first;int link=selected.U8(0x30);if(link>=current.Candidates.Length)return false;
            uint[] group=world.Groups[current.GroupIndices[link]];uint target=actor.U32(P+0x1cc);
            foreach(uint candidate in group)if(candidate==target){ActorReinitialization.BindPathSet(world.Binding,actor,target);return true;}
            float best=Single.MaxValue,distance=firstScore;uint point=0,chosen=0;SpawnVector query=new SpawnVector(actor.F32(P+0x1b4),actor.F32(P+0x1b8),actor.F32(P+0x1bc));
            foreach(uint candidate in group)
            {
                //The PC caller ignores Nearest's Boolean. Empty candidate lists
                //retain the preceding distance, initially endpoint0's score,
                //even when endpoint1 selected this group. Preserve that behavior.
                Nearest(world.Paths[candidate],query,ref point,ref distance);if(distance<best){best=distance;chosen=candidate;}
            }
            if(chosen==0)return false;ActorReinitialization.BindPathSet(world.Binding,actor,chosen);return true;
        }
    }
}
