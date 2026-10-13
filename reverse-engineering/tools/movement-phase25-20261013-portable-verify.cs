using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase2520261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static uint U(Dictionary<string,object>o,string k,uint fallback){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):fallback;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool EqualPrefix(byte[]a,byte[]b){if(a.Length<b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,ACT=D+0x1000,PAD=0x9253b0;byte[]before=Image(row["before"]),storage=new byte[before.Length+128];Array.Copy(before,storage,before.Length);var memory=new OriginPathMemory(kind=="pad"?PAD:D,storage);uint result=0;
    switch(kind)
    {
     case "pad":result=ActorInitializationPrimitives.AllocateAnimation(memory,PAD);break;
     case "start":uint table=D+(uint)before.Length;object[]p=input.ContainsKey("pointers")?(object[])input["pointers"]:null;for(uint j=0;j<8;j++)memory.Set32(table+j*16,p==null?0x12340000+j*0x400:Convert.ToUInt32(p[j]));result=ActorInitializationPrimitives.StartPointer(memory,ACT,table);break;
     case "flag":ActorInitializationPrimitives.TypeFlag(memory,ACT);break;
     case "dimensions":ActorInitializationPrimitives.Dimensions(memory,ACT);break;
     default:ActorInitializationPrimitives.InstallDimensions(memory,ACT);break;
    }
    bool image=EqualPrefix(memory.Bytes,Image(row["after"])),ret=(kind!="pad"&&kind!="start")||result==Convert.ToUInt32(row["result"]);checks+=kind=="pad"||kind=="start"?2:1;if(!image||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,result=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Actor primitives cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
