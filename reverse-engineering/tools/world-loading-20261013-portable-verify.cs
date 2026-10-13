using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class WorldLoading20261013Verify
{
    const uint D=0x10100000, Levels=D+0x10000, Areas=D+0x20000, Save=D+0x80000, A1=D+0x30000, A2=D+0x31000;
    static uint[] Worlds={WorldLoadingContracts.FirstWorld,WorldLoadingContracts.SecondWorld};
    static Dictionary<string,object> Obj(object v){return(Dictionary<string,object>)v;}
    static object[] Arr(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static uint Add(uint a,int d){return unchecked(a+(uint)d);}
    sealed class Memory:IWorldLoadingMemory
    {
        public readonly byte[][] WorldsData={new byte[WorldLoadingContracts.WorldBytes],new byte[WorldLoadingContracts.WorldBytes]};
        public readonly byte[] Data=new byte[0x100000];
        readonly Dictionary<uint,byte> extra=new Dictionary<uint,byte>();
        byte[] Region(uint a,out int offset)
        {
            if(a>=D&&a<D+Data.Length){offset=(int)(a-D);return Data;}
            for(int i=0;i<2;i++)if(a>=Worlds[i]&&a<Worlds[i]+WorldsData[i].Length){offset=(int)(a-Worlds[i]);return WorldsData[i];}
            offset=0;return null;
        }
        public byte ReadByte(uint a){int o;byte[] r=Region(a,out o);byte b;return r!=null?r[o]:extra.TryGetValue(a,out b)?b:(byte)0;}
        public sbyte ReadSByte(uint a){return unchecked((sbyte)ReadByte(a));}
        public void WriteByte(uint a,byte b){int o;byte[] r=Region(a,out o);if(r!=null)r[o]=b;else extra[a]=b;}
        public uint ReadUInt32(uint a){return(uint)(ReadByte(a)|(ReadByte(a+1)<<8)|(ReadByte(a+2)<<16)|(ReadByte(a+3)<<24));}
        public void WriteUInt32(uint a,uint b){for(int i=0;i<4;i++)WriteByte(a+(uint)i,(byte)(b>>(i*8)));}
        public void Clear(uint a,int size){int o;byte[] r=Region(a,out o);if(r==null||o+size>r.Length)throw new ArgumentException("Clear requires prepared contiguous backing.");Array.Clear(r,o,size);}
        public string ReadCString(uint a){List<byte>b=new List<byte>();while(ReadByte(a)!=0){b.Add(ReadByte(a++));if(b.Count>127)throw new ArgumentException("Fixture string bound.");}return Encoding.ASCII.GetString(b.ToArray());}
        public void WriteCString(uint a,string text){byte[] b=Encoding.ASCII.GetBytes(text);for(int i=0;i<b.Length;i++)WriteByte(a+(uint)i,b[i]);WriteByte(a+(uint)b.Length,0);}
    }
    sealed class Calls:IWorldLoadingCalls
    {
        public Memory Memory;public uint Loaded;public readonly List<string> Trace=new List<string>();
        public void Invoke(uint a,params uint[] args){Trace.Add(CallKey(a,args));if(a==0x48ce00)Memory.WriteUInt32(args[0]+0x110,Loaded);}
    }
    static string CallKey(uint a,uint[] args){string key="0x"+a.ToString("x");foreach(uint v in args)key+=":"+v.ToString();return key;}
    static string Hash(byte[] bytes){using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(bytes)).Replace("-","").ToLowerInvariant();}
    static Memory Setup(Dictionary<string,object>o,string prefix,string separator)
    {
        Memory m=new Memory();for(int i=0;i<2;i++)for(int j=0;j<m.WorldsData[i].Length;j++)m.WorldsData[i][j]=(byte)(i==0?0xa5:0x5a);
        for(int i=0;i<2;i++)
        {
            uint w=Worlds[i],a=i==0?A1:A2;
            m.WriteUInt32(w+0x100,a);m.WriteUInt32(w+0x104,a+32);m.WriteUInt32(w+0x108,Add(a,I(o["arenaLength"])));
            m.WriteUInt32(w+0x110,U(o[i==I(o["target"])?"loaded":"otherLoaded"]));
            m.WriteUInt32(w+0x11c,unchecked((uint)I(o[i==I(o["target"])?"cached":"otherCached"])));
            for(int j=0;j<256;j++)m.WriteByte(a+(uint)j,0x6d);
        }
        m.WriteUInt32(0x951b78,Levels);m.WriteUInt32(0x951354,Areas);m.WriteUInt32(0x87b2cc,Save);m.WriteUInt32(0x87b71c,U(o["force"]));
        m.WriteUInt32(0x802c54,Worlds[I(o["current"])]);m.WriteUInt32(0x802c58,Worlds[I(o["staging"])]);m.WriteUInt32(0x802c68,0xfedcba98);
        m.WriteUInt32(0x803784,unchecked((uint)I(o["currentArea"])));m.WriteUInt32(0x93d848,unchecked((uint)I(o["level"])));m.WriteUInt32(0x93d84c,0xabcdef12);m.WriteUInt32(0x9248b4,U(o["reserve"]));
        foreach(int index in new[]{-1,0,1,2})
        {
            uint record=Add(Levels,index*0x130);m.WriteCString(record,(string)o["directory"]);m.WriteCString(record+0x40,(string)o["name"]);
            m.WriteByte(record+0xa3,unchecked((byte)I(o["area"])));m.WriteByte(record+0xc8,unchecked((byte)I(o["save"])));
        }
        m.WriteByte(Add(Areas,I(o["area"])*0x9c+0x86),unchecked((byte)I(o["chapter"])));
        m.WriteByte(Add(Areas,I(o["currentArea"])*0x9c+0x7a),(byte)I(o["areaFlags"]));
        m.WriteCString(0x75a208,prefix);m.WriteCString(0x75a204,separator);return m;
    }
    public static int Main(string[]args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;
        Dictionary<string,object>data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,failures=0,index=0;List<object>errors=new List<object>();
        foreach(object value in Arr(data["cases"]))
        {
            Dictionary<string,object>row=Obj(value),o=Obj(row["options"]);List<string>bad=new List<string>();
            try
            {
                Memory m=Setup(o,(string)data["prefix"],(string)data["separator"]);Calls calls=new Calls{Memory=m,Loaded=U(o["loaderLoaded"])};uint result=0;string kind=(string)row["kind"];
                if(kind=="Initialize")result=WorldLoadingContracts.Initialize(m,calls,Worlds[I(o["target"])],I(o["level"]));
                else if(kind=="OtherCached")result=WorldLoadingContracts.OtherCachedLevel(m,Worlds[I(o["target"])]);
                else if(kind=="Stage")WorldLoadingContracts.Stage(m,calls);
                else{m.WriteUInt32(Worlds[0]+0x108,U(o["end1"]));m.WriteUInt32(Worlds[1]+0x108,U(o["end2"]));WorldLoadingContracts.AssignArenaEnds(m,I(o["currentArea"]),I(o["previousArea"]));}
                if(row["nativeReturn"]!=null){++checks;if(result!=U(row["nativeReturn"]))bad.Add("return");}
                object[] wh=Arr(row["worldSha256"]),ah=Arr(row["arenaSha256"]);
                for(int i=0;i<2;i++)
                {
                    ++checks;if(Hash(m.WorldsData[i])!=(string)wh[i])bad.Add("world"+i);
                    byte[]a=new byte[256];Array.Copy(m.Data,(int)((i==0?A1:A2)-D),a,0,256);++checks;if(Hash(a)!=(string)ah[i])bad.Add("arena"+i);
                }
                foreach(KeyValuePair<string,object>pair in Obj(row["globals"]))
                {++checks;uint address=Convert.ToUInt32(pair.Key.Substring(2),16);if(m.ReadUInt32(address)!=U(pair.Value))bad.Add(pair.Key);}
                List<string>expected=new List<string>();foreach(object call in Arr(row["calls"]))
                {Dictionary<string,object>c=Obj(call);object[]a=Arr(c["args"]);uint[]v=new uint[a.Length];for(int i=0;i<v.Length;i++)v[i]=U(a[i]);expected.Add(CallKey(Convert.ToUInt32(((string)c["address"]).Substring(2),16),v));}
                ++checks;if(String.Join("|",calls.Trace)!=String.Join("|",expected))bad.Add("call trace");
            }
            catch(Exception e){bad.Add(e.ToString());}
            if(bad.Count!=0){++failures;if(errors.Count<12)errors.Add(new{index,bad});}++index;
        }
        string report=json.Serialize(new{cases=index,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
    }
}
