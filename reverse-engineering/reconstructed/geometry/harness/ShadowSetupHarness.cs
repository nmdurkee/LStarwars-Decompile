using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowSetupHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Inflate(byte[] b){using(var f=new MemoryStream(b))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");
        var fixture=M(Json.DeserializeObject(System.Text.Encoding.UTF8.GetString(Inflate(File.ReadAllBytes(args[0])))));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Inflate(Convert.FromBase64String((string)c["beforeZ"]));var memory=new RenderPacketMemory(U(fixture["base"]),bytes);uint[] contexts=new uint[]{0x12345678,0x87654321};uint context=U(c["context"]),selector=U(c["selector"]),word=U(c["word"]);float value=BitConverter.ToSingle(BitConverter.GetBytes(word),0);
            switch((string)c["kind"])
            {
                case "float":ShadowSetup.SetFloat(memory,context,selector,value);break;
                case "cdecl":ShadowSetup.SetFloatCdecl(memory,context,selector,value);break;
                case "integer":ShadowSetup.SetInteger(memory,context,selector,word);break;
                case "initialize":contexts=ShadowSetup.Initialize(memory,U(fixture["contextPool"]),U(fixture["commandPool"]),U(fixture["shaderPool"]));break;
                default:throw new ArgumentException("Unknown fixture operation.");
            }
            byte[] all=new byte[bytes.Length+8];Array.Copy(BitConverter.GetBytes(contexts[0]),0,all,0,4);Array.Copy(BitConverter.GetBytes(contexts[1]),0,all,4,4);Array.Copy(bytes,0,all,8,bytes.Length);string digest=Hash(all);++checks;
            if(digest!=(string)c["nativeSHA256"]){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
