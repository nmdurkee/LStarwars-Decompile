using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayCreateCreaturesVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object o){return (Dictionary<string,object>)o;}
    static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    static uint[] Vector(SpawnVector v){return new uint[]{Bits(v.X),Bits(v.Y),Bits(v.Z)};}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;
        IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object key in ad.Keys)if(!bd.Contains(key)||!Equal(ad[key],bd[key]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Check(string kind,object got,object want,int index)
    {++checks;if(!Equal(got,want)){++failures;if(errors.Count<20)errors.Add(new{kind,got,want,index});}}
    class World:SpawnServices
    {
        public Dictionary<string,object> Options;
        public readonly List<object> Events=new List<object>();
        public readonly List<SpawnActor> Actors=new List<SpawnActor>();
        public SpawnLocator[] Locators=new SpawnLocator[3];
        public SpawnZip[] Zips=new SpawnZip[3];
        public SpawnLocatorSet Set=new SpawnLocatorSet();
        public SpawnActor Self;
        public SpawnContext Context;
        public uint RandomState,FloatState;
        int selection,attempt;bool zipActive;
        public bool Flag(string name){return Options.ContainsKey(name)&&Convert.ToBoolean(Options[name]);}
        static bool Missing(string name){return name.StartsWith("missing",StringComparison.OrdinalIgnoreCase);}
        static int Hash(string name){int h=0;foreach(char c in name.ToLowerInvariant())h+=c;return h;}
        void Event(string name,params object[] values){object[] row=new object[values.Length+1];row[0]=name;Array.Copy(values,0,row,1,values.Length);Events.Add(row);}
        public World(Dictionary<string,object> options)
        {
            Options=options;RandomState=options.ContainsKey("seed")?Convert.ToUInt32(options["seed"]):1;FloatState=options.ContainsKey("floatSeed")?Convert.ToUInt32(options["floatSeed"]):123;
            object[] occupants=options.ContainsKey("occupants")?(object[])options["occupants"]:new object[]{255,0,255};
            for(int i=0;i<3;i++)
            { Locators[i]=new SpawnLocator{Id=i,Heading=i*0x4000,Position=new SpawnVector(10+i,20+i,30+i),Orientation=i+1};Set.Members.Add(Locators[i]);Set.Occupants.Add(Convert.ToByte(occupants[i]));Zips[i]=new SpawnZip{Id=i,Position=new SpawnVector(40+i,50+i,60+i)}; }
            Self=new SpawnActor{Position=new SpawnVector(2,3,4),Heading=0x4000,Orientation=-2,RiderPosition=new SpawnVector(8,9,10),RiderOrientation=-2};
            ScriptDefinition script=new ScriptDefinition();ScriptPacket packet=new ScriptPacket{Script=script,SetId=7};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};
            for(int i=0;i<4;i++){script.ParameterNames[i]=names[i];packet.Parameters[i]=values[i];}
            Context=new SpawnContext{Services=this,Packet=packet,Self=Self,SelfRider=Self,MyLocator=Locators[2],MyLocatorSet=Set,HubMode=Flag("hub"),TypeCallbacksAvailable=!Flag("noTypeCallbacks")};
        }
        public override byte FindType(string name){Event("findtype",name);return Missing(name)?(byte)255:(byte)(Hash(name)%8);}
        public override short ResolveType(byte index){Event("resolvetype",index);return (short)(index+1);}
        public override short HubType(string name){return (short)(name.Equals("barman",StringComparison.OrdinalIgnoreCase)?2:name.Equals("jabba",StringComparison.OrdinalIgnoreCase)?3:5);}
        public override short RandomMapType(){Event("randommap");return 4;}
        public override short GenericGoonType(){Event("generic");return 3;}
        public override SpawnLocator FindLocator(string name){Event("locator",name);return Missing(name)?null:Locators[Hash(name)%3];}
        public override SpawnLocatorSet FindLocatorSet(string name){Event("set",name);return Missing(name)?null:Set;}
        public override void RefreshLocatorSet(SpawnLocatorSet set){Event("refresh");}
        public override SpawnZip FindZip(string name){Event("zip",name);return Missing(name)?null:Zips[Hash(name)%3];}
        public override SpawnActor FindRider(string name){Event("rider",name);return Missing(name)?null:Self;}
        public override uint Capability(string name){Event("capability",name);return name.Equals("gun",StringComparison.OrdinalIgnoreCase)?4u:0x80000002u;}
        public override int NextInteger()
        {
            unchecked{int v=(int)(RandomState^0x75bd924);int r=v*0x41a7-(v/0x1f31d)*0x7fffffff;if(r<0)r+=0x7fffffff;RandomState=(uint)r^0x75bd924;return (int)RandomState;}
        }
        public override float NextFloat(){unchecked{FloatState=FloatState*0x19660d+0x3c6ef35f;}return (FloatState&0x7fffff)/8388608.0f;}
        public override SpawnLocator SelectLocator(SpawnSelection r)
        {
            List<int> ids=new List<int>();foreach(SpawnLocator l in r.Candidates)ids.Add(l.Id);
            Event("select",r.NearestPlayer,ids,Bits(r.Radius),r.HasPlayerReference,Bits(r.MaximumRange),r.OnScreen?1:0,Bits(r.MaximumY),Bits(r.MinimumY));
            SpawnLocator result=Flag("selectFail")||r.Candidates.Count==0?null:r.Candidates[selection%r.Candidates.Count];++selection;zipActive=false;return result;
        }
        public override SpawnZip SelectZip(IList<SpawnZip> candidates)
        { List<int> ids=new List<int>();foreach(SpawnZip z in candidates)ids.Add(z.Id);Event("selectzip",ids);zipActive=true;SpawnZip result=Flag("selectFail")||candidates.Count==0?null:candidates[selection%candidates.Count];++selection;return result; }
        public override float TypeRadius(short type){return type+.5f;}
        public override float FormationValue(short type){return type+1.25f;}
        public override object CreateFormation(int across,float x,float z,float value){Event("formation",across,Bits(x),Bits(z),Bits(value));return this;}
        public override SpawnVector RotateOffset(SpawnVector v,int heading)
        {
            // Cardinal fixture LUT supplied to the original native helper.
            double sin=heading==0x4000?1:0,cos=heading==0?1:heading==0x8000?-1:0;
            return new SpawnVector((float)(sin*v.Z+cos*v.X),v.Y,(float)(cos*v.Z-sin*v.X));
        }
        public override SpawnActor Spawn(SpawnRequest r)
        {
            Event("spawn",r.Type,Vector(r.Position),r.Heading,r.Script,r.Orientation==null?0:r.Orientation,r.Formation!=null,r.SetOnSurface,r.Set);
            int ix=attempt++;
            if((Options.ContainsKey("success")&&!Flag("success"))||zipActive||(Flag("alternating")&&ix%2!=0))return null;
            SpawnActor a=new SpawnActor{Id=ix,Slot=(byte)(10+ix),Flags=0x1001,GunFlags=0x1234567f,Capabilities=0x12345678,LocatorSet=Flag("preinherit")?Set:null,BodyOrigin=new SpawnVector(1+ix,2,3)};Actors.Add(a);return a;
        }
        public override void SetState(SpawnActor a,string state){Event("state",a.Id,state);}
        public override void Crate(SpawnActor a,float height,float delay){Event("crate",a.Id,Bits(height),Bits(delay));}
        public override void ZipDown(SpawnActor a){Event("zipdown",a.Id);}
        public override void ZipUp(SpawnActor a,SpawnZip z){throw new InvalidOperationException("Successful zip-up is outside these fixtures.");}
        public override void Ride(SpawnActor rider,SpawnActor mount){Event("ride",mount.Id);}
        public override void Balloon(SpawnActor a){Event("balloon",a.Id);}
        public override void BalloonHeight(SpawnActor a,float h){Event("balloonheight",a.Id,Bits(h));}
        public List<object> ActorSnapshots()
        {
            List<object> list=new List<object>();foreach(SpawnActor a in Actors)list.Add(new Dictionary<string,object>{{"index",a.Id},{"locator",a.Locator==null?-1:a.Locator.Id},{"setref",a.LocatorSet!=null},{"flags",a.Flags},{"gun",a.GunFlags},{"capability",a.Capabilities},{"movement",a.MovementState},{"kind",a.MovementKind},{"ziporigin",Vector(a.ZipDownOrigin)}});return list;
        }
    }
    static Dictionary<string,object> Plan(SpawnPlan p)
    {
        List<int> locs=new List<int>(),zips=new List<int>();foreach(SpawnLocator l in p.Locators)locs.Add(l.Id);foreach(SpawnZip z in p.Zips)zips.Add(z.Id);
        return new Dictionary<string,object>{{"minimum",p.Minimum},{"maximum",p.Maximum},{"count",p.Count},{"across",p.Across},{"set",p.Set},{"grouped",p.Grouped},{"surface",p.SetOnSurface},{"inherit",p.InheritLocatorSet},{"start",p.StartLocatorSet},{"nearest",p.NearestPlayer},{"offscreen",p.OffScreen},{"onscreen",p.OnScreen},{"zipdown",p.ZipDown},{"cheap",p.Cheap},{"nogun",p.NoGun},{"balloon",p.Balloon},{"xspacing",Bits(p.XSpacing)},{"zspacing",Bits(p.ZSpacing)},{"maxrange",Bits(p.MaximumRange)},{"miny",Bits(p.MinimumY)},{"maxy",Bits(p.MaximumY)},{"crateheight",Bits(p.CrateHeight)},{"cratedelay",Bits(p.CrateDelay)},{"fall",Bits(p.FallChance)},{"offset",Vector(p.Offset)},{"script",p.Script},{"state",p.State},{"setref",p.LocatorSet!=null},{"rider",p.Rider!=null},{"types",p.Types},{"locators",locs},{"zips",zips},{"addcap",p.AddCapabilities},{"removecap",p.RemoveCapabilities}};
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;
        Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
        foreach(object item in (object[])data["cases"])
        {
            Dictionary<string,object> c=Obj(item),expected=Obj(c["native"]),options=Obj(c["options"]);bool first=Convert.ToBoolean(c["first"]);
            object[] raw=(object[])c["tokens"];string[] tokens=new string[raw.Length];for(int i=0;i<raw.Length;i++)tokens[i]=(string)raw[i];
            try
            {
                if(first){World parse=new World(options);Check("plan",Plan(CreatureSpawner.Parse(parse.Context,tokens)),expected["plan"],index);}
                World w=new World(options);bool result=CreatureSpawner.Execute(w.Context,tokens,first);
                Check("result",result?1:0,expected["result"],index);Check("events",w.Events,expected["events"],index);Check("actors",w.ActorSnapshots(),expected["actors"],index);Check("occupants",w.Set.Occupants,expected["occupants"],index);Check("rng",w.RandomState,expected["rng"],index);Check("floatRng",w.FloatState,expected["floatRng"],index);
            }
            catch(Exception ex){++failures;if(errors.Count<20)errors.Add(new{index,error=ex.ToString()});}
            ++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,cases=index,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
