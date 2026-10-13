using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class LightRenderCachePhase7Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static uint[] Words(object v){object[] a=Arr(v);uint[] r=new uint[a.Length];for(int i=0;i<r.Length;++i)r[i]=Convert.ToUInt32(a[i]);return r;}
 static bool Equal(uint[] a,uint[] b){if(a==null||b==null||a.Length!=b.Length)return false;for(int i=0;i<a.Length;++i)if(a[i]!=b[i])return false;return true;}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 static LightRenderCache State(Dictionary<string,object> c){var b=Map(c["before"]);return new LightRenderCache{Words=Words(b["imageWords"]),ShortCounter=Convert.ToUInt16(b["shortCounter"]),Dirty=Convert.ToUInt32(b["dirty"])};}
 static CameraRenderCache Shared(Dictionary<string,object> c){return new CameraRenderCache{Counter=Convert.ToUInt32(Map(c["before"])["counter"]),ShortCounter=0xabcd,Image=new byte[]{0x55}};}
 static LightRenderInputs Inputs(Dictionary<string,object> c){return new LightRenderInputs{VectorWords=Words(c["vectorWords"]),MatrixWords=Words(c["matrixWords"]),ColorWords=Words(c["colorWords"])};}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(string group in new[]{"rawCases","producerCases"})foreach(object value in Arr(f[group]))
  {
   var c=Map(value);var state=State(c);var shared=Shared(c);var input=Inputs(c);var expected=Map(c["native"]);int result=LightRenderCacheProduction.Update(shared,state,input);Check(Equal(state.Words,Words(expected["imageWords"])),"raw integer light image "+cases);Check(shared.Counter==Convert.ToUInt32(expected["counter"]),"shared uint counter "+cases);Check(state.ShortCounter==Convert.ToUInt16(expected["shortCounter"]),"light ushort counter "+cases);Check(state.Dirty==Convert.ToUInt32(expected["dirty"]),"light dirty "+cases);Check(result==Convert.ToInt32(c["nativeResult"]),"packer result "+cases);Check(shared.ShortCounter==0xabcd&&shared.Image.Length==1&&shared.Image[0]==0x55,"separate camera state preserved "+cases);var via=State(c);var viaShared=Shared(c);int calls=0;LightRenderCacheProduction.CameraCallback(viaShared,via,delegate(CameraPlaneState camera){++calls;return input;})(new CameraPlaneState());Check(calls==1&&Equal(via.Words,state.Words)&&via.ShortCounter==state.ShortCounter&&via.Dirty==state.Dirty&&viaShared.Counter==shared.Counter,"explicit camera light producer binding "+cases);++cases;
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Raw original light cache consumer and shared counter, using retained actual finite light producer outputs. Full numeric light producer remains explicit service."}));return failures==0?0:1;
 }
}
