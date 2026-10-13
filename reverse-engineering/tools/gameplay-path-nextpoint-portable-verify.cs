using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathNextPointVerify
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
    static RoutingPath Graph(Dictionary<string,object> g)
    {
        object[] nodes=Arr(g["nodes"]),edges=Arr(g["edges"]),groups=Arr(g["groups"]);RoutingPath p=new RoutingPath{Points=new RoutingPoint[nodes.Length],BaseNextSlots=Rows(g["base"]),Groups=new RoutingGroup[groups.Length]};
        for(int i=0;i<nodes.Length;i++){Dictionary<string,object> n=Obj(nodes[i]);object[] adj=Arr(n["adj"]);uint[] a=new uint[adj.Length];for(int j=0;j<a.Length;j++)a[j]=I(adj[j])<0?0:U(adj[j])+1;p.Points[i]=new RoutingPoint{Adjacency=a,Membership58=(ushort)I(n["member"]),Boundary5a=(ushort)I(n["boundary"])};}
        for(int i=0;i<edges.Length;i++){Dictionary<string,object> e=Obj(edges[i]);p.Connections.Add((uint)i+1,new RoutingConnection{Identity=(uint)i+1,Endpoint0=(byte)I(e["a"]),Endpoint1=(byte)I(e["b"]),RouteMask=(ushort)I(e["mask"]),Distance=Convert.ToSingle(e["distance"])});}
        for(int i=0;i<groups.Length;i++){Dictionary<string,object> s=Obj(groups[i]);p.Groups[i]=new RoutingGroup{PointCount=(byte)I(s["count"]),PointMap=Hex((string)s["map"]),Exits=Hex((string)s["exits"]),NextSlots=Rows(s["matrix"])};}
        p.InvalidGroupMap=delegate(int group,int start,int dest){diagnostics.Add(new int[]{group,start,dest});};return p;
    }
    static List<object> Caches(RoutingPath p)
    {List<object> c=new List<object>();foreach(RoutingPoint v in p.Points)c.Add(new uint[]{v.CacheDestination0,v.CacheDestination1,PcObjectImage.ToBits(v.CacheDistance0),PcObjectImage.ToBits(v.CacheDistance1)});return c;}
    static List<object> Changes(List<object> a,List<object> b)
    {List<object> d=new List<object>();for(int i=0;i<a.Count;i++)if(!Equal(a[i],b[i]))d.Add(new object[]{i,b[i]});return d;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));object[] records=Arr(root["graphs"]);RoutingPath[] paths=new RoutingPath[records.Length];ReinitializationRecord[][] points=new ReinitializationRecord[records.Length][];
        for(int i=0;i<paths.Length;i++){Dictionary<string,object> g=Obj(records[i]);paths[i]=Graph(g);object[] rows=Arr(g["positionWords"]);points[i]=new ReinitializationRecord[rows.Length];for(int j=0;j<rows.Length;j++){ReinitializationRecord p=new ReinitializationRecord((uint)j,new byte[0x5c]);for(int k=0;k<3;k++)p.Set32(4+4*k,U(Arr(rows[j])[k]));points[i][j]=p;}}
        int index=0;foreach(object item in Arr(root["cases"]))try
        {
            Dictionary<string,object> c=Obj(item),o=Obj(c["options"]);int graph=I(c["graph"]);RoutingPath p=paths[graph];for(int i=0;i<p.Points.Length;i++){RoutingPoint v=p.Points[i];v.CacheDestination0=v.CacheDestination1=255;v.CacheDistance0=10.25f+i;v.CacheDistance1=20.5f+i;}
            List<object> before=Caches(p);diagnostics.Clear();uint current=I(o["edge"])<0?0:U(o["edge"])+1,goal=Flag(o,"same")?current:0xffffffff;uint[] words={0xdeadbeef,0xcafebabe,0xfacefeed};int? destination=o["destination"]==null?(int?)null:I(o["destination"]);
            bool result=PathTargeting.TryNextPoint(p,points[graph],current,goal,(byte)I(o["direction"]),(byte)I(o["group"]),destination,Flag(o,"nullOutput")?null:words);object got=new Dictionary<string,object>{{"result",result?1:0},{"words",words},{"cache",Changes(before,Caches(p))},{"diagnostics",diagnostics.ToArray()}};++checks;if(!Equal(got,c["native"])){++failures;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}++index;
        }
        catch(Exception e){++failures;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});++index;}
        string output=json.Serialize(new{checks,mismatches=failures,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
