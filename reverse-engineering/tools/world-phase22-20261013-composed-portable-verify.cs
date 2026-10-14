using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase2220261013ComposedVerify {
 sealed class Ports {
  public uint Marker;public bool HasMarker;public List<object> Trace=new List<object>();
  public uint Call(SoundSetupImage m,uint address,uint[] a){Trace.Add(new object[]{address,(uint[])a.Clone(),m.Word(0x29620a4),HasMarker?(object)m.Word(Marker):null});if(address==0x655c30){PtlEmitterTiming.Schedule(m,a[0],a[1]);return 0;}if(address==0x5d92b0){m.Word(a[1],0x41880000);m.Word(a[1]+4,0x41900000);m.Word(a[1]+8,0x41980000);return 0x12340000;}throw new InvalidOperationException(address.ToString("x"));}
 }
 public static int Main(string[] args){var json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=World19Support.Obj(json.DeserializeObject(World19Support.Input(args[0])));var regions=World19Support.Arr(data["regions"]);var publicationRegions=World19Support.Arr(data["publicationRegions"]);int cases=0,checks=0,failures=0;var errors=new List<object>();
  foreach(object v in World19Support.Arr(data["cases"])){var row=World19Support.Obj(v);var expected=World19Support.Obj(row["expected"]);var bad=new List<string>();try{
   var m=World19Support.Setup(regions,row);m.Regions.Add(0x101f0000,new byte[1064]);var assets=new World19Support.Assets(m);var ports=new Ports();var file=new World19Support.Transport{Payload=Convert.FromBase64String((string)row["payload"])};var services=new PtlRecoveredEmitterServices(delegate(SoundSetupImage image,uint at){});
   PtlInstancePublication.Load(m,0x10105000,World19Support.U(row["mode"]),World19Support.U(row["scene"]),0x101f0000,file,assets,services);++checks;if(World19Support.Hash(m,publicationRegions)!=(string)row["phase18Sha256"])bad.Add("authenticated publication image");World21Support.Patch(m,World19Support.Arr(row["constructionWrites"]));
   Func<SoundSetupImage,uint,uint[],uint> recovered=delegate(SoundSetupImage image,uint address,uint[] a){if(address==0x684ee0){ports.Marker=a[0];ports.HasMarker=true;}return PtlEmitterConstruction.Invoke(image,address,a,ports.Call);};PtlDeclarationActivation.Activate(m,assets,recovered);
   ++checks;if(World19Support.Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete construction/activation image");++checks;if(!World19Support.Equal(ports.Trace,expected["trace"]))bad.Add("remaining timer/query calls");++checks;if(!World19Support.Equal(assets.Lookups,expected["lookups"]))bad.Add("general lookup requests");++checks;if(m.Word(PtlEmitterRuntime.Selected)!=World19Support.U(expected["selected"]))bad.Add("nearest selection");++checks;if(m.Word(0x29211e8)!=World19Support.U(expected["allocationCursor"]))bad.Add("allocator exhaustion");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
