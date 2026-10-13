using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathCornersVerify
{
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static object Opt(Dictionary<string,object> o,string k,object d){return o.ContainsKey(k)?o[k]:d;}
    static object N(Dictionary<string,object> o,string k,int i,object d){return o.ContainsKey(k)?Arr(o[k])[i]:d;}
    static uint Bits(object v){return PcObjectImage.ToBits(Convert.ToSingle(v));}
    static bool Equal(object a,object b)
    {if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    static string Hex(byte[] v){return BitConverter.ToString(v).Replace("-","").ToLowerInvariant();}
    static object Run(Dictionary<string,object> o,string kind,float[] sine)
    {
        const int P=0x2c8;const uint EDGES=0x10106000;byte[] bytes=new byte[PcObjectImage.Size];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*37+11);PcObjectImage actor=new PcObjectImage(bytes);actor.Set32(0xac,Bits(Opt(o,"bodyRadius",.5)));actor.Set32(P+0x158,0x10102000);actor.Bytes[P+0x13c]=(byte)I(Opt(o,"route",255));bool cached=Convert.ToBoolean(Opt(o,"sameCache",false));actor.Set32(P+0x190,cached?EDGES:0);actor.Set32(P+0x194,cached?EDGES+0x24:0);actor.Set32(P+0x1e8,U(Opt(o,"flags",0x1000)));
        CorridorPath path=new CorridorPath{ContextIdentity=0x12345678,Marker78=(byte)I(Opt(o,"pathMarker",7)),Points=new ReinitializationRecord[4],RefreshedBits=new byte[32],Sine=sine};object[] positions=o.ContainsKey("positions")?Arr(o["positions"]):new object[]{new object[]{0,0,0},new object[]{0,0,-10},new object[]{10,0,0},new object[]{20,0,0}};
        for(int i=0;i<4;i++){object[] pos=Arr(positions[i]);ReinitializationRecord p=new ReinitializationRecord(0x10104000u+(uint)(i*0x5c),new byte[0x5c]);path.Points[i]=p;for(int j=0;j<3;j++)p.Set32(4+j*4,Bits(pos[j]));p.Set32(0x10,Bits(N(o,"radii",i,2)));p.Set32(0x18,Bits(Convert.ToDouble(pos[1])-2));p.Set32(0x20,Bits(Convert.ToDouble(pos[1])+2));int boundary=I(N(o,"boundaries",i,0));p.Set8(0x5a,boundary);p.Set8(0x5b,boundary>>8);}
        ReinitializationRecord[] edges=new ReinitializationRecord[2];byte[][] initialEdges=new byte[2][];
        for(int i=0;i<2;i++){ReinitializationRecord e=new ReinitializationRecord(EDGES+(uint)(i*0x24),new byte[0x24]);edges[i]=e;object[] ends=Arr(N(o,"endpoints",i,new object[]{i+1,0}));e.Set8(0x10,I(ends[0]));e.Set8(0x11,I(ends[1]));int angle=I(N(o,"edgeAngles",i,i==0?0:49152)),mask=I(N(o,"masks",i,1));e.Set8(0x12,angle);e.Set8(0x13,angle>>8);e.Set8(0x14,mask);e.Set8(0x15,mask>>8);e.Set8(0x17,I(N(o,"edgeMarkers",i,3)));e.Set32(0x1c,Bits(N(o,"lengths",i,10)));initialEdges[i]=(byte[])e.Bytes.Clone();}
        if(kind=="construct"){byte[] output=new byte[12];for(int i=0;i<12;i++)output[i]=(byte)(i*17+3);SpawnVector v=new SpawnVector(BitConverter.ToSingle(output,0),BitConverter.ToSingle(output,4),BitConverter.ToSingle(output,8));bool found=PathCorners.Construct(sine,edges[0],edges[1],path.Points[0],path.Points[1],path.Points[2],I(N(o,"angles",0,0)),I(N(o,"angles",1,-16384)),actor.F32(0xac),ref v);Buffer.BlockCopy(BitConverter.GetBytes(v.X),0,output,0,4);Buffer.BlockCopy(BitConverter.GetBytes(v.Y),0,output,4,4);Buffer.BlockCopy(BitConverter.GetBytes(v.Z),0,output,8,4);return new object[]{found?1:0,Hex(output)};}
        byte[] before=(byte[])actor.Bytes.Clone();bool result=PathCorners.Update(path,actor,edges[0],edges[1]);return new Dictionary<string,object>{{"result",result?1:0},{"actor",Changes(before,actor.Bytes)},{"edges",new object[]{Changes(initialEdges[0],edges[0].Bytes),Changes(initialEdges[1],edges[1].Bytes)}}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("fixture JSON, original sine table f32, output JSON");byte[] table=File.ReadAllBytes(args[1]);if(table.Length!=32768*4)throw new ArgumentException("sine table length");float[] sine=new float[32768];Buffer.BlockCopy(table,0,sine,0,table.Length);JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();foreach(object item in Arr(root["cases"]))try{Dictionary<string,object> c=Obj(item);object got=Run(Obj(c["options"]),(string)c["kind"],sine);checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;}catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[2],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
