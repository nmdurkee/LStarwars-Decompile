using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowPlayersHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static float Float(object word){return BitConverter.ToSingle(BitConverter.GetBytes(U(word)),0);}
    static void Store(byte[] b,int p,float[] v){for(int i=0;i<v.Length;++i)Array.Copy(BitConverter.GetBytes(v[i]),0,b,p+i*4,4);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();uint baseAddress=U(fixture["base"]);int output=(int)(U(fixture["output"])-baseAddress),strength=(int)(U(fixture["strength"])-baseAddress);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Hex((string)c["before"]);var memory=new RenderPacketMemory(baseAddress,bytes);uint[] players=Array.ConvertAll(A(c["players"]),v=>U(v));var result=new float[3];int returned;
            if((string)c["kind"]=="position"){bool found=ShadowPlayers.AveragePosition(memory,players,result);returned=found?1:0;if(found)Store(bytes,output,result);}else{float value;returned=ShadowPlayers.AverageDirection(memory,players,Array.ConvertAll(A(c["seedWords"]),v=>Float(v)),result,out value);Store(bytes,output,result);Store(bytes,strength,new float[]{value});}
            string digest=Hash(bytes);++checks;if(digest!=(string)c["nativeSHA256"]||returned!=Convert.ToInt32(c["nativeReturn"])){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],returned});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
