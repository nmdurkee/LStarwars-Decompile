// 0x447f00: PC AI engage-opponent command, attached to existing name, numeric,
// RNG, ordinary movement-intent and opponent-targeting reconstructions.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public sealed class EngageActorFields
    {
        public bool ControllerPresent=true;
        public byte Blocked28b,Visible288=1,MatrixIndex28d,Mode7b5,AttackOverride1085;
        public float BlockedTimer1010,OwnerTimer1000,FollowRadius3e8;
        public uint TuningFlags90,Input8;
        public ActorStateRecord AttackTargetEa0;
        public SpawnVector PathPoint438;
        public uint[] Orientation420=new uint[6];
    }
    public sealed class EngagePacket
    {
        public ScriptPacket Numbers;
        public byte Flags;
        public ushort AttackOverride;
        public ActorStateRecord CachedOpponent;
        public float FireRange,FireInterval,Timer;
    }
    public sealed class EngageCreature
    {
        public ActorStateRecord Reference,OpponentReference;
        // Host attachment connects these to the same native controller fields.
        public LocatorCreature Movement=new LocatorCreature();
    }
    public sealed class EngageWorld
    {
        public OpponentWorld Targeting;
        public MovementWorld Movement;
        public readonly Dictionary<ActorStateRecord,EngageActorFields> Fields=new Dictionary<ActorStateRecord,EngageActorFields>();
        public ScriptRandom Random=new ScriptRandom();
        // Producer and semantics of this table remain unresolved. Row byte+28d,
        // target byte+28d; header8 followed by 8-byte masks in the original.
        public ulong[] PermissionRows=new ulong[256];
        public bool NearMode876584,Minicut855de0,AlternativeDistance7f39e4;
        public uint Touched876cd0,FireButton80227c;
        public float DefaultGoal=1.5f,DefaultInterval=1.5f,RangeMargin=.5f;
        public Action<ActorStateRecord,float,uint,float> ObserveIntent;
        public EngageActorFields State(ActorStateRecord actor){return Fields[actor];}
    }
    public static class EngageOpponentCommand
    {
        static float F(double d){return MessageNumbers.Round((float)d);}
        static bool Match(string token,string key,out int at){at=token.IndexOf(key,StringComparison.OrdinalIgnoreCase);return at>=0;}
        static string Tail(string token,int at,int skip){if(at+skip>token.Length)throw new ArgumentException("Native token skip exceeds terminator.");return token.Substring(at+skip);}
        static bool Permitted(EngageWorld w,byte row,byte target){return target<64&&(w.PermissionRows[row]&(1UL<<target))!=0;}
        static void Intent(EngageWorld w,EngageCreature creature,ActorStateRecord target,float radius,uint mode,float goal)
        {if(w.ObserveIntent!=null)w.ObserveIntent(target,radius,mode,goal);EngageActorFields fields=w.State(target);MovementCommands.SetIntent(w.Movement,creature.Movement,fields.PathPoint438,radius,fields.Orientation420,mode,goal);}
        static void Face(EngageCreature creature,ActorStateRecord target){creature.Movement.LookTarget=target;}

        // Complete bounded handler. Formation expansion remains the pre-existing
        // MovementServices boundary; world attachment and later input consumption
        // are not implemented by this handler.
        public static bool Execute(EngageWorld w,EngagePacket packet,EngageCreature creature,string[] tokens,bool firstCall,float delta)
        {
            if(creature==null||creature.Reference==null||creature.Reference.WorldObject==null)return true;
            ActorStateRecord own=creature.Reference.WorldObject;EngageActorFields a=w.State(own);LocatorCreature movement=creature.Movement;
            w.Touched876cd0=1;
            if(firstCall)
            {
                packet.FireInterval=w.DefaultInterval;movement.GoalRange=w.DefaultGoal;float initial=w.Random.Next();bool explicitRange=false;
                if(tokens!=null)foreach(string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);int at;
                    if(Match(token,"firerange",out at)){packet.FireRange=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,10));explicitRange=true;}
                    else if(Match(token,"goalrange",out at))movement.GoalRange=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,10));
                    else if(Match(token,"minrange=",out at)){movement.GoalRange=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,9));packet.Flags|=2;}
                    else if(Match(token,"static",out at))movement.GoalRange=0;
                    else if(Match(token,"offscreen",out at))packet.Flags|=1;
                    else if(Match(token,"no_fire_in_minicut",out at))packet.Flags|=4;
                    else if(Match(token,"circle",out at)){movement.Flags^=0x200;packet.Flags|=8;}
                    else if(Match(token,"fireinterval",out at))packet.FireInterval=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,13));
                    else if(Match(token,"opponent=",out at))packet.CachedOpponent=w.Targeting.Actors.ResolveObject(Tail(token,at,9));
                    else if(Match(token,"instant",out at))initial=0;
                    else if(Match(token,"attack_override",out at))
                    {
                        string value=Tail(token,at,16);string[] names={"PUNCH_1","PUNCH_2","PUNCH_3","PUNCH_BEHIND","PUNCH_SPECIAL","BLOCK","SHOOT"};packet.AttackOverride=0;
                        for(int i=0;i<names.Length;i++)if(String.Equals(value,names[i],StringComparison.OrdinalIgnoreCase)){packet.AttackOverride=(ushort)(i+1);break;}
                    }
                }
                if(w.NearMode876584)packet.Flags|=0x20;
                packet.Timer=F((double)packet.FireInterval*initial);
                if(!explicitRange)packet.FireRange=movement.GoalRange==0?9999.9f:F((double)movement.GoalRange+w.RangeMargin);
            }
            ActorStateRecord target=packet.CachedOpponent;
            if(target!=null&&((target.Flags1fc&0x1001)!=0x1001||(w.State(target).Blocked28b!=0&&w.State(target).BlockedTimer1010<=0)))target=null;
            if(packet.AttackOverride!=0)a.AttackOverride1085=(byte)packet.AttackOverride;
            if(target==null)
            {
                ActorStateRecord reference=creature.OpponentReference;
                if(reference==null||!w.State(reference).ControllerPresent||reference.WorldObject==null)return false;
                target=reference.WorldObject;
            }
            own.WeaponFlagsEec|=0x20;EngageActorFields b=w.State(target);
            if((target.Flags1fc&0x1001)!=0x1001||b.Blocked28b!=0||b.Mode7b5==0x2b||((target.Flags1fc&0x80)!=0&&b.OwnerTimer1000>1.5f))return false;
            float distance=LocatorCommands.DistanceSquared(new SpawnVector(target.X,target.Y,target.Z),new SpawnVector(creature.Reference.X,creature.Reference.Y,creature.Reference.Z),false);
            float goal=movement.GoalRange;OpponentFields assigned=w.Targeting.State(own);
            if((assigned.FlagsEf4&0x2000)!=0)
            {
                if(OpponentTargeting.AssignedTargetAllowed(w.Targeting,own,assigned.Reference3ac.WorldObject)){packet.Flags&=0xfd;goal=.1f;}
                else{goal=OpponentTargeting.PreferredRange(w.Targeting,own);packet.Flags|=2;}
            }
            else if(!(goal==0||(((target.Flags1fc&0x80)==0||a.Visible288!=0)&&Permitted(w,w.State(creature.Reference).MatrixIndex28d,b.MatrixIndex28d))))goal=.1f;
            bool special=(a.TuningFlags90&0x100)!=0,efbit=(own.ProtectionFlagsEf0&0x10000)!=0;
            if(goal==0){if(!special)Face(creature,target);}
            else
            {
                float radius=b.FollowRadius3e8<=goal?b.FollowRadius3e8:goal;
                double inner=((double)goal-w.RangeMargin)*((double)goal-w.RangeMargin),outer=((double)goal+w.RangeMargin)*((double)goal+w.RangeMargin);
                if(!efbit)packet.Flags&=0xef;
                if(efbit&&special)
                {
                    if((packet.Flags&0x10)==0){if(distance<inner)packet.Flags|=0x10;}
                    else if(outer<distance)packet.Flags&=0xef;
                    if((packet.Flags&0x10)!=0){Intent(w,creature,target,radius,2,goal);movement.MovementMode=1;own.ProtectionFlagsEf0|=0x8000;}
                    else{Intent(w,creature,target,0,1,.01f);movement.MovementMode=0;}
                }
                else if((special||(packet.Flags&0x20)!=0)&&distance<inner)
                {
                    Intent(w,creature,target,radius,2,goal);movement.MovementMode=1;if(special)own.ProtectionFlagsEf0|=0x8000;
                }
                else
                {
                    uint mode=0;float intentGoal=goal;
                    if(!w.AlternativeDistance7f39e4&&outer>distance/10.0+distance&&(packet.Flags&2)!=0){mode=2;intentGoal=F((double)movement.GoalRange+w.RangeMargin);}
                    else if(distance>outer&&(!w.AlternativeDistance7f39e4||(packet.Flags&2)==0))mode=1;
                    else if((packet.Flags&8)!=0)mode=3;
                    else if(!special)Face(creature,target);
                    if(mode!=0){Intent(w,creature,target,radius,mode,intentGoal);movement.MovementMode=0;}
                }
            }
            if(Permitted(w,a.MatrixIndex28d,b.MatrixIndex28d)&&(!special||!efbit)&&(a.Visible288!=0||(packet.Flags&1)!=0)&&distance<(double)packet.FireRange*packet.FireRange)
            {
                if(!special)Face(creature,target);
                packet.Timer=w.Minicut855de0&&(packet.Flags&4)!=0?PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(w.Random.Next()),PlaybackWide.From(packet.FireInterval)),PlaybackWide.From(2)).Store():F((double)packet.Timer-delta);
                a.AttackTargetEa0=target;
                if(packet.Timer<=0)
                {
                    float draw=w.Random.Next();packet.Timer=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(packet.FireInterval),PlaybackWide.From(.5f)),PlaybackWide.Multiply(PlaybackWide.From(draw),PlaybackWide.From(packet.FireInterval))).Store();
                    if(!OpponentTargeting.PlayerObstructs(w.Targeting,own,target)&&OpponentTargeting.AssignedTargetAllowed(w.Targeting,own,target))a.Input8|=w.FireButton80227c;
                }
            }
            return false;
        }
    }
}
