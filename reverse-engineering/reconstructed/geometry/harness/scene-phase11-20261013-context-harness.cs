using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class RenderTargetCachePhase11Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static byte[] Hex(string s){var r=new byte[s.Length/2];for(int i=0;i<r.Length;++i)r[i]=Convert.ToByte(s.Substring(i*2,2),16);return r;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Matches(RenderTargetCacheState state,object value){var v=Map(value);return Hex(state.Image)==(string)v["imageHex"]&&state.Configuration==Convert.ToInt32(v["configuration"]);}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object sequenceValue in Arr(f["sequences"]))
  {
   var sequence=Map(sequenceValue);var before=Map(sequence["before"]);var state=new RenderTargetCacheState{Image=Hex((string)before["imageHex"]),Configuration=Convert.ToInt32(before["configuration"])};
   foreach(object callValue in Arr(sequence["calls"]))
   {
    var c=Map(callValue);var service=Map(c["service"]);var events=Arr(c["nativeEvents"]);int at=0;
    Func<uint,uint,uint,uint> invoke=delegate(uint device,uint slot,uint handle){if(at>=events.Length)throw new InvalidOperationException("Unexpected COM call.");var e=Map(events[at++]);string edge=device==U(f["deviceA"])?"A":"B";Check(device==U(e["device"])&&slot==U(e["slot"])&&handle==U(e["handle"])&&edge==(string)e["edge"]&&Matches(state,e["before"]),"published cache/device argument and receiver order "+cases);foreach(object mutationValue in Arr(service["changes"])){var mutation=Map(mutationValue);int offset=Convert.ToInt32(mutation["offset"]);uint word=U(mutation["word"]);state.Image[offset]=(byte)word;state.Image[offset+1]=(byte)(word>>8);state.Image[offset+2]=(byte)(word>>16);state.Image[offset+3]=(byte)(word>>24);}state.Configuration=Convert.ToInt32(service["configurationAfter"]);return U(service["return"]);};uint result=RenderTargetCacheProduction.Apply(state,U(c["slot"]),U(c["handle"]),invoke);Check(Matches(state,c["native"]),"complete original backend image/configuration "+cases);Check(result==U(c["nativeResult"]),"original opaque/no-op return "+cases);Check(at==events.Length,"all original COM calls "+cases);++cases;
   }
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Original signed/wrapping target-cache caller with raw backend image, cache publication before COM, callback mutation and opaque HRESULT persistence. Device and runtime lifetime remain explicit."}));return failures==0?0:1;
 }
}
