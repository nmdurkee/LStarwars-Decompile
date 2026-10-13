using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SpatialConditionsVerify
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
    static float[] Floats(object v){if(v==null)return null;object[] a=Arr(v);float[] f=new float[a.Length];for(int i=0;i<a.Length;i++)f[i]=Convert.ToSingle(a[i]);return f;}
    static SpawnVector Vector(object value){float[] f=Floats(value);return new SpawnVector(f[0],f[1],f[2]);}
    static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        LocatorWorld world=new LocatorWorld();object[] names=Arr(data["names"]),points=Arr(data["points"]);for(int i=0;i<names.Length;i++)world.Locators.Add(new LocatorRecord{Name=(string)names[i],Position=Vector(points[i])});
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);
            try
            {
                object got;string kind=(string)v["kind"];
                bool system=!o.ContainsKey("system")||Bool(o["system"]);
                if(kind=="bind"){LocatorRecord found=SpatialConditions.BindCurrent(system?world:null,(string)o["name"]);got=found==null?-1:world.Locators.IndexOf(found);}
                else if(kind=="distanceXZ")got=Bits(SpatialConditions.DistanceXZ(Vector(o["a"]),Vector(o["b"])));
                else
                {
                    int selected=o.ContainsKey("selected")?Int(o["selected"]):0,bound=o.ContainsKey("bound")?Int(o["bound"]):-1;
                    LocatorPacket packet=new LocatorPacket{Selected=selected<0?null:world.Locators[selected]};
                    LocatorRecord target=bound<0?null:world.Locators[bound];
                    LocatorCreature creature=new LocatorCreature{Reference=o.ContainsKey("reference")&&!Bool(o["reference"])?null:new LocatorActor{Position=o.ContainsKey("actor")?Vector(o["actor"]):new SpawnVector(9,8,7)},Position=o.ContainsKey("position")?Vector(o["position"]):new SpawnVector(0,0,0),NodeFlags=o.ContainsKey("nodeFlags")?(byte)Int(o["nodeFlags"]):(byte)0};
                    if(o.ContainsKey("creature")&&!Bool(o["creature"]))creature=null;
                    world.Players[0]=o.ContainsKey("player0")&&!Bool(o["player0"])?null:new LocatorActor{Position=o.ContainsKey("p0")?Vector(o["p0"]):new SpawnVector(1,2,3)};
                    world.Players[1]=o.ContainsKey("player1")&&!Bool(o["player1"])?null:new LocatorActor{Position=o.ContainsKey("p1")?Vector(o["p1"]):new SpawnVector(-2,4,1)};
                    if(kind=="current")got=Bits(SpatialConditions.CurrentLocatorIs(packet,target));
                    else if(kind=="onpath")got=Bits(SpatialConditions.OnPath(creature));
                    else if(kind=="rangeXZ")got=Bits(SpatialConditions.LocatorRangeXZ(packet,creature,target));
                    else if(kind=="player")got=Bits(SpatialConditions.PlayerRange(system?world:null,creature));
                    else if(kind=="nearest")got=Bits(SpatialConditions.NearestPlayerRange(system?world:null,creature));
                    else throw new ArgumentException("kind");
                }
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
