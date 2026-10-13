using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class TextParserLinesVerify
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
    const uint D=0x10100000,PARSER=D+0x1000,BUFFER=D+0x2000,LINE=D+0x4000,HANDLE=0x12345678;
    static void Text(SoundSetupImage m,uint a,string value){foreach(char c in value)m.Byte(a++,(byte)c);m.Byte(a,0);}
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        var m=new SoundSetupImage();uint seed=U(p["seed"]);foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        m.Word(PARSER,BUFFER);m.Word(PARSER+4,HANDLE);m.Word(PARSER+0x50c,LINE);m.Word(PARSER+0x514,U(p["capacity"]));m.Word(PARSER+0x51c,U(p["lineNumber"]));m.Word(PARSER+0x520,99);m.Word(PARSER+0x524,0);m.Word(PARSER+0x528,0);m.Word(PARSER+0x52c,0xffffffff);m.Word(PARSER+0x574,(uint)((string)p["text"]).Length);m.Byte(PARSER+0x578,(byte)Int(p["binary"]));return m;
    }
    sealed class Services
    {
        readonly Dictionary<string,object> p;readonly string text;int position;public int BinaryCalls;public readonly List<object> Events=new List<object>();public Services(Dictionary<string,object> input){p=input;text=(string)p["text"];}
        public int Read(SoundSetupImage m,uint handle,uint buffer,int requested)
        {
            if(handle!=HANDLE||buffer!=BUFFER||requested<0||requested>4096)throw new Exception("File request backing");int count=Math.Min(Math.Min(requested,Int(p["chunk"])),Math.Max(0,text.Length-position));if(position>=Int(p["failAfter"]))count=0;for(int i=0;i<count;i++)m.Byte(buffer+(uint)i,(byte)text[position+i]);Events.Add(new{args=new uint[]{handle,buffer,(uint)requested},position,count});position+=count;return count;
        }
        public uint Binary(SoundSetupImage m,uint parser){if(parser!=PARSER)throw new Exception("Parser address");BinaryCalls++;m.Word(PARSER+0x51c,unchecked(m.Word(PARSER+0x51c)+3));Text(m,LINE,"binary");return 0xabcdef12;}
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));var services=new Services(p);var results=new List<object>();foreach(object ignored in Arr(v["results"]))
                {
                    if((string)p["kind"]=="bytes")results.Add(TextParserLines.ReadByte(m,PARSER,services.Read));else{uint result=TextParserLines.Next(m,PARSER,services.Read,services.Binary);results.Add(new{result,sha=SoundDefinitionVerify.Sha(m)});}
                }
                string got=SoundDefinitionVerify.Sha(m);checks++;bool bad=got!=(string)v["nativeSha"]||services.BinaryCalls!=Int(v["binaryCalls"])||!Equal(json.DeserializeObject(json.Serialize(results)),v["results"])||!Equal(json.DeserializeObject(json.Serialize(services.Events)),v["events"]);if(bad){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events=services.Events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
