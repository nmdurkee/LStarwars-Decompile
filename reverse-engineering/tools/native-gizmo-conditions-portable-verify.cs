using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GizmoConditionsVerify
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
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));object[] names=Arr(data["names"]);
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);List<object> events=new List<object>();Dictionary<SceneryGizmo,int[]> ids=new Dictionary<SceneryGizmo,int[]>();SceneryGizmo[,] records=new SceneryGizmo[5,4];SceneryRegistry registry=new SceneryRegistry{ NameBuckets=new SceneryNameBucket[5],Outputs=Bool(o["types"])?new Func<SceneryGizmo,uint,int,uint>[Math.Max(0,Int(o["typeCount"]))]:null};SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=Int(o["typeCount"]),NameAccessors=Bool(o["types"])?new Func<SceneryGizmo,string>[5]:null};
            for(int typ=0;typ<5;typ++)
            {
                SceneryNameBucket bucket=new SceneryNameBucket{Count=4};registry.NameBuckets[typ]=bucket;object[] nn=Arr(names[typ]);
                for(int i=0;i<4;i++){SceneryGizmo r=new SceneryGizmo{Type=(byte)typ,Target=nn[i]==null?null:new SceneryObject{Name=(string)nn[i],StatusFlags=3,Proximity=U(o["proximity"]),Animation=new ScenePlaybackGroup{State=Int(o["state"])}}};records[typ,i]=r;bucket.Records.Add(r);ids.Add(r,new int[]{typ,i});}
                if(bindings.NameAccessors!=null&&Bool(Arr(o["accessors"])[typ]))bindings.NameAccessors[typ]=delegate(SceneryGizmo r){events.Add(new object[]{"name",ids[r]});return SceneryNameBindings.ObjectName(r);};
                if(registry.Outputs!=null&&typ<registry.Outputs.Length&&Bool(Arr(o["outputs"])[typ]))registry.Outputs[typ]=delegate(SceneryGizmo r,uint channel,int include){events.Add(new object[]{"output",ids[r],channel,include});return (string)o["mode"]=="obstacle"?ObstacleCommands.ObstacleOutput(r,channel,include):U(o["value"]);};
            }
            SceneryWorld world=new SceneryWorld{Registry=Bool(o["registry"])?registry:null,Bindings=bindings};
            try
            {
                string kind=(string)v["kind"];object result;
                if(kind=="bindAny"||kind=="bindBlowup"){SceneryGizmo found=kind=="bindAny"?GizmoConditions.BindAny(world,(string)v["name"]):GizmoConditions.BindBlowup(world,Int(o["blowupType"]),(string)v["name"]);result=found==null?null:ids[found];}
                else
                {
                    object[] id=o["bound"]==null?null:Arr(o["bound"]);SceneryGizmo bound=id==null?null:records[Int(id[0]),Int(id[1])];
                    if(kind=="GizmoOutput0")result=Bits(GizmoConditions.Output0(world.Registry,bound));
                    else if(kind=="GizmoOutput1")result=Bits(GizmoConditions.Output1(world.Registry,bound));
                    else if(kind=="GizmoOutput2")result=Bits(GizmoConditions.Output2(world.Registry,bound));
                    else result=Bits(GizmoConditions.BlowupBlownup(world.Registry,bound));
                }
                object got=new Dictionary<string,object>{{"result",result},{"events",events}};
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
