using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase2620261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k,bool fallback){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):fallback;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,ACT=D+0x1000;var memory=new OriginPathMemory(D,Image(row["before"]));var events=new List<object>();
    if(kind=="height")ActorCollisionDimensions.HeightFactor(memory,ACT);
    else
    {
     Action<uint>callback=null;if(B(input,"callback",true))callback=delegate(uint actor){events.Add(new object[]{"updated",actor,new object[]{memory.U32(actor+0x1dc),memory.U32(actor+0x1e0)}});if(B(input,"mutate",false)){memory.Set32(actor+0x1dc,0xdeadbeef);memory.Set32(actor+0x1e0,0x7f800001);}};ActorCollisionDimensions.Update(memory,ACT,callback);
    }
    bool image=Equal(memory.Bytes,Image(row["after"])),trace=kind=="height"||json.Serialize(events)==json.Serialize(row["events"]);checks+=kind=="height"?1:2;if(!image||!trace){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,trace=trace});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Collision dimensions cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
