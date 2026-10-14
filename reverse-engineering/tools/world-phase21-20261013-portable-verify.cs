using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class World21Support {
 public static void Patch(SoundSetupImage m,object[] writes){foreach(object v in writes){var p=World19Support.Obj(v);uint at=World19Support.U(p["address"]);byte[] b=Convert.FromBase64String((string)p["data"]);for(int i=0;i<b.Length;i++)m.Byte(at+(uint)i,b[i]);}}
 public class Timer {
  public Dictionary<string,object> Row;public List<object> Trace=new List<object>();
  bool Flag(string key){return Row.ContainsKey(key)&&(bool)Row[key];}
  public uint Call(SoundSetupImage m,uint address,uint[] a){if(address!=0x655c30)throw new InvalidOperationException("unexpected port "+address.ToString("x"));uint p=a[0],time=a[1];Trace.Add(new uint[]{p,time,m.Word(0x29620a4),m.Word(0x10100800)});uint target=p;
   if(Flag("retarget")){m.Word(0x29620a4,0x10114000);target=unchecked(0x10114000+p-0x10108000);}m.Word(target+0x1e4,Row.ContainsKey("duration")?World19Support.U(Row["duration"]):0x40a00000);
   if(Flag("swapRecord"))m.Word(0x10101004,0x10104000);
   if(Flag("mutateRecord")){m.Byte(0x1010302c,128);m.Byte(0x1010302d,255);m.Byte(0x1010302e,7);m.Byte(0x101032f1,4);m.Word(0x101033e0,0);m.Word(0x101033e4,4);}
   if(Flag("mutateClock")){m.Word(0x296205c,0x42a00000);m.Word(0x2962060,0x42b40000);}if(Flag("invalidate"))m.Word(0x10100800,0xffffffff);if(Flag("swapId"))m.Word(0x10100800,7);return 0xdeadbeef;
  }
 }
}
public class WorldPhase2120261013Verify {
 public static int Main(string[] args){var json=new JavaScriptSerializer();json.MaxJsonLength=256*1024*1024;var data=World19Support.Obj(json.DeserializeObject(World19Support.Input(args[0])));var regions=World19Support.Arr(data["regions"]);int cases=0,checks=0,failures=0;var errors=new List<object>();
  foreach(object v in World19Support.Arr(data["cases"])){var row=World19Support.Obj(v);var expected=World19Support.Obj(row["expected"]);var bad=new List<string>();try{
   var m=World19Support.Setup(regions,new Dictionary<string,object>{{"writes",data["commonWrites"]}});World21Support.Patch(m,World19Support.Arr(row["writes"]));string kind=(string)row["kind"];var timer=new World21Support.Timer{Row=row};uint result=0;
   if(kind=="allocate")result=PtlEmitterConstruction.Allocate(m);
   else if(kind=="position"){var x=World19Support.Arr(row["xyz"]);PtlEmitterConstruction.Position(m,World19Support.U(row["id"]),World19Support.U(x[0]),World19Support.U(x[1]),World19Support.U(x[2]));}
   else if(kind=="fields"){var a=World19Support.Arr(row["args"]);PtlEmitterConstruction.Fields(m,World19Support.U(row["id"]),World19Support.U(a[0]),World19Support.U(a[1]),World19Support.U(a[2]),World19Support.U(a[3]));}
   else if(kind=="schedule")PtlEmitterConstruction.Schedule(m,World19Support.U(row["id"]),World19Support.U(row["time"]),timer.Call);
   else{var x=World19Support.Arr(row["xyz"]);PtlEmitterConstruction.Create(m,0x10100800,World19Support.U(row["physical"]),World19Support.U(x[0]),World19Support.U(x[1]),World19Support.U(x[2]),timer.Call);}
   ++checks;if(World19Support.Hash(m,regions)!=(string)expected["sha256"])bad.Add("complete constructor image");++checks;if(!World19Support.Equal(timer.Trace,expected["trace"]))bad.Add("timing calls");++checks;if(m.Word(0x10100800)!=World19Support.U(expected["output"]))bad.Add("published ID");++checks;if(kind=="allocate"?result!=World19Support.U(expected["result"]):expected["result"]!=null)bad.Add("allocator return");
  }catch(Exception e){bad.Add(e.ToString());}if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;}
  string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
 }
}
