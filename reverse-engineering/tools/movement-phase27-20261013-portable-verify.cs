using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase2720261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static uint U(Dictionary<string,object>o,string k,uint fallback){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):fallback;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,ACT=D+0x1000,WORLD=D+0x8000,REG=D+0xc000,RECORDS=D+0x10000,MODELS=D+0x20000,SOURCE_TABLE=D+0x52000,PAD=0x9253b0,CB=0x10200600;var memory=new OriginPathMemory(D,Image(row["before"]));var pads=new OriginPathMemory(PAD,Image(row["padBefore"]));var events=new List<object>();var w=new ActorInitializationWorld{Memory=memory,AnimationMemory=pads,Registry=REG,World=WORLD,StartTable=SOURCE_TABLE,AnimationPool=PAD,Emitter=0xdeadbeef,DefaultPosition=new uint[]{PcObjectImage.ToBits(7),PcObjectImage.ToBits(8),PcObjectImage.ToBits(9)},SpecialTypes=new ushort[]{5,6,7,8,9},BoundPadding=PcObjectImage.FromBits(Convert.ToUInt32(data["paddingBits"])),Random=new QRandom{State=U(input,"seed",123)}};
    Func<uint,uint,uint[],uint>port=delegate(uint address,uint actor,uint[]parameters)
    {
     events.Add(new{address="0x"+address.ToString("x"),actor=actor,args=parameters,flags=memory.U32(ACT+0x1f8),radius=new uint[]{memory.U32(ACT+0x1dc),memory.U32(ACT+0x1e0)},packet=memory.U32(ACT+0xca4)});
     if(B(input,"mutate"))
     {
      switch(address)
      {
       case 0x4148a0:memory.Set32(ACT+0x54,RECORDS+2*0x4c);memory.Set8(ACT+0x1079,1);memory.SetFloat(ACT+0xd30,1);memory.Set8(ACT+0x28c,1);break;
       case CB:memory.Set32(ACT+0x50,MODELS+0x54);break;
       case 0x4150d0:memory.SetFloat(ACT+0x1dc,7.125f);memory.SetFloat(ACT+0x1e0,8.125f);break;
       case 0x595840:memory.SetFloat(ACT+0x1dc,4.875f);break;
       case 0x55d2b0:memory.SetVector(ACT+0x5c,new float[]{-1,-2,-3});uint late=U(input,"lateType",9);memory.Set8(ACT+0x1064,(int)(late&255));memory.Set8(ACT+0x1065,(int)((late>>8)&255));memory.Set32(ACT+0x54,RECORDS+3*0x4c);break;
       case 0x41a9c0:case 0x41ab00:case 0x41ab90:case 0x41ac40:memory.Set32(memory.U32(memory.U32(ACT+0x54)+0x24)+0x90,0);break;
      }
     }
     return address==0x415050?U(input,"moves",1):address==0x4cca00?U(input,"suit",0):0;
    };
    w.Service=port;w.DimensionsUpdated=delegate(uint actor){port(CB,actor,new uint[]{actor});};uint result=ActorInitialization.Initialize(w,ACT,Convert.ToInt32(row["type"]),Convert.ToUInt32(row["mode"]));bool image=Equal(memory.Bytes,Image(row["after"])),pad=Equal(pads.Bytes,Image(row["padAfter"])),ret=result==Convert.ToUInt32(row["result"]),rng=w.Random.State==Convert.ToUInt32(row["rng"]),emitter=w.Emitter==Convert.ToUInt32(row["emitter"]),trace=json.Serialize(events)==json.Serialize(row["events"]);checks+=6;if(!image||!pad||!ret||!rng||!emitter||!trace){failed++;if(errors.Count<10)errors.Add(new{input=input,type=row["type"],image=image,pad=pad,result=ret,rng=rng,emitter=emitter,trace=trace});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Actor initializer cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
