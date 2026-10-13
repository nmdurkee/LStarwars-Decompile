using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowExtractionHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static float[] Floats(byte[] b,int p,int count){var v=new float[count];for(int i=0;i<count;++i)v[i]=BitConverter.ToSingle(b,p+i*4);return v;}
    static void Store(byte[] b,int p,float[] v){for(int i=0;i<v.Length;++i)Array.Copy(BitConverter.GetBytes(v[i]),0,b,p+i*4,4);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();var reference=M(fixture["sineTable"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));byte[] table=File.ReadAllBytes(Path.Combine(root,(string)reference["file"]));if(table.Length!=32768*4||Hash(table)!=(string)reference["sha256"])throw new InvalidDataException();float[] sine=Floats(table,0,32768);uint baseAddress=U(fixture["base"]);int projection=(int)(U(fixture["projection"])-baseAddress),view=(int)(U(fixture["view"])-baseAddress);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Hex((string)c["before"]);var memory=new RenderPacketMemory(baseAddress,bytes);var pp=new float[16];var vv=new float[16];ShadowExtraction.Extract(memory,U(fixture["context"]),U(fixture["camera"]),U(fixture["cuts"]),Convert.ToInt32(c["cutCount"]),sine,pp,vv);Store(bytes,projection,pp);Store(bytes,view,vv);string digest=Hash(bytes);++checks;if(digest!=(string)c["nativeSHA256"]){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
