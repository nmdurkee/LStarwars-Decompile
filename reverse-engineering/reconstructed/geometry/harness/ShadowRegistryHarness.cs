using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowRegistryHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Expand(string text){using(var f=new MemoryStream(Convert.FromBase64String(text)))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var output=new MemoryStream()){z.CopyTo(output);return output.ToArray();}}
    static bool Same(uint[] x,object[] y){if(x.Length!=y.Length)return false;for(int i=0;i<x.Length;++i)if(x[i]!=U(y[i]))return false;return true;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var initial=M(c["state"]);var expected=M(c["nativeState"]);byte[] bytes=Expand((string)c["beforeZ"]);if(bytes.Length!=Convert.ToInt32(fixture["size"]))throw new InvalidDataException();var memory=new RenderPacketMemory(U(fixture["base"]),bytes);var s=new ShadowContextRegistryState{Count=Convert.ToInt32(initial["count"]),CacheFlag=U(initial["flag"]),Contexts=Array.ConvertAll(A(initial["contexts"]),U),Masks=Array.ConvertAll(A(initial["masks"]),U)};uint? result=null;
            switch((string)c["operation"])
            {
                case "register":ShadowContextRegistry.Register(memory,s,U(c["arg"]));break;
                case "reset":ShadowContextRegistry.Reset(memory,s);break;
                case "count":result=unchecked((uint)ShadowContextRegistry.GetCount(s));break;
                case "any":result=ShadowContextRegistry.HasContexts(s)?1u:0;break;
                case "context":result=ShadowContextRegistry.GetContext(s,Convert.ToInt32(c["arg"]));break;
                case "mask":result=ShadowContextRegistry.GetMask(s,Convert.ToInt32(c["arg"]));break;
                default:throw new InvalidDataException();
            }
            string digest=Hash(bytes);bool pass=digest==(string)c["nativeSHA256"]&&s.Count==Convert.ToInt32(expected["count"])&&s.CacheFlag==U(expected["flag"])&&Same(s.Contexts,A(expected["contexts"]))&&Same(s.Masks,A(expected["masks"]))&&(c["nativeReturn"]==null?!result.HasValue:result.HasValue&&result.Value==U(c["nativeReturn"]));++checks;
            if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],count=s.Count,flag=s.CacheFlag,result});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
