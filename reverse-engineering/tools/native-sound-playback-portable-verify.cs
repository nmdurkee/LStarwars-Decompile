using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundPlaybackVerify
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
    const uint D=0x10100000,POSITION=D+0x68000,LISTENER=D+0x69000,CONTEXT=D+0x6a000,ALT=D+0x70000,RNG=0x810364;
    static float F(object x){return BitConverter.ToSingle(BitConverter.GetBytes(U(x)),0);}
    static void PutWords(SoundSetupImage m,uint at,object[] words){for(uint i=0;i<words.Length;i++)m.Word(at+i*4,U(words[i]));}
    static Dictionary<string,object> Defaults(){return new Dictionary<string,object>{{"seed",17},{"index",3},{"bankNames",new object[0]},{"nameCount",0},{"builtinCount",0},{"flags",0},{"head",-1}};}
    public static SoundSetupImage Setup(Dictionary<string,object> p,Dictionary<string,object> data)
    {
        var m=SoundDefinitionVerify.Setup(Defaults(),data);m.Word(RNG,U(p["seed"]));m.Word(0x2972c38,Bool(p["listenerPresent"])?LISTENER:0);m.Word(0x2962b8c,Bool(p["contextPresent"])?CONTEXT:0);m.Word(CONTEXT+0x1ac,U(p["contextVolume"]));m.Word(0x81046c,U(p["fade"]));m.Word(0x810468,U(p["master"]));m.Word(0x810d9c,U(p["near"]));m.Word(0x810d98,U(p["far"]));
        object[] records=Arr(p["records"]);for(uint i=0;i<records.Length;i++){PutWords(m,SoundDefinitionVerify.RECORDS+i*64,Arr(records[i]));PutWords(m,ALT+i*64,Arr(records[i]));}
        foreach(uint ptr in new uint[]{LISTENER,0x9736e8}){PutWords(m,ptr+0x30,Arr(p["listener"]));PutWords(m,ptr+0x20,Arr(p["forward"]));}if(p["position"]!=null)PutWords(m,POSITION,Arr(p["position"]));m.Half(0x2920d88,0);m.Half(0x2920d8a,2);m.Half(0x2920d8c,(ushort)Int(p["cursor"]));m.Half(0x2921260,1);m.Half(0x2921262,2);return m;
    }
    public static void Mutate(SoundSetupImage m,Dictionary<string,object> p)
    {
        string mutation=(string)p["mutation"];if(mutation=="none")return;m.Word(0x810d9c,Bits(111));m.Word(0x810d98,Bits(222));m.Word(RNG,0xabcdef01);if(p["position"]!=null)m.Word(POSITION+4,Bits(99));
        if(mutation=="clear-distance")for(uint i=0;i<Arr(p["records"]).Length;i++){m.Word(SoundDefinitionVerify.RECORDS+i*64+0x24,0);m.Word(SoundDefinitionVerify.RECORDS+i*64+0x28,0);}if(mutation=="redirect")m.Word(0x2947b74,ALT);
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);string kind=(string)v["kind"];try
            {
                var m=Setup(p,data);var events=new List<object>();object result=null;
                if(kind=="play")SoundPlayback.Play(m,Int(p["id"]),p["position"]==null?0:POSITION,F(p["volume"]),F(p["scale"]),delegate(SoundSetupImage image,uint target,uint[] arguments)
                {
                    uint position=(target==0x698260||target==0x698210||target==0x698100)?arguments[0]:0;uint[] words=position==0?null:new uint[]{image.Word(position),image.Word(position+4),image.Word(position+8)};events.Add(new{target,args=arguments,position=words,near=image.Word(0x810d9c),far=image.Word(0x810d98),seed=image.Word(RNG)});Mutate(image,p);
                });
                else if(kind=="listener")result=SoundPlayback.Listener(m);
                else{uint value;if(kind=="random"){uint seed=m.Word(RNG);value=Bits(SoundPlayback.RandomFraction(ref seed));m.Word(RNG,seed);}else value=Bits(SoundPlayback.ContextVolume(m));m.Word(D+0x62000,value);result=value;}
                string got=SoundDefinitionVerify.Sha(m);checks++;bool bad=got!=(string)v["nativeSha"];if(kind=="play")bad|=!Equal(json.DeserializeObject(json.Serialize(events)),v["events"]);else bad|=!Equal(result,v["result"]);
                if(bad){failures++;if(errors.Count<10)errors.Add(new{index,kind,got,want=v["nativeSha"],result,events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,kind,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
