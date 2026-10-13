using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase2020261013Verify
{
 static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static byte[] Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,CURVE=D+0x1000;
    var memory=new OriginPathMemory(D,Image(row["before"]));uint output=Convert.ToUInt32(row["output"]);float parameter=PcObjectImage.FromBits(Convert.ToUInt32(row["parameterBits"]));
    if(kind=="normalize"){float[]v=memory.Vector(Convert.ToUInt32(row["source"]));SpawnVector unit=PodCurveEvaluation.NormalizeStored(new SpawnVector(v[0],v[1],v[2]));memory.SetVector(output,new float[]{unit.X,unit.Y,unit.Z});}
    else if(kind=="normalized")PodCurveEvaluation.Normalized(memory,CURVE,output,parameter);else PodCurveEvaluation.Distance(memory,CURVE,output,parameter);
    bool image=Equal(memory.Bytes,Image(row["after"]));checks++;if(!image){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,output=output,parameterBits=row["parameterBits"],image=image});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Pod curve cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
