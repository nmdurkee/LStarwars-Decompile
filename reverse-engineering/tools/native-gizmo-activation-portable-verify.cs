using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GizmoActivationVerify
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
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));object[] names=Arr(data["names"]);
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);List<object> events=new List<object>();Dictionary<SceneryGizmo,int[]> ids=new Dictionary<SceneryGizmo,int[]>();SceneryGizmo[,] records=new SceneryGizmo[5,4];SceneryRegistry registry=new SceneryRegistry{NameBuckets=new SceneryNameBucket[5]};SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=Int(o["typeCount"]),NameAccessors=Bool(o["types"])?new Func<SceneryGizmo,string>[5]:null};
            GizmoActivationWorld world=new GizmoActivationWorld{Scenery=new SceneryWorld{Registry=Bool(o["registry"])?registry:null,Bindings=bindings},Types=bindings,TypeNames=Strings(data["typeNames"]),Activate=new Action<SceneryGizmo,int>[5],Visibility=new Action<SceneryGizmo,int>[5]};
            for(int typ=0;typ<5;typ++)
            {
                SceneryNameBucket bucket=new SceneryNameBucket{Count=4};registry.NameBuckets[typ]=bucket;object[] nn=Arr(names[typ]);
                for(int i=0;i<4;i++){SceneryGizmo r=new SceneryGizmo{Type=(byte)typ,Target=nn[i]==null?null:new SceneryObject{Name=(string)nn[i]}};records[typ,i]=r;bucket.Records.Add(r);ids.Add(r,new int[]{typ,i});}
                if(bindings.NameAccessors!=null&&Bool(Arr(o["accessors"])[typ]))bindings.NameAccessors[typ]=delegate(SceneryGizmo r){events.Add(new object[]{"name",ids[r]});return SceneryNameBindings.ObjectName(r);};
                if(Bool(Arr(o["activation"])[typ]))world.Activate[typ]=delegate(SceneryGizmo r,int active){events.Add(new object[]{"active",ids[r],active,"original"});};
                if(Bool(Arr(o["visibility"])[typ]))world.Visibility[typ]=delegate(SceneryGizmo r,int visible){events.Add(new object[]{"visible",ids[r],visible});int type=r.Type;if(Bool(o["rewrite"]))world.Activate[type]=delegate(SceneryGizmo a,int active){events.Add(new object[]{"active",ids[a],active,"alternate"});};if(Int(o["retag"])>=0)r.Type=(byte)Int(o["retag"]);};
            }
            try
            {
                string kind=(string)v["kind"];Dictionary<string,object> got=new Dictionary<string,object>();
                if(kind=="FindType")got.Add("result",GizmoActivation.FindType(world,(string)v["name"]));
                else if(kind=="SetActive"){object[] id=o["bound"]==null?null:Arr(o["bound"]);GizmoActivation.SetActive(world,id==null?null:records[Int(id[0]),Int(id[1])],Int(o["active"]));}
                else GizmoActivation.Execute(world,Strings(o["tokens"]));
                got.Add("events",events);++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
