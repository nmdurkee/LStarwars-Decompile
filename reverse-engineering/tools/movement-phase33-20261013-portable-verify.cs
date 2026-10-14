using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase3320261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static uint U(Dictionary<string,object>o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static float F(Dictionary<string,object>o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));var sine=new float[32768];using(var f=new BinaryReader(File.OpenRead((string)data["sineTable"])))for(int j=0;j<sine.Length;j++)sine[j]=f.ReadSingle();var angles=new ushort[513];var av=(object[])data["angles"];for(int j=0;j<513;j++)angles[j]=Convert.ToUInt16(av[j]);int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,A=D+0x1000,B=D+0x2000,V=D+0x3000,O=D+0x4000,H=D+0x5000,FRET=D+0x1f000;var memory=new OriginPathMemory(D,Image(row["before"]));uint output=U(input,"output",O);string kind=(string)row["kind"];
    if(kind=="matrix")PodProjectileMath.MatrixOrigin(memory,output,A);
    else if(kind=="distance")memory.SetFloat(FRET,PodProjectileMath.DistanceSquared(memory,A,B,output));
    else if(kind=="sprite")memory.SetFloat(FRET,PodProjectileMath.SpriteScale(memory,H));
    else PodProjectileMath.Aim(memory,output,A,B,V,F(input,"speed",12),F(input,"gravity",-9.8f),PcObjectImage.FromBits(Convert.ToUInt32(row["deltaBits"])),sine,angles);
    bool image=Equal(memory.Bytes,Image(row["after"]));checks++;if(!image){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Projectile math cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
