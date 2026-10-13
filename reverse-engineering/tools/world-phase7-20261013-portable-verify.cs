using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase720261013Verify {
 static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
 static object[] Arr(object v){return (object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int I(object v){return Convert.ToInt32(v);}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary x=a as IDictionary,y=b as IDictionary;if(x!=null&&y!=null){if(x.Count!=y.Count)return false;foreach(object k in x.Keys)if(!y.Contains(k)||!Equal(x[k],y[k]))return false;return true;}IList p=a as IList,q=b as IList;if(p!=null&&q!=null){if(p.Count!=q.Count)return false;for(int i=0;i<p.Count;i++)if(!Equal(p[i],q[i]))return false;return true;}if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 static void Patch(SoundSetupImage m,object[] writes){foreach(object v in writes){var p=Obj(v);uint at=U(p["address"]);byte[] b=Convert.FromBase64String((string)p["data"]);for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}}
 static SoundSetupImage Setup(object[] regions,Dictionary<string,object> row){SoundSetupImage m=new SoundSetupImage();foreach(object v in regions){var r=Obj(v);byte[] b=new byte[I(r["length"])];for(int i=0;i<b.Length;i++)b[i]=167;m.Regions.Add(U(r["address"]),b);}Patch(m,Arr(row["writes"]));return m;}
 static string Hash(SoundSetupImage m,object[] regions){using(MemoryStream b=new MemoryStream()){foreach(object v in regions){byte[] block=m.Regions[U(Obj(v)["address"])];b.Write(block,0,block.Length);}using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(b.ToArray())).Replace("-","").ToLowerInvariant();}}
 static string Text(SoundSetupImage m,uint at){string s="";for(byte v=m.Byte(at);v!=0;v=m.Byte(++at))s+=(char)v;return s;}
 sealed class Transport:ISplineFileTransport {
  public Dictionary<string,object> Options;public byte[] Payload;public int Position,Opens,Reads,Closes;public readonly List<object> Trace=new List<object>();
  public int Open(SoundSetupImage m,uint path,uint mode,uint archive,uint flags){Opens++;Trace.Add(new object[]{"open",Text(m,path),mode,archive,flags});Position=0;return unchecked((int)U(Options["openResult"]));}
  public int Read(SoundSetupImage m,uint handle,uint destination,int count){Reads++;int take=Math.Max(0,Math.Min(Math.Min(count,Payload.Length-Position),Options.ContainsKey("readLimit")?I(Options["readLimit"]):4096));for(int i=0;i<take;i++)m.Byte(destination+(uint)i,Payload[Position+i]);Trace.Add(new object[]{"read",handle,destination,count,Position,take});Position+=take;return take;}
  public void Close(SoundSetupImage m,uint handle){Closes++;Trace.Add(new object[]{"close",handle});}
  public object State(){return new Dictionary<string,object>{{"filePosition",Position},{"opens",Opens},{"reads",Reads},{"closes",Closes}};}
 }
 public static int Main(string[]args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;var data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));var regions=Arr(data["regions"]);int cases=0,checks=0,failures=0;List<object>errors=new List<object>();
  foreach(object value in Arr(data["cases"])){var row=Obj(value);var expected=Obj(row["expected"]);List<string>bad=new List<string>();try{
   SoundSetupImage m=Setup(regions,row);Transport t=new Transport{Options=row,Payload=Convert.FromBase64String((string)row["payload"]),Position=row.ContainsKey("initialFilePosition")?I(row["initialFilePosition"]):0};string kind=(string)row["kind"];object result=null;
   if(kind=="load")result=SplineResourceLoading.Load(m,0x10105000,0x10106000,0x10106004,t);else{object[]a=Arr(row["args"]);SplineResourceLoading.Read(m,U(a[0]),U(a[1]),t);}
   ++checks;if(Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete region image");++checks;if(!Equal(t.Trace,expected["trace"]))bad.Add("transport trace");++checks;if(!Equal(t.State(),expected["state"]))bad.Add("transport state");if(kind=="load"){++checks;if(!Equal(result,expected["result"]))bad.Add("return bits");}
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
