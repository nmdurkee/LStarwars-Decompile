using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase3720261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));uint basis=Convert.ToUInt32(data["base"]),random=Convert.ToUInt32(data["random"]);int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);cases++;try{var memory=new OriginPathMemory(basis,Image(row["before"]));uint projectile=Convert.ToUInt32(row["projectile"]);if((string)row["kind"]=="axes")ProjectileRandomFields.Axes(memory,projectile,random);else ProjectileRandomFields.Offsets(memory,projectile,random);checks++;if(!Equal(memory.Bytes,Image(row["after"]))){failed++;if(errors.Count<10)errors.Add(new{kind=row["kind"],input=row["input"]});}}catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=row["input"],error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));return failed==0?0:1;
 }
}
