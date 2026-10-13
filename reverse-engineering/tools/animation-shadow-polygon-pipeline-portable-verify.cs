// Prepared replay for actual queue-to-polygon CPU geometry composition.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class LegacyPolygonPipelineVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static byte[] Expand(byte[] b){using(var i=new MemoryStream(b))using(var z=new GZipStream(i,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
    static Dictionary<string,object> Read(string p){return M(Json.DeserializeObject(System.Text.Encoding.UTF8.GetString(Expand(File.ReadAllBytes(p)))));}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static float[] Values(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(U(x)));}
    static uint[] Words(float[] v){return Array.ConvertAll(v,PcObjectImage.ToBits);}
    static byte[] Fill(int count){var b=new byte[count];for(int i=0;i<count;++i)b[i]=0xa5;return b;}
    static void Put(byte[] b,int p,uint v){b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;IDictionary da=a as IDictionary,db=b as IDictionary;
        if(da!=null&&db!=null){if(da.Count!=db.Count)return false;foreach(object key in da.Keys)if(!db.Contains(key)||!Same(da[key],db[key]))return false;return true;}
        IList aa=a as IList,bb=b as IList;if(aa!=null&&bb!=null){if(aa.Count!=bb.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],bb[i]))return false;return true;}
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));var sineSource=M(fixture["sine"]);byte[] raw=File.ReadAllBytes(Path.Combine(root,(string)sineSource["path"]));if(Hash(raw)!=(string)sineSource["sha256"])throw new InvalidDataException();var sine=new float[32768];Buffer.BlockCopy(raw,0,sine,0,raw.Length);var table=Array.ConvertAll(A(fixture["angleTable"]),x=>Convert.ToUInt16(x));var polySource=M(fixture["polygonFixture"]);string polyPath=Path.Combine(root,(string)polySource["path"]);if(Hash(File.ReadAllBytes(polyPath))!=(string)polySource["sha256"])throw new InvalidDataException();object[] shapeRows=A(Read(polyPath)["shapes"]),sources=A(fixture["sources"]);int checks=0,failures=0;var errors=new List<object>();
        var shapes=new LegacyShadowPolygons[shapeRows.Length];for(int i=0;i<shapes.Length;++i){var row=M(shapeRows[i]);shapes[i]=new LegacyShadowPolygons{PolygonCount=I(row["polygonCount"]),Normals=Array.ConvertAll(A(row["normals"]),Values),Vertices=Array.ConvertAll(A(row["vertices"]),Values),EdgeCounts=Array.ConvertAll(A(row["edges"]),I)};}
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);var source=M(sources[I(row["source"])]);var bindings=M(source["shapeBindings"]);var pairs=M(row["pairs"]);var queue=new CharacterShadowQueueState{Records=Expand(Convert.FromBase64String((string)row["queueZ"])),Count=I(row["count"])};string queueHash=Hash(queue.Records);var direction=new LegacyShadowDirectionState{SineTable=sine,AngleTable=table};for(int i=0;i<8;++i)direction.Circle[i]=new[]{(float)(i*3-12),(float)(i*3-11),(float)(i*3-10)};
            var initial=M(row["initial"]);var geometry=new LegacyShadowGeometryState{Vertices=Fill(0xc0000),VertexCount=U(initial["vertexCount"]),GroupCount=U(initial["groupCount"]),GeneratedValue=U(initial["generated"]),GroupStarts=new uint[250],GroupEdgeCounts=new uint[250]};for(int i=0;i<250;++i){geometry.GroupStarts[i]=0xa5a5a5a5;geometry.GroupEdgeCounts[i]=0xa5a5a5a5;}
            var consumer=new LegacyShadowConsumerState{Camera=Values(row["camera"]),Direction=direction,GeneratedValue=U(initial["generated"])};consumer.ReadPair=p=>Array.ConvertAll(A(pairs[p.ToString()]),U);var events=new List<object>();var resolvedPairs=new List<object>();
            Func<uint,uint,LegacyShadowPolygons> resolve=delegate(uint first,uint second){resolvedPairs.Add(new uint[]{first,second});return shapes[I(bindings[first+":"+second])];};
            Action<LegacyShadowShapeCall> other=delegate(LegacyShadowShapeCall call)
            {
                var e=new Dictionary<string,object>{{"entry",call.NativeEntry},{"record",call.RecordIndex},{"direction",Words(call.Direction)},{"resource",call.Resource}};
                if(call.NativeEntry==0x5e3b50){e["upper"]=PcObjectImage.ToBits(call.Upper);e["lower"]=PcObjectImage.ToBits(call.Lower);}events.Add(e);consumer.GeneratedValue=unchecked(consumer.GeneratedValue+(call.NativeEntry&255)+1);
            };
            LegacyPolygonPipeline.Process(queue,consumer,geometry,resolve,other);byte[] image=Fill(0x100000);Buffer.BlockCopy(geometry.Vertices,0,image,0x30000,geometry.Vertices.Length);for(int i=0;i<250;++i){Put(image,0x20000+i*4,geometry.GroupStarts[i]);Put(image,0x21000+i*4,geometry.GroupEdgeCounts[i]);}
            var expected=M(row["native"]);var expectedOther=new List<object>();var expectedPairs=new List<object>();foreach(object call in A(expected["events"])){var e=M(call);if(U(e["entry"])==0x5e4280)expectedPairs.Add(new object[]{e["first"],e["second"]});else expectedOther.Add(e);}
            bool pass=Hash(image)==(string)expected["sha256"]&&geometry.VertexCount==U(expected["vertexCount"])&&geometry.GroupCount==U(expected["groupCount"])&&geometry.GeneratedValue==U(expected["generated"])&&consumer.GeneratedValue==geometry.GeneratedValue&&Same(Array.ConvertAll(direction.Circle,Words),expected["circle"])&&Same(events,expectedOther)&&Same(resolvedPairs,expectedPairs)&&Hash(queue.Records)==queueHash&&queue.Count==I(row["count"])&&Same(Words(consumer.Camera),row["camera"])&&consumer.Emit==null;
            // Native-only full interleaved shape records are also checked by
            // the independent composition model. Replay compares exact geometry,
            // persistent state, remaining service events and resolver order.
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest=Hash(image),expected=expected["sha256"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
