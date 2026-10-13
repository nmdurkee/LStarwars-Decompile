// Prepared selector plus actual writer replay. Compile only; no managed launch.
// Native-only nested helper traces are not exposed by the public dispatcher API.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Geometry;
public static class SkinMeshPacketDispatchVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v);}static uint U(object v){return Convert.ToUInt32(v);}static float F(object v){return PcObjectImage.FromBits(U(v));}
    static byte[] B64(object v){return Convert.FromBase64String((string)v);}static byte[] Hex(string v){var b=new byte[v.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(v.Substring(i*2,2),16);return b;}
    static string Hash(byte[] v){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(v)).Replace("-","").ToLowerInvariant();}
    static Dictionary<string,object> Read(string path){using(var f=File.OpenRead(path))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))return M(Json.DeserializeObject(r.ReadToEnd()));}
    sealed class Buffer:IMorphVertexBuffer
    {
        public byte[] Bytes;public uint Offset;public List<object> Events=new List<object>();
        public byte[] Lock(uint offset,uint count,uint flags){if(offset!=Offset||count!=Bytes.Length)throw new ArgumentException("Fixture lock range differs");Events.Add(new object[]{"lock",offset,count,flags});return Bytes;}
        public void Unlock(){Events.Add(new object[]{"unlock"});}
    }
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;var aa=a as IList;var ab=b as IList;if(aa!=null&&ab!=null){if(aa.Count!=ab.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        if(a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<skin-dispatch-native-fixtures.json.gz> <result.json>");var fixture=Read(args[0]);var reference=M(fixture["meshFixture"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0]))),meshPath=Path.Combine(root,(string)reference["path"]);if(Hash(File.ReadAllBytes(meshPath))!=(string)reference["sha256"])throw new ArgumentException("Source mesh fixture hash changed");
        var meshes=Read(meshPath);var rows=A(meshes["meshes"]);byte[] bones=B64(meshes["jointMatrices"]);var jointMatrices=new byte[256][];for(int i=0;i<256;++i){jointMatrices[i]=new byte[64];Array.Copy(bones,i*64,jointMatrices[i],0,64);}var at=M(fixture["addresses"]);Func<string,uint> P=key=>U(at[key]);uint[] uv=Array.ConvertAll(A(fixture["scratchInputs"]),U);int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var c=M(item);var mesh=M(rows[I(c["mesh"])]);int index=I(c["index"]);var memory=new RenderPacketMemory(P("base"),new byte[I(at["size"])]);for(uint i=P("arena");i<P("base")+P("size");++i)memory.Byte(i,(byte)(((i-P("arena"))*37+(uint)index*17)&255));
            memory.Block(P("mesh"),B64(mesh["descriptor"]));memory.Block(P("joints"),bones);memory.Block(P("matrix"),Hex((string)c["matrix"]));memory.Dword(P("gpu"),P("vtable"));memory.Dword(P("vtable")+0x2c,P("lock"));memory.Dword(P("vtable")+0x30,P("unlock"));memory.Dword(P("control"),P("arena")+(uint)(index%32));memory.Dword(P("record"),P("owner"));memory.Dword(P("owner")+0x50,P("table"));memory.Dword(P("table"),0x12345678);memory.Dword(P("record")+0x14,P("base")+0xc700);memory.Dword(P("record")+0x18,P("base")+0xc720);memory.Dword(P("command")+4,P("mesh"));memory.Dword(P("cache"),0xdeadbeef);for(uint i=0;i<12;++i)memory.Byte(P("output")+i,0xa5);
            memory.Byte(P("command"),Convert.ToByte(c["opcode"]));memory.Byte(P("command")-32,Convert.ToByte(c["previous"]));memory.Dword(P("command")-28,0x89abcdef);memory.Dword(P("material")+0xb4,U(c["flags"]));if(Convert.ToBoolean(c["skin"]))memory.Block(U(c["skinAddress"]),bones);
            float[] weights=c["weights"]==null?null:Array.ConvertAll(A(c["weights"]),F);if(weights!=null)for(int i=0;i<weights.Length;++i)memory.Dword(P("weights")+8+(uint)i*4,PcObjectImage.ToBits(weights[i]));
            var targets=A(mesh["deltas"]);var deltas=new float[targets.Length][];uint targetAddress=P("delta");for(int i=0;i<targets.Length;++i){memory.Dword(P("targets")+(uint)i*4,targets[i]==null?0:targetAddress);if(targets[i]!=null){byte[] data=B64(targets[i]);targetAddress+=(uint)data.Length+16;deltas[i]=new float[data.Length/4];for(int j=0;j<deltas[i].Length;++j)deltas[i][j]=BitConverter.ToSingle(data,j*4);}}
            var buffer=new Buffer{Bytes=B64(mesh["vertices"]),Offset=U(mesh["offset"])};var resource=new MorphMeshResource{SourceAddress=P("mesh"),TargetDeltas=deltas,VertexBuffer=buffer};uint writer=SkinMeshPacketDispatch.Build(memory,P("control"),P("record"),P("material"),I(c["commandIndex"]),P("command"),P("matrix"),P("cache"),P("output"),resource,weights,Convert.ToBoolean(c["skin"])?jointMatrices:null,U(c["alpha"]),I(c["metadata"]),P("scale"),P("translation"),uv);
            string digest=Hash(memory.Bytes);bool pass=digest==(string)c["nativeSha256"]&&writer==U(c["writer"])&&Same(buffer.Events,A(c["events"]));++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSha256"],writer,events=buffer.Events});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
