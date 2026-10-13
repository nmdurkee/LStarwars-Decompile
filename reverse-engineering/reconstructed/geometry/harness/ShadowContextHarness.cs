using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowContextHarness
{
    static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}static uint U(object o){return Convert.ToUInt32(o);}
    static string Hash(byte[] bytes){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(bytes)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in (object[])fixture["cases"])
        {
            var c=M(item);var memory=new RenderPacketMemory(U(fixture["base"]),Hex((string)c["before"]));var calls=ShadowContextEmission.Emit(memory,U(c["control"]),U(c["record"]),U(c["shader"]),U(c["descriptor"]));string digest=Hash(memory.Bytes);var expected=(object[])c["nativeCalls"];bool pass=digest==(string)c["nativeSHA256"]&&calls.Count==expected.Length;for(int i=0;i<calls.Count&&i<expected.Length;++i)pass=pass&&calls[i]==U(expected[i]);++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],calls,nativeCalls=expected});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
