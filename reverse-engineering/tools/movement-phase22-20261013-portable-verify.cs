using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase2220261013Verify
{
 static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
 static byte[] Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool EqualPrefix(byte[]a,byte[]b){if(a.Length<b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 static uint Pointer(Dictionary<string,object>o,string k,uint fallback){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):fallback;}
 static float F(Dictionary<string,object>o,string k,float fallback){return o.ContainsKey(k)?Convert.ToSingle(o[k]):fallback;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  object[]raw=(object[])data["table"],at=(object[])data["angles"];float[]table=new float[raw.Length];ushort[]angles=new ushort[at.Length];for(int j=0;j<raw.Length;j++)table[j]=PcObjectImage.FromBits(Convert.ToUInt32(raw[j]));for(int j=0;j<at.Length;j++)angles[j]=Convert.ToUInt16(at[j]);int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,POD=D+0x1000,DIR=D+0x2000,OUT=D+0x3000;byte[]before=Image(row["before"]),storage=new byte[before.Length+64];Array.Copy(before,storage,before.Length);var memory=new OriginPathMemory(D,storage);
    if(kind=="heading")PodHeadingCommands.Apply(new PodHeadingWorld{Memory=memory,SineTable=table,AngleTable=angles,Delta=F(input,"delta",1f/60)},POD,Pointer(input,"source",DIR),F(input,"factor",1),input.ContainsKey("mode")?Convert.ToInt32(input["mode"]):0,D+(uint)before.Length);
    else PodHeadingCommands.VectorZ(memory,Pointer(input,"output",OUT),Pointer(input,"source",DIR),input.ContainsKey("angle")?Convert.ToInt32(input["angle"]):12345,table);
    bool image=EqualPrefix(memory.Bytes,Image(row["after"]));checks++;if(!image){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Pod heading cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
