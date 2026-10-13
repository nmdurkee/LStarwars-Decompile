using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class BackendInitializationPhase13Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static byte[] Hex(string s){byte[] r=new byte[s.Length/2];for(int i=0;i<r.Length;++i)r[i]=Convert.ToByte(s.Substring(i*2,2),16);return r;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool ok,string label){++checks;if(!ok){++failures;if(errors.Count<20)errors.Add(label);}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object value in(object[])f["cases"]){var c=Map(value);byte[] image=Hex((string)c["beforeHex"]);byte[] result=RenderBackendInitialization.Apply(image);Check(Hex(image)==(string)c["nativeHex"],"all original initialized/preserved bytes "+cases);Check(Object.ReferenceEquals(result,image)&&Convert.ToBoolean(c["returnedReceiver"]),"original receiver identity "+cases);++cases;}
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Whole original backend constructor byte image, preserved gaps and receiver identity. No device/bootstrap or separate runtime global initialization claim."}));return failures==0?0:1;
 }
}
