using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase720261013Verify
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
 sealed class Services:TakeoverReleaseServices
 {
  public List<object> Events=new List<object>();readonly Dictionary<string,object> context;
  public Services(Dictionary<string,object> c){context=c;}
  uint Call(TakeoverReleaseMemory m,string name,params uint[] args)
  {
   Events.Add(new Dictionary<string,object>{{"name",name},{"args",args}});
   object patch;if(context.TryGetValue("patches",out patch)){object rows;if(Obj(patch).TryGetValue(name,out rows))foreach(object row in Arr(rows)){object[] pair=Arr(row);m.Write32(U(pair[0]),U(pair[1]));}}
   object value;if(name=="Transfer")return context.TryGetValue("transferResult",out value)?U(value):1;
   if(name=="ChangeReleasedState"&&context.TryGetValue("stateResults",out value)){object result;if(Obj(value).TryGetValue(args[0].ToString(),out result))return U(result);}return 0;
  }
  public override int Transfer(TakeoverReleaseMemory m,uint a,uint b){return (int)Call(m,"Transfer",a,b,1,0,0);}
  public override void Rebind(TakeoverReleaseMemory m,uint a){Call(m,"Rebind",a);}
  public override void RefreshPose(TakeoverReleaseMemory m,uint a){Call(m,"RefreshPose",a);}
  public override void Eject(TakeoverReleaseMemory m,uint a,uint b){Call(m,"Eject",a,b);}
  public override void VehicleResponse(TakeoverReleaseMemory m,uint a,uint b){Call(m,"VehicleResponse",a,b);}
  public override float DistanceFactor(TakeoverReleaseMemory m,uint a,uint b){Call(m,"DistanceFactor",a,b);object o;uint v=context.TryGetValue("factorBits",out o)?U(o):TakeoverReleaseMemory.Bits(.375f);return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
  public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint target,float speed,float duration){Call(m,"DirectedJump",a,target,0,TakeoverReleaseMemory.Bits(speed),TakeoverReleaseMemory.Bits(duration),0);}
  public override void Camera(TakeoverReleaseMemory m,uint camera,float duration){Call(m,"Camera",camera,TakeoverReleaseMemory.Bits(duration),0,1);}
  public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return (int)Call(m,"ChangeReleasedState",p,0x759978);}
  public override void RunScript(TakeoverReleaseMemory m,uint sys,uint a,uint p,uint dt){Call(m,"RunScript",sys,a,p,p,dt);}
 }
 static int checks;static List<object> errors=new List<object>();
 static void Check(string name,object got,object want,int index){checks++;if(json.Serialize(got)!=json.Serialize(want))errors.Add(new Dictionary<string,object>{{"group",name},{"index",index},{"got",got},{"want",want}});}
 public static int Main(string[] args)
 {
  if(args.Length!=2)return 2;var fixture=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int i=0;
  foreach(object row in Arr(fixture["cases"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);var services=new Services(Obj(c["context"]));bool fault=false;try{TakeoverRelease.Release(memory,services,U(c["input"]));}catch(ArgumentException){fault=true;}
   Check("release-fault",fault,c["nativeFault"]!=null,i);Check("release-actor-state",new string[]{memory.ReadHex(0x10101000,0x1100),memory.ReadHex(0x10104000,0x1100)},c["nativeActors"],i);Check("release-service-order",services.Events,c["nativeEvents"],i);i++;}
  i=0;foreach(object row in Arr(fixture["seats"]))
  {var c=Obj(row);var memory=new Memory(c["initial"]);uint p=U(c["output"]);memory.Ensure(p,12);TakeoverRelease.SeatPosition(memory,U(c["actor"]),p);Check("seat-position",memory.ReadHex(p,12),c["native"],i++);}
  var report=new Dictionary<string,object>{{"binarySha256",fixture["binarySha256"]},{"checks",checks},{"mismatches",errors.Count},{"errors",errors},{"limitations",new string[]{"Comparison against retained original inline/seat fixtures with explicit downstream service adapters; no platform API called."}}};File.WriteAllText(args[1],json.Serialize(report));Console.WriteLine(json.Serialize(new{checks=checks,mismatches=errors.Count}));return errors.Count==0?0:1;
 }
}
