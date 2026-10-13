using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class EffectActivationVerify
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
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);
            EffectDisabledNames saved=new EffectDisabledNames(Convert.FromBase64String((string)o["saved"]));
            EffectActivationWorld w=new EffectActivationWorld{Count=Int(o["count"]),CurrentGroup=(byte)Int(o["group"]),Disabled=Bool(o["savePresent"])?saved:null};
            foreach(object entry in Arr(o["entries"])) {if(entry==null)w.Entries.Add(null);else{Dictionary<string,object> e=Obj(entry);w.Entries.Add(new EffectActivationEntry{Name=(string)e["name"],Group=(byte)Int(e["group"]),Activation=(byte)Int(e["activation"])});}}
            object[] loaded=Arr(o["loaded"]);for(int i=0;i<8;i++)w.LoadedGroups[i]=Bool(loaded[i]);
            try
            {
                object result=null;string kind=(string)v["kind"],name=v.ContainsKey("name")?(string)v["name"]:null;bool enabled=v.ContainsKey("enabled")&&Bool(v["enabled"]);
                if(kind=="command"){object[] raw=Arr(v["tokens"]);string[] tokens=new string[raw.Length];for(int i=0;i<raw.Length;i++)tokens[i]=(string)raw[i];EffectActivation.Activate(w,tokens);}
                else if(kind=="find")result=EffectActivation.Find(w,name,w.CurrentGroup);
                else if(kind=="set")EffectActivation.Set(w,name,enabled);
                else if(kind=="enable")EffectActivation.Enable(w,Int(v["index"]));
                else if(kind=="disable")EffectActivation.Disable(w,Int(v["index"]));
                else if(kind=="save")result=EffectActivation.SaveDisabled(w.Disabled,name,enabled);
                else throw new ArgumentException("kind");
                List<object> activation=new List<object>();foreach(EffectActivationEntry e in w.Entries)activation.Add(e==null?null:(object)e.Activation);
                object got=new Dictionary<string,object>{{"result",result},{"activation",activation},{"saved",Convert.ToBase64String(saved.Bytes)}};
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
