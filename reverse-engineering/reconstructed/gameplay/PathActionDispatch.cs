using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public enum PathActionMode { Default4078d0, Variant4813d0, Variant4cbba0 }
    public abstract class PathActionServices
    {
        //52c790 is already recovered as ActorActivation.ChangeBaseState. The
        //host maps this raw processor identity to that existing ScriptPacket.
        public abstract int ChangeBaseState(PathActionWorld world,uint processor,string name);
        //Actual table entry and original arguments. An entry returning zero
        //does not advance to the next matching row; only the tail may follow.
        public abstract int Invoke(uint entry,PathActionWorld world,PcObjectImage reference,uint query);
        //43c9a0 visibility/relocation side effects remain an explicit boundary.
        public abstract int Relocate(PathActionWorld world,uint actor,ReinitializationRecord point,int mode);
    }
    public sealed class PathActionWorld
    {
        public uint OwnerIdentity;
        public PcObjectImage Owner;
        public uint SpecialMask802278;
        public float Gate876ce4;
        public PathActionServices Services;
        public readonly Dictionary<uint,PcObjectImage> Actors=new Dictionary<uint,PcObjectImage>();
        public readonly Dictionary<uint,ReinitializationRecord> Records=new Dictionary<uint,ReinitializationRecord>();
        public readonly Dictionary<uint,ReinitializationRecord[]> Paths=new Dictionary<uint,ReinitializationRecord[]>();
    }
    public static class PathActionDispatch
    {
        const int P=0x2c8;
        static readonly uint[,] DefaultTable={{4,0x406030},{0x23,0x406030},{8,0x4071d0},{0x20000000,0x4074b0},{0x10,0x406770},{0x40,0x407690},{0x1000,0x4069c0},{0x8000,0x407840},{0xc0000,0x406af0},{0x300000,0x406c20}};
        static readonly uint[,] VariantTable={{3,0x480760},{4,0x480e70},{8,0x47fed0},{0x10,0x47f8f0},{0x20000000,0x480fa0},{0x400,0x481180}};
        static readonly uint[,] AlternateTable={{0x23,0x4cc160},{4,0x4cb120},{0x18,0x4cb310},{0x40,0x4cb5e0},{0x1000,0x4cb790},{0x8000,0x4cb930},{0x20000000,0x4cb9c0}};
        static ReinitializationRecord Edge(PathActionWorld w){return w.Records[w.Owner.U32(P+0x15c)];}
        static uint Required(PathActionWorld w){return Edge(w).U32(w.Owner.U8(P+0x160)*4);}
        static bool Run(PathActionWorld world,PcObjectImage reference,uint query,PathActionMode mode)
        {
            PcObjectImage packet=world.Owner;uint actorIdentity=reference.U32(0);PcObjectImage actor=world.Actors[actorIdentity];
            if(actor.U8(0x7b5)==91){ReinitializationRecord attachment=world.Records[actor.U32(0xca4)];attachment.Set32(8,attachment.U32(8)|world.SpecialMask802278);}
            uint required=Required(world);
            if(required!=0&&(required&0x40000000)==0)
            {
                uint supported=packet.U32(P+0x1f4)&required;
                if(mode!=PathActionMode.Variant4813d0&&(required&0x8000)!=0)
                {
                    ReinitializationRecord character=world.Records[actor.U32(0x54)],tuning=world.Records[character.U32(0x24)];
                    if((tuning.U8(0x90)&0x40)==0&&actor.U32(0xea4)==0&&actor.U8(0x7b5)!=60&&(supported&0xffff7fff)==0)
                    {world.Services.ChangeBaseState(world,reference.U32(4),"TakeOverJump");return true;}
                }
                if(supported==0||(required&0x98000000)!=0)
                {
                    for(int i=0;i<3;i++)packet.Set32(P+0x104+i*4,reference.U32(0x5c+i*4));packet.Set32(P+0x110,0);reference.Set16(0x292,reference.U16(0x292)|0x2000);
                    if(mode==PathActionMode.Variant4813d0)packet.Set8(P+0x139,0);return true;
                }
                uint[,] table=mode==PathActionMode.Default4078d0?DefaultTable:mode==PathActionMode.Variant4813d0?VariantTable:AlternateTable;
                for(int i=0;i<table.GetLength(0);i++)if((table[i,0]&supported)!=0)
                {if(world.Services.Invoke(table[i,1],world,reference,query)!=0)return true;break;}
            }
            //Reread edge, direction, flags and gate after the selected handler.
            if((packet.U32(P+0x1e8)&0x20000000)!=0&&(actor.U8(0x7c5)&2)==0&&world.Gate876ce4>0&&(Required(world)&0xd8000000)==0)
            {ReinitializationRecord edge=Edge(world);int opposite=packet.U8(P+0x160)==0?1:0;world.Services.Relocate(world,actorIdentity,world.Paths[packet.U32(P+0x158)][edge.U8(0x10+opposite)],0);}
            return false;
        }
        //0x4078d0, table7ef2c0, selected through407ad0 ->520440.
        public static bool Default(PathActionWorld world,PcObjectImage reference,uint query){return Run(world,reference,query,PathActionMode.Default4078d0);}
        //0x4813d0, table7fa2d0. No TakeOverJump special case; blocked path
        //also clears packet139. Registered through4816b0 ->520440.
        public static bool Variant(PathActionWorld world,PcObjectImage reference,uint query){return Run(world,reference,query,PathActionMode.Variant4813d0);}
        //0x4cbba0, table7fcf10, selected through4cbda0 ->520440.
        public static bool Alternate(PathActionWorld world,PcObjectImage reference,uint query){return Run(world,reference,query,PathActionMode.Variant4cbba0);}
    }
}
