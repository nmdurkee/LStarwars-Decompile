using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathCorridorVerify
{
    static int checks,failures;
    static List<object> errors=new List<object>();
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?I(o[k]):d;}
    static uint OptU(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?U(o[k]):d;}
    static float OptF(Dictionary<string,object> o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
    static bool Flag(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
        if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
        IList al=a as IList,bl=b as IList;
        if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
        if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Put(ReinitializationRecord r,int offset,uint value,int size){for(int i=0;i<size;i++)r.Set8(offset+i,(int)(value>>(i*8)));}
    static List<object> Changes(byte[] before,byte[] after)
    {
        List<object> result=new List<object>();int i=0;
        while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;
    }
    const uint NodeBase=0x10101000,EdgeId=0x10103000;
    static object Run(Dictionary<string,object> o,float[] sine)
    {
        CorridorPath path=new CorridorPath{ContextIdentity=0x12345678,Marker78=(byte)Opt(o,"pathMarker",7),Sine=sine,Points=new ReinitializationRecord[4]};
        if(o.ContainsKey("seen")){object[] seen=Arr(o["seen"]);for(int i=0;i<32;i++)path.RefreshedBits[i]=(byte)I(seen[i]);}
        float[][] positions={new float[]{0,0,0},new float[]{0,0,10},new float[]{5,0,0},new float[]{5,0,10}};
        for(int i=0;i<4;i++)
        {
            ReinitializationRecord p=new ReinitializationRecord(NodeBase+(uint)(i*0x5c),new byte[0x5c]);path.Points[i]=p;
            for(int j=0;j<3;j++)p.Set32(4+j*4,PcObjectImage.ToBits(o.ContainsKey("positions")?Convert.ToSingle(Arr(Arr(o["positions"])[i])[j]):positions[i][j]));
            p.Set32(0x10,PcObjectImage.ToBits(o.ContainsKey("radii")?Convert.ToSingle(Arr(o["radii"])[i]):2));
            p.Set32(0x18,PcObjectImage.ToBits(o.ContainsKey("heights")?Convert.ToSingle(Arr(Arr(o["heights"])[i])[0]):-1));
            p.Set32(0x20,PcObjectImage.ToBits(o.ContainsKey("heights")?Convert.ToSingle(Arr(Arr(o["heights"])[i])[1]):1));
            p.Set8(0x2a,o.ContainsKey("dynamic")?I(Arr(o["dynamic"])[i]):0);Put(p,0x5a,o.ContainsKey("boundaries")?U(Arr(o["boundaries"])[i]):0,2);
        }
        ReinitializationRecord edge=new ReinitializationRecord(EdgeId,new byte[0x24]),previous=new ReinitializationRecord(EdgeId+0x24,new byte[0x24]);
        for(int i=0;i<2;i++){edge.Set8(0x10+i,o.ContainsKey("endpoints")?I(Arr(o["endpoints"])[i]):i);previous.Set8(0x10+i,o.ContainsKey("previous")?I(Arr(o["previous"])[i]):i*2);}
        Put(edge,0x12,OptU(o,"angle",0),2);Put(edge,0x14,OptU(o,"mask",1),2);edge.Set8(0x17,Opt(o,"edgeMarker",3));edge.Set32(0x1c,PcObjectImage.ToBits(OptF(o,"length",10)));
        byte[] hitBytes=new byte[32];for(int i=0;i<32;i++)hitBytes[i]=(byte)(i*17+3);ReinitializationRecord hit=new ReinitializationRecord(0x10105000,hitBytes);
        byte[][] beforeNodes=new byte[4][];for(int i=0;i<4;i++)beforeNodes[i]=(byte[])path.Points[i].Bytes.Clone();byte[] beforeEdge=(byte[])edge.Bytes.Clone();List<object> events=new List<object>();
        path.Refresh=delegate(CorridorPath p,ReinitializationRecord point)
        {
            int index=(int)((point.Identity-NodeBase)/0x5c);events.Add(new object[]{"refresh",p.ContextIdentity,index});
            if(!o.ContainsKey("effects"))return;
            foreach(object item in Arr(o["effects"]))
            {
                Dictionary<string,object> e=Obj(item);if(Opt(e,"trigger",0)!=index)continue;string target=(string)e["target"];
                if(target=="seen")p.RefreshedBits[I(e["index"])]=(byte)I(e["value"]);
                else Put(target=="node"?p.Points[I(e["index"])]:edge,I(e["offset"]),U(e["value"]),Opt(e,"size",4));
            }
        };
        SpawnVector query=new SpawnVector(0,0,5);if(o.ContainsKey("query")){object[] q=Arr(o["query"]);query=new SpawnVector(Convert.ToSingle(q[0]),Convert.ToSingle(q[1]),Convert.ToSingle(q[2]));}
        if(o.ContainsKey("queryWords")){object[] q=Arr(o["queryWords"]);query=new SpawnVector(PcObjectImage.FromBits(U(q[0])),PcObjectImage.FromBits(U(q[1])),PcObjectImage.FromBits(U(q[2])));}
        bool result=PathCorridor.Contains(path,edge,query,Flag(o,"noPrevious")?null:previous,OptU(o,"route",255),OptF(o,"margin",0),OptU(o,"stampMode",0),Flag(o,"noHit")?null:hit);
        List<object> nodeChanges=new List<object>();for(int i=0;i<4;i++)nodeChanges.Add(Changes(beforeNodes[i],path.Points[i].Bytes));
        return new Dictionary<string,object>{{"result",result?1:0},{"state",new Dictionary<string,object>{{"nodes",nodeChanges},{"edge",Changes(beforeEdge,edge.Bytes)},{"hit",Changes(hitBytes,hit.Bytes)},{"seen",path.RefreshedBits},{"events",events}}}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=3)throw new ArgumentException("fixture JSON, sine table f32, output JSON");checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));byte[] sineBytes=File.ReadAllBytes(args[1]);if(sineBytes.Length!=32768*4)throw new ArgumentException("32768 sine floats required");float[] sine=new float[32768];for(int i=0;i<sine.Length;i++)sine[i]=BitConverter.ToSingle(sineBytes,i*4);int index=0;
        foreach(object item in Arr(root["cases"]))try
        {
            Dictionary<string,object> c=Obj(item);object got=Run(Obj(c["options"]),sine);++checks;if(!Equal(got,c["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}++index;
        }
        catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});++index;}
        string output=json.Serialize(new{checks,mismatches=failures,errors});File.WriteAllText(args[2],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
