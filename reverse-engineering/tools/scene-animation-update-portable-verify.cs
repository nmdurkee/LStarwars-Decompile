// Prepared replay of original-PC scenery temporal observations. Compile only.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Globalization;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public static class SceneAnimationUpdateVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(Dictionary<string,object> m,string k,int d){return m.ContainsKey(k)?Convert.ToInt32(m[k],CultureInfo.InvariantCulture):d;}
    static uint U(Dictionary<string,object> m,string k,uint d){return m.ContainsKey(k)?Convert.ToUInt32(m[k],CultureInfo.InvariantCulture):d;}
    static float F(Dictionary<string,object> m,string k,float d){return m.ContainsKey(k+"Bits")?PcObjectImage.FromBits(U(m,k+"Bits",0)):m.ContainsKey(k)?Convert.ToSingle(m[k],CultureInfo.InvariantCulture):d;}
    static bool B(Dictionary<string,object> m,string k,bool d){return m.ContainsKey(k)?Convert.ToBoolean(m[k]):d;}
    static uint Bits(float v){return PcObjectImage.ToBits(v);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(var k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
        var aa=a as object[];var ab=b as object[];
        if(aa!=null||ab!=null){if(aa==null||ab==null||aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Same(aa[i],ab[i]))return false;return true;}
        return Convert.ToString(a,CultureInfo.InvariantCulture)==Convert.ToString(b,CultureInfo.InvariantCulture);
    }
    static object Groups(Dictionary<string,object> input)
    {
        var raw=A(input["groups"]);var groups=new ScenePlaybackGroup[raw.Length];var queue=new ScenePlaybackQueue();
        var targets=new List<ScenePlaybackTarget>();var specials=new List<ScenePlaybackSpecial>();var calls=new List<object>();
        var bindings=new Dictionary<ScenePlaybackNode,ScenePlaybackNodeBinding>();int index=0;
        for(int gi=0;gi<groups.Length;++gi)
        {
            var source=M(raw[gi]);var group=groups[gi]=new ScenePlaybackGroup{Flags=(ushort)I(source,"flags",4),State=I(source,"state",4),Queue=B(source,"queue",true)?queue:null};
            if(B(source,"queued",B(source,"queue",true)))queue.Groups.Add(group);
            foreach(object o in A(source["nodes"]))
            {
                var v=M(o);int kind=I(v,"kind",2),nodeIndex=index++;
                var t=new ScenePlaybackTarget{Frame=F(v,"frame",0),Rate=F(v,"rate",1),Flags=U(v,"targetFlags",1)};targets.Add(t);
                var sp=new ScenePlaybackSpecial{HasScene=kind!=0,HasInstance=kind==1,HasDisplay=kind==2,InstanceFlags=U(v,"instanceFlags",0),DisplayFlags=U(v,"displayFlags",0)};specials.Add(sp);
                var node=new ScenePlaybackNode{Target=B(v,"present",true)?t:null,Start=F(v,"start",0),End=F(v,"end",0)};group.Nodes.Add(node);
                bindings[node]=new ScenePlaybackNodeBinding{Special=sp,EvaluateChangedFrame=delegate(float frame){calls.Add(new object[]{nodeIndex,Bits(frame)});}};
            }
        }
        string operation=(string)input["operation"];
        if(operation=="update")SceneAnimationUpdate.UpdateGroups(queue,bindings);
        else if(operation=="remove")SceneAnimationUpdate.Remove(groups[I(input,"selected",0)]);
        else if(operation=="reset")SceneAnimationUpdate.Reset(groups[I(input,"selected",0)]);
        else throw new ArgumentException(operation);
        var groupState=new List<object>();foreach(var g in groups)groupState.Add(new object[]{g.Flags,g.State});
        var targetState=new List<object>();foreach(var t in targets)targetState.Add(new object[]{Bits(t.Frame),Bits(t.Rate),t.Flags});
        var specialState=new List<object>();foreach(var sp in specials)specialState.Add(new object[]{sp.InstanceFlags,sp.DisplayFlags});
        var queueState=new List<int>();foreach(var g in queue.Groups)queueState.Add(Array.IndexOf(groups,g));
        return new{groups=groupState,targets=targetState,specials=specialState,queue=queueState,evaluations=calls};
    }
    static ScenePlaybackScene BuildScene(Dictionary<string,object> options)
    {
        var scene=new ScenePlaybackScene{HasAnimationTable=B(options,"table",true),AnimationDataCount=(short)I(options,"dataCount",1),StateTableOwnerCount=I(options,"owners",2)};
        if(options.ContainsKey("tracks")&&options["tracks"]!=null)
        {
            var raw=A(options["tracks"]);scene.StateTracks=new ScenePlaybackStateTrack[raw.Length];
            for(int i=0;i<raw.Length;++i){var track=M(raw[i]);scene.StateTracks[i]=new ScenePlaybackStateTrack{EndFrame=(ushort)I(track,"end",0),Times=Array.ConvertAll(A(track["times"]),v=>Convert.ToSingle(v,CultureInfo.InvariantCulture)),Values=Array.ConvertAll(A(track["values"]),v=>Convert.ToByte(v,CultureInfo.InvariantCulture))};}
        }
        var clip=options.ContainsKey("clip")?M(options["clip"]):null;
        foreach(object raw in A(options["instances"]))
        {
            var v=M(raw);scene.Instances.Add(new ScenePlaybackInstance{Target=new ScenePlaybackTarget{Frame=F(v,"frame",0),Rate=F(v,"rate",0),Flags=U(v,"flags",0)},
                Special=new ScenePlaybackSpecial{DisplayFlags=U(v,"displayFlags",2)},AnimationIndex=(ushort)I(v,"animationIndex",0),HasClip=clip!=null,ClipEndFrame=clip==null?0:F(clip,"end",0),FirstFrame=F(v,"first",0),Interval=F(v,"interval",0),PreviousEvaluation=F(v,"previous",0)});
        }
        return scene;
    }
    static object SceneState(ScenePlaybackScene scene,List<ScenePlaybackEvaluation> work)
    {
        var states=new List<object>();var evals=new List<object>();var copies=new List<int>();
        foreach(var row in work){int i=scene.Instances.IndexOf(row.Instance);if(row.EvaluatePose)evals.Add(new object[]{i,Bits(row.Frame)});if(row.CopyPose)copies.Add(i);}
        foreach(var row in scene.Instances)states.Add(new{frame=Bits(row.Target.Frame),flags=row.Target.Flags,previous=Bits(row.PreviousEvaluation),displayFlags=row.Special.DisplayFlags});
        return new{instances=states,lookupPresent=scene.StateTracks!=null,evaluations=evals,copies=copies};
    }
    static object Scene(Dictionary<string,object> input)
    {
        var scene=BuildScene(M(input["options"]));return SceneState(scene,SceneAnimationUpdate.UpdateScene(scene,F(input,"delta",0)));
    }
    static object Chain(Dictionary<string,object> input)
    {
        var scene=BuildScene(M(input["options"]));var instance=scene.Instances[0];var target=instance.Target;var special=instance.Special;
        var queue=new ScenePlaybackQueue();var group=new ScenePlaybackGroup{Flags=(ushort)I(input,"flags",0),State=I(input,"state",0),Queue=queue};
        if(B(input,"queued",false))queue.Groups.Add(group);
        var node=new ScenePlaybackNode{Target=target,Start=3,End=12};group.Nodes.Add(node);var calls=new List<object>();
        var bindings=new Dictionary<ScenePlaybackNode,ScenePlaybackNodeBinding>();bindings[node]=new ScenePlaybackNodeBinding{Special=special,EvaluateChangedFrame=delegate(float v){calls.Add(new object[]{0,Bits(v)});}};
        var work=SceneAnimationUpdate.UpdateScene(scene,F(input,"delta",0));SceneAnimationUpdate.UpdateGroups(queue,bindings);
        var groupState=new{groups=new object[]{new object[]{group.Flags,group.State}},targets=new object[]{new object[]{Bits(target.Frame),Bits(target.Rate),target.Flags}},specials=new object[]{new object[]{special.InstanceFlags,special.DisplayFlags}},queue=queue.Groups.Count==0?new int[0]:new int[]{0},evaluations=calls};
        return new{clock=SceneState(scene,work),group=groupState};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<native-fixtures.json.gz> <result.json>");
        Dictionary<string,object> fixtures;using(var file=File.OpenRead(args[0]))using(var gzip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(gzip))fixtures=M(Json.DeserializeObject(reader.ReadToEnd()));
        int checks=0,failures=0;var errors=new List<object>();
        foreach(object raw in A(fixtures["cases"]))
        {
            var c=M(raw);string group=(string)c["group"];var input=M(c["input"]);object actual=group=="groups"?Groups(input):group=="scene"?Scene(input):group=="chain"?Chain(input):null;
            if(actual==null)throw new ArgumentException(group);++checks;actual=Json.DeserializeObject(Json.Serialize(actual));
            if(!Same(actual,c["native"])){++failures;if(errors.Count<12)errors.Add(new{group,input,actual,expected=c["native"]});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
