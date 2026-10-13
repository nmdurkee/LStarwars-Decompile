using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowPowerHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static float Float(uint word){return BitConverter.ToSingle(BitConverter.GetBytes(word),0);}
    static uint Word(float value){return BitConverter.ToUInt32(BitConverter.GetBytes(value),0);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");
        Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));
        int checks=0,failures=0;var errors=new List<object>();
        int valueOffset=Convert.ToInt32(fixture["valueOffset"]),exponentOffset=Convert.ToInt32(fixture["exponentOffset"]),resultOffset=Convert.ToInt32(fixture["resultOffset"]),nextOffset=Convert.ToInt32(fixture["nextOffset"]);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Hex((string)c["before"]);var cache=new ShadowPowerCache{Initialize=U(c["flag"]),Next=BitConverter.ToUInt32(bytes,nextOffset)};
            for(int i=0;i<32;++i){cache.Values[i]=BitConverter.ToSingle(bytes,valueOffset+i*4);cache.Exponents[i]=BitConverter.ToSingle(bytes,exponentOffset+i*4);cache.Results[i]=BitConverter.ToSingle(bytes,resultOffset+i*4);}
            int calls=0;uint inputWord=U(c["valueWord"]),exponentWord=U(c["exponentWord"]),expectedWord=U(c["resultWord"]);
            float returned=ShadowPower.Evaluate(cache,Float(inputWord),Float(exponentWord),delegate(float value,float exponent){++calls;if(Word(value)!=inputWord||Word(exponent)!=exponentWord)throw new InvalidOperationException("Backend arguments differ from original.");return Float(expectedWord);});
            for(int i=0;i<32;++i){Array.Copy(BitConverter.GetBytes(cache.Values[i]),0,bytes,valueOffset+i*4,4);Array.Copy(BitConverter.GetBytes(cache.Exponents[i]),0,bytes,exponentOffset+i*4,4);Array.Copy(BitConverter.GetBytes(cache.Results[i]),0,bytes,resultOffset+i*4,4);}
            Array.Copy(BitConverter.GetBytes(cache.Next),0,bytes,nextOffset,4);var state=new byte[bytes.Length+4];Array.Copy(BitConverter.GetBytes(cache.Initialize),state,4);Array.Copy(bytes,0,state,4,bytes.Length);
            string digest=Hash(state);++checks;
            if(digest!=(string)c["nativeSHA256"]||Word(returned)!=expectedWord||calls!=Convert.ToInt32(c["backendCalls"]))
            {++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],returnedWord=Word(returned),expectedWord,calls});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
