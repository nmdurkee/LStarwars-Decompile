using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase2420261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static uint U(Dictionary<string,object>o,string k,uint fallback){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):fallback;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 static string Hex(OriginPathMemory m,uint p,int count){byte[]b=new byte[count];for(int j=0;j<count;j++)b[j]=m.U8(p+(uint)j);return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    bool image,ret,high=true,trace=true;
    if(kind=="availability")
    {
     var memory=new OriginPathMemory(0x7f9000,Image(row["before"]));int result=ActorPoolCreation.Availability(memory,U(input,"active",0)!=0,0x7fa138,0x7fa190,U(input,"output",0));image=Equal(memory.Bytes,Image(row["after"]));ret=unchecked((uint)result)==Convert.ToUInt32(row["result"]);checks+=2;
    }
    else
    {
     const uint D=0x10100000,WORLD=D+0x1000,REG=D+0x8000,DESC=D+0xc000,POOL=D+0x10000;var memory=new OriginPathMemory(D,Image(row["before"]));var events=new List<object>();var w=new ActorPoolWorld{Memory=memory,World=WORLD,Registry=REG,PublishedPool=POOL,HighestActive=row.ContainsKey("highestBefore")?Convert.ToUInt32(row["highestBefore"]):0xdeadbeef};
     w.Initialize=delegate(uint actor,uint type,uint mode){events.Add(new object[]{"initialize",actor,type,mode,Hex(memory,actor,0x400),w.HighestActive});if(B(input,"mutate")){memory.Set32(actor+0x1fc,0);memory.Set32(REG+0x1c,0);memory.Set32(actor+0x398,0x12345678);}};
     uint result=0;switch(kind){case "allocate":result=ActorPoolCreation.Allocate(memory,B(input,"nullDescriptor")?0:DESC);break;case "prepare":result=ActorPoolCreation.Prepare(w);break;case "create":result=ActorPoolCreation.Create(w,U(input,"type",1),U(input,"mode",0));break;default:ActorPoolCreation.RefreshHighest(w);break;}
     image=Equal(memory.Bytes,Image(row["after"]));ret=kind=="highest"||result==Convert.ToUInt32(row["result"]);high=w.HighestActive==Convert.ToUInt32(row["highest"]);trace=json.Serialize(events)==json.Serialize(row["events"]);checks+=kind=="highest"?3:4;
    }
    if(!image||!ret||!high||!trace){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,result=ret,highest=high,trace=trace});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Actor pool cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
