// Prepared original CPU deformation replay. Device services are bounded fixtures.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class MorphMeshDeformationVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static byte[] Decode(object v){return Convert.FromBase64String((string)v);}static float F(object v){return PcObjectImage.FromBits(U(v));}
    static string Hex(byte[] v){return BitConverter.ToString(v).Replace("-","").ToLowerInvariant();}
    static string Digest(byte[] v){if(v==null)return null;using(var h=SHA256.Create())return Hex(h.ComputeHash(v));}
    sealed class Buffer:IMorphVertexBuffer
    {
        public byte[] Bytes;public uint Offset;public List<object> Events=new List<object>();
        public byte[] Lock(uint offset,uint count,uint flags){if(offset!=Offset||count!=Bytes.Length)throw new ArgumentException("Fixture lock range differs");Events.Add(new object[]{"lock",offset,count,flags});return Bytes;}
        public void Unlock(){Events.Add(new object[]{"unlock"});}
    }
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<morph-mesh-native-fixtures.json.gz> <result.json>");Dictionary<string,object> fixture;
        using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        var rows=A(fixture["meshes"]);object[] clipRows=A(fixture["clips"]);var clips=new MorphClip[clipRows.Length];for(int i=0;i<clips.Length;++i)clips[i]=new MorphClip(Decode(M(clipRows[i])["bytes"]));byte[] bones=Decode(fixture["jointMatrices"]);var matrices=new byte[256][];for(int i=0;i<256;++i){matrices[i]=new byte[64];Array.Copy(bones,i*64,matrices[i],0,64);}int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var c=M(item);var raw=M(rows[I(c["mesh"])]);var buffer=new Buffer{Bytes=Decode(raw["vertices"]),Offset=U(raw["offset"])};var targetRows=A(raw["deltas"]);var deltas=new float[targetRows.Length][];
            for(int i=0;i<deltas.Length;++i)if(targetRows[i]!=null){byte[] bytes=Decode(targetRows[i]);deltas[i]=new float[bytes.Length/4];for(int j=0;j<deltas[i].Length;++j)deltas[i][j]=BitConverter.ToSingle(bytes,j*4);}
            var mesh=new MorphMeshResource{SourceAddress=U(fixture["meshAddress"]),Descriptor=Decode(raw["descriptor"]),TargetDeltas=deltas,VertexBuffer=buffer};float[] weights=c["weights"]==null?null:Array.ConvertAll(A(c["weights"]),F);
            bool weightsMatch=true;if(c.ContainsKey("clip")){float[] sampled=MorphWeights.Single(clips[I(c["clip"])],F(c["frame"]),new[]{I(c["layer"])})[0];weightsMatch=sampled.Length==weights.Length;for(int j=0;weightsMatch&&j<weights.Length;++j)weightsMatch=PcObjectImage.ToBits(sampled[j])==PcObjectImage.ToBits(weights[j]);weights=sampled;}
            var result=MorphMeshDeformation.Build(mesh,weights,matrices,U(c["cursor"]));object actual=new{descriptorAddress=result.DescriptorAddress,paletteAddress=result.PaletteAddress,nextCursor=result.NextCursor,sourceDescriptor=Hex(mesh.Descriptor),descriptor=Hex(result.Descriptor),verticesSha256=Digest(result.Vertices),paletteSha256=Digest(result.Palette),events=buffer.Events};actual=Json.DeserializeObject(Json.Serialize(actual));
            ++checks;if(!weightsMatch||!Same(actual,c["native"])){++failures;if(errors.Count<12)errors.Add(new{caseIndex=checks-1,weightsMatch,actual,expected=c["native"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
