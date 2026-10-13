using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ViewportCpuPhase11Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static byte[] Hex(string s){var r=new byte[s.Length/2];for(int i=0;i<r.Length;++i)r[i]=Convert.ToByte(s.Substring(i*2,2),16);return r;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static string SourceHex(RawViewportView input){byte[] b=new byte[24];Array.Copy(input.Image,(int)input.Offset,b,0,24);return Hex(b);}
 static int[] Ints(object v){var a=Arr(v);var r=new int[a.Length];for(int i=0;i<r.Length;++i)r[i]=Convert.ToInt32(a[i]);return r;}
 static bool Matches(ViewportCpuState state,RawViewportView input,object value){var v=Map(value);var screen=Ints(v["screen"]);return Hex(state.BackendImage)==(string)v["backendHex"]&&SourceHex(input)==(string)v["sourceHex"]&&state.Screen[0]==screen[0]&&state.Screen[1]==screen[1];}
 static void Write(byte[] image,uint offset,uint word){int i=(int)offset;image[i]=(byte)(word&255);image[i+1]=(byte)((word>>8)&255);image[i+2]=(byte)((word>>16)&255);image[i+3]=(byte)(word>>24);}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object value in Arr(f["cases"]))
  {
   var c=Map(value);var before=Map(c["before"]);byte[] backend=Hex((string)before["backendHex"]);bool alias=Convert.ToBoolean(c["alias"]);var input=new RawViewportView(alias?backend:Hex((string)before["sourceHex"]),U(c["sourceOffset"]));var state=new ViewportCpuState(backend,Ints(before["screen"]));var plan=Map(c["service"]);var events=Arr(c["nativeEvents"]);int at=0;
   Func<ViewportComCall,uint> service=delegate(ViewportComCall call){if(at>=events.Length)throw new InvalidOperationException("Unexpected viewport COM event.");var expected=Map(events[at++]);var words=Arr(expected["arguments"]);bool same=words.Length==call.Arguments.Length;for(int i=0;same&&i<call.Arguments.Length;++i)same=call.Arguments[i]==U(words[i]);Check(call.Device==U(expected["device"])&&same&&Object.ReferenceEquals(call.Backend,state)&&Object.ReferenceEquals(call.Input,input)&&Matches(state,input,expected["before"]),"actual viewport COM clamp/receiver "+cases);foreach(object mutationValue in Arr(plan["backendChanges"])){var m=Map(mutationValue);Write(state.BackendImage,U(m["offset"]),U(m["word"]));}foreach(object mutationValue in Arr(plan["sourceChanges"])){var m=Map(mutationValue);Write(input.Image,input.Offset+U(m["index"])*4,U(m["word"]));}foreach(object mutationValue in Arr(plan["argumentChanges"])){var m=Map(mutationValue);call.Arguments[U(m["index"])]=U(m["word"]);}var screen=Ints(plan["screenAfter"]);state.Screen[0]=screen[0];state.Screen[1]=screen[1];return U(plan["return"]);};uint result=Convert.ToBoolean(c["wrapper"])?ViewportCpuProduction.Global(state,Convert.ToBoolean(c["nonnull"])?input:null,service):ViewportCpuProduction.Apply(state,input,service);Check(Matches(state,input,c["native"]),"complete original viewport backend/source/screen "+cases);Check(result==U(c["nativeResult"]),"original raw last-word return "+cases);Check(at==events.Length,"all original viewport COM calls "+cases);++cases;
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Actual raw viewport forwarding/global wrapper, unsigned size clamp, post-COM original-source forward copy and raw last-word return. Device semantics and global backend lifetime supplied."}));return failures==0?0:1;
 }
}
