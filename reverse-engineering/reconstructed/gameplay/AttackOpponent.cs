using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public sealed class AttackPacket
    {
        public ScriptPacket Numbers;
        public byte Flags,JediGoodie69;
        public ushort AttackOverride;
        public float Range70;
    }
    public sealed class AttackWorld
    {
        public EngageWorld Shared;
        public readonly Dictionary<ActorStateRecord,ushort> Input5a=new Dictionary<ActorStateRecord,ushort>();
    }
    public static class AttackOpponentCommand
    {
        static bool Match(string token,string key,out int at){at=token.IndexOf(key,StringComparison.OrdinalIgnoreCase);return at>=0;}
        static string Tail(string token,int at,int skip){if(at+skip>token.Length)throw new ArgumentException("Native token skip exceeds terminator.");return token.Substring(at+skip);}
        static float Sum(float a,float b,float c){return PlaybackWide.Add(PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)),PlaybackWide.From(c)).Store();}
        static void Intent(EngageWorld w,EngageCreature creature,ActorStateRecord target,float radius,uint mode,float goal)
        {
            if(w.ObserveIntent!=null)w.ObserveIntent(target,radius,mode,goal);EngageActorFields e=w.State(target);
            MovementCommands.SetIntent(w.Movement,creature.Movement,e.PathPoint438,radius,e.Orientation420,mode,goal);creature.Movement.MovementMode=0;
        }
        //0x447ac0. Queues input bits; actual attack/damage consumption is external.
        public static bool Execute(AttackWorld world,AttackPacket packet,EngageCreature creature,string[] tokens,bool firstCall)
        {
            if(creature==null||creature.Reference==null||creature.Reference.WorldObject==null)return true;
            EngageWorld w=world.Shared;ActorStateRecord own=creature.Reference.WorldObject;EngageActorFields a=w.State(own);LocatorCreature movement=creature.Movement;w.Touched876cd0=1;
            if(firstCall)
            {
                if(tokens!=null)foreach(string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);int at;
                    if(Match(token,"goalrange",out at))movement.GoalRange=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,10));
                    else if(Match(token,"range",out at))movement.GoalRange=MessageNumbers.Resolve(packet.Numbers,Tail(token,at,6));
                    else if(String.Equals(token,"jediGoodie_attack",StringComparison.OrdinalIgnoreCase))packet.JediGoodie69=1;
                    else if(Match(token,"attack_override",out at))
                    {
                        string value=Tail(token,at,16);string[] names={"PUNCH_1","PUNCH_2","PUNCH_3","PUNCH_BEHIND","PUNCH_SPECIAL","BLOCK","SHOOT"};packet.AttackOverride=0;
                        for(int i=0;i<names.Length;i++)if(String.Equals(value,names[i],StringComparison.OrdinalIgnoreCase)){packet.AttackOverride=(ushort)(i+1);break;}
                    }
                }
                packet.Range70=.2f;
            }
            if(packet.AttackOverride!=0)a.AttackOverride1085=(byte)packet.AttackOverride;
            ActorStateRecord reference=creature.OpponentReference;
            if(reference==null||!w.State(reference).ControllerPresent)return false;
            ActorStateRecord target=reference.WorldObject;
            // Original dereferences without checking. Invalid attachment is rejected.
            if(target==null)throw new InvalidOperationException("AttackOpponent requires a live opponent world pointer.");
            own.WeaponFlagsEec|=0x20;EngageActorFields b=w.State(target);
            if((target.Flags1fc&0x1001)!=0x1001||b.Blocked28b!=0||b.Mode7b5==0x2b||((target.Flags1fc&0x80)!=0&&b.OwnerTimer1000>1.5f))return false;
            float distance=LocatorCommands.DistanceSquared(new SpawnVector(target.X,target.Y,target.Z),new SpawnVector(creature.Reference.X,creature.Reference.Y,creature.Reference.Z),false);
            OpponentFields assignment=w.Targeting.State(own);
            if((assignment.FlagsEf4&0x2000)!=0)
            {
                if(OpponentTargeting.AssignedTargetAllowed(w.Targeting,own,assignment.Reference3ac.WorldObject)){movement.GoalRange=0;packet.Flags&=0xfd;}
                else{movement.GoalRange=OpponentTargeting.PreferredRange(w.Targeting,own);packet.Flags|=2;}
            }
            float goal=movement.GoalRange;
            if((packet.Flags&2)==0)Intent(w,creature,target,0,1,Sum(b.FollowRadius3e8,goal,movement.FollowRadius));
            else
            {
                double inner=((double)goal-w.RangeMargin)*((double)goal-w.RangeMargin),outer=((double)goal+w.RangeMargin)*((double)goal+w.RangeMargin);
                if(distance<inner)Intent(w,creature,target,movement.FollowRadius,2,goal);
                else if(distance<=outer)movement.LookTarget=target;
                else Intent(w,creature,target,movement.FollowRadius,1,goal);
            }
            if(packet.Range70<=0)world.Input5a[own]=(ushort)(world.Input5a[own]|2);
            else
            {
                if(b.Mode7b5==0x5a)return false;
                distance=LocatorCommands.DistanceSquared(new SpawnVector(target.X,target.Y,target.Z),new SpawnVector(creature.Reference.X,creature.Reference.Y,creature.Reference.Z),false);
                float range=Sum(b.FollowRadius3e8,packet.Range70,a.FollowRadius3e8);
                // Original stores the squared attack threshold to float32.
                float threshold=MessageNumbers.Round((float)((double)range*range));if(threshold<=distance)return false;
            }
            a.Input8|=w.FireButton80227c;if(packet.JediGoodie69!=0)own.WeaponFlagsEec|=0x400;return false;
        }
    }
}
