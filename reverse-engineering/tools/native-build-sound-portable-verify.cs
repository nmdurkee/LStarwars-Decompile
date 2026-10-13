using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class BuildEffectSoundVerify
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
    static uint[] Words(object input){object[] a=Arr(input);uint[] values=new uint[a.Length];for(int i=0;i<a.Length;i++)values[i]=U(a[i]);return values;}
    static float Float(uint word){return BitConverter.ToSingle(BitConverter.GetBytes(word),0);}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;string text;using(FileStream f=File.OpenRead(args[0]))using(GZipStream gz=new GZipStream(f,CompressionMode.Decompress))using(StreamReader sr=new StreamReader(gz)){text=sr.ReadToEnd();}Dictionary<string,object> data=Obj(json.DeserializeObject(text));byte[] sineBytes=File.ReadAllBytes(args[1]);float[] sine=new float[sineBytes.Length/4];Buffer.BlockCopy(sineBytes,0,sine,0,sineBytes.Length);
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);List<object> events=new List<object>();EffectSoundRegistry registry=new EffectSoundRegistry{HashTable=Words(o["table"]),Heads=Bool(o["heads"])?new short[256]:null,Entries=new EffectSoundEntry[Arr(o["names"]).Length]};
            if(registry.Heads!=null)for(int i=0;i<registry.Heads.Length;i++)registry.Heads[i]=(short)Int(o["head"]);
            for(int i=0;i<registry.Entries.Length;i++)registry.Entries[i]=new EffectSoundEntry{Name=(string)Arr(o["names"])[i],Next=(short)Int(Arr(o["next"])[i])};
            BuildEffectSoundWorld world=new BuildEffectSoundWorld{CooldownWord=U(o["cooldown"]),Sounds=registry,Sine=sine};uint[] vw=Words(o["velocity"]);BuildEffectSoundState effect=new BuildEffectSoundState{Velocity=new float[]{Float(vw[0]),Float(vw[1]),Float(vw[2])},PositionWords=Words(o["position"])};
            world.Play=delegate(int id,uint[] position,float volume,float scale)
            {
                events.Add(new{id,position=position==null?null:(uint[])position.Clone(),volume=Bits(volume),scale=Bits(scale)});
                if(Bool(o["mutate"])){world.CooldownWord=0xbf800000;if(position!=null)position[1]=0xdeadbeef;}
            };
            try
            {
                string kind=(string)v["kind"];object result=null;
                if(kind=="hash")result=BuildEffectSound.Hash(registry,(string)o["name"]);
                else if(kind=="find")result=BuildEffectSound.Find(registry,(string)o["name"]);
                else if(kind=="sqrt")result=Bits(BuildEffectSound.SquareRoot(Float(U(v["value"]))));
                else if(kind=="length")result=Bits(BuildEffectSound.Length(effect.Velocity));
                else if(kind=="play")BuildEffectSound.Play(world,Int(o["id"]),Bool(o["positionPresent"])?effect.PositionWords:null,Float(U(o["volume"])));
                else BuildEffectSound.OnBuildEffect(world,effect);
                object got=json.DeserializeObject(json.Serialize(new{result,events,cooldown=world.CooldownWord,position=effect.PositionWords}));++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[2],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
