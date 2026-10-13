using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class PartyControlVerify
{
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static bool Has(Dictionary<string,object> o,string key){return o.ContainsKey(key)&&Bool(o[key]);}
    static ActorStateRecord Actor(ActorStateWorld w,int id){return id<0?null:w.Actors[id];}
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
    static ActorStateWorld World(Dictionary<string,object> c,List<object> events)
    {
        ActorStateWorld w=new ActorStateWorld{SystemPresent=Bool(c["system"]),NameCallback=Bool(c["callback"]),ActiveCount=Int(c["count"])};
        w.Observe=delegate(string k,object value){events.Add(new object[]{k,value});};
        foreach(object row in Arr(c["definitions"])) {Dictionary<string,object> d=Obj(row);w.Definitions.Add(new ActorStateDefinition{Name=(string)d["name"],Flags=U(d["flags"])});}
        object[] aa=Arr(c["actors"]);
        for(int i=0;i<aa.Length;i++)
        {
            Dictionary<string,object> a=Obj(aa[i]);object[] s=Arr(a["state"]);
            w.Actors.Add(new ActorStateRecord{Id=i,Definition=w.Definitions[Int(a["definition"])],SpawnIndex=(byte)Int(a["spawn"]),Flags1f8=U(s[0]),Flags1fc=U(s[1])});
            w.Spawns.Add(new ActorStateSpawn{Name=(string)a["spawnName"],DefinitionIndex=(short)Int(a["spawnDefinition"])});
        }
        for(int i=0;i<aa.Length;i++)w.Actors[i].WorldObject=Actor(w,Int(Obj(aa[i])["world"]));
        w.PrimaryPlayer=Actor(w,Int(c["primary"]));object[] players=Arr(c["players"]);for(int i=0;i<8;i++)w.Players[i]=Actor(w,Int(players[i]));return w;
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),c=Obj(v["context"]);List<object> events=new List<object>();ActorStateWorld actors=World(c,events);
            TagControlWorld tags=new TagControlWorld{Actors=actors};AiOverrideWorld world=new AiOverrideWorld{Tags=tags};AiOverridePacket packet=new AiOverridePacket{CachedReference=Actor(actors,Int(v["initialCached"]))};
            object[] aa=Arr(c["actors"]);
            for(int i=0;i<aa.Length;i++)
            {
                Dictionary<string,object> a=Obj(aa[i]),life=Obj(a["life"]);object[] state=Arr(a["state"]);ActorStateRecord actor=actors.Actors[i];actor.WeaponFlagsEec=U(state[2]);actor.ProtectionFlagsEf0=U(state[3]);
                tags.State.Add(actor,new TagControlState{Blocked28b=(byte)Int(life["blocked"]),LinkedCd0=Actor(actors,Int(life["linked"]))});
                world.State.Add(actor,new AiOverrideState{Field1008=U(life["field1008"]),Timer1010=U(life["timer1010"]),Source107e=(byte)Int(life["source107e"]),Copy107f=(byte)Int(life["copy107f"]),StateE38=(byte)Int(life["stateE38"]),StateE39=(byte)Int(life["stateE39"]),DefaultE38=(byte)Int(life["defaultE38"])});
            }
            foreach(object rawTick in Arr(v["ticks"]))
            {
                Dictionary<string,object> tick=Obj(rawTick);events.Clear();object[] raw=Arr(tick["tokens"]);string[] tokens=new string[raw.Length];for(int i=0;i<raw.Length;i++)tokens[i]=(string)raw[i];
                try
                {
                    ActorStateRecord reference=Bool(c["creature"])?Actor(actors,Int(c["reference"])):null;int result;string command=(string)v["command"];bool first=Bool(tick["first"]);
                    if(command=="CannotDropIn")result=PartyControlCommands.CannotDropIn(actors,reference,tokens,first);
                    else if(command=="NotWithParty")result=PartyControlCommands.NotWithParty(actors,reference,tokens,first);
                    else result=PartyControlCommands.SetAIOverrideControl(world,packet,reference,tokens,first);
                    List<object> state=new List<object>();foreach(ActorStateRecord actor in actors.Actors){AiOverrideState life=world.State[actor];state.Add(new Dictionary<string,object>{{"flags1fc",actor.Flags1fc},{"eec",actor.WeaponFlagsEec},{"ef0",actor.ProtectionFlagsEf0},{"field1008",life.Field1008},{"timer1010",life.Timer1010},{"source107e",life.Source107e},{"copy107f",life.Copy107f},{"stateE38",life.StateE38},{"stateE39",life.StateE39},{"blocked",tags.State[actor].Blocked28b}});}
                    object got=new Dictionary<string,object>{{"result",result},{"cached",Id(packet.CachedReference)},{"state",state},{"events",events}};
                    ++checks;if(!Equal(got,tick["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=tick["native"]});}
                }
                catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
            }
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
