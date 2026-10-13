using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundMaskVerify
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
    const uint D=0x10100000,SOURCE=D+0x1000,BUFFER=D+0x2000,ALLOC=D+0x3000,TABLE=D+0x4000,COM=D+0x4100,ALT=D+0x4200,METHOD=D+0xf010,ALTMETHOD=D+0xf020;
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        var m=new SoundSetupImage();uint seed=U(p["seed"]);foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        m.Word(0x2972bf0,U(p["prior"]));m.Word(0x2972bf4,Bool(p["buffer"])?BUFFER:0);m.Word(0x2972be8,U(p["source"]));m.Word(0x2972c24,Bool(p["event"])?0xabc123u:0);m.Word(0x2972c34,Bool(p["device"])?COM:0);m.Word(COM,TABLE);m.Word(ALT,TABLE+0x100);m.Word(TABLE+0x44,METHOD);m.Word(TABLE+0x144,ALTMETHOD);return m;
    }
    sealed class Services:ISoundMaskServices
    {
        readonly Dictionary<string,object> p;public readonly List<object> Events=new List<object>();public Services(Dictionary<string,object> input){p=input;}
        uint Call(SoundSetupImage m,string kind,params uint[] args)
        {
            Events.Add(new{kind,args,sha=SoundDefinitionVerify.Sha(m)});uint result=0;
            switch(kind)
            {
                case "allocate":m.Word(0x2972bf0,999);m.Word(0x2972be8,D+0x6000);m.Word(D+0x5000,m.Word(D+0x5000)^0x1234);result=Bool(p["nullAllocation"])?0:ALLOC;break;
                case "signal":if(Int(p["redirect"])>=0)m.Word(0x2972c34,new uint[]{0,COM,ALT}[Int(p["redirect"])]);m.Word(0x2972be8,0);m.Word(0x2972bf4,0);m.Word(D+0x5004,0xabcd);break;
                case "device":m.Word(0x2972c34,0);m.Word(D+0x5008,args[1]);break;
                case "voices":m.Word(D+0x500c,args[0]);break;
            }return result;
        }
        public uint Allocate(SoundSetupImage m,uint bytes,uint file,uint line){return Call(m,"allocate",bytes,file,line);}
        public void Signal(SoundSetupImage m,uint handle){Call(m,"signal",handle);}
        public void CommitDevice(SoundSetupImage m,uint function,uint instance){Call(m,"device",function,instance);}
        public void UpdateVoices(SoundSetupImage m,uint instance){Call(m,"voices",instance);}
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));var services=new Services(p);if((string)p["kind"]!="commit")SoundMaskLifecycle.Configure(m,U(p["source"]),Int(p["count"]),services);if((string)p["kind"]!="configure")SoundMaskLifecycle.Commit(m,services);string got=SoundDefinitionVerify.Sha(m);checks++;if(got!=(string)v["nativeSha"]||!Equal(json.DeserializeObject(json.Serialize(services.Events)),v["events"])){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events=services.Events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
