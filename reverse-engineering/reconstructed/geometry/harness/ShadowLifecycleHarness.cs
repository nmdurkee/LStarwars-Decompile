using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowLifecycleHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Expand(string text){using(var f=new MemoryStream(Convert.FromBase64String(text)))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var output=new MemoryStream()){z.CopyTo(output);return output.ToArray();}}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();uint source=U(fixture["source"]),control=U(fixture["control"]);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Expand((string)c["beforeZ"]);if(bytes.Length!=Convert.ToInt32(fixture["size"]))throw new InvalidDataException();var m=new RenderPacketMemory(U(fixture["base"]),bytes);uint? result=null;uint arg=U(c["arg"]);
            switch((string)c["operation"])
            {
                case "enable":ShadowContextLifecycle.SetEnabled(m,source,arg);break;
                case "volume":ShadowContextLifecycle.CopyVolume(m,arg,source);break;
                case "context":ShadowContextLifecycle.CopyContext(m,arg,source);break;
                case "snapshot":result=ShadowContextLifecycle.Snapshot(m,source,control);break;
                default:throw new InvalidDataException();
            }
            string digest=Hash(bytes);bool pass=digest==(string)c["nativeSHA256"]&&(c["nativeReturn"]==null?!result.HasValue:result.HasValue&&result.Value==U(c["nativeReturn"]));++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],result,expectedReturn=c["nativeReturn"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
