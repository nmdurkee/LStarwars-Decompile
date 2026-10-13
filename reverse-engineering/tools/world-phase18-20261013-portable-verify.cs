using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase1820261013Verify {
 static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
 static object[] Arr(object v){return (object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int I(object v){return Convert.ToInt32(v);}
 static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary x=a as IDictionary,y=b as IDictionary;if(x!=null&&y!=null){if(x.Count!=y.Count)return false;foreach(object k in x.Keys)if(!y.Contains(k)||!Equal(x[k],y[k]))return false;return true;}IList p=a as IList,q=b as IList;if(p!=null&&q!=null){if(p.Count!=q.Count)return false;for(int i=0;i<p.Count;i++)if(!Equal(p[i],q[i]))return false;return true;}if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 static SoundSetupImage Setup(object[] regions,Dictionary<string,object> row){SoundSetupImage m=new SoundSetupImage();foreach(object v in regions){var r=Obj(v);byte[] b=new byte[I(r["length"])];for(int i=0;i<b.Length;i++)b[i]=(byte)I(r["fill"]);m.Regions.Add(U(r["address"]),b);}foreach(object v in Arr(row["writes"])){var p=Obj(v);uint at=U(p["address"]);byte[] b=Convert.FromBase64String((string)p["data"]);for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}m.Regions.Add(0x101f0000,new byte[1064]);return m;}
 static string Digest(byte[] bytes){using(SHA256 h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(bytes)).Replace("-","").ToLowerInvariant();}
 static string Hash(SoundSetupImage m,object[] regions){using(MemoryStream b=new MemoryStream()){foreach(object v in regions){byte[] block=m.Regions[U(Obj(v)["address"])];b.Write(block,0,block.Length);}return Digest(b.ToArray());}}
 static string Text(SoundSetupImage m,uint at){string s="";for(byte v=m.Byte(at);v!=0;v=m.Byte(++at))s+=(char)v;return s;}
 sealed class Transport:ISplineFileTransport {
  public Dictionary<string,object> Options;public byte[] Payload;public int Position,Opens,Reads,Closes;public readonly List<object> Trace=new List<object>();
  public int Open(SoundSetupImage m,uint path,uint mode,uint archive,uint flags){Opens++;Trace.Add(new object[]{"open",Text(m,path),mode,archive,flags});Position=0;return unchecked((int)(Options.ContainsKey("openResult")?U(Options["openResult"]):1u));}
  public int Read(SoundSetupImage m,uint handle,uint destination,int count){Reads++;int take=Math.Max(0,Math.Min(Math.Min(count,Payload.Length-Position),Options.ContainsKey("readLimit")?I(Options["readLimit"]):4096));for(int i=0;i<take;i++)m.Byte(destination+(uint)i,Payload[Position+i]);Trace.Add(new object[]{"read",handle,destination,count,Position,take});Position+=take;return take;}
  public void Close(SoundSetupImage m,uint handle){Closes++;Trace.Add(new object[]{"close",handle});}
  public object State(){return new Dictionary<string,object>{{"filePosition",Position},{"opens",Opens},{"reads",Reads},{"closes",Closes}};}
 }
 sealed class Assets:IParRecordBindings {
  public readonly ParLoadedAssetBindings Loaded;public readonly MemoryStream Bytes=new MemoryStream();public readonly List<object> Effects=new List<object>();public int Calls;
  public Assets(SoundSetupImage m){Loaded=new ParLoadedAssetBindings(m);}
  public int Sprite(byte[] name,uint scene){return Loaded.Sprite(name,scene);}
  public uint Effect(byte[] name,uint bank,bool fast){Effects.Add(new object[]{Convert.ToBase64String(name),bank});return Loaded.Effect(name,bank,fast);}
  public uint Sound(byte[] name,int bound){Calls++;byte[] bytes=BitConverter.GetBytes(0x650e40u);Bytes.Write(bytes,0,4);Bytes.Write(name,0,16);bytes=BitConverter.GetBytes((uint)bound);Bytes.Write(bytes,0,4);return Loaded.Sound(name,bound);}
  public string Hash(){return Digest(Bytes.ToArray());}
 }
 sealed class Services:IPtlRecordServices {
  public readonly List<object> Events=new List<object>(),Allocations=new List<object>();
  void Allocate(SoundSetupImage m,uint at){Allocations.Add(new object[]{at,m.Half(at+0x18c),m.Half(at+0x18e),m.Half(at+0x180)});}
  public void Normalize(SoundSetupImage m,uint record){Events.Add(new object[]{"normalize",record});PtlEmitterRuntime.Normalize(m,record,Allocate);}
  public void Select(SoundSetupImage m,uint bits){Events.Add(new object[]{"select",bits});PtlEmitterRuntime.Select(m,BitConverter.ToSingle(BitConverter.GetBytes(bits),0));}
 }
 static string Input(string file){if(!file.EndsWith(".gz"))return File.ReadAllText(file);using(FileStream f=File.OpenRead(file))using(GZipStream g=new GZipStream(f,CompressionMode.Decompress))using(StreamReader r=new StreamReader(g))return r.ReadToEnd();}
 public static int Main(string[] args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=Obj(json.DeserializeObject(Input(args[0])));var regions=Arr(data["regions"]);int cases=0,checks=0,failures=0;List<object> errors=new List<object>();
  foreach(object value in Arr(data["cases"])){var row=Obj(value);var expected=Obj(row["expected"]);List<string> bad=new List<string>();try{
   SoundSetupImage m=Setup(regions,row);Transport t=new Transport{Options=row,Payload=Convert.FromBase64String((string)row["payload"])};Assets assets=new Assets(m);Services services=new Services();uint result=PtlInstancePublication.Load(m,0x10105000,U(row["mode"]),U(row["scene"]),0x101f0000,t,assets,services);
   ++checks;if(result!=U(expected["result"]))bad.Add("bank return");++checks;if(Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete retained image");++checks;if(!Equal(services.Events,expected["services"]))bad.Add("normalization/selection trace");++checks;if(!Equal(services.Allocations,expected["allocations"]))bad.Add("allocation trace");++checks;if(!Equal(assets.Effects,expected["effects"]))bad.Add("fast particle lookup requests");++checks;if(assets.Hash()!=(string)expected["audioSha256"])bad.Add("audio argument hash");++checks;if(assets.Calls!=I(expected["audioCalls"]))bad.Add("audio count");++checks;if(!Equal(t.Trace,expected["trace"]))bad.Add("file trace");++checks;if(!Equal(t.State(),expected["state"]))bad.Add("file state");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
