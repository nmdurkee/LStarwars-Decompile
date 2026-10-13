using System;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase520261013Verify
{
    const uint D=0x10100000,World=D,Arena=D+0x10000,ArenaEnd=D+0x50000,Levels=D+0x60000,Level=Levels+0x130,Level2=Levels+0x260,Group=D+0x80000,GroupArray=D+0x81000,GroupObjects=D+0x82000,Glyph=D+0x90000,Scene=D+0x90100,Photo=D+0x90200,Alternate=D+0x90300,Fail=0x93d840,Tag=0x2854d4c;
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
    static string Hash(SoundSetupImage m){using(MemoryStream b=new MemoryStream()){foreach(var r in m.Regions)b.Write(r.Value,0,r.Value.Length);using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(b.ToArray())).Replace("-","").ToLowerInvariant();}}
    sealed class Backend:ILevelTextFileBackend,IWorldResourceServices
    {
        public Dictionary<string,object> Options,IO;public byte[] Text;public readonly List<object> Trace=new List<object>();public int Reads,Seeks,AudioStops,Allocations,Teardowns;
        public void Emit(string name,params object[]fields){Dictionary<string,object>row=new Dictionary<string,object>();row["name"]=name;for(int i=0;i<fields.Length;i+=2)row[(string)fields[i]]=fields[i+1];Trace.Add(row);}
        void Entry(uint entry,uint[]args,params object[]fields){Dictionary<string,object>row=new Dictionary<string,object>();row["entry"]="0x"+entry.ToString("x");row["args"]=args;for(int i=0;i<fields.Length;i+=2)row[(string)fields[i]]=fields[i+1];Trace.Add(row);}
        void Feed(SoundSetupImage m,uint destination,int count){count=Math.Max(0,Math.Min(count,Text.Length));for(int i=0;i<count;i++)m.Byte(destination+(uint)i,Text[i]);}
        public int ReadArchive(SoundSetupImage m,uint archive,string path,uint destination,int capacity){Emit("Archive","archive",archive,"path",path,"destination",destination,"limit",capacity);m.Word(LevelTextLoading.Error,unchecked((uint)I(IO["archiveError"])));int value=I(IO["archiveReturn"]);Feed(m,destination,value);return value;}
        public int Exists(SoundSetupImage m,string path){Emit("Exists","path",path);return I(IO["exists"]);}
        public uint Open(SoundSetupImage m,string path,uint mode,uint archive,uint flags){Emit("Open","path",path,"mode",mode,"archive",archive,"flags",flags);return U(IO["open"]);}
        public int ReadSpecial(SoundSetupImage m,uint handle,uint destination,int capacity){Emit("Special","handle",handle,"destination",destination,"limit",capacity);int value=I(IO["specialReturn"]);Feed(m,destination,value);return value;}
        public int Length(SoundSetupImage m,uint handle){Emit("Length","handle",handle);return I(IO["length"]);}
        public int Read(SoundSetupImage m,uint handle,uint destination,int count){object[]results=Arr(IO["readResults"]);int value=I(results[Math.Min(Reads++,results.Length-1)]);Emit("Read","handle",handle,"destination",destination,"count",count,"result",value);if(value>=0)Feed(m,destination,Math.Min(value,count));return value;}
        public void Close(SoundSetupImage m,uint handle){Emit("Close","handle",handle);}
        public void Pump(SoundSetupImage m){Emit("Pump");}
        public long Seek(SoundSetupImage m,uint handle,uint low,uint high,uint origin){object[]results=Arr(IO["seekResults"]);long value=Convert.ToInt64(results[Math.Min(Seeks++,results.Length-1)]);Emit("Seek","handle",handle,"low",low,"high",high,"origin",origin,"result",value);return value;}
        public void TeardownStarted(uint world){Teardowns++;}
        public string TitleSuffix(SoundSetupImage m){string suffix=(string)Options["titleSuffix"];Entry(0x489aa0,new uint[0],"suffix",suffix);return suffix;}
        public uint LoadScene(SoundSetupImage m,uint entry,uint[]args,string path,string role)
        {
            Entry(entry,args,"path",path,"role",role,"tag",m.Word(Tag),"cursor",m.Word(args[0]));uint ptr=m.Word(args[0]);int size=I(Options[role=="pictures"?"pictureBytes":"sceneBytes"]);
            for(int i=0;i<size;i++)m.Byte(ptr+(uint)i,(byte)(role=="pictures"?0xab:0xcd));m.Word(args[0],ptr+(uint)size);Allocations++;
            if((string)Options["failAt"]==role)m.Word(Fail,1);return Bool(Options[role=="pictures"?"picturePresent":"scenePresent"])?ptr:0;
        }
        public uint Call(SoundSetupImage m,uint entry,params uint[]args)
        {
            Entry(entry,args);string failAt=(string)Options["failAt"];
            if(entry==0x578f60)
            {
                if(Bool(Options["metaSwap"]))m.Word(World+0x128,Level2);if(I(Options["metaFlags"])!=-1)m.Word(m.Word(World+0x128)+0x64,U(Options["metaFlags"]));if(failAt=="metadata")m.Word(Fail,1);
            }
            else if(entry==0x6d34c0){if(Bool(Options["flipBackend"]))m.Word(0x8264bc,2);}
            else if(entry==0x48c270){m.Word(args[1],0xc0270);if(Bool(Options["clearSceneAtBounds"]))m.Word(World+0x13c,0);if(failAt=="bounds")m.Word(Fail,1);}
            else if(entry==0x5528b0){m.Word(World+0x150,m.Word(World+0x150)+1);if(Bool(Options["rebindSceneAtPost"]))m.Word(World+0x13c,Alternate);if(failAt=="postscene")m.Word(Fail,1);}
            else if(entry==0x48c630){m.Word(World+0x2b00,m.Word(World+0x2b00)+1);if(failAt=="special")m.Word(Fail,1);}
            else if(entry==0x5934d0)m.Word(World+0x2b00,m.Word(World+0x2b00)+1);
            else if(entry==0x652b40){AudioStops++;if(AudioStops==1&&I(Options["newGroupCount"])!=-99)m.Word(Group+4,unchecked((uint)I(Options["newGroupCount"])));}
            else if(entry==0x5ef880){if(args[0]>=D&&args[0]<D+0xa0000)m.Word(args[0],0xd15ab1ed);}
            else if(entry==0x5a29d0){if(Bool(Options["rebindSceneAtTeardown"]))m.Word(World+0x13c,Alternate);}
            if(Bool(Options["mutateHandles"]))
            {
                uint offset=entry==0x68e900?0x2a98u:entry==0x648a30?0x2a9cu:entry==0x689e70?0x2aa4u:entry==0x65a5c0?0x2aa0u:0;
                if(offset!=0)m.Word(World+offset,U(Options["mutateValue"]));
            }
            if(Bool(Options["mutatePools"])&&args.Length!=0)
            {
                if(entry==0x68ea00&&args[0]>=2&&args[0]<7)m.Word(0x2948eb0+(args[0]+1)*4,0);
                if(entry==0x64c6e0&&args[0]>=1&&args[0]<7)m.Word(0x2913a2c+(args[0]+1)*4,0);
            }
            return 0;
        }
    }
    static SoundSetupImage Setup(Dictionary<string,object>p,object[]regions)
    {
        SoundSetupImage m=new SoundSetupImage();foreach(object region in regions){object[]r=Arr(region);byte[]b=new byte[I(r[1])];for(int i=0;i<b.Length;i++)b[i]=0x6d;m.Regions.Add(U(r[0]),b);}Array.Clear(m.Regions[D],0,0x51ac);Dictionary<string,object>io=Obj(p["io"]);
        CString(m,World,(string)io["path"]);CString(m,World+0x80,(string)io["path"]);m.Word(World+0x100,Arena);m.Word(World+0x104,Arena+(uint)I(io["cursorOffset"]));m.Word(World+0x108,ArenaEnd);m.Word(World+0x110,U(p["loadedMarker"]));m.Word(World+0x11c,1);m.Word(World+0x120,2);m.Word(World+0x124,3);m.Word(World+0x128,Level);
        m.Word(World+0x2ab0,Bool(p["groupPresent"])?Group:0);m.Word(Group,GroupArray);m.Word(Group+4,unchecked((uint)I(p["groupCount"])));
        for(uint i=0;i<3;i++){m.Word(GroupArray+i*4,GroupObjects+i*32);m.Word(GroupObjects+i*32+4,0xa0+i);}
        m.Word(World+0x2964,Bool(p["glyphPresent"])?Glyph:0);m.Word(World+0x13c,Bool(p["sceneBefore"])?Scene:0);m.Word(World+0x140,Bool(p["photoBefore"])?Photo:0);uint[]offs={0x2a98,0x2a9c,0x2aa4,0x2aa8,0x2aa0};object[]handles=Arr(p["handles"]);for(int i=0;i<offs.Length;i++)m.Word(World+offs[i],unchecked((uint)Convert.ToInt64(handles[i])));
        m.Word(0x7fac04,U(p["poolSkip"]));m.Word(0x8264bc,U(p["backendMode"]));m.Word(0x87b71c,0);m.Word(LevelTextLoading.Archive,U(io["archive"]));m.Word(LevelTextLoading.SpecialMode,U(io["special"]));m.Word(LevelTextLoading.Error,0xdeadbeef);m.Word(Fail,U(p["initialFail"]));m.Word(0x951b78,Levels);m.Word(0x951b88,I(p["title"])==1?Level:0);m.Word(0x951b9c,I(p["title"])==2?Level:0);m.Word(0x951ba8,0x1234);m.Word(0x955870,0x5678);m.Word(Tag,0x87654321);
        m.Zero(0x87b060,44);m.Zero(0x87b164,16);if((I(p["tableMatch"])&1)!=0)m.Word(0x87b060+40,Level);if((I(p["tableMatch"])&2)!=0)m.Word(0x87b164+12,Level);
        for(uint i=0;i<8;i++){bool active=(I(p["poolMask"])&(1<<(int)i))!=0;m.Word(0x2948eb0+i*4,active?0x1000+i:0);m.Word(0x2913a2c+i*4,active?0x2000+i:0);}
        for(int i=0;i<2;i++){uint record=i==0?Level:Level2;int delta=i==0?0:7;m.Word(record+0x64,U(p["flags"]));m.Byte(record+0xa0,unchecked((byte)(I(p["stageByte"])+delta)));m.Byte(record+0xa2,unchecked((byte)(I(p["channelByte"])+delta)));m.Byte(record+0xa3,2);}
        return m;
    }
    public static int Main(string[]args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object>data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int cases=0,checks=0,failures=0;List<object>errors=new List<object>();
        foreach(object value in Arr(data["cases"]))
        {
            Dictionary<string,object>row=Obj(value),p=Obj(row["options"]);List<string>bad=new List<string>();
            try
            {
                SoundSetupImage m=Setup(p,Arr(data["regions"]));Dictionary<string,object>io=Obj(p["io"]);Backend backend=new Backend{Options=p,IO=io,Text=Encoding.GetEncoding(28591).GetBytes((string)io["text"])};bool handoff=false;
                if((string)p["kind"]=="Prefix")handoff=WorldSceneLoaderPhase.Run(m,World,backend,source=>{string path=source+".txt";backend.Emit("Format","format","%s.txt","source",source,"path",path);return path;},backend)==WorldScenePhaseResult.HandoffToAuxiliary;
                else WorldResourceTeardown.Run(m,World,backend);
                ++checks;if(Hash(m)!=(string)row["nativeSha"])bad.Add("complete image");++checks;if(handoff!=Bool(row["handoff"]))bad.Add("phase outcome");++checks;if(backend.Teardowns!=I(row["teardownEntries"]))bad.Add("nested teardown entries");++checks;if(!Equal(backend.Trace,row["trace"]))bad.Add("mutable service trace");
                ++checks;if(!Equal(new Dictionary<string,object>{{"audioStops",backend.AudioStops},{"allocations",backend.Allocations}},row["resourceState"]))bad.Add("resource state");++checks;if(!Equal(new Dictionary<string,object>{{"read",backend.Reads},{"seek",backend.Seeks}},row["ioState"]))bad.Add("IO state");
            }
            catch(Exception e){bad.Add(e.ToString());}
            if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,bad});}cases++;
        }
        string report=json.Serialize(new{cases,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
    }
}
