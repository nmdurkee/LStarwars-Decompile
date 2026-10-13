// Prepared differential replay for CPU polygon shadow geometry; compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class LegacyPolygonShadowsVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static float[] Values(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(U(x)));}
    static uint[] Words(float[] v){return Array.ConvertAll(v,PcObjectImage.ToBits);}
    static bool Same(IList a,IList b){if(a.Count!=b.Count)return false;for(int i=0;i<a.Count;++i)if(Convert.ToDecimal(a[i])!=Convert.ToDecimal(b[i]))return false;return true;}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static Dictionary<string,object> Read(string path){using(var f=File.OpenRead(path))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))return M(Json.DeserializeObject(r.ReadToEnd()));}
    static void Put(byte[] b,int p,uint v){b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
    static void Floats(byte[] b,int p,float[] v){for(int i=0;i<v.Length;++i)Put(b,p+i*4,PcObjectImage.ToBits(v[i]));}
    static byte[] Fill(int size){var b=new byte[size];for(int i=0;i<b.Length;++i)b[i]=0xa5;return b;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);object[] shapes=A(fixture["shapes"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);string kind=(string)row["kind"];float[] matrix=Values(row["matrix"]);bool pass;
            if(kind!="polygon")
            {
                float[] v=Values(row["vector"]);var before=Words(v);float[] result=kind=="point"?LegacyPolygonShadows.TransformPoint(v,matrix):LegacyPolygonShadows.TransformDirection(v,matrix);
                pass=Same(Words(result),A(row["native"]))&&Same(Words(v),before)&&Same(Words(matrix),A(row["matrix"]));
                // Original exact-in-place probes are also represented here;
                // the portable helper returns owned output for assignment.
            }
            else
            {
                var source=M(shapes[I(row["shape"])]);var shape=new LegacyShadowPolygons{PolygonCount=I(source["polygonCount"]),Normals=Array.ConvertAll(A(source["normals"]),Values),Vertices=Array.ConvertAll(A(source["vertices"]),Values),EdgeCounts=Array.ConvertAll(A(source["edges"]),I)};
                byte[] image=Fill(0x100000);Floats(image,0,matrix);float[] direction=Values(row["direction"]);Floats(image,0x100,direction);
                for(int i=0;i<shape.Normals.Length;++i){Floats(image,0x1000+i*16,shape.Normals[i]);Put(image,0x100c+i*16,unchecked((uint)shape.EdgeCounts[i]));}
                for(int i=0;i<shape.Vertices.Length;++i){Floats(image,0x10000+i*16,shape.Vertices[i]);Put(image,0x1000c+i*16,unchecked((uint)(i==0?shape.PolygonCount:0)));}
                if(shape.Vertices.Length==0)Put(image,0x1000c,unchecked((uint)shape.PolygonCount));
                var initial=M(row["initial"]);var state=new LegacyShadowGeometryState{Vertices=Fill(0xc0000),VertexCount=U(initial["vertexCount"]),GroupCount=U(initial["groupCount"]),GeneratedValue=U(initial["generated"]),GroupStarts=new uint[250],GroupEdgeCounts=new uint[250]};
                for(int i=0;i<250;++i){state.GroupStarts[i]=0xa5a5a5a5;state.GroupEdgeCounts[i]=0xa5a5a5a5;}
                LegacyPolygonShadows.Emit(state,shape,matrix,direction);Buffer.BlockCopy(state.Vertices,0,image,0x30000,state.Vertices.Length);
                for(int i=0;i<250;++i){Put(image,0x20000+i*4,state.GroupStarts[i]);Put(image,0x21000+i*4,state.GroupEdgeCounts[i]);}
                var expected=M(row["native"]);pass=Hash(image)==(string)expected["sha256"]&&state.VertexCount==U(expected["vertexCount"])&&state.GroupCount==U(expected["groupCount"])&&state.GeneratedValue==U(expected["generated"])&&Same(Words(matrix),A(row["matrix"]))&&Same(Words(direction),A(row["direction"]));
                // Helper-call counts are native-model diagnostics. Replay checks
                // exact persisted generated geometry and group metadata instead.
            }
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
