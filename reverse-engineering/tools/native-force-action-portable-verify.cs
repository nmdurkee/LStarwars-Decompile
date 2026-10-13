using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;

public class ForceActionVerify
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
    static string ReadFixture(string file){using(FileStream f=File.OpenRead(file))using(GZipStream gz=new GZipStream(f,CompressionMode.Decompress))using(StreamReader r=new StreamReader(gz))return r.ReadToEnd();}
    static string[] Strings(object value){object[] a=Arr(value);string[] s=new string[a.Length];for(int i=0;i<s.Length;i++)s[i]=(string)a[i];return s;}
    static object ObjectId(SceneryObject value,Dictionary<SceneryObject,int[]> ids){return value==null?null:ids[value];}
    static object State(ForceActionWorld world,ForceActionContext context,ForceActionPacket packet,ActorStateRecord actor,ForceActorState own,Dictionary<SceneryObject,int[]> ids,SceneryObject[,] objects)
    {
        List<uint> flags=new List<uint>();for(int t=0;t<5;t++)for(int i=0;i<4;i++)flags.Add(world.Objects[objects[t,i]].Shared.FlagsA0);
        return new Dictionary<string,object>{{"selected",ObjectId(packet.Selected6c,ids)},{"throwable",packet.Throwable68},{"inrange",packet.InRange69},{"timer",Bits(packet.Timer9c)},{"seed",world.Random.State},{"goal",ObjectId(context.Goal1e4,ids)},{"forceTarget",ObjectId(world.Conditions.ForceTargets[actor],ids)},{"input8",own.Input8},{"input5a",own.Input5a},{"objectFlags",flags}};
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(ReadFixture(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);object[] names=Arr(o["names"]);List<object> events=new List<object>();Dictionary<SceneryGizmo,int[]> recordIds=new Dictionary<SceneryGizmo,int[]>();Dictionary<SceneryObject,int[]> ids=new Dictionary<SceneryObject,int[]>();SceneryObject[,] objects=new SceneryObject[5,4];SceneryRegistry registry=new SceneryRegistry{NameBuckets=new SceneryNameBucket[5]};SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=Int(o["typeCount"]),NameAccessors=Bool(o["types"])?new Func<SceneryGizmo,string>[5]:null};
            ForceActionWorld world=new ForceActionWorld{Conditions=new ForceConditionWorld{Scenery=new SceneryWorld{Registry=Bool(o["registry"])?registry:null,Bindings=bindings},ForceType=Int(o["forceType"])},Random=new QRandom{State=U(o["seed"])},RetryEnabled=Bool(o["retry"]),RetryInputMask=U(o["retryMask"]),CapabilityCount=Int(o["capabilityCount"])};
            for(int typ=0;typ<5;typ++)
            {
                SceneryNameBucket bucket=new SceneryNameBucket{Count=4};registry.NameBuckets[typ]=bucket;object[] nn=Arr(names[typ]);
                for(int i=0;i<4;i++)
                {
                    int j=typ*4+i;SceneryObject item=new SceneryObject{Name=(string)nn[i]};objects[typ,i]=item;ids.Add(item,new int[]{typ,i});SceneryGizmo r=new SceneryGizmo{Type=(byte)typ,Target=nn[i]==null?null:item};bucket.Records.Add(r);recordIds.Add(r,new int[]{typ,i});
                    ForcePlatformState shared=new ForcePlatformState{FlagsA0=U(Arr(o["objectFlags"])[j])};world.Conditions.Platforms.Add(item,shared);world.Objects.Add(item,new ForceObjectState{Shared=shared,Flags74=U(Arr(o["flags74"])[j]),Timer4c=Convert.ToSingle(Arr(o["timers4c"])[j]),GroupPresent=Bool(Arr(o["groupPresent"])[j]),GroupState=Int(Arr(o["groupState"])[j])});
                }
                if(bindings.NameAccessors!=null&&Bool(Arr(o["accessors"])[typ]))bindings.NameAccessors[typ]=delegate(SceneryGizmo r){events.Add(new object[]{"name",recordIds[r]});return SceneryNameBindings.ObjectName(r);};
            }
            ActorStateRecord actor=new ActorStateRecord(),reference=new ActorStateRecord{WorldObject=Bool(o["actor"])?actor:null};ForceActionContext context=new ForceActionContext{CreaturePresent=Bool(o["creature"]),Reference=Bool(o["reference"])?reference:null,AttachmentD4=Bool(o["attachment"]),Goal1e4=Target(o["goal"],objects)};
            ForceActorState own=new ForceActorState{DefinitionPresent=Bool(o["definition"]),ClassPresent=Bool(o["classPresent"]),InputPresent=Bool(o["inputPresent"]),DefinitionFlags4=U(o["definitionFlags"]),ClassFlags90=U(o["class90"]),ClassFlags94=U(o["class94"]),Input8=U(o["input8"]),Input5a=(ushort)Int(o["input5a"])};world.Actors.Add(actor,own);world.Conditions.ForceTargets.Add(actor,Target(o["forceTarget"],objects));foreach(object c in Arr(o["capabilities"])){object[] a=Arr(c);world.Capabilities.Add(new ForceCapability{DefinitionMask=U(a[0]),ClassMask=U(a[1])});}
            ForceActionPacket packet=new ForceActionPacket{Throwable68=(byte)Int(o["throwable"]),InRange69=(byte)Int(o["inrange"]),Selected6c=Target(o["selected"],objects),Timer9c=PcObjectImage.FromBits(U(o["timerBits"]))};
            object[] steps=v["sequence"]==null?new object[]{new Dictionary<string,object>()}:Arr(v["sequence"]);int tick=0;
            foreach(object step in steps)
            {
                foreach(KeyValuePair<string,object> pair in Obj(step))o[pair.Key]=pair.Value;events.Clear();
                try
                {
                    string kind=(string)v["kind"];SceneryObject bound=Target(o["bound"],objects);object result;
                    if(kind=="UseForce")result=ForceActions.UseForce(world,context,packet,Strings(o["tokens"]),Bool(o["first"]),PcObjectImage.FromBits(U(o["deltaBits"])));
                    else if(kind=="IsComplete")result=ForceActions.IsComplete(world.Objects[bound]);
                    else if(kind=="ForceComplete")result=Bits(ForceActions.Complete(world,bound));
                    else if(kind=="HasCapability")result=ForceActions.HasCapability(world,own,Int(o["capabilityIndex"]));
                    else result=ObjectId(ForceActions.BindComplete(world,(string)v["name"]),ids);
                    Dictionary<string,object> got=new Dictionary<string,object>{{"result",result},{"events",events}};if(kind=="UseForce")got.Add("state",State(world,context,packet,actor,own,ids,objects));
                    object want=v["sequence"]==null?v["native"]:Arr(v["native"])[tick];++checks;if(!Equal(got,want)){++failures;if(errors.Count<15)errors.Add(new{index,tick,got,want});}
                }
                catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,tick,error=e.ToString()});}++tick;
            }
            ++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
