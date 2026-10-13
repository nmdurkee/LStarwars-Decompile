// Prepared exact legacy morph replay. Compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class MorphWeightsVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}
    static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static byte[] Unhex(string v){byte[] b=new byte[v.Length/2];for(int i=0;i<b.Length;++i)b[i]=Byte.Parse(v.Substring(i*2,2),NumberStyles.HexNumber,CultureInfo.InvariantCulture);return b;}
    static int[] Layers(object v){return v==null?null:Array.ConvertAll(A(v),I);}
    static uint[][] Bits(float[][] rows){return rows==null?null:Array.ConvertAll(rows,r=>Array.ConvertAll(r,PcObjectImage.ToBits));}
    static MorphClip Clip(MorphClip[] clips,object i){return i==null?null:clips[I(i)];}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<morph-native-fixtures.json.gz> <result.json>");
        Dictionary<string,object> fixture;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        object[] clipRows=A(fixture["clips"]);var clips=new MorphClip[clipRows.Length];for(int i=0;i<clips.Length;++i)clips[i]=new MorphClip(Convert.FromBase64String((string)M(clipRows[i])["raw"]));
        int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var row=M(item);var input=M(row["input"]);string kind=(string)row["kind"];object actual;
            if(kind=="single")actual=Bits(MorphWeights.Single(Clip(clips,input["clip"]),F(input["frame"]),Layers(input["layers"])));
            else if(kind=="blend")actual=Bits(MorphWeights.Blend(Clip(clips,input["source"]),F(input["sourceFrame"]),Clip(clips,input["target"]),F(input["targetFrame"]),F(input["weight"]),Layers(input["layers"])));
            else if(kind=="scalar"){var clip=Clip(clips,input["clip"]);actual=PcObjectImage.ToBits(MorphWeights.SampleCurve(clip,I(input["curve"]),MorphWeights.PrepareTime(clip,F(input["frame"]))));}
            else if(kind=="time")
            {
                var t=MorphWeights.PrepareTime(Clip(clips,input["clip"]),F(input["frame"]));uint[] raw={PcObjectImage.ToBits(t.Frame),PcObjectImage.ToBits(t.LocalFrame),(uint)t.Chunk,(uint)t.Mask,(uint)t.ByteIndex,(uint)t.Subframe};actual=Array.ConvertAll(A(input["defined"]),v=>raw[I(v)]);
            }
            else if(kind=="packet")
            {
                var slots=Array.ConvertAll(A(input["clips"]),v=>Clip(clips,v));float[][] weights;bool writes=MorphWeights.EvaluatePacket(new AnimationPacket(Unhex((string)input["packet"])),slots,I(input["layerCount"]),U(input["mask"]),out weights);actual=new{untouched=!writes,rows=Bits(weights)};
            }
            else throw new ArgumentException(kind);
            actual=Json.DeserializeObject(Json.Serialize(actual));++checks;if(!Same(actual,row["native"])){++failures;if(errors.Count<12)errors.Add(new{kind,caseIndex=checks-1,actual,expected=row["native"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
