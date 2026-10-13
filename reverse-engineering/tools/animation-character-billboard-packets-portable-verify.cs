// Compile-only character, secondary visibility and shadow packet composition.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
using Recovered.Animation;
public static class CharacterBillboardPacketPipelineVerify
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

    static float[] Bits(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(U(x)));}
    static float[][] Rows(object v){return Array.ConvertAll(A(v),Bits);}
    sealed class Rig
    {
        public CharacterRenderModel Model;public float[][] Joints;
        readonly Dictionary<string,object> Addresses;readonly RenderPacketMemory Memory;
        CharacterRenderHandle Handle(object v)
        {
            if(v==null)return null;var row=M(v);uint p=U(Addresses[U(row["identity"]).ToString()]);return new CharacterRenderHandle{Identity=p,Scene=Memory.Dword(p),DisplaySpecial=Memory.Dword(p+8)};
        }
        CharacterRenderHandle[] Handles(object v){return v==null?null:Array.ConvertAll(A(v),Handle);}
        public Rig(Dictionary<string,object> row,Dictionary<string,object> addresses,RenderPacketMemory memory)
        {
            Addresses=addresses;Memory=memory;Joints=Rows(row["joints"]);Model=new CharacterRenderModel{InverseBind=Rows(row["inverse"]),BoundsMinimum=Bits(row["minimum"]),BoundsMaximum=Bits(row["maximum"])};object[] layers=A(row["layers"]);Model.Layers=new CharacterRenderLayer[layers.Length];
            for(int i=0;i<layers.Length;++i){var l=M(layers[i]);Model.Layers[i]=new CharacterRenderLayer{Rigid=Handles(l["rigid"]),AlternateRigid=Handles(l["alternateRigid"]),Smooth=Handle(l["smooth"]),AlternateSmooth=Handle(l["alternateSmooth"])};}
        }
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);var reference=M(fixture["meshFixture"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0]))),meshPath=Path.Combine(root,(string)reference["path"]);if(Hash(File.ReadAllBytes(meshPath))!=(string)reference["sha256"])throw new InvalidDataException("Mesh fixture changed");object[] meshes=A(Read(meshPath)["meshes"]),rigs=A(fixture["rigs"]);var addresses=M(fixture["addresses"]);Func<string,uint> P=k=>U(addresses[k]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var o=M(c["options"]);var input=M(c["state"]);byte[] bytes=Expand(B64(c["beforeZ"]));if(bytes.Length!=0x100000)throw new InvalidDataException();var memory=new RenderPacketMemory(0x10100000,bytes);var mesh=M(meshes[I(c["mesh"])]);var targetRows=A(mesh["deltas"]);var deltas=new float[targetRows.Length][];
            for(int i=0;i<deltas.Length;++i)if(targetRows[i]!=null){byte[] raw=B64(targetRows[i]);deltas[i]=new float[raw.Length/4];for(int j=0;j<deltas[i].Length;++j)deltas[i][j]=BitConverter.ToSingle(raw,j*4);}
            var buffer=new Buffer{Bytes=B64(mesh["vertices"]),Offset=U(mesh["offset"])};
            var dynamic=new DynamicSubmissionState{ForcedVisibility=I(o["forcedVisibility"]),ForcedLod=I(o["forcedLod"]),FilterMode=I(o["filterMode"]),ShadowCount=I(o["shadowCount"]),ShadowMask=U(o["shadowMask"]),ShadowMetadataDisabled=I(o["shadowMetadataDisabled"]),GlobalOverride=U(o["globalOverride"]),OverrideTable=U(o["overrideTable"]),OverrideFirst=U(o["overrideFirst"]),OverrideScalarWord=U(o["overrideScalarWord"]),ScratchInputs=Array.ConvertAll(A(o["uv"]),U),CameraPosition=Values(o["camera"]),AllocatorControl=P("control"),Shader=P("shader"),TokenBase=0x12345678,ScaleScratch=P("scale"),TranslationScratch=P("translation"),CacheScratch=P("cache"),OutputScratch=P("output")};
            dynamic.Box=new DynamicBoxState{Enabled=I(o["enabled"])!=0,View=Values(o["view"]),Near=Convert.ToSingle(o["near"]),Far=Convert.ToSingle(o["far"]),FarOverride=Convert.ToSingle(o["farOverride"]),HorizontalSlope=Convert.ToSingle(o["sx"]),VerticalSlope=Convert.ToSingle(o["sy"]),CombinedMatrix=Floats(memory,P("combined"),16),FarLanes=Floats(memory,P("farLanes"),4)};
            var rig=new Rig(M(rigs[I(c["rig"])]),M(c["handles"]),memory);var state=new CharacterSubmissionState{CachedVisibility=I(input["cached"]),ArenaCursor=memory.Dword(P("control")),SubmissionFlag=U(o["shadowMask"]),SecondaryVisibilityCount=I(input["secondaryCount"])};
            var environment=new CharacterPacketEnvironment{Memory=memory,Dynamic=dynamic,MatrixScratch=P("matrix"),CenterBoundsOnRoot=Convert.ToBoolean(input["center"]),Shadows=new CharacterShadowQueueState()};
            environment.ResolveMesh=delegate(uint source){throw new InvalidDataException("Billboard branch must bypass typed mesh resolution.");};
            short[] map=input["map"]==null?null:Array.ConvertAll(A(input["map"]),x=>Convert.ToInt16(x));uint[] morphs=Array.ConvertAll(A(input["morph"]),U);
            uint[] contextAddresses=Array.ConvertAll(A(o["shadowContexts"]),U),masks=Array.ConvertAll(A(o["initialMasks"]),U);
            var secondary=new SecondaryVisibilityState{Count=state.SecondaryVisibilityCount,Masks=masks,CacheFlag=state.SubmissionFlag,Contexts=new SecondaryVisibilityContext[state.SecondaryVisibilityCount]};
            for(int ci=0;ci<secondary.Count;++ci)
            {
                uint context=contextAddresses[ci];int count=checked((int)memory.Dword(context+0x710));if(count>128)throw new InvalidDataException();var volumes=new SecondaryVisibilityVolume[count];
                for(int vi=0;vi<count;++vi){uint p=context+(uint)vi*0x380;int pc=checked((int)memory.Dword(p+0x260));if(pc>12)throw new InvalidDataException();var planes=new float[pc][];for(int pi=0;pi<pc;++pi)planes[pi]=Floats(memory,p+0x1a0+(uint)pi*16,4);volumes[vi]=new SecondaryVisibilityVolume{Planes=planes};}
                secondary.Contexts[ci]=new SecondaryVisibilityContext{Volumes=volumes};
            }
            uint result=CharacterBillboardPacketPipeline.Submit(rig.Model,Bits(input["world"]),rig.Joints,I(input["count"]),map,morphs,state,environment,secondary,contextAddresses,Values(o["view"]),Values(o["forward"]));
            uint mirror=U(fixture["maskMirror"]);for(int i=0;i<masks.Length;++i)memory.Dword(mirror+(uint)i*4,masks[i]);
            Store(memory,P("combined"),dynamic.Box.CombinedMatrix);Store(memory,P("farLanes"),dynamic.Box.FarLanes);memory.Block(P("cache"),new byte[32]);memory.Block(P("matrix"),new byte[64]);string digest=Hash(bytes);var draws=new List<uint[]>();var records=new List<uint>();foreach(var submission in environment.Submissions){draws.AddRange(submission.Draws);records.AddRange(submission.DrawRecords);}
            var expected=M(c["native"]);bool pass=digest==(string)expected["sha256"]&&result==U(expected["result"])&&state.CachedVisibility==I(expected["cached"])&&dynamic.ForcedVisibility==state.CachedVisibility&&state.SubmissionFlag==U(expected["flag"])&&dynamic.ShadowMask==state.SubmissionFlag&&state.ArenaCursor==U(expected["cursor"])&&Same(draws,A(expected["draws"]))&&Same(records,A(expected["records"]))&&secondary.CacheFlag==state.SubmissionFlag&&dynamic.ShadowCount==state.SecondaryVisibilityCount&&Same(buffer.Events,A(expected["events"]))&&environment.Submissions.Count==A(expected["layers"]).Length;
            // Entry-only native layer diagnostics (matrix/palette hashes and
            // pre-draw cursor) are independently checked by the Python model.
            // Managed replay compares their persistent byte consequences and
            // ordered emitted packets, rather than inventing public callbacks.
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=expected["sha256"],result,cursor=state.ArenaCursor,draws,events=buffer.Events});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
