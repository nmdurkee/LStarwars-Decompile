using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class CameraRenderCachePhase6Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static int[] Ints(object v){object[] a=Arr(v);int[] r=new int[a.Length];for(int i=0;i<r.Length;++i)r[i]=Convert.ToInt32(a[i]);return r;}
 static uint[] UInts(object v){object[] a=Arr(v);uint[] r=new uint[a.Length];for(int i=0;i<r.Length;++i)r[i]=Convert.ToUInt32(a[i]);return r;}
 static byte[] Hex(string s){byte[] r=new byte[s.Length/2];for(int i=0;i<r.Length;++i)r[i]=Convert.ToByte(s.Substring(i*2,2),16);return r;}
 static string Hex(byte[] r){return BitConverter.ToString(r).Replace("-","").ToLowerInvariant();}
 static float[] Floats(uint[] words){float[] r=new float[words.Length];for(int i=0;i<r.Length;++i)r[i]=BitConverter.ToSingle(BitConverter.GetBytes(words[i]),0);return r;}
 static bool Words(float[] values,object expected){uint[] r=UInts(expected);if(values.Length!=r.Length)return false;for(int i=0;i<r.Length;++i)if(BitConverter.ToUInt32(BitConverter.GetBytes(values[i]),0)!=r[i])return false;return true;}
 static RenderCacheInputs Inputs(Dictionary<string,object> c){return new RenderCacheInputs{Screen=Ints(c["screen"]),Source=Ints(c["source"]),Rectangle=Ints(c["rectangle"]),Origin=Ints(c["origin"])};}
 static CameraRenderCache State(Dictionary<string,object> c){return new CameraRenderCache{Image=Hex((string)c["beforeHex"]),Counter=Convert.ToUInt32(c["counter"]),ShortCounter=Convert.ToUInt16(c["shortCounter"])};}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object value in Arr(f["offsetCases"])) {var c=Map(value);Check(Words(CameraRenderCacheProduction.Offsets(Inputs(c)),c["nativeWords"]),"original offset words "+cases);++cases;}
  foreach(object value in Arr(f["extentCases"])) {var c=Map(value);Check(Words(CameraRenderCacheProduction.Extents(Inputs(c)),c["nativeWords"]),"original extent words "+cases);++cases;}
  foreach(object value in Arr(f["cacheCases"]))
  {
   var c=Map(value);var input=Inputs(c);var state=State(c);uint[] view=UInts(c["viewWords"]);float[] projection=Floats(UInts(c["projectionWords"]));int result=CameraRenderCacheProduction.Update(state,input,view,projection);Check(Hex(state.Image)==(string)c["nativeHex"],"complete cache image "+cases);Check(state.Counter==Convert.ToUInt32(c["nativeCounter"]),"wrapping uint counter "+cases);Check(state.ShortCounter==Convert.ToUInt16(c["nativeShortCounter"]),"wrapping ushort counter "+cases);Check(result==Convert.ToInt32(c["nativeResult"]),"cache return "+cases);var callbackState=State(c);CameraRenderCacheProduction.CameraCallback(callbackState,input)(new CameraPlaneState{View=Floats(view),Projection=projection});Check(Hex(callbackState.Image)==Hex(state.Image)&&callbackState.Counter==state.Counter&&callbackState.ShortCounter==state.ShortCounter,"camera callback binding "+cases);++cases;
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Original CPU render-cache and concrete signed viewport offsets/extents. Raw view words, finite sampled projection values, exact spills and untouched cache gaps; authored runtime inputs remain supplied."}));return failures==0?0:1;
 }
}
