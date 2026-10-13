using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class TargetResetPhase14Harness
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
 static void Write(byte[] image,uint offset,uint word){int i=(int)offset;image[i]=(byte)(word&255);image[i+1]=(byte)((word>>8)&255);image[i+2]=(byte)((word>>16)&255);image[i+3]=(byte)(word>>24);}
 static RenderTargetResetCapabilities Caps(object value){var c=Map(value);return new RenderTargetResetCapabilities{FirstEnabled=Convert.ToByte(c["firstEnabled"]),SecondEnabled=Convert.ToByte(c["secondEnabled"]),FirstMode=U(c["firstMode"]),SecondMode=U(c["secondMode"])};}
 static bool CapsMatch(RenderTargetResetCapabilities caps,object value){var c=Map(value);return caps.FirstEnabled==Convert.ToByte(c["firstEnabled"])&&caps.SecondEnabled==Convert.ToByte(c["secondEnabled"])&&caps.FirstMode==U(c["firstMode"])&&caps.SecondMode==U(c["secondMode"]);}
 static bool SnapshotMatches(RenderTargetPipelineRuntime runtime,RenderTargetResetCapabilities caps,object value){var s=Map(value);return Hex(runtime.BackendImage)==(string)s["backendHex"]&&runtime.TargetCache.Configuration==Convert.ToInt32(s["configuration"])&&CapsMatch(caps,s["capabilities"])&&InputsMatch(runtime.Viewport,s["inputs"])&&ViewportMatches(runtime.Viewport,s["viewport"]);}
 static void Plan(RenderTargetPipelineRuntime runtime,RenderTargetResetCapabilities caps,string edge,Dictionary<string,object> plan,ViewportComCall viewport)
 {
  foreach(object value in Arr(plan["backendChanges"])){var m=Map(value);Write(runtime.BackendImage,U(m["offset"]),U(m["word"]));}
  if(edge!="viewport"){runtime.TargetCache.Configuration=Convert.ToInt32(plan["configuration"]);var c=Caps(plan["capabilities"]);caps.FirstEnabled=c.FirstEnabled;caps.SecondEnabled=c.SecondEnabled;caps.FirstMode=c.FirstMode;caps.SecondMode=c.SecondMode;runtime.Viewport.Bias=Floats(plan["bias"]);}
  else{foreach(object value in Arr(plan["sourceChanges"])){var m=Map(value);Write(viewport.Input.Image,viewport.Input.Offset+U(m["index"])*4,U(m["word"]));}foreach(object value in Arr(plan["argumentChanges"])){var m=Map(value);viewport.Arguments[U(m["index"])]=U(m["word"]);}}
 }
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));float[] identity=WordFloats(f["identityWords"]);int cases=0;
  foreach(object sequenceValue in Arr(f["sequences"])){
   var sequence=Map(sequenceValue);var before=Map(sequence["before"]);var setter=Runtime(before["inputs"],identity);Globals(setter,before["viewport"]);var caps=Caps(before["capabilities"]);var runtime=new RenderTargetPipelineRuntime(Hex((string)before["backendHex"]),Convert.ToInt32(before["configuration"]),null,setter);
   foreach(object value in Arr(sequence["calls"])){
    var c=Map(value);var plans=Arr(c["plans"]);var events=Arr(c["nativeEvents"]);int at=0;
    Func<string,uint,uint[],ViewportComCall,uint> service=delegate(string edge,uint device,uint[] packet,ViewportComCall viewport){if(at>=events.Length)throw new InvalidOperationException("Unexpected reset COM edge.");var expected=Map(events[at]);var plan=Map(plans[at++]);Check(edge==(string)expected["edge"]&&device==U(expected["device"])&&Equal(packet,expected["arguments"])&&(viewport==null||Object.ReferenceEquals(viewport.Backend,runtime.ViewportBackend)&&SourceHex(viewport.Input)==(string)expected["sourceHex"]),"actual reset final COM packet/receiver "+cases+"/"+at);Check(SnapshotMatches(runtime,caps,expected["before"]),"published reset CPU state at COM "+cases+"/"+at);Plan(runtime,caps,edge,plan,viewport);return U(plan["return"]);};
    var services=new RenderTargetResetServices{Target=delegate(uint device,uint slot,uint handle){return service("target",device,new uint[]{slot,handle},null);},Depth=delegate(uint device,uint handle){return service("depth",device,new uint[]{handle},null);},Viewport=delegate(ViewportComCall call){return service("viewport",call.Device,call.Arguments,call);}};
    uint result=(string)c["kind"]=="restore"?RenderTargetResetProduction.Restore(runtime,caps,services):RenderTargetResetProduction.ClearAdditional(runtime,services);var final=Map(c["native"]);Check(Hex(runtime.BackendImage)==(string)final["backendHex"],"one reset/backend image "+cases);Check(runtime.TargetCache.Configuration==Convert.ToInt32(final["configuration"])&&CapsMatch(caps,final["capabilities"]),"per-slot configuration/capabilities "+cases);Check(InputsMatch(setter,final["inputs"]),"fresh reset dimension producer globals "+cases);Check(ViewportMatches(setter,final["viewport"]),"actual refresh/reset numeric globals "+cases);Check(result==U(c["nativeResult"]),"tail-jump original refresh result "+cases);Check(at==events.Length,"all final reset COM calls "+cases);++cases;
   }
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Whole original target/depth restore and clear-additional CPU consumers ending in actual viewport refresh. Single backend and finite mode0 runtime supplied; only final target/depth/viewport COM edges explicit."}));return failures==0?0:1;
 }
}
