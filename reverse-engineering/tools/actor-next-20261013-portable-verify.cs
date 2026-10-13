using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ActorNext20261013Verify
{
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static int I(Dictionary<string,object> d,string k){return Convert.ToInt32(d[k]);}
    static uint U(Dictionary<string,object> d,string k){return Convert.ToUInt32(d[k]);}
    static string[] Tokens(object a){object[] v=(object[])a;var r=new string[v.Length];for(int i=0;i<v.Length;i++)r[i]=(string)v[i];return r;}
    static int Flag(int i){return(i*997+0x55aa)&65535;}
    static SockTableProjection Table()
    {
        var t=new SockTableProjection();for(int i=0;i<64;i++)t.Records[i]=new SockRecordProjection{Present32=(byte)(i==0||i==7||i==8||i==63?1:0),Flags68=(ushort)Flag(i),NameE4=i==0?"Zero":i==7||i==8?"Door":i==63?"Final":"Unused"+i};return t;
    }
    static ScriptPacket Packet()
    {
        var p=new ScriptPacket();p.Script=new ScriptDefinition();p.Parameters[0]=5.75f;p.Parameters[1]=63.9f;p.Parameters[2]=-.75f;p.Parameters[3]=100f;
        string[] names={"slot","other","neg","large"};for(int i=0;i<4;i++)p.Script.ParameterNames[i]=names[i];return p;
    }
    sealed class Services:TagControlServices
    {
        public readonly List<object> Events;public readonly ActorStateRecord[] Actors;
        public Services(List<object> e,ActorStateRecord[] a){Events=e;Actors=a;}
        public override int Transfer(ActorStateRecord a,ActorStateRecord b,uint argument){throw new InvalidOperationException("Unexpected transfer.");}
        public override void Release(ActorStateRecord actor){Events.Add(new object[]{"release",Array.IndexOf(Actors,actor)});}
    }
    static object Run(string group,Dictionary<string,object> input)
    {
        bool authored=group.StartsWith("Authored-");if(authored)group=(string)input["command"];
        if(group=="CannotBeSeen")
        {
            var actor=new ActorStateRecord{ProtectionFlagsEf0=U(input,"flags")};var reference=I(input,"gate")==3?new ActorStateRecord{WorldObject=actor}:null;
            int result=ActorStateContinuationCommands.CannotBeSeen(reference,Tokens(input["tokens"]),I(input,"first")!=0);return new object[]{result,actor.ProtectionFlagsEf0};
        }
        if(group=="EnableSock")
        {
            SockTableProjection table=Convert.ToBoolean(input["table"])?Table():null;var events=new List<object>();
            // Native fixture observes final helper edge; selector observations
            // are additional source hooks and intentionally not compared here.
            Action<string,int> observe=delegate(string op,int ix){if(op=="enable"||op=="disable")events.Add(new object[]{op,ix});};
            bool first=I(input,"first")!=0;string[] tokens=Tokens(input["tokens"]);
            int result=ActorStateContinuationCommands.EnableSock(table,Packet(),tokens,first,observe);
            var flags=new int[64];for(int i=0;i<64;i++)flags[i]=table==null?Flag(i):table.Records[i].Flags68;
            return new object[]{result,flags,events};
        }
        if(group=="SockUnsignedIndex")
        {
            var table=Table();table.Records[0].Flags68=(ushort)I(input,"flags");table.Records[63].Flags68=(ushort)I(input,"flags");
            ActorStateContinuationCommands.SetSockEnabled(table,I(input,"index"),(string)input["address"]=="0x541430");var flags=new int[64];for(int i=0;i<64;i++)flags[i]=table.Records[i].Flags68;return flags;
        }
        var events2=new List<object>();var actors=new ActorStateRecord[]{new ActorStateRecord{Id=0},new ActorStateRecord{Id=1}};
        var refs=new ActorStateRecord[]{new ActorStateRecord{WorldObject=actors[0],Flags1fc=1,Definition=new ActorStateDefinition{Name="A"}},new ActorStateRecord{WorldObject=actors[1],Flags1fc=1,Definition=new ActorStateDefinition{Name="B"}}};
        if(I(input,"gate")==2)refs[0].WorldObject=null;
        var aw=new ActorStateWorld{NameCallback=I(input,"callback")!=0,ActiveCount=2};aw.Actors.Add(refs[0]);aw.Actors.Add(refs[1]);aw.Observe=delegate(string op,object v){if(op=="name")events2.Add(new object[]{"name",v});};
        var world=new TagControlWorld{Actors=aw,Services=new Services(events2,actors)};
        for(int i=0;i<2;i++)world.State[actors[i]]=new TagControlState{LinkedCd0=(I(input,"links")&(1<<i))!=0?actors[1-i]:null};
        ActorStateRecord initial=I(input,"gate")==3?refs[0]:null;
        int answer=ActorStateContinuationCommands.ReleaseTakeOver(world,initial,Tokens(input["tokens"]),I(input,"first")!=0);return new object[]{answer,events2};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("Fixture and output paths required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=M(json.DeserializeObject(File.ReadAllText(args[0])));int cases=0,failed=0;var errors=new List<object>();
        foreach(object item in(object[])data["vectors"])
        {
            var row=M(item);cases++;try{object actual=Run((string)row["group"],M(row["input"]));if(json.Serialize(actual)!=json.Serialize(row["native"])){failed++;if(errors.Count<12)errors.Add(new{group=row["group"],input=row["input"],actual=actual,native=row["native"]});}}catch(Exception e){failed++;if(errors.Count<12)errors.Add(new{group=row["group"],error=e.Message});}
        }
        File.WriteAllText(args[1],json.Serialize(new{cases=cases,failures=failed,examples=errors}));Console.WriteLine("Actor command comparisons:"+cases+", failures:"+failed);return failed==0?0:1;
    }
}
