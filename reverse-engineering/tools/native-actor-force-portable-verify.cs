using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class ActorForceVerify
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
    static SceneryObject Target(object v,SceneryObject[,] objects){if(v==null)return null;object[] pair=Arr(v);return objects[Int(pair[0]),Int(pair[1])];}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);List<object> calls=new List<object>();SceneryObject[,] objects=new SceneryObject[5,4];Dictionary<SceneryObject,int[]> ids=new Dictionary<SceneryObject,int[]>();for(int t=0;t<5;t++)for(int i=0;i<4;i++){objects[t,i]=new SceneryObject();ids.Add(objects[t,i],new int[]{t,i});}
            ActorStateRecord actor=new ActorStateRecord{Id=0,Y=Convert.ToSingle(o["height"])},primary=new ActorStateRecord{Id=1,Y=999},second=new ActorStateRecord{Id=2};ActorStateRecord reference=new ActorStateRecord{WorldObject=Bool(o["actor"])?actor:null};ActorForceContext context=new ActorForceContext{CreaturePresent=Bool(o["creature"]),Reference=Bool(o["reference"])?reference:null};
            TerrainObjectWorld terrain=new TerrainObjectWorld{TerrainPresent=Bool(o["terrain"]),Actors=new ActorStatusWorld{Tags=new TagControlWorld{Actors=new ActorStateWorld{PrimaryPlayer=Bool(o["player"])?primary:null}}}};
            terrain.Actors.State.Add(actor,new ActorStatusState{State7b5=(byte)Int(o["state"]),Ground281=(byte)Int(Arr(o["groundFlags"])[0]),Ground282=(byte)Int(Arr(o["groundFlags"])[1])});terrain.GroundObjects.Add(actor,(short)Int(o["ground"]));terrain.Actors.State.Add(primary,new ActorStatusState{State7b5=(byte)Int(o["primaryState"])});terrain.Actors.State.Add(second,new ActorStatusState{State7b5=(byte)Int(o["secondState"])});
            object[] heights=Arr(o["terrainHeights"]);for(int i=0;i<heights.Length;i++)terrain.Terrain.Add(new TerrainObjectRecord{Height=Convert.ToSingle(heights[i]),HasTransform=Bool(Arr(o["transforms"])[i])});
            ForceConditionWorld world=new ForceConditionWorld{Terrain=terrain};world.ForceTargets.Add(actor,Target(o["forceTarget"],objects));world.ForceTargets.Add(primary,Target(o["primaryTarget"],objects));world.ForceTargets.Add(second,Target(o["secondTarget"],objects));world.ObserveUsingForce=delegate(ActorStateRecord who,SceneryObject target){calls.Add(new object[]{who==null?-1:who.Id,target==null?null:ids[target]});};
            for(int t=0;t<5;t++)for(int i=0;i<4;i++)if(Bool(o["memberGroup"])){ForcePlatformState p=new ForcePlatformState();foreach(object member in Arr(o["members"]))p.GroundObjectIndices.Add((short)Int(member));world.Platforms.Add(objects[t,i],p);}
            try
            {
                string kind=(string)v["kind"];SceneryObject bound=Target(o["bound"],objects);float result;
                if(kind=="UsingForce")result=ActorForceConditions.UsingForce(world,context,bound);
                else if(kind=="EitherPlayerUsingForce")result=ActorForceConditions.EitherPlayerUsingForce(world,Bool(o["second"])?second:null,bound);
                else if(kind=="OnForcePlatform")result=ActorForceConditions.OnForcePlatform(world,context,bound);
                else result=ActorForceConditions.OnObject(terrain,context,Int(o["objectBound"]));
                object got=new Dictionary<string,object>{{"result",Bits(result)},{"calls",calls}};++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
