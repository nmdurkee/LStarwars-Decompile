// Handwritten bounded projection of PC 0x456c10. World allocation and physical
// effects are explicit services. See gameplay-createcreatures-contract.json.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public struct SpawnVector
    {
        public float X, Y, Z;
        public SpawnVector(float x, float y, float z) { X=x; Y=y; Z=z; }
        public bool Nonzero { get { return X!=0 || Y!=0 || Z!=0; } }
        public static SpawnVector Add(SpawnVector a, SpawnVector b)
        { return new SpawnVector(MessageNumbers.Round(a.X+b.X), MessageNumbers.Round(a.Y+b.Y), MessageNumbers.Round(a.Z+b.Z)); }
    }
    public sealed class SpawnLocator
    {
        public int Id, Heading;
        public SpawnVector Position;
        public object Orientation;
    }
    public sealed class SpawnLocatorSet
    {
        public readonly List<SpawnLocator> Members=new List<SpawnLocator>();
        public readonly List<byte> Occupants=new List<byte>();
    }
    public sealed class SpawnZip
    {
        public int Id;
        public SpawnVector Position;
    }
    public sealed class SpawnActor
    {
        public int Id;
        public byte Slot;
        public uint Flags, GunFlags, Capabilities;
        public SpawnLocator Locator;
        public SpawnLocatorSet LocatorSet;
        public SpawnVector Position, RiderPosition, BodyOrigin, ZipDownOrigin;
        public int Heading;
        public object Orientation, RiderOrientation;
        public byte MovementState;
        public ushort MovementKind;
    }
    public sealed class SpawnRequest
    {
        public short Type;
        public SpawnVector Position;
        public int Heading, Set;
        public string Script;
        public object Orientation, Formation;
        public bool SetOnSurface;
    }
    public sealed class SpawnSelection
    {
        public IList<SpawnLocator> Candidates;
        public bool NearestPlayer, OnScreen, HasPlayerReference;
        public float Radius, MaximumRange, MinimumY, MaximumY;
    }
    public sealed class SpawnContext
    {
        public ScriptPacket Packet;
        public SpawnActor Self;
        // PC ridden_by=myself dereferences the first word of creature+d0.
        // It is deliberately distinct from the creature+d0 source for origin.
        public SpawnActor SelfRider;
        public SpawnLocator MyLocator;
        public SpawnLocatorSet MyLocatorSet;
        public bool HubMode, TypeCallbacksAvailable=true;
        public SpawnServices Services;
        public int OperationBudget=4096;
    }
    public abstract class SpawnServices
    {
        public abstract byte FindType(string name);
        public abstract short ResolveType(byte index);
        // Hub-name service returns the original special ID only when its load
        // table entry is not -1. Only Barman/Jabba/CantinaBand reach this method.
        public abstract short HubType(string name);
        public abstract short RandomMapType();
        public abstract short GenericGoonType();
        public abstract SpawnLocator FindLocator(string name);
        public abstract SpawnLocatorSet FindLocatorSet(string name);
        public abstract void RefreshLocatorSet(SpawnLocatorSet set);
        public abstract SpawnZip FindZip(string name);
        public abstract SpawnActor FindRider(string name);
        public abstract uint Capability(string name);
        public abstract int NextInteger();
        public abstract float NextFloat();
        public abstract SpawnLocator SelectLocator(SpawnSelection request);
        // May mutate/remove candidates, as the native zip selector does.
        public abstract SpawnZip SelectZip(IList<SpawnZip> candidates);
        public abstract float TypeRadius(short type);
        public abstract float FormationValue(short type);
        public abstract object CreateFormation(int across, float xSpacing, float zSpacing, float typeValue);
        public abstract SpawnVector RotateOffset(SpawnVector offset, int heading);
        public abstract SpawnActor Spawn(SpawnRequest request);
        public abstract void SetState(SpawnActor actor, string state);
        public abstract void Crate(SpawnActor actor, float height, float delay);
        public abstract void ZipDown(SpawnActor actor);
        // Full zip-up setup is intentionally delegated, including native field
        // changes, angle helpers, audio and animation dispatch.
        public abstract void ZipUp(SpawnActor actor, SpawnZip zip);
        public abstract void Ride(SpawnActor rider, SpawnActor mount);
        public abstract void Balloon(SpawnActor actor);
        public abstract void BalloonHeight(SpawnActor actor, float height);
    }
    public sealed class SpawnPlan
    {
        public int Minimum=-1, Maximum=-1, Count=1, Across=2, Set;
        public bool Grouped=true, SetOnSurface=true, InheritLocatorSet=true;
        public bool StartLocatorSet, NearestPlayer, OffScreen, OnScreen;
        public bool ZipDown, Cheap, NoGun, Balloon;
        public float XSpacing=.8f, ZSpacing=.8f, MaximumRange=1e9f, MinimumY=1e9f, MaximumY=1e9f;
        public float CrateHeight, CrateDelay, FallChance;
        public SpawnVector Offset;
        public string Script="default", State;
        public uint AddCapabilities, RemoveCapabilities;
        public SpawnLocatorSet LocatorSet;
        public SpawnActor Rider;
        public readonly List<short> Types=new List<short>();
        public readonly List<SpawnLocator> Locators=new List<SpawnLocator>();
        public readonly List<SpawnZip> Zips=new List<SpawnZip>();
    }
    public static class CreatureSpawner
    {
        static bool Match(string token,string key,out int at)
        { at=token.IndexOf(key,StringComparison.OrdinalIgnoreCase); return at>=0; }
        static bool Equal(string a,string b) { return String.Equals(a,b,StringComparison.OrdinalIgnoreCase); }
        static float Number(SpawnContext c,string t,int at,int skip)
        {
            if(at+skip>t.Length) throw new ArgumentException("Token reads beyond its terminator in the native command.");
            float value=MessageNumbers.Resolve(c.Packet,t.Substring(at+skip));
            if(Single.IsNaN(value)||Single.IsInfinity(value)) throw new ArgumentOutOfRangeException("tokens");
            return value;
        }
        static int Integer(float f)
        {
            if((double)f < -2147483648.0 || (double)f >= 2147483648.0) throw new ArgumentOutOfRangeException("tokens");
            return (int)f;
        }
        static string Tail(string t,int at,int skip)
        { if(at+skip>t.Length)throw new ArgumentException("Short native token."); return t.Substring(at+skip); }
        static void AddType(SpawnPlan p,short id) { if(id!=-1 && p.Types.Count<10)p.Types.Add(id); }

        public static SpawnPlan Parse(SpawnContext c,string[] tokens)
        {
            if(c==null||c.Services==null)throw new ArgumentNullException("context/services");
            SpawnServices s=c.Services; SpawnPlan p=new SpawnPlan();
            if(tokens==null)return p;
            foreach(string t in tokens)
            {
                MessageNumbers.RequireAscii(t); int a; string text;
                if(Match(t,"mingroupsize",out a))p.Minimum=Integer(Number(c,t,a,13));
                else if(Match(t,"maxgroupsize",out a))p.Maximum=Integer(Number(c,t,a,13));
                else if(Match(t,"groupsize",out a))p.Count=Integer(Number(c,t,a,10));
                else if(Match(t,"start_locator_set=",out a))
                {
                    text=Tail(t,a,18);p.LocatorSet=Equal(text,"myset")?c.MyLocatorSet:s.FindLocatorSet(text);
                    if(p.LocatorSet!=null)p.StartLocatorSet=true; // failed later lookup does not clear the latch
                }
                else if(Equal(t,"dont_inherit_locator_set"))p.InheritLocatorSet=false;
                else if(Match(t,"locator_set=",out a))
                {
                    text=Tail(t,a,12);p.LocatorSet=Equal(text,"myset")?c.MyLocatorSet:s.FindLocatorSet(text);
                    if(p.LocatorSet!=null)
                    {
                        s.RefreshLocatorSet(p.LocatorSet);
                        int count=p.LocatorSet.Members.Count;
                        if(count>127||p.LocatorSet.Occupants.Count!=count)throw new InvalidOperationException("Invalid signed-byte locator set.");
                        for(int i=0;i<count && p.Locators.Count<64;i++)
                            if(p.LocatorSet.Occupants[i]==255)p.Locators.Add(p.LocatorSet.Members[i]);
                    }
                }
                else if(Match(t,"locator=",out a))
                {
                    if(p.Locators.Count<64)
                    { text=Tail(t,a,8);SpawnLocator l=Equal(text,"mylocator")?c.MyLocator:s.FindLocator(text);if(l!=null)p.Locators.Add(l); }
                }
                else if(Match(t,"max_range_to_player=",out a))p.MaximumRange=Number(c,t,a,20);
                else if(Match(t,"mindy=",out a))p.MinimumY=Number(c,t,a,6);
                else if(Match(t,"maxdy=",out a))p.MaximumY=Number(c,t,a,6);
                else if(Match(t,"zipup",out a))
                {
                    // The native guard checks LOCATOR count, not zip count.
                    if(p.Locators.Count<32)
                    { SpawnZip zip=s.FindZip(Tail(t,a,6));if(zip!=null){if(p.Zips.Count>=32)throw new InvalidOperationException("Native zip candidate overflow.");p.Zips.Add(zip);} }
                }
                else if(Match(t,"type=randommap",out a)) { if(c.HubMode)AddType(p,s.RandomMapType()); }
                else if(Match(t,"type=generic_goon",out a)) { if(p.Types.Count<10)AddType(p,s.GenericGoonType()); }
                else if(Match(t,"type",out a))
                {
                    if(c.TypeCallbacksAvailable)
                    {
                        text=Tail(t,a,5);
                        if(c.HubMode)
                        { if(Equal(text,"Barman")||Equal(text,"Jabba")||Equal(text,"CantinaBand"))AddType(p,s.HubType(text)); }
                        else { byte index=s.FindType(text);if(index!=255)AddType(p,s.ResolveType(index)); }
                    }
                }
                else if(Match(t,"state=",out a))p.State=Tail(t,a,6);
                else if(Match(t,"script",out a))
                { p.Script=Tail(t,a,7);if(p.Script.Length>63)throw new ArgumentOutOfRangeException("tokens","Native script buffer is 64 bytes."); }
                else if(Match(t,"xspacing",out a))p.XSpacing=Number(c,t,a,9);
                else if(Match(t,"zspacing",out a))p.ZSpacing=Number(c,t,a,9);
                else if(Match(t,"xoffset",out a))p.Offset.X=Number(c,t,a,8);
                else if(Match(t,"yoffset",out a))p.Offset.Y=Number(c,t,a,8);
                else if(Match(t,"zoffset",out a))p.Offset.Z=Number(c,t,a,8);
                else if(Match(t,"nacross",out a))p.Across=Integer(Number(c,t,a,8));
                else if(Match(t,"addtoset=myset",out a))p.Set=c.Packet.SetId;
                else if(Match(t,"addtoset=",out a))p.Set=Integer(Number(c,t,a,9));
                else if(Match(t,"crate_height=",out a))p.CrateHeight=Number(c,t,a,13);
                else if(Match(t,"crate_delay=",out a))p.CrateDelay=Number(c,t,a,12);
                else if(Equal(t,"not_grouped"))p.Grouped=false;
                else if(Equal(t,"dont_set_on_surface"))p.SetOnSurface=false;
                else if(Equal(t,"zipdown")) { p.ZipDown=true;p.SetOnSurface=false; }
                else if(Equal(t,"nearest_player"))p.NearestPlayer=true;
                else if(Equal(t,"off_screen")||Equal(t,"offscreen"))p.OffScreen=true;
                else if(Equal(t,"on_screen"))p.OnScreen=true;
                else if(Match(t,"fall_chance=",out a))p.FallChance=Number(c,t,a,12);
                else if(Equal(t,"CheapAsChips"))p.Cheap=true;
                else if(Match(t,"ridden_by=myself",out a)) { if(c.Self!=null)p.Rider=c.SelfRider; }
                else if(Match(t,"ridden_by=",out a))p.Rider=s.FindRider(Tail(t,a,10));
                else if(Equal(t,"no_gun"))p.NoGun=true;
                else if(Equal(t,"ballooning")) { p.Balloon=true;p.SetOnSurface=false; }
                else if(Match(t,"lose_capability=",out a))p.RemoveCapabilities|=s.Capability(Tail(t,a,16));
                else if(Match(t,"capability=",out a))p.AddCapabilities|=s.Capability(Tail(t,a,11));
            }
            return p;
        }
        public static bool Execute(SpawnContext c,string[] tokens,bool firstCall)
        {
            if(!firstCall)return true;
            SpawnPlan p=Parse(c,tokens);SpawnServices s=c.Services;
            int count=p.Count,budget=c.OperationBudget;
            if(p.Minimum>=0)
            {
                if(p.Minimum<p.Maximum)
                { long span=(long)p.Maximum-p.Minimum+1;if(span>Int32.MaxValue)throw new ArgumentOutOfRangeException("tokens");count=s.NextInteger()%(int)span+p.Minimum; }
                else if(p.Minimum==p.Maximum)count=p.Minimum;
            }
            // Native can fail to make progress forever for negative counts.
            if(count<0)throw new ArgumentOutOfRangeException("tokens","Negative spawn count can loop indefinitely in the PC command.");
            SpawnVector position=c.Self==null?new SpawnVector():c.Self.Position,offset=p.Offset;
            int heading=c.Self==null?0:c.Self.Heading;
            object orientation=c.Self==null?null:c.Self.Orientation;
            bool offsetApplied=false;float delay=0;
            while(count!=0)
            {
                if(--budget<0)throw new InvalidOperationException("Spawn operation budget exceeded.");
                if((p.Locators.Count==0&&p.Zips.Count==0&&p.Rider==null&&!p.StartLocatorSet)||p.Types.Count==0)break;
                int random=s.NextInteger();if(random<0)throw new InvalidOperationException("Negative type RNG index is outside this contract.");
                short type=p.Types[random%p.Types.Count];SpawnLocator locator=null;SpawnZip zip=null;
                if(p.Locators.Count!=0||p.StartLocatorSet)
                {
                    if(p.StartLocatorSet && p.LocatorSet!=null)
                    { if(p.LocatorSet.Members.Count>0)locator=p.LocatorSet.Members[0]; }
                    else locator=s.SelectLocator(new SpawnSelection{Candidates=p.Locators,NearestPlayer=p.NearestPlayer,OnScreen=p.OnScreen,HasPlayerReference=p.NearestPlayer||p.MaximumRange!=1e9f,Radius=p.OffScreen?MessageNumbers.Round(s.TypeRadius(type)+.5f):0,MaximumRange=p.MaximumRange,MinimumY=p.MinimumY,MaximumY=p.MaximumY});
                    if(locator==null)break;
                    position=locator.Position;heading=locator.Heading;orientation=locator.Orientation;offsetApplied=false;
                }
                else if(p.Zips.Count!=0)
                { zip=s.SelectZip(p.Zips);if(zip==null)break;position=zip.Position;orientation=null;p.SetOnSurface=false; }
                else if(p.Rider!=null)
                { position=p.Rider.RiderPosition;heading=p.Rider.Heading;orientation=p.Rider.RiderOrientation; }
                if(!offsetApplied && offset.Nonzero)
                { offset=s.RotateOffset(offset,heading);position=SpawnVector.Add(position,offset);offsetApplied=true; }
                int group=p.Grouped?count:1;count-=group;object formation=null;
                for(int i=0;i<group;i++)
                {
                    if(--budget<0)throw new InvalidOperationException("Spawn operation budget exceeded.");
                    if(i==0&&group>1)formation=s.CreateFormation(p.Across,p.XSpacing,p.ZSpacing,s.FormationValue(type));
                    SpawnActor actor=s.Spawn(new SpawnRequest{Type=type,Position=position,Heading=heading,Script=p.Script,Orientation=orientation,Formation=formation,SetOnSurface=p.SetOnSurface,Set=p.Set});
                    if(actor==null)continue;
                    if(p.State!=null)s.SetState(actor,p.State);
                    actor.Locator=locator;if(p.InheritLocatorSet)actor.LocatorSet=p.LocatorSet;
                    if(p.NoGun)actor.GunFlags&=0xfffffffb;
                    if(p.CrateHeight!=0)s.Crate(actor,p.CrateHeight,delay);
                    delay=MessageNumbers.Round(delay+p.CrateDelay);
                    if(p.LocatorSet!=null&&locator!=null)
                        for(int j=0;j<p.LocatorSet.Members.Count;j++)if(Object.ReferenceEquals(p.LocatorSet.Members[j],locator)){p.LocatorSet.Occupants[j]=actor.Slot;break;}
                    if(zip!=null)s.ZipUp(actor,zip);
                    else if(p.ZipDown && (p.FallChance<=0||p.FallChance<=s.NextFloat()))
                    { actor.ZipDownOrigin=actor.BodyOrigin;actor.MovementState=0x35;actor.MovementKind=0x2a;s.ZipDown(actor); }
                    if(p.Cheap)actor.Flags|=0x420;
                    if(p.Rider!=null)s.Ride(p.Rider,actor);
                    else if(p.Balloon){s.Balloon(actor);if(locator!=null)s.BalloonHeight(actor,locator.Position.Y);}
                    actor.Capabilities|=p.AddCapabilities;actor.Capabilities&=~p.RemoveCapabilities;
                }
            }
            return true;
        }
    }
}
