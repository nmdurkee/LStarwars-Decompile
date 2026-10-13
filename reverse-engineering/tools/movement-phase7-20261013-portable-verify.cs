using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase720261013Verify
{
 static Dictionary<string,object> M(object x){return(Dictionary<string,object>)x;}
 static int I(Dictionary<string,object> x,string k,int d){return x.ContainsKey(k)?Convert.ToInt32(x[k]):d;}
 static uint U(Dictionary<string,object> x,string k,uint d){return x.ContainsKey(k)?Convert.ToUInt32(x[k]):d;}
 static bool B(Dictionary<string,object> x,string k,bool d){return x.ContainsKey(k)?Convert.ToBoolean(x[k]):d;}
 static byte[] Bytes(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static uint Word(byte[] b,int o){return(uint)b[o]|(uint)b[o+1]<<8|(uint)b[o+2]<<16|(uint)b[o+3]<<24;}
 static void Set(byte[] b,int o,uint v){for(int i=0;i<4;i++)b[o+i]=unchecked((byte)(v>>(8*i)));}
 static uint[] Position(Dictionary<string,object> x,string k,uint[] d){if(!x.ContainsKey(k))return d;object[] a=(object[])x[k];return new uint[]{Convert.ToUInt32(a[0]),Convert.ToUInt32(a[1]),Convert.ToUInt32(a[2])};}
 static string[] Tokens(object o){object[] a=(object[])o;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output paths required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object v in(object[])data["vectors"])
  {
   var row=M(v);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,SECOND=D+0x40000;object[] raw=(object[])row["actors"];var actors=new PcObjectImage[]{new PcObjectImage(Bytes((string)raw[0])),new PcObjectImage(Bytes((string)raw[1]))};var events=new List<object>();byte[] globals=Bytes((string)row["before"]);
    var world=new CreatureAlertWorld{SourceActor=Word(globals,0x28),DurationBits=Word(globals,0x2c),RuntimeDurationBits=U(input,"duration",0x7fc98765)};
    for(int i=0;i<3;i++)world.PositionBits[i]=Word(globals,8+4*i);
    world.TypeFlags=delegate(uint definition){if(definition==0||B(input,"missingType",false))throw new InvalidOperationException("Native null definition/type fault.");return U(input,"typeFlags",0);};
    if(B(input,"characterCallback",true))world.ResolveCharacter=delegate(string name){events.Add(new object[]{"character",name});return name=="Self"?(I(input,"gate",3)==2?null:actors[0]):name=="Other"?actors[1]:null;};
    bool fault=false;bool result=false;
    try
    {
     if(kind=="body")
     {
      int target=input.ContainsKey("bodyTarget")&&input["bodyTarget"]==null?-1:I(input,"bodyTarget",0);
      CreatureAlerts.Produce(world,target<0?0:target==0?D:SECOND,target<0?null:actors[target],Position(input,"bodyPosition",new uint[]{0xffffffff,0x80000000,0x7f800000}));
     }
     else result=CreatureAlerts.Alert(world,D,I(input,"gate",3)==3?actors[0]:null,Tokens(row["tokens"]),Convert.ToBoolean(row["first"]),delegate(PcObjectImage actor){return Object.ReferenceEquals(actor,actors[0])?D:SECOND;});
    }catch(InvalidOperationException){fault=true;}
    for(int i=0;i<3;i++)Set(globals,8+4*i,world.PositionBits[i]);Set(globals,0x28,world.SourceActor);Set(globals,0x2c,world.DurationBits);
    bool image=Hex(globals)==(string)row["after"],confined=Hex(actors[0].Bytes)==(string)raw[0]&&Hex(actors[1].Bytes)==(string)raw[1],order=json.Serialize(events)==json.Serialize(row["events"]),faultMatch=fault==Convert.ToBoolean(row["fault"]),ret=kind=="body"||fault||result;checks+=kind=="body"?4:5;
    if(!image||!confined||!order||!faultMatch||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image,confined=confined,order=order,fault=fault,faultMatch=faultMatch,ret=ret,events=events});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Alert command/producer comparisons:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
