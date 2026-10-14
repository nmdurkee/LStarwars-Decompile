using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase3420261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static uint U(Dictionary<string,object>o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static int I(Dictionary<string,object>o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
 static float F(Dictionary<string,object>o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length<b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 static string Hex(byte[]bytes){return BitConverter.ToString(bytes).Replace("-","").ToLowerInvariant();}
 static byte[]Read(OriginPathMemory m,uint p,int length){var result=new byte[length];for(int j=0;j<length;j++)result[j]=m.U8(p+(uint)j);return result;}
 static bool Events(List<Dictionary<string,object>>a,object[]b){if(a.Count!=b.Length)return false;for(int j=0;j<a.Count;j++)foreach(string k in new string[]{"arguments","matrix","direction"})if((string)a[j][k]!=(string)M(b[j])[k])return false;return true;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));var sine=new float[32768];using(var f=new BinaryReader(File.OpenRead((string)data["sineTable"])))for(int j=0;j<sine.Length;j++)sine[j]=f.ReadSingle();var angles=new ushort[513];var av=(object[])data["angles"];for(int j=0;j<513;j++)angles[j]=Convert.ToUInt16(av[j]);int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,POD=D+0x2000,WORLD=D+0x8000,GAME=D+0x9000,TIME=D+0x10000,SCR=D+0xf0000,ACT2=D+0x12000,TARG=D+0x14000;byte[]bytes=new byte[0x100000];Array.Copy(Image(row["before"]),bytes,0x30000);var memory=new OriginPathMemory(D,bytes);var w=new PodFrameWorld{Memory=memory,World=WORLD,TimeState=TIME,SpecialGame=B(input,"special")?GAME:0,ProjectileGame=B(input,"wrongWorld")?0:GAME,SpecialMode=I(input,"mode",1),ProjectileType=0x1234,Delta=PcObjectImage.FromBits(Convert.ToUInt32(row["deltaBits"])),LookAhead=PcObjectImage.FromBits(Convert.ToUInt32(row["lookAheadBits"])),DisplacementW=U(input,"stackWord",0),SineTable=sine,AngleTable=angles};
    var p=new PodProjectileContext{SpriteHandle=D+0xe000,Template=D+0xf000,Target=B(input,"nullTarget")?0:TARG,Range=F(input,"range",10),Amplitude=F(input,"amplitude",4),TargetSpeed=F(input,"targetSpeed",1.5f),ProjectileSpeed=F(input,"projectileSpeed",12),Gravity=F(input,"gravity",-9.8f),RangeLimit=F(input,"rangeLimit",15),TimerCenter=F(input,"timerCenter",1),TimerSpread=F(input,"timerSpread",.25f),Random=new ScriptRandom{State=Convert.ToUInt32(row["beforeRandom"])} };
    if(input.ContainsKey("directionWords")){var words=(object[])input["directionWords"];for(int j=0;j<3;j++)p.InitialDirection[j]=Convert.ToUInt32(words[j]);}else p.InitialDirection=new uint[]{0x3f800000,0,0x40000000};var events=new List<Dictionary<string,object>>();
    p.Spawn=delegate(uint address){byte[]raw=Read(memory,address,200),matrix=Read(memory,memory.U32(address),64),direction=Read(memory,memory.U32(address+8),12);Array.Clear(raw,0,4);Array.Clear(raw,8,4);events.Add(new Dictionary<string,object>{{"arguments",Hex(raw)},{"matrix",Hex(matrix)},{"direction",Hex(direction)}});int mode=I(input,"spawnMode",0);if(mode==1||mode==4)memory.Set32(POD+0x90,ACT2);if(mode==3||mode==4){p.TimerCenter=2.125f;p.TimerSpread=.3125f;p.Random.State=0xabcdef01;}if(mode==5){memory.Set32(POD,0x3f000000);memory.Set32(POD+0x30,0x41100000);memory.Set32(POD+0x34,0xc0400000);memory.Set32(POD+0x38,0x80000000);}if(mode==6)memory.Set32(POD+0x88,0xffa51234);};
    uint result=PodFrameUpdate.Update(w,p,POD,SCR);bool image=Equal(memory.Bytes,Image(row["after"])),ret=result==Convert.ToUInt32(row["result"]),trace=Events(events,(object[])row["events"]),random=p.Random.State==Convert.ToUInt32(row["afterRandom"]),globals=PcObjectImage.ToBits(p.TimerCenter)==Convert.ToUInt32(row["afterCenterBits"])&&PcObjectImage.ToBits(p.TimerSpread)==Convert.ToUInt32(row["afterSpreadBits"]);checks+=5;if(!image||!ret||!trace||!random||!globals){failed++;if(errors.Count<10)errors.Add(new{input=input,image=image,result=ret,trace=trace,random=random,globals=globals});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Full pod update cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
