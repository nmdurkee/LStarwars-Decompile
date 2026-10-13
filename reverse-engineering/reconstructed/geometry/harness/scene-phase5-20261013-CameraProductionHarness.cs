using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class TreeVisibilityPhase5Harness
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
    static NativeSineTable Sine;static double AngleScale;
    static uint[] UInts(object v){var a=A(v);var b=new uint[a.Length];for(int i=0;i<a.Length;++i)b[i]=U(a[i]);return b;}
    static float[] WordFloats(object v){var words=UInts(v);var b=new float[words.Length];for(int i=0;i<b.Length;++i)b[i]=BitConverter.ToSingle(BitConverter.GetBytes(words[i]),0);return b;}
    static bool Words(float[] values,object expected){var words=UInts(expected);if(values==null||words.Length!=values.Length)return false;for(int i=0;i<values.Length;++i)if(Word(values[i])!=words[i])return false;return true;}
    static int[] Ints(object v){var a=A(v);var b=new int[a.Length];for(int i=0;i<a.Length;++i)b[i]=I(a[i]);return b;}
    static CameraPlaneGlobals Globals(object v)
    {
        var g=M(v);return new CameraPlaneGlobals{Sine=Sine,AngleScale=AngleScale,Correction=Floats(g["correction"]),ClipScales=Floats(g["clipScales"]),FarBias=F(g["farBias"]),Orthographic=Convert.ToBoolean(g["orthographic"]),OrthographicScale=F(g["orthographicScale"]),CullingMode=I(g["cullingMode"]),ScreenSize=Ints(g["screenSize"]),SourceSize=Ints(g["sourceSize"]),Template=Floats(g["template"]),Auxiliary=Floats(g["auxiliary"]),ClipTransform=Floats(g["clipTransform"])};
    }
    static CameraPlaneState State(object v)
    {
        var s=M(v);var m=M(s["matrixWords"]);return new CameraPlaneState{Current=WordFloats(s["currentWords"]),Base=WordFloats(s["baseWords"]),Saved=WordFloats(s["savedWords"]),Mode=I(s["mode"]),PreviousCullingMode=I(s["previousCullingMode"]),View=WordFloats(m["view"]),Projection=WordFloats(m["projection"]),ClipTransform=WordFloats(m["clipTransform"]),AuxiliaryCopy=WordFloats(m["auxiliaryCopy"]),Combined=WordFloats(m["combined"]),Secondary=WordFloats(m["secondary"]),Primary=WordFloats(m["primary"]),SymmetricCache=WordFloats(m["symmetricCache"]),MappedCombined=WordFloats(m["mappedCombined"]),MappedProjection=WordFloats(m["mappedProjection"]),EdgePlanes=WordFloats(m["edgePlanes"]),AsymmetricCache=WordFloats(m["asymmetricCache"]),Scales=WordFloats(s["scaleWords"]),Frustum=Hex((string)s["frustumHex"]),PassWord=U(s["passWord"]),ResetWord=U(s["resetWord"])};
    }
    static void CheckState(CameraPlaneState state,object original,string label)
    {
        var s=M(original);var m=M(s["matrixWords"]);bool matches=Words(state.Current,s["currentWords"])&&Words(state.Base,s["baseWords"])&&Words(state.Saved,s["savedWords"])&&state.Mode==I(s["mode"])&&state.PreviousCullingMode==I(s["previousCullingMode"])&&Words(state.Scales,s["scaleWords"])&&Hex(state.Frustum)==(string)s["frustumHex"]&&state.PassWord==U(s["passWord"])&&state.ResetWord==U(s["resetWord"]);
        matches=matches&&Words(state.View,m["view"])&&Words(state.Projection,m["projection"])&&Words(state.ClipTransform,m["clipTransform"])&&Words(state.AuxiliaryCopy,m["auxiliaryCopy"])&&Words(state.Combined,m["combined"])&&Words(state.Secondary,m["secondary"])&&Words(state.Primary,m["primary"])&&Words(state.SymmetricCache,m["symmetricCache"])&&Words(state.MappedCombined,m["mappedCombined"])&&Words(state.MappedProjection,m["mappedProjection"])&&Words(state.EdgePlanes,m["edgePlanes"])&&Words(state.AsymmetricCache,m["asymmetricCache"]);Check(matches,label);
    }
    static CameraPlaneServices Services(List<string> events,object[] originalEvents,string label)
    {
        var devices=new List<Dictionary<string,object>>();foreach(object value in originalEvents){var e=M(value);if((string)e["edge"]=="deviceTransform")devices.Add(e);}int at=0;
        return new CameraPlaneServices{
            Multiply=delegate(float[] a,float[] b){events.Add("matrix");return TreePlaneProduction.ScalarMatrixAdapter(a,b);},
            UpdateLight=delegate(CameraPlaneState state){events.Add("lightState");},
            UpdateRenderCache=delegate(CameraPlaneState state){events.Add("renderCache");},
            DeviceTransform=delegate(int index,float[] values){events.Add("deviceTransform");if(at>=devices.Count)throw new InvalidOperationException("Unexpected portable device transform.");var e=devices[at++];Check(index==I(e["index"])&&Words(values,e["words"]),label+" device transform "+at);}
        };
    }
    static string NativeEvents(object[] events){var values=new List<string>();foreach(object value in events)values.Add((string)M(value)["edge"]);return String.Join(",",values.ToArray());}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;
        using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=M(Json.DeserializeObject(r.ReadToEnd()));string sinePath=Path.GetFullPath(Path.Combine(Path.GetDirectoryName(args[0]),"..",(string)f["sineFile"]));byte[] sineBytes=File.ReadAllBytes(sinePath);using(var sha=System.Security.Cryptography.SHA256.Create())Check(Hex(sha.ComputeHash(sineBytes))==(string)f["sineSHA256"],"bound native sine table");Sine=NativeSineTable.DecodeLittleEndian(sineBytes);AngleScale=Convert.ToDouble(f["angleScale"]);int cases=0;
        foreach(object item in A(f["inverseCases"]))
        {var c=M(item);float[] input=WordFloats(c["inputWords"]);float[] output=CameraPlaneProduction.Inverse(input);if(Convert.ToBoolean(c["inPlace"]))input=output;Check(Words(output,c["nativeWords"]),"inverse "+cases);++cases;}
        foreach(object item in A(f["projectionCases"]))
        {var c=M(item);Check(Words(CameraPlaneProduction.Projection(WordFloats(c["cameraWords"]),Globals(c["globals"])),c["nativeWords"]),"projection "+cases);++cases;}
        foreach(object item in A(f["clipCases"]))
        {
            var c=M(item);var state=new CameraPlaneState();var services=Services(new List<string>(),new object[0],"clip "+cases);bool asymmetric=Convert.ToBoolean(c["asymmetric"]);float[] output=asymmetric?CameraPlaneProduction.Asymmetric(state,WordFloats(c["cameraWords"]),WordFloats(c["viewWords"]),Globals(c["globals"]),services):CameraPlaneProduction.Symmetric(state,WordFloats(c["cameraWords"]),WordFloats(c["viewWords"]),Globals(c["globals"]),services);Check(Words(asymmetric?state.AsymmetricCache:state.SymmetricCache,c["nativeCacheWords"]),"clip cache "+cases);Check(Words(output,c["nativeWords"]),"clip composed output "+cases);++cases;
        }
        foreach(object item in A(f["frustumCases"]))
        {var c=M(item);var services=Services(new List<string>(),new object[0],"frustum "+cases);Check(Hex(CameraPlaneProduction.OrdinaryFrustum(WordFloats(c["cameraWords"]),WordFloats(c["viewWords"]),Floats(c["scales"]),Floats(c["template"]),services))==(string)c["nativeHex"],"ordinary frustum "+cases);++cases;}
        foreach(object item in A(f["cameraCases"]))
        {
            var c=M(item);var state=State(c["before"]);var g=Globals(c["globals"]);var events=new List<string>();var originalEvents=A(c["nativeEvents"]);var services=Services(events,originalEvents,"camera "+cases);string kind=(string)c["kind"];
            if(kind=="apply")CameraPlaneProduction.ApplyNormal(state,WordFloats(c["cameraWords"]),g,services);else if(kind=="restore")CameraPlaneProduction.RestoreNormal(state,WordFloats(c["cameraWords"]),g,services);else CameraPlaneProduction.Switch(state,I(c["requested"]),g,services);CheckState(state,c["native"],"complete numeric camera image "+cases);Check(String.Join(",",events.ToArray())==NativeEvents(originalEvents),"camera service order "+cases);++cases;
        }
        foreach(object item in A(f["dispatchCases"]))
        {
            var c=M(item);var camera=State(c["beforeCamera"]);var g=Globals(c["globals"]);var events=new List<string>();var originalEvents=A(c["nativeEvents"]);var services=Services(events,originalEvents,"dispatcher "+cases);var planes=new TreePlaneRuntime();var oldContext=new SchedulingState();planes.Visibility.CurrentContext=oldContext;var state=new SchedulingState{ContextCount=-7,ContextScratch=0xabcdef,InstanceTreeBits=new byte[]{0x55},ContextFlags=0xc012,VisibilityActive=Convert.ToBoolean(c["beforeVisibilityActive"])};byte[] bits=Hex((string)c["beforeHex"]);var visits=A(c["nativeVisits"]);int at=0;var tree=Tree(c["tree"]);
            Func<TreeVisibilityVisit,uint> residue=delegate(TreeVisibilityVisit visit)
            {
                if(at>=visits.Length)throw new InvalidOperationException("Portable traversal exceeded native sequence.");var v=M(visits[at++]);uint stale=U(v["scratchWord"]);bool order=Equal(visit.Bounds.Center,Point(v["center"]))&&Equal(visit.Bounds.Extent,Point(v["extent"]))&&Word(visit.Far)==U(v["farWord"])&&visit.Individual==(I(v["individual"])!=0);int value=TreeVisibility.Classify(planes.Prepared,visit.Bounds,visit.Far,visit.Individual,stale);Check(order&&value==I(v["nativeResult"]),"ordered original tree predicate "+cases+"/"+at);return stale;
            };
            var call=new SceneVisibilityPreparationCall{Scene=new SchedulingScene{LegacyInstanceCount=32,TreePresent=Convert.ToBoolean(c["present"])},Options=new SchedulingOptions{VisibilityEnabled=Convert.ToBoolean(c["visible"]),TreeEnabled=Convert.ToBoolean(c["enabled"]),RequestedCameraMode=I(c["requested"]),CurrentCameraMode=I(c["mode"])},State=state,WorkspaceToken=I(c["workspaceToken"])};call.Services=CameraPlaneProduction.PreparationServices(camera,g,services,planes,tree,bits,residue);var traverse=call.Services.TraverseTree;call.Services.TraverseTree=delegate(SceneVisibilityPreparationCall current){events.Add("tree");traverse(current);};var returned=SceneVisibilityPreparation.Prepare(call);var context=M(c["nativeContext"]);
            CheckState(camera,c["nativeCamera"],"dispatcher numeric camera image "+cases);Check((returned!=null)==Convert.ToBoolean(c["returned"]),"dispatcher return "+cases);Check(state.ContextCount==I(context["count"]),"dispatcher count "+cases);Check(state.ContextScratch==I(context["scratch"]),"dispatcher scratch "+cases);Check((state.InstanceTreeBits==null)==(U(context["pointer"])==0),"dispatcher instance pointer gate "+cases);Check(state.ContextFlags==U(context["flags"]),"dispatcher flags "+cases);Check(state.VisibilityActive==Convert.ToBoolean(c["nativeVisibilityActive"]),"dispatcher visibility active "+cases);Check(Object.ReferenceEquals(planes.Visibility.CurrentContext,state)==Convert.ToBoolean(c["nativeCurrentTreeContextChanged"]),"dispatcher current tree context "+cases);Check(planes.Visibility.PlanesInitialized==Convert.ToBoolean(c["nativePlanesInitialized"]),"dispatcher plane initialization "+cases);Check(Hex(bits)==(string)c["nativeHex"],"dispatcher packed bits "+cases);Check(at==visits.Length,"dispatcher all predicate calls "+cases);Check(String.Join(",",events.ToArray())==NativeEvents(originalEvents),"dispatcher service order "+cases);++cases;
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Normal finite camera inverse/projection/clipping/frustum, switch/restore and populated real visibility-preparation composition. Imported D3DX scalar/device/light/cache services and exact percall finite tree stack residue remain explicit."}));return failures==0?0:1;
    }
}
