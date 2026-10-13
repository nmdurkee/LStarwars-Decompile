using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class CameraCpuRendererCompositionPhase9Harness
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
    static CameraViewportInputs ViewportInput(object value)
    {var v=M(value);return new CameraViewportInputs{Screen=Ints(v["screen"]),Rectangle=Ints(v["rectangle"]),Ranges=Floats(v["ranges"]),DepthWords=UInts(v["depthWords"])};}
    static CameraViewportState ViewportState(object value,float[] identity,CameraPlaneGlobals g)
    {var v=M(value);g.Correction=WordFloats(v["correctionWords"]);g.ClipScales=WordFloats(v["clipScaleWords"]);g.Auxiliary=WordFloats(v["auxiliaryWords"]);g.ClipTransform=WordFloats(v["clipTransformWords"]);return new CameraViewportState{Dirty=U(v["dirty"]),Globals=g,Identity=identity};}
    static bool ViewportMatches(CameraViewportState state,object value)
    {var v=M(value);return state.Dirty==U(v["dirty"])&&Words(state.Globals.Correction,v["correctionWords"])&&Words(state.Globals.ClipScales,v["clipScaleWords"])&&Words(state.Globals.Auxiliary,v["auxiliaryWords"])&&Words(state.Globals.ClipTransform,v["clipTransformWords"]);}
    static Action<uint[]> ViewportService(CameraViewportState state,object[] originals,List<string> events,string label)
    {
        var expected=new List<Dictionary<string,object>>();foreach(object item in originals){var e=M(item);if((string)e["edge"]=="deviceViewport")expected.Add(e);}int at=0;
        return delegate(uint[] words){events.Add("deviceViewport");if(at>=expected.Count)throw new InvalidOperationException("Unexpected viewport service.");var e=expected[at++];var want=UInts(e["words"]);bool same=words.Length==want.Length;for(int i=0;same&&i<words.Length;++i)same=words[i]==want[i];Check(same,label+" six raw viewport words");Check(ViewportMatches(state,e["stateAtService"]),label+" ordered viewport state atservice");};
    }
    static CameraAlternateView Frame(object value){var v=M(value);return new CameraAlternateView{ConversionMode=I(v["mode"]),Reference=WordFloats(v["referenceWords"]),TemplateWords=UInts(v["templateWords"])};}
    static CameraRenderCache CpuCamera(object value){var v=M(value);return new CameraRenderCache{Image=Hex((string)v["cameraImageHex"]),Counter=U(v["counter"]),ShortCounter=Convert.ToUInt16(v["cameraShortCounter"])};}
    static LightRenderCache CpuLight(object value){var v=M(value);return new LightRenderCache{Words=UInts(v["lightImageWords"]),ShortCounter=Convert.ToUInt16(v["lightShortCounter"]),Dirty=U(v["lightDirty"])};}
    static LightNumericGlobals CpuLightGlobals(object before,object globals){var b=M(before);var g=M(globals);return new LightNumericGlobals{DirectionWords=UInts(b["directionWords"]),ColorWords=UInts(b["colorWords"]),Aim=WordFloats(g["aimWords"]),IdentityWords=UInts(g["identityWords"])};}
    static RenderCacheInputs CpuCacheInputs(object value){var v=M(value);return new RenderCacheInputs{Screen=Ints(v["screen"]),Source=Ints(v["source"]),Rectangle=Ints(v["rectangle"]),Origin=Ints(v["origin"])};}
    static bool UIntWords(uint[] actual,object value){var expected=UInts(value);if(actual==null||actual.Length!=expected.Length)return false;for(int i=0;i<actual.Length;++i)if(actual[i]!=expected[i])return false;return true;}
    static bool CpuMatches(CameraRenderCache camera,LightRenderCache light,LightNumericGlobals globals,object value){var v=M(value);return Hex(camera.Image)==(string)v["cameraImageHex"]&&camera.Counter==U(v["counter"])&&camera.ShortCounter==Convert.ToUInt16(v["cameraShortCounter"])&&UIntWords(light.Words,v["lightImageWords"])&&light.ShortCounter==Convert.ToUInt16(v["lightShortCounter"])&&light.Dirty==U(v["lightDirty"])&&UIntWords(globals.DirectionWords,v["directionWords"])&&UIntWords(globals.ColorWords,v["colorWords"]);}
    static CameraPlaneServices CpuServices(CameraPlaneServices matrixAndDevice,CameraRenderCache camera,RenderCacheInputs inputs,LightRenderCache light,LightNumericGlobals globals,object[] original,List<string> events,string label,Action consumed)
    {
        int at=0;var services=CameraCpuRendererServices.Bind(matrixAndDevice,camera,inputs,light,globals);var lightCall=services.UpdateLight;var cacheCall=services.UpdateRenderCache;
        Action<string,CameraPlaneState,Action<CameraPlaneState>> invoke=delegate(string edge,CameraPlaneState state,Action<CameraPlaneState> action){if(at>=original.Length)throw new InvalidOperationException("Unexpected CPU renderer callback.");var item=M(original[at++]);Check((string)item["edge"]==edge&&CpuMatches(camera,light,globals,item["before"]),label+" renderer receiver/order "+at);events.Add(edge);action(state);Check(CpuMatches(camera,light,globals,item["native"]),label+" recovered CPU renderer bytes "+at);consumed();};services.UpdateLight=delegate(CameraPlaneState state){invoke("lightState",state,lightCall);};services.UpdateRenderCache=delegate(CameraPlaneState state){invoke("renderCache",state,cacheCall);};return services;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=M(Json.DeserializeObject(r.ReadToEnd()));string sinePath=Path.GetFullPath(Path.Combine(Path.GetDirectoryName(args[0]),"..",(string)f["sineFile"]));byte[] sineBytes=File.ReadAllBytes(sinePath);using(var sha=System.Security.Cryptography.SHA256.Create())Check(Hex(sha.ComputeHash(sineBytes))==(string)f["sineSHA256"],"bound native sine table");Sine=NativeSineTable.DecodeLittleEndian(sineBytes);AngleScale=Convert.ToDouble(f["angleScale"]);float[] identity=WordFloats(f["identityWords"]);int cases=0;
        foreach(object item in A(f["pipelineCases"]))
        {
            var c=M(item);var camera=State(c["before"]);var g=Globals(c["globals"]);var viewport=ViewportState(c["beforeViewport"],identity,g);var input=ViewportInput(c["viewportInput"]);var frame=Frame(c["frame"]);var originals=A(c["nativeEvents"]);var events=new List<string>();var cpuCamera=CpuCamera(c["beforeRenderer"]);var cpuLight=CpuLight(c["beforeRenderer"]);var cpuGlobals=CpuLightGlobals(c["beforeRenderer"],c["rendererLightGlobals"]);int cpuCalls=0;var services=CpuServices(Services(events,originals,"pipeline "+cases),cpuCamera,CpuCacheInputs(c["rendererInputs"]),cpuLight,cpuGlobals,A(c["nativeRendererEvents"]),events,"pipeline "+cases,delegate{++cpuCalls;});var emit=ViewportService(viewport,originals,events,"pipeline "+cases);string kind=(string)c["kind"];
            if(kind=="apply")CameraNumericPipeline.Apply(camera,WordFloats(c["cameraWords"]),viewport,input,frame,I(c["reuseArgument"]),emit,services);else if(kind=="restore")CameraNumericPipeline.Restore(camera,WordFloats(c["cameraWords"]),viewport,input,frame,emit,services);else if(kind=="switch")CameraNumericPipeline.Switch(camera,I(c["requested"]),viewport,input,frame,emit,services);else throw new ArgumentException("Unknown retained pipeline kind.");CheckState(camera,c["native"],"complete numeric camera image "+cases);Check(ViewportMatches(viewport,c["nativeViewport"]),"complete viewport image "+cases);Check(String.Join(",",events.ToArray())==NativeEvents(originals),"composed service order "+cases);Check(CpuMatches(cpuCamera,cpuLight,cpuGlobals,c["nativeRenderer"]),"final composed CPU renderer image "+cases);Check(cpuCalls==A(c["nativeRendererEvents"]).Length,"all CPU renderer calls "+cases);++cases;
        }
        foreach(object item in A(f["dispatchCases"]))
        {
            var c=M(item);var camera=State(c["before"]);var g=Globals(c["globals"]);var viewport=ViewportState(c["beforeViewport"],identity,g);var input=ViewportInput(c["viewportInput"]);var frame=Frame(c["frame"]);var events=new List<string>();var originalEvents=A(c["nativeEvents"]);var cpuCamera=CpuCamera(c["beforeRenderer"]);var cpuLight=CpuLight(c["beforeRenderer"]);var cpuGlobals=CpuLightGlobals(c["beforeRenderer"],c["rendererLightGlobals"]);int cpuCalls=0;var services=CpuServices(Services(events,originalEvents,"dispatcher "+cases),cpuCamera,CpuCacheInputs(c["rendererInputs"]),cpuLight,cpuGlobals,A(c["nativeRendererEvents"]),events,"dispatcher "+cases,delegate{++cpuCalls;});var planes=new TreePlaneRuntime();var oldContext=new SchedulingState();planes.Visibility.CurrentContext=oldContext;var state=new SchedulingState{ContextCount=-7,ContextScratch=0xabcdef,InstanceTreeBits=new byte[]{0x55},ContextFlags=0xc012,VisibilityActive=Convert.ToBoolean(c["beforeVisibilityActive"])};byte[] bits=Hex((string)c["beforeHex"]);var visits=A(c["nativeVisits"]);int at=0;var tree=Tree(c["tree"]);
            Func<TreeVisibilityVisit,uint> residue=delegate(TreeVisibilityVisit visit)
            {
                if(at>=visits.Length)throw new InvalidOperationException("Portable traversal exceeded native sequence.");var v=M(visits[at++]);uint stale=U(v["scratchWord"]);bool order=Equal(visit.Bounds.Center,Point(v["center"]))&&Equal(visit.Bounds.Extent,Point(v["extent"]))&&Word(visit.Far)==U(v["farWord"])&&visit.Individual==(I(v["individual"])!=0);int value=TreeVisibility.Classify(planes.Prepared,visit.Bounds,visit.Far,visit.Individual,stale);Check(order&&value==I(v["nativeResult"]),"ordered original tree predicate "+cases+"/"+at);return stale;
            };
            var call=new SceneVisibilityPreparationCall{Scene=new SchedulingScene{LegacyInstanceCount=32,TreePresent=Convert.ToBoolean(c["present"])},Options=new SchedulingOptions{VisibilityEnabled=Convert.ToBoolean(c["visible"]),TreeEnabled=Convert.ToBoolean(c["enabled"]),RequestedCameraMode=I(c["requested"]),CurrentCameraMode=I(c["mode"])},State=state,WorkspaceToken=I(c["workspaceToken"])};call.Services=CameraNumericPipeline.PreparationServices(camera,viewport,input,frame,ViewportService(viewport,originalEvents,events,"dispatcher "+cases),services,planes,tree,bits,residue);var traverse=call.Services.TraverseTree;call.Services.TraverseTree=delegate(SceneVisibilityPreparationCall current){events.Add("tree");traverse(current);};var returned=SceneVisibilityPreparation.Prepare(call);var context=M(c["nativeContext"]);
            CheckState(camera,c["native"],"dispatcher numeric camera image "+cases);Check(ViewportMatches(viewport,c["nativeViewport"]),"dispatcher viewport image "+cases);Check((returned!=null)==Convert.ToBoolean(c["returned"]),"dispatcher return "+cases);Check(state.ContextCount==I(context["count"]),"dispatcher count "+cases);Check(state.ContextScratch==I(context["scratch"]),"dispatcher scratch "+cases);Check((state.InstanceTreeBits==null)==(U(context["pointer"])==0),"dispatcher instance pointer gate "+cases);Check(state.ContextFlags==U(context["flags"]),"dispatcher flags "+cases);Check(state.VisibilityActive==Convert.ToBoolean(c["nativeVisibilityActive"]),"dispatcher visibility active "+cases);Check(Object.ReferenceEquals(planes.Visibility.CurrentContext,state)==Convert.ToBoolean(c["nativeCurrentTreeContextChanged"]),"dispatcher current tree context "+cases);Check(planes.Visibility.PlanesInitialized==Convert.ToBoolean(c["nativePlanesInitialized"]),"dispatcher plane initialization "+cases);Check(Hex(bits)==(string)c["nativeHex"],"dispatcher packed bits "+cases);Check(at==visits.Length,"dispatcher all predicate calls "+cases);Check(String.Join(",",events.ToArray())==NativeEvents(originalEvents),"dispatcher service order "+cases);Check(CpuMatches(cpuCamera,cpuLight,cpuGlobals,c["nativeRenderer"]),"final composed CPU renderer image "+cases);Check(cpuCalls==A(c["nativeRendererEvents"]).Length,"all CPU renderer calls "+cases);++cases;
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Finite original camera/viewport/reuse/alternate view, populated visibility dispatch and recovered CPU light/cache byte outputs with shared counters. Imported matrix/device policy, authored runtime bindings and exact caller residue remain explicit."}));return failures==0?0:1;
    }
}
