using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class GameplayExpressionLoadingVerify
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
        public readonly ExpressionLoadContext Context=new ExpressionLoadContext{SeenSymbol=0x11,LastSymbolUnresolved=0x22,RequiresRuntime=0x33};
        public readonly List<object> Events=new List<object>();
        // Load-time functions have no access to a runtime environment. This
        // independent sentinel instance represents the native untouched globals.
        readonly ExpressionEnvironment runtime=new ExpressionEnvironment{Creature=new object(),ActivePacket=new ScriptPacket(),Random=new ScriptRandom{State=123}};
        readonly object oldCreature;readonly ScriptPacket oldPacket;
        public Fixture(Dictionary<string,object> options)
        {
            oldCreature=runtime.Creature;oldPacket=runtime.ActivePacket;
            Context.ObserveError=delegate(){Events.Add(new object[]{"error"});};
            if(Option(options,"callback",true))Context.GameSymbol=delegate(object creature,ScriptPacket packet,string name,out float value)
            {
                Dictionary<string,object> symbols=options.ContainsKey("symbols")?O(options["symbols"]):new Dictionary<string,object>();object raw;bool exists=symbols.TryGetValue(name.ToLowerInvariant(),out raw);Dictionary<string,object> entry=exists?O(raw):null;bool handled=exists&&Convert.ToBoolean(entry["handled"]);value=exists?F(U(entry["valueBits"])):0;
                Events.Add(new object[]{"symbol",name,creature!=null,packet!=null,handled,exists?(object)B(value):null});return handled;
            };
        }
        uint[] Flags(){return new uint[]{Context.SeenSymbol,Context.LastSymbolUnresolved,Context.RequiresRuntime};}
        public object Evaluate(string text)
        {
            ExpressionBuffer buffer=new ExpressionBuffer(text);float value=ScriptExpressionLoading.Evaluate(Context,buffer);
            return new Dictionary<string,object>{{"value",B(value)},{"flags",Flags()},{"text",buffer.ToString()},{"events",Events.ToArray()},{"rng",runtime.Random.State},{"runtimeGlobals",new uint[]{Object.ReferenceEquals(runtime.Creature,oldCreature)?0x11111111u:0u,Object.ReferenceEquals(runtime.ActivePacket,oldPacket)?0x22222222u:0u}}};
        }
        public object Symbol(Dictionary<string,object> row)
        {
            float[] f=new float[]{F(0x12345678)};uint[] i=new uint[]{0x87654321};int result=ScriptExpressionLoading.ResolveOutputs(Context,(string)row["name"],Convert.ToBoolean(row["floatOutput"])?f:null,Convert.ToBoolean(row["integerOutput"])?i:null);
            return new Dictionary<string,object>{{"result",result},{"floatBits",B(f[0])},{"integerBits",i[0]},{"flags",Flags()},{"events",Events.ToArray()}};
        }
    }
    public static int Main(string[] args)
    {
        JavaScriptSerializer j=new JavaScriptSerializer();j.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(j.DeserializeObject(File.ReadAllText(args[0])));int checks=0,failures=0;List<object> errors=new List<object>();
        foreach(string kind in new string[]{"cases","symbols"})foreach(object value in A(data[kind]))try
        {
            Dictionary<string,object> row=O(value);Fixture fixture=new Fixture(O(row["options"]));object got=kind=="cases"?fixture.Evaluate((string)row["text"]):fixture.Symbol(row);++checks;
            if(!Equal(got,row["native"])){++failures;if(errors.Count<12)errors.Add(new{kind,index=checks-1,got,want=row["native"]});}
        }
        catch(Exception e){++failures;if(errors.Count<12)errors.Add(new{kind,error=e.ToString()});}
        string output=j.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
