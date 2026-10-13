using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathRoutingVerify
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
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));object[] records=Arr(root["graphs"]);RoutingPath[] paths=new RoutingPath[records.Length];for(int i=0;i<paths.Length;i++)paths[i]=Graph(Obj(records[i]));int index=0;
        foreach(object item in Arr(root["cases"]))
        {
            Dictionary<string,object> c=Obj(item),o=Obj(c["options"]);RoutingPath p=paths[I(c["graph"])];
            for(int i=0;i<p.Points.Length;i++){RoutingPoint v=p.Points[i];v.CacheDestination0=(byte)Opt(o,"cache0",255);v.CacheDestination1=(byte)Opt(o,"cache1",255);v.CacheDistance0=10.25f+i;v.CacheDistance1=20.5f+i;}
            List<object> before=Caches(p);diagnostics.Clear();int start=I(c["start"]),group=I(c["group"]);Dictionary<string,object> got=new Dictionary<string,object>();
            if((string)c["kind"]=="distance")
            {byte[][] saved=p.BaseNextSlots;if(Flag(o,"noBase"))p.BaseNextSlots=null;float value=PathRouting.Distance(p,start,I(c["destination"]),group,U(c["exclude"]));p.BaseNextSlots=saved;got["value"]=PcObjectImage.ToBits(value);}
            else
            {
                p.Connections[0xffffffff]=new RoutingConnection{Identity=0xffffffff,Endpoint0=(byte)start,Endpoint1=(byte)start};uint current=o.ContainsKey("edge")?U(o["edge"])+1:0xffffffff;uint direction=0xdeadbeef;int? destination=c["destination"]==null?(int?)null:I(c["destination"]);uint value=PathRouting.NextConnection(p,Flag(o,"noCurrent")?0:current,(byte)Opt(o,"direction",0),(byte)group,destination,ref direction);got["value"]=value==0?-1:(int)value-1;got["direction"]=direction;
            }
            got["cache"]=Changes(before,Caches(p));got["diagnostics"]=diagnostics.ToArray();++checks;if(!Equal(got,c["native"])) {++failures;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}++index;
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));Console.WriteLine("Path routing: "+checks+" comparisons, "+failures+" failures.");return failures==0?0:1;
    }
}
