using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class GraphBuildFailureVerify
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
    sealed class Services:GraphActorServices
    {
        public Dictionary<string,object> Options;
        public GraphActorGlobals Globals;
        public ActorStateWorld[] Worlds;
        public ActorStateRecord[] Actors;
        public Dictionary<SceneryObject,int[]> ObjectIds;
        public Dictionary<GraphActorPlacement,int[]> PlacementIds;
        public List<object> Events;
        public int Releases;
        public object ChangedSpawn,ChangedPlacement;
        public override ActorStateRecord Activate(string name,GraphActorPlacement placement,ushort heading)
        {
            Events.Add(new object[]{"activate",name,placement==null?null:PlacementIds[placement],placement==null?null:(uint[])placement.PositionWords.Clone(),(int)heading});
            if(placement!=null&&Bool(Options["placementMutation"])){placement.PositionWords[0]=0x40a00000;ChangedPlacement=PlacementIds[placement];}
            return Bool(Options["success"])?Actors[2]:null;
        }
        public override void Deactivate(string name){Events.Add(new object[]{"deactivate",name});}
        public override void BuildFailureEffects(SceneryObject buildIt){Events.Add(new object[]{"effects",ObjectIds[buildIt]});}
        public override void Release(ActorStateRecord actor)
        {
            Events.Add(new object[]{"release",actor.Id,0});if(++Releases!=1)return;
            ActorStateRecord[] players=Globals.Tags.Actors.Players;string kind=(string)Options["releaseMutation"];
            if(kind=="swap"){ActorStateRecord tmp=players[0];players[0]=players[1];players[1]=tmp;}
            else if(kind=="clear-primary")players[0]=null;
            else if(kind=="replace-primary")players[0]=Actors[2];
            else if(kind=="change-world")Globals.Current=Worlds[1-Int(Options["world"])];
            else if(kind=="change-spawn"){int index=Actors[Int(Options["primary"])].SpawnIndex;Worlds[Int(Options["world"])].Spawns[index].Name="gamma";ChangedSpawn=index;}
            else if(kind=="secondary-inactive"&&Int(Options["secondary"])>=0)Actors[Int(Options["secondary"])].Flags1fc=0;
        }
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;string text;using(FileStream f=File.OpenRead(args[0]))using(GZipStream gz=new GZipStream(f,CompressionMode.Decompress))using(StreamReader sr=new StreamReader(gz)){text=sr.ReadToEnd();}Dictionary<string,object> data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["graphOptions"]);object[] names=Arr(v["names"]);List<object> events=new List<object>();Dictionary<SceneryGizmo,int[]> ids=new Dictionary<SceneryGizmo,int[]>();SceneryRegistry registry=new SceneryRegistry{NameBuckets=new SceneryNameBucket[5]};SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=Int(o["typeCount"]),NameAccessors=Bool(o["types"])?new Func<SceneryGizmo,string>[5]:null};
            ActorStateWorld players=new ActorStateWorld();ActorStateWorld[] worlds={new ActorStateWorld(),new ActorStateWorld()};ActorStateRecord[] actors=new ActorStateRecord[3];TagControlWorld tags=new TagControlWorld{Actors=players};
            for(int w=0;w<2;w++)for(int i=0;i<256;i++)worlds[w].Spawns.Add(new ActorStateSpawn{Name=(w==0?new string[]{"alpha","beta","alpha"}:new string[]{"beta","alpha","beta"})[i%3]});
            for(int i=0;i<3;i++){Dictionary<string,object> a=Obj(Arr(o["actors"])[i]);actors[i]=new ActorStateRecord{Id=i,Flags1fc=U(a["flags"]),SpawnIndex=(byte)Int(a["spawn"])};tags.State.Add(actors[i],new TagControlState{Blocked28b=(byte)Int(a["blocked"])});players.Actors.Add(actors[i]);}
            players.Players[0]=Int(o["primary"])<0?null:actors[Int(o["primary"])];players.Players[1]=Int(o["secondary"])<0?null:actors[Int(o["secondary"])];
            GraphActorGlobals globals=new GraphActorGlobals{Current=Int(o["world"])<0?null:worlds[Int(o["world"])],Tags=tags,BuildItType=Int(o["buildType"]),Scenery=new SceneryWorld{Registry=Bool(o["registry"])?registry:null,Bindings=bindings}};
            Services service=new Services{Options=o,Globals=globals,Worlds=worlds,Actors=actors,Events=events,ObjectIds=new Dictionary<SceneryObject,int[]>(),PlacementIds=new Dictionary<GraphActorPlacement,int[]>()};BuildFailureEffectsVerify.Fixture ef=new BuildFailureEffectsVerify.Fixture(Obj(v["effectOptions"]));GraphBuildFailureBridge bridge=new GraphBuildFailureBridge{Lifecycle=service,Effects=ef.World};globals.Services=bridge;
            for(int typ=0;typ<5;typ++)
            {
                SceneryNameBucket bucket=new SceneryNameBucket{Count=4};registry.NameBuckets[typ]=bucket;object[] nn=Arr(names[typ]);
                for(int i=0;i<4;i++)
                {
                    int[] id={typ,i};SceneryGizmo r=new SceneryGizmo{Type=(byte)typ,Target=nn[i]==null?null:new SceneryObject{Name=(string)nn[i]}};bucket.Records.Add(r);ids.Add(r,id);
                    if(r.Target!=null){GraphActorPlacement p=new GraphActorPlacement{PositionWords=new uint[]{0x3f800000+(uint)(typ*0x10000+i),0x80000000,0xc0400000+(uint)i},Heading=(ushort)((typ*17001+i*11003)&65535)};globals.Placements.Add(r.Target,p);service.PlacementIds.Add(p,id);service.ObjectIds.Add(r.Target,id);bridge.Objects.Add(r.Target,ef.Object);}
                }
                if(bindings.NameAccessors!=null&&Bool(Arr(o["accessors"])[typ]))bindings.NameAccessors[typ]=delegate(SceneryGizmo r){events.Add(new object[]{"name",ids[r]});return SceneryNameBindings.ObjectName(r);};
            }
            try
            {
                string[] tokens=Strings(o["tokens"]);if(o["count"]!=null){string[] selected=new string[Math.Max(0,Int(o["count"]))];Array.Copy(tokens,selected,selected.Length);tokens=selected;}
                GraphActorActivation.Execute(globals,tokens);Dictionary<string,object> got=new Dictionary<string,object>();got.Add("events",events);got.Add("players",new int[]{Id(players.Players[0]),Id(players.Players[1])});got.Add("world",globals.Current==null?-1:Object.ReferenceEquals(globals.Current,worlds[0])?0:1);got.Add("flags",new uint[]{actors[0].Flags1fc,actors[1].Flags1fc,actors[2].Flags1fc});got.Add("changedSpawn",service.ChangedSpawn);got.Add("changedPlacement",service.ChangedPlacement);
                object combined=json.DeserializeObject(json.Serialize(new{graph=got,effects=new{events=ef.Events,state=ef.Capture(),result=(object)null}}));++checks;if(!Equal(combined,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got=combined,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
