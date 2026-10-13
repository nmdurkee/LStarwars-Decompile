using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayCreateSplineCreaturesVerify
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
    class World:SplineSpawnServices
    {
        public Dictionary<string,object> Options;
        public readonly List<object> Events=new List<object>();
        public readonly List<SplineActor> Actors=new List<SplineActor>();
        readonly Dictionary<SplineFollower,SplineActor> owners=new Dictionary<SplineFollower,SplineActor>();
        public SpawnLocator[] Locators=new SpawnLocator[3];
        public readonly object Rider=new object(),Player=new object();
        public SplineSpawnContext Context;
        public uint RandomState,FloatState,Spline16;
        int attempt;
        public bool Flag(string name){return Options.ContainsKey(name)&&Convert.ToBoolean(Options[name]);}
        int Option(string name,int fallback){return Options.ContainsKey(name)?Convert.ToInt32(Options[name]):fallback;}
        static bool Missing(string name){return name.StartsWith("missing",StringComparison.OrdinalIgnoreCase);}
        static int Hash(string name){int h=0;foreach(char c in name.ToLowerInvariant())h+=c;return h;}
        void Event(string name,params object[] values){object[] row=new object[values.Length+1];row[0]=name;Array.Copy(values,0,row,1,values.Length);Events.Add(row);}
        public World(Dictionary<string,object> options,object[] splineNames)
        {
            Options=options;RandomState=options.ContainsKey("seed")?Convert.ToUInt32(options["seed"]):1;FloatState=options.ContainsKey("floatSeed")?Convert.ToUInt32(options["floatSeed"]):123;Spline16=options.ContainsKey("seed16")?Convert.ToUInt32(options["seed16"]):77;
            List<SplineReference> splines=new List<SplineReference>();
            for(int i=0;i<splineNames.Length;i++)splines.Add(new SplineReference{Id=i,Name=(string)splineNames[i]});
            for(int i=0;i<3;i++)Locators[i]=new SpawnLocator{Id=i,Position=new SpawnVector(10+i,20+i,30+i)};
            ScriptDefinition script=new ScriptDefinition();ScriptPacket packet=new ScriptPacket{Script=script,SetId=7};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};
            for(int i=0;i<4;i++){script.ParameterNames[i]=names[i];packet.Parameters[i]=values[i];}
            int selected=Option("selected",1),my=Option("mySpline",0);
            Context=new SplineSpawnContext{Services=this,Packet=packet,Self=Flag("noSelf")?null:this,HasSelfRiderReference=!Flag("noRiderRef"),SelfRider=Rider,
                MySpline=my<0?null:splines[my],SelectedSpline=selected<0?null:splines[selected],Splines=splines,PlayerReference=Player,
                LevelSplineLimitsActive=Flag("sameLevel"),TypeCallbacksAvailable=!Flag("noTypeCallbacks")};
        }
        public override byte FindType(string name){Event("findtype",name);return Missing(name)?(byte)255:(byte)(Hash(name)%8);}
        public override short ResolveType(byte index){Event("resolvetype",index);return index==7?(short)-1:(short)(index+1);}
        public override object FindLocator(string name){Event("locator",name);return Missing(name)?null:Locators[Hash(name)%3];}
        public override object FindRider(string name){Event("rider",name);return Missing(name)?null:Rider;}
        public override int NextInteger()
        {
            unchecked{int v=(int)(RandomState^0x75bd924);int r=v*0x41a7-(v/0x1f31d)*0x7fffffff;if(r<0)r+=0x7fffffff;RandomState=(uint)r^0x75bd924;return (int)RandomState;}
        }
        public override float NextFloat(){unchecked{FloatState=FloatState*0x19660d+0x3c6ef35f;}return (FloatState&0x7fffff)/8388608.0f;}
        public override int NextSpline16(){Spline16=(Spline16*0x24cd+1)&0xffff;return (int)Spline16;}
        public override SplineActor Spawn(SplineSpawnRequest r)
        {
            Event("spawn",(int)r.Type,0,0,r.Script,0,0,0,r.Spline.Id,Vector(r.Offset),r.Looping?1:0,r.Set);
            int ix=attempt++;
            if((Options.ContainsKey("success")&&!Flag("success"))||(Flag("alternating")&&ix%2!=0))return null;
            SplineActor a=new SplineActor{Id=ix,Offset=r.Offset};
            a.Follower.Spline=r.Spline;a.Follower.Header=(uint)(r.Looping?1:0)<<16;a.Follower.Time=.5f;
            Actors.Add(a);owners[a.Follower]=a;return a;
        }
        public override void LevelSplineLimits(SplineReference spline,out int first,out int second){Event("levelspline",spline.Id);first=spline.Id+10;second=spline.Id+20;}
        public override SplineFollower RelativeFollower(object origin,SplineReference spline,bool looping,int first,int second)
        {
            SpawnLocator l=origin as SpawnLocator;SpawnVector o=l==null?new SpawnVector(8,9,10):l.Position;
            Event("relative",l==null?(object)"player":l.Id,spline.Id,looping?1:0,first,second);
            SplineFollower f=new SplineFollower{Spline=spline,Header=(uint)(2+(looping?1:0))<<16,Time=.25f};
            f.Words[0]=(uint)first;f.Words[1]=(uint)second;f.Words[2]=Bits(o.X);f.Words[3]=Bits(o.Y);f.Words[4]=Bits(o.Z);
            foreach(SplineActor a in Actors)if(a.Id==attempt-1)owners[f]=a;
            return f;
        }
        public override void Advance(SplineFollower f,float distance){Event("advance",owners[f].Id,Bits(distance));f.Time=MessageNumbers.Round(f.Time+distance);}
        public override void Evaluate(SplineReference spline,float time,int mode,out SpawnVector position,out ushort heading,out int pitch)
        {
            Event("evaluate",spline.Id,Bits(time),mode);
            position=new SpawnVector(MessageNumbers.Round(time*2),3,MessageNumbers.Round(-time));
            heading=(ushort)new int[]{0,0x4000,0x8000,0xc000}[spline.Id%4];pitch=new int[]{0,0x4000,0xc000,0x8000}[(spline.Id+mode)%4];
        }
        // Cardinal fixture LUT supplied to the original native helpers.
        public override float AngleTable(int index){return index==0x2000?1f:index==0x6000?-1f:0f;}
        public override void UpdatePlacement(SplineActor a){Event("update",a.Id);}
        public override void Ride(object rider,SplineActor mount){Event("ride","rider",mount.Id,0,1);}
        public List<object> ActorSnapshots()
        {
            List<object> list=new List<object>();
            foreach(SplineActor a in Actors)
            {
                SplineFollower f=a.Follower;
                list.Add(new Dictionary<string,object>{{"index",a.Id},{"follower",new object[]{f.Spline==null?-1:f.Spline.Id,f.Header,f.Words[0],f.Words[1],f.Words[2],f.Words[3],f.Words[4],Bits(f.Time)}},{"offset",Vector(a.Offset)},
                    {"angles",new int[]{a.Heading58,a.Heading5A}},{"pitchYaw",new int[]{a.Pitch278,a.Heading27A}},{"position",Vector(a.Position)},{"p80",Vector(a.Origin80)},{"p8c",Vector(a.Origin8C)},{"p98",Vector(a.Origin98)},{"p1b4",Vector(a.Previous1B4)},{"p10bc",Vector(a.Previous10BC)}});
            }
            return list;
        }
    }
    // count and distance are captured after the native RNG/lerp; their effects are compared through events.
    static Dictionary<string,object> Plan(SplineSpawnPlan p,World w,Dictionary<string,object> want)
    {
        List<int> splines=new List<int>();foreach(SplineReference r in p.Splines)splines.Add(r.Id);
        SpawnLocator l=p.RelativeLocator as SpawnLocator;
        return new Dictionary<string,object>{{"minimum",p.Minimum},{"maximum",p.Maximum},{"count",want["count"]},{"set",p.Set},{"distance",want["distance"]},{"mindistance",Bits(p.MinimumDistance)},{"maxdistance",Bits(p.MaximumDistance)},
            {"useSelected",p.UseSelected},{"looping",p.Looping},{"relativeToPlayer",p.RelativeToPlayer},{"relativeLocator",l==null?-1:l.Id},{"rider",p.Rider==null?"none":"rider"},{"offset",Vector(p.Offset)},{"script",p.Script},{"types",p.Types},{"splines",splines}};
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;
        Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;object[] names=(object[])data["splines"];
        foreach(object item in (object[])data["cases"])
        {
            Dictionary<string,object> c=Obj(item),expected=Obj(c["native"]),options=Obj(c["options"]);bool first=Convert.ToBoolean(c["first"]);
            object[] raw=(object[])c["tokens"];string[] tokens=new string[raw.Length];for(int i=0;i<raw.Length;i++)tokens[i]=(string)raw[i];
            try
            {
                if(first){World parse=new World(options,names);Check("plan",Plan(SplineCreatureSpawner.Parse(parse.Context,tokens),parse,Obj(expected["plan"])),expected["plan"],index);}
                World w=new World(options,names);bool result=SplineCreatureSpawner.Execute(w.Context,tokens,first);
                Check("result",result?1:0,expected["result"],index);Check("events",w.Events,expected["events"],index);Check("actors",w.ActorSnapshots(),expected["actors"],index);
                Check("rng",w.RandomState,expected["rng"],index);Check("floatRng",w.FloatState,expected["floatRng"],index);Check("rng16",w.Spline16,expected["rng16"],index);Check("globalPosition",Vector(w.Context.LastPlacement),expected["globalPosition"],index);
            }
            catch(Exception ex){++failures;if(errors.Count<20)errors.Add(new{index,error=ex.ToString()});}
            ++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,cases=index,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
