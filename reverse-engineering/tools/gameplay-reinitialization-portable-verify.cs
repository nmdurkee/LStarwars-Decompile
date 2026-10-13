using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;

// fixtureJSON, original sine-table f32 file, outputJSON. Compile only until
// ordinary managed execution is available; no alternate execution host.
public class GameplayReinitializationVerify
{
    const uint A=0x10100000,SYS=A+0x2000,CHAR=A+0x6000,MODEL=A+0x8000,SPAWN=A+0xa000,LOC=A+0xc000,FORM=A+0x10000,PATH=A+0x20000;
    static int checks,failures;
    static List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static int I(object v){return Convert.ToInt32(v);}
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?I(o[k]):d;}
    static uint Opt(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?U(o[k]):d;}
    static bool Opt(Dictionary<string,object> o,string k,bool d){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):d;}
    static float Opt(Dictionary<string,object> o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Check(object got,object want,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<15)errors.Add(new{index,got,want});}}
    static byte[] Pattern(int size,int seed){byte[] b=new byte[size];for(int i=0;i<size;i++)b[i]=(byte)(i*37+seed*11);return b;}
    static void Put(byte[] b,int at,uint value,int size){for(int i=0;i<size;i++)b[at+i]=(byte)(value>>(i*8));}
    static uint Bits(float f){return PcObjectImage.ToBits(f);}
    static uint[] Probe(PcObjectImage a){return new uint[]{a.U32(0x5c),a.U32(0x4b0),a.U8(0x406),a.U32(0x420)};}
    sealed class Services:ActorReinitializationServices
    {
        public Dictionary<string,object> Options;public List<object> Events=new List<object>();
        public override void Invoke(ReinitializationOperation op,ActorReinitializationWorld w,PcObjectImage a,params uint[] arguments)
        {
            Events.Add(new object[]{op.ToString(),arguments,Probe(a)});
            if(Options.ContainsKey("effects"))foreach(object e in Arr(Options["effects"]))
            {Dictionary<string,object> v=Obj(e);if((string)v["operation"]==op.ToString())Put(a.Bytes,I(v["offset"]),U(v["value"]),Opt(v,"size",4));}
        }
    }
    static ActorReinitializationWorld Setup(Dictionary<string,object> o,float[] sine,out PcObjectImage a,out Services services)
    {
        services=new Services{Options=o};ActorReinitializationWorld w=new ActorReinitializationWorld{ActorIdentity=A,ScriptSystemIdentity=SYS,SceneIdentity=0x24681357,Services=services,Sine=sine};
        int seed=Opt(o,"seed",1);a=new PcObjectImage(Pattern(0x10d8,seed));
        a.Set32(0x50,MODEL);a.Set32(0x54,CHAR);a.Set32(0x478,Opt(o,"locator",false)?LOC:0);a.Set32(0x40c,Opt(o,"formation",false)?FORM:0);
        a.Set32(0x4c4,Opt(o,"count",0u));a.Set32(0x420,Opt(o,"samePath",false)?PATH:0);a.Set32(0x3f8,Opt(o,"maskLow",0xa5a5a5a5u));a.Set32(0x3fc,Opt(o,"maskHigh",0x80000001u));
        a.Set8(0x400,Opt(o,"spawn",0));a.Set8(0x410,Opt(o,"slot",0));a.Set8(0x411,Opt(o,"column",0));a.Set8(0x412,Opt(o,"row",0));a.Set8(0x281,Opt(o,"ground",0));
        a.Set16(0xe1c,Opt(o,"accessoryState",17));a.Set32(0xe24,Opt(o,"accessoryFlags",0x12340000u));a.SetFloat(0x5c,20);a.SetFloat(0x60,30);a.SetFloat(0x64,40);
        w.Formations.Add(FORM,new ReinitializationRecord(FORM,Pattern(0x54+256*0x34,seed+3)));w.Spawns=new ReinitializationRecord[3];
        for(int i=0;i<3;i++)
        {
            ReinitializationRecord s=new ReinitializationRecord(SPAWN+(uint)(i*0xa4),Pattern(0xa4,4+i));w.Spawns[i]=s;s.Set8(0x4c,3+i);s.Set8(0x48,Opt(o,"spawnFlags",i&1));s.Set8(0x51,Opt(o,"columns",3));
            float[] pos=new float[]{1.25f+i,-2.5f-i,3.75f+i};if(o.ContainsKey("position")){object[] v=Arr(o["position"]);for(int j=0;j<3;j++)pos[j]=Convert.ToSingle(v[j]);}
            for(int j=0;j<3;j++)s.Set32(0x20+j*4,Bits(pos[j]));s.Set32(0x2c,Opt(o,"angle",0x2345u));s.Set32(0x5c,Bits(Opt(o,"spacing",1.25f)));s.Set32(0x60,Bits(Opt(o,"rowSpacing",2.75f)));
            s.Set32(0x30,Opt(o,"nullPath",false)?0:PATH);s.Set32(0x34,0x12345600u+(uint)i);s.Set8(0x38,7+i);for(int j=0;j<4;j++)s.Set32(0x94+4*j,Bits(i+j+.125f));
        }
        ReinitializationRecord loc=new ReinitializationRecord(LOC,Pattern(0x3c,9));w.Locators.Add(LOC,loc);loc.Set32(0x10,Bits(19.5f));loc.Set32(0x14,Bits(23.25f));loc.Set32(0x18,Bits(-17.75f));loc.Set32(0x1c,Opt(o,"locatorAngle",0xdeadbeefu));loc.Set32(0x20,Opt(o,"nullPath",false)?0:PATH);loc.Set32(0x24,0x87654321);loc.Set8(0x28,254);
        ulong[] masks=new ulong[]{0,1,0x100000000,0x8000000000000000,0x400,0xffffffffffffffff};
        if(o.ContainsKey("masks")){object[] v=Arr(o["masks"]);masks=new ulong[v.Length];for(int i=0;i<v.Length;i++)masks[i]=v[i] is string?Convert.ToUInt64((string)v[i],16):Convert.ToUInt64(v[i]);}
        w.PathSets.Add(PATH,new ReinitializationPathSet{MembershipMasks=masks});w.Characters.Add(CHAR,new ReinitializationCharacter{Flags04=Opt(o,"characterFlags",0u),Callback18=Opt(o,"callback",0u),AccessoryE8=(short)Opt(o,"accessory",-1),AccessoryMagnitude11e=(byte)Opt(o,"magnitude",9),TuningF4=33,TuningF5=44});w.ModelHasAnimation65.Add(MODEL,Opt(o,"clip",false));
        w.LastSpawnOrigin[0]=0xaaaa0001;w.LastSpawnOrigin[1]=0xbbbb0002;w.LastSpawnOrigin[2]=0xcccc0003;
        if(o.ContainsKey("reset")){object[] v=Arr(o["reset"]);for(int i=0;i<3;i++)w.ResetVector[i]=Bits(Convert.ToSingle(v[i]));}
        return w;
    }
    static List<object> Changes(byte[] a,byte[] b)
    {
        List<object> result=new List<object>();int i=0;
        while(i<a.Length){if(a[i]==b[i]){++i;continue;}int j=i+1;while(j<a.Length&&a[j]!=b[j])++j;string hex="";for(int k=i;k<j;k++)hex+=b[k].ToString("x2");result.Add(new object[]{i,hex});i=j;}return result;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("fixture JSON, sine f32, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));byte[] table=File.ReadAllBytes(args[1]);if(table.Length!=32768*4)throw new ArgumentException("sine table size");float[] sine=new float[32768];Buffer.BlockCopy(table,0,sine,0,table.Length);int index=0;
        foreach(object item in Arr(root["cases"]))
        {
            Dictionary<string,object> c=Obj(item);string kind=(string)c["kind"];object got;
            if(kind=="direction"){float[] d=ActorReinitialization.Direction(PcObjectImage.FromBits(U(c["speed"])),U(c["angle"]),sine);got=new uint[]{Bits(d[0]),Bits(d[1]),Bits(d[2])};}
            else
            {
                Dictionary<string,object> o=Obj(c["options"]);PcObjectImage a;Services services;ActorReinitializationWorld w=Setup(o,sine,out a,out services);byte[] before=(byte[])a.Bytes.Clone(),formation=(byte[])w.Formations[FORM].Bytes.Clone();
                if(kind=="path")ActorReinitialization.BindPathSet(w,a,Opt(o,"nullPath",false)?0:PATH);else if(kind=="accessory")ActorReinitialization.ResetAccessory(w,a);else ActorReinitialization.Reinitialize(w,Opt(o,"nullActor",false)?null:a,!Opt(o,"noSystem",false));
                got=new Dictionary<string,object>{{"actor",Changes(before,a.Bytes)},{"formation",Changes(formation,w.Formations[FORM].Bytes)},{"origin",w.LastSpawnOrigin},{"events",services.Events}};
            }
            Check(got,c["native"],index++);
        }
        File.WriteAllText(args[2],json.Serialize(new{checks,failures,errors}));Console.WriteLine("Actor reinitialization: "+checks+" comparisons, "+failures+" failures.");return failures==0?0:1;
    }
}
