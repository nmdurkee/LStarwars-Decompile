using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowVolumeHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static float[] Floats(byte[] b,int p,int count){var v=new float[count];for(int i=0;i<count;++i)v[i]=BitConverter.ToSingle(b,p+i*4);return v;}
    static void Store(byte[] b,int p,float[] v,int count){for(int i=0;i<count;++i)Array.Copy(BitConverter.GetBytes(v[i]),0,b,p+i*4,4);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();uint baseAddress=U(fixture["base"]);int direction=(int)(U(fixture["direction"])-baseAddress),corners=(int)(U(fixture["corners"])-baseAddress),output=(int)(U(fixture["output"])-baseAddress),center=(int)(U(fixture["center"])-baseAddress),position=(int)(U(fixture["position"])-baseAddress),radius=(int)(U(fixture["radius"])-baseAddress);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Hex((string)c["before"]);int? returned=null;float[] d=Floats(bytes,direction,3),points=Floats(bytes,corners,32);
            if((string)c["kind"]=="planes"){float[] planes=Floats(bytes,output,36);returned=ShadowVolume.SelectPlanes(d,points,planes);Store(bytes,output,planes,returned.Value*4);}
            else{float[] cc=Floats(bytes,center,4),pp=Floats(bytes,position,4);float rr=ShadowVolume.Aggregate(d,points,cc,pp);Store(bytes,center,cc,4);Store(bytes,position,pp,3);Store(bytes,radius,new float[]{rr},1);}
            string digest=Hash(bytes);bool pass=digest==(string)c["nativeSHA256"]&&(c["nativeReturn"]==null?!returned.HasValue:returned.HasValue&&returned.Value==Convert.ToInt32(c["nativeReturn"]));++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],returned});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
