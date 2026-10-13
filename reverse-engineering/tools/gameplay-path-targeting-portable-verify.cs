using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathTargetingVerify
{
    static int checks,failures;
    static List<object> errors=new List<object>(),diagnostics=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?I(o[k]):d;}
    static bool Flag(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
    static byte[] Hex(string v){byte[] b=new byte[v.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(v.Substring(i*2,2),16);return b;}
    static byte[][] Rows(object value){object[] a=Arr(value);byte[][] b=new byte[a.Length][];for(int i=0;i<a.Length;i++)b[i]=Hex((string)a[i]);return b;}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    const uint PathId=0x10102000,EdgeBase=0x10110000;
    static TargetingPath Graph(Dictionary<string,object> g)
    {
        object[] points=Arr(g["points"]),edges=Arr(g["edges"]);TargetingPath p=new TargetingPath{Identity=PathId,PointCount=(byte)I(g["count"]),CandidateCount=(byte)Opt(g,"candidateCount",0),Points=new ReinitializationRecord[points.Length],PointConnections=new uint[points.Length][]};
        if(g.ContainsKey("candidates")){object[] cc=Arr(g["candidates"]);p.CandidateIndices=new byte[cc.Length];for(int i=0;i<cc.Length;i++)p.CandidateIndices[i]=(byte)I(cc[i]);}
        for(int i=0;i<edges.Length;i++){object[] e=Arr(edges[i]);uint id=EdgeBase+(uint)(i*0x24);p.Connections.Add(id,new RoutingConnection{Identity=id,Endpoint0=(byte)I(e[0]),Endpoint1=(byte)I(e[1])});}
        for(int i=0;i<points.Length;i++){Dictionary<string,object> n=Obj(points[i]);ReinitializationRecord r=new ReinitializationRecord(0x10104000u+(uint)(i*0x5c),new byte[0x5c]);for(int j=0;j<3;j++)r.Set32(4+j*4,PcObjectImage.ToBits(Convert.ToSingle(Arr(n["position"])[j])));r.Set32(0x10,PcObjectImage.ToBits(Convert.ToSingle(n["radius"])));object[] ee=Arr(n["edges"]);r.Set8(0x28,ee.Length);uint[] ids=new uint[ee.Length];for(int j=0;j<ee.Length;j++)ids[j]=EdgeBase+(uint)(I(ee[j])*0x24);p.Points[i]=r;p.PointConnections[i]=ids;}
        return p;
    }
    static PcObjectImage Image(Dictionary<string,object> o)
    {
        byte[] bytes=new byte[PcObjectImage.Size];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*37+11);PcObjectImage a=new PcObjectImage(bytes);a.Set32(0x420,PathId);a.Set32(0x494,Flag(o,"same")?PathId:0);a.Set32(0x498,Flag(o,"target")?EdgeBase:0);a.Set8(0x40a,Opt(o,"cursor",0));a.Set8(0x40b,Opt(o,"selected",255));a.Set8(0x4b4,Opt(o,"flags",4));for(int j=0;j<3;j++)a.SetFloat(0x47c+4*j,o.ContainsKey("query")?Convert.ToSingle(Arr(o["query"])[j]):0);return a;
    }
    static List<object> Changes(byte[] before,PcObjectImage after)
    {List<object> result=new List<object>();for(int at=0;at<before.Length;at+=4)if(BitConverter.ToUInt32(before,at)!=after.U32(at))result.Add(new object[]{at,after.U32(at)});return result;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));object[] records=Arr(root["graphs"]);TargetingPath[] paths=new TargetingPath[records.Length];for(int i=0;i<paths.Length;i++)paths[i]=Graph(Obj(records[i]));int index=0;
        foreach(object item in Arr(root["cases"]))try
        {
            Dictionary<string,object> c=Obj(item),o=Obj(c["options"]);TargetingPath p=paths[I(c["graph"])];PcObjectImage a=Image(o);byte[] before=(byte[])a.Bytes.Clone();object result=null;string kind=(string)c["kind"];
            if(kind=="scan")PathTargeting.Scan(p,a,new SpawnVector(a.F32(0x47c),a.F32(0x480),a.F32(0x484)));else if(kind=="materialize")result=PathTargeting.Materialize(p,a)?1:0;else result=PathTargeting.EnsureTarget(p,a);
            object got=new Dictionary<string,object>{{"result",result},{"changes",Changes(before,a)}};++checks;if(!Equal(got,c["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}++index;
        }
        catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});++index;}
        string output=json.Serialize(new{checks,mismatches=failures,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
