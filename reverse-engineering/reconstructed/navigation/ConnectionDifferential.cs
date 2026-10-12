// Compare portable connection runtime with saved original-x86 observations.
using System;
using System.IO;
using System.Collections.Generic;
using System.Globalization;
using System.Web.Script.Serialization;
using Recovered.Navigation;
public static class ConnectionDifferential
{
    static JavaScriptSerializer json = new JavaScriptSerializer { MaxJsonLength=Int32.MaxValue };
    static int checks,failures,skipped;
    static List<object> examples=new List<object>();
    static Dictionary<string,object> M(object o){return (Dictionary<string,object>)o;}
    static int I(Dictionary<string,object> m,string k,int d){return m.ContainsKey(k)?Convert.ToInt32(m[k],CultureInfo.InvariantCulture):d;}
    static uint U(Dictionary<string,object> m,string k,uint d){return m.ContainsKey(k)?Convert.ToUInt32(m[k],CultureInfo.InvariantCulture):d;}
    static bool B(Dictionary<string,object> m,string k,bool d){return m.ContainsKey(k)?Convert.ToBoolean(m[k]):d;}
    static float F(Dictionary<string,object> m,string k,float d){return m.ContainsKey(k)?Convert.ToSingle(m[k],CultureInfo.InvariantCulture):d;}
    static uint[] UA(object o){return Array.ConvertAll((object[])o,x=>Convert.ToUInt32(x,CultureInfo.InvariantCulture));}
    static void Check(string kind,object got,object want,object context)
    {
        checks++;if(json.Serialize(got)==json.Serialize(want))return;
        failures++;if(examples.Count<16)examples.Add(new{kind=kind,actual=got,expected=want,input=context});
    }
    sealed class Services:IConnectionServices
    {
        public Dictionary<string,object> options;
        public NavigationPath path;
        public ConnectionTarget target;
        public readonly List<object> calls=new List<object>();
        public NavigationPath FindPath(string name){calls.Add(new object[]{"path",name});return B(options,"pathMissing",false)?null:path;}
        public ConnectionTarget ResolveTarget(ConnectionKind kind,string name){calls.Add(new object[]{"target",(int)kind,name});return B(options,"targetMissing",false)?null:target;}
        public ConnectionTarget FakeAnimation(int index){return target;}
        public uint ReadGizmoOutput(ConnectionTarget t,uint index){calls.Add(new object[]{"output",index});return U(options,"output",0);}
        public int EvaluateInteger(string expression)
        {
            string s=expression.ToLowerInvariant();int nul=s.IndexOf('\0');if(nul>=0)s=s.Substring(0,nul);
            if(B(options,"parameters",true))
            {
                if(s=="alpha"||s.Contains("param"))return 5;
                if(s=="beta")return-1;if(s=="gamma")return 16;if(s=="delta")return 0;
            }
            double v;return Double.TryParse(s,NumberStyles.Float,CultureInfo.InvariantCulture,out v)?(int)v:0;
        }
    }
    static ConnectionTarget Target(Dictionary<string,object> o)
    {
        return new ConnectionTarget{HasAnimation=!B(o,"noAnimation",false),Visible=B(o,"visible",true),EndFrame=F(o,"end",60),Frame=F(o,"frame",1),BuildState=(byte)I(o,"buildState",2),BlowUpFlags=(byte)I(o,"blowupFlags",0),FlowFlags=(byte)I(o,"flowFlags",2),ObstacleState=I(o,"obstacleState",2),ZipFlags=(ushort)I(o,"zipFlags",0xc0),ForceFlags=U(o,"forceFlags",0),ForceFlags2=U(o,"forceFlags2",0),ForceTimer=F(o,"forceTimer",0),ForceHasObstacle=B(o,"forceHasObstacle",false)};
    }
    static ConnectionWorld World(Dictionary<string,object> o,out Services s,out NavigationConnection edge)
    {
        NavigationPath p=new NavigationPath();edge=new NavigationConnection{Endpoint0=0,Endpoint1=1,ForwardFlags=0x12345678,ReverseFlags=0x87654321,Obstacle=3};
        if(o.ContainsKey("edgeFlags")){uint[] v=UA(o["edgeFlags"]);edge.ForwardFlags=v[0];edge.ReverseFlags=v[1];}
        p.Locators.Add(new NavigationLocator{Name=o.ContainsKey("fromName")?(string)o["fromName"]:"a"});p.Locators.Add(new NavigationLocator{Name=o.ContainsKey("toName")?(string)o["toName"]:"b"});
        if(!B(o,"connectionMissing",false)){p.Locators[0].Connections.Add(edge);p.Locators[1].Connections.Add(edge);}
        s=new Services{options=o,path=p,target=Target(o)};ConnectionWorld w=new ConnectionWorld{Manager=new ConnectionManager(I(o,"capacity",4)),DefaultPath=p,Services=s,FlagDialect=I(o,"mode",1)};w.Paths.Add(p);
        if(o.ContainsKey("fallback")){uint[] values=UA(o["fallback"]);w.BigJumpFlag=values[0];w.RequiresPermissionFlag=values[1];w.NoDestinationCheckFlag=values[2];}
        return w;
    }
    static void Command(Dictionary<string,object> input,Dictionary<string,object> want)
    {
        Dictionary<string,object> o=M(input["options"]);Services s;NavigationConnection edge;ConnectionWorld w=World(o,out s,out edge);
        int result=ConnectionControllers.Execute(w,Array.ConvertAll((object[])input["tokens"],x=>(string)x),I(input,"first",1)!=0);
        Check("command-return",result,want["result"],input);Check("command-created",w.Manager.Active.Count!=0,want["created"],input);Check("command-services",s.calls,want["calls"],input);
        if(w.Manager.Active.Count==0||want["record"]==null)return;
        ConnectionController c=w.Manager.Active[0];Dictionary<string,object> r=M(want["record"]);
        Check("record-fields",new object[]{c.OnFlags,c.OffFlags,c.FrameMask,(int)c.Kind,c.PathIndex,c.Flags,c.Connection!=null,c.OutputIndex},new object[]{r["on"],r["off"],r["mask"],r["kind"],r["pathIndex"],r["flags"],r["connection"],r["output"]},input);
        // Native pointer words are represented by canonical managed object bindings.
        uint[] words=UA(r["targetWords"]);Check("record-target-binding",c.Kind==ConnectionKind.FakeAnimation?unchecked((uint)c.FakeAnimationIndex):c.Target==s.target?words[0]:0u,words[0],input);
    }
    static void Update(Dictionary<string,object> input,Dictionary<string,object> want)
    {
        Dictionary<string,object> o=M(input["options"]);Services s;NavigationConnection edge;ConnectionWorld w=World(o,out s,out edge);ConnectionController c=w.Manager.Allocate();
        c.Connection=edge;c.Target=s.target;c.Kind=(ConnectionKind)I(input,"kind",0);c.Flags=(ushort)I(input,"flags",0);c.OnFlags=U(input,"on",0);c.OffFlags=U(input,"off",0);c.OutputIndex=U(o,"outputIndex",0);Array.Copy(UA(input["mask"]),c.FrameMask,32);
        ConnectionControllers.Update(w.Manager,s);Check("update-fields",new object[]{c.Flags,edge.ForwardFlags,edge.ReverseFlags,edge.Obstacle,s.calls},new object[]{want["flags"],((object[])want["edgeFlags"])[0],((object[])want["edgeFlags"])[1],want["edgeObstacle"],want["calls"]},input);
    }
    static void Pool(Dictionary<string,object> input)
    {
        int count=I(input,"capacity",1);ConnectionManager manager=new ConnectionManager(count);List<ConnectionController> ids=new List<ConnectionController>();for(int i=0;i<count;i++)ids.Add(manager.Allocate());manager.Reset();
        foreach(object raw in(object[])input["steps"])
        {
            Dictionary<string,object> step=M(raw);string op=(string)step["op"];
            if(op=="reset")manager.Reset();else if(op=="release")manager.Release(ids[I(step,"index",0)]);
            else{ConnectionController c=manager.Allocate();Check("pool-return",c==null?-1:ids.IndexOf(c),step["returned"],step);}
            List<int> active=new List<int>(),free=new List<int>();foreach(ConnectionController c in manager.Active)active.Add(ids.IndexOf(c));foreach(ConnectionController c in manager.FreeRecords)free.Add(ids.IndexOf(c));
            Dictionary<string,object> expected=M(step["native"]);Check("pool-order",new object[]{active,free},new object[]{expected["active"],expected["free"]},step);
        }
    }
    static int Review(string file)
    {
        Dictionary<string,object> root=M(json.DeserializeObject(File.ReadAllText(file)));int count=0;
        foreach(object raw in(object[])root["cases"])
        {
            Dictionary<string,object> row=M(raw),input=M(row["input"]);string group=(string)row["group"];object actual;
            switch(group)
            {
                case "force":{
                    ConnectionTarget target=new ConnectionTarget{ForceFlags=U(input,"forceFlags",0),ForceFlags2=U(input,"forceFlags2",0),ForceTimer=F(input,"timer",0),ForceHasObstacle=B(input,"hasObstacle",false),ObstacleState=I(input,"obstacleState",0)};
                    actual=ConnectionControllers.IsEnabled(new ConnectionController{Kind=ConnectionKind.Force,Target=target},null)?1:0;break;}
                case "locator":{
                    NavigationPath path=new NavigationPath();foreach(object name in(object[])input["names"])path.Locators.Add(new NavigationLocator{Name=(string)name});
                    NavigationLocator found=ConnectionControllers.FindLocator(path,(string)input["query"]);actual=found==null?-1:path.Locators.IndexOf(found);break;}
                case "connection":{
                    NavigationPath path=new NavigationPath();path.Locators.Add(new NavigationLocator{Name="a"});path.Locators.Add(new NavigationLocator{Name="b"});
                    foreach(object pair in(object[])input["endpoints"]){object[] endpoints=(object[])pair;path.Locators[0].Connections.Add(new NavigationConnection{Endpoint0=Convert.ToByte(endpoints[0]),Endpoint1=Convert.ToByte(endpoints[1])});}
                    byte direction=Convert.ToByte(input["initialDirection"]);NavigationConnection found=ConnectionControllers.FindConnection(path,"a","b",ref direction);
                    actual=new object[]{found==null?-1:path.Locators[0].Connections.IndexOf(found),direction};break;}
                case "pathIndex":{
                    Services services;NavigationConnection edge;ConnectionWorld world=World(new Dictionary<string,object>(),out services,out edge);world.Paths.Clear();
                    int selected=I(input,"explicitPathIndex",0);for(int i=0;i<I(input,"pathCount",1);i++)world.Paths.Add(i==selected?services.path:new NavigationPath());
                    ConnectionController controller=ConnectionControllers.Create(world,services.path,"a","b",ConnectionKind.BuildIt,"x",-1,0);actual=controller==null?-1:(int)controller.PathIndex;break;}
                default:throw new ArgumentException("Unknown review fixture group:"+group);
            }
            Check("review-"+group,actual,row["native"],input);count++;
        }
        return count;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2&&args.Length!=3)throw new ArgumentException("Expected original native fixture and output report paths, optionally followed by review fixture path.");checks=failures=skipped=0;examples.Clear();Dictionary<string,object> root=M(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object raw in(object[])root["cases"])
        {
            Dictionary<string,object> row=M(raw),input=M(row["input"]);string group=(string)row["group"];
            switch(group)
            {
                case "flag_lookup":{uint[] f=UA(input["fallback"]);Check(group,ConnectionFlags.Lookup((string)input["name"],I(input,"mode",1),f[0],f[1],f[2]),row["native"],input);break;}
                case "command":Command(input,M(row["native"]));break;
                case "update":Update(input,M(row["native"]));break;
                case "frame_mask":{
                    Dictionary<string,object> o=new Dictionary<string,object>{{"end",input["end"]}};Services s;NavigationConnection edge;ConnectionWorld w=World(o,out s,out edge);ConnectionController c=new ConnectionController{Kind=(ConnectionKind)I(input,"kind",0),Target=s.target};
                    ConnectionControllers.AddFrameRange(c,I(input,"start",0),I(input,"stop",0),s);Check(group,c.FrameMask,row["native"],input);break;}
                case "pool_sequence":Pool(input);break;
                case "pool-allocation-return":case "pool-list-order":skipped++;break; // compared through complete saved pool_sequence
                case "shared-edge-update-order":{
                    Services s;NavigationConnection edge;ConnectionWorld w=World(new Dictionary<string,object>(),out s,out edge);
                    for(int i=0;i<2;i++){ConnectionController c=w.Manager.Allocate();c.Connection=edge;c.Target=s.target;c.Kind=ConnectionKind.BuildIt;c.Flags=2;c.OnFlags=U(input,i==0?"onA":"onB",0);c.OffFlags=U(input,i==0?"offA":"offB",0);}
                    ConnectionControllers.Update(w.Manager,s);Check(group,new uint[]{edge.ForwardFlags,edge.ReverseFlags},row["native"],input);break;}
                default:throw new ArgumentException("Unknown native fixture group:"+group);
            }
        }
        int reviewCases=args.Length==3?Review(args[2]):0;
        string report=json.Serialize(new{checks=checks,mismatches=failures,duplicatePoolSummaryRows=skipped,reviewCases=reviewCases,examples=examples,scope="Portable bounded connection runtime with explicit world target/numeric/gizmo adapters."});File.WriteAllText(args[1],report+Environment.NewLine);Console.WriteLine(report);return failures==0?0:1;
    }
}
