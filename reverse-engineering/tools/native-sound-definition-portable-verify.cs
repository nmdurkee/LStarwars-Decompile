using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundDefinitionVerify
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
    public const uint D=0x10100000,TABLE=D+0x1000,HEADS=D+0x2000,RECORDS=D+0x4000,BANKS=D+0x20000,BACKUP=D+0x30000,TOKENS=D+0x50000,PARSER=D+0x60000,TEMP=D+0x61000;
    static void Text(SoundSetupImage m,uint a,string value){foreach(char c in value)m.Byte(a++,(byte)c);m.Byte(a,0);}
    public static string Sha(SoundSetupImage m){using(var bytes=new MemoryStream()){foreach(var r in m.Regions)bytes.Write(r.Value,0,r.Value.Length);using(var sha=System.Security.Cryptography.SHA256.Create())return BitConverter.ToString(sha.ComputeHash(bytes.ToArray())).Replace("-","").ToLowerInvariant();}}
    public static SoundSetupImage Setup(Dictionary<string,object> p,Dictionary<string,object> data)
    {
        var m=new SoundSetupImage();int seed=Int(p["seed"]);foreach(object r in Arr(data["regions"])){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        m.Word(0x2947d80,TABLE);object[] table=Arr(data["table"]);for(uint i=0;i<table.Length;i++)m.Word(TABLE+i*4,U(table[i]));m.Word(0x292fda0,HEADS);for(uint i=0;i<256;i++)m.Half(HEADS+i*2,unchecked((ushort)Int(p["head"])));
        m.Word(0x2947b74,RECORDS);m.Word(0x292fda4,BACKUP);m.Word(0x2947d70,BANKS);m.Word(0x296201c,U(p["index"]));object[] names=Arr(p["bankNames"]);m.Word(0x2962014,(uint)names.Length);m.Word(0x2962018,U(p["nameCount"]));m.Word(0x296202c,U(p["builtinCount"]));m.Word(RECORDS+U(p["index"])*64+4,U(p["flags"]));m.Word(PARSER+0x510,TOKENS);Text(m,TOKENS,"");
        for(uint i=0;i<names.Length;i++){m.Word(BANKS+i*28,0x2948f10+i*64);Text(m,0x2948f10+i*64,(string)names[i]);m.Word(0x2921888+i*4,unchecked(0xfffffffe+i));}return m;
    }
    public sealed class Reader:ISoundDefinitionTokens
    {
        readonly SoundSetupImage m;readonly object[] tokens;int index=-1;public readonly List<object> Events=new List<object>();
        public Reader(SoundSetupImage image,object[] input){m=image;tokens=input;}
        Dictionary<string,object> Take(string kind)
        {
            index++;Dictionary<string,object> t=index<tokens.Length?Obj(tokens[index]):new Dictionary<string,object>{{"text",""},{"integer",0},{"real",0}};uint at=TOKENS+(uint)index*256;Text(m,at,(string)t["text"]);m.Word(PARSER+0x510,at);Events.Add(new object[]{kind,index,t["text"]});return t;
        }
        public bool ReadNext(){Take("next");return index<tokens.Length;}
        public string Current {get{return SoundDefinitionParser.Text(m,m.Word(PARSER+0x510));}}
        public void Append(string suffix){Text(m,m.Word(PARSER+0x510),Current+suffix);}
        public int ReadInteger(){return Int(Take("integer")["integer"]);}
        public float ReadFloat(){uint word=U(Take("real")["real"]);m.Word(TEMP,word);return BitConverter.ToSingle(BitConverter.GetBytes(word),0);}
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);try{var p=Obj(v["input"]);var m=Setup(p,data);var reader=new Reader(m,Arr(p["tokens"]));SoundDefinitionParser.Parse(m,reader);string got=Sha(m);checks++;if(got!=(string)v["nativeSha"]||!Equal(json.DeserializeObject(json.Serialize(reader.Events)),v["events"])){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],events=reader.Events});}}
            catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
