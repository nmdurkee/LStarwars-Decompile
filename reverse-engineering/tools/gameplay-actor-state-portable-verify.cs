using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

// Arguments: native fixture JSON, output JSON. Compile-only until managed
// execution is available through the ordinary supported Windows launch path.
public class GameplayActorStateVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static string[] Strings(object v){object[] a=Arr(v);string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
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
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?Int(o[k]):d;}
    static uint Opt(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?U(o[k]):d;}
    static bool Opt(Dictionary<string,object> o,string k,bool d){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):d;}
    static int Id(ActorStateRecord a){return a==null?-1:a.Id;}
    static ActorStateRecord Actor(ActorStateWorld w,int id){return id<0?null:w.Actors[id];}
    static void State(ActorStateRecord a,uint[] v)
    {a.Flags1f8=v[0];a.Flags1fc=v[1];a.WeaponFlagsEec=v[2];a.ProtectionFlagsEf0=v[3];a.Flags4b0=v[4];a.Membership4bc=v[5];a.OpponentEc0=v[6];a.OpponentEc4=v[7];a.Opponent3ac=v[8];}
    static object Snapshot(ActorStateWorld w)
    {
        List<object> values=new List<object>();
        foreach(ActorStateRecord a in w.Actors)values.Add(new uint[]{a.Flags1f8,a.Flags1fc,a.WeaponFlagsEec,a.ProtectionFlagsEf0,a.Flags4b0,a.Membership4bc,a.OpponentEc0,a.OpponentEc4,a.Opponent3ac});
        return values;
    }
    static ActorStateWorld World(Dictionary<string,object> o,string[] names,List<object> events)
    {
        ActorStateWorld w=new ActorStateWorld{SystemPresent=Opt(o,"system",true),NameCallback=Opt(o,"callback",true),TypeNameCallback=Opt(o,"typeNameCallback",true),TypeIndexCallback=Opt(o,"typeIndexCallback",true),ActiveCount=Opt(o,"count",8),GoodMask=Opt(o,"goodMask",0x4000000u),BadMask=Opt(o,"badMask",0x8000000u)};
        w.Observe=delegate(string k,object v){events.Add(new object[]{k,v});};
        for(int i=0;i<names.Length;i++)w.Definitions.Add(new ActorStateDefinition{Name=names[i],Flags=new uint[]{0,4,0x200,0x204}[i%4]});
        if(Opt(o,"table",true))
        {
            w.TypeTable=new short[256];for(int i=0;i<256;i++)w.TypeTable[i]=(short)(i<13?i:-1);w.TypeTable[64]=8;
            if(o.ContainsKey("tableEntries")){object[] v=Arr(o["tableEntries"]);for(int i=0;i<v.Length;i++)w.TypeTable[i]=(short)Int(v[i]);}
        }
        int[] references=new int[8];
        Dictionary<string,object> overrides=o.ContainsKey("actorOverrides")?Obj(o["actorOverrides"]):new Dictionary<string,object>();
        for(int i=0;i<8;i++)
        {
            Dictionary<string,object> a=overrides.ContainsKey(i.ToString())?Obj(overrides[i.ToString()]):new Dictionary<string,object>();
            ActorStateRecord r=new ActorStateRecord{Id=i,Definition=w.Definitions[Opt(a,"definition",i)],Type=(short)Opt(a,"type",i),SpawnIndex=(byte)Opt(a,"spawn",i),X=i,Y=i%2,Z=i%3};
            uint[] state=new uint[]{0x400u|new uint[]{0,1,4,0x10000}[i%4],0x1001,0xa5a5a5a5,0x11401022,0xa5a50800,0x5a5a5a5a,0x100u+(uint)i,0x200u+(uint)i,0x300u+(uint)i};
            if(a.ContainsKey("state")){object[] v=Arr(a["state"]);for(int j=0;j<v.Length;j++)state[j]=U(v[j]);}
            state[0]=Opt(a,"flags",state[0]);state[1]=Opt(a,"active",state[1]);State(r,state);
            if(a.ContainsKey("position")){object[] p=Arr(a["position"]);r.X=Convert.ToSingle(p[0]);r.Y=Convert.ToSingle(p[1]);r.Z=Convert.ToSingle(p[2]);}
            references[i]=Opt(a,"world",i);w.Actors.Add(r);w.Spawns.Add(new ActorStateSpawn{Name=a.ContainsKey("spawnName")?(string)a["spawnName"]:i==1?"order66":"spawn"+i,DefinitionIndex=(short)Opt(a,"spawnDefinition",i)});
        }
        for(int i=0;i<8;i++)w.Actors[i].WorldObject=Actor(w,references[i]);
        w.PrimaryPlayer=Actor(w,Opt(o,"primary",1));int[] players={1,2,3,-1,-1,-1,-1,7};
        if(o.ContainsKey("players")){object[] p=Arr(o["players"]);for(int i=0;i<8;i++)players[i]=Int(p[i]);}
        for(int i=0;i<8;i++)w.Players[i]=Actor(w,players[i]);return w;
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));string[] names=Strings(data["typeNames"]);int index=0;
        foreach(object row in Arr(data["commands"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);List<object> events=new List<object>();ActorStateWorld w=World(o,names,events);ActorStateRecord reference=Opt(o,"creature",true)?Actor(w,Opt(o,"reference",0)):null;string[] tokens=Strings(v["tokens"]);bool first=Convert.ToBoolean(v["first"]);
            ScriptPacket packet=new ScriptPacket{Script=new ScriptDefinition()};string[] pn={"alpha","beta","gamma","delta"};float[] pv={2.75f,1.5f,3,4};for(int i=0;i<4;i++){packet.Script.ParameterNames[i]=pn[i];packet.Parameters[i]=pv[i];}
            try
            {
                int result;switch((string)v["command"])
                {case "DontPush":result=ActorStateCommands.DontPush(w,reference,tokens,first);break;case "SetInvulnerable":result=ActorStateCommands.SetInvulnerable(w,reference,tokens,first);break;case "KeepWeaponOut":result=ActorStateCommands.KeepWeaponOut(w,reference,tokens,first);break;case "SetSide":result=ActorStateCommands.SetSide(w,packet,reference,tokens,first);break;default:throw new ArgumentException("command");}
                Check(new Dictionary<string,object>{{"result",result},{"state",Snapshot(w)},{"events",events}},v["native"],index);
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        foreach(object row in Arr(data["helpers"]))
        {
            Dictionary<string,object> v=Obj(row);List<object> events=new List<object>();ActorStateWorld w=World(Obj(v["options"]),names,events);
            try
            {
                int result;switch((string)v["kind"])
                {case "name":result=Id(w.FindReference((string)v["name"]));break;case "object":result=Id(w.ResolveObject((string)v["name"]));break;case "type":result=w.FindTypeIndex((string)v["name"]);break;default:result=w.ResolveTypeIndex((byte)Int(v["name"]));break;}
                Check(result,v["native"],index);
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
