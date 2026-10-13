using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

// Arguments: native fixture JSON, output JSON. Compile-only until managed
// execution is available through the ordinary supported Windows launch path.
public class GameplayActivationVerify
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
    class Services:ActorActivationServices
    {
        public ActorActivationWorld World;public Dictionary<string,object> Options;public List<object> Events;
        public override void Reinitialize(ActorStateRecord actor,bool system){Events.Add(new object[]{"reinitialize",actor.Id,system});if(Options.ContainsKey("reinitializeGroup"))World.Fields[actor].Packet.SetId=(byte)Int(Options["reinitializeGroup"]);}
        public override void DestroyAttachment(ActorStateRecord actor,int mode,uint flags){Events.Add(new object[]{"destroyAttachment",actor.Id,mode,flags});}
        public override void ReleaseControl(ActorStateRecord actor,bool deactivate){Events.Add(new object[]{"releaseControl",actor.Id,deactivate?1:0});}
    }
    class Fixture
    {
        public ActorActivationWorld Activation;public readonly List<object> Events=new List<object>();
        public readonly ScriptDefinition[] Scripts={new ScriptDefinition(),new ScriptDefinition()};
        public readonly ScriptState[] States=new ScriptState[6];
        public readonly ScriptAction FirstAction=new ScriptAction(),OldAction=new ScriptAction();
        public Fixture(Dictionary<string,object> o,string[] typeNames)
        {
            ActorStateWorld actors=World(o,typeNames,Events);Activation=new ActorActivationWorld{Actors=actors,Machine=new ScriptMachine(new ScriptEnvironment()),SpawnPhase87=new byte[8]};
            Activation.Services=new Services{World=Activation,Options=o,Events=Events};Activation.ObserveStateChange=delegate(ActorStateRecord actor,string name){Events.Add(new object[]{"state",actor.Id,name});};
            string[] stateNames={"Base","InActive","Other"};string[] missing=o.ContainsKey("missingStates")?Strings(o["missingStates"]):new string[0];
            for(int sc=0;sc<2;sc++)
            {
                for(int k=0;k<4;k++)Scripts[sc].Parameters[k]=sc*10+k+.25f;
                for(int k=0;k<3;k++){string name=stateNames[k];foreach(string absent in missing)if(name==absent)name="Hidden"+name;States[sc*3+k]=new ScriptState{Name=name,FirstAction=Opt(o,"withAction",false)?FirstAction:null};Scripts[sc].States.Add(States[sc*3+k]);}
            }
            int[] groups={0,1,2,3,16,2,1,255};
            for(int i=0;i<8;i++)
            {
                int kind=o.ContainsKey("scriptKinds")?Int(Arr(o["scriptKinds"])[i]):1,sc=kind==0?0:1;ScriptPacket packet=new ScriptPacket{BaseScript=Scripts[0],Script=kind==2?null:Scripts[sc],State=States[sc*3+2],Action=OldAction,PendingState=States[sc*3+1],Timer=3.5f,Flags=Opt(o,"scriptFlags",0x24u),SetId=(byte)(o.ContainsKey("groups")?Int(Arr(o["groups"])[i]):groups[i]),BlockedMessages=0x7654,DeadlineMarker=7,Deadline=8,DeadlineState=States[sc*3+1]};
                for(int j=0;j<4;j++)packet.Parameters[j]=9-j;for(int j=0;j<3;j++)packet.Stack.Add(new ScriptReference());
                Activation.Fields.Add(actors.Actors[i],new ActivationActorFields{Packet=packet,Phase406=9,DeadlineB5=9,DeadlineC0=0x13572468,AttachedCd0=o.ContainsKey("attached")?Actor(actors,Int(Arr(o["attached"])[i])):null});Activation.SpawnPhase87[i]=5;
            }
            for(int i=0;i<17;i++)Activation.GroupCounts[i]=(byte)(o.ContainsKey("counts")?Int(Arr(o["counts"])[i]):(254+i)&255);
        }
        int StateId(ScriptState s){return s==null?-1:Array.IndexOf(States,s);}
        static uint Bits(float value){return BitConverter.ToUInt32(BitConverter.GetBytes(value),0);}
        public Dictionary<string,object> Snapshot()
        {
            List<object> rows=new List<object>();foreach(ActorStateRecord actor in Activation.Actors.Actors)
            {
                ActivationActorFields fields=Activation.Fields[actor];ScriptPacket p=fields.Packet;uint[] parameters=new uint[4];for(int i=0;i<4;i++)parameters[i]=Bits(p.Parameters[i]);
                rows.Add(new Dictionary<string,object>{{"active",actor.Flags1fc},{"group",p.SetId},{"phase",fields.Phase406},{"script",p.Script==null?-1:Object.ReferenceEquals(p.Script,Scripts[0])?0:1},{"state",StateId(p.State)},{"action",p.Action==null?-1:Object.ReferenceEquals(p.Action,FirstAction)?0:1},{"pending",StateId(p.PendingState)},{"parameters",parameters},{"flags",p.Flags},{"depth",p.Stack.Count},{"blocked",p.BlockedMessages},{"deadline",Bits(p.Deadline)},{"deadlineState",StateId(p.DeadlineState)},{"deadlineMarker",p.DeadlineMarker},{"conditionBank38",fields.ConditionBank38},{"deadlineB5",fields.DeadlineB5},{"deadlineC0",fields.DeadlineC0}});
            }
            return new Dictionary<string,object>{{"actors",rows.ToArray()},{"counts",Activation.GroupCounts.Clone()},{"spawnPhase",Activation.SpawnPhase87.Clone()}};
        }
        public object Delta(Dictionary<string,object> before)
        {
            Dictionary<string,object> after=Snapshot(),result=new Dictionary<string,object>();foreach(string kind in new string[]{"actors","counts","spawnPhase"})
            {
                IList a=(IList)before[kind],b=(IList)after[kind];List<object> values=new List<object>();for(int i=0;i<b.Count;i++)
                {
                    if(Equal(a[i],b[i]))continue;
                    if(kind=="actors"){Dictionary<string,object> change=new Dictionary<string,object>();foreach(var pair in Obj(b[i]))if(!Equal(Obj(a[i])[pair.Key],pair.Value))change.Add(pair.Key,pair.Value);values.Add(new object[]{i,change});}
                    else values.Add(new object[]{i,b[i]});
                }
                result.Add(kind,values);
            }
            return result;
        }
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));string[] typeNames=Strings(data["typeNames"]);int index=0;
        foreach(string kind in new string[]{"commands","helpers"})foreach(object row in Arr(data[kind]))try
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);Fixture fixture=new Fixture(o,typeNames);ActorActivationWorld w=fixture.Activation;Dictionary<string,object> before=fixture.Snapshot();object result;
            if(kind=="commands")
            {
                ScriptPacket numbers=new ScriptPacket{Script=new ScriptDefinition()};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){numbers.Script.ParameterNames[i]=names[i];numbers.Parameters[i]=values[i];}
                ActorStateRecord reference=Opt(o,"creature",true)?Actor(w.Actors,Opt(o,"reference",0)):null;string[] tokens=Strings(v["tokens"]);bool first=Convert.ToBoolean(v["first"]);
                result=(string)v["command"]=="Activate"?ActorActivation.Activate(w,numbers,reference,tokens,first):ActorActivation.DeActivate(w,numbers,reference,tokens,first);
            }
            else
            {
                int id=Int(v["index"]);ActorStateRecord actor=Actor(w.Actors,id);
                if((string)v["kind"]=="baseState")
                {
                    string name=(string)v["name"];fixture.Events.Add(new object[]{"state",id,name});ActivationActorFields fields=actor==null?null:w.Fields[actor];result=ActorActivation.ChangeBaseState(w.Machine,fields==null?null:fields.Packet,name,fields)?1:0;
                }
                else{ActorActivation.DeactivateActor(w,actor);result=null;}
            }
            Check(new Dictionary<string,object>{{"result",result},{"delta",fixture.Delta(before)},{"events",fixture.Events}},v["native"],index++);
        }
        catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});++index;}
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
