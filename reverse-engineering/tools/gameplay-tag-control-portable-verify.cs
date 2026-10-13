using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayTagControlVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static float Float(object v){return BitConverter.ToSingle(BitConverter.GetBytes(U(v)),0);}
    static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?Int(o[k]):d;}
    static uint Opt(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?U(o[k]):d;}
    static bool Opt(Dictionary<string,object> o,string k,bool d){return o.ContainsKey(k)?Bool(o[k]):d;}
    static ActorStateRecord Actor(TagControlWorld w,int id){return id<0?null:w.Actors.Actors[id];}
    static int Id(ActorStateRecord a){return a==null?-1:a.Id;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;
        IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Check(object got,object want,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<15)errors.Add(new{index,got,want});}}
    class Services:TagControlServices
    {
        readonly Dictionary<string,object> o;readonly List<object> events;
        public Services(Dictionary<string,object> options,List<object> log){o=options;events=log;}
        public override int Transfer(ActorStateRecord from,ActorStateRecord to,uint argument)
        {events.Add(new object[]{"transfer",from.Id,to.Id,0,0,argument});if(Opt(o,"mutateTransfer",false)){from.Flags1fc^=0x1080;to.Flags1fc^=0x1080;}return Opt(o,"transferResult",1);}
        public override void Release(ActorStateRecord actor)
        {events.Add(new object[]{"release",actor.Id});if(Opt(o,"mutateRelease",false))actor.Flags1fc^=0x80;}
    }
    static TagControlWorld World(Dictionary<string,object> c,Dictionary<string,object> o,List<object> events)
    {
        ActorStateWorld actors=new ActorStateWorld{SystemPresent=Bool(c["system"]),NameCallback=Bool(c["callback"]),TypeNameCallback=Bool(c["typeNameCallback"]),TypeIndexCallback=Bool(c["typeIndexCallback"]),ActiveCount=Int(c["count"]),GoodMask=U(c["goodMask"]),BadMask=U(c["badMask"])};
        actors.Observe=delegate(string key,object value){events.Add(new object[]{key,value});};
        TagControlWorld w=new TagControlWorld{Actors=actors,Services=new Services(o,events)};
        foreach(object row in Arr(c["definitions"])) {Dictionary<string,object> d=Obj(row);actors.Definitions.Add(new ActorStateDefinition{Name=(string)d["name"],Flags=U(d["flags"])});}
        if(Bool(c["table"])){object[] t=Arr(c["typeTable"]);actors.TypeTable=new short[t.Length];for(int i=0;i<t.Length;i++)actors.TypeTable[i]=(short)Int(t[i]);}
        object[] aa=Arr(c["actors"]),tt=Arr(c["tags"]);
        for(int i=0;i<aa.Length;i++)
        {
            Dictionary<string,object> a=Obj(aa[i]);object[] s=Arr(a["state"]),p=Arr(a["position"]);
            ActorStateRecord r=new ActorStateRecord{Id=i,Definition=actors.Definitions[Int(a["definition"])],Type=(short)Int(a["type"]),SpawnIndex=(byte)Int(a["spawn"]),X=Convert.ToSingle(p[0]),Y=Convert.ToSingle(p[1]),Z=Convert.ToSingle(p[2]),Flags1f8=U(s[0]),Flags1fc=U(s[1]),WeaponFlagsEec=U(s[2]),ProtectionFlagsEf0=U(s[3]),Flags4b0=U(s[4]),Membership4bc=U(s[5]),OpponentEc0=U(s[6]),OpponentEc4=U(s[7]),Opponent3ac=U(s[8])};
            actors.Actors.Add(r);actors.Spawns.Add(new ActorStateSpawn{Name=(string)a["spawnName"],DefinitionIndex=(short)Int(a["spawnDefinition"])});
        }
        for(int i=0;i<aa.Length;i++)
        {
            actors.Actors[i].WorldObject=Actor(w,Int(Obj(aa[i])["world"]));Dictionary<string,object> t=Obj(tt[i]);
            w.State.Add(actors.Actors[i],new TagControlState{Flags7c5=(byte)Int(t["flags"]),Blocked28b=(byte)Int(t["blocked"]),LinkedCd0=Actor(w,Int(t["linked"])),Pending7c8=Actor(w,Int(t["target"])),Wait7c0=Float(t["wait"])});
        }
        actors.PrimaryPlayer=Actor(w,Int(c["primary"]));w.SecondaryPlayer=Actor(w,Int(c["secondary"]));object[] players=Arr(c["players"]);for(int i=0;i<8;i++)actors.Players[i]=Actor(w,Int(players[i]));return w;
    }
    static object Snapshot(TagControlWorld w)
    {
        List<object> state=new List<object>();foreach(ActorStateRecord a in w.Actors.Actors){TagControlState t=w.State[a];state.Add(new object[]{a.Flags1fc,t.Flags7c5,Bits(t.Wait7c0),Id(t.Pending7c8)});}
        return new Dictionary<string,object>{{"primary",Id(w.Actors.PrimaryPlayer)},{"secondary",Id(w.SecondaryPlayer)},{"actors",state}};
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]),c=Obj(v["context"]);List<object> events=new List<object>();TagControlWorld w=World(c,o,events);
            try
            {
                object result;string kind=(string)v["kind"];
                if(kind=="refresh"){w.RefreshPlayers();result=null;}
                else if(kind=="candidate")result=TagControls.TryTransfer(w,Actor(w,Opt(o,"own",0)),Actor(w,Int(v["target"])),Opt(o,"transferArgument",0u));
                else
                {object[] ts=Arr(v["tokens"]);string[] tokens=new string[ts.Length];for(int i=0;i<ts.Length;i++)tokens[i]=(string)ts[i];result=TagControls.SetTaggable(w,Bool(c["creature"])?Actor(w,Int(c["reference"])):null,tokens,Bool(v["first"]));}
                Check(new Dictionary<string,object>{{"result",result},{"state",Snapshot(w)},{"events",events}},v["native"],index);
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
