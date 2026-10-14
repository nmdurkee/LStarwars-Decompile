using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase15720261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}


 sealed class Services:ScriptInvalidParameterServices
 {
  readonly Dictionary<string,object> c;readonly List<object> events;public Services(Dictionary<string,object> config,List<object> log){c=config;events=log;}
  uint Value(string key,uint fallback){object value;return c.TryGetValue(key,out value)?U(value):fallback;}
  uint Port(TakeoverReleaseMemory m,uint callback,uint[] args,uint result){events.Add(new Dictionary<string,object>{{"callback",callback},{"args",args}});object all,value;if(c.TryGetValue("patches",out all)&&O(all).TryGetValue("0x"+callback.ToString("x"),out value))foreach(object item in A(value)){object[] p=A(item);uint address=U(p[0]),word=U(p[2]);for(uint i=0;i<U(p[1]);i++)m.Write8(address+i,(byte)(word>>(int)(i*8)));}return result;}
  static uint[] Arguments(TakeoverReleaseMemory m,uint pointer){uint[] words=new uint[5];for(uint i=0;i<5;i++)words[i]=m.Read32(pointer+i*4);return words;}
  public override uint Decode(TakeoverReleaseMemory m,uint encoded){return Port(m,0x6f01bc,new uint[]{encoded},Value("handler",0x10200c00));}
  public override uint Handler(TakeoverReleaseMemory m,uint callback,uint arguments){return Port(m,callback,Arguments(m,arguments),Value("result",0x12345678));}
  public override void Report(TakeoverReleaseMemory m,uint reason){Port(m,0x6f8568,new uint[]{reason},Value("reportResult",0));}
  public override uint Fatal(TakeoverReleaseMemory m,uint arguments){return Port(m,0x6e9e8e,Arguments(m,arguments),Value("result",0x12345678));}
 }
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase157-20261013-native-fixtures.json"))));int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);var events=new List<object>();var c=O(row["context"]);uint result=0;bool fault=false;try{result=PreparedScriptInvalidParameter.Dispatch(m,new Services(c,events),U(input["arguments"]));}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["initial"]),events.ToArray()},b={row["fault"],row["returnValue"],row["final"],row["nativeEvents"]};for(int i=0;i<4;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Sprintf wrapper mismatch group "+i);}}Console.WriteLine(checks+" sprintf wrapper comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
