using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class BuildFailureEffectsVerify
{
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int Int(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static bool Has(Dictionary<string,object> o,string key){return o.ContainsKey(key)&&Bool(o[key]);}
    static ActorStateRecord Actor(ActorStateWorld w,int id){return id<0?null:w.Actors[id];}
    static int Id(ActorStateRecord a){return a==null?-1:a.Id;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;
        IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    static string[] Strings(object value){object[] a=Arr(value);string[] s=new string[a.Length];for(int i=0;i<s.Length;i++)s[i]=(string)a[i];return s;}
    static uint[] Words(object input){object[] a=Arr(input);uint[] values=new uint[a.Length];for(int i=0;i<a.Length;i++)values[i]=U(a[i]);return values;}
    public sealed class Fixture
    {
        public Dictionary<string,object> Options;
        public BuildFailureWorld World;
        public BuildFailureObject Object;
        public BuildFailureNode[] Nodes=new BuildFailureNode[3];
        public BuildFailureEffect[] Effects=new BuildFailureEffect[3];
        public List<object> Events=new List<object>();
        public int Calls;
        public Fixture(Dictionary<string,object> o)
        {
            Options=o;World=new BuildFailureWorld{Template=Words(o["template"]),DefaultOrigin=Words(o["origin"]),TimeWord=U(o["time"]),Random=new QRandom{State=U(o["seed"])}};
            for(int i=0;i<3;i++){Nodes[i]=new BuildFailureNode{Id=i,Matrix=Words(Arr(o["matrices"])[i])};Effects[i]=new BuildFailureEffect{LifetimeWord=U(Arr(o["lifetimes"])[i]),Flags20a=(byte)Int(Arr(o["flags"])[i])};}
            for(int i=0;i<3;i++)Nodes[i].Next=i+1<Int(o["count"])?Nodes[i+1]:null;
            Object=Bool(o["present"])?new BuildFailureObject{Group=Bool(o["group"])?new BuildFailureGroup{Head=Int(o["count"])==0?null:Nodes[0]}:null}:null;World.Allocate=Allocate;
        }
        BuildFailureEffect Allocate(BuildFailureRequest request)
        {
            Events.Add(new{node=request.Node.Id,words=(uint[])request.Words.Clone(),matrix=(uint[])request.Matrix.Clone(),origin=(uint[])request.Origin.Clone()});
            if(Calls==0)
            {
                string mode=(string)Options["mutation"];
                if(mode=="template"){World.Template[1]=0xfedcba98;World.TimeWord=0x3f400000;}
                else if(mode=="origin-global"){World.DefaultOrigin[0]=0x11111111;World.DefaultOrigin[1]=0x22222222;World.DefaultOrigin[2]=0x33333333;}
                else if(mode=="origin-local"){request.Origin[0]=0x44444444;request.Origin[1]=0x55555555;request.Origin[2]=0x66666666;}
                else if(mode=="skip")request.Node.Next=Int(Options["count"])>2?Nodes[2]:null;
                else if(mode=="stop")request.Node.Next=null;
                else if(mode=="matrix")Nodes[1].Matrix[0]=0xabcdef01;
                else if(mode=="random")World.Random.State=0x12345678;
            }
            object[] allocations=Arr(Options["allocations"]);int selected=Int(allocations[Calls%allocations.Length]);Calls++;return selected<0?null:Effects[selected];
        }
        public object Capture()
        {
            return new{seed=World.Random.State,time=World.TimeWord,origin=World.DefaultOrigin,template=World.Template,next=new int[]{Nodes[0].Next==null?-1:Nodes[0].Next.Id,Nodes[1].Next==null?-1:Nodes[1].Next.Id,Nodes[2].Next==null?-1:Nodes[2].Next.Id},matrices=new uint[][]{Nodes[0].Matrix,Nodes[1].Matrix,Nodes[2].Matrix},lifetimes=new uint[]{Effects[0].LifetimeWord,Effects[1].LifetimeWord,Effects[2].LifetimeWord},flags=new byte[]{Effects[0].Flags20a,Effects[1].Flags20a,Effects[2].Flags20a}};
        }
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;string text;using(FileStream f=File.OpenRead(args[0]))using(GZipStream gz=new GZipStream(f,CompressionMode.Decompress))using(StreamReader sr=new StreamReader(gz)){text=sr.ReadToEnd();}Dictionary<string,object> data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);Fixture f=new Fixture(o);
            try
            {
                string kind=(string)v["kind"];object result=null;
                if(kind=="create")BuildFailureEffects.Create(f.World,f.Object);
                else
                {
                    f.Effects[0].LifetimeWord=U(v["life"]);f.Effects[0].Flags20a=(byte)Int(v["flags"]);
                    if(kind=="reset")BuildFailureEffects.ResetLifetime(f.Effects[0]);else result=BuildFailureEffects.Visible(f.Effects[0],U(v["frame"]));
                }
                object got=json.DeserializeObject(json.Serialize(new{events=f.Events,state=f.Capture(),result}));++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        BuildFailureEffect effect=new BuildFailureEffect();BuildFailureWorld cycle=new BuildFailureWorld{Random=new QRandom{State=0},Template=new uint[50],DefaultOrigin=new uint[3],Allocate=delegate(BuildFailureRequest request){return effect;}};BuildFailureObject build=new BuildFailureObject{Group=new BuildFailureGroup{Head=new BuildFailureNode{Matrix=new uint[16]}}};uint seed=0;
        foreach(object expected in Arr(data["cycleLifetimes"]))
        {
            seed=unchecked(seed*0x24cd+1)&65535;BuildFailureEffects.Create(cycle,build);++checks;if(effect.LifetimeWord!=U(expected)||cycle.Random.State!=seed){++failures;if(errors.Count<15)errors.Add(new{cycleIndex=index,actual=effect.LifetimeWord,expected,seed});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
