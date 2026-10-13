using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class SecondaryVisibilityVerify
{
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static float[] Floats(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(U(x)));}
    static SecondaryVisibilityContext Context(object v)
    {return new SecondaryVisibilityContext{Volumes=Array.ConvertAll(A(v),x=>new SecondaryVisibilityVolume{Planes=Array.ConvertAll(A(x),Floats)})};}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var input=File.OpenRead(args[0]))using(var zip=new GZipStream(input,CompressionMode.Decompress))using(var reader=new StreamReader(zip))fixture=M(json.DeserializeObject(reader.ReadToEnd()));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var contexts=Array.ConvertAll(A(c["contexts"]),Context);float[] low=Floats(c["low"]),high=Floats(c["high"]);uint result;uint flag=0;uint[] masks=null;bool pass;
            if((string)c["kind"]=="volume")result=SecondaryVisibility.IntersectsVolume(contexts[0].Volumes[0],low,high)?1u:0u;
            else if((string)c["kind"]=="mask")result=SecondaryVisibility.BuildMask(contexts[0],low,high);
            else
            {
                int count=I(c["count"]);var selected=new SecondaryVisibilityContext[count];if(!Convert.ToBoolean(c["poisonContexts"]))for(int i=0;i<count;++i)selected[i]=contexts[i%contexts.Length];
                var state=new SecondaryVisibilityState{Count=count,CacheFlag=U(c["flag"]),Masks=Array.ConvertAll(A(c["initial"]),U),Contexts=Convert.ToBoolean(c["poisonContexts"])?null:selected};
                result=(uint)SecondaryVisibility.Evaluate(state,low.Length==0?null:low,high.Length==0?null:high,I(c["refresh"]));flag=state.CacheFlag;masks=state.Masks;
            }
            pass=result==U(c["native"]);
            if(masks!=null){pass=pass&&flag==U(c["nativeFlag"]);object[] expected=A(c["nativeMasks"]);if(expected.Length!=masks.Length)pass=false;else for(int i=0;i<masks.Length;++i)if(masks[i]!=U(expected[i]))pass=false;}
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,result,flag,masks,expected=c});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
