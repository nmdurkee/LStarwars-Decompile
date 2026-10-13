// Prepared composition replay, no new native entrypoint mapping.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class AnimationOverrideExpressionVerify
{
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}static bool Q(object v){return Convert.ToBoolean(v);}
    static uint Bits(float v){return PcObjectImage.ToBits(v);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;var ma=a as IDictionary;var mb=b as IDictionary;if(ma!=null&&mb!=null){if(ma.Count!=mb.Count)return false;foreach(object k in ma.Keys)if(!mb.Contains(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as IList;var ab=b as IList;if(aa!=null&&ab!=null){if(aa.Count!=ab.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<override-expression-fixtures.json.gz> <result.json>");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var file=File.OpenRead(args[0]))using(var zip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(zip))fixture=M(json.DeserializeObject(reader.ReadToEnd()));
        int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var row=M(item);var state=M(row["state"]);string[] tokens=Array.ConvertAll(A(row["tokens"]),v=>(string)v);var events=new List<object>();var actor=new PcObjectImage(new byte[0x10d8]);actor.Set16(0x3ee,17);actor.Set16(0x3f0,19);
            var processor=new ScriptAnimationProcessor{ActionTimer=3.25f};var definitions=new[]{new AnimationNameEntry{Name="idle",Action=0},new AnimationNameEntry{Name="walk",Action=2},new AnimationNameEntry{Name="jump",Action=3}};
            var packet=new ScriptPacket{Script=new ScriptDefinition()};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;++i){packet.Script.ParameterNames[i]=names[i];packet.Parameters[i]=values[i];}
            object creature=new object(),oldCreature=new object();var oldPacket=new ScriptPacket();var environment=new ExpressionEnvironment{Creature=oldCreature,ActivePacket=oldPacket};environment.Random.State=U(state["seed"]);environment.ObserveError=delegate(){events.Add(new object[]{"error"});};
            int result=ScriptAnimationOverride.Run(Q(state["packet"])?actor:null,Q(state["owner"]),Q(state["world"]),definitions,233,tokens,tokens.Length,I(state["first"]),Q(state["processor"])?processor:null,delegate(string text){events.Add(new object[]{"expression",text});return ScriptExpressions.EvaluateToken(environment,creature,packet,tokens,0);});
            var expected=new Dictionary<string,object>(M(row["native"]));var filtered=new List<object>();foreach(var e in A(expected["events"]))if((string)A(e)[0]!="lookup")filtered.Add(e);expected["events"]=filtered;
            // Lookup events are not observable through the pure FindAction API;
            // original command/lookup suites cover them. Compare final IDs here.
            object actual=new{result,source=unchecked((short)actor.U16(0x3ee)),target=unchecked((short)actor.U16(0x3f0)),timer=Bits(processor.ActionTimer),tokens,seed=environment.Random.State,creature=Object.ReferenceEquals(environment.Creature,creature)?1:2,packet=environment.ActivePacket==null?0:2,events};actual=json.DeserializeObject(json.Serialize(actual));
            ++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,actual,expected});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
