using System;
using System.IO;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public class WorldPhase320261013Verify
{
    const uint D=0x10100000,World=D,Entries=D+0x6000,Scene=D+0x20000,Special=D+0x21000,Matrix=D+0x22000,State=D+0x23000,Dynamic=D+0x24000,Clips=D+0x25000,Clip=D+0x26000,Portals=D+0x28000,OtherScene=D+0x30000,OtherPortals=D+0x31000,Output=D+0x3f000;
    static Dictionary<string,object> Obj(object v){return(Dictionary<string,object>)v;}
    static object[] Arr(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static bool Bool(object v){return Convert.ToBoolean(v);}
    static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    static string Key(uint a,int id,int mode){return "0x5d9060:"+a+":"+unchecked((uint)id)+":"+unchecked((uint)mode);}
    static string Hash(SoundSetupImage m){using(SHA256 s=SHA256.Create())return BitConverter.ToString(s.ComputeHash(m.Regions[D])).Replace("-","").ToLowerInvariant();}
    static SoundSetupImage Setup(Dictionary<string,object>p)
    {
        SoundSetupImage m=new SoundSetupImage();m.Regions.Add(D,new byte[0x40000]);for(int i=0;i<0x40000;i++)m.Regions[D][i]=0x6d;
        m.Word(World+0x5048,Bool(p["tablePresent"])?Entries:0);m.Word(World+0x504c,unchecked((uint)I(p["doorCount"])));m.Word(World+0x13c,Bool(p["worldSceneOther"])?OtherScene:Scene);
        object[]ids=Arr(p["portalIds"]),flags=Arr(p["portalFlags"]);
        for(int s=0;s<2;s++)
        {
            uint scene=s==0?Scene:OtherScene,portals=s==0?Portals:OtherPortals;
            m.Word(scene+0x54,Clips);m.Word(scene+0x6c,U(p["portalCount"]));m.Word(scene+0x70,portals);
            for(int i=0;i<ids.Length;i++){m.Byte(portals+(uint)i*32+0x1a,unchecked((byte)I(ids[i])));m.Word(portals+(uint)i*32+0x1c,U(flags[i]));}
        }
        m.Word(Clips+U(p["clipIndex"])*4,Clip);m.Word(Clip,U(p["header"]));m.Half(Clip+0x16,(ushort)I(p["override"]));m.Half(Clip+0x0a,(ushort)I(p["wordA"]));m.Half(Clip+0x0e,(ushort)I(p["wordB"]));
        string kind=(string)p["refKind"];
        for(int i=0;i<Math.Max(0,I(p["doorCount"]));i++)
        {
            uint entry=Entries+(uint)i*16,normal=Special+(uint)i*0x80,matrix=Matrix+(uint)i*0x80,state=State+(uint)i*0x80,dynamic=Dynamic+(uint)i*0xd0;
            m.Word(entry,Scene);m.Word(entry+4,kind=="static"||kind=="both"||kind=="static-zero"?normal:0);m.Word(entry+8,kind=="dynamic"||kind=="both"||kind=="dynamic-zero"||kind=="dynamic-minus1"?dynamic:0);
            m.Half(entry+12,(ushort)(i%2==0?I(p["flags"]):I(p["flags"])^1));m.Byte(entry+14,unchecked((byte)(i%2==0?I(p["id"]):I(p["id"])+1)));
            m.Word(normal+0x40,matrix);m.Word(matrix+0x48,kind=="static-zero"?0:state);m.Word(dynamic+0xc4,kind=="dynamic-zero"?0:kind=="dynamic-minus1"?uint.MaxValue:state);
            m.Word(state+0x4c,U(Arr(p["timesBits"])[0]));m.Half(state+0x5c,(ushort)I(p["clipIndex"]));
        }
        return m;
    }
    public static int Main(string[]args)
    {
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object>data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        int cases=0,steps=0,checks=0,failures=0;List<object>errors=new List<object>();
        foreach(object value in Arr(data["cases"]))
        {
            Dictionary<string,object>row=Obj(value),p=Obj(row["options"]);SoundSetupImage m=Setup(p);object[]snapshots=Arr(row["snapshots"]);string kind=(string)p["kind"];
            for(int step=0;step<snapshots.Length;step++)
            {
                Dictionary<string,object>snapshot=Obj(snapshots[step]);List<string>trace=new List<string>(),bad=new List<string>();
                try
                {
                    if(kind=="Update")
                    {
                        uint time=U(Arr(p["timesBits"])[step]);for(int i=0;i<Math.Max(0,I(p["doorCount"]));i++)m.Word(State+(uint)i*0x80+0x4c,time);
                        PortalDoorRuntime.Update(m,World,(scene,id,mode)=>trace.Add(Key(scene,id,mode)));
                    }
                    else if(kind=="Mutate")PortalDoorRuntime.SetPortalState(m,Scene,I(p["targetId"]),I(p["mode"]),(scene,id,mode)=>trace.Add(Key(scene,id,mode)));
                    else{uint result=Bits(PortalDoorRuntime.DurationValue(m,Clip));m.Word(Output,result);++checks;if(result!=U(snapshot["durationBits"]))bad.Add("duration bits");}
                    ++checks;if(Hash(m)!=(string)snapshot["nativeSha"])bad.Add("complete memory");
                    List<string>want=new List<string>();foreach(object call in Arr(snapshot["calls"]))
                    {object[]a=Arr(Obj(call)["args"]);want.Add(Key(U(a[0]),unchecked((int)U(a[1])),unchecked((int)U(a[2]))));}
                    ++checks;if(String.Join("|",trace)!=String.Join("|",want))bad.Add("actual mutation trace");
                }
                catch(Exception e){bad.Add(e.ToString());}
                if(bad.Count!=0){failures++;if(errors.Count<12)errors.Add(new{cases,step,bad});}steps++;
            }
            cases++;
        }
        string report=json.Serialize(new{cases,nativeSteps=steps,checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],report);Console.WriteLine(report);return failures==0?0:1;
    }
}
