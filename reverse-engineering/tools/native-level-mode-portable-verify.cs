using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class LevelModeConditionsVerify
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
    static MissionModeState Mission(object enabled,object handle){uint h=U(handle);return new MissionModeState{Enabled1d=(byte)Int(enabled),Mission4=h==0?null:(object)h};}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row),o=Obj(v["options"]);object[] ids=Arr(o["levelIds"]);LevelModeWorld world=new LevelModeWorld{CurrentMission=Bool(o["current"])?Mission(o["currentEnabled"],o["currentMission"]):null,MiniCut855de0=Int(o["mini"]),SecondaryMiniCut9514e4=Int(o["secondaryMini"]),HubArea87b460=unchecked((short)Int(o["hub"])),ChapterPresent=Bool(o["chapter"]),ChapterCount=(byte)Int(o["count"]),ChapterLevelIds=new short[ids.Length]};for(int i=0;i<ids.Length;i++)world.ChapterLevelIds[i]=(short)Int(ids[i]);foreach(object name in Arr(o["levelNames"]))world.LevelNames.Add((string)name);foreach(object flags in Arr(o["visited"]))world.VisitedFlags.Add(U(flags));
            try
            {
                string kind=(string)v["kind"];object got;
                if(kind=="ResolveMission"){object result=LevelModeConditions.ResolveMission(world,Bool(o["explicit"])?Mission(o["explicitEnabled"],o["explicitMission"]):null);got=result==null?0u:U(result);}
                else if(kind=="MissionMode")got=Bits(LevelModeConditions.MissionMode(world));
                else if(kind=="InMiniCut")got=Bits(LevelModeConditions.InMiniCut(world,Bool(o["fourth"])));
                else if(kind=="BindHubArea")got=LevelModeConditions.BindHubArea((string)o["name"]);
                else if(kind=="InHubArea")got=Bits(LevelModeConditions.InHubArea(world,Int(o["bound"])));
                else if(kind=="BindVisitedLevel")got=LevelModeConditions.BindVisitedLevel(world,Bool(o["system"]),(string)o["name"]);
                else got=Bits(LevelModeConditions.BeenToLevel(world,Int(o["bound"])));
                ++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
