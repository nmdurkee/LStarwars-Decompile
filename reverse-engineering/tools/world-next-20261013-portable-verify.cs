using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldNext20261013Verify
{
    const uint D=0x10100000,World=D,Parser=D+0x6000,Buffer=D+0x7000,Line=D+0x8000,Token=D+0x9000,Text=D+0xe000,Arena=D+0x10000,Scene=D+0x20000,Display=D+0x21000,Static=D+0x23000,Dynamic=D+0x24000,Names=D+0x26000,Handle=0x12345678;
    static Dictionary<string,object> Obj(object v){return(Dictionary<string,object>)v;}
    static object[] Arr(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static void CString(SoundSetupImage m,uint a,string s){byte[] b=Encoding.GetEncoding(28591).GetBytes(s);for(int i=0;i<b.Length;i++)m.Byte(a+(uint)i,b[i]);m.Byte(a+(uint)b.Length,0);}
    static string Key(uint a,params uint[]args){string k="0x"+a.ToString("x");foreach(uint v in args)k+=":"+v.ToString();return k;}
    static string Hash(SoundSetupImage m)
    {
        byte[]b=new byte[0x30004];Array.Copy(m.Regions[0x88ab4c],0,b,0,4);Array.Copy(m.Regions[D],0,b,4,0x30000);
        using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(b)).Replace("-","").ToLowerInvariant();
    }
    static SoundSetupImage Setup(Dictionary<string,object>p)
    {
        SoundSetupImage m=new SoundSetupImage();m.Regions.Add(0x88ab4c,new byte[4]);m.Regions.Add(D,new byte[0x30000]);for(int i=0;i<0x30000;i++)m.Regions[D][i]=0x6d;
        m.Word(0x88ab4c,0x17);m.Word(World+0x104,Arena+(uint)I(p["cursorOffset"]));m.Word(World+0x108,Arena+0x4000);m.Word(World+0x13c,Bool(p["scene"])?Scene:0);m.Word(World+0x5048,0xdeadbeef);m.Word(World+0x504c,0x7fffffff);
        m.Zero(Parser,0x584);m.Word(Parser,Buffer);m.Word(Parser+4,Handle);m.Word(Parser+0x50c,Line);m.Word(Parser+0x510,Token);m.Word(Parser+0x514,4096);m.Word(Parser+0x518,512);m.Word(Parser+0x51c,uint.MaxValue);m.Word(Parser+0x52c,uint.MaxValue);m.Word(Parser+0x574,(uint)((string)p["text"]).Length);m.Word(Parser+0x570,uint.MaxValue);
        m.Zero(Scene,0x114);m.Word(Scene+0x110,Bool(p["dynamic"])?Display:0);m.Word(Scene+0x24,(uint)Arr(p["names"]).Length);m.Word(Scene+0x28,Static);m.Zero(Display,0x74);m.Word(Display+0x6c,(uint)Arr(p["names"]).Length);m.Word(Display+0x70,Dynamic);
        object[]names=Arr(p["names"]);for(int i=0;i<names.Length;i++){CString(m,Names+(uint)i*0x100,(string)names[i]);m.Word(Static+(uint)i*0x4c+0x44,Names+(uint)i*0x100);m.Word(Dynamic+(uint)i*0xd0+0xb4,Names+(uint)i*0x100);}
        if((string)p["kind"]=="Reset")
        {
            uint pointer=Arena+(uint)I(p["cursorOffset"]);m.Word(World+0x5048,Bool(p["tablePresent"])?pointer:0);m.Word(World+0x504c,unchecked((uint)I(p["resetCount"])));
            for(int i=0;i<I(p["resetCount"]);i++)m.Half(pointer+(uint)i*16+12,(ushort)I(p["resetFlags"]));
        }
        return m;
    }
    public static int Main(string[]args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object>data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        int index=0,checks=0,failures=0;List<object>errors=new List<object>();
        foreach(object value in Arr(data["cases"]))
        {
            Dictionary<string,object>row=Obj(value),p=Obj(row["input"]);List<string>bad=new List<string>();
            try
            {
                SoundSetupImage m=Setup(p);List<string>calls=new List<string>(),events=new List<string>();byte[]text=Encoding.GetEncoding(28591).GetBytes((string)p["text"]);int position=0;
                CameraScene scene=new CameraScene{Dynamic=Bool(p["dynamic"])};foreach(object name in Arr(p["names"]))scene.Objects.Add(new CameraSceneObject{Name=(string)name});
                if((string)p["kind"]=="Reset")PortalDoorTable.ResetTransitionFlags(m,World);
                else PortalDoorTable.Load(m,World,Text,
                    (name,source,size)=>{calls.Add(Key(0x4fc900,source,(uint)size)+":"+name);return Bool(p["open"])?Parser:0;},
                    (memory,handle,buffer,requested)=>
                    {
                        int count=Math.Min(requested,Math.Min(I(p["chunk"]),Math.Max(0,text.Length-position)));if(position>=I(p["failAfter"]))count=0;
                        for(int i=0;i<count;i++)memory.Byte(buffer+(uint)i,text[position+i]);events.Add(Key(handle,buffer,(uint)requested,(uint)position,(uint)count));position+=count;return count;
                    },
                    (memory,parser)=>{calls.Add(Key(0x4fa300,parser));memory.Word(parser,0);},
                    (memory,sceneAddress,output,name)=>
                    {
                        CameraSceneReference reference=new CameraSceneReference();bool result=CameraSceneLookup.Find(scene,reference,name);
                        if(!result){memory.Zero(output,12);return false;}
                        CameraSceneObject item=reference.Dynamic??reference.Static;int objectIndex=scene.Objects.IndexOf(item);memory.Word(output,Scene);memory.Word(output+4,reference.Static==null?0:Static+(uint)objectIndex*0x4c);memory.Word(output+8,reference.Dynamic==null?0:Dynamic+(uint)objectIndex*0xd0);return true;
                    });
                ++checks;if(Hash(m)!=(string)row["nativeSha"])bad.Add("full memory");
                ++checks;if(m.Word(World+0x504c)!=U(row["count"]))bad.Add("count");++checks;if(m.Word(World+0x5048)!=U(row["table"]))bad.Add("table");++checks;if(m.Word(World+0x104)!=U(row["cursor"]))bad.Add("cursor");
                List<string>wantCalls=new List<string>();foreach(object v in Arr(row["calls"]))
                {Dictionary<string,object>c=Obj(v);object[]a=Arr(c["args"]);uint[]a2=new uint[a.Length];for(int i=0;i<a.Length;i++)a2[i]=U(a[i]);string k=Key(Convert.ToUInt32(((string)c["address"]).Substring(2),16),a2);if(c.ContainsKey("name"))k+=":"+(string)c["name"];wantCalls.Add(k);}
                ++checks;if(String.Join("|",calls)!=String.Join("|",wantCalls))bad.Add("lifecycle calls");
                List<string>wantEvents=new List<string>();foreach(object v in Arr(row["events"]))
                {Dictionary<string,object>e=Obj(v);object[]a=Arr(e["args"]);wantEvents.Add(Key(U(a[0]),U(a[1]),U(a[2]),U(e["position"]),U(e["count"])));}
                ++checks;if(String.Join("|",events)!=String.Join("|",wantEvents))bad.Add("file stream");
            }
            catch(Exception e){bad.Add(e.ToString());}
            if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{index,bad});}index++;
        }
        string report=json.Serialize(new{cases=index,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
    }
}
