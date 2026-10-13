using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase1220261013Verify
{
 static JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=200};
 static Dictionary<string,object> Obj(object o){return (Dictionary<string,object>)o;}
 static object[] Arr(object o){return (object[])o;}
 static uint U(object o){return Convert.ToUInt32(o);}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
 sealed class Memory:TakeoverReleaseMemory
 {
  readonly Dictionary<uint,byte> bytes=new Dictionary<uint,byte>();
  public Memory(object segments){foreach(object row in Arr(segments)){var r=Obj(row);uint p=U(r["address"]);byte[] b=Unhex((string)r["bytes"]);for(uint i=0;i<b.Length;i++)bytes[p+i]=b[i];}}
  public override byte Read8(uint p){byte v;if(!bytes.TryGetValue(p,out v))throw new ArgumentException("Unmapped prepared read "+p.ToString("x"));return v;}
  public override void Write8(uint p,byte b){if(!bytes.ContainsKey(p))throw new ArgumentException("Unmapped prepared write "+p.ToString("x"));bytes[p]=b;}
  public string ReadHex(uint p,int n){byte[] b=new byte[n];for(int i=0;i<n;i++)b[i]=Read8(p+(uint)i);return Hex(b);}
  public void Ensure(uint p,int n){for(uint i=0;i<n;i++)if(!bytes.ContainsKey(p+i))bytes[p+i]=0;}
 }
 static int checks;static List<object> errors=new List<object>();
 static void Check(string name,object got,object want,int index){checks++;if(json.Serialize(got)!=json.Serialize(want))errors.Add(new Dictionary<string,object>{{"group",name},{"index",index},{"got",got},{"want",want}});}
 static string[] External(Memory m){return new string[]{m.ReadHex(0x10102000,0x100),m.ReadHex(0x10103000,0x100),m.ReadHex(0x10104000,0x200),m.ReadHex(0x10106000,0x1000)};}
 public static int Main(string[] args)
 {
  if(args.Length!=2)return 2;var fixture=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int i=0;
  foreach(object row in Arr(fixture["cases"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);string[] beforeExternal=External(memory);bool fault=false;
   try{PreparedCharacterBounds.Refresh(memory,U(c["actor"]));}catch(ArgumentException){fault=true;}
   Check("pose-hydration-fault",fault,c["nativeFault"]!=null,i);Check("pose-state-before-fault",memory.ReadHex(0x10100000,0x10d8),c["nativeActor"],i);Check("pose-external-confinement",External(memory),beforeExternal,i);i++;}
  var report=new Dictionary<string,object>{{"binarySha256",fixture["binarySha256"]},{"checks",checks},{"mismatches",errors.Count},{"errors",errors},{"limitations",new string[]{"Original pose hydration and numeric state before early/late faults; reuses existing CharacterPredictedBounds.Update."}}};File.WriteAllText(args[1],json.Serialize(report));Console.WriteLine(json.Serialize(new{checks=checks,mismatches=errors.Count}));return errors.Count==0?0:1;
 }
}
