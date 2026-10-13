using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class SceneVisibilityPreparation20261013Harness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static bool B(object v){return Convert.ToBoolean(v);}
    static float F(object v){return Convert.ToSingle(v);}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
    static string Hash(byte[] b){using(var h=SHA256.Create())return Hex(h.ComputeHash(b));}
    static int checks,failures,cases,observations;static List<object> errors=new List<object>();
    static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;
        var ma=a as Dictionary<string,object>;var mb=b as Dictionary<string,object>;
        if(ma!=null&&mb!=null){if(ma.Count!=mb.Count)return false;foreach(var v in ma)if(!mb.ContainsKey(v.Key)||!Equal(v.Value,mb[v.Key]))return false;return true;}
        var aa=a as object[];var ab=b as object[];if(aa!=null&&ab!=null){if(aa.Length!=ab.Length)return false;for(int i=0;i<aa.Length;++i)if(!Equal(aa[i],ab[i]))return false;return true;}
        if(a is bool||b is bool||a is string||b is string)return a.Equals(b);
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static byte[] Raw,Tree,Sentinel;static Dictionary<string,object> Current;static int Observation;
    static VisibilityGrid Grid(Dictionary<string,object> c)
    {
        byte[] bytes=Hex((string)c["maskHex"]);Raw=bytes;
        var g=new VisibilityGrid{Width=3,MinimumX=-2,MaximumX=0,MinimumZ=-2,MaximumZ=0,ScaleX=1,ScaleZ=1,StorageMode=I(c["storageMode"]),DecodedByteCount=4,Cells=new byte[9][]};
        for(int i=0;i<9;++i)g.Cells[i]=B(c["nonnull"])?bytes:null;return g;
    }
    static Dictionary<string,object> Snapshot(SceneVisibilityPreparationCall c)
    {
        byte[] bits=c.State.InstanceTreeBits;string pointer=bits==null?"null":Object.ReferenceEquals(bits,c.GridCache.Scratch)?"cache":Object.ReferenceEquals(bits,Raw)?"raw":Object.ReferenceEquals(bits,Tree)?"tree":"sentinel";
        byte[] output=new byte[4];Array.Copy(c.GridCache.Scratch,output,4);
        return new Dictionary<string,object>{{"contextCount",c.State.ContextCount},{"scratch",c.State.ContextScratch},{"pointer",pointer},{"contextFlags",c.State.ContextFlags},{"visibilityActive",c.State.VisibilityActive},{"gridActive",c.GridGlobals.GridActive},{"cacheIndex",c.GridCache.LastCell},{"cacheHex",Hex(output)},{"cameraMode",c.Options.CurrentCameraMode},{"cameraX",c.Camera.World[12]},{"cameraZ",c.Camera.World[14]},{"legacyCount",c.Scene.LegacyInstanceCount},{"alternateCount",c.Scene.AlternateInstanceCount.HasValue?(object)c.Scene.AlternateInstanceCount.Value:null},{"portalAttached",c.State.Portal.VisibilityAttached},{"portalBitsSHA256",Hash(c.State.Portal.VisibilityBits)}};
    }
    static void Observe(SceneVisibilityPreparationCall c,string edge)
    {
        var expected=M(A(Current["serviceObservations"])[Observation++]);++observations;
        Check((string)expected["edge"]==edge&&Equal(Snapshot(c),expected["before"]),"service observation "+cases+" "+edge);
        if(edge=="cameraSwitch")Check(I(expected["arg"])==c.Options.RequestedCameraMode,"camera argument "+cases);
        if(edge=="tree")Check(B(expected["argumentsMatch"]),"original tree argument contract "+cases);
        if(edge=="restore")Check(B(expected["argumentMatches"]),"original restore fixed-buffer contract "+cases);
    }
    static SceneVisibilityPreparationCall Create(Dictionary<string,object> input)
    {
        Tree=Hex("c0ff3355");Sentinel=Hex("12345678");byte[] portalBits=new byte[625];for(int i=0;i<625;++i)portalBits[i]=0xa5;
        var c=new SceneVisibilityPreparationCall{WorkspaceToken=I(input["workspace"]),Grid=Grid(input),GridCache=new VisibilityGridCache{LastCell=I(input["initialCacheIndex"])},GridGlobals=new VisibilityGridContext{GridActive=B(input["initialGridActive"])} };
        Array.Copy(Hex((string)input["initialCacheHex"]),c.GridCache.Scratch,4);
        c.Scene=new SchedulingScene{LegacyInstanceCount=7,AlternateInstanceCount=B(input["alternate"])?(int?)11:null,GridPresent=B(input["gridPresent"]),TreePresent=B(input["treePresent"]),PortalMarkerPresent=B(input["portalPresent"]),PortalScene=new PortalRuntimeScene{Rooms=new RuntimePortalRoom[0],Portals=new RuntimePortal[0],Centers=new Point3[0]}};
        c.Options=new SchedulingOptions{VisibilityEnabled=B(input["visible"]),GridEnabled=B(input["gridEnabled"]),PortalsEnabled=B(input["portalEnabled"]),TreeEnabled=B(input["treeEnabled"]),RequestedCameraMode=I(input["requestedMode"]),CurrentCameraMode=I(input["initialMode"])};
        c.State=new SchedulingState{ContextCount=91,ContextScratch=0x55667788,InstanceTreeBits=Sentinel,ContextFlags=0xffffffff,VisibilityActive=B(input["initialVisibilityActive"]),Portal=new PortalEntryState(portalBits,new uint[0],new short[16])};
        float[] world=new float[16];world[0]=world[5]=world[10]=world[15]=1;world[12]=23;world[14]=24;c.Camera=new PortalEntryCamera{World=world};
        c.Services=new SceneVisibilityPreparationServices{
            SwitchCamera=delegate(SceneVisibilityPreparationCall call,int mode){Observe(call,"cameraSwitch");var v=M(Current["input"]);call.Options.CurrentCameraMode=mode;call.Camera.World[12]=F(v["cameraAfterX"]);call.Camera.World[14]=F(v["cameraAfterZ"]);call.Scene.LegacyInstanceCount+=2;if(call.Scene.AlternateInstanceCount.HasValue)call.Scene.AlternateInstanceCount+=3;call.State.ContextScratch=0x22222222;call.State.InstanceTreeBits=Raw;call.State.ContextFlags=0xf00f;},
            TraverseTree=delegate(SceneVisibilityPreparationCall call){Observe(call,"tree");call.State.ContextCount+=5;call.State.ContextScratch=0x33445566;call.State.InstanceTreeBits=Tree;call.State.ContextFlags=0x120;},
            RestoreCamera=delegate(SceneVisibilityPreparationCall call){Observe(call,"restore");call.Camera.World[12]=9;call.Camera.World[14]=9;}
        };return c;
    }
    static void Execute(SceneVisibilityPreparationCall c,Dictionary<string,object> fixture)
    {
        Current=fixture;Observation=0;var v=M(fixture["input"]);c.WorkspaceToken=I(v["workspace"]);c.Options.RequestedCameraMode=I(v["requestedMode"]);c.State.Calls.Clear();
        Check(Equal(Snapshot(c),fixture["before"]),"initial state "+cases);
        VisibilityInputs result=SceneVisibilityPreparation.Prepare(c);
        Check((result!=null)==B(fixture["returned"]),"return "+cases);
        Check(Equal(Snapshot(c),fixture["native"]),"final state "+cases);
        var calls=new object[c.State.Calls.Count];for(int i=0;i<calls.Length;++i)calls[i]="0x"+c.State.Calls[i].ToString("x");Check(Equal(calls,fixture["calls"]),"call order "+cases);
        Check(Observation==A(fixture["serviceObservations"]).Length,"all service observations consumed "+cases);
        if(result!=null)Check(Object.ReferenceEquals(result.InstanceTreeBits,c.State.InstanceTreeBits)&&Object.ReferenceEquals(result.PortalBits,c.State.Portal.VisibilityBits),"output aliases "+cases);
        ++cases;
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));
        foreach(object item in A(fixture["cases"])){var v=M(item);Execute(Create(M(v["input"])),v);}
        foreach(object sequence in A(fixture["sequences"]))
        {
            var steps=A(sequence);var call=Create(M(M(steps[0])["input"]));
            for(int i=0;i<steps.Length;++i){var step=M(steps[i]);if(i==1)call.Grid=Grid(M(step["input"]));Execute(call,step);}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,serviceObservations=observations,scope="Stateful camera/tree adapters,actual recovered grid and empty portal-entry composition;no full camera/tree/renderer equivalence."}));return failures==0?0:1;
    }
}
