// Prepared exact replay; compile only while managed execution is restricted.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class SkeletalPoseVerify
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
        if(args.Length!=3)throw new ArgumentException("<native-fixtures.json.gz> <native-sine-table.f32> <result.json>");
        Dictionary<string,object> fixture;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        byte[] sine=File.ReadAllBytes(args[1]);if(sine.Length!=131072)throw new ArgumentException("Invalid sine table");float[] table=new float[32768];for(int i=0;i<table.Length;++i)table[i]=BitConverter.ToSingle(sine,i*4);
        object[] clipRows=A(fixture["clips"]);var clips=new SkeletalClip[clipRows.Length];for(int i=0;i<clips.Length;++i)clips[i]=new SkeletalClip(Convert.FromBase64String((string)M(clipRows[i])["raw"]));
        object[] rigRows=A(fixture["rigs"]);var rigs=new SkeletalJoint[rigRows.Length][];
        for(int i=0;i<rigs.Length;++i){object[] rows=A(M(rigRows[i])["joints"]);rigs[i]=new SkeletalJoint[rows.Length];for(int j=0;j<rows.Length;++j){var row=M(rows[j]);rigs[i][j]=new SkeletalJoint{Parent=(byte)I(row["parent"]),AnimationBindMatrix=Floats(row["bind"])};}}
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);string kind=(string)row["kind"];object actual;var expected=new Dictionary<string,object>(M(row["native"]));
            if(kind=="scalar")
            {
                var clip=clips[I(row["clip"])];var buffer=new SkeletalEulerBuffer(clip.NodeCount){Quaternion=true};for(int n=0;n<clip.NodeCount;++n){buffer.Flags[n]=0xa5;for(int c=0;c<9;++c)buffer.Values[n][c]=PcObjectImage.FromBits(0xa5a5a5a5);}
                int result=SkeletalPose.Sample(clip,F(row["frame"]),buffer,I(row["count"]),I(row["start"]));actual=new{valuesSha256=Digest(buffer.Values),flags=Array.ConvertAll(buffer.Flags,v=>(int)v),quaternion=buffer.Quaternion?1:0,@return=result};
                // Native record padding is intentionally absent from the projected
                // buffer; only the original oracle checks those untouched bytes.
                expected.Remove("paddingPreserved");
            }
            else if(kind=="evaluate")
            {
                var pose=SkeletalPose.Evaluate(clips[I(row["clip"])],F(row["frame"]),rigs[I(row["rig"])],table,SkeletalPose.D3dx9_35ScalarMultiply);actual=new{worldSha256=Digest(pose.WorldMatrices),scalesSha256=Digest(pose.CumulativeScales)};
                // Native scratch-arena balance is checked by the original oracle;
                // managed arrays deliberately have a different ownership model.
                expected.Remove("arenaRestored");
            }
            else if(kind=="pose")
            {
                object[] values=A(row["values"]),flags=A(row["flags"]);var buffer=new SkeletalEulerBuffer(values.Length);for(int n=0;n<values.Length;++n){Array.Copy(Floats(values[n]),buffer.Values[n],9);buffer.Flags[n]=(byte)I(flags[n]);}
                var pose=SkeletalPose.Build(buffer,rigs[I(row["rig"])],I(row["clipCount"]),table,SkeletalPose.D3dx9_35ScalarMultiply);actual=new{worldSha256=Digest(pose.WorldMatrices),scalesSha256=Digest(pose.CumulativeScales)};
            }
            else throw new ArgumentException(kind);
            actual=Json.DeserializeObject(Json.Serialize(actual));++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{kind,caseIndex=checks-1,actual,expected});}
        }
        File.WriteAllText(args[2],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
