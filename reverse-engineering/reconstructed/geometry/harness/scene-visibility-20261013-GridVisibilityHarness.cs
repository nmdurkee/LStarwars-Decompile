using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class GridVisibility20261013Harness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");
        Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))fixture=M(Json.DeserializeObject(r.ReadToEnd()));
        int checks=0,failures=0;var errors=new List<object>();
        Action<bool,string> check=delegate(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}};
        foreach(object item in A(fixture["floors"]))
        {var c=A(item);check(GridVisibility.Floor(Convert.ToSingle(c[1]))==Convert.ToInt32(c[2]),"floor "+checks);}
        foreach(object item in A(fixture["grid"]))
        {
            var c=M(item);
            if((string)c["kind"]=="rle")
            {
                byte[] stream=Hex((string)c["streamHex"]);int count=Convert.ToInt32(c["length"]);
                var grid=new VisibilityGrid{Width=3,MinimumX=-2,MaximumX=0,MinimumZ=-2,MaximumZ=0,ScaleX=1,ScaleZ=1,StorageMode=1,DecodedByteCount=count,Cells=new byte[9][]};for(int i=0;i<9;++i)grid.Cells[i]=stream;
                var cache=new VisibilityGridCache();for(int i=0;i<625;++i)cache.Scratch[i]=0x77;
                var ctx=new VisibilityGridContext();GridVisibility.Produce(grid,-1,-1,cache,ctx);
                byte[] output=new byte[count];Array.Copy(cache.Scratch,output,count);
                check(Hex(output)==(string)c["outputHex"],"decoded "+checks);check(cache.LastCell==4&&ctx.GridActive&&Object.ReferenceEquals(ctx.InstanceTreeBits,cache.Scratch),"cache state "+checks);
                grid.Cells[4]=new byte[]{0xff};GridVisibility.Produce(grid,-1,-1,cache,ctx);Array.Copy(cache.Scratch,output,count);check(Hex(output)==(string)c["outputHex"],"cache hit "+checks);
            }
            else
            {
                byte[] stream=Convert.ToBoolean(c["nonnull"])?new byte[]{0x10}:null,sentinel=new byte[]{0x12};
                var grid=new VisibilityGrid{Width=3,MinimumX=-2,MaximumX=0,MinimumZ=-2,MaximumZ=0,ScaleX=1,ScaleZ=1,StorageMode=Convert.ToInt32(c["mode"]),DecodedByteCount=4,Cells=new byte[9][]};for(int i=0;i<9;++i)grid.Cells[i]=stream;
                var cache=new VisibilityGridCache();var ctx=new VisibilityGridContext{InstanceTreeBits=sentinel,GridActive=true};GridVisibility.Produce(grid,Convert.ToSingle(c["x"]),Convert.ToSingle(c["z"]),cache,ctx);
                uint pointer=Convert.ToUInt32(c["nativePointer"]);byte[] expected=pointer==0?null:pointer==0x966390?cache.Scratch:pointer==0x12345678?sentinel:stream;
                bool active=Convert.ToUInt32(c["nativeActive"])!=0;
                check(Object.ReferenceEquals(ctx.InstanceTreeBits,expected)&&ctx.GridActive==active&&cache.LastCell==Convert.ToInt32(c["nativeCacheIndex"]),"selection "+checks);
            }
        }
        foreach(object item in A(fixture["coordinates"]))
        {
            var c=M(item);int width=Convert.ToInt32(c["width"]);var grid=new VisibilityGrid{Width=width,MinimumX=Convert.ToSingle(c["minimumX"]),MaximumX=Convert.ToSingle(c["maximumX"]),MinimumZ=Convert.ToSingle(c["minimumZ"]),MaximumZ=Convert.ToSingle(c["maximumZ"]),ScaleX=Convert.ToSingle(c["scaleX"]),ScaleZ=Convert.ToSingle(c["scaleZ"]),StorageMode=0,DecodedByteCount=4,Cells=new byte[width*width][]};
            for(int i=0;i<grid.Cells.Length;++i)grid.Cells[i]=new byte[]{(byte)i};
            var cache=new VisibilityGridCache();var ctx=new VisibilityGridContext();GridVisibility.Produce(grid,Convert.ToSingle(c["cameraX"]),Convert.ToSingle(c["cameraZ"]),cache,ctx);
            int index=Convert.ToInt32(c["nativeCellIndex"]);check(Object.ReferenceEquals(ctx.InstanceTreeBits,grid.Cells[index])&&ctx.GridActive==(Convert.ToUInt32(c["nativeActive"])!=0)&&cache.LastCell==-1,"non-unit coordinate "+checks);
        }
        foreach(object item in A(fixture["crossGrid"]))
        {
            var c=M(item);int count=Convert.ToInt32(c["decodedByteCount"]);var first=new VisibilityGrid{Width=3,MinimumX=-2,MaximumX=0,MinimumZ=-2,MaximumZ=0,ScaleX=1,ScaleZ=1,StorageMode=1,DecodedByteCount=count,Cells=new byte[9][]};
            var second=new VisibilityGrid{Width=3,MinimumX=-2,MaximumX=0,MinimumZ=-2,MaximumZ=0,ScaleX=1,ScaleZ=1,StorageMode=1,DecodedByteCount=count,Cells=new byte[9][]};
            for(int i=0;i<9;++i){first.Cells[i]=Hex((string)c["firstStreamHex"]);second.Cells[i]=Hex((string)c["secondStreamHex"]);}
            var cache=new VisibilityGridCache();var ctx=new VisibilityGridContext();float x=Convert.ToSingle(c["cameraX"]),z=Convert.ToSingle(c["cameraZ"]);GridVisibility.Produce(first,x,z,cache,ctx);GridVisibility.Produce(second,x,z,cache,ctx);
            byte[] output=new byte[count];Array.Copy(cache.Scratch,output,count);check(Hex(output)==(string)c["nativeOutputHex"]&&cache.LastCell==Convert.ToInt32(c["nativeCacheIndex"])&&Object.ReferenceEquals(ctx.InstanceTreeBits,cache.Scratch)&&ctx.GridActive==(Convert.ToUInt32(c["nativeActive"])!=0),"cross-grid same-cell cache reuse "+checks);
        }
        int portableReplayCases=A(fixture["floors"]).Length+A(fixture["grid"]).Length+A(fixture["coordinates"]).Length+A(fixture["crossGrid"]).Length;
        int dispatcherEvidenceOnly=A(fixture["dispatcher"]).Length;
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases,dispatcherEvidenceOnly,retainedFixtureCases=portableReplayCases+dispatcherEvidenceOnly,scope="Saved original floor and grid cases only; dispatcher adapters remain native/Python evidence."}));return failures==0?0:1;
    }
}
