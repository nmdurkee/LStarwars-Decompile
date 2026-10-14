using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase16720261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}



 sealed class LocaleServicesImpl:ScriptLocaleUpdateServices
 {readonly Services s;public LocaleServicesImpl(Services service){s=service;}public override uint Thread(TakeoverReleaseMemory m){return s.Port(m,0x6f040c,new uint[0]);}public override uint Locale(TakeoverReleaseMemory m){return s.Port(m,0x6fae25,new uint[0]);}public override uint Multibyte(TakeoverReleaseMemory m){return s.Port(m,0x6fa67a,new uint[0]);}}
 sealed class Services:ScriptFormattingServices
 {
  readonly Dictionary<string,object> c;readonly List<object> events;readonly LocaleServicesImpl locale;public Services(Dictionary<string,object> config,List<object> log){c=config;events=log;locale=new LocaleServicesImpl(this);}public override ScriptLocaleUpdateServices LocaleServices{get{return locale;}}
  uint Value(string key,uint fallback){object x;return c.TryGetValue(key,out x)?U(x):fallback;}bool Flag(string key){object x;return c.TryGetValue(key,out x)&&(bool)x;}
  public uint Port(TakeoverReleaseMemory m,uint address,uint[] args)
  {
   var e=new Dictionary<string,object>{{"callback",address},{"args",args}};if(address==0x6ead5f)e["errno"]=m.Read32(0x10103900);if(address==0x10200a00)e["value"]=(ulong)m.Read32(args[0])|((ulong)m.Read32(args[0]+4)<<32);if(address==0x10200c00){uint[] header=new uint[8];for(uint i=0;i<8;i++)header[i]=m.Read32(args[0]+i*4);e["header"]=header;}events.Add(e);if(address==0x10200c00){m.Write32(args[0]+4,Value("probeCount",0x12345678));return Value("probeReturn",0xfedcba98);}
   if(address==0x6f040c)return 0x10103800;if(address==0x6fae25)return 0x10103200;if(address==0x6fa67a)return 0x10103400;if(address==0x6ead5f)return 0x10103900;if(address==0x6e9fc2)return 0;
   if(address==0x6eecd9){m.Write32(0x10103900,Value("errorValue",21));return Value("flushReturn",0xffffffff);}if(address==0x6e7a93)return Value("nEnabled",1);if(address==0x10200b10)return Value("lastError",21);if(address==0x10200b00){object x;byte[] payload=Unhex(c.TryGetValue("widePayload",out x)?(string)x:"c3a9");m.Write32(args[7],Value("usedDefault",0));if(args[4]!=0&&Value("winCount",2)!=0)for(int i=0;i<payload.Length&&(uint)i<args[5];i++)m.Write8(args[4]+(uint)i,payload[i]);return Value("winCount",2);}if(address==0x6f01bc)return args[0];if(address==0x6f076f)return Flag("allocationFail")?0u:0x10104000u;if(address==0x6e7633)return 0;
   if(address==0x701ea2){uint result=args[0],buffer=args[1],character=args[3];if(character==0xffff){m.Write32(result,0);return 42;}uint count=character==0?0u:character<128?1u:2u;m.Write32(result,count);if(count==1)m.Write8(buffer,(byte)character);if(count==2){m.Write8(buffer,(byte)(0xc0|((character>>6)&31)));m.Write8(buffer+1,(byte)(0x80|(character&63)));}return 0;}
   if(address==0x10200a00){object x;string text=c.TryGetValue("floating",out x)?(string)x:"-12.500";for(int i=0;i<text.Length;i++)m.Write8(args[1]+(uint)i,(byte)text[i]);m.Write8(args[1]+(uint)text.Length,0);return 0;}if(address==0x10200a10||address==0x10200a20)return 0;throw new InvalidOperationException("Unknown port");
  }
  public override uint Output(TakeoverReleaseMemory m,uint f,uint fmt,uint l,uint a){throw new InvalidOperationException("Recursive output");}
  public override uint Errno(TakeoverReleaseMemory m){return Port(m,0x6ead5f,new uint[0]);}public override void Invalid(TakeoverReleaseMemory m,uint a,uint b,uint c,uint d,uint e){Port(m,0x6e9fc2,new uint[]{a,b,c,d,e});}public override uint Flush(TakeoverReleaseMemory m,uint v,uint f){return Port(m,0x6eecd9,new uint[]{v,f});}
  public override uint Wide(TakeoverReleaseMemory m,uint result,uint buffer,uint capacity,ushort character){return Port(m,0x701ea2,new uint[]{result,buffer,capacity,character});}
  public override uint Decode(TakeoverReleaseMemory m,uint encoded){return Port(m,0x6f01bc,new uint[]{encoded});}
  public override void Floating(TakeoverReleaseMemory m,uint f,uint value,uint buffer,uint capacity,int type,int precision,uint capitals,uint locale){Port(m,f,new uint[]{value,buffer,capacity,unchecked((uint)type),unchecked((uint)precision),capitals,locale});}
  public override void Alter(TakeoverReleaseMemory m,uint f,uint buffer,uint locale){Port(m,f,new uint[]{buffer,locale});}public override uint Allocate(TakeoverReleaseMemory m,uint cap){return Port(m,0x6f076f,new uint[]{cap});}public override void Release(TakeoverReleaseMemory m,uint buffer){Port(m,0x6e7633,new uint[]{buffer});}public override uint CountEnabled(TakeoverReleaseMemory m){return Port(m,0x6e7a93,new uint[0]);}
 }

 sealed class WideServices:ScriptWideCharacterServices
 {
  readonly Services s;public WideServices(Dictionary<string,object> c,List<object> e){s=new Services(c,e);}
  public override uint Thread(TakeoverReleaseMemory m){return s.Port(m,0x6f040c,new uint[0]);}public override uint Locale(TakeoverReleaseMemory m){return s.Port(m,0x6fae25,new uint[0]);}public override uint Multibyte(TakeoverReleaseMemory m){return s.Port(m,0x6fa67a,new uint[0]);}public override uint Errno(TakeoverReleaseMemory m){return s.Errno(m);}public override void Invalid(TakeoverReleaseMemory m){s.Invalid(m,0,0,0,0,0);}public override void Fill(TakeoverReleaseMemory m,uint b,uint c){PtlRuntimeMemory.Fill(((Memory)m).Image,b,0,c);}public override uint Windows(TakeoverReleaseMemory m,uint page,uint flags,uint character,uint characters,uint buffer,uint capacity,uint def,uint used){return s.Port(m,0x10200b00,new uint[]{page,flags,character,characters,buffer,capacity,def,used});}public override uint LastError(TakeoverReleaseMemory m){return s.Port(m,0x10200b10,new uint[0]);}
 }

 sealed class CountInvocation:ScriptCountFormatServices
 {
  readonly Services raw;readonly ScriptFormattingServices formatting;readonly uint frame;public CountInvocation(Dictionary<string,object> c,List<object> e,uint f){raw=new Services(c,e);formatting=new RecoveredScriptWideFormattingServices(new RecoveredScriptCountFormattingServices(raw),new WideServices(c,e),f);frame=f;}
  public override uint Errno(TakeoverReleaseMemory m){return raw.Errno(m);}public override void Invalid(TakeoverReleaseMemory m){raw.Invalid(m,0,0,0,0,0);}public override uint Invoke(TakeoverReleaseMemory m,uint function,uint file,uint format,uint locale,uint args){if(function==0x6eef05)return new RecoveredScriptCountParserServices(formatting,frame).Invoke(m,function,file,format,locale,args);return raw.Port(m,function,new uint[]{file,format,locale,args});}
 }
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase167-20261013-native-fixtures.json"))));int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);var events=new List<object>();var c=O(row["context"]);uint result=0;bool fault=false;try{result=PreparedScriptCountFormatting.Execute(m,new CountInvocation(c,events,U(input["frame"])),U(input["function"]),U(input["format"]),U(input["locale"]),U(input["arguments"]),U(input["file"]));}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["final"]),events.ToArray()},b={row["fault"],row["returnValue"],row["final"],row["nativeEvents"]};for(int i=0;i<4;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Formatting mismatch group "+i);}}Console.WriteLine(checks+" formatting comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
