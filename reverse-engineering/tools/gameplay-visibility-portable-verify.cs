using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GameplayVisibilityVerify
{
    static int checks,failures;
    static List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object x){return (Dictionary<string,object>)x;}
    static object[] Arr(object x){return (object[])x;}
    static string[] Tokens(object x){object[] a=Arr(x);string[] r=new string[a.Length];for(int i=0;i<a.Length;++i)r[i]=(string)a[i];return r;}
    static void Check(string kind,object got,object want,object input){++checks;if(!Object.Equals(got,want)){++failures;if(errors.Count<20)errors.Add(new{kind,got,want,input});}}
    static void Run(Dictionary<string,object> input,bool shipped)
    {
        string kind=(string)input["kind"];string[] tokens=Tokens(input["tokens"]);
        bool dynamic=!shipped&&input.ContainsKey("dynamic")&&Convert.ToBoolean(input["dynamic"]),aux=shipped||!input.ContainsKey("aux")||Convert.ToBoolean(input["aux"]),first=shipped||Convert.ToBoolean(input["first"]);
        string name=shipped?(string)input["fixtureName"]:"first";
        string other=shipped?"__other__":"second";
        object[] expected=Arr(input["native"]);
        if(kind.StartsWith("scene"))
        {
            SceneVisibilityRegistry scene=new SceneVisibilityRegistry();
            foreach(string n in new string[]{name,other,name})scene.Items.Add(new SceneVisibilityItem{Name=n,Dynamic=dynamic,HasSecondary=!dynamic||aux,Flags=dynamic?0x80000202u:0x80000200u,SecondaryFlags=dynamic?0xa5u:0x11u});
            if(kind=="scene-git")VisibilityCommands.Scene(scene,tokens);else Check("command-result",VisibilityCommands.SceneScript(scene,tokens,first),true,input);
            for(int i=0;i<3;++i){Dictionary<string,object> want=Obj(expected[i]);Check("scene-flags",scene.Items[i].Flags,Convert.ToUInt32(want["flags"]),input);Check("secondary-flags",scene.Items[i].SecondaryFlags,Convert.ToUInt32(want["secondary"]),input);}
        }
        else
        {
            NamedGizmoRegistry registry=new NamedGizmoRegistry();bool[] active={true,true,true,true},visible={true,true,true,true};int[] playing={1,1,1,1};
            string firstType=shipped?(string)input["fixtureType"]:"NuSpecial";
            for(int t=0;t<2;++t)
            {
                NamedGizmoType type=new NamedGizmoType{Name=t==0?firstType:"Other"};registry.Types.Add(type);
                for(int j=0;j<2;++j)
                {
                    int index=t*2+j;GizmoCallbacks callbacks=new GizmoCallbacks();
                    callbacks.Activate=delegate(bool value){active[index]=value;if(!value)playing[index]=0;};callbacks.Visibility=delegate(bool value){visible[index]=value;};
                    type.Items.Add(new NamedGizmo{Name=j==0?name:other,Callbacks=callbacks});
                }
            }
            if(kind=="gizmo-git")VisibilityCommands.Gizmo(registry,tokens);else Check("command-result",VisibilityCommands.GizmoScript(registry,tokens,first),true,input);
            for(int i=0;i<4;++i){Dictionary<string,object> want=Obj(expected[i]);Check("visible",visible[i],Convert.ToBoolean(want["visible"]),input);Check("active",active[i],Convert.ToBoolean(want["active"]),input);Check("playing",playing[i],Convert.ToInt32(want["playing"]),input);}
        }
    }
    public static int Main(string[] args)
    {
        checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=64*1024*1024;
        Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object input in Arr(data["cases"]))Run(Obj(input),false);
        foreach(object input in Arr(data["shipped"]))Run(Obj(input),true);
        string output=json.Serialize(new{checks,mismatches=failures,errors,method="Compiled C# visibility command comparison against original-PC fixtures; physical callback effects represented by explicit harness delegates."});
        if(args.Length>1)File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
