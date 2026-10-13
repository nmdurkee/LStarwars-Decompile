using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public static class ObstacleDifferential
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=200};
    static int checks,failures;
    static readonly List<object> examples=new List<object>();
    static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
    static bool B(Dictionary<string,object> o,string key,bool d){return o.ContainsKey(key)?Convert.ToBoolean(o[key]):d;}
    static int I(Dictionary<string,object> o,string key,int d){return o.ContainsKey(key)?Convert.ToInt32(o[key],CultureInfo.InvariantCulture):d;}
    static uint U(Dictionary<string,object> o,string key,uint d){return o.ContainsKey(key)?Convert.ToUInt32(o[key],CultureInfo.InvariantCulture):d;}
    static float F(Dictionary<string,object> o,string key,float d)
    {return o.ContainsKey(key+"Bits")?PcObjectImage.FromBits(U(o,key+"Bits",0)):o.ContainsKey(key)?Convert.ToSingle(o[key],CultureInfo.InvariantCulture):d;}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;
        Dictionary<string,object> ma=a as Dictionary<string,object>,mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(string k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        object[] aa=a as object[],bb=b as object[];
        if(aa!=null||bb!=null){if(aa==null||bb==null||aa.Length!=bb.Length)return false;for(int i=0;i<aa.Length;i++)if(!Same(aa[i],bb[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    static void Check(string group,object input,object actual,object expected)
    {
        checks++;object normalized=Json.DeserializeObject(Json.Serialize(actual));if(Same(normalized,expected))return;
        failures++;if(examples.Count<12)examples.Add(new{group=group,input=input,actual=normalized,expected=expected});
    }
    sealed class Fixture:ISceneryBindings
    {
        public Dictionary<string,object> Options;
        public ScenePlaybackGroup[] Groups=new ScenePlaybackGroup[2];
        public List<ScenePlaybackTarget>[] Targets=new List<ScenePlaybackTarget>[2];
        public SceneryObject[] Objects=new SceneryObject[2];
        public SceneryGizmo[] Gizmos=new SceneryGizmo[3];
        public ScenePlaybackQueue Queue=new ScenePlaybackQueue();
        public SceneryWorld World;
        public List<object> Calls=new List<object>();
        public Fixture(Dictionary<string,object> options)
        {
            Options=options;object[] nodes=options.ContainsKey("nodes")?(object[])options["nodes"]:(object[])Json.DeserializeObject("[{\"start\":1,\"end\":61,\"frame\":17,\"rate\":3,\"scale\":0,\"flags\":2882400018,\"present\":true,\"reference\":true},{\"start\":81,\"end\":2,\"frame\":97,\"rate\":-2,\"scale\":0.5,\"flags\":324508639,\"present\":true,\"reference\":true}]");
            for(int i=0;i<2;i++)
            {
                ScenePlaybackGroup group=Groups[i]=new ScenePlaybackGroup{Flags=(ushort)I(options,"controlFlags",0),State=I(options,"state",4),MemberCount=(byte)I(options,"memberCount",nodes.Length),Queue=B(options,"queue",true)?Queue:null};Targets[i]=new List<ScenePlaybackTarget>();
                foreach(object raw in nodes)
                {
                    Dictionary<string,object> node=M(raw);ScenePlaybackTarget target=new ScenePlaybackTarget{Frame=F(node,"frame",0),Rate=F(node,"rate",0),RateScale=F(node,"scale",0),Flags=U(node,"flags",0)};Targets[i].Add(target);
                    group.Nodes.Add(new ScenePlaybackNode{Target=B(node,"present",true)?target:null,Start=F(node,"start",0),End=F(node,"end",0),HasOwner=B(node,"owner",true),ReferenceValid=B(node,"reference",true)});
                }
                Objects[i]=new SceneryObject{Animation=B(options,"animationPresent",true)?group:null,Speed=F(options,"speed",1),ForwardRate=F(options,"forwardRate",2),BackwardRate=F(options,"backwardRate",3),LoopMode=(byte)I(options,"loopMode",2),SpecialFlags=(byte)I(options,"specialFlags",2),StatusFlags=U(options,"obstacleStatus",3),Proximity=U(options,"proximity",0),StayFlags=U(options,"obstacleFlags",0xf0f0a5a5)};
                Gizmos[i]=new SceneryGizmo{Target=Objects[i],Type=(byte)I(options,"recordType",0)};
            }
            Gizmos[2]=new SceneryGizmo();
            SceneryRegistry registry=new SceneryRegistry();if(!B(options,"typesMissing",false))
            {
                registry.Outputs=new Func<SceneryGizmo,uint,int,uint>[Math.Max(0,I(options,"typeCount",2))];
                if(!B(options,"outputMissing",false)){if(registry.Outputs.Length>0)registry.Outputs[0]=ObstacleCommands.ObstacleOutput;if(registry.Outputs.Length>1)registry.Outputs[1]=ObstacleCommands.SpecialOutput;}
            }
            World=new SceneryWorld{Registry=B(options,"registryMissing",false)?null:registry,Bindings=this};
            if(B(options,"concreteBindings",false))
            {
                registry.NameBuckets=new SceneryNameBucket[2];
                SceneryNameBindings names=new SceneryNameBindings{TypeCount=2,NameAccessors=B(options,"typesMissing",false)?null:new Func<SceneryGizmo,string>[]{SceneryNameBindings.ObjectName,SceneryNameBindings.ObjectName}};
                Objects[0].Name="a";Objects[1].Name="b";
                for(int kind=0;kind<2;kind++)
                {
                    SceneryNameBucket bucket=registry.NameBuckets[kind]=new SceneryNameBucket{Count=2};
                    for(int i=0;i<2;i++)bucket.Records.Add(new SceneryGizmo{Target=Objects[i],Type=(byte)kind});
                }
                World.Bindings=names;
            }
        }
        public SceneryGizmo Find(SceneryRegistry registry,int type,string name)
        {
            Calls.Add(new object[]{"find",type,name});
            if(B(Options,"registryMissing",false)||B(Options,"targetMissing",false)||name==null||SceneryText.Equal(name,"missing"))return null;
            if(SceneryText.Equal(name,"nullobject"))return Gizmos[2];
            SceneryGizmo result=Gizmos[SceneryText.Equal(name,"b")?1:0];result.Type=(byte)type;return result;
        }
        public object Snapshot()
        {
            List<object> values=new List<object>();List<int> queue=new List<int>();
            for(int i=0;i<2;i++)
            {
                List<object> nodes=new List<object>();foreach(ScenePlaybackTarget t in Targets[i])nodes.Add(new{frameBits=PcObjectImage.ToBits(t.Frame),rateBits=PcObjectImage.ToBits(t.Rate),flags=t.Flags});
                values.Add(new{controlFlags=Groups[i].Flags,state=Groups[i].State,obstacleFlags=Objects[i].StayFlags,nodes=nodes});
            }
            foreach(ScenePlaybackGroup group in Queue.Groups)queue.Add(Array.IndexOf(Groups,group));
            return new{targets=values,queue=queue,calls=Calls};
        }
    }
    static object Execute(string group,Dictionary<string,object> input)
    {
        Dictionary<string,object> options=input.ContainsKey("options")?M(input["options"]):new Dictionary<string,object>();Fixture f=new Fixture(options);
        if(group=="command")
        {
            string kind=(string)input["kind"];string[] tokens=Array.ConvertAll((object[])input["tokens"],x=>(string)x);int result=1;
            if(kind=="scp")result=ObstacleCommands.ExecuteScript(f.World,tokens,B(input,"first",true));else ObstacleCommands.ExecuteGraph(f.World,tokens,kind=="special");
            return new{result=result,state=f.Snapshot()};
        }
        if(group=="scene-control"||group=="scene-boundary")
        {
            string operation=(string)input["operation"];ScenePlaybackGroup g=f.Groups[0];float argument=F(input,"argument",1);
            switch(operation)
            {
                case "refresh":SceneAnimationControls.Refresh(g);break;
                case "play":SceneAnimationControls.Play(g,argument,B(input,"evaluate",false));break;
                case "loop":SceneAnimationControls.SetLoop(g,I(input,"argument",0));break;
                case "stop":SceneAnimationControls.Stop(g);break;
                case "start":SceneAnimationControls.JumpToStart(g);break;
                case "end":SceneAnimationControls.JumpToEnd(g);break;
                case "seek":SceneAnimationControls.Seek(g,argument);break;
                default:throw new InvalidDataException("Unknown scene operation");
            }
            return f.Snapshot();
        }
        if(group=="obstacle-helper")
        {if(B(input,"snap",false))ObstacleCommands.Snap(f.Objects[0],B(input,"backwards",false));else ObstacleCommands.Play(f.Objects[0],B(input,"backwards",false));return f.Snapshot();}
        if(group=="gizmo-output")
        {
            f.Gizmos[0].Type=(byte)(B(input,"special",false)?1:0);if(B(options,"objectMissing",false))f.Gizmos[0].Target=null;
            uint value=SceneryRegistry.Output(f.World.Registry,B(options,"recordMissing",false)?null:f.Gizmos[0],U(input,"index",0),I(input,"include",0));return new{value=value,state=f.Snapshot()};
        }
        if(group=="condition")
        {
            f.Gizmos[0].Type=(byte)(B(input,"special",false)?1:0);SceneryGizmo gizmo=B(input,"record",false)?f.Gizmos[0]:null;
            return PcObjectImage.ToBits(B(input,"atEnd",false)?ObstacleCommands.AtEnd(f.World.Registry,gizmo):ObstacleCommands.AtStart(f.World.Registry,gizmo));
        }
        if(group=="locked-condition")return PcObjectImage.ToBits(ObstacleCommands.LockedShut(new SceneryObject{StayFlags=U(input,"flags",0)}));
        if(group=="initializer")
        {SceneryGizmo g=ObstacleCommands.Initialize(f.World,(string)input["name"],B(input,"special",false));return g==null?0:Array.IndexOf(f.Gizmos,g)+1;}
        if(group=="authored-condition")
        {
            string name=(string)input["name"];Dictionary<string,object> use=M(input["authored"]);
            if((string)use["name"]=="ObstacleLockedShut")return PcObjectImage.ToBits(ObstacleCommands.LockedShut(ObstacleCommands.InitializeObject(f.World,name)));
            SceneryGizmo gizmo=ObstacleCommands.Initialize(f.World,name,B(input,"special",false));return PcObjectImage.ToBits(B(input,"atEnd",false)?ObstacleCommands.AtEnd(f.World.Registry,gizmo):ObstacleCommands.AtStart(f.World.Registry,gizmo));
        }
        throw new InvalidDataException("Unknown fixture group: "+group);
    }
    static Dictionary<string,object> Options(object value)
    {return M(Json.DeserializeObject(Json.Serialize(value)));}
    static object ExecuteReview(string group,Dictionary<string,object> input)
    {
        if(group=="object-initializer")
        {
            Fixture f=new Fixture(Options(new{registryMissing=B(input,"registryMissing",false)}));
            SceneryObject target=ObstacleCommands.InitializeObject(f.World,(string)input["name"]);
            // Fixture pointer projection only: native review objects start at
            // DATA+0x9000, with stride0x200. The portable API returns references.
            return target==null?0u:0x10109000u+(uint)Array.IndexOf(f.Objects,target)*0x200u;
        }
        if(group=="stop-state-and-flags")
        {
            Fixture f=new Fixture(Options(new{state=I(input,"state",4),controlFlags=I(input,"flags",0),nodes=new object[]{
                new{start=1f,end=2f,frame=1.5f,flags=UInt32.MaxValue},
                new{start=3f,end=0f,frame=1f,flags=0xa5a5a5a5u,present=B(input,"secondPresent",false)}}}));
            int result=SceneAnimationControls.Stop(f.Groups[0]);
            return new Dictionary<string,object>{{"return",result},{"state",f.Snapshot()}};
        }
        if(group=="special-reference-and-side-effect")
        {
            // Native reference+4 OR reference+8 is represented by ReferenceValid.
            bool valid=(string)input["reference"]!="none";
            Fixture f=new Fixture(Options(new{memberCount=I(input,"memberCount",0),state=4,controlFlags=0,specialFlags=0,
                nodes=new object[]{new{start=2f,end=7f,frame=7f,flags=3u,reference=valid}}}));
            uint value=ObstacleCommands.SpecialOutput(f.Gizmos[0],U(input,"index",0),I(input,"include",0));
            return new{value=value,state=f.Groups[0].State};
        }
        if(group=="shared-target-and-queue")
        {
            Fixture f=new Fixture(Options(new{state=4,controlFlags=2,nodes=new object[]{
                new{start=0f,end=10f,frame=F(input,"frame",0),flags=0xabcd0004u,scale=F(input,"scale",0),rate=3f},
                new{start=100f,end=20f,frame=-200f,flags=0xdeadbeefu,scale=9f,rate=4f}}}));
            f.Groups[0].Nodes[1].Target=f.Targets[0][0];
            f.Groups[1].Nodes[0].Target=f.Targets[0][0];
            f.Groups[1].Nodes[1].Target=f.Targets[0][0];
            foreach(object which in(object[])input["sequence"])
                SceneAnimationControls.Play(f.Groups[Convert.ToInt32(which)],F(input,"speed",0),false);
            return f.Snapshot();
        }
        if(group=="null-return")
        {
            switch((string)input["address"])
            {
                case "0x5a1170":return SceneAnimationControls.Stop(null);
                case "0x5a1030":return SceneAnimationControls.Play(null,1,true);
                case "0x5a11b0":return SceneAnimationControls.SetLoop(null,-1);
                case "0x5a11f0":return SceneAnimationControls.JumpToEnd(null);
                case "0x5a1230":return SceneAnimationControls.JumpToStart(null);
                default:throw new InvalidDataException("Unknown null-return address");
            }
        }
        throw new InvalidDataException("Unknown obstacle review group: "+group);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2&&args.Length!=3)throw new ArgumentException("Usage: obstacle fixtures.json results.json [native-obstacle-review-tests.json]");
        checks=failures=0;examples.Clear();int reviewCases=0;
        Dictionary<string,object> fixture=M(Json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object raw in(object[])fixture["cases"])
        {Dictionary<string,object> c=M(raw);string group=(string)c["group"];Dictionary<string,object> input=M(c["input"]);Check(group,input,Execute(group,input),c["expected"]);}
        if(args.Length==3)
        {
            Dictionary<string,object> review=M(Json.DeserializeObject(File.ReadAllText(args[2])));
            foreach(object raw in(object[])review["cases"])
            {
                Dictionary<string,object> c=M(raw);string group=(string)c["group"];Dictionary<string,object> input=M(c["input"]);
                Check("review-"+group,input,ExecuteReview(group,input),c["native"]);reviewCases++;
            }
        }
        string report=Json.Serialize(new{cases=checks,reviewCases=reviewCases,mismatches=failures,examples=examples,scope="Compiled portable obstacle/scene-control outputs compared against saved original-PC observations."});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
    }
}
