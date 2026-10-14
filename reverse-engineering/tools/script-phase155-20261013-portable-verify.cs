using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase15520261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}


 sealed class Services:ScriptFlushServices
 {
  readonly Dictionary<string,object> c;readonly List<object> events;const uint Error=0x10100500,BufferPointer=0x10100300;public Services(Dictionary<string,object> config,List<object> log){c=config;events=log;}
  uint Value(string key,uint fallback){object v;return c.TryGetValue(key,out v)?U(v):fallback;}
  void Event(TakeoverReleaseMemory m,uint callback,uint[] args){var row=new Dictionary<string,object>{{"callback",callback},{"args",args}};if(callback==0x6f6461){byte[] bytes=new byte[args[2]];for(uint i=0;i<args[2];i++)bytes[i]=m.Read8(args[1]+i);row["bytes"]=bytes;}events.Add(row);}
  void Patch(TakeoverReleaseMemory m,uint callback){object all,value;if(c.TryGetValue("patches",out all)&&O(all).TryGetValue("0x"+callback.ToString("x"),out value))foreach(object item in A(value)){object[] p=A(item);uint address=U(p[0]),word=U(p[2]);for(uint i=0;i<U(p[1]);i++)m.Write8(address+i,(byte)(word>>(int)(i*8)));}}
  public override uint Errno(TakeoverReleaseMemory m){Event(m,0x6ead5f,new uint[0]);uint result=Value("errnoPointer",Error);Patch(m,0x6ead5f);return result;}
  public override void Invalid(TakeoverReleaseMemory m){Event(m,0x6e9fc2,new uint[5]);Patch(m,0x6e9fc2);}
  public override uint StandardStreams(TakeoverReleaseMemory m){Event(m,0x6e81d7,new uint[0]);uint result=Value("iob",0x10101000);Patch(m,0x6e81d7);return result;}
  public override uint IsTerminal(TakeoverReleaseMemory m,uint descriptor){Event(m,0x701ce5,new uint[]{descriptor});uint result=Value("terminal",0);Patch(m,0x701ce5);return result;}
  public override void Buffer(TakeoverReleaseMemory m,uint file){Event(m,0x701ca1,new uint[]{file});m.Write32(file+8,BufferPointer);m.Write32(file,BufferPointer);m.Write32(file+0x18,Value("bufferSize",4));m.Write32(file+12,m.Read32(file+12)|8);Patch(m,0x701ca1);}
  public override uint Write(TakeoverReleaseMemory m,uint descriptor,uint bytes,uint count){Event(m,0x6f6461,new uint[]{descriptor,bytes,count});uint result=Value("written",count);Patch(m,0x6f6461);return result;}
  public override ulong Seek(TakeoverReleaseMemory m,uint descriptor,uint low,uint high,uint origin){Event(m,0x701b88,new uint[]{descriptor,low,high,origin});object value;ulong result=c.TryGetValue("seekResult",out value)?Convert.ToUInt64(value):0;Patch(m,0x701b88);return result;}
 }
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase155-20261013-native-fixtures.json"))));int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);var events=new List<object>();var c=O(row["context"]);uint result=0;bool fault=false;try{var service=new Services(c,events);result=(string)input["method"]=="FileNo"?PreparedScriptFileFlush.FileNumber(m,service,U(input["file"])):PreparedScriptFileFlush.Flush(m,service,U(input["characterSlot"]),U(input["fileSlot"]));}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["initial"]),events.ToArray()},b={row["fault"],row["returnValue"],row["final"],row["nativeEvents"]};for(int i=0;i<4;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Sprintf wrapper mismatch group "+i);}}Console.WriteLine(checks+" sprintf wrapper comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
