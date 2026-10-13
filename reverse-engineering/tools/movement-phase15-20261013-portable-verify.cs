using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase1520261013Verify
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
   var row=M(o);var input=M(row["input"]);string kind="scale";cases++;
   try
   {
    const uint D=0x10100000,C=D,P=D+0x4000;
    var memory=new OriginPathMemory(D,Image(row["before"]));var world=new ScaleOverrideWorld{Memory=memory,Numbers=new ScriptPacket{Script=new ScriptDefinition()},Delta=input.ContainsKey("delta")?Convert.ToSingle(input["delta"]):.125f};world.Random.State=input.ContainsKey("seed")?Convert.ToUInt32(input["seed"]):123u;
    object[]raw=(object[])row["tokens"];string[]tokens=new string[raw.Length];for(int j=0;j<tokens.Length;j++)tokens[j]=(string)raw[j];uint creature=input.ContainsKey("missing")&&(string)input["missing"]=="creature"?0:C;
    bool result=ScaleOverrideCommands.SetScaleOverride(world,P,creature,tokens,Convert.ToBoolean(row["first"]));bool image=Equal(memory.Bytes,Image(row["after"])),rng=world.Random.State==Convert.ToUInt32(row["rng"]),ret=(result?1u:0u)==Convert.ToUInt32(row["result"]);checks+=3;
    if(!image||!rng||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,rng=rng,ret=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Scale override cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
