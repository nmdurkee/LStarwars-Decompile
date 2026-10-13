using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class TreeVisibilityPhase3Harness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static float F(object v){return Convert.ToSingle(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static int I(object v){return Convert.ToInt32(v);}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
    static Point3 Point(object v){var a=A(v);return new Point3(F(a[0]),F(a[1]),F(a[2]));}
    static float[] Floats(object v){var a=A(v);var b=new float[a.Length];for(int i=0;i<b.Length;++i)b[i]=F(a[i]);return b;}
    static ushort[] Shorts(object v){var a=A(v);var b=new ushort[a.Length];for(int i=0;i<b.Length;++i)b[i]=Convert.ToUInt16(a[i]);return b;}
    static TreeVisibilityPlanes Planes(object v){var p=M(v);return new TreeVisibilityPlanes{Outer=Floats(p["outer"]),Inner=Floats(p["inner"]),AbsOuter=Floats(p["absOuter"]),AbsInner=Floats(p["absInner"]),Depth=Floats(p["depth"]),AbsDepth=Floats(p["absDepth"]),Near=F(p["near"]),GlobalFar=F(p["globalFar"])};}
    static TreeVisibilityBounds Bounds(object v){var b=M(v);return new TreeVisibilityBounds(Point(b["center"]),Point(b["extent"]));}
    static TreeVisibilityBounds[] BoundArray(object v){var a=A(v);var b=new TreeVisibilityBounds[a.Length];for(int i=0;i<b.Length;++i)b[i]=Bounds(a[i]);return b;}
    static TreeVisibilityData Tree(object v)
    {
        var t=M(v);var a=A(t["nodes"]);var nodes=new TreeVisibilityNode[a.Length];for(int i=0;i<a.Length;++i){var n=Shorts(a[i]);nodes[i]=new TreeVisibilityNode(n[0],n[1],n[2],n[3],n[4],n[5]);}
        return new TreeVisibilityData{Nodes=nodes,NodeBounds=BoundArray(t["nodeBounds"]),ItemBounds=BoundArray(t["itemBounds"]),Members=Shorts(t["members"]),Roots=Shorts(t["roots"]),FarLimits=Floats(t["far"])};
    }
    static bool Equal(Point3 a,Point3 b){return a.X==b.X&&a.Y==b.Y&&a.Z==b.Z;}
    static uint Word(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
    static int checks,failures;static List<object> errors=new List<object>();
    static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;
        using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=M(Json.DeserializeObject(r.ReadToEnd()));
        var planeCases=A(f["planeCases"]);int cases=0;
        foreach(object item in A(f["predicateCases"]))
        {
            var c=M(item);var p=Planes(M(planeCases[I(c["planeIndex"])])["planes"]);var b=new TreeVisibilityBounds(Point(c["center"]),Point(c["extent"]));int result=TreeVisibility.Classify(p,b,F(c["far"]),I(c["individual"])!=0,U(c["scratchWord"]));Check(result==I(c["native"]),"predicate "+cases);++cases;
        }
        foreach(object item in A(f["walkCases"]))
        {
            var c=M(item);var context=new SchedulingState{ContextFlags=U(c["flags"])};var oldContext=new SchedulingState();var runtime=new TreeVisibilityRuntime{CurrentContext=oldContext,PlanesInitialized=Convert.ToBoolean(c["initialPlanesInitialized"])};byte[] bits=Hex((string)c["beforeHex"]);var visits=A(c["nativeVisits"]);int at=0;
            Func<TreeVisibilityVisit,uint> residue=delegate(TreeVisibilityVisit visit)
            {
                if(at>=visits.Length)throw new InvalidOperationException("Portable traversal exceeded retained original predicate sequence.");
                var original=M(visits[at++]);Check(Equal(visit.Bounds.Center,Point(original["center"]))&&Equal(visit.Bounds.Extent,Point(original["extent"]))&&Word(visit.Far)==U(original["farWord"])&&visit.Individual==(I(original["individual"])!=0),"ordered predicate "+cases+"/"+at);return U(original["scratchWord"]);
            };
            var call=new SceneVisibilityPreparationCall{State=context,Options=new SchedulingOptions{TreeEnabled=Convert.ToBoolean(c["enabled"])}};
            // Exercise the actual dispatcher service binding as well as wrapper.
            var service=TreeVisibility.PreparedService(Convert.ToBoolean(c["present"])?Tree(c["tree"]):null,Planes(c["planes"]),bits,runtime,residue);service(call);
            Check(Hex(bits)==(string)c["nativeHex"],"packed bits "+cases);Check(context.ContextFlags==U(c["nativeFlags"]),"context flags "+cases);Check(Object.ReferenceEquals(runtime.CurrentContext,context)==Convert.ToBoolean(c["nativeCurrentContextChanged"]),"current context "+cases);Check(runtime.PlanesInitialized==Convert.ToBoolean(c["nativePlanesInitialized"]),"plane initialization "+cases);Check(at==visits.Length,"all predicate calls consumed "+cases);++cases;
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Prepared original-generated planes and exact percall finite prior-stack fourth-radius words;actual tree math/traversal/control,not recovered live plane producer or whole-renderer behavior."}));return failures==0?0:1;
    }
}
