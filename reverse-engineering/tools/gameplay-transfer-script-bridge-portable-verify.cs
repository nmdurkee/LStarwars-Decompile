using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayTransferScriptBridgeVerify
{
    static int checks,failures;static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static float Float(object v){return BitConverter.ToSingle(BitConverter.GetBytes(U(v)),0);}
    static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    static ActorStateRecord Actor(PlayerTransferWorld w,int i){return i<0?null:w.Tags.Actors.Actors[i];}
    static int Id(ActorStateRecord a){return a==null?-1:a.Id;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Check(object got,object want,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<15)errors.Add(new{index,got,want});}}
    class Services:PlayerTransferServices
    {
        readonly List<object> events;public Services(List<object> value){events=value;}
        public override void InitializeBaseScript(ActorStateRecord actor,object script,object state){events.Add(new object[]{"script",actor.Id,Int(script),U(state)});}
        public override void PlatformFeedback(uint handle,float duration){events.Add(new object[]{"feedback",handle,Bits(duration),0,0,0});}
    }
    class Fixture
    {
        public readonly PlayerTransferWorld World=new PlayerTransferWorld();
        public readonly PlayerTransferInput[] Inputs=new PlayerTransferInput[2];
        public readonly byte[][] Aux=new byte[2][];
        public readonly List<object> Events=new List<object>();
        public Fixture(Dictionary<string,object> c)
        {
            World.Tags=new TagControlWorld{Actors=new ActorStateWorld()};World.Services=new Services(Events);World.Tags.Services=new OrdinaryPlayerTransferAdapter(World);
            World.Blocked=Bool(c["blocked"]);World.SpecialLevel=Bool(c["specialLevel"]);World.DefaultMaximumHealth=(byte)Int(c["defaultMax"]);World.TransferTimeBits=U(c["transferTime"]);World.FeedbackDivisor=Convert.ToSingle(c["feedbackDivisor"]);
            for(int i=0;i<8;i++){ActorStateRecord actor=new ActorStateRecord{Id=i,Definition=new ActorStateDefinition()};actor.WorldObject=actor;World.Tags.Actors.Actors.Add(actor);World.Tags.State.Add(actor,new TagControlState());}
            object[] records=Arr(c["records"]),tagFlags=Arr(c["tagFlags"]);
            for(int i=0;i<2;i++)
            {
                Inputs[i]=new PlayerTransferInput{FeedbackHandle=U(Obj(records[i])["handle"])};Aux[i]=new byte[0x630];for(int j=0;j<Aux[i].Length;j++)Aux[i][j]=(byte)(0xa1+i);
            }
            for(int i=0;i<2;i++)
            {
                Dictionary<string,object> r=Obj(records[i]);ActorStateRecord actor=Actor(World,i);actor.Flags1f8=U(r["flags"]);actor.Flags1fc=U(r["active"]);actor.Definition.Flags=U(r["definitionFlags"]);
                int aux=Int(r["aux"]),script=Int(r["script"]);object[] v=Arr(r["words"]);
                PlayerTransferState s=new PlayerTransferState{Input=Inputs[Int(r["input"])],Auxiliary800=aux<0?null:Aux[aux],PersonalIndex=(sbyte)Int(r["index"]),MaximumHealth=(byte)Int(r["maximum"]),Health=(byte)Int(r["health"]),AlternateHealth=(byte)Int(r["alternate"]),TuningMaximumHealth=(byte)Int(r["tuningMax"]),BaseScript=script<0?null:(object)script,BaseState=script<0?null:Obj(records[script])["scriptState"],FieldDa8=U(v[0]),Field7fc=U(v[1]),FieldDec=U(v[2]),FieldEa8=U(v[3]),Field1000=U(v[4]),TimerD60=U(v[5]),TimerDa4=U(v[6]),FieldEe4=U(v[8]),FieldEe8=U(v[9]),ResetD80=U(v[11]),ResetD84=U(v[12]),ResetD14=U(v[13]),ResetD90=U(v[14]),ResetD18=U(v[15]),ResetD88=U(v[16]),ScriptCounter32c=U(v[17])};
                actor.ProtectionFlagsEf0=U(v[7]);World.State.Add(actor,s);TagControlState t=World.Tags.State[actor];t.Wait7c0=Float(v[10]);t.Flags7c5=(byte)Int(tagFlags[i]);t.LinkedCd0=Actor(World,Int(r["linked"]));t.Blocked28b=i==1?(byte)Int(c["targetBlocked"]):(byte)0;
            }
            object[] players=Arr(c["players"]);for(int i=0;i<8;i++)World.Tags.Actors.Players[i]=Actor(World,Int(players[i]));World.Tags.Actors.PrimaryPlayer=Actor(World,Int(c["primary"]));World.Tags.SecondaryPlayer=Actor(World,Int(c["secondary"]));World.PairFrom=Actor(World,Int(c["pairFrom"]));World.PairTo=Actor(World,Int(c["pairTo"]));object[] pair=Arr(c["pairWords"]);World.PairWord0=U(pair[0]);World.PairWord1=U(pair[1]);
        }
        public object Snapshot()
        {
            List<object> records=new List<object>(),hashes=new List<object>(),tags=new List<object>();int[] players=new int[8];for(int i=0;i<8;i++)players[i]=Id(World.Tags.Actors.Players[i]);
            for(int i=0;i<2;i++)
            {
                ActorStateRecord a=Actor(World,i);PlayerTransferState s=World.State[a];TagControlState t=World.Tags.State[a];tags.Add(t.Flags7c5);
                uint[] words={s.FieldDa8,s.Field7fc,s.FieldDec,s.FieldEa8,s.Field1000,s.TimerD60,s.TimerDa4,a.ProtectionFlagsEf0,s.FieldEe4,s.FieldEe8,Bits(t.Wait7c0),s.ResetD80,s.ResetD84,s.ResetD14,s.ResetD90,s.ResetD18,s.ResetD88,s.ScriptCounter32c};
                records.Add(new Dictionary<string,object>{{"flags",a.Flags1f8},{"active",a.Flags1fc},{"input",Array.IndexOf(Inputs,s.Input)},{"aux",s.Auxiliary800==null?-1:Array.IndexOf(Aux,s.Auxiliary800)},{"index",s.PersonalIndex},{"maximum",s.MaximumHealth},{"health",s.Health},{"words",words}});
                using(SHA256 sha=SHA256.Create())hashes.Add(BitConverter.ToString(sha.ComputeHash(Aux[i])).Replace("-","").ToLowerInvariant());
            }
            return new Dictionary<string,object>{{"records",records},{"players",players},{"pairFrom",Id(World.PairFrom)},{"pairTo",Id(World.PairTo)},{"pairWords",new uint[]{World.PairWord0,World.PairWord1}},{"auxiliaryHashes",hashes},{"primary",Id(World.Tags.Actors.PrimaryPlayer)},{"secondary",Id(World.Tags.SecondaryPlayer)},{"tagFlags",tags}};
        }
    }
    class Bridge:PlayerTransferScriptBridge
    {
        readonly List<object> events;public readonly ScriptDefinition[] Definitions=new ScriptDefinition[2];
        public readonly ScriptState[] States=new ScriptState[4];public readonly ScriptAction Action=new ScriptAction();
        readonly uint[] Addresses=new uint[4];
        public Bridge(List<object> log,bool action):base(new ScriptMachine(new ScriptEnvironment()))
        {
            events=log;
            for(int i=0;i<2;i++)
            {
                Definitions[i]=new ScriptDefinition();
                for(int j=0;j<4;j++)Definitions[i].Parameters[j]=i*10+j+.25f;
                for(int j=0;j<2;j++){States[i*2+j]=new ScriptState{Name=j==0?"Base":"Idle",FirstAction=action?Action:null};Definitions[i].States.Add(States[i*2+j]);Addresses[i*2+j]=0x10166000u+(uint)(i*0x100+j*0x40);}
                Definitions[i].IdleState=States[i*2+1];
            }
            Feedback=delegate(uint handle,float duration){events.Add(new object[]{"feedback",handle,Bits(duration),0,0,0});};
        }
        public override void InitializeBaseScript(ActorStateRecord actor,object script,object state)
        {events.Add(new object[]{"script",actor.Id,Array.IndexOf(Definitions,script),state==null?0u:Addresses[Array.IndexOf(States,state)]});base.InitializeBaseScript(actor,script,state);}
        public ScriptPacket Packet(Dictionary<string,object> before)
        {
            ScriptPacket p=new ScriptPacket{BaseScript=Definition(Int(before["base"])),Script=Definition(Int(before["script"])),State=State(Int(before["state"])),PendingState=State(Int(before["pending"])),Action=Int(before["action"])<0?null:Action,Timer=Float(before["timer"]),Flags=U(before["flags"]),BlockedMessages=(ushort)Int(before["blocked"]),DeadlineMarker=(byte)Int(before["marker"]),Deadline=Float(before["deadline"]),DeadlineState=State(Int(before["deadlineState"]))};
            object[] parameters=Arr(before["parameters"]);for(int i=0;i<4;i++)p.Parameters[i]=Float(parameters[i]);for(int i=0;i<Int(before["depth"]);i++)p.Stack.Add(new ScriptReference());return p;
        }
        ScriptDefinition Definition(int id){return id<0?null:Definitions[id];}
        ScriptState State(int id){return id<0?null:States[id];}
        public object Snapshot(ScriptPacket p)
        {
            uint[] parameters=new uint[4];for(int i=0;i<4;i++)parameters[i]=Bits(p.Parameters[i]);
            return new Dictionary<string,object>{{"base",Array.IndexOf(Definitions,p.BaseScript)},{"script",Array.IndexOf(Definitions,p.Script)},{"state",Array.IndexOf(States,p.State)},{"action",p.Action==null?-1:0},{"pending",Array.IndexOf(States,p.PendingState)},{"parameters",parameters},{"timer",Bits(p.Timer)},{"flags",p.Flags},{"depth",p.Stack.Count},{"blocked",p.BlockedMessages},{"marker",p.DeadlineMarker},{"deadline",Bits(p.Deadline)},{"deadlineState",Array.IndexOf(States,p.DeadlineState)}};
        }
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),c=Obj(v["context"]);Fixture f=new Fixture(c);Bridge bridge=new Bridge(f.Events,Bool(v["action"]));f.World.Services=bridge;
            ScriptPacket packet=bridge.Packet(Obj(v["scriptBefore"]));bridge.Packets.Add(Actor(f.World,0),packet);
            object[] records=Arr(c["records"]);
            for(int i=0;i<2;i++){int script=Int(Obj(records[i])["script"]);PlayerTransferState state=f.World.State[Actor(f.World,i)];state.BaseScript=script<0?null:bridge.Definitions[script];state.BaseState=script<0||!Bool(v["idle"])?null:bridge.States[script*2+1];}
            try
            {
                int result=(string)v["kind"]=="tag"?TagControls.SetTaggable(f.World.Tags,Actor(f.World,0),new string[]{"FALSE"},Bool(v["first"])):PlayerTransfer.Transfer(f.World,Actor(f.World,0),Actor(f.World,1));
                object transfer=new Dictionary<string,object>{{"result",result},{"state",f.Snapshot()},{"events",f.Events}};
                Check(new Dictionary<string,object>{{"transfer",transfer},{"script",bridge.Snapshot(packet)}},v["native"],index);
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}