using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class ForceConditionsVerify
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
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));object[] names=Arr(data["names"]);
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);List<object> events=new List<object>();Dictionary<SceneryGizmo,int[]> recordIds=new Dictionary<SceneryGizmo,int[]>();Dictionary<SceneryObject,int[]> objectIds=new Dictionary<SceneryObject,int[]>();SceneryObject[,] objects=new SceneryObject[5,4];SceneryRegistry registry=new SceneryRegistry{NameBuckets=new SceneryNameBucket[5]};SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=Int(o["typeCount"]),NameAccessors=Bool(o["types"])?new Func<SceneryGizmo,string>[5]:null};
            ForceConditionWorld world=new ForceConditionWorld{Scenery=new SceneryWorld{Registry=Bool(o["registry"])?registry:null,Bindings=bindings},ForceType=Int(o["forceType"]),Terrain=new TerrainObjectWorld{TerrainPresent=Bool(o["terrain"])}};
            for(int typ=0;typ<5;typ++)
            {
                SceneryNameBucket bucket=new SceneryNameBucket{Count=4};registry.NameBuckets[typ]=bucket;object[] nn=Arr(names[typ]);
                for(int i=0;i<4;i++)
                {
                    SceneryObject item=new SceneryObject{Name=(string)nn[i]};objects[typ,i]=item;objectIds.Add(item,new int[]{typ,i});SceneryGizmo r=new SceneryGizmo{Type=(byte)typ,Target=nn[i]==null?null:item};bucket.Records.Add(r);recordIds.Add(r,new int[]{typ,i});
                    if(Bool(o["memberGroup"])) {ForcePlatformState platform=new ForcePlatformState{FlagsA0=U(o["platformFlags"])};foreach(object member in Arr(o["members"]))platform.GroundObjectIndices.Add((short)Int(member));world.Platforms.Add(item,platform);}
                }
                if(bindings.NameAccessors!=null&&Bool(Arr(o["accessors"])[typ]))bindings.NameAccessors[typ]=delegate(SceneryGizmo r){events.Add(new object[]{"name",recordIds[r]});return SceneryNameBindings.ObjectName(r);};
            }
            ActorStateRecord player=new ActorStateRecord{Y=Convert.ToSingle(o["height"])};world.Terrain.Actors=new ActorStatusWorld{Tags=new TagControlWorld{Actors=new ActorStateWorld{PrimaryPlayer=Bool(o["player"])?player:null}}};world.Terrain.Actors.State.Add(player,new ActorStatusState{State7b5=(byte)Int(o["state"]),Ground281=(byte)Int(Arr(o["groundFlags"])[0]),Ground282=(byte)Int(Arr(o["groundFlags"])[1])});world.Terrain.GroundObjects.Add(player,(short)Int(o["ground"]));world.ForceTargets.Add(player,Target(o["forceTarget"],objects));
            object[] heights=Arr(o["terrainHeights"]);for(int i=0;i<heights.Length;i++)world.Terrain.Terrain.Add(new TerrainObjectRecord{Height=Convert.ToSingle(heights[i]),HasTransform=Bool(Arr(o["transforms"])[i])});
            try
            {
                string kind=(string)v["kind"];object result;SceneryObject bound=Target(o["bound"],objects);
                if(kind=="BindUsingForce"||kind=="BindForcePlatform"){SceneryObject found=kind=="BindUsingForce"?ForceConditions.BindUsingForce(world,(string)v["name"]):ForceConditions.BindForcePlatform(world,(string)v["name"]);result=found==null?null:objectIds[found];}
                else if(kind=="IsUsingForce")result=ForceConditions.IsUsingForce(world,Bool(o["player"])?player:null,bound);
                else if(kind=="PlayerUsingForce")result=Bits(ForceConditions.PlayerUsingForce(world,bound));
                else result=Bits(ForceConditions.PlayerOnForcePlatform(world,bound));
                object got=new Dictionary<string,object>{{"result",result},{"events",events}};
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
