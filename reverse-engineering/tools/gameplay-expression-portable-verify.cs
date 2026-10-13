using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class GameplayExpressionVerify
{
    static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}
    static object[] A(object x){return (object[])x;}
    static uint U(object x){return Convert.ToUInt32(x);}
    static uint B(float x){return BitConverter.ToUInt32(BitConverter.GetBytes(x),0);}
    static float F(uint x){return BitConverter.ToSingle(BitConverter.GetBytes(x),0);}
    static bool Option(Dictionary<string,object> d,string k,bool fallback){return d.ContainsKey(k)?Convert.ToBoolean(d[k]):fallback;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    sealed class Fixture
    {
        public readonly ExpressionEnvironment Environment=new ExpressionEnvironment();
        public readonly List<object> Events=new List<object>();
        public readonly object Creature=new object(),OldCreature=new object();
        public readonly ScriptPacket Packet=new ScriptPacket{Script=new ScriptDefinition()},OldPacket=new ScriptPacket();
        public readonly Dictionary<string,object> Options;
        public Fixture(Dictionary<string,object> options)
        {
            Options=options;Environment.Creature=OldCreature;Environment.ActivePacket=OldPacket;
            Environment.Random.State=options.ContainsKey("seed")?U(options["seed"]):123;
            string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){Packet.Script.ParameterNames[i]=names[i];Packet.Parameters[i]=values[i];}
            Environment.ObserveError=delegate(){Events.Add(new object[]{"error"});};
            if(Option(options,"callback",true))Environment.GameSymbol=delegate(object creature,ScriptPacket packet,string name,out float value)
            {
                Dictionary<string,object> symbols=options.ContainsKey("symbols")?O(options["symbols"]):new Dictionary<string,object>();object entry;bool handled=symbols.TryGetValue(name.ToLowerInvariant(),out entry);value=handled?Convert.ToSingle(entry):0;
                Events.Add(new object[]{"symbol",name,creature!=null,packet!=null,handled,handled?(object)B(value):null});return handled;
            };
        }
        public object Execute(ExpressionBuffer buffer)
        {
            Events.Clear();float value=ScriptExpressions.Evaluate(Environment,Option(Options,"creature",true)?Creature:null,Option(Options,"packet",true)?Packet:null,buffer);ExpressionParserState s=Environment.LastParser;
            return new Dictionary<string,object>{{"value",B(value)},{"text",buffer.ToString()},{"rng",Environment.Random.State},{"events",Events.ToArray()},{"slow",s!=null},{"globalCreature",Environment.Creature==null?0:Object.ReferenceEquals(Environment.Creature,Creature)?1:Object.ReferenceEquals(Environment.Creature,OldCreature)?2:-1},{"globalPacket",Environment.ActivePacket==null?0:Object.ReferenceEquals(Environment.ActivePacket,Packet)?1:Object.ReferenceEquals(Environment.ActivePacket,OldPacket)?2:-1},{"parser",s==null?null:new Dictionary<string,object>{{"index",s.Index},{"kind",s.Kind},{"value",s.HasTokenValue?(object)B(s.TokenValue):null}}}};
        }
        public object Symbol(Dictionary<string,object> row)
        {
            Environment.Creature=Option(Options,"creature",true)?Creature:null;Environment.ActivePacket=Option(Options,"packet",true)?Packet:null;
            float[] f=new float[]{F(0x12345678)};uint[] i=new uint[]{0x87654321};
            int result=ScriptExpressions.ResolveOutputs(Environment,(string)row["name"],Convert.ToBoolean(row["floatOutput"])?f:null,Convert.ToBoolean(row["integerOutput"])?i:null);
            return new Dictionary<string,object>{{"result",result},{"floatBits",B(f[0])},{"integerBits",i[0]},{"rng",Environment.Random.State},{"events",Events.ToArray()}};
        }
    }
    static int checks,failures;static readonly List<object> errors=new List<object>();
    static void Check(string kind,object got,object wanted)
    {++checks;if(!Equal(got,wanted)){++failures;if(errors.Count<12)errors.Add(new{kind,index=checks-1,got,want=wanted});}}
    public static int Main(string[] args)
    {
        JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(j.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object value in A(data["cases"]))try{Dictionary<string,object> row=O(value);Fixture fixture=new Fixture(O(row["options"]));Check("expression",fixture.Execute(new ExpressionBuffer((string)row["text"])),row["native"]);}catch(Exception e){++failures;errors.Add(new{kind="expression",error=e.ToString()});}
        foreach(object value in A(data["symbols"]))try{Dictionary<string,object> row=O(value);Fixture fixture=new Fixture(O(row["options"]));Check("symbol",fixture.Symbol(row),row["native"]);}catch(Exception e){++failures;errors.Add(new{kind="symbol",error=e.ToString()});}
        foreach(object value in A(data["identifiers"])){Dictionary<string,object> row=O(value);Check("identifier",ScriptExpressions.IdentifierCharacter((byte)U(row["value"]))?1:0,row["native"]);}
        foreach(object value in A(data["sequences"]))try
        {Dictionary<string,object> row=O(value);Fixture fixture=new Fixture(O(row["options"]));ExpressionBuffer buffer=new ExpressionBuffer((string)row["text"]);foreach(object wanted in A(row["native"]))Check("persistent",fixture.Execute(buffer),wanted);}
        catch(Exception e){++failures;errors.Add(new{kind="persistent",error=e.ToString()});}
        string output=j.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
