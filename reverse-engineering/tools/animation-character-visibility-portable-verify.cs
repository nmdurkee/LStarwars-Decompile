using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Geometry;
public static class CharacterVisibilityVerify
{
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static float F(object v){return PcObjectImage.FromBits(Convert.ToUInt32(v));}static float[] Floats(object v){return Array.ConvertAll(A(v),F);}static uint[] Bits(float[] v){return v==null?null:Array.ConvertAll(v,PcObjectImage.ToBits);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;var ma=a as IDictionary;var mb=b as IDictionary;if(ma!=null&&mb!=null){if(ma.Count!=mb.Count)return false;foreach(object k in ma.Keys)if(!mb.Contains(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as IList;var ab=b as IList;if(aa!=null&&ab!=null){if(aa.Count!=ab.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],ab[i]))return false;return true;}return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<character-visibility-fixtures.json.gz> <result.json>");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var reader=new StreamReader(z))fixture=M(json.DeserializeObject(reader.ReadToEnd()));var rigs=A(fixture["rigs"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var c=M(item);var rig=M(rigs[Convert.ToInt32(c["rig"])]);var input=M(c["state"]);var p=A(input["camera"]);var camera=new DynamicBoxState{Near=F(p[0]),Far=F(p[1]),FarOverride=F(p[2]),HorizontalSlope=F(p[3]),VerticalSlope=F(p[4]),Enabled=Convert.ToInt32(p[5])!=0,View=Floats(input["view"]),CombinedMatrix=Floats(fixture["beforeMatrix"]),FarLanes=Floats(fixture["beforeFar"])};
            int result=CharacterVisibility.Classify(camera,Floats(rig["minimum"]),Floats(rig["maximum"]),input["world"]==null?null:Floats(input["world"]),Floats(rig["root"]),Convert.ToBoolean(input["center"]));object actual=new{result,combined=Bits(camera.CombinedMatrix),far=Bits(camera.FarLanes),corners=Bits(camera.LastCorners)};actual=json.DeserializeObject(json.Serialize(actual));var expected=new Dictionary<string,object>(M(c["native"]));expected.Remove("input");expected.Remove("calls");
            // Original-vs-model probes separately observe preprocessed arguments
            // and helper entries. This replay compares public effects/results.
            ++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,actual,expected});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
