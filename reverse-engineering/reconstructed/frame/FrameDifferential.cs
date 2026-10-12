using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Frame;
public static class FrameDifferential
{
    static Dictionary<string, object> Map(object v) { return (Dictionary<string,object>)v; }
    static int I(Dictionary<string, object> m,string k) { return Convert.ToInt32(m[k]); }
    static uint U(Dictionary<string, object> m,string k) { return Convert.ToUInt32(m[k]); }
    static object[] Run(string contract,Dictionary<string,object> m)
    {
        int callbacks=0;
        if(contract=="transition_state_select_and_begin")
        {
            TransitionState state=new TransitionState();state.Argument=0xdeadbeef;state.Progress=7.25f;state.Selected=I(m,"initial");
            for(int i=0;i<4;i++)if((I(m,"mask")&(1<<i))!=0)state.States[i]=delegate{callbacks++;};
            bool selected=state.Select(I(m,"index"),U(m,"argument"));state.Begin((sbyte)I(m,"phase"));
            return new object[]{selected?1:0,state.Selected,state.Argument,state.Phase,state.Progress,callbacks};
        }
        TransitionInputs s=new TransitionInputs();s.Request=I(m,"request")!=0;s.ActiveMode=I(m,"activeMode")!=0;s.Auxiliary=0x1234;
        s.UpdatingLevel=new LevelRecord{Flags=U(m,"levelFlags")};s.GlobalLevel=s.UpdatingLevel;
        s.SpecialLevel=new LevelRecord();s.AlternateLevel=new LevelRecord();s.AlternateDestination=new LevelRecord();
        LevelRecord[] destinations={null,s.UpdatingLevel,new LevelRecord(),s.SpecialLevel,s.AlternateLevel,s.AlternateDestination};
        s.Destination=destinations[I(m,"destinationKind")];
        if(s.Destination!=null){s.Destination.AreaIndex=(sbyte)I(m,"areaId");s.Destination.AreaFlags=(byte)I(m,"areaFlags");}
        s.CurrentAreaIndex=I(m,"sameArea")!=0?I(m,"areaId"):9;s.CurrentAreaFlags=(byte)I(m,"areaFlags");
        if(I(m,"slotEnabled")!=0){s.State.States[1]=delegate{callbacks++;};s.State.States[2]=delegate{callbacks++;};}
        FrameTransitions.Advance(s);
        // Native array[0] records the selection call; compare all observable state
        // fields here. The separate output clear belongs to the dispatcher body.
        return new object[]{s.Delay,s.Auxiliary,s.State.Selected,s.State.Phase,callbacks};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("Frame fixture path and output report path required.");
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=Int32.MaxValue;
        var data=Map(json.DeserializeObject(File.ReadAllText(args[0])));int cases=0,failed=0,scalars=0;var examples=new List<object>();
        foreach(object v in (object[])data["vectors"])
        {
            var row=Map(v);string contract=(string)row["contract"];var input=Map(row["input"]);cases++;
            try
            {
                object[] expected=(object[])row["native"],actual=Run(contract,input);
                int offset=contract=="transition_state_select_and_begin"?0:1;
                bool match=true;
                for(int i=0;i<actual.Length;i++){scalars++;if(Convert.ToDecimal(actual[i])!=Convert.ToDecimal(expected[i+offset]))match=false;}
                if(!match){failed++;if(examples.Count<20)examples.Add(new{contract=contract,input=input,actual=actual,native=expected});}
            }
            catch(Exception e){failed++;if(examples.Count<20)examples.Add(new{contract=contract,error=e.Message,input=input});}
        }
        File.WriteAllText(args[1],json.Serialize(new{cases=cases,scalars=scalars,failures=failed,examples=examples}));
        Console.WriteLine("Frame compiled differential: "+cases+" cases, "+failed+" failures");return failed==0?0:1;
    }
}
