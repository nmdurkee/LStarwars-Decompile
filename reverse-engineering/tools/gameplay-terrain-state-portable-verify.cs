using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayTerrainStateVerify
{
    const uint A=0x10100000,Char=0x10102000,Tune=0x10102200;
    static float[] sine;static ushort[] table;
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
    static uint U(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
    static float F(Dictionary<string,object> o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
    static bool B(Dictionary<string,object> o,string k,bool d){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):d;}
    static float[] V(Dictionary<string,object> o,string k,float[] d){bool words=o.ContainsKey(k+"Words");if(!words&&!o.ContainsKey(k))return d;object[] a=Arr(o[words?k+"Words":k]);float[] b=new float[a.Length];for(int i=0;i<a.Length;i++)b[i]=words?PcObjectImage.FromBits(Convert.ToUInt32(a[i])):Convert.ToSingle(a[i]);return b;}
    static byte[] Pattern(int count){byte[] b=new byte[count];for(int i=0;i<count;i++)b[i]=(byte)(i*37+11);return b;}
    static uint[] Words(float[] v){uint[] b=new uint[v.Length];for(int i=0;i<v.Length;i++)b[i]=PcObjectImage.ToBits(v[i]);return b;}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    static object[] Probe(PcObjectImage a)
    {return new object[]{a.U8(0x283),a.U8(0x284),a.U8(0x285),a.U8(0x286),a.U8(0x287),a.U8(0xe42),a.U8(0x107b),a.U32(0x21c),a.U32(0x220),a.U32(0x224),a.U32(0x1014),a.U16(0x106c)};}
    sealed class Services:TerrainActorServices
    {
        public Dictionary<string,object> Options;public List<object> Events=new List<object>();public int Calls;
        public override float Query(TerrainActorWorld w,uint id,PcObjectImage a,float range,uint mask){Events.Add(new object[]{"query",id,id+0x5c,PcObjectImage.ToBits(range),mask});return F(Options,"queryHeight",3);}
        public override float SecondaryHeight(TerrainActorWorld w,uint id,PcObjectImage a){Events.Add(new object[]{"secondary",id+0x5c});return F(Options,"secondaryHeight",2000000);}
        public void Callback(TerrainActorWorld w,uint id,PcObjectImage a)
        {
            Events.Add(new object[]{"callback",id,Probe(a)});Calls++;
            if(Options.ContainsKey("effects"))foreach(object item in Arr(Options["effects"]))
            {Dictionary<string,object> e=Obj(item);if(I(e,"call",0)!=Calls)continue;int offset=I(e,"offset",0);uint value=U(e,"value",0);switch(I(e,"size",4)){case 1:a.Set8(offset,(int)value);break;case 2:a.Set16(offset,(int)value);break;default:a.Set32(offset,value);break;}}
        }
    }
    static ReinitializationRecord Metadata(int value,int offset)
    {if(value<0)return null;ReinitializationRecord r=new ReinitializationRecord(0,new byte[0x100]);r.Set8(offset,value);return r;}
    static object Run(Dictionary<string,object> o,string kind)
    {
        Services service=new Services{Options=o};TerrainActorWorld w=new TerrainActorWorld{GroundMetadata=Metadata(I(o,"material",1),0x60),UpperMetadata=Metadata(I(o,"upperType",1),0x61),LowerMetadata=Metadata(I(o,"lowerType",1),0x60),ObjectIndex=I(o,"objectIndex",0),UpperHeight=F(o,"upperHeight",2),LowerHeight=F(o,"lowerHeight",-2),DefaultNormal=V(o,"defaultNormal",new float[]{0,1,0}),GroundNormal=V(o,"groundNormal",new float[]{.25f,1,-.5f}),UpperNormal=V(o,"upperNormal",new float[]{-.5f,1,.25f}),Sine=sine,AngleTable=table,FirstAngle92b0c4=0x1234,SecondAngle92b0c0=0x5678,Mode951288=U(o,"modeA",0),Mode951154=U(o,"modeB",0),Mask8034c4=U(o,"maskA",0),Mask95100c=U(o,"maskB",0),Services=service};
        if(B(o,"callback",true))w.Callback951010=service.Callback;
        if(!B(o,"nullObject",false))
        {w.ObjectRecords=new ReinitializationRecord[3];for(int i=0;i<3;i++){ReinitializationRecord rec=new ReinitializationRecord(0,new byte[0x38]);w.ObjectRecords[i]=rec;rec.Set32(0x2c,U(o,"objectKind",1));int id=I(o,"objectId",7);rec.Set8(0x30,id);rec.Set8(0x31,id>>8);}}
        for(int i=0;i<32;i++)w.MaterialFlags[i]=(byte)I(o,"materialFlags",10);
        ReinitializationRecord chr=new ReinitializationRecord(Char,new byte[0x100]),tuning=new ReinitializationRecord(Tune,new byte[0x100]);chr.Set32(0x24,Tune);tuning.Set32(0x90,U(o,"characterFlags",0));w.Records.Add(Char,chr);w.Records.Add(Tune,tuning);
        PcObjectImage actor=new PcObjectImage(Pattern(PcObjectImage.Size));actor.Set32(0x54,Char);actor.SetFloat(0x21c,F(o,"floor",3));actor.SetFloat(0x84,F(o,"predictedY",1));actor.SetFloat(0x17c,F(o,"lowerY",-1));actor.SetFloat(0x188,F(o,"upperY",5));float[] position=V(o,"position",new float[]{2,3,4});for(int i=0;i<3;i++)actor.SetFloat(0x5c+4*i,position[i]);
        if(kind=="material")return unchecked((uint)TerrainActorState.GroundMetadata(w));if(kind=="upperType")return unchecked((uint)TerrainActorState.UpperMetadata(w));if(kind=="lowerType")return unchecked((uint)TerrainActorState.LowerMetadata(w));if(kind=="object")return unchecked((uint)TerrainActorState.ObjectId(w));
        float[] vector=V(o,"vector",new float[]{.25f,1,-.5f});
        if(kind=="rotate"){float[] output=B(o,"alias",false)?vector:new float[3];TerrainActorState.RotateX(output,vector,I(o,"angle",0),sine);return Words(output);}
        if(kind=="normal"){ushort[] first={0x3333},second={0x4444};TerrainActorState.NormalAngles(w,vector,B(o,"first",true)?first:null,B(o,"second",true)?second:null);return new ushort[]{w.FirstAngle92b0c4,w.SecondAngle92b0c0,first[0],second[0]};}
        byte[] before=(byte[])actor.Bytes.Clone();if(kind=="apply")TerrainActorState.Apply(w,A,actor,I(o,"publish",1),F(o,"height",3));else TerrainActorState.Refresh(w,A,actor);
        return new Dictionary<string,object>{{"changes",Changes(before,actor.Bytes)},{"angles",new ushort[]{w.FirstAngle92b0c4,w.SecondAngle92b0c0}},{"events",service.Events}};
    }
    static bool Equal(object a,object b)
    {if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    public static int Main(string[] args)
    {
        if(args.Length!=4)throw new ArgumentException("fixture JSON, sine f32, angle u16, output JSON");byte[] raw=File.ReadAllBytes(args[1]);sine=new float[raw.Length/4];Buffer.BlockCopy(raw,0,sine,0,raw.Length);raw=File.ReadAllBytes(args[2]);table=new ushort[raw.Length/2];Buffer.BlockCopy(raw,0,table,0,raw.Length);
        JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();
        foreach(object item in Arr(root["cases"]))try{Dictionary<string,object> c=Obj(item);object got=Run(Obj(c["options"]),(string)c["kind"]);checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;}catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}
        string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[3],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
