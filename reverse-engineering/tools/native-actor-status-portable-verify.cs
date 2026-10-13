using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class ActorStatusVerify
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
    static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),c=Obj(v["context"]);List<object> events=new List<object>();ActorStateWorld actors=World(c,events);TagControlWorld tags=new TagControlWorld{Actors=actors};ActorStatusWorld world=new ActorStatusWorld{Tags=tags};object[] aa=Arr(c["actors"]);
            for(int i=0;i<aa.Length;i++)
            {
                Dictionary<string,object> a=Obj(aa[i]),s=Obj(a["status"]);ActorStateRecord actor=actors.Actors[i];actor.WeaponFlagsEec=U(Arr(a["state"])[2]);
                tags.State.Add(actor,new TagControlState{LinkedCd0=Actor(actors,Int(s["linked"]))});
                world.State.Add(actor,new ActorStatusState{OpponentReference=Actor(actors,Int(s["opponent"])),TakeoverTarget=Actor(actors,Int(s["takeover"])),State7b5=(byte)Int(s["state7b5"]),Ground281=(byte)Int(s["ground281"]),Ground282=(byte)Int(s["ground282"]),HitTimer1018=Convert.ToSingle(s["hitTimer"])});
            }
            try
            {
                ActorStateRecord reference=Bool(c["creature"])?Actor(actors,Int(c["reference"])):null,bound=Actor(actors,Int(v["bound"]));string kind=(string)v["kind"],operand=(string)v["operand"];object result;
                if(kind=="bindHit")result=Id(ActorStatusConditions.BindBeenHit(actors,operand));
                else if(kind=="bindTaken")result=Id(ActorStatusConditions.BindTakenOver(actors,operand));
                else if(kind=="BeenHit")result=Bits(ActorStatusConditions.BeenHit(world,reference,bound));
                else if(kind=="TakenOver")result=Bits(ActorStatusConditions.TakenOver(world,reference,operand,bound));
                else if(kind=="HasTakeOverTarget")result=Bits(ActorStatusConditions.HasTakeOverTarget(world,reference));
                else result=Bits(ActorStatusConditions.PlayerOnGround(world));
                object got=new Dictionary<string,object>{{"result",result},{"events",events}};
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
