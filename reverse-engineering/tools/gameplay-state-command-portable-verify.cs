using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayStateCommandVerify
{
    static int checks, failures;
    static readonly List<object> errors = new List<object>();
    static Dictionary<string, object> Obj(object value) { return (Dictionary<string, object>)value; }
    static object[] Arr(object value) { return (object[])value; }
    static uint UInt(object value) { return Convert.ToUInt32(value); }
    static int Int(object value) { return Convert.ToInt32(value); }
    static uint Bits(float value) { return BitConverter.ToUInt32(BitConverter.GetBytes(value), 0); }
    static string[] Tokens(object value) { object[] a = Arr(value); string[] r = new string[a.Length]; for (int i=0;i<a.Length;++i) r[i]=(string)a[i]; return r; }
    static void Check(string name, object actual, object expected, object input)
    {
        ++checks; if (!Object.Equals(actual, expected)) { ++failures; if (errors.Count<20) errors.Add(new { name, actual, expected, input }); }
    }
    static object Index(Dictionary<ScriptState,int> ids, ScriptState state) { return state == null ? null : (object)ids[state]; }
    static void Run(Dictionary<string,object> input, bool shipped, string[] names)
    {
        Dictionary<string,object> options = !shipped ? Obj(input["options"]) : new Dictionary<string,object>();
        ScriptDefinition[] scripts = new ScriptDefinition[] { new ScriptDefinition(), new ScriptDefinition() };
        Dictionary<ScriptState,int> stateIds = new Dictionary<ScriptState,int>();
        for (int s=0;s<2;++s)
        {
            for (int i=0;i<4;++i) { scripts[s].Parameters[i]=10*s+i+.25f; scripts[s].ParameterNames[i]=new string[] {"alpha","beta","gamma","delta"}[i]; }
            for (int i=0;i<names.Length;++i)
            {
                string name=names[i]; if (s==0 && (name=="CurrentOnly" || (name=="Target" && options.ContainsKey("missing_target") && Convert.ToBoolean(options["missing_target"])))) name="Base";
                ScriptState state=new ScriptState {Name=name}; scripts[s].States.Add(state);stateIds[state]=s*64+i;
            }
        }
        StateControlContext context = new StateControlContext { Machine=new ScriptMachine(new ScriptEnvironment()) };
        int[] defaultGroups = new int[] {0,1,2,3,16,2,1,255};
        for(int i=0;i<8;++i)
        {
            ScriptPacket packet=new ScriptPacket { BaseScript=scripts[0],Script=scripts[1],State=scripts[1].States[2],PendingState=scripts[1].States[1],Timer=3.5f,Flags=0x24,BlockedMessages=0x7654,Deadline=8,DeadlineMarker=7,DeadlineState=scripts[1].States[1] };
            for(int j=0;j<4;++j)packet.Parameters[j]=9-j;
            for(int j=0;j<3;++j)packet.Stack.Add(new ScriptReference());
            context.Actors.Add(new ScriptActor {Packet=packet,Flags=options.ContainsKey("flags")?UInt(Arr(options["flags"])[i]):0x1001,SetId=(byte)(options.ContainsKey("groups")?Int(Arr(options["groups"])[i]):defaultGroups[i])});
        }
        context.Self=options.ContainsKey("self_actor")&&!Convert.ToBoolean(options["self_actor"])?null:context.Actors[0];
        Dictionary<string,ScriptActor> bindings=new Dictionary<string,ScriptActor>(StringComparer.OrdinalIgnoreCase);bindings["self"]=context.Actors[0];bindings["other"]=context.Actors[1];
        string[] tokens=Tokens(shipped?input["args"]:input["tokens"]);
        if(shipped)
            foreach(string token in tokens) { int at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase);if(at>=0)bindings[token.Substring(at+10)]=context.Actors[1]; }
        if(shipped || (options.ContainsKey("named_adapter") && Convert.ToBoolean(options["named_adapter"])))
            context.ResolveCharacter=delegate(string name) {ScriptActor actor;return bindings.TryGetValue(name,out actor)?actor:null;};
        ScriptPacket caller=new ScriptPacket {Script=scripts[0]};float[] parameters=new float[]{2.75f,1,3,4};for(int i=0;i<4;++i)caller.Parameters[i]=parameters[i];
        Check("completion",StateControl.SetScriptState(context,caller,tokens,shipped||Convert.ToBoolean(input["first"])),true,input);
        object[] expected=Arr(input["native"]);
        for(int i=0;i<8;++i)
        {
            ScriptPacket p=context.Actors[i].Packet;Dictionary<string,object> v=Obj(expected[i]);
            Check("base",p.BaseScript==scripts[0]?0:256,Int(v["base"]),input);Check("script",p.Script==scripts[0]?0:256,Int(v["script"]),input);
            Check("state",Index(stateIds,p.State),Int(v["state"]),input);Check("pending",Index(stateIds,p.PendingState),v["pending"]==null?null:(object)Int(v["pending"]),input);
            for(int j=0;j<4;++j)Check("local-bits",Bits(p.Parameters[j]),UInt(Arr(v["localsBits"])[j]),input);
            Check("timer",Bits(p.Timer),UInt(v["timerBits"]),input);Check("flags",p.Flags,UInt(v["flags"]),input);Check("depth",p.Stack.Count,Int(v["depth"]),input);Check("blocked",(int)p.BlockedMessages,Int(v["blocked"]),input);
            Check("deadline",Bits(p.Deadline),UInt(v["deadlineBits"]),input);Check("deadline-state",Index(stateIds,p.DeadlineState),v["deadlineState"]==null?null:(object)Int(v["deadlineState"]),input);Check("marker",(int)p.DeadlineMarker,Int(v["marker"]),input);
        }
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;
        Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));string[] names=Tokens(data["states"]);
        foreach(object input in Arr(data["cases"]))Run(Obj(input),false,names);
        foreach(object input in Arr(data["shipped"]))Run(Obj(input),true,names);
        string output=json.Serialize(new {checks,mismatches=failures,errors,method="Compiled C# SetScriptState comparison against captured original-PC reference packets."});
        if(args.Length>1)File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
