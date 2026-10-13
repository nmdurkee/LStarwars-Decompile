using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase2120261013Verify
{
 static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
 static bool B(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
 static byte[] Image(object o){using(var s=new MemoryStream(Convert.FromBase64String((string)o)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new MemoryStream()){z.CopyTo(r);return r.ToArray();}}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int j=0;j<a.Length;j++)if(a[j]!=b[j])return false;return true;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  object[] rawTable=(object[])data["table"];float[]table=new float[rawTable.Length];for(int j=0;j<table.Length;j++)table[j]=PcObjectImage.FromBits(Convert.ToUInt32(rawTable[j]));int cases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object o in(object[])data["vectors"])
  {
   var row=M(o);var input=M(row["input"]);string kind=(string)row["kind"];cases++;
   try
   {
    const uint D=0x10100000,MATRIX=D+0x1000,INPUT=D+0x2000,OUT=D+0x3000;
    var memory=new OriginPathMemory(D,Image(row["before"]));int angle=input.ContainsKey("angle")?Convert.ToInt32(input["angle"]):12345;
    switch(kind){case "x":PodMatrixMath.RotateX(memory,MATRIX,angle,table);break;case "y":PodMatrixMath.RotateY(memory,MATRIX,angle,table);break;case "z":PodMatrixMath.RotateZ(memory,MATRIX,angle,table);break;default:PodMatrixMath.TransformVector(memory,input.ContainsKey("output")?Convert.ToUInt32(input["output"]):OUT,input.ContainsKey("source")?Convert.ToUInt32(input["source"]):INPUT,MATRIX);break;}
    bool image=Equal(memory.Bytes,Image(row["after"]));checks++;if(!image){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,image=image});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind=kind,input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=cases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Pod matrix cases:"+cases+", failures:"+failed);return failed==0?0:1;
 }
}
