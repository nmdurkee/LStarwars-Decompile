using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase15320261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}


 sealed class Services:ScriptPrintfServices
 {
  readonly Dictionary<string,object> c;readonly List<object> events;int ordinal;const uint Error=0x10100700;public Services(Dictionary<string,object> config,List<object> log){c=config;events=log;}
  uint Value(string key,uint fallback){object v;return c.TryGetValue(key,out v)?U(v):fallback;}
  public override uint Output(TakeoverReleaseMemory m,uint file,uint format,uint locale,uint arguments){throw new InvalidOperationException("Unprepared output parser.");}
  public override void Invalid(TakeoverReleaseMemory m,uint expression,uint function,uint source,uint line,uint reserved){throw new InvalidOperationException("Unprepared invalid dispatch.");}
  public override uint Errno(TakeoverReleaseMemory m){events.Add(new Dictionary<string,object>{{"callback",0x6ead5fu},{"args",new uint[0]},{"errno",m.Read32(Error)}});return Value("errnoPointer",Error);}
  public override uint Flush(TakeoverReleaseMemory m,uint value,uint file){ordinal++;events.Add(new Dictionary<string,object>{{"callback",0x6eecd9u},{"args",new uint[]{value,file}}});m.Write32(Error,Value("errorValue",21));object all;if(!c.TryGetValue("flushResults",out all))return 0xffffffff;object[] values=A(all);return U(values[Math.Min(ordinal-1,values.Length-1)]);}
 }
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase153-20261013-native-fixtures.json"))));int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);var events=new List<object>();var c=O(row["context"]);uint result=0;bool fault=false;try{var service=new Services(c,events);string method=(string)input["method"];uint counter=U(input["counter"]),file=U(input["file"]);result=method=="Byte"?PreparedScriptPrintfOutput.Byte(m,service,file,counter,U(input["character"])):method=="Repeat"?PreparedScriptPrintfOutput.Repeat(m,service,counter,U(input["characterSlot"]),U(input["countSlot"]),U(input["fileSlot"])):PreparedScriptPrintfOutput.Span(m,service,counter,U(input["source"]),file,U(input["countSlot"]));}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["initial"]),events.ToArray()},b={row["fault"],row["returnValue"],row["final"],row["nativeEvents"]};for(int i=0;i<4;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Sprintf wrapper mismatch group "+i);}}Console.WriteLine(checks+" sprintf wrapper comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
