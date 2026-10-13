using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase1020261013Verify
{
 static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
 static int I(Dictionary<string,object> x,string k,int d){return x.ContainsKey(k)?Convert.ToInt32(x[k]):d;}
 static uint U(Dictionary<string,object> x,string k,uint d){return x.ContainsKey(k)?Convert.ToUInt32(x[k]):d;}
 static bool B(Dictionary<string,object> x,string k,bool d){return x.ContainsKey(k)?Convert.ToBoolean(x[k]):d;}
 static byte[] Image(object text){using(var s=new MemoryStream(Convert.FromBase64String((string)text)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
 static bool Equal(byte[] a,byte[] b){if(a.Length<b.Length)return false;for(int i=0;i<b.Length;i++)if(a[i]!=b[i])return false;return true;}
 static string[] Tokens(object o){object[] a=(object[])o;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));object[] rawTable=(object[])data["table"];float[] table=new float[rawTable.Length];for(int i=0;i<table.Length;i++)table[i]=PcObjectImage.FromBits(Convert.ToUInt32(rawTable[i]));
  int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object v in(object[])data["vectors"])
  {
   var row=M(v);var input=M(row["input"]);string kind=(string)row["kind"];cases++;try
   {
    const uint D=0x10100000,C=D,R=D+0x1000,P=D+0x2000,W=D+0x3000,O=D+0x6000,OBJECT=D+0x9000,OTHER=D+0xc000,RESULT=D+0xe000;
    byte[] before=Image(row["before"]);byte[] full=new byte[before.Length+16];Array.Copy(before,full,before.Length);var memory=new OriginPathMemory(D,full);var movement=new OriginPathWorld{Memory=memory,SineTable=table};var world=new ForwardOriginWorld{Movement=movement,HasPlayer=B(input,"player",true),Numbers=new ScriptPacket{Script=new ScriptDefinition()}};world.Numbers.Script.ParameterNames[0]="factor";world.FloatRandom.State=U(input,"seed",123);world.IntegerRandom.Global.State=U(input,"integerSeed",123);var events=new List<object>();
    if(B(input,"tokenCallback",true))movement.MovementToken=delegate(string t,uint modePointer)
    {
     int mode=String.Equals(t,"walk",StringComparison.OrdinalIgnoreCase)?17:String.Equals(t,"run",StringComparison.OrdinalIgnoreCase)?34:-1;bool handled=mode>=0||t=="mutate";events.Add(new object[]{"token",t,handled});if(mode>=0)memory.Set8(modePointer,mode);
     if(t=="mutate"){memory.Set32(R,OTHER);memory.SetVector(OBJECT+0x5c,new float[]{10.125f,-5.5f,2.375f});memory.SetFloat(P+0x70,1234.5f);memory.Set8(C+0x166,1);memory.Set32(C+0x160,0x1234cafe);}return handled;
    };
    if(B(input,"originCallback",true))movement.OriginPosition=delegate(uint w,uint c)
    {
     bool origin=B(input,"origin",false);events.Add(new object[]{"origin",origin});if(B(input,"originMutate",false)){memory.SetVector(C+0x14c,new float[]{2.125f,-1.25f,3.375f});memory.Set8(C+0x138,B(input,"mutateSpawn255",false)?255:0);}return origin?O:0;
    };
    movement.Schedule=delegate(uint callback){uint formation=memory.U32(C+0x144);FormationScheduling.Dispatch(new FormationScheduleWorld{Memory=memory,Callback=delegate(uint code,uint fo,uint point,uint previous,uint owner){throw new InvalidOperationException("Disabled native scheduler rows expected.");}},formation,callback);};
    uint creature=input.ContainsKey("missing")&&(string)input["missing"]=="creature"?0:C;uint result;
    if(kind=="range"){result=PcObjectImage.ToBits(ForwardOriginCommands.OriginRange(movement,B(input,"worldNull",false)?0:W,creature));memory.Set32(RESULT,result);}
    else result=ForwardOriginCommands.MoveForward(world,P,creature,Tokens(row["tokens"]),Convert.ToBoolean(row["first"]),D+(uint)before.Length)?1u:0u;
    bool image=Equal(memory.Bytes,Image(row["after"])),fr=world.FloatRandom.State==Convert.ToUInt32(row["floatRng"]),ir=world.IntegerRandom.Global.State==Convert.ToUInt32(row["integerRng"]),order=json.Serialize(events)==json.Serialize(row["events"]),ret=result==Convert.ToUInt32(row["result"]);checks+=5;
    if(!image||!fr||!ir||!order||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,floatRng=fr,integerRng=ir,order=order,ret=ret,events=events,result=result});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Forward/origin comparisons:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
