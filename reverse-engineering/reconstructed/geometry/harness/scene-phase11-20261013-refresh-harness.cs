using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ContextRefreshPhase11Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static float F(object v){return Convert.ToSingle(v);}
 static int[] Ints(object v){var a=Arr(v);var r=new int[a.Length];for(int i=0;i<r.Length;++i)r[i]=Convert.ToInt32(a[i]);return r;}
 static uint[] UInts(object v){var a=Arr(v);var r=new uint[a.Length];for(int i=0;i<r.Length;++i)r[i]=U(a[i]);return r;}
 static float[] Floats(object v){var a=Arr(v);var r=new float[a.Length];for(int i=0;i<r.Length;++i)r[i]=F(a[i]);return r;}
 static float[] WordFloats(object v){var a=UInts(v);var r=new float[a.Length];for(int i=0;i<r.Length;++i)r[i]=BitConverter.ToSingle(BitConverter.GetBytes(a[i]),0);return r;}
 static byte[] Hex(string s){var r=new byte[s.Length/2];for(int i=0;i<r.Length;++i)r[i]=Convert.ToByte(s.Substring(i*2,2),16);return r;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static string SourceHex(RawViewportView input){byte[] packet=new byte[24];Array.Copy(input.Image,(int)input.Offset,packet,0,24);return Hex(packet);}
 static bool Equal(int[] actual,object value){var b=Ints(value);if(actual==null||actual.Length!=b.Length)return false;for(int i=0;i<b.Length;++i)if(actual[i]!=b[i])return false;return true;}
 static bool Equal(uint[] actual,object value){var b=UInts(value);if(actual==null||actual.Length!=b.Length)return false;for(int i=0;i<b.Length;++i)if(actual[i]!=b[i])return false;return true;}
 static bool Equal(float[] actual,object value){var b=Floats(value);if(actual==null||actual.Length!=b.Length)return false;for(int i=0;i<b.Length;++i)if(BitConverter.ToUInt32(BitConverter.GetBytes(actual[i]),0)!=BitConverter.ToUInt32(BitConverter.GetBytes(b[i]),0))return false;return true;}
 static bool FloatWords(float[] actual,object value){var b=UInts(value);if(actual==null||actual.Length!=b.Length)return false;for(int i=0;i<b.Length;++i)if(BitConverter.ToUInt32(BitConverter.GetBytes(actual[i]),0)!=b[i])return false;return true;}
 static ViewportSetterRuntime Runtime(object value,float[] identity){var c=Map(value);var input=new CameraViewportInputs{Screen=Ints(c["screen"]),Rectangle=Ints(c["rectangle"]),DepthWords=UInts(c["depthWords"]),Ranges=Floats(c["ranges"])};return new ViewportSetterRuntime{Input=input,Viewport=new CameraViewportState{Dirty=U(c["dirty"]),Identity=identity},Source=Ints(c["source"]),Origin=Ints(c["origin"]),Scale=Floats(c["scale"]),Bias=Floats(c["bias"]),ConversionMode=0};}
 static void Globals(ViewportSetterRuntime runtime,object value){var v=Map(value);runtime.Viewport.Dirty=U(v["dirty"]);runtime.Viewport.Globals=new CameraPlaneGlobals{ScreenSize=runtime.Input.Screen,Correction=WordFloats(v["correctionWords"]),ClipScales=WordFloats(v["clipScaleWords"]),Auxiliary=WordFloats(v["auxiliaryWords"]),ClipTransform=WordFloats(v["clipTransformWords"])};}
 static bool InputsMatch(ViewportSetterRuntime s,object value){var c=Map(value);return Equal(s.Input.Screen,c["screen"])&&Equal(s.Source,c["source"])&&Equal(s.Origin,c["origin"])&&Equal(s.Scale,c["scale"])&&Equal(s.Bias,c["bias"])&&Equal(s.Input.Rectangle,c["rectangle"])&&Equal(s.Input.DepthWords,c["depthWords"])&&Equal(s.Input.Ranges,c["ranges"])&&s.Viewport.Dirty==U(c["dirty"]);}
 static bool ViewportMatches(ViewportSetterRuntime s,object value){var c=Map(value);var g=s.Viewport.Globals;return s.Viewport.Dirty==U(c["dirty"])&&FloatWords(g.Correction,c["correctionWords"])&&FloatWords(g.ClipScales,c["clipScaleWords"])&&FloatWords(g.Auxiliary,c["auxiliaryWords"])&&FloatWords(g.ClipTransform,c["clipTransformWords"]);}
 static bool SnapshotMatches(byte[] caller,ViewportCpuState global,ViewportSetterRuntime runtime,object value){var s=Map(value);return Hex(caller)==(string)s["callerHex"]&&Hex(global.BackendImage)==(string)s["globalHex"]&&InputsMatch(runtime,s["inputs"])&&ViewportMatches(runtime,s["viewport"]);}
 static void Write(byte[] image,uint offset,uint word){int i=(int)offset;image[i]=(byte)(word&255);image[i+1]=(byte)((word>>8)&255);image[i+2]=(byte)((word>>16)&255);image[i+3]=(byte)(word>>24);}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));float[] identity=WordFloats(f["identityWords"]);int cases=0;
  foreach(object value in Arr(f["primitiveCases"]))
  {var c=Map(value);var runtime=Runtime(c["before"],identity);float[] input=WordFloats(c["inputWords"]);switch((string)c["kind"]){case "depth":ContextViewportRefresh.Depth(runtime,input[0],input[1]);break;case "position":ContextViewportRefresh.Position(runtime,input[0],input[1]);break;case "physical":ContextViewportRefresh.Physical(runtime,input[0],input[1]);break;case "extent":ContextViewportRefresh.Extent(runtime,input[0],input[1]);break;default:throw new ArgumentException("Unknown original setter.");}Check(InputsMatch(runtime,c["native"]),"complete original setter inputs/dirty "+cases);++cases;}
  foreach(object value in Arr(f["refreshCases"]))
  {
   var c=Map(value);var before=Map(c["before"]);var runtime=Runtime(before["inputs"],identity);Globals(runtime,before["viewport"]);byte[] globalImage=Hex((string)before["globalHex"]),caller=Convert.ToBoolean(c["sameBackend"])?globalImage:Hex((string)before["callerHex"]);var global=new ViewportCpuState(globalImage,runtime.Input.Screen);var plans=Arr(c["plans"]);var events=Arr(c["nativeEvents"]);int at=0;
   Func<ViewportComCall,uint> service=delegate(ViewportComCall call){if(at>=events.Length)throw new InvalidOperationException("Unexpected real context-refresh viewport call.");var expected=Map(events[at]);var plan=Map(plans[at++]);Check(call.Device==U(expected["device"])&&Equal(call.Arguments,expected["arguments"])&&SourceHex(call.Input)==(string)expected["sourceHex"]&&Object.ReferenceEquals(call.Backend,global)&&SnapshotMatches(caller,global,runtime,expected["before"]),"actual refresh COM receiver/source and numeric state "+cases+"/"+at);foreach(object mutationValue in Arr(plan["backendChanges"])){var m=Map(mutationValue);Write(global.BackendImage,U(m["offset"]),U(m["word"]));}foreach(object mutationValue in Arr(plan["sourceChanges"])){var m=Map(mutationValue);Write(call.Input.Image,call.Input.Offset+U(m["index"])*4,U(m["word"]));}foreach(object mutationValue in Arr(plan["argumentChanges"])){var m=Map(mutationValue);call.Arguments[U(m["index"])]=U(m["word"]);}return U(plan["return"]);};uint result=ContextViewportRefresh.Refresh(caller,global,runtime,service);var expectedFinal=Map(c["native"]);Check(Hex(caller)==(string)expectedFinal["callerHex"],"caller viewport context image "+cases);Check(Hex(global.BackendImage)==(string)expectedFinal["globalHex"],"global backend image "+cases);Check(InputsMatch(runtime,expectedFinal["inputs"]),"actual setter/global input state "+cases);Check(ViewportMatches(runtime,expectedFinal["viewport"]),"real dirty-reset numeric globals "+cases);Check(result==U(c["nativeResult"]),"actual raw final refresh return "+cases);Check(at==events.Length,"all actual refresh COM calls "+cases);++cases;
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Actual finite depth/position/physical/extent setters and original complete context-refresh CPU chain through dirty reset and real viewport forwarding. Mode0/fitting integer conversion and runtime inputs explicit; COM/device lifetime external."}));return failures==0?0:1;
 }
}
