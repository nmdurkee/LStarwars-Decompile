using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundVoicesVerify
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
    const uint D=0x10100000,OWNER=D+0x1000,TABLE=D+0x3000,OBJECTS=D+0x4000,AUX=D+0x7000,ALTS=D+0x8000;
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        var m=new SoundSetupImage();uint seed=U(p["seed"]);foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        m.Word(0x810dc0,U(p["master"]));m.Word(0x297dbfc,U(p["delta"]));m.Word(OWNER+0xd10,U(p["live"]));foreach(uint slot in new uint[]{8,0x18,0x24,0x3c,0x48})m.Word(TABLE+slot,D+0xf100+slot);
        object[] voices=Arr(p["voices"]);for(uint index=0;index<64;index++)
        {
            object[] r=Arr(voices[index]);uint record=OWNER+12+index*52,obj=OBJECTS+index*64,alt=ALTS+index*64,aux=AUX+index*16;
            m.Word(record,Bool(r[0])?obj:0);m.Word(record+4,Bool(r[1])?aux:0);m.Word(record+0x14,U(r[2]));m.Word(record+0x28,U(r[3]));m.Word(record+0x2c,U(r[4]));
            foreach(uint target in new uint[]{obj,alt}){m.Word(target,TABLE);m.Word(target+4,index);m.Word(target+8,U(r[5]));m.Word(target+12,U(r[6]));}m.Word(aux,TABLE);m.Word(aux+4,index+128);
        }return m;
    }
    sealed class Services:ISoundVoiceServices
    {
        readonly Dictionary<string,object> p;public readonly List<object> Events=new List<object>();public Services(Dictionary<string,object> input){p=input;}
        uint Call(SoundSetupImage m,string kind,params uint[] args)
        {
            Events.Add(new{kind,args,sha=SoundDefinitionVerify.Sha(m)});uint result=0;
            if(kind=="clock"){if(Bool(p["mutate"])){m.Word(0x2972c1c,3);m.Word(0x2972c20,5);}return U(p["time"]);}
            uint obj=args[1],index=m.Word(obj+4),record=OWNER+12+(index%128)*52,alt=ALTS+(index%128)*64;
            switch(kind)
            {
                case "status":result=m.Word(obj+8);if(Bool(p["mutate"])){if(index<32&&index%5==0)m.Word(record,0);else if(index%5==1)m.Word(record,alt);else if(index>=32&&index%5==2){m.Word(record+0x14,1);m.Word(record+0x2c,0xffffffff);m.Word(record+0x28,unchecked(m.Word(0x2972c18)+2));}}break;
                case "volume":result=m.Word(obj+12);if(Bool(p["mutate"])){m.Word(0x297dbfc,U(p["changedDelta"]));m.Word(record,alt);}break;
                case "set":m.Word(obj+12,args[2]);break;
                case "stop":m.Word(obj+0x10,m.Word(obj+0x10)^0x1234);if(Bool(p["mutate"]))m.Word(record,alt);break;
                case "release":m.Word(obj+0x14,m.Word(obj+0x14)^0x5678);if(Bool(p["mutate"])&&index>=128)m.Word(record,alt);break;
            }return result;
        }
        public uint TimeMilliseconds(SoundSetupImage m){return Call(m,"clock");}
        public uint GetStatus(SoundSetupImage m,uint function,uint instance){return Call(m,"status",function,instance);}
        public int GetVolume(SoundSetupImage m,uint function,uint instance){return unchecked((int)Call(m,"volume",function,instance));}
        public void SetVolume(SoundSetupImage m,uint function,uint instance,int volume){Call(m,"set",function,instance,unchecked((uint)volume));}
        public void Stop(SoundSetupImage m,uint function,uint instance){Call(m,"stop",function,instance);}
        public void Release(SoundSetupImage m,uint function,uint instance){Call(m,"release",function,instance);}
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));var services=new Services(p);switch((string)p["kind"]){case "update":SoundVoiceLifecycle.Update(m,OWNER,services);break;case "retire":SoundVoiceLifecycle.Retire(m,OWNER,Int(p["index"]),services);break;case "set":SoundVoiceLifecycle.SetVolume(m,OBJECTS+U(p["index"])*64,unchecked((int)U(p["value"])),services);break;}string got=SoundDefinitionVerify.Sha(m);checks++;if(got!=(string)v["nativeSha"]||!Equal(json.DeserializeObject(json.Serialize(services.Events)),v["events"])){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events=services.Events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
