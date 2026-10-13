using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
using Recovered.Animation;
public static class ObjectSwayHarness
{
    static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}static object[] A(object o){return(object[])o;}
    static uint U(object o){return Convert.ToUInt32(o);}static int I(object o){return Convert.ToInt32(o);}static float F(object o){return PcObjectImage.FromBits(U(o));}
    static string Hash(byte[] b){using(var sha=SHA256.Create())return BitConverter.ToString(sha.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string h){byte[] b=new byte[h.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(h.Substring(i*2,2),16);return b;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var file=File.OpenRead(args[0]))using(var z=new GZipStream(file,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(json.DeserializeObject(r.ReadToEnd()));
        var reference=M(fixture["sineTable"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));byte[] table=File.ReadAllBytes(Path.Combine(root,(string)reference["file"]));if(Hash(table)!=(string)reference["sha256"]||table.Length!=32768*4)throw new InvalidDataException("Original sine fixture changed");var sine=new float[32768];for(int i=0;i<sine.Length;++i)sine[i]=BitConverter.ToSingle(table,i*4);
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] before=Hex((string)c["before"]);var memory=new RenderPacketMemory(0x10100000,before);var state=new ObjectSwayState{FrameCounter=U(c["time"]),Amplitude=F(c["amplitude"]),Rate=F(c["rate"]),UseSseConversion=Convert.ToBoolean(c["sse"]),SineTable=sine};ObjectSwayCoefficients result;
            if((string)c["kind"]=="coefficients"){result=ObjectSway.Coefficients(state,I(c["a"]),I(c["seed"]));memory.Dword(memory.BaseAddress,PcObjectImage.ToBits(result.X));memory.Dword(memory.BaseAddress+4,PcObjectImage.ToBits(result.Z));}
            else result=ObjectSway.Transform(memory,memory.BaseAddress+U(c["out"]),memory.BaseAddress+U(c["source"]),state,I(c["a"]),I(c["seed"]));
            string digest=Hash(before);var expected=A(c["nativeAngles"]);bool pass=digest==(string)c["nativeSHA256"]&&result.Angles.Count==expected.Length;for(int i=0;i<expected.Length&&i<result.Angles.Count;++i)pass=pass&&result.Angles[i]==U(expected[i]);
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],angles=result.Angles,nativeAngles=expected});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
