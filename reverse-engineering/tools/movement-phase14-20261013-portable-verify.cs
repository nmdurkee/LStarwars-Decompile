using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase1420261013Verify
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
    const uint D=0x10100000,C=D,R=D+0x1000,P=D+0x4000,W=D+0x6000,ROWS=D+0x8000,ALT=D+0xa000,OTHER=D+0xb000;
    var memory=new OriginPathMemory(D,Image(row["before"]));var world=new WeaponGravityWorld{Memory=memory,Numbers=new ScriptPacket{Script=new ScriptDefinition()}};world.Random.State=input.ContainsKey("seed")?Convert.ToUInt32(input["seed"]):123u;var events=new List<object>();
    if(!input.ContainsKey("callback")||Convert.ToBoolean(input["callback"]))world.ResolveReference=delegate(uint w,string text){string lo=text.ToLowerInvariant();uint reference=lo=="alt"||lo=="mutate"||lo=="empty"?ALT:0;events.Add(new object[]{"character",w,text,reference});if(lo=="mutate"){memory.Set32(R,OTHER);memory.SetFloat(P+0x14,3.125f);byte[]name=System.Text.Encoding.ASCII.GetBytes("Changed\0");for(int j=0;j<name.Length;j++)memory.Set8(ROWS+(uint)j,name[j]);memory.Set32(W+0x24,2);}memory.Set32(ALT,lo=="empty"?0:OTHER);return reference;};
    object[]raw=(object[])row["tokens"];string[]tokens=new string[raw.Length];for(int j=0;j<tokens.Length;j++)tokens[j]=(string)raw[j];uint creature=input.ContainsKey("missing")&&(string)input["missing"]=="creature"?0:C;
    bool result=kind=="weapon"?WeaponGravityCommands.SnapWeaponOut(world,B(input,"worldNull")?0:W,creature,tokens,Convert.ToBoolean(row["first"])):WeaponGravityCommands.SetGravityHeight(world,P,creature,tokens,Convert.ToBoolean(row["first"]));
    bool image=Equal(memory.Bytes,Image(row["after"])),rng=world.Random.State==Convert.ToUInt32(row["rng"]),order=json.Serialize(events)==json.Serialize(row["events"]),ret=(result?1u:0u)==Convert.ToUInt32(row["result"]);checks+=4;
    if(!image||!rng||!order||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,rng=rng,order=order,ret=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Weapon/gravity cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
