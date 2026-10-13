// Handwritten original-PC actor targeting and state-control contracts.
// Evidence: reports/gameplay-actor-state-contract.json. Runtime record loading
// and consumers of these state bits remain separate integration boundaries.
using System;
using System.Collections.Generic;
using System.Globalization;

namespace Recovered.Gameplay
{
    public sealed class ActorStateDefinition
    {
        public string Name;
        public uint Flags;
    }
    public sealed class ActorStateSpawn
    {
        public string Name;
        public short DefinitionIndex;
    }
    public sealed class ActorStateRecord
    {
        public int Id;
        // First pointer in the reference record is a separate world object.
        public ActorStateRecord WorldObject;
        public ActorStateDefinition Definition;
        public short Type;
        public byte SpawnIndex=255;
        public float X,Y,Z;
        public uint Flags1f8,Flags1fc,WeaponFlagsEec,ProtectionFlagsEf0;
        public uint Flags4b0,Membership4bc,OpponentEc0,OpponentEc4,Opponent3ac;
    }
    public sealed class ActorStateWorld
    {
        public bool SystemPresent=true,NameCallback=true,TypeNameCallback=true,TypeIndexCallback=true;
        public readonly List<ActorStateRecord> Actors=new List<ActorStateRecord>();
        public readonly List<ActorStateDefinition> Definitions=new List<ActorStateDefinition>();
        public readonly List<ActorStateSpawn> Spawns=new List<ActorStateSpawn>();
        // Null represents an absent native table. At least 65 slots are needed
        // for a full 64-entry scan and the distinct Everyone index 64.
        public short[] TypeTable;
        public int ActiveCount;
        public ActorStateRecord PrimaryPlayer;
        public readonly ActorStateRecord[] Players=new ActorStateRecord[8];
        public uint GoodMask,BadMask;
        // Optional observation hook; never substitutes lookup behavior.
        public Action<string,object> Observe;

        internal static bool Equal(string a,string b){return String.Equals(a,b,StringComparison.OrdinalIgnoreCase);}
        internal void Event(string kind,object value){if(Observe!=null)Observe(kind,value);}
        internal ActorStateDefinition DefinitionAt(int index)
        {if(index<0||index>=Definitions.Count)throw new ArgumentOutOfRangeException("definitionIndex");return Definitions[index];}
        internal ActorStateSpawn SpawnAt(int index)
        {if(!SystemPresent||index<0||index>=Spawns.Count)throw new ArgumentOutOfRangeException("spawnIndex");return Spawns[index];}
        internal void CheckCount()
        {if(ActiveCount<0||ActiveCount>Actors.Count)throw new ArgumentOutOfRangeException("ActiveCount");}

        // 0x43c220: actual callback registered at global 0x923904 by 0x43c830.
        public ActorStateRecord FindReference(string name)
        {
            MessageNumbers.RequireAscii(name);Event("name",name);
            if(SystemPresent)
            {
                CheckCount();
                for(int i=0;i<ActiveCount;i++)
                {
                    ActorStateRecord actor=Actors[i];
                    if((actor.Flags1fc&1)==0)continue;
                    if((actor.Flags1f8&0x400)!=0&&actor.SpawnIndex!=255&&Equal(SpawnAt(actor.SpawnIndex).Name,name))return actor;
                    if(actor.Definition==null)throw new InvalidOperationException("An active native actor requires a definition.");
                    if(Equal(actor.Definition.Name,name))return actor;
                }
            }
            if(Equal(name,"player"))return PrimaryPlayer;
            if(Equal(name,"player_2"))return Object.ReferenceEquals(Players[0],PrimaryPlayer)?Players[1]:Players[0];
            for(int i=0;i<8;i++)
                if(Players[i]!=null&&Equal(name,"Player"+i.ToString(CultureInfo.InvariantCulture)))return Players[i];
            return null;
        }
        // 0x440120: callback availability followed by one pointer dereference.
        public ActorStateRecord ResolveObject(string name)
        {
            ActorStateRecord reference=NameCallback?FindReference(name):null;
            return reference==null?null:reference.WorldObject;
        }
        // 0x43bc00: Everyone precedes the absent-table check, returns slot64.
        public byte FindTypeIndex(string name)
        {
            MessageNumbers.RequireAscii(name);Event("type",name);
            if(Equal(name,"Everyone"))return 64;
            if(TypeTable!=null)
                for(int i=0;i<64;i++)
                {
                    if(i>=TypeTable.Length)throw new ArgumentException("Native type-table backing is incomplete.");
                    short index=TypeTable[i];if(index==-1)break;
                    if(Equal(DefinitionAt(index).Name,name))return (byte)i;
                }
            return 255;
        }
        // 0x43bed0: direct signed-short lookup. There is no native <64 guard.
        public int ResolveTypeIndex(byte index)
        {
            Event("typeIndex",(int)index);
            if(index==255||TypeTable==null)return -1;
            if(index>=TypeTable.Length)throw new ArgumentException("Native type-table backing is incomplete.");
            return TypeTable[index];
        }
    }

