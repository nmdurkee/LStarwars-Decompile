using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase1120261013Verify
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
 sealed class Audio:JumpContextAudio
 {
  public readonly List<object> Events=new List<object>();readonly Dictionary<string,object> context;
  public Audio(Dictionary<string,object> c){context=c;}
  void Call(TakeoverReleaseMemory m,string name,params uint[] args)
  {
   uint a=args[1]-0x19c;var observed=new Dictionary<string,object>{{"velocityXBits",m.Read32(a+0x68)},{"velocityZBits",m.Read32(a+0x70)},{"rng",m.Read32(0x80253c)},{"context",m.Read8(a+0x7b5)},{"animation",m.Read16(a+0x7aa)},{"flags7bc",m.Read32(a+0x7bc)},{"input",m.Read32(a+0xca4)}};
   Events.Add(new Dictionary<string,object>{{"name",name},{"args",args},{"observed",observed}});object patches,rows;if(context.TryGetValue("patches",out patches)&&Obj(patches).TryGetValue(name,out rows))foreach(object row in Arr(rows)){object[] pair=Arr(row);m.Write32(U(pair[0]),U(pair[1]));}
  }
  public override void PlayerSound(TakeoverReleaseMemory m,int sound,uint p){Call(m,"PlayerSound",unchecked((uint)sound),p);}
  public override void WorldSound(TakeoverReleaseMemory m,int sound,uint p,float volume){Call(m,"WorldSound",unchecked((uint)sound),p,TakeoverReleaseMemory.Bits(volume));}
 }
 static int checks;static List<object> errors=new List<object>();
 static void Check(string name,object got,object want,int index){checks++;if(json.Serialize(got)!=json.Serialize(want))errors.Add(new Dictionary<string,object>{{"group",name},{"index",index},{"got",got},{"want",want}});}
 static string[] State(Memory m){return new string[]{m.ReadHex(0x10101000,0x1100),m.ReadHex(0x10104000,0x1100),m.ReadHex(0x1010b000,0x100),m.ReadHex(0x1010c000,0x100),m.ReadHex(0x10109000,0x400),m.ReadHex(0x80253c,4)};}
 public static int Main(string[] args)
 {
  if(args.Length!=2)return 2;var fixture=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int i=0;
  foreach(object row in Arr(fixture["cases"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);var audio=new Audio(Obj(c["context"]));bool fault=false;
   for(int call=0;call<Convert.ToInt32(c["calls"]);call++){try{VehicleEjection.Eject(memory,audio,U(c["rider"]),U(c["vehicle"]));}catch(ArgumentException){fault=true;break;}}
   Check("ejection-fault",fault,c["nativeFault"]!=null,i);Check("ejection-state",State(memory),c["nativeState"],i);Check("audio-temporary-velocity-rng",audio.Events,c["nativeEvents"],i);i++;}
  var speedMemory=new Memory(fixture["speedInitial"]);var method=typeof(VehicleEjection).GetMethod("Speed",System.Reflection.BindingFlags.Static|System.Reflection.BindingFlags.NonPublic);if(method==null)throw new InvalidOperationException("Missing actual ejection speed stage.");i=0;
  foreach(object row in Arr(fixture["speedCases"]))
  {var c=Obj(row);float value=(float)method.Invoke(null,new object[]{speedMemory,U(c["speedDraw"])});Check("exhaustive-original-speed-stage",TakeoverReleaseMemory.Bits(value),c["nativeSpeedBits"],i++);}
  var report=new Dictionary<string,object>{{"binarySha256",fixture["binarySha256"]},{"checks",checks},{"mismatches",errors.Count},{"errors",errors},{"limitations",new string[]{"Original ejection/helper full-state fixtures plus every16-bit speed stage; terminal audio is explicit. Prefix uses actual private speed stage, not separate duplicate arithmetic."}}};File.WriteAllText(args[1],json.Serialize(report));Console.WriteLine(json.Serialize(new{checks=checks,mismatches=errors.Count}));return errors.Count==0?0:1;
 }
}
