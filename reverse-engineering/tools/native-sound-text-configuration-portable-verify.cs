using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundTextConfigurationVerify
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
    const uint D=0x10100000,PARSER=D+0x60000,TOKEN=D+0x50000,BUFFER=D+0x62000,LINE=D+0x64000,PATH=D+0x66000,CURSOR=D+0x67000,MARKER=D+0x7f000,HANDLE=0x12345678;
    static void Text(SoundSetupImage m,uint a,string value){foreach(char c in value)m.Byte(a++,(byte)c);m.Byte(a,0);}
    static object Stats(SoundSetupImage m){return new{sounds=m.Word(0x296201c),banks=m.Word(0x2962014),names=m.Word(0x2962018),groups=m.Word(0x2962024),members=m.Word(0x2962020),version=m.Word(0x2962030)};}
    static SoundSetupImage Setup(Dictionary<string,object> p,Dictionary<string,object> data)
    {
        var defaults=new Dictionary<string,object>{{"seed",p["seed"]},{"index",0},{"bankNames",new object[0]},{"nameCount",0},{"builtinCount",0},{"flags",0},{"head",-1}};var m=SoundDefinitionVerify.Setup(defaults,data);
        foreach(var pair in Obj(data["constants"])) {uint at=UInt32.Parse(pair.Key);string hex=(string)pair.Value;for(int i=0;i<hex.Length;i+=2)m.Byte(at+(uint)i/2,Convert.ToByte(hex.Substring(i,2),16));}
        m.Zero(SoundDefinitionVerify.RECORDS,0x19000);m.Zero(SoundDefinitionVerify.BACKUP,0x19000);m.Zero(SoundDefinitionVerify.BANKS,0xaf00);foreach(uint at in new uint[]{0x2962024,0x2962020,0x91eec4})m.Word(at,0);
        m.Word(0x2962034,U(p["flag"]));m.Word(PARSER,BUFFER);m.Word(PARSER+4,HANDLE);m.Word(PARSER+0x50c,LINE);m.Word(PARSER+0x510,TOKEN);m.Word(PARSER+0x514,4096);m.Word(PARSER+0x518,128);m.Word(PARSER+0x51c,0);m.Word(PARSER+0x520,0);m.Word(PARSER+0x524,0);m.Word(PARSER+0x528,0);m.Word(PARSER+0x52c,0xffffffff);m.Word(PARSER+0x574,(uint)((string)p["text"]).Length);m.Word(PARSER+0x570,0xffffffff);m.Byte(PARSER+0x578,0);m.Word(PARSER+0x57c,0);m.Word(PARSER+0x580,0);Text(m,PATH,"AUDIO/AUDIO.CFG");m.Word(CURSOR,D+0x68000);return m;
    }
    sealed class Services:ISoundConfigurationServices
    {
        readonly Dictionary<string,object> p;readonly string text;int position;public readonly List<object> Events=new List<object>(),Reads=new List<object>();public Services(Dictionary<string,object> input){p=input;text=(string)p["text"];}
        public int Read(SoundSetupImage m,uint handle,uint buffer,int requested)
        {
            if(handle!=HANDLE||buffer!=BUFFER||requested<0||requested>4096)throw new Exception("File request backing");int count=Math.Min(Math.Min(requested,Int(p["chunk"])),text.Length-position);for(int i=0;i<count;i++)m.Byte(buffer+(uint)i,(byte)text[position+i]);Reads.Add(new{args=new uint[]{handle,buffer,(uint)requested},position,count});position+=count;return count;
        }
        void Device(SoundSetupImage m,string kind,params uint[] args)
        {
            if(kind=="banks")Events.Add(new{kind,args,counts=Stats(m)});else Events.Add(new{kind,args});
            if(kind=="banks"){for(uint i=0;i<200;i++)m.Byte(0x2921760+i,238);m.Word(0x2962034,U(p["afterFlag"]));m.Word(CURSOR,unchecked(m.Word(CURSOR)+16));}
            else if(kind=="mask")for(uint i=0;i<200;i++)m.Byte(0x2921760+i,(byte)(i*3+U(p["seed"])));else if(kind=="finish")m.Word(MARKER,0x12345678);
        }
        public uint Open(SoundSetupImage m,uint path){Device(m,"open",path);return Bool(p["open"])?PARSER:0;}
        public void Configure(SoundSetupImage m,uint parser,uint table){throw new Exception("Recovered configuration bypassed");}
        public int ReadLine(SoundSetupImage m,uint parser){throw new Exception("Recovered line parser bypassed");}
        public void ReadToken(SoundSetupImage m,uint parser){throw new Exception("Recovered token parser bypassed");}
        public void Dispatch(SoundSetupImage m,uint parser){throw new Exception("Recovered dispatcher bypassed");}
        public void Close(SoundSetupImage m,uint parser){Device(m,"close",parser);}
        public void LoadBanks(SoundSetupImage m,uint banks,uint cursor,uint opaque){Device(m,"banks",banks,cursor,opaque);}
        public void SetMask(SoundSetupImage m,uint mask,int words){Device(m,"mask",mask,(uint)words);}
        public void Finish(SoundSetupImage m){Device(m,"finish");}
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,data);var host=new Services(p);var adapter=new SoundTextConfiguration(host,host.Read);SoundConfiguration.Load(m,PATH,CURSOR,0xaabbccdd,adapter);string got=SoundDefinitionVerify.Sha(m);checks++;bool bad=got!=(string)v["nativeSha"]||!Equal(json.DeserializeObject(json.Serialize(host.Events)),v["events"])||!Equal(json.DeserializeObject(json.Serialize(host.Reads)),v["reads"])||!Equal(json.DeserializeObject(json.Serialize(Stats(m))),v["counts"]);if(bad){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events=host.Events,counts=Stats(m)});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
