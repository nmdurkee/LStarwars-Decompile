using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase1320261013Verify
{
 static Dictionary<string,object>M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object>o,string k,bool d){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):d;}
 static byte[] Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static byte[] Hex(string s){byte[] a=new byte[s.Length/2];for(int j=0;j<a.Length;j++)a[j]=Convert.ToByte(s.Substring(j*2,2),16);return a;}
 static bool Equal(byte[]a,byte[]b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 static string[]Tokens(object o){object[]a=(object[])o;string[]t=new string[a.Length];for(int j=0;j<a.Length;j++)t[j]=(string)a[j];return t;}
 static byte[] State(ForceBackState s){byte[] a=new byte[20];uint[]words={PcObjectImage.ToBits(s.Radius),PcObjectImage.ToBits(s.RadiusSquared),s.Actor,s.Origin,s.Extra};for(int j=0;j<5;j++)Array.Copy(BitConverter.GetBytes(words[j]),0,a,j*4,4);return a;}
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object>data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=row.ContainsKey("kind")?(string)row["kind"]:"command";cases++;
   try
   {
    const uint D=0x10100000,C=D,R=D+0x1000,P=D+0x4000,W=D+0x6000,ROWS=D+0x8000,ALT=D+0xa000,OTHER=D+0xb000;
    var memory=new OriginPathMemory(D,Image(row["before"]));var world=new ForceBackWorld{Memory=memory,Numbers=new ScriptPacket{Script=new ScriptDefinition()}};world.Numbers.Script.ParameterNames[0]="factor";byte[] sb=Hex((string)row["stateBefore"]);world.State.Radius=PcObjectImage.FromBits(BitConverter.ToUInt32(sb,0));world.State.RadiusSquared=PcObjectImage.FromBits(BitConverter.ToUInt32(sb,4));world.State.Actor=BitConverter.ToUInt32(sb,8);world.State.Origin=BitConverter.ToUInt32(sb,12);world.State.Extra=BitConverter.ToUInt32(sb,16);var events=new List<object>();
    if(B(input,"callback",true))world.ResolveReference=delegate(uint w,string text){string lo=text.ToLowerInvariant();uint result=lo=="alt"||lo=="mutate"||lo=="empty"?ALT:0;events.Add(new object[]{"character",w,text,result});if(lo=="mutate"){memory.Set32(R,OTHER);memory.SetFloat(P+0x14,3.125f);byte[]name=System.Text.Encoding.ASCII.GetBytes("Changed\0");for(int j=0;j<name.Length;j++)memory.Set8(ROWS+(uint)j,name[j]);memory.Set32(W+0x24,2);}memory.Set32(ALT,lo=="empty"?0:OTHER);return result;};
    bool resultValue=true;
    if(kind=="publish")ForceBackCommands.Publish(world.State,Convert.ToUInt32(input["actor"]),Convert.ToUInt32(input["fallback"]),PcObjectImage.FromBits(Convert.ToUInt32(input["radiusBits"])),Convert.ToUInt32(input["extra"]));
    else if(kind=="clear")ForceBackCommands.Clear(world.State);
    else resultValue=ForceBackCommands.SetForceBack(world,B(input,"worldNull",false)?0:W,P,input.ContainsKey("missing")&&(string)input["missing"]=="creature"?0:C,Tokens(row["tokens"]),Convert.ToBoolean(row["first"]));
    bool image=Equal(memory.Bytes,Image(row["after"])),state=Equal(State(world.State),Hex((string)row["stateAfter"]));bool order=true,ret=true;checks+=2;if(kind=="command"){order=json.Serialize(events)==json.Serialize(row["events"]);ret=(resultValue?1u:0u)==Convert.ToUInt32(row["result"]);checks+=2;}
    if(!image||!state||!order||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,state=state,order=order,ret=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("ForceBack cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
