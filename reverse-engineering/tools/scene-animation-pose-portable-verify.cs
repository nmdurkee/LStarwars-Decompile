// Prepared replay of original-PC scalar/matrix observations. Compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public static class SceneAnimationPoseVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v,CultureInfo.InvariantCulture);}
    static uint U(object v){return Convert.ToUInt32(v,CultureInfo.InvariantCulture);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static uint[] Bits(float[] v){return Array.ConvertAll(v,PcObjectImage.ToBits);}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static bool Same(object a,object b)
    {
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    static object Apply(Dictionary<string,object> input,SceneAnimationClip clip,float[] table,bool tick)
    {
        bool present=Convert.ToBoolean(input["present"]),hasClip=Convert.ToBoolean(input["hasClip"]);float frame=F(input["frame"]);
        var instance=new ScenePlaybackInstance{Target=present?new ScenePlaybackTarget{Frame=frame}:null,Special=new ScenePlaybackSpecial{DisplayFlags=2},HasClip=hasClip,ClipEndFrame=16,PreviousEvaluation=F(input["previous"])};
        var binding=new SceneAnimationPoseBinding{Instance=instance,Clip=hasClip?clip:null,CachedMatrix=Floats(input["cached"]),TargetMatrix=Floats(input["target"]),BaseTranslation=Floats(input["base"])};var bounds=new List<object>();
        binding.RefreshBounds=delegate{bounds.Add(new{target=Bits(binding.TargetMatrix),cache=Bits(binding.CachedMatrix)});};
        if(tick){var scene=new ScenePlaybackScene{AnimationDataCount=1};scene.Instances.Add(instance);foreach(var work in SceneAnimationUpdate.UpdateScene(scene,0))SceneAnimationPose.ApplyWork(work,binding,table);}
        else SceneAnimationPose.EvaluateChangedFrame(binding,frame,table);
        return new{target=Bits(binding.TargetMatrix),cache=Bits(binding.CachedMatrix),previous=PcObjectImage.ToBits(instance.PreviousEvaluation),bounds};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("<native-fixtures.json.gz> <native-sine-table.f32> <result.json>");
        Dictionary<string,object> fixtures;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixtures=M(Json.DeserializeObject(reader.ReadToEnd()));
        byte[] sine=File.ReadAllBytes(args[1]);if(sine.Length!=131072)throw new ArgumentException("Invalid original sine table");float[] table=new float[32768];for(int i=0;i<table.Length;++i)table[i]=BitConverter.ToSingle(sine,i*4);
        var raw=A(fixtures["clips"]);var clips=new SceneAnimationClip[raw.Length];for(int i=0;i<raw.Length;++i)clips[i]=new SceneAnimationClip(Convert.FromBase64String((string)M(raw[i])["raw"]));
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object row in A(fixtures["cases"]))
        {
            var c=M(row);string kind=(string)c["kind"];var input=M(c["input"]);object actual;
            if(kind=="scalar")actual=Bits(SceneAnimationPose.Sample(clips[I(input["clip"])],F(input["frame"])));
            else if(kind=="pose")actual=Bits(SceneAnimationPose.Evaluate(clips[I(input["clip"])],F(input["frame"]),table));
            else if(kind=="rotation"){var angles=A(input["angles"]);actual=Bits(SceneAnimationPose.Rotation(I(angles[0]),I(angles[1]),I(angles[2]),table));}
            else if(kind=="scale"||kind=="translate"){var matrix=Floats(input["matrix"]);var vector=Floats(input["vector"]);if(kind=="scale")SceneAnimationPose.ScaleRows(matrix,vector);else SceneAnimationPose.Translate(matrix,vector);actual=Bits(matrix);}
            else if(kind=="changedFrame"||kind=="applyWork")actual=Apply(input,clips[I(input["clip"])],table,kind=="applyWork");
            else throw new ArgumentException(kind);
            object expected=c["native"];var expectedObject=expected as Dictionary<string,object>;
            // This additional original-byte invariant is native-only: the portable
            // projected records do not contain the unrelated native object bytes.
            if(expectedObject!=null){expectedObject=new Dictionary<string,object>(expectedObject);expectedObject.Remove("otherTargetBytesPreserved");expected=expectedObject;}
            actual=Json.DeserializeObject(Json.Serialize(actual));bool same=Same(actual,expected);++checks;
            if(!same){++failures;if(errors.Count<12)errors.Add(new{kind,input,actual,expected});}
        }
        File.WriteAllText(args[2],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
