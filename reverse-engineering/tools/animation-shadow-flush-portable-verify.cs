using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class LegacyShadowFlushVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static Dictionary<string,object> Read(string p){using(var f=File.OpenRead(p))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))return M(Json.DeserializeObject(r.ReadToEnd()));}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static void Put(byte[] b,int p,uint v){b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;IDictionary da=a as IDictionary,db=b as IDictionary;if(da!=null&&db!=null){if(da.Count!=db.Count)return false;foreach(object key in da.Keys)if(!db.Contains(key)||!Same(da[key],db[key]))return false;return true;}IList aa=a as IList,bb=b as IList;if(aa!=null&&bb!=null){if(aa.Count!=bb.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],bb[i]))return false;return true;}return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);var expected=M(row["native"]);string kind=(string)row["kind"];bool pass;
            if(kind=="allocate")
            {
                uint cursor=U(row["cursor"]);var allocation=LegacyShadowFlush.Allocate(ref cursor);pass=allocation.Vertices==U(expected["vertices"])&&allocation.GroupStarts==U(expected["starts"])&&allocation.GroupEdgeCounts==U(expected["edges"])&&cursor==U(expected["cursor"]);
            }
            else
            {
                var e=M(row["environment"]);var queue=new CharacterShadowQueueState{Enabled=Convert.ToByte(e["enabled"]),Mode=I(e["mode"]),Count=I(e["queueCount"])};var geometry=new LegacyShadowGeometryState{VertexCount=U(e["vertexCount"]),GroupCount=U(e["groupCount"]),GeneratedValue=U(e["generated"])};var events=new List<object>();var state=new LegacyShadowRenderState{VolumeShader=U(e["volumeShader"]),OverlayShader=U(e["overlayShader"]),OverlayBuffer=U(e["overlayBuffer"]),StencilValues=Array.ConvertAll(A(e["stencil"]),U),InlineStarts=Array.ConvertAll(A(e["starts"]),U),InlineEdgeCounts=Array.ConvertAll(A(e["edges"]),U)};
                state.DeviceCall=(entry,words)=>events.Add(new Dictionary<string,object>{{"entry",entry},{"args",words}});
                if(kind=="draw")LegacyShadowFlush.DrawVolumes(geometry,state);else if(kind=="overlay")LegacyShadowFlush.Overlay(state);else LegacyShadowFlush.Flush(queue,geometry,state,delegate(uint a,uint b){events.Add(new Dictionary<string,object>{{"entry",0x5e4840u},{"args",new[]{a,b}}});var post=M(e["post"]);geometry.VertexCount=U(post["vertexCount"]);geometry.GroupCount=U(post["groupCount"]);geometry.GeneratedValue=U(post["generated"]);});
                byte[] image=new byte[0x10100];for(int i=0;i<image.Length;++i)image[i]=0xa5;for(int i=0;i<250;++i){Put(image,0x963f88-0x963f80+i*4,state.InlineStarts[i]);Put(image,0x96e568-0x963f80+i*4,state.InlineEdgeCounts[i]);}Put(image,0x973fec-0x963f80,geometry.VertexCount);Put(image,0x973ff0-0x963f80,geometry.GroupCount);Put(image,0x971878-0x963f80,geometry.GeneratedValue);Put(image,0x973fe8-0x963f80,unchecked((uint)queue.Count));
                pass=Same(events,expected["events"])&&Hash(image)==(string)expected["imageSha256"]&&geometry.VertexCount==U(expected["vertexCount"])&&geometry.GroupCount==U(expected["groupCount"])&&geometry.GeneratedValue==U(expected["generated"])&&queue.Count==I(expected["queueCount"])&&queue.Enabled==Convert.ToByte(e["enabled"])&&queue.Mode==I(e["mode"])&&state.VolumeShader==U(e["volumeShader"])&&state.OverlayShader==U(e["overlayShader"])&&state.OverlayBuffer==U(e["overlayBuffer"])&&Same(state.StencilValues,e["stencil"]);
            }
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
