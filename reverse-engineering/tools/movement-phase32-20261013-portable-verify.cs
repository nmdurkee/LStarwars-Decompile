using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase3220261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static uint U(Dictionary<string,object>o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static int I(Dictionary<string,object>o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length<b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));var sine=new float[32768];using(var f=new BinaryReader(File.OpenRead((string)data["sineTable"])))for(int j=0;j<sine.Length;j++)sine[j]=f.ReadSingle();var angles=new ushort[513];var av=(object[])data["angles"];for(int j=0;j<513;j++)angles[j]=Convert.ToUInt16(av[j]);int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,POD=D+0x2000,WORLD=D+0x8000,GAME=D+0x9000,TIME=D+0x10000,SCR=D+0xf0000;byte[]bytes=new byte[0x100000];Array.Copy(Image(row["before"]),bytes,0x30000);var memory=new OriginPathMemory(D,bytes);var w=new PodFrameWorld{Memory=memory,World=WORLD,TimeState=TIME,SpecialGame=B(input,"special")?GAME:0,ProjectileGame=0,SpecialMode=I(input,"mode",1),ProjectileType=0x1234,Delta=PcObjectImage.FromBits(Convert.ToUInt32(row["deltaBits"])),LookAhead=PcObjectImage.FromBits(Convert.ToUInt32(row["lookAheadBits"])),DisplacementW=U(input,"stackWord",0),SineTable=sine,AngleTable=angles};uint result=PodFrameMotion.UpdateWithoutProjectile(w,POD,SCR);bool image=Equal(memory.Bytes,Image(row["after"])),ret=result==Convert.ToUInt32(row["result"]);checks+=2;if(!image||!ret){failed++;if(errors.Count<10)errors.Add(new{input=input,image=image,result=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Pod frame cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
