using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class CategoryCommandsVerify
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
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);ActorStateRecord actor=new ActorStateRecord(),reference=new ActorStateRecord{WorldObject=Bool(o["actor"])?actor:null};ActorForceContext context=new ActorForceContext{CreaturePresent=Bool(o["creature"]),Reference=Bool(o["reference"])?reference:null};
            ForceActorState state=new ForceActorState{DefinitionPresent=Bool(o["definition"]),ClassPresent=Bool(o["classPresent"]),DefinitionFlags4=U(o["definitionFlags"]),ClassFlags90=U(o["class90"]),ClassFlags94=U(o["class94"])};ForceActionWorld capabilities=new ForceActionWorld{CapabilityCount=Int(o["capabilityCount"])};capabilities.Actors.Add(actor,state);foreach(object c in Arr(o["capabilities"])){object[] a=Arr(c);capabilities.Capabilities.Add(new ForceCapability{DefinitionMask=U(a[0]),ClassMask=U(a[1])});}
            CategoryWorld world=new CategoryWorld{Capabilities=capabilities,TablePresent=Bool(o["table"]),Names=Strings(o["categoryNames"]),Opponents=new OpponentWorld()};OpponentFields fields=new OpponentFields{FlagsEf4=U(o["flagsEf4"])};world.Opponents.Fields.Add(actor,fields);
            try
            {
                string kind=(string)v["kind"];object result;
                if(kind=="Find")result=CategoryCommands.Find(world,(string)o["name"]);
                else if(kind=="Bind")result=CategoryCommands.Bind(world,Bool(o["system"]),(string)o["name"]);
                else if(kind=="CategoryIs")result=Bits(CategoryCommands.CategoryIs(world,context,Int(o["bound"])));
                else result=CategoryCommands.UseTimeBasedUpdate(world,context,Strings(o["tokens"]),Bool(o["first"]));
                object got=new Dictionary<string,object>{{"result",result},{"flags",fields.FlagsEf4}};++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
