using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class TextParserNumbersVerify
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
    const uint D=0x10100000,PARSER=D+0x1000,LINE=D+0x2000,TOKEN=D+0x4000,SEPARATORS=D+0x5000,SINGLES=D+0x5100,TEXT=D+0x7000,RESULT=D+0x8000;
    static void Text(SoundSetupImage m,uint a,string value){foreach(char c in value)m.Byte(a++,(byte)c);m.Byte(a,0);}
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        var m=new SoundSetupImage();uint seed=U(p["seed"]);foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        Text(m,LINE,(string)p["line"]);Text(m,TEXT,(string)p["text"]);m.Word(PARSER+0x50c,LINE);m.Word(PARSER+0x510,TOKEN);m.Word(PARSER+0x514,4096);m.Word(PARSER+0x518,128);m.Word(PARSER+0x520,0);m.Byte(PARSER+0x578,0);m.Word(PARSER+0x570,0xffffffff);m.Word(PARSER+0x57c,0);m.Word(PARSER+0x580,0);Text(m,SEPARATORS,"");Text(m,SINGLES,"");return m;
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));uint result;string kind=(string)p["kind"],input=(string)p["text"];
                if(kind=="decimal")result=unchecked((uint)TextParserNumbers.Decimal(input));else if(kind=="hex")result=TextParserNumbers.Hexadecimal(input);else if(kind=="real")result=Bits(TextParserNumbers.Real(input));else if(kind=="read-int")result=unchecked((uint)TextParserNumbers.ReadInteger(m,PARSER,null));else result=Bits(TextParserNumbers.ReadReal(m,PARSER,null));
                if(kind=="real"||kind=="read-real")m.Word(RESULT,result);string got=SoundDefinitionVerify.Sha(m);checks++;if(got!=(string)v["nativeSha"]||result!=U(v["result"])){failures++;if(errors.Count<10)errors.Add(new{index,kind,got,want=v["nativeSha"],result,wantResult=v["result"]});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
