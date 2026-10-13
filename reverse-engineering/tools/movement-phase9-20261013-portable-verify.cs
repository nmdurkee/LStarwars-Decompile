using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase920261013Verify
{
 static Dictionary<string,object> M(object x){return(Dictionary<string,object>)x;}
 static int I(Dictionary<string,object> x,string k,int d){return x.ContainsKey(k)?Convert.ToInt32(x[k]):d;}
 static uint U(Dictionary<string,object> x,string k,uint d){return x.ContainsKey(k)?Convert.ToUInt32(x[k]):d;}
 static bool B(Dictionary<string,object> x,string k,bool d){return x.ContainsKey(k)?Convert.ToBoolean(x[k]):d;}
 static byte[] Image(object text){using(var s=new MemoryStream(Convert.FromBase64String((string)text)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
 static void Set(byte[] b,int o,uint v){for(int i=0;i<4;i++)b[o+i]=unchecked((byte)(v>>(i*8)));}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int i=0;i<a.Length;i++)if(a[i]!=b[i])return false;return true;}
 static string[] Tokens(object o){object[] a=(object[])o;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object v in(object[])data["vectors"])
  {
   var row=M(v);var input=M(row["input"]);string kind=(string)row["kind"];cases++;try
   {
    const uint D=0x10100000,SPL=D+0x10000;byte[] image=Image(row["before"]);var world=new RandomSplineWorld{HasWorldPointer=!B(input,"noWorld",false),HasScene=!B(input,"noScene",false)};world.Random.State=U(input,"seed",123);
    var records=new List<SelectedSplineRecord>();foreach(object rr in(object[])data["records"]){int ix=records.Count;var r=M(rr);int p=0x10000+ix*12;records.Add(new SelectedSplineRecord{Address=SPL+(uint)ix*12,Name=(string)r["name"],Flags=(ushort)(image[p]|image[p+1]<<8)});}
    for(int i=0;i<Math.Max(0,I(input,"sceneCount",40));i++)world.Splines.Add(records[i]);world.Selected=records[7];world.ResolveAttachedSpline=delegate(uint id){foreach(var r in records)if(r.Address==id)return r;return null;};
    for(int i=0;i<Math.Max(0,I(input,"actorCount",4));i++){byte[] actor=new byte[PcObjectImage.Size];Array.Copy(image,0x20000+i*0x10d8,actor,0,actor.Length);world.Actors.Add(new PcObjectImage(actor));}
    bool fault=false;uint result=0;string a=input.ContainsKey("a")?(string)input["a"]:null,b=input.ContainsKey("b")?(string)input["b"]:null;
    try
    {
     if(kind=="compare")result=unchecked((uint)RandomSplineSelection.Compare(a,b,I(input,"length",-1)));
     else if(kind=="find"){var r=RandomSplineSelection.Find(world,a);result=r==null?0:r.Address;}
     else if(kind=="prefix"){var output=new List<SelectedSplineRecord>();result=(uint)RandomSplineSelection.FindPrefix(world,a,output,I(input,"capacity",32));for(int i=0;i<output.Count;i++)Set(image,0x9000+i*4,output[i].Address);}
     else result=RandomSplineSelection.Select(world,Tokens(row["tokens"]),Convert.ToBoolean(row["first"]))?1u:0u;
    }catch(InvalidOperationException){fault=true;}
    for(int i=0;i<records.Count;i++){int p=0x10000+i*12;image[p]=unchecked((byte)records[i].Flags);image[p+1]=unchecked((byte)(records[i].Flags>>8));}
    bool state=Equal(image,Image(row["after"])),rng=world.Random.State==Convert.ToUInt32(row["seed"]),selected=(world.Selected==null?0:world.Selected.Address)==Convert.ToUInt32(row["selected"]),faultMatch=fault==Convert.ToBoolean(row["fault"]),ret=fault||result==Convert.ToUInt32(row["result"]);checks+=5;
    if(!state||!rng||!selected||!faultMatch||!ret){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,state=state,rng=rng,selected=selected,fault=fault,faultMatch=faultMatch,ret=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Spline selection/lookup comparisons:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
