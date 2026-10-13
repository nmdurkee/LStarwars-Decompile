// Compile-only replay of normal caller -> real recovered skin packet writer.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
using Recovered.Animation;
public static class DynamicSkinHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static byte[] B64(object v){return Convert.FromBase64String((string)v);}
    static string Hash(byte[] bytes){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(bytes)).Replace("-","").ToLowerInvariant();}
    static Dictionary<string,object> Read(string path){using(var f=File.OpenRead(path))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))return M(Json.DeserializeObject(r.ReadToEnd()));}
    static byte[] Expand(byte[] bytes){using(var input=new MemoryStream(bytes))using(var z=new GZipStream(input,CompressionMode.Decompress))using(var output=new MemoryStream()){z.CopyTo(output);return output.ToArray();}}
    static float[] Floats(RenderPacketMemory m,uint p,int count){float[] values=new float[count];for(int i=0;i<count;++i)values[i]=BitConverter.ToSingle(m.Block(p+(uint)i*4,4),0);return values;}
    static float[] Values(object v){return Array.ConvertAll(A(v),x=>Convert.ToSingle(x));}
    static void Store(RenderPacketMemory m,uint p,float[] values){for(int i=0;i<values.Length;++i)m.Block(p+(uint)i*4,BitConverter.GetBytes(values[i]));}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;IList aa=a as IList,bb=b as IList;
        if(aa!=null&&bb!=null){if(aa.Count!=bb.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],bb[i]))return false;return true;}
        if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    sealed class Buffer:IMorphVertexBuffer
    {
        public byte[] Bytes;public uint Offset;public readonly List<object> Events=new List<object>();
        public byte[] Lock(uint offset,uint count,uint flags){if(offset!=Offset||count!=Bytes.Length||flags!=16)throw new ArgumentException("Fixture lock differs");Events.Add(new object[]{"lock",offset,count,flags});return Bytes;}
        public void Unlock(){Events.Add(new object[]{"unlock"});}
    }
    public static int Main(string[] args)
    {return Run(args,null);}
    public static int Run(string[] args,Func<float,float,float,float> distanceFade)
    {return Run(args,distanceFade,false);}
    public static int Run(string[] args,Func<float,float,float,float> distanceFade,bool billboardOnly)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);var reference=M(fixture[billboardOnly?"billboardFixture":"meshFixture"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0]))),meshPath=Path.Combine(root,(string)reference["file"]);if(Hash(File.ReadAllBytes(meshPath))!=(string)reference["sha256"])throw new InvalidDataException("Resource fixture changed");var meshes=billboardOnly?null:A(Read(meshPath)["meshes"]);var addresses=M(fixture["addresses"]);Func<string,uint> P=k=>U(addresses[k]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var o=M(c["options"]);byte[] bytes=Expand(B64(c["beforeZ"]));if(bytes.Length!=(billboardOnly?0x10000:0x100000))throw new InvalidDataException();var memory=new RenderPacketMemory(0x10100000,bytes);var mesh=billboardOnly?null:M(meshes[I(c["mesh"])]);var targetRows=billboardOnly?new object[0]:A(mesh["deltas"]);var deltas=new float[targetRows.Length][];
            for(int i=0;i<deltas.Length;++i)if(targetRows[i]!=null){byte[] raw=B64(targetRows[i]);deltas[i]=new float[raw.Length/4];for(int j=0;j<deltas[i].Length;++j)deltas[i][j]=BitConverter.ToSingle(raw,j*4);}
            var buffer=new Buffer{Bytes=billboardOnly?new byte[0]:B64(mesh["vertices"]),Offset=billboardOnly?0:U(mesh["offset"])};
            var s=new DynamicSubmissionState{ForcedVisibility=I(o["forcedVisibility"]),ForcedLod=I(o["forcedLod"]),FilterMode=I(o["filterMode"]),ShadowMask=U(o["shadowMask"]),ShadowMetadataDisabled=I(o["shadowMetadataDisabled"]),GlobalOverride=U(o["globalOverride"]),OverrideTable=U(o["overrideTable"]),OverrideFirst=U(o["overrideFirst"]),OverrideScalarWord=U(o["overrideScalarWord"]),ScratchInputs=Array.ConvertAll(A(o["uv"]),U),CameraPosition=Values(o["camera"]),AllocatorControl=P("control"),Shader=P("shader"),TokenBase=0x12345678,ScaleScratch=P("scale"),TranslationScratch=P("translation"),CacheScratch=P("cache"),OutputScratch=P("output")};
            s.Box=new DynamicBoxState{Enabled=I(o["enabled"])!=0,View=Values(o["view"]),Near=Convert.ToSingle(o["near"]),Far=Convert.ToSingle(o["far"]),FarOverride=Convert.ToSingle(o["farOverride"]),HorizontalSlope=Convert.ToSingle(o["sx"]),VerticalSlope=Convert.ToSingle(o["sy"]),CombinedMatrix=Floats(memory,P("combined"),16),FarLanes=Floats(memory,P("farLanes"),4)};
            var forwardedAlpha=new List<uint>();var fadeCalls=new List<uint[]>();Func<float,float,float,float> trackedFade=null;
            if(distanceFade!=null)trackedFade=delegate(float distance,float start,float end){fadeCalls.Add(new uint[]{PcObjectImage.ToBits(distance),PcObjectImage.ToBits(start),PcObjectImage.ToBits(end)});return distanceFade(distance,start,end);};
            DynamicSubmissionResult result=DynamicObjectSubmission.SubmitWithDistanceFade(memory,s,U(o["handle"]),U(o["matrix"]),U(o["skin"]),U(o["morph"]),null,delegate(RenderPacketMemory m,DynamicSubmissionState state,DynamicPacketRequest request)
            {
                forwardedAlpha.Add(request.AlphaWord);
                if(request.SkinPalette!=U(o["skin"])||request.MorphWeights!=U(o["morph"]))throw new InvalidDataException("Caller pointer forwarding differs");
                if(billboardOnly)
                {
                    if(m.Byte(request.Command)!=0x8f)throw new InvalidDataException("Expected billboard opcode");
                    return SkinMeshPacketDispatch.BuildWithBillboards(m,state.AllocatorControl,request.Record,request.Material,unchecked((int)request.CommandIndex),request.Command,request.Matrix,request.Cache,request.Output,null,null,null,request.AlphaWord,request.Metadata,state.ScaleScratch,state.TranslationScratch,state.ScratchInputs,state.Box.View,Values(o["forward"]));
                }
                uint source=m.Dword(request.Command+4);var resource=new MorphMeshResource{SourceAddress=source,TargetDeltas=deltas,VertexBuffer=buffer};byte[][] joints=null;float[] weights=null;
                if(request.SkinPalette!=0){joints=new byte[256][];for(int i=0;i<256;++i)joints[i]=m.Block(request.SkinPalette+(uint)i*64,64);if(request.MorphWeights!=0)weights=Floats(m,request.MorphWeights+8,(int)m.Dword(source+40));}
                return SkinMeshPacketDispatch.Build(m,state.AllocatorControl,request.Record,request.Material,unchecked((int)request.CommandIndex),request.Command,request.Matrix,request.Cache,request.Output,resource,weights,joints,request.AlphaWord,request.Metadata,state.ScaleScratch,state.TranslationScratch,state.ScratchInputs);
            },trackedFade);
            Store(memory,P("combined"),s.Box.CombinedMatrix);Store(memory,P("farLanes"),s.Box.FarLanes);memory.Block(P("cache"),new byte[32]);string digest=Hash(bytes);
            bool pass=digest==(string)c["nativeSHA256"]&&unchecked((uint)result.Visibility)==U(c["nativeReturn"])&&s.ShadowMask==U(c["nativeShadowMask"])&&Same(result.Draws,A(c["nativeDraws"]))&&Same(buffer.Events,A(c["nativeEvents"]));
            if(c.ContainsKey("nativeAlphaWords"))pass=pass&&Same(forwardedAlpha,A(c["nativeAlphaWords"]));
            if(c.ContainsKey("nativeFadeInputs"))pass=pass&&Same(fadeCalls,A(c["nativeFadeInputs"]));
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],visibility=result.Visibility,shadow=s.ShadowMask,draws=result.Draws,events=buffer.Events});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
