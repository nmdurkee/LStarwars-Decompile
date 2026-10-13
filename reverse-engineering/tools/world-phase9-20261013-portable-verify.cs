using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase920261013Verify {
 static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
 static object[] Arr(object v){return (object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int I(object v){return unchecked((int)U(v));}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IList x=a as IList,y=b as IList;if(x!=null&&y!=null){if(x.Count!=y.Count)return false;for(int i=0;i<x.Count;i++)if(!Equal(x[i],y[i]))return false;return true;}if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 static void Patch(SoundSetupImage m,object[] writes){foreach(object value in writes){var p=Obj(value);uint at=U(p["address"]);byte[] b=Convert.FromBase64String((string)p["data"]);for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}}
 static SoundSetupImage Setup(object[] regions,Dictionary<string,object> row){SoundSetupImage m=new SoundSetupImage();foreach(object v in regions){var r=Obj(v);byte[] b=new byte[Convert.ToInt32(r["length"])];for(int i=0;i<b.Length;i++)b[i]=167;m.Regions.Add(U(r["address"]),b);}Patch(m,Arr(row["writes"]));return m;}
 static string Hash(SoundSetupImage m,object[] regions){using(MemoryStream b=new MemoryStream()){foreach(object v in regions){var r=Obj(v);byte[] block=m.Regions[U(r["address"])];b.Write(block,0,block.Length);}using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(b.ToArray())).Replace("-","").ToLowerInvariant();}}
 sealed class Callbacks:IDispatchAllocationCallbacks {
  public Dictionary<string,object> Options;public readonly List<object> Trace=new List<object>();
  public uint Invoke(SoundSetupImage m,uint callback,uint world,uint descriptor,uint entry){int index=(int)((descriptor-0x10109000)/156);string key=index+":"+(callback==0x10200100?"count":"state");Dictionary<string,object> item=null;if(Options.ContainsKey("callbacks")){var items=Obj(Options["callbacks"]);if(items.ContainsKey(key))item=Obj(items[key]);}
   uint ret=item!=null&&item.ContainsKey("result")?U(item["result"]):callback==0x10200100?U(Arr(Options["counts"])[index]):0xb000u+(uint)index;uint registry=m.Word(0x93b268);
   Trace.Add(new object[]{callback,world,descriptor,entry,m.Word(0x10106000),m.Word(0x10106004),registry,m.Word(registry),ret});if(item!=null&&item.ContainsKey("writes"))Patch(m,Arr(item["writes"]));return ret;
  }
 }
 public static int Main(string[]args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;var data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));var regions=Arr(data["regions"]);int cases=0,checks=0,failures=0;List<object>errors=new List<object>();
  foreach(object value in Arr(data["cases"])){var row=Obj(value);var expected=Obj(row["expected"]);List<string>bad=new List<string>();try{SoundSetupImage m=Setup(regions,row);var raw=Arr(row["args"]);uint[]a=new uint[raw.Length];for(int i=0;i<a.Length;i++)a[i]=U(raw[i]);Callbacks cb=new Callbacks{Options=row};object result=null;string kind=(string)row["kind"];
   if(kind=="allocate")result=WorldRuntimeAllocation.Allocate16(m,a[0],a[1],a[2]);else if(kind=="pool")result=WorldRuntimeAllocation.CreatePool(m,a[0],a[1],a[2],unchecked((int)a[3]));else if(kind=="dispatch")result=WorldRuntimeAllocation.CreateDispatchState(m,a[0],a[1],a[2],cb);else for(int i=0;i<(row.ContainsKey("repeat")?Convert.ToInt32(row["repeat"]):1);i++)WorldRuntimeAllocation.ReleasePoolNode(m,a[0],a[1]);
   ++checks;if(Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete region image");++checks;if(!Equal(cb.Trace,expected["trace"]))bad.Add("mutable callback trace");if(kind!="release"){++checks;if(!Equal(result,expected["result"]))bad.Add("return bits");}
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
