using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase420261013Verify
{
 static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
 static bool Flag(Dictionary<string,object> v,string k,bool fallback){return v.ContainsKey(k)?Convert.ToBoolean(v[k]):fallback;}
 static uint U(Dictionary<string,object> v,string k,uint fallback){return v.ContainsKey(k)?Convert.ToUInt32(v[k]):fallback;}
 static byte[] Image(object text){using(var s=new MemoryStream(Convert.FromBase64String((string)text)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int i=0;i<a.Length;i++)if(a[i]!=b[i])return false;return true;}
 static string[] Tokens(object value){object[] a=(object[])value;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Gzip fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  object[] words=(object[])data["table"];float[] table=new float[words.Length];for(int i=0;i<words.Length;i++)table[i]=PcObjectImage.FromBits(Convert.ToUInt32(words[i]));
  int count=0,assertions=0,failed=0;var errors=new List<object>();
  foreach(object item in(object[])data["cases"])
  {
   var row=M(item);var meta=M(row["meta"]);string kind=(string)row["kind"];count++;
   try
   {
    const uint D=0x10100000,C=D,P=D+0x2000,W=D+0x3000,F=D+0x5000,O=D+0x6000;
    var memory=new OriginPathMemory(D,Image(row["before"]));var events=new List<object>();
    var world=new OriginPathWorld{Memory=memory,SineTable=table};world.Expressions.Random.State=U(meta,"seed",123);
    if(Flag(meta,"originCallback",true))world.OriginPosition=delegate(uint w,uint c){bool available=Flag(meta,"origin",false);events.Add(new object[]{"origin",available});return available?O:0;};
    if(Flag(meta,"tokenCallback",true))world.MovementToken=delegate(string t,uint p){int mode=String.Equals(t,"walk",StringComparison.OrdinalIgnoreCase)?17:String.Equals(t,"run",StringComparison.OrdinalIgnoreCase)?34:-1;events.Add(new object[]{"token",t,mode>=0});if(mode>=0)memory.Set8(p,mode);return mode>=0;};
    world.Schedule=delegate(uint callback){events.Add(new object[]{"schedule","0x"+callback.ToString("x")});if(Flag(meta,"mutateFormation",false)){memory.SetFloat(F+0x128,2.125f);memory.Set8(F+0x50,12);}};
    uint creature=meta.ContainsKey("missing")&&(string)meta["missing"]=="creature"?0:C;bool first=Convert.ToBoolean(row["first"]);float delta=PcObjectImage.FromBits(Convert.ToUInt32(row["delta"]));string[] tokens=Tokens(row["tokens"]);int result=0;
    if(kind=="formation")OriginPathCommands.FormationIntent(world,creature);
    else if(kind=="origin")result=OriginPathCommands.GoToOrigin(world,W,P,creature,tokens,first,delta)?1:0;
    else result=OriginPathCommands.FollowPath(world,P,creature,tokens,first,delta)?1:0;
    bool image=Equal(memory.Bytes,Image(row["after"]));bool rng=world.Expressions.Random.State==Convert.ToUInt32(row["seed"]);bool order=json.Serialize(events)==json.Serialize(row["events"]);bool ret=kind=="formation"||result==Convert.ToInt32(row["result"]);assertions+=kind=="formation"?3:4;
    if(!image||!rng||!order||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=meta,tokens=tokens,image=image,rng=rng,order=order,ret=ret,events=events});}
   }
   catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=count,assertionGroups=assertions,failures=failed,examples=errors}));Console.WriteLine("Origin/path/formation comparisons:"+count+", failures:"+failed);return failed==0?0:1;
 }
}
