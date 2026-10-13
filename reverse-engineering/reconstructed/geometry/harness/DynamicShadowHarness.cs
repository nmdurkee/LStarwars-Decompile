using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
using Recovered.Animation;
public static class DynamicShadowHarness
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
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);uint maskMirror=U(fixture["maskMirror"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var o=M(c["options"]);byte[] bytes=Expand((string)c["beforeZ"]);if(bytes.Length!=1048576)throw new InvalidDataException();var m=new RenderPacketMemory(0x10100000,bytes);
            var s=new DynamicSubmissionState{ForcedVisibility=I(o["forcedVisibility"]),ForcedLod=I(o["forcedLod"]),FilterMode=I(o["filterMode"]),ShadowCount=I(o["shadowCount"]),ShadowMask=U(o["shadowMask"]),ShadowMetadataDisabled=I(o["shadowMetadataDisabled"]),GlobalOverride=U(o["globalOverride"]),OverrideTable=U(o["overrideTable"]),OverrideFirst=U(o["overrideFirst"]),OverrideScalarWord=U(o["overrideScalarWord"]),ScratchInputs=Array.ConvertAll(A(o["uv"]),U),CameraPosition=Values(o["camera"]),AllocatorControl=0x10100000,Shader=0x10106000,SignedByteDescriptor=U(o["descriptor"]),TokenBase=0x12345678,ScaleScratch=0x10106200,TranslationScratch=0x10106240,CacheScratch=0x10106300,OutputScratch=0x10106310};
            s.Box=new DynamicBoxState{Enabled=I(o["enabled"])!=0,View=Values(o["view"]),Near=Convert.ToSingle(o["near"]),Far=Convert.ToSingle(o["far"]),FarOverride=Convert.ToSingle(o["farOverride"]),HorizontalSlope=Convert.ToSingle(o["sx"]),VerticalSlope=Convert.ToSingle(o["sy"]),CombinedMatrix=Floats(m,0x10106400,16),FarLanes=Floats(m,0x10106440,4)};
            uint[] addresses=Array.ConvertAll(A(o["shadowContexts"]),U),masks=Array.ConvertAll(A(o["initialMasks"]),U);var state=new SecondaryVisibilityState{Count=s.ShadowCount,Masks=masks,CacheFlag=s.ShadowMask,Contexts=new SecondaryVisibilityContext[s.ShadowCount]};
            for(int ci=0;ci<state.Count;++ci)
            {
                uint context=addresses[ci];int count=checked((int)m.Dword(context+0x710));if(count>128)throw new InvalidDataException();var volumes=new SecondaryVisibilityVolume[count];
                for(int vi=0;vi<count;++vi){uint p=context+(uint)vi*0x380;int pc=checked((int)m.Dword(p+0x260));if(pc>12)throw new InvalidDataException();var planes=new float[pc][];for(int pi=0;pi<pc;++pi)planes[pi]=Floats(m,p+0x1a0+(uint)pi*16,4);volumes[vi]=new SecondaryVisibilityVolume{Planes=planes};}
                state.Contexts[ci]=new SecondaryVisibilityContext{Volumes=volumes};
            }
            var shadows=new DynamicShadowServices{Contexts=addresses,Masks=masks,Evaluate=delegate(DynamicSubmissionState dynamicState,float[] first,float[] second){state.CacheFlag=dynamicState.ShadowMask;int visible=SecondaryVisibility.Evaluate(state,first,second,0);dynamicState.ShadowMask=state.CacheFlag;return visible;}};
            DynamicSubmissionResult result=DynamicObjectSubmission.SubmitWithShadows(m,s,U(o["handle"]),U(o["matrix"]),0,0,null,null,null,null,shadows);
            for(int i=0;i<masks.Length;++i)m.Dword(maskMirror+(uint)i*4,masks[i]);Store(m,0x10106400,s.Box.CombinedMatrix);Store(m,0x10106440,s.Box.FarLanes);m.Block(0x10106300,new byte[32]);string digest=Hash(bytes);
            bool pass=digest==(string)c["nativeSHA256"]&&unchecked((uint)result.Visibility)==U(c["nativeReturn"])&&s.ShadowMask==U(c["nativeShadowMask"])&&Same(result.Draws,A(c["nativeDraws"]))&&Same(result.DrawRecords,A(c["nativeRecords"]));
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],visibility=result.Visibility,shadow=s.ShadowMask,draws=result.Draws,records=result.DrawRecords});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
