using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;

public class RunSpeedVerify
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
    static float[] Floats(object v){if(v==null)return null;object[] a=Arr(v);float[] f=new float[a.Length];for(int i=0;i<a.Length;i++)f[i]=Convert.ToSingle(a[i]);return f;}
    static float F(object bits){return BitConverter.ToSingle(BitConverter.GetBytes(U(bits)),0);}
    static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
    public static int Main(string[] args)
    {
        int checks=0,failures=0,index=0;List<object> errors=new List<object>();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=Obj(json.DeserializeObject(File.ReadAllText(args[0])));
        foreach(object row in Arr(data["cases"]))
        {
            Dictionary<string,object> v=Obj(row);
            try
            {
                if((string)v["kind"]=="helper")
                {
                    object[] b=Arr(v["valueBits"]);uint got=Bits(RunSpeedCommands.Seek(F(b[0]),F(b[1]),F(b[2]),F(b[3])));++checks;if(!Equal(got,v["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=v["native"]});}
                }
                else
                {
                    Dictionary<string,object> c=Obj(v["context"]),input=Obj(v["inputBits"]);object[] defs=Arr(input["defaults"]),speeds=Arr(input["speeds"]),raw=Arr(v["tokens"]);RunSpeedActor[] actors=new RunSpeedActor[8];for(int i=0;i<8;i++)actors[i]=new RunSpeedActor{DefaultSpeed=F(defs[i]),OverrideSpeed=F(speeds[i])};
                    string[] tokens=new string[raw.Length];for(int i=0;i<raw.Length;i++)tokens[i]=(string)raw[i];ScriptPacket numbers=new ScriptPacket{Script=new ScriptDefinition()};string[] names={"alpha","beta","gamma","delta"};float[] values={2.75f,1.5f,3,4};for(int i=0;i<4;i++){numbers.Parameters[i]=values[i];numbers.Script.ParameterNames[i]=names[i];}
                    RunSpeedPacket packet=new RunSpeedPacket{Numbers=numbers,SeekRate=F(input["rate"]),TargetSpeed=F(input["goal"])};
                    int reference=Bool(c["creature"])?Int(c["reference"]):-1,target=reference<0?-1:Int(Obj(Arr(c["actors"])[reference])["world"]);
                    foreach(object h in Arr(v["history"]))
                    {
                        Dictionary<string,object> tick=Obj(h);int result=RunSpeedCommands.Set(target<0?null:actors[target],packet,actors[Int(c["primary"])].DefaultSpeed,tokens,Bool(tick["first"]),F(input["delta"]));uint[] output=new uint[8];for(int i=0;i<8;i++)output[i]=Bits(actors[i].OverrideSpeed);
                        object got=new Dictionary<string,object>{{"result",result},{"speeds",output},{"rate",Bits(packet.SeekRate)},{"goal",Bits(packet.TargetSpeed)}};++checks;if(!Equal(got,tick["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=tick["native"]});}
                    }
                }
            }
            catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});}++index;
        }
        string outputJson=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],outputJson);Console.WriteLine(outputJson);return failures==0?0:1;
    }
}
