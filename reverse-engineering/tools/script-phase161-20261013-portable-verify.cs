using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase16120261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}



 sealed class Services:ScriptWideCharacterServices
 {
  readonly Dictionary<string,object> c;readonly List<object> events;readonly uint win,last;readonly Dictionary<uint,int> calls=new Dictionary<uint,int>();public Services(Dictionary<string,object> config,List<object> log,uint wide,uint error){c=config;events=log;win=wide;last=error;}
  uint Value(string k,uint d){object x;return c.TryGetValue(k,out x)?U(x):d;}
  uint Port(TakeoverReleaseMemory m,uint address,uint[] args){events.Add(new Dictionary<string,object>{{"callback",address},{"args",args}});if(!calls.ContainsKey(address))calls[address]=0;calls[address]++;object all,patch;if(c.TryGetValue("patches",out all)&&O(all).TryGetValue("0x"+address.ToString("x"),out patch))foreach(object item in A(patch)){object[] p=A(item);uint a=U(p[0]),z=U(p[1]),v=U(p[2]);for(uint i=0;i<z;i++)m.Write8(a+i,(byte)(v>>(int)(8*i)));}
   if(address==0x6f040c)return 0x10100e00;if(address==0x6fae25)return 0x10100a00;if(address==0x6fa67a)return 0x10100c00;if(address==0x6ead5f){object x;return c.TryGetValue("alternateErrno",out x)&&(bool)x&&calls[address]>1?0x10100f10u:0x10100f00u;}if(address==0x6e9fc2)return 0;if(address==last)return Value("lastError",21);
   if(address==win){m.Write32(args[7],Value("usedDefault",0));object x;byte[] payload=Unhex(c.TryGetValue("payload",out x)?(string)x:"c3a9");if(args[4]!=0&&Value("winCount",2)!=0)for(int i=0;i<payload.Length&&(uint)i<args[5];i++)m.Write8(args[4]+(uint)i,payload[i]);return Value("winCount",2);}throw new InvalidOperationException("Unknown port");
  }
  public override uint Thread(TakeoverReleaseMemory m){return Port(m,0x6f040c,new uint[0]);}public override uint Locale(TakeoverReleaseMemory m){return Port(m,0x6fae25,new uint[0]);}public override uint Multibyte(TakeoverReleaseMemory m){return Port(m,0x6fa67a,new uint[0]);}public override uint Errno(TakeoverReleaseMemory m){return Port(m,0x6ead5f,new uint[0]);}public override void Invalid(TakeoverReleaseMemory m){Port(m,0x6e9fc2,new uint[5]);}
  public override void Fill(TakeoverReleaseMemory m,uint buffer,uint capacity){PtlRuntimeMemory.Fill(((Memory)m).Image,buffer,0,capacity);}
  public override uint Windows(TakeoverReleaseMemory m,uint page,uint flags,uint character,uint characters,uint buffer,uint capacity,uint def,uint used){return Port(m,win,new uint[]{page,flags,character,characters,buffer,capacity,def,used});}public override uint LastError(TakeoverReleaseMemory m){return Port(m,last,new uint[0]);}
 }
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase161-20261013-native-fixtures.json"))));var info=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase161-20261013-tests.json"))));var imports=O(info["imports"]);int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);var events=new List<object>();var c=O(row["context"]);uint result=0;bool fault=false;try{var services=new Services(c,events,U(imports["wide"]),U(imports["lastError"]));result=(bool)input["wrapper"]?PreparedScriptWideCharacter.Standard(m,services,U(input["caller"]),U(input["child"]),U(input["context"])):PreparedScriptWideCharacter.Local(m,services,U(input["child"]),U(input["context"]));}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["final"]),events.ToArray()},b={row["fault"],row["returnValue"],row["final"],row["nativeEvents"]};for(int i=0;i<4;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Wide conversion mismatch group "+i);}}Console.WriteLine(checks+" wide conversion comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
