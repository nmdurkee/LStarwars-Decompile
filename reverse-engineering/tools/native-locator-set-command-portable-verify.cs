using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class LocatorSetCommandVerify
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
    static float[] Floats(object v){if(v==null)return null;object[] a=Arr(v);float[] f=new float[a.Length];for(int i=0;i<a.Length;i++)f[i]=Convert.ToSingle(a[i]);return f;}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]),c=Obj(v["context"]);List<object> events=new List<object>();ActorStateWorld w=World(c,events);
            LocatorReservationWorld world=new LocatorReservationWorld{Actors=w,IndexCallback=!o.ContainsKey("indexCallback")||Bool(o["indexCallback"])};object[] aa=Arr(c["actors"]);
            for(int i=0;i<aa.Length;i++){Dictionary<string,object> a=Obj(aa[i]);float[] pos=Floats(a["position"]);w.Actors[i].X=pos[0];w.Actors[i].Y=pos[1];w.Actors[i].Z=pos[2];world.Views.Add(w.Actors[i],new LocatorReservationActor{Actor=w.Actors[i],PacketPresent=Bool(a["packet"]),SelectedLocatorIndex=a["selected"]==null?(int?)null:Int(a["selected"]),ReservationToken=U(a["token"]),State406=(byte)Int(a["state406"]),DeathState=(byte)Int(a["deathState"]),DeathTimer=Convert.ToSingle(a["deathTimer"]),OwnerId=(byte)Int(a["ownerId"])});}
            object[] ix=Arr(v["indices"]),ow=Arr(v["owners"]);LocatorReservationSet set=new LocatorReservationSet{Count=(sbyte)(o.ContainsKey("setCount")?Int(o["setCount"]):8),Indices=new byte[ix.Length],Owners=new byte[ow.Length]};for(int i=0;i<ix.Length;i++)set.Indices[i]=(byte)Int(ix[i]);for(int i=0;i<ow.Length;i++)set.Owners[i]=(byte)Int(ow[i]);
            object[] pp=Arr(o["positions"]);float[][] positions=new float[pp.Length][];for(int i=0;i<pp.Length;i++)positions[i]=Floats(pp[i]);
            LocatorSelectionContext context=new LocatorSelectionContext{Reservations=world,Positions=positions,View=new LocatorView{ViewMatrix=Floats(o["view"]),PlaneMatrix=Floats(o["planes"]),Near=Convert.ToSingle(o["near"]),Far=Convert.ToSingle(o["far"])},ObjectMatrix=Floats(o["object"]),Random=new ScriptRandom{State=U(o["random"])}};
            try
            {
                LocatorSetCommandWorld command=new LocatorSetCommandWorld{Selection=context,GlobalSetSystemPresent=!o.ContainsKey("globalSetSystem")||Bool(o["globalSetSystem"]),PrimaryPlayer=w.PrimaryPlayer,SecondaryPlayer=Actor(w,o.ContainsKey("secondaryPlayer")?Int(o["secondaryPlayer"]):2),Random=new QRandom{State=o.ContainsKey("qrandom")?U(o["qrandom"]):12345}};
                foreach(object name in Arr(v["names"]))command.Sets.Add(new NamedLocatorReservationSet{Name=(string)name,Set=set});command.SetCount=o.ContainsKey("collectionCount")?Int(o["collectionCount"]):command.Sets.Count;
                object[] opponents=o.ContainsKey("opponents")?Arr(o["opponents"]):null;for(int i=0;i<8;i++)command.Opponents.Add(w.Actors[i],Actor(w,opponents==null?3:Int(opponents[i])));
                ScriptPacket numbers=new ScriptPacket{Script=new ScriptDefinition()};string[] paramNames={"alpha","beta","gamma","delta"};float[] parameters={2.75f,1.5f,3,4};for(int i=0;i<4;i++){numbers.Script.ParameterNames[i]=paramNames[i];numbers.Parameters[i]=parameters[i];}
                object[] raw=Arr(v["tokens"]);string[] tokens=new string[raw.Length];for(int i=0;i<raw.Length;i++)tokens[i]=(string)raw[i];
                int result=LocatorSetCommands.Get(command,numbers,o.ContainsKey("currentSet")&&!Bool(o["currentSet"])?null:set,Bool(c["creature"])?Actor(w,Int(c["reference"])):null,tokens,Bool(v["first"]));
                List<object> selected=new List<object>(),flags=new List<object>();foreach(ActorStateRecord actor in w.Actors){selected.Add(world.View(actor).SelectedLocatorIndex);flags.Add(actor.Flags1fc);}
                object got=new Dictionary<string,object>{{"result",result},{"selected",selected},{"owners",set.Owners},{"flags",flags},{"random",context.Random.State},{"qrandom",command.Random.State},{"events",events}};
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
