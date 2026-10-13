using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class TreeVisibilityPhase4Harness
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
    static uint[] UInts(object v){var a=A(v);var b=new uint[a.Length];for(int i=0;i<a.Length;++i)b[i]=U(a[i]);return b;}
    static bool Words(float[] values,object expected){var words=UInts(expected);if(words.Length!=values.Length)return false;for(int i=0;i<values.Length;++i)if(Word(values[i])!=words[i])return false;return true;}
    static Point3 WordPoint(object v){var a=UInts(v);return new Point3(BitConverter.ToSingle(BitConverter.GetBytes(a[0]),0),BitConverter.ToSingle(BitConverter.GetBytes(a[1]),0),BitConverter.ToSingle(BitConverter.GetBytes(a[2]),0));}
    static TreePlaneInputs Input(Dictionary<string,object> c){return new TreePlaneInputs{Near=F(c["near"]),Far=F(c["far"]),Scales=Floats(c["scales"]),Template=Floats(c["template"]),View=Floats(c["view"]),Direction=Point(c["direction"]),Position=Point(c["position"])};}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;
        using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=M(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
        foreach(object item in A(f["producerCases"]))
        {
            var c=M(item);var runtime=new TreePlaneRuntime();var input=new TreePlaneInputs{Near=F(c["near"]),Scales=Floats(c["scales"]),Template=Floats(c["template"])};TreePlaneProduction.BuildLocal(input,runtime);var expected=A(c["nativeLocalWords"]);
            Check(Words(runtime.LocalOuter,expected[0])&&Words(runtime.LocalInner,expected[1]),"local plane words "+cases);Check(runtime.Visibility.PlanesInitialized,"local initialized "+cases);++cases;
        }
        foreach(object item in A(f["transformCases"]))
        {
            var c=M(item);var local=A(c["local"]);var runtime=new TreePlaneRuntime{LocalOuter=Floats(local[0]),LocalInner=Floats(local[1])};var input=new TreePlaneInputs{View=Floats(c["view"]),Direction=c.ContainsKey("directionWords")?WordPoint(c["directionWords"]):Point(c["direction"]),Position=c.ContainsKey("positionWords")?WordPoint(c["positionWords"]):Point(c["position"])};int calls=0;
            var p=TreePlaneProduction.Transform(input,runtime,delegate(float[] a,float[] b){++calls;return TreePlaneProduction.ScalarMatrixAdapter(a,b);});var expected=M(c["nativePlaneWords"]);
            Check(Words(p.Outer,expected["outer"])&&Words(p.Inner,expected["inner"])&&Words(p.AbsOuter,expected["absOuter"])&&Words(p.AbsInner,expected["absInner"])&&Words(p.Depth,expected["depth"])&&Words(p.AbsDepth,expected["absDepth"]),"transformed plane words "+cases);Check(calls==2,"matrix adapter twice "+cases);++cases;
        }
        foreach(object item in A(f["composedCases"]))
        {
            var c=M(item);var input=Input(c);var runtime=new TreePlaneRuntime();TreePlaneProduction.BuildLocal(input,runtime);runtime.Visibility.PlanesInitialized=Convert.ToBoolean(c["initialPlanesInitialized"]);var context=new SchedulingState{ContextFlags=U(c["flags"])};var tree=Tree(c["tree"]);var clips=new ClipObject[32];var bounds=new ClipBounds[32];var flags=new byte[32];for(int i=0;i<32;++i){clips[i]=new ClipObject{ItemIndices=new[]{i*2+1}};bounds[i]=new ClipBounds();}var scene=new SceneVisibility(clips,bounds,flags,0){Flags=(uint)I(c["parity"])*0x8000u};int parity=I(c["parity"]);Array.Copy(Hex((string)c["beforeHex"]),scene.ClipBits[parity],8);Array.Copy(Hex((string)c["previousHex"]),scene.ClipBits[1-parity],8);byte[] items=Hex((string)c["itemBeforeHex"]);var visits=A(c["nativeVisits"]);int at=0,matrixCalls=0;
            Func<TreeVisibilityVisit,uint> residue=delegate(TreeVisibilityVisit visit)
            {
                if(at>=visits.Length)throw new InvalidOperationException("Portable traversal exceeded original predicate sequence.");var original=M(visits[at++]);Check(Equal(visit.Bounds.Center,Point(original["center"]))&&Equal(visit.Bounds.Extent,Point(original["extent"]))&&Word(visit.Far)==U(original["farWord"])&&visit.Individual==(I(original["individual"])!=0),"ordered predicate "+cases+"/"+at);return U(original["scratchWord"]);
            };
            TreePlaneProduction.ProduceAndPatch(context,tree,input,runtime,scene,items,delegate(float[] a,float[] b){++matrixCalls;Check(Object.ReferenceEquals(runtime.Visibility.CurrentContext,context)&&context.ContextFlags==U(c["nativeFlags"]),"context before matrix adapter "+cases);return TreePlaneProduction.ScalarMatrixAdapter(a,b);},residue);
            Check(Hex(scene.ClipBits[parity])==(string)c["nativeHex"],"packed bits "+cases);Check(Hex(items)==(string)c["nativeItemHex"],"paired clip controls "+cases);Check(context.ContextFlags==U(c["nativeFlags"]),"context flags "+cases);Check(Object.ReferenceEquals(runtime.Visibility.CurrentContext,context),"current context "+cases);Check(runtime.Visibility.PlanesInitialized,"plane initialization "+cases);Check(at==visits.Length,"all predicate calls consumed "+cases);Check(matrixCalls==2,"composed matrix calls "+cases);++cases;
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Actual finite plane producers with explicit D3DX scalar adapter/runtime template;populated tree traversal with exact finite prior-stack fourth radius and paired clip control writes. Compiled replay execution status is separate."}));return failures==0?0:1;
    }
}
