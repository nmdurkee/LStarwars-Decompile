using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class TextParserDispatchVerify
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
    const uint D=0x10100000,PARSER=D+0x1000,TOKEN=D+0x4000,FIRST=D+0x5000,SECOND=D+0x6000,PRIMARY=D+0x8000,SECONDARY=D+0x8400,NAMES=D+0x9000,WIDE=D+0x10000,OUTPUT=D+0x40000;
    static uint Callback(int i){return D+0xf000+(uint)i*16;}
    static void Bytes(SoundSetupImage m,uint at,object[] values){for(uint i=0;i<values.Length;i++)m.Byte(at+i,(byte)Int(values[i]));m.Byte(at+(uint)values.Length,0);}
    static void Wide(SoundSetupImage m,uint at,object[] values){for(uint i=0;i<values.Length;i++)m.Half(at+i*2,(ushort)Int(values[i]));m.Half(at+(uint)values.Length*2,0);}
    static void Table(SoundSetupImage m,uint table,object[] names,int offset){for(int i=0;i<names.Length;i++){uint ptr=NAMES+(uint)(offset+i)*128;Bytes(m,ptr,Arr(names[i]));m.Word(table+(uint)i*8,ptr);m.Word(table+(uint)i*8+4,Callback(offset+i));}m.Word(table+(uint)names.Length*8,0);}
    static SoundSetupImage Setup(Dictionary<string,object> p,object[] regions)
    {
        var m=new SoundSetupImage();uint seed=U(p["seed"]);foreach(object r in regions){object[] pair=Arr(r);byte[] bytes=new byte[Int(pair[1])];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*7+seed);m.Regions.Add(U(pair[0]),bytes);}
        string kind=(string)p["kind"];if(kind=="compare"){Bytes(m,FIRST,Arr(p["first"]));Bytes(m,SECOND,Arr(p["second"]));}else if(kind=="convert")Wide(m,WIDE,Arr(p["words"]));else
        {
            m.Word(PARSER+0x510,Bool(p["nullToken"])?0:TOKEN);m.Byte(PARSER+0x578,Bool(p["wide"])?(byte)1:(byte)0);m.Word(PARSER+0x570,unchecked((uint)Int(p["depth"])));m.Word(0x91eec4,Bool(p["fallback"])?Callback(7):0);if(Bool(p["wide"]))Wide(m,TOKEN,Arr(p["token"]));else Bytes(m,TOKEN,Arr(p["token"]));
            bool secondary=p["secondary"]!=null&&Arr(p["secondary"]).Length!=0;for(uint depth=0;depth<8;depth++){m.Word(PARSER+0x530+depth*4,PRIMARY);m.Word(PARSER+0x550+depth*4,secondary?SECONDARY:0);}Table(m,PRIMARY,Arr(p["primary"]),0);Table(m,SECONDARY,p["secondary"]==null?new object[0]:Arr(p["secondary"]),3);
        }return m;
    }
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);try
            {
                var m=Setup(p,Arr(data["regions"]));object result=null;var events=new List<object>();string kind=(string)p["kind"];
                if(kind=="compare")result=TextParserDispatch.Compare(m,Bool(p["nullFirst"])?0:FIRST,Bool(p["nullSecond"])?0:SECOND);
                else if(kind=="convert")TextParserDispatch.ToBytes(m,Bool(p["nullTarget"])?0:OUTPUT,Bool(p["nullSource"])?0:WIDE);
                else TextParserDispatch.Dispatch(m,PARSER,delegate(SoundSetupImage image,uint target,uint parser){events.Add(new{target,parser});image.Word(D+0x3000,target);image.Word(parser+0x570,7);image.Byte(TOKEN,33);image.Word(0x91eec4,0);});
                string got=SoundDefinitionVerify.Sha(m);checks++;if(got!=(string)v["nativeSha"]||!Equal(result,v["result"])||!Equal(json.DeserializeObject(json.Serialize(events)),v["events"])){failures++;if(errors.Count<10)errors.Add(new{index,got,want=v["nativeSha"],result,events});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
