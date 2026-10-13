using System;
using System.IO;
using System.IO.Compression;
using System.Text;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase2920261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static uint U(Dictionary<string,object>o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static int I(Dictionary<string,object>o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 static string Hex(OriginPathMemory m,uint p,int count){var s=new StringBuilder(count*2);for(uint j=0;j<count;j++)s.Append(m.U8(p+j).ToString("x2"));return s.ToString();}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,ACT=D+0x1000,META=D+0x4000,WORLD=D+0x8000,TABLE=D+0x18000,CB=0x10200700;var memory=new OriginPathMemory(D,Image(row["before"]));var events=new List<object>();var w=new ActorBaseResetWorld{Memory=memory,World=WORLD,TypeTable=TABLE,AlternateMode=B(input,"alternate"),SpecialMode=B(input,"special"),DefaultPlayerMask=B(input,"defaultMask"),MaskCallback=!input.ContainsKey("callback")||B(input,"callback")?CB:0,DefaultMaskLow=0x76543210,DefaultMaskHigh=0xfedcba98,DurationBits=U(input,"duration",0x3f800000)};
    w.Service=delegate(uint address,uint actor,uint[]p)
    {
     events.Add(new{address="0x"+address.ToString("x"),args=p,actorImage=Hex(memory,ACT,0x10d8)});
     if(B(input,"mutate"))
     {
      if(address==0x407b60||address==0x481740||address==0x4cbe50){memory.Set8(ACT+0x1064,7);memory.Set8(ACT+0x1065,0);memory.Set32(ACT+0x54,META+0x100);memory.Set32(ACT+0x1f8,memory.U32(ACT+0x1f8)^0x400);}
      else if(address==CB){memory.Set32(ACT+0x54,META+0x200);w.DefaultMaskLow=0xabcddcba;w.DefaultMaskHigh=0x11223344;w.DurationBits=0xbf800000;}
      else if(address==0x52f800){memory.Set32(ACT+0x420,0xdeadbeef);memory.Set32(ACT+0x5c,0x12345678);}
     }
     return address==CB?U(input,"maskReturn",0):0;
    };
    uint result=0;if(kind=="reset")ActorBaseReset.Reset(w,ACT);else if(kind=="path")ActorBaseReset.PathReset(w,ACT);else result=ActorBaseReset.TypePredicate(memory,TABLE,I(input,"type",1));var g=M(row["globals"]);bool image=Equal(memory.Bytes,Image(row["after"])),trace=json.Serialize(events)==json.Serialize(row["events"]),globals=w.DefaultMaskLow==Convert.ToUInt32(g["low"])&&w.DefaultMaskHigh==Convert.ToUInt32(g["high"])&&w.DurationBits==Convert.ToUInt32(g["duration"]),ret=kind!="predicate"||result==Convert.ToUInt32(row["result"]);checks+=kind=="predicate"?4:3;if(!image||!trace||!globals||!ret){failed++;if(errors.Count<10)errors.Add(new{input=input,kind=kind,image=image,trace=trace,globals=globals,result=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,kind=kind,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Actor base reset cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
