using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase920261013Verify
{
 static JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=200};
 static Dictionary<string,object> Obj(object o){return (Dictionary<string,object>)o;}
 static object[] Arr(object o){return (object[])o;}
 static uint U(object o){return Convert.ToUInt32(o);}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static byte[] Unhex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
 sealed class Memory:TakeoverReleaseMemory
 {
  public int HelperReads;readonly Dictionary<uint,byte> bytes=new Dictionary<uint,byte>();
  public Memory(object segments){foreach(object row in Arr(segments)){var r=Obj(row);uint p=U(r["address"]);byte[] b=Unhex((string)r["bytes"]);for(uint i=0;i<b.Length;i++)bytes[p+i]=b[i];}}
  public override byte Read8(uint p){if(p==0x10101039)HelperReads++;byte v;if(!bytes.TryGetValue(p,out v))throw new ArgumentException("Unmapped prepared read "+p.ToString("x"));return v;}
  public override void Write8(uint p,byte b){if(!bytes.ContainsKey(p))throw new ArgumentException("Unmapped prepared write "+p.ToString("x"));bytes[p]=b;}
  public string ReadHex(uint p,int n){byte[] b=new byte[n];for(int i=0;i<n;i++)b[i]=Read8(p+(uint)i);return Hex(b);}
  public void Ensure(uint p,int n){for(uint i=0;i<n;i++)if(!bytes.ContainsKey(p+i))bytes[p+i]=0;}
 }
 sealed class Recorder
 {
  public List<object> Events=new List<object>();public readonly Dictionary<string,object> Context;
  public Recorder(Dictionary<string,object> c){Context=c;}
  public uint Call(TakeoverReleaseMemory m,string name,params uint[] args)
  {
   Events.Add(new Dictionary<string,object>{{"name",name},{"args",args}});object patch;
   if(Context.TryGetValue("patches",out patch)){object rows;if(Obj(patch).TryGetValue(name,out rows))foreach(object row in Arr(rows)){object[] pair=Arr(row);m.Write32(U(pair[0]),U(pair[1]));}}
   if(name=="SelectTakeoverAnimation")TakeoverAnimationSelector.Select(m,args[0],args[1]);
   if(name=="ChangeTakenOverState"||name=="ChangeReleasedState"){object states,result;if(Context.TryGetValue("stateResults",out states)&&Obj(states).TryGetValue(args[0].ToString(),out result))return U(result);}return 0;
  }
 }
 sealed class TransferServices:TakeoverTransferServices
 {
  readonly Recorder r;public TransferServices(Recorder recorder){r=recorder;}
  public override void Rebind(TakeoverReleaseMemory m,uint a){r.Call(m,"Rebind",a);}
  public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return (int)r.Call(m,"ChangeTakenOverState",p,0x759958);}
  public override void RunScript(TakeoverReleaseMemory m,uint sys,uint a,uint p,uint dt){r.Call(m,"RunScript",sys,a,p,p,dt);}
  public override void ClearAction(TakeoverReleaseMemory m,uint a){r.Call(m,"ClearAction",a,0);}
  public override void ResetActor(TakeoverReleaseMemory m,uint a){r.Call(m,"ResetActor",a,0);}
  public override void StopActor(TakeoverReleaseMemory m,uint a){r.Call(m,"StopActor",a);}
  public override void ResetAnimation(TakeoverReleaseMemory m,uint p){r.Call(m,"ResetAnimation",p);}
  public override void PrepareActor(TakeoverReleaseMemory m,uint a){r.Call(m,"PrepareActor",a);}
  public override void SelectTakeoverAnimation(TakeoverReleaseMemory m,uint t,uint s){r.Call(m,"SelectTakeoverAnimation",t,s);}
  public override void Camera(TakeoverReleaseMemory m,uint camera,float duration){r.Call(m,"Camera",camera,TakeoverReleaseMemory.Bits(duration),0,1);}
 }
 sealed class ReleaseServices:TakeoverReleaseServices
 {
  readonly Recorder r;readonly TransferServices transfer;public ReleaseServices(Recorder recorder){r=recorder;transfer=new TransferServices(r);}
  public override int Transfer(TakeoverReleaseMemory m,uint a,uint b){return TakeoverTransfer.Transfer(m,transfer,a,b,false);}
  public override void Rebind(TakeoverReleaseMemory m,uint a){r.Call(m,"Rebind",a);}
  public override void RefreshPose(TakeoverReleaseMemory m,uint a){r.Call(m,"RefreshPose",a);}
  public override void Eject(TakeoverReleaseMemory m,uint a,uint b){r.Call(m,"Eject",a,b);}
  public override void VehicleResponse(TakeoverReleaseMemory m,uint a,uint b){r.Call(m,"VehicleResponse",a,b);}
  public override float DistanceFactor(TakeoverReleaseMemory m,uint a,uint b){r.Call(m,"DistanceFactor",a,b);object o;uint v=r.Context.TryGetValue("factorBits",out o)?U(o):TakeoverReleaseMemory.Bits(.375f);return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
  public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint target,float speed,float duration){r.Call(m,"DirectedJump",a,target,0,TakeoverReleaseMemory.Bits(speed),TakeoverReleaseMemory.Bits(duration),0);}
  public override void Camera(TakeoverReleaseMemory m,uint camera,float duration){r.Call(m,"Camera",camera,TakeoverReleaseMemory.Bits(duration),0,1);}
  public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return (int)r.Call(m,"ChangeReleasedState",p,0x759978);}
  public override void RunScript(TakeoverReleaseMemory m,uint sys,uint a,uint p,uint dt){r.Call(m,"RunScript",sys,a,p,p,dt);}
 }
 static int checks;static List<object> errors=new List<object>();
 static void Check(string name,object got,object want,int index){checks++;if(json.Serialize(got)!=json.Serialize(want))errors.Add(new Dictionary<string,object>{{"group",name},{"index",index},{"got",got},{"want",want}});}
 static string[] State(Memory m){return new string[]{m.ReadHex(0x10101000,0x1100),m.ReadHex(0x10104000,0x1100),m.ReadHex(0x10110000,0x1630),m.ReadHex(0x93d5f0,0x400),m.ReadHex(0x87a7c8,16)};}
 public static int Main(string[] args)
 {
  if(args.Length!=2)return 2;var fixture=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int i=0;
  foreach(object row in Arr(fixture["selectorCases"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);bool fault=false;try{TakeoverAnimationSelector.Select(memory,U(c["vehicle"]),U(c["rider"]));}catch(ArgumentException){fault=true;}int helperReads=memory.HelperReads;
   Check("selector-fault",fault,c["nativeFault"]!=null,i);Check("current-action-query-count",helperReads,c["currentActionCalls"],i);Check("selector-actor-state",new string[]{memory.ReadHex(0x10101000,0x1100),memory.ReadHex(0x10104000,0x1100)},c["nativeActors"],i);i++;}
  i=0;
  foreach(object row in Arr(fixture["cases"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);var recorder=new Recorder(Obj(c["context"]));bool fault=false;object ret=null;try{ret=TakeoverTransfer.Transfer(memory,new TransferServices(recorder),U(c["source"]),U(c["target"]),(bool)c["camera"]);}catch(ArgumentException){fault=true;}
   Check("mode1-fault",fault,c["nativeFault"]!=null,i);Check("mode1-return",ret,c["nativeReturn"],i);Check("mode1-state",State(memory),c["nativeState"],i);Check("mode1-service-order",recorder.Events,c["nativeEvents"],i);i++;}
  i=0;foreach(object row in Arr(fixture["interop"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);var recorder=new Recorder(Obj(c["context"]));bool fault=false;try{TakeoverRelease.Release(memory,new ReleaseServices(recorder),U(c["input"]));}catch(ArgumentException){fault=true;}
   Check("release-mode1-interoperation-fault",fault,c["nativeFault"]!=null,i);Check("release-mode1-interoperation-state",State(memory),c["nativeState"],i);Check("release-mode1-interoperation-order",recorder.Events,c["nativeEvents"],i);i++;}
  var report=new Dictionary<string,object>{{"binarySha256",fixture["binarySha256"]},{"checks",checks},{"mismatches",errors.Count},{"errors",errors},{"limitations",new string[]{"Retained original mode1/clear/reset and release interoperation fixtures; downstream script/animation/camera remain explicit services."}}};File.WriteAllText(args[1],json.Serialize(report));Console.WriteLine(json.Serialize(new{checks=checks,mismatches=errors.Count}));return errors.Count==0?0:1;
 }
}
