using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase1320261013Verify
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
 sealed class Recorder
 {
  public readonly List<object> Events=new List<object>();readonly Dictionary<string,object> c;readonly Dictionary<string,int> counts=new Dictionary<string,int>();
  public Recorder(Dictionary<string,object> context){c=context;}
  object Peek(TakeoverReleaseMemory m)
  {
   var actors=new List<object>();foreach(uint a in new uint[]{0x10101000,0x10104000})actors.Add(new Dictionary<string,object>{{"link",m.Read32(a+0xcd0)},{"context",m.Read8(a+0x7b5)},{"animation",m.Read16(a+0x7aa)},{"flags1fc",m.Read32(a+0x1fc)},{"flags1f8",m.Read32(a+0x1f8)},{"packetWord",m.Read32(a+0x2c8)},{"set",m.Read8(a+0x378)},{"xBits",m.Read32(a+0x5c)},{"yBits",m.Read32(a+0x60)},{"zBits",m.Read32(a+0x64)},{"velocityXBits",m.Read32(a+0x68)},{"velocityYBits",m.Read32(a+0x6c)},{"velocityZBits",m.Read32(a+0x70)},{"bottomBits",m.Read32(a+0x1a0)},{"input",m.Read32(a+0xca4)}});
   return new Dictionary<string,object>{{"rng",m.Read32(0x80253c)},{"actors",actors}};
  }
  void Patches(TakeoverReleaseMemory m,string key)
  {object patch,rows;if(c.TryGetValue("patches",out patch)&&Obj(patch).TryGetValue(key,out rows))foreach(object row in Arr(rows)){object[] pair=Arr(row);m.Write32(U(pair[0]),U(pair[1]));}}
  public uint Call(TakeoverReleaseMemory m,string name,params uint[] args)
  {
   int ordinal;counts.TryGetValue(name,out ordinal);counts[name]=++ordinal;Events.Add(new Dictionary<string,object>{{"name",name},{"args",args},{"observed",Peek(m)}});Patches(m,name);Patches(m,name+"#"+ordinal);
   object states,result;if((name=="ChangeTakenOverState"||name=="ChangeReleasedState")&&c.TryGetValue("stateResults",out states)&&Obj(states).TryGetValue(args[0].ToString(),out result))return U(result);return 0;
  }
  public float Factor{get{object value;uint bits=c.TryGetValue("factorBits",out value)?U(value):TakeoverReleaseMemory.Bits(.375f);return BitConverter.ToSingle(BitConverter.GetBytes(bits),0);}}
 }
 sealed class Ports:TakeoverPipelinePorts
 {
  readonly Recorder r;public Ports(Recorder recorder){r=recorder;}
  public override void Rebind(TakeoverReleaseMemory m,uint a){r.Call(m,"Rebind",a);}
  public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return unchecked((int)r.Call(m,"ChangeTakenOverState",p,0x759958));}
  public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return unchecked((int)r.Call(m,"ChangeReleasedState",p,0x759978));}
  public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint dt){r.Call(m,"RunScript",s,a,p,p,dt);}
  public override void ClearAction(TakeoverReleaseMemory m,uint a){r.Call(m,"ClearAction",a,0);}
  public override void ResetActor(TakeoverReleaseMemory m,uint a){r.Call(m,"ResetActor",a,0);}
  public override void StopActor(TakeoverReleaseMemory m,uint a){r.Call(m,"StopActor",a);}
  public override void ResetAnimation(TakeoverReleaseMemory m,uint p){r.Call(m,"ResetAnimation",p);}
  public override void PrepareActor(TakeoverReleaseMemory m,uint a){r.Call(m,"PrepareActor",a);}
  public override void VehicleResponse(TakeoverReleaseMemory m,uint b,uint a){r.Call(m,"VehicleResponse",b,a);}
  public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){r.Call(m,"DistanceFactor",p,t);return r.Factor;}
  public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float speed,float duration){r.Call(m,"DirectedJump",a,t,0,TakeoverReleaseMemory.Bits(speed),TakeoverReleaseMemory.Bits(duration),0);}
  public override void Camera(TakeoverReleaseMemory m,uint c,float duration){r.Call(m,"Camera",c,TakeoverReleaseMemory.Bits(duration),0,1);}
 }
 sealed class Audio:JumpContextAudio
 {
  readonly Recorder r;public Audio(Recorder recorder){r=recorder;}
  public override void PlayerSound(TakeoverReleaseMemory m,int id,uint p){r.Call(m,"PlayerSound",unchecked((uint)id),p);}
  public override void WorldSound(TakeoverReleaseMemory m,int id,uint p,float v){r.Call(m,"WorldSound",unchecked((uint)id),p,TakeoverReleaseMemory.Bits(v));}
 }
 static int checks;static List<object> errors=new List<object>();
 static void Check(string name,object got,object want,int index){checks++;if(json.Serialize(got)!=json.Serialize(want))errors.Add(new Dictionary<string,object>{{"group",name},{"index",index},{"got",got},{"want",want}});}
 static string[] State(Memory m){return new string[]{m.ReadHex(0x10101000,0x1100),m.ReadHex(0x10104000,0x1100),m.ReadHex(0x1010b000,0x100),m.ReadHex(0x1010c000,0x100),m.ReadHex(0x1010f000,0x100),m.ReadHex(0x10109000,0x400),m.ReadHex(0x10120000,0x1630),m.ReadHex(0x93d5f0,0x400),m.ReadHex(0x87a7c8,16),m.ReadHex(0x80253c,4)};}
 public static int Main(string[] args)
 {
  if(args.Length!=2)return 2;var fixture=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in Arr(fixture["cases"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);var recorder=new Recorder(Obj(c["context"]));var pipeline=new RecoveredTakeoverPipeline(new Ports(recorder),new Audio(recorder));bool fault=false;
   for(int call=0;call<Convert.ToInt32(c["calls"]);call++){try{pipeline.Release(memory,U(c["input"]));}catch(ArgumentException){fault=true;break;}}
   Check("pipeline-fault",fault,c["nativeFault"]!=null,index);Check("pipeline-full-state",State(memory),c["nativeState"],index);Check("pipeline-callback-order-and-alias",recorder.Events,c["nativeEvents"],index);index++;}
  var report=new Dictionary<string,object>{{"binarySha256",fixture["binarySha256"]},{"checks",checks},{"mismatches",errors.Count},{"errors",errors},{"limitations",new string[]{"Actual recovered release/transfer/selector/bounds/ejection composition; remaining script/actor cleanup/vehicle response/special jump/camera/audio ports explicit."}}};File.WriteAllText(args[1],json.Serialize(report));Console.WriteLine(json.Serialize(new{checks=checks,mismatches=errors.Count}));return errors.Count==0?0:1;
 }
}
