using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class MovementPhase520261013Verify
{
 static Dictionary<string,object> M(object x){return(Dictionary<string,object>)x;}
 static int I(Dictionary<string,object> x,string k,int d){return x.ContainsKey(k)?Convert.ToInt32(x[k]):d;}
 static bool B(Dictionary<string,object> x,string k,bool d){return x.ContainsKey(k)?Convert.ToBoolean(x[k]):d;}
 static byte[] Image(object text){using(var s=new MemoryStream(Convert.FromBase64String((string)text)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int i=0;i<a.Length;i++)if(a[i]!=b[i])return false;return true;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output paths required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int count=0,failed=0,checks=0;var errors=new List<object>();
  foreach(object item in(object[])data["vectors"])
  {
   var row=M(item);var input=M(row["input"]);count++;
   try
   {
    const uint D=0x10100000,CB=0x10200100;var memory=new OriginPathMemory(D,Image(row["before"]));var events=new List<object>();
    var world=new FormationScheduleWorld{Memory=memory};world.Callback=delegate(uint cb,uint formation,uint point,uint previous,uint owner)
    {
     events.Add(new object[]{formation,point,previous,owner});int index=(int)((point-D-0x54)/0x34);memory.Set8(point+0x30,memory.U8(point+0x30)^I(input,"toggleRow",0));
     if(B(input,"mutate",false))
     {
      memory.Set8(D+6,I(input,"newCount",2));memory.Set32(D,memory.U32(D)+4);memory.Set32(D+0x50,memory.U32(D+0x50)^4);
      if(index+1<255)memory.Set8(D+0x54+(uint)(index+1)*0x34+0x2d,1);
     }
     return index==I(input,"stop",-1);
    };
    FormationScheduling.Dispatch(world,D,B(input,"callback",true)?CB:0);
    bool image=Equal(memory.Bytes,Image(row["after"])),order=json.Serialize(events)==json.Serialize(row["events"]);checks+=2;
    if(!image||!order){failed++;if(errors.Count<10)errors.Add(new{input=input,image=image,order=order,events=events});}
   }
   catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=count,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Formation scheduling comparisons:"+count+", failures:"+failed);return failed==0?0:1;
 }
}
