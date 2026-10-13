using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase1720261013Verify {
 static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
 static object[] Arr(object v){return (object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int I(object v){return Convert.ToInt32(v);}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary x=a as IDictionary,y=b as IDictionary;if(x!=null&&y!=null){if(x.Count!=y.Count)return false;foreach(object k in x.Keys)if(!y.Contains(k)||!Equal(x[k],y[k]))return false;return true;}IList p=a as IList,q=b as IList;if(p!=null&&q!=null){if(p.Count!=q.Count)return false;for(int i=0;i<p.Count;i++)if(!Equal(p[i],q[i]))return false;return true;}if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 static SoundSetupImage Setup(object[] regions,Dictionary<string,object> row){SoundSetupImage m=new SoundSetupImage();foreach(object v in regions){var r=Obj(v);byte[] b=new byte[I(r["length"])];for(int i=0;i<b.Length;i++)b[i]=(byte)I(r["fill"]);m.Regions.Add(U(r["address"]),b);}foreach(object v in Arr(row["writes"])){var p=Obj(v);uint at=U(p["address"]);byte[] b=Convert.FromBase64String((string)p["data"]);for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}return m;}
 static string Hash(SoundSetupImage m,object[] regions){using(MemoryStream b=new MemoryStream()){foreach(object v in regions){byte[] block=m.Regions[U(Obj(v)["address"])];b.Write(block,0,block.Length);}using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(b.ToArray())).Replace("-","").ToLowerInvariant();}}
 public static int Main(string[] args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;var data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));var regions=Arr(data["regions"]);int cases=0,checks=0,failures=0;List<object> errors=new List<object>();
  foreach(object value in Arr(data["cases"])){var row=Obj(value);var expected=Obj(row["expected"]);List<string> bad=new List<string>();try{
   SoundSetupImage m=Setup(regions,row);List<object> trace=new List<object>();Action<SoundSetupImage,uint> allocate=delegate(SoundSetupImage image,uint at){trace.Add(new object[]{at,image.Half(at+0x18c),image.Half(at+0x18e),image.Half(at+0x180)});if(row.ContainsKey("mutate")&&Convert.ToBoolean(row["mutate"])&&trace.Count==1){image.Word(0x29620a4,0x10114000);image.Half(0x10101014,0xfff1);image.Word(PtlEmitterRuntime.Instances+511*0x58+16,2);}};
   string kind=(string)row["kind"];if(kind=="normalize")PtlEmitterRuntime.Normalize(m,0x10101000,allocate);else if(kind=="count")PtlEmitterRuntime.SetCount(m,U(row["emitter"]),unchecked((int)U(row["count"])),allocate);else PtlEmitterRuntime.Select(m,BitConverter.ToSingle(BitConverter.GetBytes(U(row["threshold"])),0));
   ++checks;if(Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete retained image");++checks;if(!Equal(trace,expected["trace"]))bad.Add("allocation callback trace");++checks;if(m.Half(0x10101014)!=U(expected["count"]))bad.Add("normalized count");++checks;if(m.Word(PtlEmitterRuntime.Selected)!=U(expected["selected"]))bad.Add("selected row");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
