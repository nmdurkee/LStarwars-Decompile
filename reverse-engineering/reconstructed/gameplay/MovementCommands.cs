using System;

namespace Recovered.Gameplay
{
    public sealed class MovementNode { public byte Index; }
    public sealed class MovementPath { public byte[][] NextHopOrdinals; }
    public sealed class MovementFormation { public bool Enabled; public LocatorActor Leader; }
    public abstract class MovementServices
    {
        // Native callback0x9238b0. A consumed token skips command-specific parsing.
        public abstract bool MovementToken(LocatorCreature creature,string token);
        // Full0x514920 expression evaluation is an explicit boundary here.
        public abstract float Evaluate(LocatorCreature creature,LocatorPacket packet,string text);
        public abstract float NextFloat();
        public abstract SpawnVector Rotate(SpawnVector vector,int heading);
        // Native0x9238b8 can complete must_reach_destination outside normal range.
        public abstract bool SpecialCompletion(LocatorActor reference,LocatorRecord locator);
        public abstract void FormationOwnerCommand(LocatorCreature creature,int mode);
        public abstract void FormationIntent(LocatorCreature creature);
    }
    public class MovementWorld:LocatorWorld
    {
        public bool HasFollowSystem=true, HasCompletionCallback;
        public MovementServices Movement;
        public readonly LocatorActor[] FollowPlayers=new LocatorActor[2];
        public Func<sbyte,float> PartyOffset;
        public float PartyOverride;
        public uint SpecialButtonMask;
    }
    public static class MovementCommands
    {
        static bool Match(string t,string key,out int at){at=t.IndexOf(key,StringComparison.OrdinalIgnoreCase);return at>=0;}
        static bool Equal(string a,string b){return String.Equals(a,b,StringComparison.OrdinalIgnoreCase);}
        static string Tail(string t,int at,int skip){if(at+skip>t.Length)throw new ArgumentException("Native token skip exceeds terminator.");return t.Substring(at+skip);}
        static float Round(double d){return MessageNumbers.Round((float)d);}
        static int Integer(float v){if(Single.IsNaN(v)||Single.IsInfinity(v)||(double)v< -2147483648.0||(double)v>=2147483648.0)throw new ArgumentOutOfRangeException("tokens");return (int)v;}

        //0x52fcb0: ordinary goal writes are real logic; formation expansion is an adapter.
        public static void SetIntent(MovementWorld world,LocatorCreature creature,SpawnVector? point,float radius,uint[] words,uint mode,float goal)
        {
            if(creature.Formation!=null&&creature.Formation.Enabled)
            {
                if(mode==1||mode==4)
                {
                    if(Object.ReferenceEquals(creature.Formation.Leader,creature.Reference))world.Movement.FormationOwnerCommand(creature,(int)mode);
                    world.Movement.FormationIntent(creature);return;
                }
                if(mode==5)mode=1;
            }
            if(point.HasValue)creature.IntentPoint=point.Value;
            if(words!=null){if(words.Length<6)throw new ArgumentException("Six orientation words required.");Array.Copy(words,creature.IntentWords,6);}
            creature.IntentRadius=radius;creature.Flags=(creature.Flags&~7u)|(mode&7u);creature.IntentGoal=goal;
        }

        //0x534e10, follows resolved path/node state instead of invoking a pathfinder.
        public static void FollowIntent(MovementWorld world,LocatorActor follower,LocatorActor target,byte flags,float goal)
        {
            if(follower==null||target==null||follower.Controller==null||target.Controller==null)throw new InvalidOperationException("Follow helper requires valid actor/controller pointers.");
            LocatorCreature a=follower.Controller,b=target.Controller;uint mode=1;SpawnVector point=b.PathPoint;
            if((flags&1)!=0)
            {
                bool direct=a.Path==null||!Object.ReferenceEquals(a.Path,b.Path);
                if(!direct)
                {
                    direct=((b.NodeFlags&1)==0&&Object.ReferenceEquals(a.Node,b.Node))||a.Node==null||b.Node==null||(a.Flags&0x100000)!=0;
                    if(!direct)
                    {
                        if(a.Path.NextHopOrdinals==null||a.Node.Index>=a.Path.NextHopOrdinals.Length||a.Path.NextHopOrdinals[a.Node.Index]==null||b.Node.Index>=a.Path.NextHopOrdinals[a.Node.Index].Length)throw new InvalidOperationException("Incomplete route matrix.");
                        direct=a.Path.NextHopOrdinals[a.Node.Index][b.Node.Index]==255&&a.Node.Index!=b.Node.Index;
                    }
                }
                if(direct){mode=7;point=b.Position;}
            }
            SetIntent(world,a,point,(flags&2)==0?b.FollowRadius:0,b.PathWords,mode,goal);
        }

