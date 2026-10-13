using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class DisplayModePhase14Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static byte[] Hex(string s){byte[] r=new byte[s.Length/2];for(int i=0;i<r.Length;++i)r[i]=Convert.ToByte(s.Substring(i*2,2),16);return r;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool ok,string label){++checks;if(!ok){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object sequenceValue in Arr(f["modeSequences"])){var sequence=Map(sequenceValue);var before=Map(sequence["before"]);byte[] backend=Hex((string)before["backendHex"]),modes=Hex((string)before["modesHex"]);foreach(object value in Arr(sequence["calls"])){var c=Map(value);var request=Arr(c["request"]);uint result=DisplayModeCpuSelection.Select(backend,modes,Convert.ToInt32(request[0]),Convert.ToInt32(request[1]),Convert.ToInt32(request[2]));Check(Hex(backend)==(string)c["nativeBackendHex"],"mode caller/backend preserved "+cases);Check(Hex(modes)==(string)c["nativeModesHex"],"actual mode-table selected mutation and preserved words "+cases);Check(result==U(c["nativeResult"]),"signed/wrapping/tied mode index "+cases);++cases;}}
  foreach(object value in Arr(f["aspectCases"])){var c=Map(value);var result=DisplayModeCpuSelection.ClassifyRaw(U(c["width"]),U(c["height"]));var scratch=Arr(c["nativeArgumentWords"]);Check(result.Mode==U(c["nativeResult"]),"original finite unsigned aspect result "+cases);Check(result.WidthStackWord==U(scratch[0])&&result.HeightStackWord==U(scratch[1]),"original argument scratch diagnostics "+cases);++cases;}
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Original display-mode selection/mutation and finite unsigned aspect classifier with raw argument-word diagnostics. Disjoint mode-pointer resolution and mode enumeration/device bootstrap external; no later caller-stack lifetime claim."}));return failures==0?0:1;
 }
}
