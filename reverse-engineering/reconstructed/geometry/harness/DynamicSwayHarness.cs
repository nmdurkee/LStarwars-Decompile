using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class DynamicSwayHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static Dictionary<string,object> Read(string p){using(var f=File.OpenRead(p))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))return M(Json.DeserializeObject(r.ReadToEnd()));}
    static byte[] Expand(string text){using(var f=new MemoryStream(Convert.FromBase64String(text)))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var output=new MemoryStream()){z.CopyTo(output);return output.ToArray();}}
    static float[] Floats(RenderPacketMemory m,uint p,int count){float[] v=new float[count];for(int i=0;i<count;++i)v[i]=BitConverter.ToSingle(m.Block(p+(uint)i*4,4),0);return v;}
    static float[] Values(object v){return Array.ConvertAll(A(v),x=>Convert.ToSingle(x));}
    static void Store(RenderPacketMemory m,uint p,float[] v){for(int i=0;i<v.Length;++i)m.Block(p+(uint)i*4,BitConverter.GetBytes(v[i]));}
    static bool Same(object a,object b){IList x=a as IList,y=b as IList;if(x!=null&&y!=null){if(x.Count!=y.Count)return false;for(int i=0;i<x.Count;++i)if(!Same(x[i],y[i]))return false;return true;}return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);var reference=M(fixture["sineTable"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));byte[] table=File.ReadAllBytes(Path.Combine(root,(string)reference["file"]));if(table.Length!=32768*4||Hash(table)!=(string)reference["sha256"])throw new InvalidDataException();var sine=new float[32768];for(int i=0;i<sine.Length;++i)sine[i]=BitConverter.ToSingle(table,i*4);uint scratch=U(fixture["swayScratch"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var o=M(c["options"]);byte[] bytes=Expand((string)c["beforeZ"]);if(bytes.Length!=65536)throw new InvalidDataException();var m=new RenderPacketMemory(0x10100000,bytes);var s=new DynamicSubmissionState{ForcedVisibility=I(o["forcedVisibility"]),ForcedLod=I(o["forcedLod"]),FilterMode=I(o["filterMode"]),ShadowMask=U(o["shadowMask"]),ShadowMetadataDisabled=I(o["shadowMetadataDisabled"]),GlobalOverride=U(o["globalOverride"]),OverrideTable=U(o["overrideTable"]),OverrideFirst=U(o["overrideFirst"]),OverrideScalarWord=U(o["overrideScalarWord"]),ScratchInputs=Array.ConvertAll(A(o["uv"]),U),CameraPosition=Values(o["camera"]),AllocatorControl=0x10100000,Shader=0x10106000,TokenBase=0x12345678,ScaleScratch=0x10106200,TranslationScratch=0x10106240,CacheScratch=0x10106300,OutputScratch=0x10106310};
            s.Box=new DynamicBoxState{Enabled=I(o["enabled"])!=0,View=Values(o["view"]),Near=Convert.ToSingle(o["near"]),Far=Convert.ToSingle(o["far"]),FarOverride=Convert.ToSingle(o["farOverride"]),HorizontalSlope=Convert.ToSingle(o["sx"]),VerticalSlope=Convert.ToSingle(o["sy"]),CombinedMatrix=Floats(m,0x10106400,16),FarLanes=Floats(m,0x10106440,4)};
            var sway=new ObjectSwayState{FrameCounter=U(o["swayFrame"]),Amplitude=Convert.ToSingle(o["swayAmplitude"]),Rate=Convert.ToSingle(o["swayRate"]),UseSseConversion=Convert.ToBoolean(o["swaySse"]),SineTable=sine};int swayCalls=0;
            DynamicSubmissionResult result=DynamicObjectSubmission.SubmitWithSway(m,s,U(o["handle"]),U(o["matrix"]),0,0,null,null,null,delegate(uint source,int amplitude,int seed){ObjectSway.Transform(m,scratch,source,sway,amplitude,seed);++swayCalls;return scratch;});
            Store(m,0x10106400,s.Box.CombinedMatrix);Store(m,0x10106440,s.Box.FarLanes);m.Block(0x10106300,new byte[32]);string digest=Hash(bytes);bool pass=digest==(string)c["nativeSHA256"]&&unchecked((uint)result.Visibility)==U(c["nativeReturn"])&&s.ShadowMask==U(c["nativeShadowMask"])&&Same(result.Draws,A(c["nativeDraws"]))&&swayCalls==(c["nativeSwayMatrix"]==null?0:1);
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],visibility=result.Visibility,shadow=s.ShadowMask,draws=result.Draws,swayCalls});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
