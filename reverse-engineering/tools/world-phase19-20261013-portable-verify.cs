using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class World19Support {
 public static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
 public static object[] Arr(object v){return (object[])v;}
 public static uint U(object v){return Convert.ToUInt32(v);}
 public static int I(object v){return Convert.ToInt32(v);}
 public static bool Equal(object a,object b){if(a==null||b==null)return a==b;IDictionary x=a as IDictionary,y=b as IDictionary;if(x!=null&&y!=null){if(x.Count!=y.Count)return false;foreach(object k in x.Keys)if(!y.Contains(k)||!Equal(x[k],y[k]))return false;return true;}IList p=a as IList,q=b as IList;if(p!=null&&q!=null){if(p.Count!=q.Count)return false;for(int i=0;i<p.Count;i++)if(!Equal(p[i],q[i]))return false;return true;}if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
 public static bool Yes(Dictionary<string,object> row,string key){return row.ContainsKey(key)&&Convert.ToBoolean(row[key]);}
 public static string Input(string file){if(!file.EndsWith(".gz"))return File.ReadAllText(file);using(FileStream f=File.OpenRead(file))using(GZipStream g=new GZipStream(f,CompressionMode.Decompress))using(StreamReader r=new StreamReader(g))return r.ReadToEnd();}
 public static SoundSetupImage Setup(object[] regions,Dictionary<string,object> row){SoundSetupImage m=new SoundSetupImage();foreach(object v in regions){var r=Obj(v);byte[] b=new byte[I(r["length"])];for(int i=0;i<b.Length;i++)b[i]=(byte)I(r["fill"]);m.Regions.Add(U(r["address"]),b);}foreach(object v in Arr(row["writes"])){var p=Obj(v);uint at=U(p["address"]);byte[] b=Convert.FromBase64String((string)p["data"]);for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}return m;}
 public static string Hash(SoundSetupImage m,object[] regions){using(MemoryStream b=new MemoryStream()){foreach(object v in regions){uint at=U(Obj(v)["address"]);int length=I(Obj(v)["length"]);byte[] block;if(m.Regions.TryGetValue(at,out block)&&block.Length==length)b.Write(block,0,length);else for(int i=0;i<length;i++)b.WriteByte(m.Byte(at+(uint)i));}using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(b.ToArray())).Replace("-","").ToLowerInvariant();}}
 public sealed class Assets:IParRecordBindings {
  readonly ParLoadedAssetBindings loaded;public readonly List<object> Lookups=new List<object>();
  public Assets(SoundSetupImage m){loaded=new ParLoadedAssetBindings(m);}
  public int Sprite(byte[] name,uint scene){return loaded.Sprite(name,scene);}
  public uint Effect(byte[] name,uint bank,bool fast){if(!fast)Lookups.Add(new object[]{Convert.ToBase64String(name),bank,0});return loaded.Effect(name,bank,fast);}
  public uint Sound(byte[] name,int bound){return loaded.Sound(name,bound);}
 }
 public sealed class Ports {
  public Dictionary<string,object> Options;public readonly List<object> Trace=new List<object>();bool hasMarker;uint marker;
  static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
  public uint Call(SoundSetupImage m,uint address,uint[] args){unchecked{
   if(address==0x684ee0){marker=args[0];hasMarker=true;}
   Trace.Add(new object[]{address,(uint[])args.Clone(),m.Word(0x29620a4),hasMarker?(object)m.Word(marker):null});uint result=0xdeadbeef;
   if(address==0x684ee0)m.Word(marker,Yes(Options,"fail")||args[1]==0xffffffff?0xffffffff:Options.ContainsKey("spawnId")?U(Options["spawnId"]):1u);
   if(address==0x5d92b0){m.Word(args[1],Bits(17));m.Word(args[1]+4,Bits(18));m.Word(args[1]+8,Bits(19));result=Options.ContainsKey("queryResult")?U(Options["queryResult"]):0x12340000;}
   if(Options.ContainsKey("stage")&&address==U(Options["stage"])){
    if(Yes(Options,"retarget"))m.Word(0x29620a4,0x1010c000);
    if(hasMarker){if(Yes(Options,"invalidate"))m.Word(marker,0xffffffff);else if(Yes(Options,"swapId"))m.Word(marker,2);uint at=marker-16;
     if(Yes(Options,"mutateFields")){m.Word(at+0x34,Bits(7));m.Word(at+0x38,Bits(8));m.Word(at+0x3c,Bits(9));m.Word(at+0x44,Bits(10));m.Word(at+0x48,Bits(11));m.Half(at+0x40,0xfedc);m.Half(at+0x42,0x8abc);}
     if(Options.ContainsKey("mutateBank"))m.Byte(at+0x51,(byte)U(Options["mutateBank"]));
    }
   }
   if(Yes(Options,"alias")&&address==0x684720)m.Word(marker,1);return result;
  }}
 }
 public sealed class Transport:ISplineFileTransport {
  public byte[] Payload;int position;
  public int Open(SoundSetupImage m,uint path,uint mode,uint archive,uint flags){position=0;return 1;}
  public int Read(SoundSetupImage m,uint handle,uint destination,int count){int take=Math.Max(0,Math.Min(Math.Min(count,4096),Payload.Length-position));for(int i=0;i<take;i++)m.Byte(destination+(uint)i,Payload[position+i]);position+=take;return take;}
  public void Close(SoundSetupImage m,uint handle){}
 }
}
public class WorldPhase1920261013Verify {
 public static int Main(string[] args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=World19Support.Obj(json.DeserializeObject(World19Support.Input(args[0])));var regions=World19Support.Arr(data["regions"]);int cases=0,checks=0,failures=0;List<object> errors=new List<object>();
  foreach(object v in World19Support.Arr(data["cases"])){var row=World19Support.Obj(v);var expected=World19Support.Obj(row["expected"]);List<string> bad=new List<string>();try{
   SoundSetupImage m=World19Support.Setup(regions,row);var assets=new World19Support.Assets(m);var ports=new World19Support.Ports{Options=row};
   if((string)row["kind"]=="activate")PtlDeclarationActivation.Activate(m,assets,ports.Call);else PtlDeclarationActivation.Attach(m,World19Support.U(row["id"]),World19Support.U(row["scene"]),ports.Call);
   ++checks;if(World19Support.Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete retained image");++checks;if(!World19Support.Equal(ports.Trace,expected["trace"]))bad.Add("mutable child service trace");++checks;if(!World19Support.Equal(assets.Lookups,expected["lookups"]))bad.Add("actual general lookup requests");++checks;if(m.Word(PtlEmitterRuntime.Selected)!=World19Support.U(expected["selected"]))bad.Add("nearest selection");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string result=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],result);Console.WriteLine(result);return failures==0?0:1;
 }
}
public class WorldPhase1920261013ComposedVerify {
 public static int Main(string[] args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=World19Support.Obj(json.DeserializeObject(World19Support.Input(args[0])));var regions=World19Support.Arr(data["regions"]);var publicationRegions=World19Support.Arr(data["publicationRegions"]);int cases=0,checks=0,failures=0;List<object> errors=new List<object>();
  foreach(object v in World19Support.Arr(data["cases"])){var row=World19Support.Obj(v);var expected=World19Support.Obj(row["expected"]);List<string> bad=new List<string>();try{
   SoundSetupImage m=World19Support.Setup(regions,row);m.Regions.Add(0x101f0000,new byte[1064]);var assets=new World19Support.Assets(m);var ports=new World19Support.Ports{Options=new Dictionary<string,object>()};var file=new World19Support.Transport{Payload=Convert.FromBase64String((string)row["payload"])};var services=new PtlRecoveredEmitterServices(delegate(SoundSetupImage image,uint at){});
   uint result=PtlInstancePublication.Load(m,0x10105000,World19Support.U(row["mode"]),World19Support.U(row["scene"]),0x101f0000,file,assets,services);string publicationHash=World19Support.Hash(m,publicationRegions);
   ++checks;if(result!=World19Support.U(expected["publicationResult"]))bad.Add("publication return");++checks;if(publicationHash!=(string)expected["publicationSha256"])bad.Add("publication table image");++checks;if(publicationHash!=(string)row["phase18Sha256"])bad.Add("phase18 producer identity");
   PtlDeclarationActivation.Activate(m,assets,ports.Call);
   ++checks;if(World19Support.Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete activation image");++checks;if(!World19Support.Equal(ports.Trace,expected["trace"]))bad.Add("activation child services");++checks;if(!World19Support.Equal(assets.Lookups,expected["lookups"]))bad.Add("actual general lookup requests");++checks;if(m.Word(PtlEmitterRuntime.Selected)!=World19Support.U(expected["selected"]))bad.Add("nearest selection");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string resultText=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],resultText);Console.WriteLine(resultText);return failures==0?0:1;
 }
}
