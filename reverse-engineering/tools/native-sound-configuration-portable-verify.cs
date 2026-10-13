using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundConfigurationVerify
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
    const uint D=0x10100000,PARSER=D+0x1000,TOKEN=D+0x2000,BANKS=D+0x4000,ALT=D+0x8000,PATH=D+0x3000,CURSOR=D+0x3100;
    static void Text(SoundSetupImage m,uint a,string value){foreach(char c in value)m.Byte(a++,(byte)c);m.Byte(a,0);}
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        var m=new SoundSetupImage();uint seed=U(p["seed"]);foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        m.Word(0x2947d70,BANKS);m.Word(0x2962014,U(p["count"]));m.Word(0x2962034,U(p["flag"]));m.Word(PARSER+0x510,TOKEN);Text(m,TOKEN,"prior");Text(m,PATH,(string)p["path"]);m.Word(CURSOR,D+0xa000);return m;
    }
    sealed class Services:ISoundConfigurationServices
    {
        readonly Dictionary<string,object> p;int line=-1;public readonly List<object> Events=new List<object>();public Services(Dictionary<string,object> input){p=input;}
        uint Call(SoundSetupImage m,string kind,params uint[] args)
        {
            Events.Add(new{kind,args,sha=SoundDefinitionVerify.Sha(m)});uint result=0;
            switch(kind)
            {
                case "open":result=Bool(p["open"])?PARSER:0;break;
                case "configure":m.Word(PARSER+0x20,args[1]);break;
                case "line":line++;result=line<Arr(p["lines"]).Length?U(p["lineResult"]):0;break;
                case "token":Text(m,TOKEN,(string)Arr(p["lines"])[line]);m.Word(PARSER+0x510,TOKEN);result=U(p["tokenResult"]);break;
                case "dispatch":m.Word(0x2962014,unchecked(m.Word(0x2962014)+1));m.Word(D+0x3200,unchecked(m.Word(D+0x3200)+1));break;
                case "close":m.Word(0x2962014,unchecked(m.Word(0x2962014)+U(p["closeAdd"])));if(Bool(p["redirect"]))m.Word(0x2947d70,ALT);break;
                case "banks":for(uint i=0;i<200;i++)m.Byte(0x2921760+i,238);m.Word(0x2962034,U(p["afterFlag"]));m.Word(CURSOR,unchecked(m.Word(CURSOR)+U(p["advance"])));break;
                case "mask":for(uint i=0;i<200;i++)m.Byte(0x2921760+i,(byte)(i*3+U(p["seed"])));break;
                case "finish":m.Word(D+0x3300,0x12345678);break;
            }return result;
        }
        public uint Open(SoundSetupImage m,uint path){return Call(m,"open",path);}
        public void Configure(SoundSetupImage m,uint parser,uint table){Call(m,"configure",parser,table);}
        public int ReadLine(SoundSetupImage m,uint parser){return unchecked((int)Call(m,"line",parser));}
        public void ReadToken(SoundSetupImage m,uint parser){Call(m,"token",parser);}
        public void Dispatch(SoundSetupImage m,uint parser){Call(m,"dispatch",parser);}
        public void Close(SoundSetupImage m,uint parser){Call(m,"close",parser);}
        public void LoadBanks(SoundSetupImage m,uint banks,uint cursor,uint opaque){Call(m,"banks",banks,cursor,opaque);}
        public void SetMask(SoundSetupImage m,uint mask,int words){Call(m,"mask",mask,(uint)words);}
        public void Finish(SoundSetupImage m){Call(m,"finish");}
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));var services=new Services(p);SoundConfiguration.Load(m,PATH,CURSOR,0xaabbccdd,services);string got=SoundDefinitionVerify.Sha(m);checks++;if(got!=(string)v["nativeSha"]||!Equal(json.DeserializeObject(json.Serialize(services.Events)),v["events"])){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events=services.Events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
