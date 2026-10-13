using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowConstructionHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Expand(string text){using(var f=new MemoryStream(Convert.FromBase64String(text)))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var output=new MemoryStream()){z.CopyTo(output);return output.ToArray();}}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();uint cp=U(fixture["contextPool"]),hp=U(fixture["commandPool"]),sp=U(fixture["shaderPool"]);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Expand((string)c["beforeZ"]);if(bytes.Length!=Convert.ToInt32(fixture["size"]))throw new InvalidDataException();var m=new RenderPacketMemory(U(fixture["base"]),bytes);uint result,arg=U(c["arg"]);
            switch((string)c["operation"])
            {
                case "context-pool":result=ShadowContextConstruction.AllocateContext(m,arg);break;
                case "shader-pool":result=ShadowContextConstruction.AllocateShaderContext(m,arg);break;
                case "command-pool":result=ShadowContextConstruction.AllocateCommand(m,arg);break;
                case "volume":result=ShadowContextConstruction.InitializeVolume(m,arg,hp,sp);break;
                case "context":result=ShadowContextConstruction.InitializeContext(m,arg,hp,sp);break;
                case "create":result=ShadowContextConstruction.Create(m,cp,hp,sp);break;
                default:throw new InvalidDataException();
            }
            string digest=Hash(bytes);bool pass=digest==(string)c["nativeSHA256"]&&result==U(c["nativeReturn"]);++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],result,expectedReturn=c["nativeReturn"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
