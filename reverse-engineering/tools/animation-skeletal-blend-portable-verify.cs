// Prepared exact original-PC blend replay. Compilation does not execute this.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class SkeletalBlendVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}
    static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static string Digest(float[][] rows)
    {using(var stream=new MemoryStream()){foreach(var row in rows)foreach(float v in row){byte[] bytes=BitConverter.GetBytes(PcObjectImage.ToBits(v));stream.Write(bytes,0,4);}using(var hash=SHA256.Create())return BitConverter.ToString(hash.ComputeHash(stream.ToArray())).Replace("-","").ToLowerInvariant();}}
    static bool Same(object a,object b)
    {
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("<blend-native-fixtures.json.gz> <native-sine-table.f32> <result.json>");
        Dictionary<string,object> fixture;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        byte[] sine=File.ReadAllBytes(args[1]);if(sine.Length!=131072)throw new ArgumentException("Invalid sine table");float[] table=new float[32768];for(int i=0;i<table.Length;++i)table[i]=BitConverter.ToSingle(sine,i*4);
        object[] clipRows=A(fixture["clips"]);var clips=new SkeletalClip[clipRows.Length];for(int i=0;i<clips.Length;++i)clips[i]=new SkeletalClip(Convert.FromBase64String((string)M(clipRows[i])["raw"]));
        object[] rigRows=A(fixture["rigs"]);var rigs=new SkeletalJoint[rigRows.Length][];
        for(int i=0;i<rigs.Length;++i){object[] rows=A(M(rigRows[i])["joints"]);rigs[i]=new SkeletalJoint[rows.Length];for(int j=0;j<rows.Length;++j){var row=M(rows[j]);rigs[i][j]=new SkeletalJoint{Parent=(byte)I(row["parent"]),AnimationBindMatrix=Floats(row["bind"])};}}
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);string kind=(string)row["kind"];object actual;var expected=new Dictionary<string,object>(M(row["native"]));
            if(kind=="blend")
            {
                var clip=clips[I(row["clip"])];var buffer=new SkeletalEulerBuffer(clip.NodeCount);
                if(row.ContainsKey("initial")){var initial=M(row["initial"]);var source=clips[I(initial["clip"])];SkeletalPose.Sample(source,F(initial["frame"]),buffer,source.NodeCount,0);}
                else{object[] values=A(row["values"]),flags=A(row["flags"]);for(int n=0;n<values.Length;++n){Array.Copy(Floats(values[n]),buffer.Values[n],9);buffer.Flags[n]=(byte)I(flags[n]);}}
                float[] root=new float[]{PcObjectImage.FromBits(0xa5a5a5a5),PcObjectImage.FromBits(0xa5a5a5a5),PcObjectImage.FromBits(0xa5a5a5a5)};
                int result=SkeletalBlend.Blend(clip,F(row["frame"]),buffer,F(row["weight"]),I(row["count"]),I(row["start"]),Convert.ToBoolean(row["root"])?root:null);
                actual=new{valuesSha256=Digest(buffer.Values),flags=Array.ConvertAll(buffer.Flags,v=>(int)v),root=Array.ConvertAll(root,PcObjectImage.ToBits),@return=result,quaternion=buffer.Quaternion?1:0};
                // Three native padding words/node are outside the portable buffer.
                expected.Remove("paddingPreserved");
            }
            else if(kind=="evaluate")
            {
                var pose=SkeletalBlend.Evaluate(clips[I(row["sourceClip"])],F(row["sourceFrame"]),clips[I(row["targetClip"])],F(row["targetFrame"]),F(row["weight"]),rigs[I(row["rig"])],table,SkeletalPose.D3dx9_35ScalarMultiply);
                actual=new{worldSha256=Digest(pose.WorldMatrices),scalesSha256=Digest(pose.CumulativeScales)};
                // Original scratch and global mode-stack invariants have no
                // projected managed storage; the native oracle verifies them.
                foreach(string key in new string[]{"arenaRestored","depthRestored","globalRestored","stackEntry"})expected.Remove(key);
            }
            else throw new ArgumentException(kind);
            actual=Json.DeserializeObject(Json.Serialize(actual));++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{kind,caseIndex=checks-1,actual,expected});}
        }
        File.WriteAllText(args[2],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
