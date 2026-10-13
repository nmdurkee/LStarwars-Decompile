using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase2820261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static uint U(Dictionary<string,object>o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static int I(Dictionary<string,object>o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[]a,byte[]b){if(a.Length<b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 static void Word(OriginPathMemory m,uint p,uint v){m.Set8(p,(int)(v&255));m.Set8(p+1,(int)((v>>8)&255));}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();var sine=new float[32768];using(var f=new BinaryReader(File.OpenRead((string)data["sineTable"])))for(int j=0;j<sine.Length;j++)sine[j]=f.ReadSingle();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,POOL=D+0x50000,WORLD=D+0x8000,REG=D+0xc000,RECORDS=D+0x10000,SOURCE_TABLE=D+0x48000,PAD=0x9253b0,POS=D+0x49000,SCR=D+0xf0000,CB=0x10200600;uint slot=U(input,"free",0),ACT=POOL+(slot<64?slot*0x10d8:0);byte[]bytes=new byte[0x100000];Array.Copy(Image(row["before"]),bytes,0xc0000);var memory=new OriginPathMemory(D,bytes);var pads=new OriginPathMemory(PAD,Image(row["padBefore"]));var events=new List<object>();var defaultPosition=new uint[]{PcObjectImage.ToBits(7),PcObjectImage.ToBits(8),PcObjectImage.ToBits(9)};
    Func<uint,uint,uint[],uint>port=delegate(uint address,uint actor,uint[]p)
    {
     events.Add(new{address="0x"+address.ToString("x"),actor=actor,args=p,flags=memory.U32(ACT+0x1f8),radius=new uint[]{memory.U32(ACT+0x1dc),memory.U32(ACT+0x1e0)},packet=memory.U32(ACT+0xca4)});
     if(address==0x518040){memory.Set32(ACT+0x40c,p[0]);memory.Set8(ACT+0x410,(int)U(input,"member",3));memory.Set8(ACT+0x411,(int)U(input,"column",0));memory.Set8(ACT+0x412,(int)U(input,"row",1));}
     if(address==0x553570){memory.Set32(ACT+0xe64,p[1]);memory.Set32(ACT+0xe80,p[3]);memory.Set8(ACT+0xe6a,(int)U(input,"splineIndex",255));}
     if(address==0x550a20){memory.SetVector(p[2],new float[]{1.25f,-2.5f,3.75f});memory.Set32(p[3],U(input,"sampleHeading",0x1234));Word(memory,p[4],U(input,"samplePitch",0x2345));Word(memory,p[4]+2,0x3456);}
     if(B(input,"mutate"))
     {
      if(address==0x41b0a0){memory.Set32(POS,0xc0400000);memory.Set32(ACT+0x54,RECORDS+3*0x4c);}
      if(address==0x41af70)memory.Set32(ACT+0x5c,0x40b00000);
      if(address==0x514640)for(uint j=0;j<6;j++)memory.Set32(ACT+0x420+j*4,0x11110000+j);
      if(address==0x498a40)memory.Set32(ACT+0x5c,0xc0f00000);
     }
     if(address==0x51b890&&B(input,"boundPath"))memory.Set32(ACT+0x424,1);
     return address==0x415050?1u:0;
    };
    var iw=new ActorInitializationWorld{Memory=memory,AnimationMemory=pads,Registry=REG,World=WORLD,StartTable=SOURCE_TABLE,AnimationPool=PAD,Emitter=0xdeadbeef,DefaultPosition=defaultPosition,SpecialTypes=new ushort[]{5,6,7,8,9},BoundPadding=PcObjectImage.FromBits(Convert.ToUInt32(data["paddingBits"])),Random=new QRandom{State=123},Service=port};iw.DimensionsUpdated=delegate(uint a){port(CB,a,new uint[]{a});};var pool=new ActorPoolWorld{Memory=memory,World=WORLD,Registry=REG,PublishedPool=POOL,HighestActive=0xdeadbeef};pool.Initialize=delegate(uint a,uint t,uint mode){ActorInitialization.Initialize(iw,a,unchecked((int)t),mode);};byte[]groupCounts=new byte[17];for(int j=0;j<17;j++)groupCounts[j]=(byte)U(input,"groupCount",0);
    var w=new ActorCreationWorld{Memory=memory,World=WORLD,Registry=REG,TypeLock=B(input,"typeLock"),HeroType=unchecked((ushort)I(input,"hero",1)),ContextActive=B(input,"contextActive"),ContextIndex=unchecked((sbyte)I(input,"contextIndex",0)),RefreshTypeState=B(input,"refresh"),SelectedRoom=B(input,"rooms")?I(input,"selected",0):-1,CurrentRoom=23,GroupCounts=groupCounts,DefaultPosition=defaultPosition,LastPosition=new uint[]{0x12345678,0x23456789,0x3456789a},SineTable=sine,Service=port};w.DimensionsUpdated=delegate(uint a){port(CB,a,new uint[]{a});};w.AllocateActor=delegate(uint t){return ActorPoolCreation.Create(pool,t,0);};object[]aa=(object[])row["args"];var aargs=new uint[11];for(int j=0;j<11;j++)aargs[j]=Convert.ToUInt32(aa[j]);uint result=ActorCreation.Create(w,aargs[0],aargs[1],aargs[2],aargs[3],aargs[4],aargs[5],aargs[6],aargs[7],aargs[8],aargs[9],aargs[10],SCR);object[]g=(object[])row["globals"];var nativeLast=(object[])g[4];var nativeGroups=(object[])g[5];bool global=result==Convert.ToUInt32(g[0])&&iw.Random.State==Convert.ToUInt32(g[1])&&iw.Emitter==Convert.ToUInt32(g[2])&&pool.HighestActive==Convert.ToUInt32(g[3])&&w.CurrentRoom==Convert.ToInt32(g[6]);for(int j=0;j<3;j++)global&=w.LastPosition[j]==Convert.ToUInt32(nativeLast[j]);for(int j=0;j<17;j++)global&=w.GroupCounts[j]==Convert.ToByte(nativeGroups[j]);bool image=Equal(memory.Bytes,Image(row["after"])),pad=Equal(pads.Bytes,Image(row["padAfter"])),trace=json.Serialize(events)==json.Serialize(row["events"]);checks+=4;if(!image||!pad||!global||!trace){failed++;if(errors.Count<10)errors.Add(new{input=input,image=image,pad=pad,globals=global,trace=trace});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Actor creation cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
