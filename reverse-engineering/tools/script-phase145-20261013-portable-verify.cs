using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase14520261013Verify
{
 static Dictionary<string,object> O(object x){return (Dictionary<string,object>)x;}static object[] A(object x){return (object[])x;}static uint U(object x){return Convert.ToUInt32(x);}static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 sealed class Memory:TakeoverReleaseMemory
 {public readonly SoundSetupImage Image=new SoundSetupImage();public readonly ConditionParserMemory Shared;public Memory(object rows){foreach(object item in A(rows)){var r=O(item);Image.Regions[U(r["address"])]=Unhex((string)r["bytes"]);}Shared=new ConditionParserMemory(Image);}public override byte Read8(uint p){return Image.Byte(p);}public override void Write8(uint p,byte b){Image.Byte(p,b);}public object State(object rows){var result=new List<object>();foreach(object item in A(rows)){var r=O(item);uint p=U(r["address"]);int z=((string)r["bytes"]).Length/2;byte[] b=new byte[z];for(int i=0;i<z;i++)b[i]=Read8(p+(uint)i);result.Add(new Dictionary<string,object>{{"address",p},{"bytes",Hex(b)}});}return result.ToArray();}}


 sealed class Symbols:ScriptExpressionServices{public override uint Symbol(TakeoverReleaseMemory m,uint callback,uint creature,uint packet,string name,out uint value){value=0;throw new InvalidOperationException("Unprepared symbol callback.");}}
 sealed class Intent:ScriptFollowServices{public override void Schedule(TakeoverReleaseMemory m,uint callback){throw new InvalidOperationException("Unprepared formation scheduler.");}}
 static uint Call(Memory m,uint address,Dictionary<string,object> i){uint s=U(i["system"]),p=U(i["packet"]),a=U(i["actor"]),args=U(i["args"]),f=U(i["first"]);int c=Convert.ToInt32(i["count"]);var token=new RecoveredScriptMovementTokens(null);return address==0x535fc0?PreparedNullableScriptNodeActions.Go(m,new Intent(),token,new Symbols(),s,p,a,args,c,f):PreparedNullableScriptNodeActions.Away(m,new Intent(),token,new Symbols(),s,p,a,args,c,f);}
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase145-20261013-native-fixtures.json"))));int checks=0;foreach(object item in A(data["cases"])){var row=O(item);var input=O(row["inputs"]);var m=new Memory(row["initial"]);uint result=0;bool fault=false;try{result=Call(m,U(row["address"]),input);}catch(Exception){fault=true;result=0;}object[] a={fault,result,m.State(row["initial"])},b={row["fault"],row["returnValue"],row["final"]};for(int i=0;i<3;i++){checks++;if(!Equal(a[i],b[i]))throw new InvalidOperationException("Node action mismatch group "+i);}}Console.WriteLine(checks+" node action comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
