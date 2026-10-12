// Test executable only. The reconstructed library does not depend on System.Web.Extensions.
using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

class GameplayPortableVerify
{
    static int checks, failures;
    static Dictionary<string,int> categories = new Dictionary<string,int>();
    static List<object> errors = new List<object>();
    static Dictionary<string,object> Obj(object x) { return (Dictionary<string,object>)x; }
    static object[] Arr(object x) { return (object[])x; }
    static int Int(object x) { return Convert.ToInt32(x); }
    static uint UInt(object x) { return Convert.ToUInt32(x); }
    static float Float(object x) { return Convert.ToSingle(x); }
    static uint Bits(float x) { return BitConverter.ToUInt32(BitConverter.GetBytes(x),0); }
    static float FromBits(object x) { return BitConverter.ToSingle(BitConverter.GetBytes(UInt(x)),0); }
    static void Check(string kind, object got, object expected, object context)
    {
        ++checks; if (!categories.ContainsKey(kind)) categories[kind] = 0; ++categories[kind];
        if (!Object.Equals(got,expected)) { ++failures; if (errors.Count < 20) errors.Add(new { kind,got,expected,context }); }
    }
    static void Snapshot(FlowGraph graph, List<FlowTimer> timers, object state, object context)
    {
        object[] values = Arr(state);
        for (int i=0;i<values.Length;++i)
        {
            Dictionary<string,object> v=Obj(values[i]);FlowNode node=graph.Nodes[i];
            Check("graph-flags",(int)node.Flags,Int(v["flags"]),context);Check("graph-tick-generation",(int)node.Generation,Int(v["stamp"]),context);Check("graph-reset-generation",(int)node.ResetGeneration,Int(v["resetStamp"]),context);
            if(timers[i]!=null) { Check("graph-timer-bits",Bits(timers[i].Remaining),Bits(Float(v["remaining"])),context);Check("graph-timer-flags",(int)timers[i].Flags,Int(v["timerFlags"]),context); }
        }
    }
    sealed class SceneFixture : ISceneAnimation
    {
        public float Speed=.75f,Frame=.5f;
        public bool Visible,BoundsVisible,Playing=true;
        public int Flags=4;
        public readonly List<string> Trace = new List<string>();
        public void JumpToStart() { Frame=0;Playing=false; }
        public void Play(float speed,bool evaluate) { Trace.Add("0x5a1030");Speed=speed;Playing=true;Flags&=~2; }
        public void Stop() { Trace.Add("0x5a1170");Flags|=2;Playing=false; }
        public void SetVisibility(bool visible) { Trace.Add("0x5cfc00");Visible=BoundsVisible=visible; }
    }
    public static int Main(string[] args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;json.RecursionLimit=200;
        Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        int graphIndex=0;
        foreach(object entry in Arr(data["graphs"]))
        {
            Dictionary<string,object> input=Obj(entry);FlowGraph graph=new FlowGraph();graph.Generation=(byte)Int(input["generation"]);List<FlowTimer> timers=new List<FlowTimer>();QRandom random=new QRandom();
            foreach(object item in Arr(input["nodes"]))
            {
                Dictionary<string,object> spec=Obj(item);FlowNode node=new FlowNode();node.Kind=(FlowKind)Int(spec["kind"]);node.Flags=(ushort)Int(spec["flags"]);node.Condition=(FlowCondition)Int(spec["condition"]);node.Threshold=(byte)Int(spec["threshold"]);node.LoopInputs=(byte)Int(spec["skip"]);node.Generation=(byte)Int(spec["stamp"]);node.ResetGeneration=(byte)Int(spec["resetStamp"]);node.Name=(string)spec["name"];
                foreach(object parent in Arr(spec["parents"]))node.Parents.Add(new FlowInput(Int(parent),0));foreach(object child in Arr(spec["children"]))node.Children.Add(Int(child));
                foreach(object action in Arr(spec["actions"])) { object[] a=Arr(action);string[] tokens=new string[a.Length];for(int i=0;i<a.Length;++i)tokens[i]=(string)a[i];node.Actions.Add(delegate(FlowGraph g,FlowNode unused){g.TurnOnFlowBox(tokens);}); }
                FlowTimer timer=null;if(node.Kind==FlowKind.Gizmo){timer=new FlowTimer(Float(spec["duration"]),random);timer.Remaining=Float(spec["remaining"]);timer.Flags=(byte)Int(spec["timerFlags"]);node.Gizmos.Add(timer.Callbacks());}timers.Add(timer);graph.Nodes.Add(node);
            }
            if((bool)input["initialize"])graph.Initialize(null);
            Snapshot(graph,timers,input["initialState"],"initial:"+graphIndex);Check("initial-reset-counter",(int)graph.ResetGeneration,Int(input["initialResetGeneration"]),graphIndex);
            int frame=0;foreach(object row in Arr(input["frames"]))
            {
                Dictionary<string,object> expected=Obj(row);foreach(FlowTimer timer in timers)if(timer!=null)timer.Update(Float(expected["delta"]));graph.Tick();string context=graphIndex+":"+frame;Snapshot(graph,timers,expected["state"],context);Check("graph-generation",(int)graph.Generation,Int(expected["generation"]),context);Check("graph-global-reset",(int)graph.ResetGeneration,Int(expected["resetGeneration"]),context);++frame;
            }
            ++graphIndex;
        }
        byte[] selections=Convert.FromBase64String((string)data["equalRandomSelections"]);
        for(uint seed=0;seed<selections.Length;++seed)
        {
            QRandom rng=new QRandom();rng.State=seed;FlowRandom random=new FlowRandom { Random=rng,Weights=new int[]{25,25,25,25} };random.Activate(true);Check("random-all-65536-seeds",random.Selected,(int)selections[seed],seed);
        }
        foreach(object row in Arr(data["randomTimers"]))
        {
            object[] a=Arr(row);QRandom rng=new QRandom();rng.State=UInt(a[0]);FlowTimer timer=new FlowTimer(FromBits(a[1]),rng);timer.Flags=2;timer.Activate(true);Check("random-timer-exact-bits",Bits(timer.Remaining),UInt(a[2]),a[0]);Check("random-timer-state",rng.State,UInt(a[3]),a[0]);
        }
        foreach(object row in Arr(data["savedStates"]))
        {
            Dictionary<string,object> entry=Obj(row);FlowGraph graph=new FlowGraph();foreach(object flag in Arr(entry["flags"]))graph.Nodes.Add(new FlowNode { Kind=FlowKind.Action,Flags=(ushort)Int(flag) });uint[] saved=graph.Save();object[] words=Arr(entry["words"]);for(int i=0;i<words.Length;++i)Check("saved-bitplanes",saved[i],UInt(words[i]),i);
            object[] initial=Arr(entry["initial"]);for(int i=0;i<initial.Length;++i){graph.Nodes[i].Flags=(ushort)Int(initial[i]);graph.Nodes[i].Generation=199;graph.Nodes[i].ResetGeneration=178;}graph.Initialize(saved);object[] restored=Arr(entry["restored"]);for(int i=0;i<restored.Length;++i){Check("restored-flags",(int)graph.Nodes[i].Flags,Int(restored[i]),i);Check("restored-tick-stamp",(int)graph.Nodes[i].Generation,0,i);Check("restored-nonloop-reset-stamp",(int)graph.Nodes[i].ResetGeneration,178,i);}
        }
        foreach(object row in Arr(data["physicalCases"]))
        {
            Dictionary<string,object> entry=Obj(row),expected=Obj(entry["after"]);SceneFixture scene=new SceneFixture();scene.Visible=scene.BoundsVisible=(bool)entry["priorVisible"];SpecialGizmo special=new SpecialGizmo(scene);special.Flags=(byte)(2|((bool)entry["priorReverse"]?1:0));GizmoCallbacks callbacks=new GizmoCallbacks();callbacks.Activate=delegate(bool value){scene.Trace.Add("0x5ae450");special.Activate(value);};callbacks.Reverse=delegate(bool value,int mode){scene.Trace.Add("0x5ae4a0");return special.Reverse(value,mode);};callbacks.Visibility=delegate(bool value){scene.Trace.Add("0x5ae520");scene.SetVisibility(value);};callbacks.SetReverse((bool)entry["reverse"],(bool)entry["withVisibility"]);
            Check("special-flags",(int)special.Flags,Int(expected["flags"]),row);Check("special-animation-flags",scene.Flags,Int(expected["animFlags"]),row);Check("special-speed",Bits(scene.Speed),Bits(Float(expected["speed"])),row);Check("special-frame",Bits(scene.Frame),Bits(Float(expected["frame"])),row);Check("special-playing",scene.Playing,Int(expected["playing"])!=0,row);Check("special-visibility",scene.Visible,(bool)expected["visible"],row);Check("special-bound-visibility",scene.BoundsVisible,(bool)expected["boundsVisible"],row);object[] trace=Arr(entry["trace"]);Check("special-callback-count",scene.Trace.Count,trace.Length,row);for(int i=0;i<Math.Min(trace.Length,scene.Trace.Count);++i)Check("special-callback-order",scene.Trace[i],Obj(trace[i])["address"],i);
        }
        foreach(object row in Arr(data["monitorOutputCases"]))
        {
            object[] a=Arr(row);FlowGraph graph=new FlowGraph();SceneFixture scene=new SceneFixture();SpecialGizmo special=new SpecialGizmo(scene);special.Flags=2;FlowNode target=new FlowNode { Kind=FlowKind.Gizmo,Flags=0x100 };target.Gizmos.Add(special.Callbacks(null));target.Parents.Add(new FlowInput(1,(byte)Int(a[2])));target.Parents.Add(new FlowInput(2,(byte)Int(a[3])));graph.Nodes.Add(target);
            for(int i=0;i<2;++i){FlowRandom random=new FlowRandom { Flags=1,Selected=Int(a[i]) };FlowNode node=new FlowNode { Kind=FlowKind.Gizmo,Flags=0x4000 };node.Gizmos.Add(random.Callbacks());graph.Nodes.Add(node);}graph.Tick();Check("monitor-first-output-index",(int)(special.Flags&1),Int(a[4]),row);
        }
        object report=new { binarySha256=data["binarySha256"],method="Compiled dependency-free C# reconstruction compared with original-PC captured outputs",checks,categories,mismatches=failures,errors,limits=new string[]{"Captured fixtures are bounded evidence, not a full level or complete engine run.","Physical callback adapter is tested on the native one-static-instance fixture; host renderer/animation/collision implementation remains separate.","Timer random rounding is checked exactly on the recorded seeds and durations, not every possible binary32 input.","Source GIT parsing, name resolution and editor Collapse flattening remain external adapters."} };
        File.WriteAllText(args[1],json.Serialize(report));Console.WriteLine("Checks: "+checks+", mismatches: "+failures);return failures==0?0:1;
    }
}
