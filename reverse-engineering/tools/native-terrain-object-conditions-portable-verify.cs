using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class TerrainObjectConditionsVerify
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
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);CameraScene scene=new CameraScene{Dynamic=Bool(o["dynamic"])};TerrainObjectWorld world=new TerrainObjectWorld{TerrainPresent=Bool(o["terrain"]),Scene=Bool(o["scene"])?scene:null,StaticInstanceCount=Int(o["instanceCount"]),TerrainCount=Int(o["terrainCount"])};CameraSceneObject[] items=new CameraSceneObject[4];
            for(int i=0;i<4;i++)world.StaticInstances.Add(new object());
            for(int i=0;i<4;i++){items[i]=new CameraSceneObject{Name=(string)names[i]};if(i<Int(o["sceneCount"]))scene.Objects.Add(items[i]);int id=Int(Arr(o["instanceIds"])[i]);world.Bindings.Add(items[i],new SceneObjectIndexBinding{StaticInstance=id<0?null:world.StaticInstances[id],DynamicIndex=Int(Arr(o["dynamicIds"])[i])});}
            for(int i=0;i<8;i++)world.Terrain.Add(new TerrainObjectRecord{HasTransform=Bool(Arr(o["transforms"])[i]),SceneIndex=(short)Int(Arr(o["sceneIds"])[i]),Height=Convert.ToSingle(Arr(o["heights"])[i])});
            ActorStateRecord player=new ActorStateRecord{Y=Convert.ToSingle(o["y"])};ActorStateWorld actors=new ActorStateWorld{PrimaryPlayer=Bool(o["primary"])?player:null};world.Actors=new ActorStatusWorld{Tags=new TagControlWorld{Actors=actors}};world.Actors.State.Add(player,new ActorStatusState{Ground281=(byte)Int(o["ground281"]),Ground282=(byte)Int(o["ground282"])});world.GroundObjects.Add(player,(short)Int(o["groundIndex"]));
            try
            {
                string kind=(string)v["kind"];object got;
                if(kind=="index"){string mode=(string)o["referenceKind"];int which=Int(o["referenceIndex"]);got=TerrainObjectConditions.SceneIndex(world,new CameraSceneReference{Scene=scene,Static=mode=="static"?items[which]:null,Dynamic=mode=="dynamic"?items[which]:null});}
                else if(kind=="terrain")got=TerrainObjectConditions.FindTerrainObject(world,Int(o["index"]));
                else if(kind=="bind")got=TerrainObjectConditions.Bind(world,(string)o["name"]);
                else got=Bits(TerrainObjectConditions.PlayerOnObject(world,Int(o["bound"])));
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
