using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase2320261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k,bool fallback=false){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):fallback;}
 static int I(Dictionary<string,object>o,string k,int fallback=0){return o.ContainsKey(k)?Convert.ToInt32(o[k]):fallback;}
 static uint U(Dictionary<string,object>o,string k,uint fallback){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):fallback;}
 static float F(Dictionary<string,object>o,string k,float fallback){return o.ContainsKey(k)?Convert.ToSingle(o[k]):fallback;}
 static byte[]Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool EqualPrefix(byte[]a,byte[]b){if(a.Length<b.Length)return false;for(int j=0;j<b.Length;j++)if(a[j]!=b[j])return false;return true;}
 static string Hex(OriginPathMemory m,uint p,int count){byte[]b=new byte[count];for(int j=0;j<count;j++)b[j]=m.U8(p+(uint)j);return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static uint Definition(string name){return name.Equals("unknown",StringComparison.OrdinalIgnoreCase)?0x123400ffu:(name.Equals("MiscPod",StringComparison.OrdinalIgnoreCase)||name.Equals("mutate",StringComparison.OrdinalIgnoreCase))?0xabcdef01u:2u;}
 static uint[]Words(object o){object[]a=(object[])o;uint[]v=new uint[a.Length];for(int j=0;j<a.Length;j++)v[j]=Convert.ToUInt32(a[j]);return v;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  uint[]raw=Words(data["table"]);float[]table=new float[raw.Length];for(int j=0;j<raw.Length;j++)table[j]=PcObjectImage.FromBits(raw[j]);object[]at=(object[])data["angles"];ushort[]angles=new ushort[at.Length];for(int j=0;j<at.Length;j++)angles[j]=Convert.ToUInt16(at[j]);int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);cases++;
   try
   {
    const uint D=0x10100000,C=D+0x1000,ACT=D+0x5000,RACE=D+0x10000,ALT=D+0x20000;byte[]before=Image(row["before"]),storage=new byte[before.Length+256];Array.Copy(before,storage,before.Length);var memory=new OriginPathMemory(D,storage);var events=new List<object>();var w=new PodCreationWorld{Memory=memory,Race=B(input,"nullRace")?0:RACE,Pacemaker=0x76543210,MatrixTemplate=Words(input.ContainsKey("template")?input["template"]:data["template"]),SineTable=table,AngleTable=angles,Delta=F(input,"delta",1f/60),LookAhead=PcObjectImage.FromBits(Convert.ToUInt32(data["stepBits"])),Numbers=new ScriptPacket()};
    if(B(input,"definition",true))w.Definition=delegate(string name){uint v=Definition(name);events.Add(new object[]{"definition",name,v});if(name.Equals("mutate",StringComparison.OrdinalIgnoreCase)){memory.SetFloat(C+0x14,.25f);memory.SetFloat(RACE+0xb00c,5);w.Race=B(input,"switchRace")?ALT:RACE;}return v;};
    if(B(input,"typeCallback",true))w.ActorType=delegate(ushort id){uint v=U(input,"type",0x12348002);events.Add(new object[]{"type",id,v});return v;};
    w.CreateActor=delegate(int type,uint spline){uint actor=B(input,"noActor")?0:ACT,pod=w.Race+0xa600+(uint)I(input,"free")*0xa0;events.Add(new object[]{"create",new object[]{unchecked((uint)type),spline,0,0,0,0,1,0,0,0,0},actor,Hex(memory,pod,0xa0)});if(B(input,"spawnMutation")){memory.Set32(pod+0x88,0xcafe1234);memory.Set32(ACT+0xef4,0x2468ace0);memory.Set32(pod+0x90,ACT+0x100);}return actor;};
    object[]tt=(object[])row["tokens"];string[]tokens=new string[tt.Length];for(int j=0;j<tokens.Length;j++)tokens[j]=(string)tt[j];bool result=PodCreationCommands.Create(w,B(input,"nullContext")?0:C,tokens,Convert.ToBoolean(row["first"]),D+(uint)before.Length);bool image=EqualPrefix(memory.Bytes,Image(row["after"])),pace=w.Pacemaker==Convert.ToUInt32(row["pace"]),trace=json.Serialize(events)==json.Serialize(row["events"]),ret=(result?1:0)==Convert.ToInt32(row["result"]);checks+=4;if(!image||!pace||!trace||!ret){failed++;if(errors.Count<10)errors.Add(new{input=input,tokens=tokens,image=image,pace=pace,trace=trace,result=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("CreatePod cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
