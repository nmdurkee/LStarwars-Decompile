using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase320261013Verify
{
    static Dictionary<string,object> M(object x){return(Dictionary<string,object>)x;}
    static int I(Dictionary<string,object> x,string k,int fallback){return x.ContainsKey(k)?Convert.ToInt32(x[k]):fallback;}
    static uint U(Dictionary<string,object> x,string k,uint fallback){return x.ContainsKey(k)?Convert.ToUInt32(x[k]):fallback;}
    static byte[] Bytes(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
    static uint[] Words(object x){object[] a=(object[])x;uint[] r=new uint[a.Length];for(int i=0;i<a.Length;i++)r[i]=Convert.ToUInt32(a[i]);return r;}
    static string[] Tokens(object x){object[] a=(object[])x;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
    sealed class Services:BigJumpServices
    {
        public List<object> Events=new List<object>();public Dictionary<string,object> Input;
        bool Mutate(){return I(Input,"mutate",0)!=0;}
        public override void ResetActor(BigJumpWorld w,uint id,PcObjectImage a){Events.Add(new object[]{"reset",0});if(Mutate()){w.ContextId31=32;a.Set32(0xef0,0xabcdef01);}}
        public override short SelectAnimation(BigJumpWorld w,uint id,PcObjectImage a){Events.Add(new object[]{"select",a.U8(0x7b5),a.U8(0x7b4)});if(Mutate())a.Set16(0x1064,77);return unchecked((short)I(Input,"animation",-3));}
        public override float Duration(BigJumpWorld w,short model,short animation){Events.Add(new object[]{"duration",model,animation});return PcObjectImage.FromBits(U(Input,"duration",0x3fa00000));}
        public override void InvalidateAnimation(BigJumpWorld w,uint id,PcObjectImage a){Events.Add(new object[]{"invalidate",8,0xffffffffu});}
        public override void Feedback(BigJumpWorld w,uint id,PcObjectImage a,int kind){Events.Add(new object[]{"feedback",kind});if(Mutate()){a.Set32(0x4b0,0x200);a.Set32(0x7bc,0x300);}}
    }
    static object Run(Dictionary<string,object> data,Dictionary<string,object> row)
    {
        var input=M(row["input"]);var actor=new PcObjectImage(Bytes((string)row["beforeActorHex"]));
        var controls=new PathRelocationWorld{RandomState=U(input,"controlSeed",12345)};var pad=new ReinitializationRecord(actor.U32(0xca4),new byte[0x100]);pad.Set8(0x5a,255);pad.Set8(0x5b,255);controls.Records[pad.Identity]=pad;
        var services=new Services{Input=input};var locators=new LocatorWorld();
        foreach(object v in(object[])data["records"]){var r=M(v);uint[] p=Words(r["position"]);locators.Locators.Add(new LocatorRecord{Name=(string)r["name"],Position=new SpawnVector(PcObjectImage.FromBits(p[0]),PcObjectImage.FromBits(p[1]),PcObjectImage.FromBits(p[2])),Orientation=Words(r["orientation"])});}
        var world=new BigJumpWorld{ContextId31=I(input,"context",31),FallbackAnimation=61,Controls=controls,Locators=locators,Services=services};
        uint[] aa=Words(data["angleTable"]);world.AngleTable=new ushort[aa.Length];for(int i=0;i<aa.Length;i++)world.AngleTable[i]=(ushort)aa[i];
        var definition=new ReinitializationRecord(actor.U32(0x54),new byte[0x30]);definition.Set32(4,U(input,"definitionFlags",0));world.Definitions[definition.Identity]=definition;world.CharacterNames[definition.Identity]="Hero";
        var draws=new Queue<int>();foreach(object draw in(object[])row["randomDraws"])draws.Enqueue(Convert.ToInt32(draw));locators.NextInteger=delegate{if(draws.Count==0)throw new InvalidOperationException("Unexpected integer RNG request.");return draws.Dequeue();};
        world.Observe=delegate(string op,string v){if(op=="lookup")services.Events.Add(new object[]{op,v});};
        string group=(string)row["group"];bool result;LocatorPacket packet=null;
        if(group=="Request"||group=="RequestComposition")
        {
            uint[] position=input.ContainsKey("position")?Words(input["position"]):Words(M(((object[])data["records"])[0])["position"]);
            result=BigJumpActions.Request(world,0x10100000,actor,position,U(input,"directed",0),PcObjectImage.FromBits(U(input,"factor",0x3f800000)),PcObjectImage.FromBits(U(input,"speed",0x3f800000)),unchecked((byte)I(input,"mode",0)));
        }
        else
        {
            var numbers=new ScriptPacket{Script=new ScriptDefinition()};numbers.Parameters[0]=.5f;numbers.Parameters[1]=2;numbers.Parameters[2]=-1;numbers.Parameters[3]=7;numbers.Script.ParameterNames[0]="factor";
            int selected=I(input,"selected",0),active=I(input,"active",5);packet=new LocatorPacket{Numbers=numbers,Selected=selected<0?null:locators.Locators[selected],Active=active<0?null:locators.Locators[active]};
            result=BigJumpActions.ToLocator(world,0x10100000,I(input,"gate",3)==3?actor:null,packet,Tokens(input["tokens"]),I(input,"first",1)!=0);
        }
        if(draws.Count!=0)throw new InvalidOperationException("Native integer RNG draw not consumed.");
        var output=new List<object>{result?1:0,Hex(actor.Bytes),(int)(pad.U8(0x5a)|pad.U8(0x5b)<<8),controls.RandomState,services.Events};
        if(packet!=null)output.Add(packet.Active==null?-1:locators.Locators.IndexOf(packet.Active));return output;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("Gzip fixture and output paths required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));int cases=0,failed=0;var errors=new List<object>();
        foreach(object v in(object[])data["vectors"]){var row=M(v);cases++;try{object actual=Run(data,row);if(json.Serialize(actual)!=json.Serialize(row["native"])){failed++;if(errors.Count<10)errors.Add(new{group=row["group"],input=row["input"],actual=actual,native=row["native"]});}}catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{group=row["group"],input=row["input"],error=e.Message});}}
        File.WriteAllText(args[1],json.Serialize(new{cases=cases,failures=failed,examples=errors}));Console.WriteLine("BigJump compiled comparisons:"+cases+", failures:"+failed);return failed==0?0:1;
    }
}
