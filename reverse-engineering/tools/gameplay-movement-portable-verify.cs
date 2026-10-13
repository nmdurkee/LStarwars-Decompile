using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

// Replays original-PC state deltas. Intent call observations are filtered because
// the portable implementation executes those writes directly, without an adapter.
public class GameplayMovementVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float Float(object v){return BitConverter.ToSingle(BitConverter.GetBytes(U(v)),0);}
    static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    static SpawnVector Vector(object o){object[] a=Arr(o);return new SpawnVector(Float(a[0]),Float(a[1]),Float(a[2]));}
    static uint[] Words(SpawnVector v){return new uint[]{Bits(v.X),Bits(v.Y),Bits(v.Z)};}
    static uint[] Raw(object o){object[] a=Arr(o);uint[] w=new uint[a.Length];for(int i=0;i<w.Length;i++)w[i]=U(a[i]);return w;}
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
    static void Check(string group,object got,object want,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<20)errors.Add(new{group,got,want,index});}}
    static List<object> Events(object rows){List<object> result=new List<object>();foreach(object row in (IList)rows)if((string)((IList)row)[0]!="intent")result.Add(row);return result;}
    class World:MovementWorld
    {
        public readonly List<object> Events=new List<object>();
        public LocatorActor[] Actors=new LocatorActor[3];
        public LocatorCreature Creature,Storage;
        public LocatorPacket Caller;
        public uint State;
        public ScriptRandom FloatRandom=new ScriptRandom();
        public Dictionary<string,object> Options;
        public int Option(string k,int d){return Options.ContainsKey(k)?Int(Options[k]):d;}
        public bool Option(string k,bool d){return Options.ContainsKey(k)?Convert.ToBoolean(Options[k]):d;}
        public float Option(string k,float d){return Options.ContainsKey(k)?Convert.ToSingle(Options[k]):d;}
        public override LocatorRecord Find(string name){Events.Add(new object[]{"find",name});return base.Find(name);}
        int Draw(){unchecked{int x=(int)(State^0x75bd924);int v=x*0x41a7-(x/0x1f31d)*0x7fffffff;if(v<0)v+=0x7fffffff;State=(uint)v^0x75bd924;return (int)State;}}
        public World(Dictionary<string,object> c,Dictionary<string,object> b,Dictionary<string,object> o,string command)
        {
            Options=o;Movement=new Services(this);
            foreach(object row in Arr(c["records"]))
            {Dictionary<string,object> r=Obj(row);Locators.Add(new LocatorRecord{Name=(string)r["name"],Position=Vector(r["position"]),Heading=unchecked((int)U(r["heading"])),Orientation=Raw(r["orientation"])});}
            ScriptDefinition script=new ScriptDefinition();ScriptPacket numbers=new ScriptPacket{Script=script};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){script.ParameterNames[i]=names[i];numbers.Parameters[i]=values[i];}
            int selected=Int(c["selected"]),target=Int(b["target"]);
            Caller=new LocatorPacket{Numbers=numbers,Selected=selected<0?null:Locators[selected],Flags=(byte)Int(b["packetFlags"]),HoldSpecial=(byte)Int(b["hold"]),Wait=Float(b["wait"]),FacingPoint=Vector(b["facing"])};
            byte[][] routes=new byte[3][];
            for(int i=0;i<3;i++){routes[i]=new byte[3];for(int j=0;j<3;j++)routes[i][j]=(byte)(o.ContainsKey("route")?Int(Arr(Arr(o["route"])[i])[j]):j);}
            MovementPath path=new MovementPath{NextHopOrdinals=routes};MovementNode[] nodes={new MovementNode{Index=0},new MovementNode{Index=1},new MovementNode{Index=2}};
            for(int i=0;i<3;i++)
            {
                LocatorCreature controller=new LocatorCreature{Path=i==0&&!Option("path",true)?null:path,Node=i==0&&!Option("node",true)?null:nodes[i],NodeFlags=i==1?(byte)Option("targetNodeFlags",0):(byte)0,Position=Vector(Arr(c["controllerPositions"])[i]),PathPoint=Vector(Arr(c["pathPoints"])[i]),PathWords=Raw(Arr(c["pathWords"])[i]),FollowRadius=1.25f+i,Flags=U(b["flags"])};
                object[] inputs=Arr(Arr(b["inputWords"])[i]);
                Actors[i]=new LocatorActor{Id=i,Controller=controller,Packet=new LocatorPacket{Numbers=numbers},PersonalIndex=(sbyte)Int(Arr(c["indices"])[i]),CharacterName=(string)Arr(c["characterNames"])[i],Position=Vector(Arr(c["actorPositions"])[i]),Input4=U(inputs[0]),Input8=U(inputs[1]),TravelSpeed=Option("speed",.75f),GroundState=(byte)Option("ground",1)};
                controller.Reference=Actors[i];Actors[i].WorldObject=Actors[i];
            }
            if(Option("differentPath",false))Actors[1].Controller.Path=new MovementPath();
            if(Option("sameNode",false))Actors[1].Controller.Node=nodes[0];
            int worldObject=Int(c["worldObject"]);Actors[0].WorldObject=worldObject<0?null:Actors[worldObject];Actors[0].Position=Vector(b["actorPosition"]);
            Storage=Actors[0].Controller;Creature=Convert.ToBoolean(c["creature"])?Storage:null;
            if(!Convert.ToBoolean(c["reference"]))Storage.Reference=null;
            Storage.GoalRange=Float(b["goal"]);Storage.MovementMode=(byte)Int(b["mode"]);Storage.IntentPoint=Vector(b["point"]);Storage.IntentRadius=Float(b["radius"]);Storage.IntentGoal=Float(b["intentGoal"]);Storage.IntentWords=Raw(b["words"]);Storage.Opponent=Option("opponent",false)?Actors[2]:null;
            Storage.LookTarget=(string)b["look"]=="opponent"?(object)Actors[2]:(string)b["look"]=="packet"?(object)Caller:null;
            if(command=="GoToLocator")Caller.Active=target<0?null:Locators[target];else Caller.FollowTarget=target<0?null:Actors[target];
            for(int i=0;i<2;i++){int p=Option("player"+i,i+1);FollowPlayers[i]=p<0?null:Actors[p];}
            HasFollowSystem=Option("system",true);HasCompletionCallback=Option("completionCallback",false);PartyOverride=Option("partyOverride",0f);PartyOffset=delegate(sbyte index){return index*.25f;};SpecialButtonMask=0x800;
            State=U(b["rng"]);FloatRandom.State=U(b["floatRng"]);NextInteger=Draw;
        }
        public object Snapshot(string command)
        {
            List<object> inputs=new List<object>();foreach(LocatorActor actor in Actors)inputs.Add(new uint[]{actor.Input4,actor.Input8});
            return new Dictionary<string,object>{{"packetFlags",Caller.Flags},{"hold",Caller.HoldSpecial},{"target",command=="GoToLocator"?(Caller.Active==null?-1:Locators.IndexOf(Caller.Active)):(Caller.FollowTarget==null?-1:Caller.FollowTarget.Id)},{"wait",Bits(Caller.Wait)},{"facing",Words(Caller.FacingPoint)},{"goal",Bits(Storage.GoalRange)},{"mode",Storage.MovementMode},{"flags",Storage.Flags},{"point",Words(Storage.IntentPoint)},{"radius",Bits(Storage.IntentRadius)},{"intentGoal",Bits(Storage.IntentGoal)},{"words",Storage.IntentWords},{"look",Object.ReferenceEquals(Storage.LookTarget,Actors[2])?"opponent":Object.ReferenceEquals(Storage.LookTarget,Caller)?"packet":null},{"actorPosition",Words(Actors[0].Position)},{"inputWords",inputs},{"rng",State},{"floatRng",FloatRandom.State}};
        }
    }
    class Services:MovementServices
    {
        readonly World w;public Services(World value){w=value;}
        public override bool MovementToken(LocatorCreature c,string t)
        {if(w.Option("noTokenCallback",false))return false;int mode=t.Equals("walk",StringComparison.OrdinalIgnoreCase)?17:t.Equals("run",StringComparison.OrdinalIgnoreCase)?34:t.Equals("tiptoe",StringComparison.OrdinalIgnoreCase)?51:0;w.Events.Add(new object[]{"token",t,mode!=0});if(mode!=0)c.MovementMode=(byte)mode;return mode!=0;}
        public override float Evaluate(LocatorCreature c,LocatorPacket p,string t){w.Events.Add(new object[]{"expression",t});return MessageNumbers.Resolve(p.Numbers,t);}
        public override float NextFloat(){return w.FloatRandom.Next();}
        public override SpawnVector Rotate(SpawnVector v,int heading){if(heading==0)return v;if(heading==0x4000)return new SpawnVector(v.Z,v.Y,-v.X);if(heading==0x8000)return new SpawnVector(-v.X,v.Y,-v.Z);throw new ArgumentException("Only fixture cardinal headings supplied.");}
        public override bool SpecialCompletion(LocatorActor a,LocatorRecord l){w.Events.Add(new object[]{"completion",a.Id,w.Locators.IndexOf(l)});return w.Option("completionResult",false);}
        public override void FormationOwnerCommand(LocatorCreature c,int mode){throw new InvalidOperationException("Formation expansion outside fixture.");}
        public override void FormationIntent(LocatorCreature c){throw new InvalidOperationException("Formation expansion outside fixture.");}
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
        foreach(object item in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(item),expected=Obj(v["native"]);string command=(string)v["command"];World w=new World(Obj(v["context"]),Obj(v["before"]),Obj(v["options"]),command);object[] ts=Arr(v["tokens"]);string[] tokens=new string[ts.Length];for(int i=0;i<ts.Length;i++)tokens[i]=(string)ts[i];
            try{bool result=command=="GoToLocator"?MovementCommands.GoToLocator(w,w.Caller,w.Creature,tokens,Convert.ToBoolean(v["first"]),Float(v["delta"])):MovementCommands.FollowPlayer(w,w.Caller,w.Creature,tokens,Convert.ToBoolean(v["first"]));Check("state",w.Snapshot(command),expected["state"],index);Check("events",Events(w.Events),Events(expected["events"]),index);Check("result",result?1:0,expected["result"],index);}
            catch(Exception ex){++failures;if(errors.Count<20)errors.Add(new{index,error=ex.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
