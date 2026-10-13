using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowSelectionHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static float[] Floats(byte[] b,int p,int count){var v=new float[count];for(int i=0;i<count;++i)v[i]=BitConverter.ToSingle(b,p+i*4);return v;}
    static float[] V(object values){return Array.ConvertAll(A(values),v=>Convert.ToSingle(v));}
    static void Store(byte[] b,int p,float[] v){for(int i=0;i<v.Length;++i)Array.Copy(BitConverter.GetBytes(v[i]),0,b,p+i*4,4);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();var reference=M(fixture["sineTable"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));byte[] table=File.ReadAllBytes(Path.Combine(root,(string)reference["file"]));if(table.Length!=32768*4||Hash(table)!=(string)reference["sha256"])throw new InvalidDataException();float[] sine=Floats(table,0,32768);uint baseAddress=U(fixture["base"]),mirror=U(fixture["globalMirror"]);int projection=(int)(U(fixture["projection"])-baseAddress),view=(int)(U(fixture["view"])-baseAddress);
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var cfg=M(c["config"]);byte[] bytes=Hex((string)c["before"]);var memory=new RenderPacketMemory(baseAddress,bytes);object[] contexts=A(fixture["contexts"]),power=A(c["powerBoundary"]);int powerCalls=0;
            var state=new ShadowSelectionState{World=U(fixture["world"]),CameraInfo=U(fixture["info"]),DefaultCamera=U(fixture["camera"]),AlternateCamera=U(fixture["alternateCamera"]),FixedCamera=U(fixture["fixedCamera"]),FirstContext=U(contexts[0]),SecondContext=U(contexts[1]),ScratchCuts=U(fixture["cutMirror"]),Players=Array.ConvertAll(A(cfg["players"]),v=>U(v)),Mode=Convert.ToInt32(cfg["mode"])!=0,AlternateView=Convert.ToInt32(cfg["alternate"])!=0,DirectionSeed=V(cfg["seed"]),Tuning=V(fixture["constants"]),SineTable=sine,Projection=new float[16],View=new float[16],Height=BitConverter.ToSingle(BitConverter.GetBytes(memory.Dword(mirror)),0),Mask=memory.Dword(mirror+4)};
            state.Power=(a,b)=>{if(powerCalls>=power.Length)throw new InvalidDataException("Unexpected power boundary call.");var expected=M(power[powerCalls++]);float[] parameters=V(expected["arguments"]);if(a!=parameters[0]||b!=parameters[1])throw new InvalidDataException("Power boundary inputs differ.");return Convert.ToSingle(expected["result"]);};bool updated=ShadowSelection.Update(memory,state);Store(bytes,(int)(mirror-baseAddress),new float[]{state.Height});memory.Dword(mirror+4,state.Mask);if(updated){Store(bytes,projection,state.Projection);Store(bytes,view,state.View);}string digest=Hash(bytes);bool pass=digest==(string)c["nativeSHA256"]&&updated==(A(c["nativeEvents"]).Length!=0)&&powerCalls==power.Length;++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],updated,powerCalls});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
