using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase17020261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}



 sealed class Services:ScriptCtypeServices
 {
  readonly Dictionary<string,object> c;readonly List<object> events;public Services(Dictionary<string,object> config,List<object> log){c=config;events=log;}
  uint Port(TakeoverReleaseMemory m,uint address,uint character,uint locale){events.Add(new Dictionary<string,object>{{"callback",address},{"args",new uint[]{character,locale}}});object x;if(c.TryGetValue("patches",out x))foreach(object item in A(x)){object[] p=A(item);uint a=U(p[0]),z=U(p[1]),v=U(p[2]);for(uint i=0;i<z;i++)m.Write8(a+i,(byte)(v>>(int)(i*8)));}return c.TryGetValue("childReturn",out x)?U(x):0xfedcba98;}
  public override uint LocaleLower(TakeoverReleaseMemory m,uint c,uint locale){return Port(m,0x70138e,c,locale);}public override uint LocaleDigit(TakeoverReleaseMemory m,uint c,uint locale){return Port(m,0x700f21,c,locale);}
 }
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase170-20261013-native-fixtures.json"))));int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);var events=new List<object>();var services=new Services(O(row["context"]),events);uint result=0;bool fault=false;try{result=(string)input["method"]=="Lower"?PreparedScriptCtype.Lower(m,services,U(input["character"])):PreparedScriptCtype.Digit(m,services,U(input["character"]));}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["final"]),events.ToArray()},b={row["fault"],row["returnValue"],row["final"],row["nativeEvents"]};for(int i=0;i<4;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Ctype mismatch group "+i);}}Console.WriteLine(checks+" ctype comparisons passed.");return 0;}public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
