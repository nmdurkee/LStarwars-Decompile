using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

// Four arguments: command fixtures, helper fixtures, raw original sine table,
// output JSON. Observation-only native look-helper events are filtered; all
// resulting request fields and RNG changes are compared directly instead.
public class GameplayFacingVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float Float(object v){return BitConverter.ToSingle(BitConverter.GetBytes(U(v)),0);}
    static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
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
    static List<object> FilterEvents(object rows){List<object> result=new List<object>();foreach(object row in (IList)rows)if((string)((IList)row)[0]!="look")result.Add(row);return result;}
    static FacingLookRequest Request(object row,FacingPoint[] points)
    {Dictionary<string,object> b=Obj(row);int target=Int(b["target"]);return new FacingLookRequest{Target=target<0?null:points[target],CachedPosition=Vector(b["position"]),Priority=(sbyte)Int(b["priority"]),Duration=Float(b["duration"]),Delay=Float(b["delay"])};}
    static object RequestSnapshot(FacingLookRequest r,FacingPoint[] p)
    {return new Dictionary<string,object>{{"target",r.Target==null?-1:Array.IndexOf(p,r.Target)},{"position",Words(r.CachedPosition)},{"priority",r.Priority},{"duration",Bits(r.Duration)},{"delay",Bits(r.Delay)}};}
    class World:MovementWorld
    {
        public readonly List<object> Events=new List<object>();
        public readonly LocatorActor[] Actors=new LocatorActor[3];
        public readonly FacingPoint[] HeadPoints=new FacingPoint[4];
        public readonly object Prior=new object();
        public LocatorCreature Creature,Storage;
        public FacingWorld Facing;
        public FacingPacket Packet;
        public ScriptRandom FloatRandom=new ScriptRandom();
        public Dictionary<string,object> Options;
        public int Opt(string k,int d){return Options.ContainsKey(k)?Int(Options[k]):d;}
        public bool Opt(string k,bool d){return Options.ContainsKey(k)?Convert.ToBoolean(Options[k]):d;}
        public override LocatorRecord Find(string name){Events.Add(new object[]{"find",name});return base.Find(name);}
        public World(Dictionary<string,object> c,Dictionary<string,object> b,Dictionary<string,object> o,string command,float[] sine)
        {
            Options=o;Movement=new Services(this);Facing=new FacingWorld{World=this,Camera=new FacingPoint(),SineTable=sine,Random=new QRandom{State=U(b["qrand"])}};FloatRandom.State=U(b["floatRng"]);
            foreach(object row in Arr(c["records"]))
            {Dictionary<string,object> r=Obj(row);Locators.Add(new LocatorRecord{Name=(string)r["name"],Position=Vector(r["position"]),Heading=unchecked((int)U(r["heading"])),Orientation=Raw(r["orientation"])});}
            ScriptDefinition script=new ScriptDefinition();ScriptPacket numbers=new ScriptPacket{Script=script};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){script.ParameterNames[i]=names[i];numbers.Parameters[i]=values[i];}
            int selected=Int(c["selected"]),bound=Int(b["bound"]);
            Packet=new FacingPacket{Angle=(ushort)Int(b["angle"]),Offset=Float(b["offset"]),Shared=new LocatorPacket{Numbers=numbers,Selected=selected<0?null:Locators[selected],Flags=(byte)Int(b["flags"]),Wait=Float(b["wait"]),FacingPoint=Vector(b["point"])}};
            for(int i=0;i<3;i++)
            {Actors[i]=new LocatorActor{Id=i,Controller=new LocatorCreature(),Position=Vector(Arr(c["actorPositions"])[i]),Origin80=Vector(Arr(c["origins"])[i]),Angle27a=(ushort)Int(Arr(c["actorAngles"])[i])};Actors[i].WorldObject=Actors[i];HeadPoints[i]=new FacingPoint{Position=Vector(Arr(c["headpoints"])[i])};}
            HeadPoints[3]=Facing.Camera;Facing.Camera.Position=Vector(Arr(c["headpoints"])[3]);
            for(int i=0;i<3;i++){Facing.LookRequests.Add(Actors[i],Request(Arr(b["head"])[i],HeadPoints));int point=Opt("lookPoint",0);Facing.CameraLookPoints.Add(Actors[i],point<0?null:HeadPoints[point]);}
            if(!Opt("opponentController",true))Actors[Opt("opponent",1)].Controller=null;
            int world=Int(c["worldObject"]);Actors[0].WorldObject=world<0?null:Actors[world];Storage=Actors[0].Controller;Creature=Convert.ToBoolean(c["creature"])?Storage:null;
            Storage.Reference=Convert.ToBoolean(c["reference"])?Actors[0]:null;Storage.MovementMode=(byte)Int(b["mode"]);Storage.Path=Opt("path",true)?new MovementPath():null;Storage.Node=Opt("node",true)?new MovementNode():null;
            if(Opt("embeddedCreature",false))Facing.EmbeddedCreatureOwners.Add(Storage,Actors[0]);
            int opponent=Opt("opponent",1),nearest=Opt("nearest",2),player=Opt("player",1);Storage.Opponent=opponent<0?null:Actors[opponent];Facing.NearestOpponent=nearest<0?null:Actors[nearest];Facing.PrimaryPlayer=player<0?null:Actors[player];
            if(command=="FaceLocator")Packet.Shared.Active=bound<0?null:Locators[bound];else Packet.Shared.FollowTarget=bound<0?null:Actors[bound];
            string look=(string)b["look"];Storage.LookTarget=look==null?null:look=="prior"?Prior:look=="packet"?(object)Packet.Shared:look=="camera"?(object)Facing.Camera:look.StartsWith("actor:")?(object)Actors[Int32.Parse(look.Substring(6))]:(object)Locators[Int32.Parse(look.Substring(8))];
            if(Convert.ToBoolean(c["callback"]))ResolveReference=delegate(string name){Events.Add(new object[]{"reference",name});if(name.StartsWith("missing",StringComparison.OrdinalIgnoreCase))return null;int value=0;foreach(char ch in name.ToLowerInvariant())value+=ch;return Actors[1+value%2];};
        }
        public object Snapshot(string command)
        {
            string look=null;if(Storage.LookTarget!=null){if(Object.ReferenceEquals(Storage.LookTarget,Prior))look="prior";else if(Object.ReferenceEquals(Storage.LookTarget,Packet.Shared))look="packet";else if(Object.ReferenceEquals(Storage.LookTarget,Facing.Camera))look="camera";else if(Storage.LookTarget is LocatorActor)look="actor:"+((LocatorActor)Storage.LookTarget).Id;else look="locator:"+Locators.IndexOf((LocatorRecord)Storage.LookTarget);}
            List<object> heads=new List<object>();foreach(LocatorActor a in Actors)heads.Add(RequestSnapshot(Facing.LookRequests[a],HeadPoints));
            return new Dictionary<string,object>{{"wait",Bits(Packet.Shared.Wait)},{"flags",Packet.Shared.Flags},{"angle",Packet.Angle},{"offset",Bits(Packet.Offset)},{"point",Words(Packet.Shared.FacingPoint)},{"bound",command=="FaceLocator"?(Packet.Shared.Active==null?-1:Locators.IndexOf(Packet.Shared.Active)):(Packet.Shared.FollowTarget==null?-1:Packet.Shared.FollowTarget.Id)},{"mode",Storage.MovementMode},{"look",look},{"floatRng",FloatRandom.State},{"qrand",Facing.Random.State},{"head",heads}};
        }
    }
    class Services:MovementServices
    {
        readonly World w;public Services(World value){w=value;}
        public override bool MovementToken(LocatorCreature c,string t){if(w.Opt("noTokenCallback",false))return false;w.Events.Add(new object[]{"token",t});return FacingCommands.MovementToken(t,ref c.MovementMode);}
        public override float Evaluate(LocatorCreature c,LocatorPacket p,string t){w.Events.Add(new object[]{"expression",t});return MessageNumbers.Resolve(p.Numbers,t);}
        public override float NextFloat(){return w.FloatRandom.Next();}
        public override SpawnVector Rotate(SpawnVector v,int angle){return FacingMath.RotateY(v,unchecked((ushort)angle),w.Facing.SineTable);}
        public override bool SpecialCompletion(LocatorActor a,LocatorRecord l){throw new InvalidOperationException("Not part of facing fixtures.");}
        public override void FormationOwnerCommand(LocatorCreature c,int mode){throw new InvalidOperationException("Not part of facing fixtures.");}
        public override void FormationIntent(LocatorCreature c){throw new InvalidOperationException("Not part of facing fixtures.");}
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0]))),helpers=Obj(json.DeserializeObject(File.ReadAllText(args[1])));byte[] rawSine=File.ReadAllBytes(args[2]);float[] sine=new float[32768];for(int i=0;i<sine.Length;i++)sine[i]=BitConverter.ToSingle(rawSine,i*4);int index=0;
        foreach(object item in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(item),expected=Obj(v["native"]);string command=(string)v["command"];World w=new World(Obj(v["context"]),Obj(v["before"]),Obj(v["options"]),command,sine);object[] ts=Arr(v["tokens"]);string[] tokens=new string[ts.Length];for(int i=0;i<ts.Length;i++)tokens[i]=(string)ts[i];bool first=Convert.ToBoolean(v["first"]);float delta=Float(v["delta"]);
            try
            {bool result;switch(command){case "FacePlayer":result=FacingCommands.FacePlayer(w.Facing,w.Packet,w.Creature,tokens,first,delta);break;case "FaceOpponent":result=FacingCommands.FaceOpponent(w.Facing,w.Packet,w.Creature,tokens,first,delta);break;case "FaceCamera":result=FacingCommands.FaceCamera(w.Facing,w.Packet,w.Creature,tokens,first,delta);break;case "FaceCharacter":result=FacingCommands.FaceCharacter(w.Facing,w.Packet,w.Creature,tokens,first,delta);break;case "FaceLocator":result=FacingCommands.FaceLocator(w.Facing,w.Packet,w.Creature,tokens,first);break;case "SpinOnSpot":result=FacingCommands.SpinOnSpot(w.Facing,w.Packet,w.Creature,tokens,first,delta);break;default:throw new ArgumentException(command);}Check("state",w.Snapshot(command),expected["state"],index);Check("events",FilterEvents(w.Events),FilterEvents(expected["events"]),index);Check("result",result?1:0,expected["result"],index);}
            catch(Exception ex){++failures;if(errors.Count<20)errors.Add(new{index,error=ex.ToString()});}++index;
        }
        foreach(object row in Arr(helpers["cases"]))
        {
            Dictionary<string,object> h=Obj(row);string kind=(string)h["kind"];
            try
            {
                object result;
                if(kind=="token"){byte mode=(byte)Int(h["mode"]);bool yes=FacingCommands.MovementToken((string)h["token"],ref mode);result=new object[]{yes?1:0,mode};}
                else if(kind=="normalize")result=Words(FacingMath.Normalize(Vector(h["point"])));
                else if(kind=="rotate")result=Words(FacingMath.RotateY(Vector(h["point"]),(ushort)Int(h["angle"]),sine));
                else{object[] values=Arr(h["positions"]);FacingPoint[] points=new FacingPoint[values.Length];for(int i=0;i<points.Length;i++)points[i]=new FacingPoint{Position=Vector(values[i])};FacingLookRequest state=Request(h["before"],points);QRandom random=new QRandom{State=U(h["seed"])};int target=Int(h["target"]);FacingCommands.RequestLook(state,target<0?null:points[target],(sbyte)Int(h["priority"]),Float(h["duration"]),Float(h["minDelay"]),Float(h["maxDelay"]),random);result=new Dictionary<string,object>{{"state",RequestSnapshot(state,points)},{"qrand",random.State}};}
                Check(kind,result,h["native"],index);
            }
            catch(Exception ex){++failures;if(errors.Count<20)errors.Add(new{index,error=ex.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[3],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
