// Prepared original-PC bounds observations. Compile only.
using System;using System.IO;using System.IO.Compression;using System.Collections.Generic;using System.Globalization;using System.Web.Script.Serialization;
using Recovered.Gameplay;using Recovered.Animation;
public static class SceneAnimationBoundsVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static int I(Dictionary<string,object> v,string k,int d){return v.ContainsKey(k)?Convert.ToInt32(v[k],CultureInfo.InvariantCulture):d;}
    static uint U(Dictionary<string,object> v,string k,uint d){return v.ContainsKey(k)?Convert.ToUInt32(v[k],CultureInfo.InvariantCulture):d;}
    static bool B(Dictionary<string,object> v,string k,bool d){return v.ContainsKey(k)?Convert.ToBoolean(v[k]):d;}
    static float[] F(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(Convert.ToUInt32(x,CultureInfo.InvariantCulture)));}
    static float Scalar(object v){return PcObjectImage.FromBits(Convert.ToUInt32(v,CultureInfo.InvariantCulture));}
    static object[] Record(SceneAnimationBoundsRecord v){var a=new object[8];for(int i=0;i<8;++i)a[i]=(v.KnownMask&(1<<i))==0?null:(object)PcObjectImage.ToBits(v.Values[i]);return a;}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("<native-fixtures.json.gz> <native-sine-table.f32> <output.json>");Dictionary<string,object> fixtures;
        using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixtures=M(Json.DeserializeObject(reader.ReadToEnd()));
        byte[] sine=File.ReadAllBytes(args[1]);if(sine.Length!=131072)throw new ArgumentException("Invalid original sine table");float[] table=new float[32768];for(int i=0;i<table.Length;++i)table[i]=BitConverter.ToSingle(sine,4*i);
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object raw in A(fixtures["cases"]))
        {
            var c=M(raw);var input=M(c["input"]);var expected=M(c["native"]);var owner=new SceneAnimationBoundsOwner{Flags=U(input,"gate",0x10000)|(B(input,"center",false)?0x4000u:0u),Records=new SceneAnimationBoundsRecord[3]};
            for(int j=0;j<3;++j){owner.Records[j]=new SceneAnimationBoundsRecord();for(int k=0;k<8;++k)owner.Records[j].Values[k]=PcObjectImage.FromBits(0xa5a5a5a5);}
            var reference=new SceneAnimationBoundsReference{HasScene=B(input,"scene",true),HasDisplay=B(input,"present",true),HasNormalInstance=I(input,"mode",2)==1,Owner=B(input,"descriptor",true)?owner:null,DisplayFlags=U(input,"flags",0),BoundsIndex=1,
                LocalMinimum=F(input["lo"]),LocalMaximum=F(input["hi"]),DisplayTransform=F(input["fallback"]),InstanceTransform=F(input["fallback"]),DisplayAnimatedTransform=I(input,"pointer",1)==1?F(input["matrix"]):null,InstanceAnimatedTransform=I(input,"pointer",1)==1?F(input["matrix"]):null};
            if((string)c["kind"]=="poseChain")
            {
                var instance=new ScenePlaybackInstance{Target=new ScenePlaybackTarget(),PreviousEvaluation=Scalar(input["previous"])};
                var binding=new SceneAnimationPoseBinding{Instance=instance,Clip=new SceneAnimationClip(Convert.FromBase64String((string)input["raw"])),CachedMatrix=new float[16],TargetMatrix=F(input["matrix"]),BaseTranslation=new float[]{reference.DisplayTransform[12],reference.DisplayTransform[13],reference.DisplayTransform[14]}};
                binding.RefreshBounds=delegate{reference.DisplayAnimatedTransform=binding.TargetMatrix;SceneAnimationBounds.Notify(reference);};
                SceneAnimationPose.EvaluateChangedFrame(binding,Scalar(input["frame"]),table);
                object actualChain=new{target=Array.ConvertAll(binding.TargetMatrix,PcObjectImage.ToBits),cache=Array.ConvertAll(binding.CachedMatrix,PcObjectImage.ToBits),previous=PcObjectImage.ToBits(instance.PreviousEvaluation),flags=reference.DisplayFlags,record=Record(owner.Records[1])};
                actualChain=Json.DeserializeObject(Json.Serialize(actualChain));++checks;if(!Same(actualChain,expected)){++failures;if(errors.Count<12)errors.Add(new{input,actual=actualChain,expected});}continue;
            }
            if(B(input,"notify",true))SceneAnimationBounds.Notify(I(input,"mode",2)==0?null:reference);else SceneAnimationBounds.Rebuild(reference);
            var record=owner.Records[1];var native=A(expected["record"]);var actual=new object[8];bool same=reference.DisplayFlags==Convert.ToUInt32(expected["flags"],CultureInfo.InvariantCulture);
            for(int j=0;j<8;++j){actual[j]=(record.KnownMask&(1<<j))==0?null:(object)PcObjectImage.ToBits(record.Values[j]);if(native[j]==null?actual[j]!=null:actual[j]==null||Convert.ToUInt32(actual[j],CultureInfo.InvariantCulture)!=Convert.ToUInt32(native[j],CultureInfo.InvariantCulture))same=false;}
            for(int j=0;j<8;++j)if(PcObjectImage.ToBits(owner.Records[0].Values[j])!=0xa5a5a5a5||PcObjectImage.ToBits(owner.Records[2].Values[j])!=0xa5a5a5a5)same=false;
            ++checks;if(!same){++failures;if(errors.Count<12)errors.Add(new{input,actual,flags=reference.DisplayFlags,expected});}
        }
        File.WriteAllText(args[2],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
