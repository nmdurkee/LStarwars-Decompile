using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class LegacyCylinderShadowsVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static float[] Values(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(U(x)));}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static Dictionary<string,object> Read(string p){using(var f=File.OpenRead(p))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))return M(Json.DeserializeObject(r.ReadToEnd()));}
    static byte[] Fill(int size){var b=new byte[size];for(int i=0;i<size;++i)b[i]=0xa5;return b;}
    static void Put(byte[] b,int p,uint v){b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
    static void Floats(byte[] b,int p,float[] v){for(int i=0;i<v.Length;++i)Put(b,p+i*4,PcObjectImage.ToBits(v[i]));}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);var cylinders=A(fixture["cylinders"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);var e=M(cylinders[I(row["cylinder"])]);float[] cylinder=Values(e["values"]),matrix=Values(row["matrix"]),direction=Values(row["direction"]);var initial=M(row["initial"]);byte[] image=Fill(0x5000);Floats(image,0x100,cylinder);Floats(image,0x200,matrix);Floats(image,0x300,direction);
            var state=new LegacyShadowGeometryState{Vertices=Fill(0x2000),VertexCount=U(initial["vertexCount"]),GroupCount=U(initial["groupCount"]),GeneratedValue=U(initial["generated"]),GroupStarts=new uint[250],GroupEdgeCounts=new uint[250]};for(int i=0;i<250;++i){state.GroupStarts[i]=0xa5a5a5a5;state.GroupEdgeCounts[i]=0xa5a5a5a5;}
            LegacyCylinderShadows.Emit(state,cylinder,matrix,direction);Buffer.BlockCopy(state.Vertices,0,image,0x3000,state.Vertices.Length);for(int i=0;i<250;++i){Put(image,0x1000+i*4,state.GroupStarts[i]);Put(image,0x2000+i*4,state.GroupEdgeCounts[i]);}
            Floats(image,0x100,cylinder);Floats(image,0x200,matrix);Floats(image,0x300,direction);var expected=M(row["native"]);
            bool pass=Hash(image)==(string)expected["sha256"]&&state.VertexCount==U(expected["vertexCount"])&&state.GroupCount==U(expected["groupCount"])&&state.GeneratedValue==U(expected["generated"]);
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest=Hash(image),expected=expected["sha256"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
