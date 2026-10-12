using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayCompactConditionVerify
{
    static int checks,failures;
    static readonly List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object value){return (Dictionary<string,object>)value;}
    static object[] Arr(object value){return (object[])value;}
    static uint UInt(object value){return Convert.ToUInt32(value);}
    static int Selector(object value){return unchecked((int)Convert.ToInt64(value));}
    static uint Bits(float value){return BitConverter.ToUInt32(BitConverter.GetBytes(value),0);}
    static float FromBits(object value){return BitConverter.ToSingle(BitConverter.GetBytes(UInt(value)),0);}
    static void Check(string kind,object got,object want,object input)
    {
        ++checks;if(!Object.Equals(got,want)){++failures;if(errors.Count<20)errors.Add(new{kind,got,want,input});}
    }
    static bool Compare(float a,float b,string op)
    {
        switch(op){case "==":return a==b;case "!=":return a!=b;case "<":return a<b;case ">":return a>b;case "<=":return a<=b;case ">=":return a>=b;default:throw new InvalidOperationException(op);}
    }
    static void Run(Dictionary<string,object> input)
    {
        string name=(string)input["command"];Dictionary<string,object> c=Obj(input["context"]);
        ConditionObject own=new ConditionObject{OffScreenTimer=FromBits(c["offscreenBits"])};
        ConditionObject bound=new ConditionObject{OffScreenTimer=FromBits(c["boundTimeBits"])};
        ConditionCreature creature=Convert.ToBoolean(c["creature"])?new ConditionCreature{HasOpponentReference=Convert.ToBoolean(c["opponent"]),OpponentRange=FromBits(c["distanceBits"]),ActorReference=Convert.ToBoolean(c["actor"])?new ConditionActorReference{Object=Convert.ToBoolean(c["actorObject"])?own:null}:null}:null;
        int seed=Convert.ToInt32(c["countSeed"]);Dictionary<string,object> countOverride=input.ContainsKey("countOverride")?Obj(input["countOverride"]):null;
        ConditionWorld world=new ConditionWorld{FreePlayValue=Convert.ToInt32(c["freePlay"]),ReadAliveCount=delegate(byte i){return countOverride!=null&&Convert.ToInt32(countOverride["index"])==i?(byte)Convert.ToInt32(countOverride["value"]):(byte)((i*31+seed)&255);}};
        ScriptPacket packet=new ScriptPacket{SetId=(byte)Convert.ToInt32(c["setId"])};
        float got;
        switch(name)
        {
            case "GotOpponent":got=CompactConditions.GotOpponent(creature);break;
            case "OpponentRange":got=CompactConditions.OpponentRange(creature);break;
            case "OffScreenTimer":got=CompactConditions.OffScreenTimer(creature,UInt(input["initialized"])!=0?bound:null);break;
            case "FreePlay":got=CompactConditions.FreePlay(world);break;
            case "NumInSetAlive":got=CompactConditions.NumInSetAlive(world,packet,Selector(input["initialized"]));break;
            case "AlwaysTrue":got=CompactConditions.AlwaysTrue(FromBits(input["initialized"]));break;
            default:throw new InvalidOperationException(name);
        }
        Check(name+"-bits",Bits(got),UInt(input["nativeBits"]),input);
        if(input.ContainsKey("comparison")&&input["comparison"]!=null)
        {
            Dictionary<string,object> comparison=Obj(input["comparison"]);Check(name+"-comparison",Compare(got,FromBits(comparison["thresholdBits"]),(string)comparison["operator"]),Convert.ToBoolean(comparison["matched"]),input);
        }
    }
    static void Initializer(Dictionary<string,object> input)
    {
        string name=(string)input["command"],operand=(string)input["operand"];
        if(name=="NumInSetAlive")Check("set-selector",CompactConditions.BindNumInSetAlive(operand),Selector(input["selector"]),input);
        else if(name=="AlwaysTrue")Check("always-initializer",Bits(CompactConditions.BindAlwaysTrue(operand)),UInt(input["initializedBits"]),input);
        else
        {
            bool hasObject=Convert.ToBoolean(input["actorObject"]);ConditionObject own=hasObject?new ConditionObject{OffScreenTimer=6.25f}:null,named=new ConditionObject{OffScreenTimer=12.5f};
            ConditionWorld world=new ConditionWorld();
            if(Convert.ToBoolean(input["callback"]))world.ResolveCharacter=delegate(string requested){return requested=="named"?new ConditionActorReference{Object=named}:requested=="empty-object"?new ConditionActorReference{Object=own}:null;};
            ConditionObject selected=CompactConditions.BindOffScreenTimer(world,operand);
            string kind=selected==null?null:Object.ReferenceEquals(selected,named)?"named":"self";
            Check("offscreen-initializer-reference",kind,input["boundKind"],input);
            float value=CompactConditions.OffScreenTimer(new ConditionCreature{ActorReference=new ConditionActorReference{Object=own}},selected);
            Check("offscreen-initializer-value",Bits(value),UInt(input["nativeBits"]),input);
        }
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;
        Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object input in Arr(data["cases"]))Run(Obj(input));
        foreach(object input in Arr(data["initializers"]))Initializer(Obj(input));
        foreach(object input in Arr(data["shipped"]))Run(Obj(input));
        string output=json.Serialize(new{checks,mismatches=failures,errors,method="Compiled compact condition readers/initializers compared with captured original-PC float32 and comparison results."});
        if(args.Length>1)File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
