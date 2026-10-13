using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase1220261013Verify
{
 static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static byte[] Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,CRE=D,PACKET=D+0x6000,LOC=D+0x8000,TURRET=D+0xa000,RESULT=D+0xc000;
    var memory=new OriginPathMemory(D,Image(row["before"]));string missing=input.ContainsKey("missing")?(string)input["missing"]:null;uint creature=missing=="creature"?0:CRE,packet=missing=="packet"?0:PACKET,locator=B(input,"explicitLocator")?LOC:0,turret=missing=="turret"?0:TURRET;uint result=0;bool fault=false;
    try{float value;switch(kind){case "takeover":value=CompactRuntimeConditions.TakeOverRange(memory,creature);break;case "stuck":value=CompactRuntimeConditions.StuckTime(memory,creature);break;case "turret":value=CompactRuntimeConditions.TurretAlive(memory,turret);break;case "opponentY":value=CompactRuntimeConditions.OpponentToLocatorY(memory,packet,creature,locator);break;default:value=CompactRuntimeConditions.CheatProgress();break;}result=PcObjectImage.ToBits(value);memory.Set32(RESULT,result);}catch(InvalidOperationException){fault=true;}
    bool image=Equal(memory.Bytes,Image(row["after"])),ff=fault==Convert.ToBoolean(row["fault"]),ret=fault||result==Convert.ToUInt32(row["result"]);checks+=3;
    if(!image||!ff||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,fault=fault,faultMatches=ff,result=result,returnMatches=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Compact condition cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
