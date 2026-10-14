using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase3520261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static int I(Dictionary<string,object>o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 static string Position(OriginPathMemory m,uint p){byte[]bytes=new byte[12];for(uint j=0;j<12;j++)bytes[j]=m.U8(p+j);return BitConverter.ToString(bytes).Replace("-","").ToLowerInvariant();}
 static bool Events(List<Dictionary<string,object>>a,object[]b){if(a.Count!=b.Length)return false;for(int j=0;j<a.Count;j++){var expected=M(b[j]);if((string)a[j]["port"]!=(string)expected["port"]||(string)a[j]["position"]!=(string)expected["position"])return false;var aa=(object[])a[j]["args"];var bb=(object[])expected["args"];for(int k=0;k<3;k++)if(Convert.ToInt64(aa[k])!=Convert.ToInt64(bb[k]))return false;}return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,P=D+0x2000,W=D+0x4000,W2=D+0x5000;var memory=new OriginPathMemory(D,Image(row["before"]));var w=new PodProjectileEffectWorld{Memory=memory,World=B(input,"nullWorld")?0:W,ParticleId=(short)I(input,"particle",-1),SoundId=I(input,"sound",-1)};var events=new List<Dictionary<string,object>>();Action<string,object[],uint>publish=delegate(string port,object[]arguments,uint position){events.Add(new Dictionary<string,object>{{"port",port},{"args",arguments},{"position",Position(memory,position)}});int mode=I(input,"mode",0);if(port=="particle"){if(mode==1||mode==4)w.SoundId=I(input,"nextSound",-1);if(mode==2||mode==4){w.World=W2;w.ParticleId=-1;memory.Set32(P+0x30,0x41200000);}}if(port=="sound"&&(mode==3||mode==4)){w.SoundId=0x1234ffff;memory.Set32(P+0x34,0x80000000);}};
    w.Particle=delegate(uint system,int id,uint position){publish("particle",new object[]{system,id,position},position);};w.Sound=delegate(int id,uint position,int flag){publish("sound",new object[]{id,position,flag},position);};PodProjectileEffects.Publish(w,P);var state=M(row["afterState"]);bool image=Equal(memory.Bytes,Image(row["after"])),trace=Events(events,(object[])row["events"]),globals=w.ParticleId==Convert.ToInt32(state["particle"])&&w.SoundId==Convert.ToInt32(state["sound"])&&w.World==Convert.ToUInt32(state["world"]);checks+=3;if(!image||!trace||!globals){failed++;if(errors.Count<10)errors.Add(new{input=input,image=image,trace=trace,globals=globals});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));return failed==0?0:1;
 }
}