        public static bool GoToLocator(MovementWorld world,LocatorPacket packet,LocatorCreature creature,string[] tokens,bool firstCall,float delta)
        {
            if(creature==null||creature.Reference==null||creature.Reference.WorldObject==null||creature.Path==null||creature.Node==null)return true;
            MovementServices services=world.Movement;
            if(firstCall)
            {
                packet.Flags=0;packet.Active=packet.Selected;
                bool personal=false,indexed=false;int random=0;float minimum=0,maximum=0;
                if(tokens!=null)for(int i=0;i<tokens.Length;i++)
                {
                    string token=tokens[i];MessageNumbers.RequireAscii(token);if(services.MovementToken(creature,token))continue;int at;
                    if(Match(token,"name",out at)||Match(token,"teleport",out at))
                    {
                        ++i;if(i<tokens.Length)packet.Active=world.Find(LocatorCommands.FormatName(world,creature.Reference,tokens[i],indexed,personal,random));
                        if(token.IndexOf("teleport",StringComparison.OrdinalIgnoreCase)>=0)
                        {if(packet.Active!=null)creature.Reference.Position=packet.Active.Position;return true;}
                    }
                    else if(Match(token,"personal",out at))personal=true;
                    else if(Match(token,"indexed",out at))indexed=true;
                    else if(Match(token,"random",out at))random=Integer(services.Evaluate(creature,packet,Tail(token,at,7)));
                    else if(Match(token,"waittime",out at))packet.Wait=services.Evaluate(creature,packet,Tail(token,at,9));
                    else if(Match(token,"mintime",out at))minimum=services.Evaluate(creature,packet,Tail(token,at,8));
                    else if(Match(token,"maxtime",out at))maximum=services.Evaluate(creature,packet,Tail(token,at,8));
                    else if(Match(token,"goalrange",out at))creature.GoalRange=services.Evaluate(creature,packet,Tail(token,at,10));
                    else if(Equal(token,"on_ground"))packet.Flags|=1;
                    else if(Equal(token,"xz_rangecheck"))packet.Flags|=2;
                    else if(Equal(token,"face_opponent"))packet.Flags|=4;
                    else if(Equal(token,"ignore_path"))packet.Flags|=8;
                    else if(Equal(token,"must_reach_destination"))packet.Flags|=16;
                    else creature.GoalRange=services.Evaluate(creature,packet,token);
                }
                if(packet.Wait==0)packet.Wait=maximum<=minimum?.01f:Round((double)services.NextFloat()*((double)maximum-minimum)+minimum);
                if(packet.Active==null)return true;
                SetIntent(world,creature,packet.Active.Position,0,packet.Active.Orientation,(packet.Flags&8)==0?1u:7u,creature.GoalRange);
                packet.FacingPoint=SpawnVector.Add(services.Rotate(new SpawnVector(0,0,1),packet.Active.Heading),packet.Active.Position);
                return false;
            }
            if(packet.Active==null)return true;
            SetIntent(world,creature,packet.Active.Position,0,packet.Active.Orientation,(packet.Flags&8)==0?1u:7u,creature.GoalRange);
            if((packet.Flags&4)!=0&&creature.Opponent!=null)creature.LookTarget=creature.Opponent;
            if((packet.Flags&1)!=0&&creature.Reference.GroundState==0)return false;
            float distance=LocatorCommands.DistanceSquared(creature.Position,packet.Active.Position,(packet.Flags&2)!=0);
            float threshold=Round((double)delta*creature.Reference.TravelSpeed+Round((double)creature.GoalRange+.10000000149011612));
            if((double)distance>=(double)threshold*threshold)
                return (creature.Flags&0x400000)!=0&&(packet.Flags&16)!=0&&world.HasCompletionCallback&&services.SpecialCompletion(creature.Reference,packet.Active);
            if((packet.Flags&4)==0||creature.Opponent==null)creature.LookTarget=packet;
            if(packet.Wait>0){packet.Wait=Round((double)packet.Wait-delta);if(packet.Wait<0)packet.Wait=0;return false;}
            return true;
        }

        public static bool FollowPlayer(MovementWorld world,LocatorPacket packet,LocatorCreature creature,string[] tokens,bool firstCall)
        {
            if(creature==null||creature.Reference==null||creature.Reference.WorldObject==null||!world.HasFollowSystem)return true;
            LocatorActor reference=creature.Reference,own=reference.WorldObject;
            if(firstCall&&tokens!=null)foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);if(world.Movement.MovementToken(creature,token))continue;
                if(Equal(token,"ignore_radius"))packet.Flags|=2;
                else if(Equal(token,"can_go_off_path"))packet.Flags|=1;
                else if(Equal(token,"hold_special_button"))packet.HoldSpecial=1;
                else if(Equal(token,"nearest"))
                {
                    LocatorActor a=world.FollowPlayers[0],b=world.FollowPlayers[1];
                    if(a==null||b==null)packet.FollowTarget=a;
                    else
                    {
                        // Original sqrt distances are float32 before the comparison.
                        float da=Round(Math.Sqrt(LocatorCommands.DistanceSquared(reference.Position,a.Position,false))),db=Round(Math.Sqrt(LocatorCommands.DistanceSquared(reference.Position,b.Position,false)));
                        packet.FollowTarget=db<da?b:a;
                    }
                }
                else if(creature.GoalRange==0)creature.GoalRange=MessageNumbers.Resolve(packet.Numbers,token);
            }
            if(packet.FollowTarget==null&&world.FollowPlayers[0]==null)return false;
            float range=creature.GoalRange;
            if(reference.PersonalIndex!=-1)
            {
                if(world.PartyOverride>0)range=.01f;
                else {if(world.PartyOffset==null)throw new InvalidOperationException("Missing indexed party offset.");range=Round((double)world.PartyOffset(reference.PersonalIndex)+range);}
            }
            // PC stores nearest in packet+6c, but this call still passes player0.
            FollowIntent(world,reference,world.FollowPlayers[0],packet.Flags,range);
            if(packet.HoldSpecial!=0){own.Input4|=world.SpecialButtonMask;own.Input8|=world.SpecialButtonMask;}
            return false;
        }
    }
}
