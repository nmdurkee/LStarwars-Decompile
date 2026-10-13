using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundInitializationVerify
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
    const uint D=0x10100000,CURSOR=D+0x1000,BUILTIN=D+0x4000,NAMES=D+0x8000,PATH=D+0x9000;
    static void Text(SoundSetupImage m,uint a,string value){foreach(char c in value)m.Byte(a++,(byte)c);m.Byte(a,0);}
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        SoundSetupImage m=new SoundSetupImage();uint seed=U(p["seed"]);
        foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        m.Word(CURSOR,D+0x10000+U(p["alignment"]));m.Word(0x2962044,unchecked((uint)Int(p["initialized"])));m.Word(0x2947d80,D+0x2000);m.Word(0x2962028,BUILTIN);m.Word(0x296202c,unchecked((uint)Int(p["builtinCount"])));m.Word(0x2962018,U(p["nameCount"]));Text(m,PATH,(string)p["path"]);
        object[] names=Arr(p["names"]);for(uint i=0;i<names.Length;i++){for(uint j=0;j<7;j++)m.Word(BUILTIN+i*28+j*4,unchecked(seed*0x10001+i*97+j*131));m.Word(BUILTIN+i*28,NAMES+i*64);Text(m,NAMES+i*64,(string)names[i]);}
        return m;
    }
    static string Sha(SoundSetupImage m){using(var bytes=new MemoryStream()){foreach(var r in m.Regions)bytes.Write(r.Value,0,r.Value.Length);using(var sha=System.Security.Cryptography.SHA256.Create())return BitConverter.ToString(sha.ComputeHash(bytes.ToArray())).Replace("-","").ToLowerInvariant();}}
    static void Service(SoundSetupImage m,Dictionary<string,object> p)
    {
        m.Word(CURSOR,unchecked(m.Word(CURSOR)+U(p["advance"])));m.Word(0x2962014,unchecked(m.Word(0x2962014)+2));m.Word(0x2962018,unchecked(m.Word(0x2962018)+3));m.Word(0x296201c,unchecked((uint)Int(p["soundCount"])));
        for(uint i=0;i<200;i++){m.Byte(0x2921760+i,255);m.Byte(0x2947ca8+i,238);}if(Bool(p["redirect"]))m.Word(0x2947b74,D+0x50000);
        uint records=m.Word(0x2947b74);object[] flags=Arr(p["flags"]);for(uint i=0;i<flags.Length;i++)m.Word(records+i*64+4,U(flags[i]));m.Word(D+0x70000,0xcafebabe);
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;string text;
        using(FileStream f=File.OpenRead(args[0]))using(GZipStream gz=new GZipStream(f,CompressionMode.Decompress))using(StreamReader sr=new StreamReader(gz)){text=sr.ReadToEnd();}Dictionary<string,object> data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));int calls=0;string entry=null;
                SoundInitialization.Initialize(m,CURSOR,0xaabbccdd,PATH,delegate(SoundSetupImage image,uint file,uint cursor,uint opaque){calls++;if(file!=PATH||cursor!=CURSOR||opaque!=0xaabbccdd)throw new Exception("Service argument mismatch");entry=Sha(image);Service(image,p);});
                string final=Sha(m);checks++;if(calls!=1||entry!=(string)v["entrySha"]||final!=(string)v["finalSha"]){failures++;if(errors.Count<10)errors.Add(new{index,calls,entry,final,wantEntry=v["entrySha"],wantFinal=v["finalSha"]});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
