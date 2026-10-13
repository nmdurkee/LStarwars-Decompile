using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class SoundGroupsVerify
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
    const uint RNG=0x810364,GROUPS=0x2920d88,MEMBERS=0x2921260;
    static Dictionary<string,object> Defaults(){return new Dictionary<string,object>{{"seed",17},{"index",3},{"bankNames",new object[0]},{"nameCount",0},{"builtinCount",0},{"flags",0},{"head",-1}};}
    static SoundSetupImage Clone(SoundSetupImage m){var c=new SoundSetupImage();foreach(var r in m.Regions)c.Regions.Add(r.Key,(byte[])r.Value.Clone());return c;}
    static int I(Dictionary<string,object> p,string key){return Int(p[key]);}
    static uint A(int value){return unchecked((uint)value);}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;var errors=new List<object>();var json=new JavaScriptSerializer{MaxJsonLength=128*1024*1024};string text;using(var f=File.OpenRead(args[0]))using(var gz=new GZipStream(f,CompressionMode.Decompress))using(var sr=new StreamReader(gz)){text=sr.ReadToEnd();}var data=Obj(json.DeserializeObject(text));SoundSetupImage stream=null;
        foreach(object row in Arr(data["cases"]))
        {
            var v=Obj(row);var p=Obj(v["input"]);string kind=(string)v["kind"];try
            {
                SoundSetupImage m;object result=null;SoundDefinitionVerify.Reader reader=null;
                if(kind=="helper")
                {
                    m=SoundDefinitionVerify.Setup(Defaults(),data);m.Word(RNG,U(p["seed"]));m.Word(0x2962024,U(p["groupCount"]));m.Word(0x2962020,U(p["memberCount"]));uint g=GROUPS+U(p["group"])*8;m.Half(g,unchecked((ushort)I(p,"start")));m.Half(g+2,unchecked((ushort)I(p,"count")));m.Half(g+4,unchecked((ushort)I(p,"cursor")));int[] values={-32768,-1,0,3,32767};for(int i=-8;i<80;i++)m.Half(unchecked(MEMBERS+(uint)(i*2)),unchecked((ushort)values[(i+8)%5]));
                    switch((string)p["kind"])
                    {
                        case "create":result=SoundGroups.Create(m,I(p,"sound"));break;
                        case "contains":result=SoundGroups.Contains(m,I(p,"group"),I(p,"sound"));break;
                        case "select":result=SoundGroups.Select(m,I(p,"group"),I(p,"sequential"));break;
                        case "count":result=SoundGroups.Count(m,I(p,"group"));break;
                        case "at":result=SoundGroups.At(m,I(p,"group"),I(p,"ordinal"));break;
                        case "random":uint seed=m.Word(RNG);result=SoundGroups.StepRandom(ref seed);m.Word(RNG,seed);break;
                    }
                }
                else
                {
                    if(stream==null){stream=SoundDefinitionVerify.Setup(Obj(data["streamInitial"]),data);stream.Zero(SoundDefinitionVerify.RECORDS,0x19000);stream.Zero(SoundDefinitionVerify.BACKUP,0x19000);stream.Zero(SoundDefinitionVerify.BANKS,0xaf00);stream.Word(0x2962024,0);stream.Word(0x2962020,0);stream.Word(RNG,1);}
                    m=kind=="parse"?Clone(stream):stream;if(kind=="parse"){m.Word(0x2962024,U(p["groupCount"]));m.Word(0x2962020,U(p["memberCount"]));}
                    reader=new SoundDefinitionVerify.Reader(m,Arr(p["tokens"]));if(kind=="stream-sample")SoundDefinitionParser.Parse(m,reader);else SoundGroups.Parse(m,reader);
                }
                string got=SoundDefinitionVerify.Sha(m);checks++;bool bad=got!=(string)v["nativeSha"];
                if(kind=="helper")bad|=!Equal(result,p["result"]);else bad|=!Equal(json.DeserializeObject(json.Serialize(reader.Events)),v["events"]);
                if(bad){failures++;if(errors.Count<10)errors.Add(new{index,kind,result,got,want=v["nativeSha"]});}
            }catch(Exception e){failures++;if(errors.Count<10)errors.Add(new{index,kind,error=e.ToString()});}index++;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"],note="Native repeated lookup observations belong to native evidence; portable behavior replays state and token events."});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
