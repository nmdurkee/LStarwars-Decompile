using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase3020261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static uint U(Dictionary<string,object>o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    var m=new OriginPathMemory(0x10100000,Image(row["before"]));const uint actor=0x10101000;
    if(kind=="normal")ActorModeCapabilities.Normal(m,actor);else if(kind=="alternate")ActorModeCapabilities.Alternate(m,actor,(ushort)U(input,"alternateType",7));else ActorModeCapabilities.Special(m,actor,(ushort)U(input,"specialType",8));checks++;if(!Equal(m.Bytes,Image(row["after"]))){failed++;if(errors.Count<10)errors.Add(new{input=input,kind=kind,image=false});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,kind=kind,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Actor mode capability cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
