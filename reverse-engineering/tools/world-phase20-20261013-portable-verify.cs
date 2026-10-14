using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase2020261013Verify {
 static void Patch(SoundSetupImage m,object[] writes){foreach(object v in writes){var p=World19Support.Obj(v);uint at=World19Support.U(p["address"]);byte[] bytes=Convert.FromBase64String((string)p["data"]);for(int i=0;i<bytes.Length;i++)m.Byte(at+(uint)i,bytes[i]);}}
 public static int Main(string[] args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=World19Support.Obj(json.DeserializeObject(World19Support.Input(args[0])));var regions=World19Support.Arr(data["regions"]);int cases=0,checks=0,failures=0;List<object> errors=new List<object>();
  foreach(object v in World19Support.Arr(data["cases"])){var row=World19Support.Obj(v);var expected=World19Support.Obj(row["expected"]);List<string> bad=new List<string>();try{
   SoundSetupImage m=World19Support.Setup(regions,new Dictionary<string,object>{{"writes",data["commonWrites"]}});Patch(m,World19Support.Arr(row["writes"]));string kind=(string)row["kind"];
   if(kind=="copy")PtlEmitterOrientation.Copy(m,World19Support.U(row["dest"]),World19Support.U(row["src"]));
   else if(kind=="rotate"){int axis=World19Support.I(row["axis"]);uint p=World19Support.U(row["ptr"]);int angle=unchecked((int)World19Support.U(row["angle"]));if(axis==0)PtlEmitterOrientation.RotateX(m,p,angle);else if(axis==1)PtlEmitterOrientation.RotateY(m,p,angle);else PtlEmitterOrientation.RotateZ(m,p,angle);}
   else{object[] angles=World19Support.Arr(row["angles"]);uint id=World19Support.U(row["id"]),first=World19Support.U(angles[0]),second=World19Support.U(angles[1]);if(kind=="primary")PtlEmitterOrientation.Primary(m,id,first,second);else if(kind=="secondary")PtlEmitterOrientation.Secondary(m,id,first,second,World19Support.U(angles[2]));else PtlEmitterOrientation.Mode(m,id,World19Support.U(row["mode"]),first,second);}
   ++checks;if(World19Support.Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete orientation/matrix image");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
public class WorldPhase2020261013ComposedVerify {
 public static int Main(string[] args){JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=World19Support.Obj(json.DeserializeObject(World19Support.Input(args[0])));var regions=World19Support.Arr(data["regions"]);var publicationRegions=World19Support.Arr(data["publicationRegions"]);int cases=0,checks=0,failures=0;List<object> errors=new List<object>();
  foreach(object v in World19Support.Arr(data["cases"])){var row=World19Support.Obj(v);var expected=World19Support.Obj(row["expected"]);List<string> bad=new List<string>();try{
   SoundSetupImage m=World19Support.Setup(regions,row);m.Regions.Add(0x101f0000,new byte[1064]);var assets=new World19Support.Assets(m);var ports=new World19Support.Ports{Options=new Dictionary<string,object>()};var file=new World19Support.Transport{Payload=Convert.FromBase64String((string)row["payload"])};var services=new PtlRecoveredEmitterServices(delegate(SoundSetupImage image,uint at){});
   PtlInstancePublication.Load(m,0x10105000,World19Support.U(row["mode"]),World19Support.U(row["scene"]),0x101f0000,file,assets,services);
   ++checks;if(World19Support.Hash(m,publicationRegions)!=(string)row["phase18Sha256"])bad.Add("authenticated producer image");
   Func<SoundSetupImage,uint,uint[],uint> recovered=delegate(SoundSetupImage image,uint address,uint[] callArgs){uint result=ports.Call(image,address,callArgs);return PtlEmitterOrientation.Invoke(image,address,callArgs,delegate(SoundSetupImage x,uint y,uint[] z){return result;});};
   PtlDeclarationActivation.Activate(m,assets,recovered);
   ++checks;if(World19Support.Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete activated image");++checks;if(!World19Support.Equal(ports.Trace,expected["trace"]))bad.Add("remaining child service trace");++checks;if(!World19Support.Equal(assets.Lookups,expected["lookups"]))bad.Add("actual general lookup requests");++checks;if(m.Word(PtlEmitterRuntime.Selected)!=World19Support.U(expected["selected"]))bad.Add("nearest selection");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
