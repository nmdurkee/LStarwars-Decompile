using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class BuildEffectPlaybackVerify
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
    const uint D=0x10100000,POSITION=D+0x68000,NAMES=D+0x63000,RNG=0x810364;
    static float F(object x){return BitConverter.ToSingle(BitConverter.GetBytes(U(x)),0);}
    static void Text(SoundSetupImage m,uint at,string text){for(uint i=0;i<text.Length;i++)m.Byte(at+i,(byte)text[(int)i]);m.Byte(at+(uint)text.Length,0);}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));byte[] sineBytes=File.ReadAllBytes(args[1]);float[] sine=new float[sineBytes.Length/4];for(int i=0;i<sine.Length;i++)sine[i]=BitConverter.ToSingle(sineBytes,i*4);
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=SoundPlaybackVerify.Setup(p,data);m.Word(0x951000,U(p["cooldown"]));uint[] position=p["position"]==null?new uint[]{Bits(1),Bits(2),Bits(3)}:Words(p["position"]);uint[] velocity=Words(p["velocity"]);for(uint i=0;i<3;i++){m.Word(POSITION+i*4,position[i]);m.Word(POSITION+0x50+i*4,velocity[i]);}
                bool heads=Bool(p["heads"]);m.Word(0x292fda0,heads?SoundDefinitionVerify.HEADS:0);short[] headArray=new short[256];for(uint i=0;i<256;i++){headArray[i]=(short)Int(p["head"]);m.Half(SoundDefinitionVerify.HEADS+i*2,unchecked((ushort)headArray[i]));}
                object[] names=Arr(p["names"]),next=Arr(p["next"]);var entries=new EffectSoundEntry[names.Length];for(uint i=0;i<names.Length;i++){string name=(string)names[i];m.Word(SoundDefinitionVerify.RECORDS+i*64,name==null?0:NAMES+i*256);m.Half(SoundDefinitionVerify.RECORDS+i*64+0x10,unchecked((ushort)Int(next[i])));Text(m,NAMES+i*256,name??"");entries[i]=new EffectSoundEntry{Name=name,Next=(short)Int(next[i])};}
                var world=new BuildEffectSoundWorld{Sine=sine,Sounds=new EffectSoundRegistry{HashTable=Words(data["table"]),Heads=heads?headArray:null,Entries=entries}};var effect=new BuildEffectSoundState{PositionWords=position,Velocity=new float[]{F(velocity[0]),F(velocity[1]),F(velocity[2])}};var normalized=new Dictionary<string,object>(p);normalized["position"]=position;var events=new List<object>();
                BuildEffectPlaybackBridge.Run(world,effect,m,POSITION,delegate(SoundSetupImage image,uint target,uint[] arguments)
                {
                    uint ptr=(target==0x698260||target==0x698210||target==0x698100)?arguments[0]:0;uint[] words=ptr==0?null:new uint[]{image.Word(ptr),image.Word(ptr+4),image.Word(ptr+8)};events.Add(new{target,args=arguments,position=words,near=image.Word(0x810d9c),far=image.Word(0x810d98),seed=image.Word(RNG)});SoundPlaybackVerify.Mutate(image,normalized);if((string)p["mutation"]!="none")image.Word(0x951000,Bits(-1));
                });
                string got=SoundDefinitionVerify.Sha(m);checks++;bool bad=got!=(string)v["nativeSha"]||!Equal(json.DeserializeObject(json.Serialize(events)),v["events"]);if(bad){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[2],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
