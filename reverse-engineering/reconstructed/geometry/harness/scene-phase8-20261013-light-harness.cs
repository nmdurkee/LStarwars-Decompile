using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class LightNumericPhase8Harness
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
 static float[] Floats(object v){uint[] words=Words(v);float[] r=new float[words.Length];for(int i=0;i<r.Length;++i)r[i]=BitConverter.ToSingle(BitConverter.GetBytes(words[i]),0);return r;}
 static uint[] Optional(object v){return v==null?null:Words(v);}
 static LightNumericGlobals Globals(Dictionary<string,object> c){return new LightNumericGlobals{DirectionWords=Words(c["beforeDirectionWords"]),ColorWords=Words(c["beforeColorWords"]),Aim=Floats(c["aimWords"]),IdentityWords=Words(c["identityWords"])};}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object value in Arr(f["cases"]))
  {
   var c=Map(value);var g=Globals(c);float[] camera=Floats(c["cameraWords"]);uint[] direction=Optional(c["inputDirectionWords"]),color=Optional(c["inputColorWords"]);var input=LightNumericProduction.Produce(g,camera,direction,color);Check(Equal(input.MatrixWords,Words(c["matrixWords"])),"complete original light orientation "+cases);Check(Equal(input.VectorWords,Words(c["vectorWords"])),"original inverse light vector "+cases);Check(Equal(input.ColorWords,Words(c["colorWords"])),"raw packed color "+cases);Check(Equal(g.DirectionWords,Words(c["nativeDirectionWords"])),"optional direction source "+cases);Check(Equal(g.ColorWords,Words(c["nativeColorWords"])),"optional color source "+cases);var state=State(c);var shared=Shared(c);var expected=Map(c["native"]);int result=LightNumericProduction.Apply(shared,state,Globals(c),camera,direction,color);Check(Equal(state.Words,Words(expected["imageWords"])),"complete original light cache "+cases);Check(shared.Counter==Convert.ToUInt32(expected["counter"]),"shared counter "+cases);Check(state.ShortCounter==Convert.ToUInt16(expected["shortCounter"]),"light counter "+cases);Check(state.Dirty==Convert.ToUInt32(expected["dirty"]),"light dirty "+cases);Check(result==Convert.ToInt32(c["nativeResult"]),"full producer return "+cases);
   if(direction==null&&color==null){var callbackState=State(c);var callbackShared=Shared(c);var callbackGlobals=Globals(c);LightNumericProduction.CameraCallback(callbackShared,callbackState,callbackGlobals)(new CameraPlaneState{Current=camera});Check(Equal(callbackState.Words,state.Words)&&callbackState.ShortCounter==state.ShortCounter&&callbackState.Dirty==state.Dirty&&callbackShared.Counter==shared.Counter&&Equal(callbackGlobals.DirectionWords,g.DirectionWords)&&Equal(callbackGlobals.ColorWords,g.ColorWords),"real null-source camera binding "+cases);}++cases;
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Finite original light orientation, repeated float-spilled squaring, optional raw sources and real light cache packing. Runtime templates and authored light globals supplied; no whole renderer claim."}));return failures==0?0:1;
 }
}
