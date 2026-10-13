// Original-PC locator selection and snap command projections. Runtime actors,
// source attachment and terrain resampling have explicit host boundaries.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class LocatorRecord
    {
        public string Name;
        public SpawnVector Position;
        public int Heading;
        public uint[] Orientation=new uint[6];
    }
    public sealed class LocatorPacket
    {
        public ScriptPacket Numbers;
        public LocatorRecord Selected, Active;
        public byte Flags, HoldSpecial;
        public float Wait;
        public SpawnVector FacingPoint;
        public LocatorActor FollowTarget;
    }
    public sealed class LocatorActor
    {
        public int Id;
        public LocatorActor WorldObject;
        public LocatorPacket Packet;
        public sbyte PersonalIndex=-1;
        public string CharacterName;
        public LocatorRecord SpawnLocator;
        public SpawnVector Position, Velocity, Origin80, Cache8c, Cache98, Cache1b4, Cache1cc, Cache10bc;
        public ushort Angle58, Angle5a, Angle27a;
        public uint[] Orientation420=new uint[6];
        public LocatorCreature Controller;
        public byte GroundState;
        public float TravelSpeed;
        public uint Input4, Input8;
    }
    public sealed class LocatorCreature
    {
        public LocatorActor Reference;
        public SpawnVector Position;
        public MovementPath Path;
        public MovementNode Node;
        public byte NodeFlags, MovementMode;
        public float GoalRange, FollowRadius, IntentRadius, IntentGoal;
        public uint Flags;
        public SpawnVector PathPoint, IntentPoint;
        public uint[] PathWords=new uint[6], IntentWords=new uint[6];
        public MovementFormation Formation;
        public LocatorActor Opponent;
        // Reference identity is separate from the pointed-to position value.
        public object LookTarget;
    }
    public class LocatorWorld
    {
        public readonly List<LocatorRecord> Locators=new List<LocatorRecord>();
        public Func<string,LocatorActor> ResolveReference, ResolveObject;
        public Func<int> NextInteger;
        public readonly LocatorActor[] Players=new LocatorActor[2];
        public SpawnVector VelocityReset, LastSnapOrigin;
        public Action<LocatorActor> RefreshTerrain, CheckTerrain;
        public int NearestSearchBudget=4096;
        // 0x51ac10, first case-insensitive match in contiguous native record order.
        public virtual LocatorRecord Find(string name)
        {
            MessageNumbers.RequireAscii(name);
            foreach(LocatorRecord locator in Locators)
                if(String.Equals(locator.Name,name,StringComparison.OrdinalIgnoreCase))return locator;
            return null;
        }
    }
    public static class LocatorCommands
    {
        static bool Match(string t,string k,out int a){a=t.IndexOf(k,StringComparison.OrdinalIgnoreCase);return a>=0;}
        static bool Eq(string a,string b){return String.Equals(a,b,StringComparison.OrdinalIgnoreCase);}
        static string Tail(string t,int a,int n){if(a+n>t.Length)throw new ArgumentException("Native token skip passes the terminator.");return t.Substring(a+n);}
        static int Integer(float f){if(Single.IsNaN(f)||Single.IsInfinity(f)||(double)f< -2147483648.0||(double)f>=2147483648.0)throw new ArgumentOutOfRangeException("tokens");return (int)f;}
        internal static string FormatName(LocatorWorld world,LocatorActor actor,string value,bool indexed,bool personal,int random)
        {
            string result;
            if(indexed&&actor.PersonalIndex!=-1)result=value+"_"+actor.PersonalIndex.ToString(System.Globalization.CultureInfo.InvariantCulture);
            else if(personal&&actor.CharacterName!=null)result=value+"_"+actor.CharacterName;
            else if(random!=0)
            {
                if(world.NextInteger==null)throw new InvalidOperationException("Missing shared integer RNG.");
                result=value+"_"+(world.NextInteger()%random).ToString(System.Globalization.CultureInfo.InvariantCulture);
            }
            else
            {
                // Native calls sprintf(buffer,name) here, with no format args.
                // Format directives and native stack overflow are not reproduced.
                if(value.IndexOf('%')>=0)throw new ArgumentException("Unbound native format string.");result=value;
            }
            if(result.Length>63)throw new ArgumentOutOfRangeException("name");return result;
        }
        public static float GotLocator(LocatorPacket packet){return packet.Selected==null?0:1;}

        // Native distance helper uses three float32 difference stores and an
        // extended sum. The return here models its later float32 storage.
        public static float DistanceSquared(SpawnVector a,SpawnVector b,bool xzOnly)
        {
            float x=MessageNumbers.Round(a.X-b.X),y=xzOnly?0:MessageNumbers.Round(a.Y-b.Y),z=MessageNumbers.Round(a.Z-b.Z);
            return Recovered.Animation.FiniteX87.Dot3PlusConstant(x,y,z,x,y,z,0);
        }
        public static bool SetLocator(LocatorWorld world,LocatorPacket caller,LocatorCreature creature,string[] tokens,bool firstCall)
        {
            if(!firstCall||tokens==null||tokens.Length==0)return true;
            LocatorActor target=creature==null?null:creature.Reference;
            string name=null;bool personal=false,indexed=false,nearest=false;int random=0;
            foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int a;
                if(Match(token,"name=",out a))name=Tail(token,a,5);
                else if(Eq(token,"personal"))personal=true;
                else if(Eq(token,"indexed"))indexed=true;
                else if(Eq(token,"nearest"))nearest=true;
                else if(Match(token,"random=",out a))random=Integer(MessageNumbers.Resolve(caller.Numbers,Tail(token,a,7)));
                else if(Match(token,"character=",out a)&&world.ResolveReference!=null)target=world.ResolveReference(Tail(token,a,10));
            }
            LocatorRecord selected=null;
            if(name!=null)
            {
                if(nearest)
                {
                    if(creature==null)throw new InvalidOperationException("Nearest lookup needs a valid script creature.");
                    float best=1e9f;
                    for(int i=0;;i++)
                    {
                        if(i>=world.NearestSearchBudget)throw new InvalidOperationException("Nearest lookup budget exceeded.");
                        string query=name+"_"+i.ToString(System.Globalization.CultureInfo.InvariantCulture);
                        if(query.Length>63)throw new ArgumentOutOfRangeException("name");
                        LocatorRecord locator=world.Find(query);if(locator==null)break;
                        float d=DistanceSquared(creature.Position,locator.Position,false);
                        if(d<best){best=d;selected=locator;}
                    }
                }
                else if(creature!=null)
                {
                    if(creature.Reference==null)throw new InvalidOperationException("Named lookup needs the original creature reference.");
                    selected=world.Find(FormatName(world,creature.Reference,name,indexed,personal,random));
                }
            }
            if(target!=null)
            {
                if(target.Packet==null)throw new InvalidOperationException("Selected reference has no packet.");
                target.Packet.Selected=selected;
            }
            return true;
        }
        public static bool SnapToLocator(LocatorWorld world,LocatorPacket caller,LocatorCreature creature,string[] tokens,bool firstCall)
        {
            if(!firstCall)return true;
            LocatorActor own=creature==null||creature.Reference==null?null:creature.Reference.WorldObject,target=own;
            string name=null;bool personal=false,indexed=false,terrain=true;int random=0;
            if(tokens!=null)foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int a;
                if(Match(token,"name",out a))name=Tail(token,a,5);
                else if(Match(token,"personal",out a))personal=true;
                else if(Match(token,"indexed",out a))indexed=true;
                else if(Match(token,"random",out a))random=Integer(MessageNumbers.Resolve(caller.Numbers,Tail(token,a,9))); // PC fixed skip really is9
                else if(Match(token,"character",out a))target=world.ResolveObject==null?null:world.ResolveObject(Tail(token,a,10));
                else if(Match(token,"player=",out a)){int player=Integer(MessageNumbers.Resolve(caller.Numbers,Tail(token,a,7)));if(player==1||player==2)target=world.Players[player-1];}
                else if(Match(token,"dont_check_terrain",out a))terrain=false;
            }
            if(target==null)target=own; // named/player null lookup falls back to self
            if(target==null)return true;
            LocatorRecord locator=target.SpawnLocator;
            if(name!=null)locator=world.Find(FormatName(world,target,name,indexed,personal,random));
            if(locator==null)return true;
            target.Position=locator.Position;
            target.Angle58=target.Angle5a=target.Angle27a=unchecked((ushort)locator.Heading);
            Array.Copy(locator.Orientation,target.Orientation420,6);
            target.Origin80=target.Cache8c=target.Cache98=target.Cache1b4=target.Cache1cc=target.Cache10bc=target.Position;
            world.LastSnapOrigin=target.Origin80;target.Velocity=world.VelocityReset;
            if(world.RefreshTerrain!=null)world.RefreshTerrain(target);
            if(terrain&&world.CheckTerrain!=null)world.CheckTerrain(target);
            return true;
        }
    }
}