    public static class ActorStateCommands
    {
        static bool Match(string text,string key,out int offset){offset=text.IndexOf(key,StringComparison.OrdinalIgnoreCase);return offset>=0;}
        static string Tail(string text,int offset,int skip)
        {if(offset+skip>text.Length)throw new ArgumentException("Native token skip passes its terminator.");return text.Substring(offset+skip);}
        static void AddType(ActorStateWorld world,List<int> types,string name)
        {
            if(!world.TypeNameCallback||!world.TypeIndexCallback)return;
            byte index=world.FindTypeIndex(name);if(index==255)return;
            int type=world.ResolveTypeIndex(index);
            // Native still resolves overflow tokens before checking the cap.
            if(type!=-1&&types.Count<10)types.Add(type);
        }
        static bool Eligible(ActorStateRecord actor)
        {return (actor.Flags1fc&0x1001)==0x1001&&(actor.Flags1f8&0x400)!=0;}
        static List<ActorStateRecord> Targets(ActorStateWorld world,List<int> types,ActorStateRecord target)
        {
            List<ActorStateRecord> result=new List<ActorStateRecord>();
            if(types.Count==0){if(target!=null)result.Add(target);return result;}
            world.CheckCount();
            for(int i=0;i<world.ActiveCount;i++)
                if(Eligible(world.Actors[i])&&types.Contains(world.Actors[i].Type))result.Add(world.Actors[i]);
            return result;
        }
        static int Toggle(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first,bool protection)
        {
            if(!first)return 1;
            ActorStateRecord target=reference==null?null:reference.WorldObject;
            List<int> types=new List<int>();bool enabled=true,still=false;
            foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int at;
                if(Match(token,"type",out at))AddType(world,types,Tail(token,at,5));
                else if(Match(token,"character=",out at))target=world.ResolveObject(Tail(token,at,10));
                else if(ActorStateWorld.Equal(token,"FALSE"))enabled=false;
                else if(protection&&ActorStateWorld.Equal(token,"still_do_take_hit_anim"))still=true;
            }
            foreach(ActorStateRecord actor in Targets(world,types,target))
            {
                if(!protection)actor.Flags1fc=(actor.Flags1fc&~2u)|(enabled?2u:0u);
                else if((actor.Flags1f8&0x400)!=0)
                    actor.ProtectionFlagsEf0=enabled?(actor.ProtectionFlagsEf0&~0x1000u)|0x400000u|(still?0x1000u:0u):actor.ProtectionFlagsEf0&~0x400000u;
            }
            return 1;
        }
        // 0x4497b0, game override. This is distinct from builtin 0x516420.
        public static int DontPush(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first)
        {return Toggle(world,reference,tokens,first,false);}
        // 0x449440. Disabling invulnerability preserves the take-hit-animation bit.
        public static int SetInvulnerable(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first)
        {return Toggle(world,reference,tokens,first,true);}
        // 0x44ef00. This handler has no type-group argument support.
        public static int KeepWeaponOut(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first)
        {
            if(!first)return 1;
            ActorStateRecord target=reference==null?null:reference.WorldObject;bool enabled=true;
            foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int at;
                if(ActorStateWorld.Equal(token,"FALSE"))enabled=false;
                else if(Match(token,"character=",out at))target=world.ResolveObject(Tail(token,at,10));
            }
            if(target!=null)target.WeaponFlagsEec=(target.WeaponFlagsEec&~0x10u)|(enabled?0x10u:0u);
            return 1;
        }
        static void ApplySide(ActorStateWorld world,ActorStateRecord actor,int side)
        {
            uint old=actor.Flags1f8;actor.Flags1f8&=0xfffefffa;
            if(side==0)actor.Flags1f8|=4;
            else if(side==1)actor.Flags1f8|=1;
            else if(side==2)actor.Flags1f8|=0x10000;
            else if(side==3&&(old&0x400)!=0&&actor.SpawnIndex!=255)
            {
                uint definition=world.DefinitionAt(world.SpawnAt(actor.SpawnIndex).DefinitionIndex).Flags;
                if((definition&0x200)!=0)actor.Flags1f8|=4;
                else if((definition&4)!=0)actor.Flags1f8|=1;
            }
            actor.Membership4bc&=~(world.GoodMask|world.BadMask);
            if((actor.Flags1f8&1)!=0)actor.Membership4bc|=world.BadMask;
            else if((actor.Flags1f8&4)==0)actor.Membership4bc|=world.GoodMask;
            // Intersection, not an equality/change test: goodie -> goodie clears.
            if((old&0x10005&actor.Flags1f8)==0)
            {actor.Flags4b0&=~0x800u;actor.OpponentEc0=actor.OpponentEc4=actor.Opponent3ac=0;}
        }
        // 0x444940. Numeric range uses the established packet-number parser.
        public static int SetSide(ActorStateWorld world,ScriptPacket packet,ActorStateRecord reference,string[] tokens,bool first)
        {
            if(!first)return 1;
            ActorStateRecord target=reference==null||(reference.Flags1fc&1)==0?null:reference.WorldObject;
            List<int> types=new List<int>();int side=0;float radiusSquared=0;
            foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int at;
                if(ActorStateWorld.Equal(token,"neutral"))side=0;
                else if(ActorStateWorld.Equal(token,"goodie")||ActorStateWorld.Equal(token,"goody"))side=-1;
                else if(ActorStateWorld.Equal(token,"baddie")||ActorStateWorld.Equal(token,"baddy"))side=1;
                else if(ActorStateWorld.Equal(token,"goodiebaddie")||ActorStateWorld.Equal(token,"goodybaddy"))side=2;
                else if(ActorStateWorld.Equal(token,"default"))side=3;
                else if(Match(token,"type",out at))AddType(world,types,Tail(token,at,5));
                else if(Match(token,"character=",out at))target=world.ResolveObject(Tail(token,at,10));
                else if(Match(token,"range=",out at))
                {
                    float r=MessageNumbers.Resolve(packet,Tail(token,at,6));
                    if(Single.IsNaN(r)||Single.IsInfinity(r))throw new ArgumentOutOfRangeException("range");
                    radiusSquared=MessageNumbers.Round(r*r);
                    if(Single.IsInfinity(radiusSquared))throw new ArgumentOutOfRangeException("range");
                }
            }
            if(types.Count==0&&radiusSquared<=0){if(target!=null)ApplySide(world,target,side);return 1;}
            world.CheckCount();
            for(int i=0;i<world.ActiveCount;i++)
            {
                ActorStateRecord actor=world.Actors[i];
                if(!Eligible(actor)||(types.Count!=0&&!types.Contains(actor.Type)))continue;
                if(radiusSquared>0)
                {
                    float distance=0;
                    if(target!=null)
                    {
                        float x=MessageNumbers.Round(target.X-actor.X),y=MessageNumbers.Round(target.Y-actor.Y),z=MessageNumbers.Round(target.Z-actor.Z);
                        distance=MessageNumbers.Round((float)((double)z*z+(double)x*x+(double)y*y));
                    }
                    // A missing center leaves distance zero, as the PC handler does.
                    if(radiusSquared<=distance)continue;
                }
                ApplySide(world,actor,side);
            }
            return 1;
        }
    }
}
