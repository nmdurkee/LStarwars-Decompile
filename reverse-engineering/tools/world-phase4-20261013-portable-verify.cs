using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase420261013Verify
{
    const uint D=0x10100000,World=D,Input=D+0x20000,Output=D+0x40000;
    static Dictionary<string,object> Obj(object v){return(Dictionary<string,object>)v;}
    static object[] Arr(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static void CString(SoundSetupImage m,uint a,string text){byte[]b=Encoding.GetEncoding(28591).GetBytes(text);for(int i=0;i<b.Length;i++)m.Byte(a+(uint)i,b[i]);m.Byte(a+(uint)b.Length,0);}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static string Hash(SoundSetupImage m)
    {
        using(MemoryStream buffer=new MemoryStream()){foreach(var r in m.Regions)buffer.Write(r.Value,0,r.Value.Length);using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(buffer.ToArray())).Replace("-","").ToLowerInvariant();}
    }
    sealed class Backend:ILevelTextFileBackend
    {
        public Dictionary<string,object> Options;public byte[] Text;public readonly List<object> Trace=new List<object>();int reads,seeks;
        public void Emit(string name,params object[]fields){Dictionary<string,object>row=new Dictionary<string,object>();row["name"]=name;for(int i=0;i<fields.Length;i+=2)row[(string)fields[i]]=fields[i+1];Trace.Add(row);}
        void Feed(SoundSetupImage m,uint destination,int count){count=Math.Max(0,Math.Min(count,Text.Length));for(int i=0;i<count;i++)m.Byte(destination+(uint)i,Text[i]);}
        public int ReadArchive(SoundSetupImage m,uint archive,string path,uint destination,int capacity){Emit("Archive","archive",archive,"path",path,"destination",destination,"limit",capacity);m.Word(LevelTextLoading.Error,unchecked((uint)I(Options["archiveError"])));int value=I(Options["archiveReturn"]);Feed(m,destination,value);return value;}
        public int Exists(SoundSetupImage m,string path){Emit("Exists","path",path);return I(Options["exists"]);}
        public uint Open(SoundSetupImage m,string path,uint mode,uint archive,uint flags){Emit("Open","path",path,"mode",mode,"archive",archive,"flags",flags);return U(Options["open"]);}
        public int ReadSpecial(SoundSetupImage m,uint handle,uint destination,int capacity){Emit("Special","handle",handle,"destination",destination,"limit",capacity);int value=I(Options["specialReturn"]);Feed(m,destination,value);return value;}
        public int Length(SoundSetupImage m,uint handle){Emit("Length","handle",handle);return I(Options["length"]);}
        public int Read(SoundSetupImage m,uint handle,uint destination,int count){object[]results=Arr(Options["readResults"]);int value=I(results[Math.Min(reads++,results.Length-1)]);Emit("Read","handle",handle,"destination",destination,"count",count,"result",value);if(value>=0)Feed(m,destination,Math.Min(value,count));return value;}
        public void Close(SoundSetupImage m,uint handle){Emit("Close","handle",handle);}
        public void Pump(SoundSetupImage m){Emit("Pump");}
        public long Seek(SoundSetupImage m,uint handle,uint low,uint high,uint origin){object[]results=Arr(Options["seekResults"]);long value=Convert.ToInt64(results[Math.Min(seeks++,results.Length-1)]);Emit("Seek","handle",handle,"low",low,"high",high,"origin",origin,"result",value);return value;}
    }
    static SoundSetupImage Setup(Dictionary<string,object>p,object[]regions)
    {
        SoundSetupImage m=new SoundSetupImage();foreach(object region in regions){object[]r=Arr(region);byte[]b=new byte[I(r[1])];for(int i=0;i<b.Length;i++)b[i]=0x6d;m.Regions.Add(U(r[0]),b);}
        m.Word(LevelTextLoading.Archive,U(p["archive"]));m.Word(LevelTextLoading.SpecialMode,U(p["special"]));m.Word(LevelTextLoading.Error,0xdeadbeef);CString(m,World+0x80,(string)p["path"]);m.Word(World+0x104,Input+(uint)I(p["cursorOffset"]));m.Word(World+0x10c,0x11223344);CString(m,D+0x1000,(string)p["path"]+".txt");if((string)p["kind"]=="Normalize")CString(m,Input,(string)p["text"]);return m;
    }
    public static int Main(string[]args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object>data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int cases=0,checks=0,failures=0;List<object>errors=new List<object>();
        foreach(object value in Arr(data["cases"]))
        {
            Dictionary<string,object>row=Obj(value),p=Obj(row["options"]);List<string>bad=new List<string>();
            try
            {
                SoundSetupImage m=Setup(p,Arr(data["regions"]));Backend backend=new Backend{Options=p,Text=Encoding.GetEncoding(28591).GetBytes((string)p["text"])};string kind=(string)p["kind"];uint result=0;
                if(kind=="Normalize")result=unchecked((uint)LevelTextLoading.Normalize(m,Input,Bool(p["inPlace"])?Input:Output,I(p["normalizeSeparators"])));
                else if(kind=="Read")result=unchecked((uint)LevelTextLoading.ReadWhole(m,backend,(string)p["path"]+".txt",Input,I(p["capacity"])));
                else LevelTextLoading.Produce(m,World,backend,source=>{string path=source+".txt";backend.Emit("Format","format","%s.txt","source",source,"path",path);return path;});
                if(row["nativeReturn"]!=null){++checks;if(result!=U(row["nativeReturn"]))bad.Add("return");}
                ++checks;if(Hash(m)!=(string)row["nativeSha"])bad.Add("complete image");
                ++checks;if(m.Word(World+0x10c)!=U(row["count"]))bad.Add("count");++checks;if(m.Word(World+0x104)!=U(row["cursor"]))bad.Add("cursor");++checks;if(m.Word(LevelTextLoading.Error)!=U(row["error"]))bad.Add("error");
                ++checks;if(!Equal(backend.Trace,row["trace"]))bad.Add("backend trace");
            }
            catch(Exception e){bad.Add(e.ToString());}
            if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;
        }
        string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
    }
}
