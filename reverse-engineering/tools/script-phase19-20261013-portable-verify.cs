using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase1920261013Verify
{
 static JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=200};static Dictionary<string,object> Obj(object o){return (Dictionary<string,object>)o;}static object[] Arr(object o){return (object[])o;}static uint U(object o){return Convert.ToUInt32(o);}
 static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 sealed class Memory:TakeoverReleaseMemory
 {
  readonly Dictionary<uint,byte> bytes=new Dictionary<uint,byte>();public Memory(object segments){foreach(object row in Arr(segments)){var r=Obj(row);uint p=U(r["address"]);byte[] b=Unhex((string)r["bytes"]);for(uint i=0;i<b.Length;i++)bytes[p+i]=b[i];}}
  public override byte Read8(uint p){byte v;if(!bytes.TryGetValue(p,out v))throw new ArgumentException("Unmapped prepared read "+p.ToString("x"));return v;}public override void Write8(uint p,byte b){if(!bytes.ContainsKey(p))throw new ArgumentException("Unmapped prepared write "+p.ToString("x"));bytes[p]=b;}
  public object State(object segments){var rows=new List<object>();foreach(object row in Arr(segments)){var r=Obj(row);uint p=U(r["address"]);int length=((string)r["bytes"]).Length/2;byte[] b=new byte[length];for(int i=0;i<length;i++)b[i]=Read8(p+(uint)i);rows.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return rows;}
 }
 sealed class Services:ScriptConditionServices
 {
  readonly Dictionary<string,object> context;readonly Dictionary<string,int> counts=new Dictionary<string,int>();public readonly List<object> Events=new List<object>();public Services(Dictionary<string,object> c){context=c;}
  void Patch(TakeoverReleaseMemory m,string key){object obj,rows;if(context.TryGetValue("patches",out obj)&&Obj(obj).TryGetValue(key,out rows))foreach(object row in Arr(rows)){object[] p=Arr(row);uint address=U(p[0]),value=U(p[2]);for(uint i=0;i<U(p[1]);i++)m.Write8(address+i,(byte)(value>>(int)(i*8)));}}
  uint Call(TakeoverReleaseMemory m,string name,uint[] args)
  {int count;counts.TryGetValue(name,out count);counts[name]=++count;Events.Add(new Dictionary<string,object>{{"name",name},{"args",args},{"observed",new uint[]{m.Read32(0x10101004),m.Read32(0x10101008),m.Read32(0x10101050),m.Read32(0x10101064)}}});Patch(m,name);Patch(m,name+"#"+count);object obj,value;if(context.TryGetValue("results",out obj)&&Obj(obj).TryGetValue(name,out value)){object[] sequence=Arr(value);return U(sequence[Math.Min(count-1,sequence.Length-1)]);}string key=name=="Predicate"?"left":"right";return TakeoverReleaseMemory.Bits(context.TryGetValue(key,out value)?Convert.ToSingle(value):1f);}
  public override uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint a,uint b){return Call(m,"Predicate",new uint[]{callback,system,packet,actor,a,b});}public override uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint expression){return Call(m,"Expression",new uint[]{actor,packet,expression});}
 }
 sealed class Remaining:ScriptDispatcherServices
 {
  public override uint Conditions(TakeoverReleaseMemory m,uint b,uint s,uint l,uint a,uint p){throw new ArgumentException("Unexpected condition fallback");}public override uint References(TakeoverReleaseMemory m,uint s,uint a){throw new ArgumentException("Unexpected reference fallback");}public override void Scratch(TakeoverReleaseMemory m,uint c,uint s,uint a,uint p){throw new ArgumentException("Unexpected scratch child");}public override void Animation(TakeoverReleaseMemory m,uint a,uint c){throw new ArgumentException("Unexpected animation child");}public override uint Command(TakeoverReleaseMemory m,uint c,uint s,uint p,uint a,uint b,uint d,uint f,uint t){throw new ArgumentException("Unexpected action child");}
 }
 static int checks;static List<object> errors=new List<object>();static void Check(string group,object got,object want,int index){checks++;if(json.Serialize(got)!=json.Serialize(want))errors.Add(new Dictionary<string,object>{{"group",group},{"index",index},{"got",got},{"want",want}});}
 public static int Main(string[] args)
 {
  if(args.Length!=2)return 2;var fixture=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;foreach(object row in Arr(fixture["cases"]))
  {var c=Obj(row);var i=Obj(c["inputs"]);var m=new Memory(c["initial"]);var services=new Services(Obj(c["context"]));bool fault=false;uint result=0;string method=(string)c["method"];
   try{if(method=="Evaluate")result=PreparedScriptConditions.Evaluate(m,services,U(i["bank"]),U(i["system"]),U(i["list"]),U(i["actor"]),U(i["packet"]));else if(method=="Finish")PreparedScriptConditions.Finish(m,services,U(i["bank"]),U(i["list"]),U(i["actor"]),U(i["packet"]),U(i["current"]));else if(method=="Tick")PreparedEvaluatedScriptDispatcher.Tick(m,new Remaining(),services,U(i["system"]),U(i["actor"]),U(i["packet"]),0);else result=PreparedScriptReferences.Scan(m,services,U(i["system"]),U(i["actor"]),U(i["packet"]));}catch(ArgumentException){fault=true;}
   Check("fault",fault,c["fault"]!=null,index);Check("events",services.Events,c["nativeEvents"],index);Check("memory",m.State(c["initial"]),c["final"],index);if(method!="Finish"&&method!="Tick"&&!fault)Check("return",result,c["returnValue"],index);index++;
  }
  File.WriteAllText(args[1],json.Serialize(new Dictionary<string,object>{{"binarySha256",fixture["binarySha256"]},{"checks",checks},{"cases",index},{"mismatches",errors.Count},{"errors",errors},{"limitations",new string[]{"Predicate and expression child calls remain explicit; prepared memory, bounded acyclic lists, finite/infinity/quietNaN condition values and supplied script binding. Saved-fixture harness has no binary dependency."}}}));Console.WriteLine(json.Serialize(new{checks=checks,mismatches=errors.Count}));return errors.Count==0?0:1;
 }
}
