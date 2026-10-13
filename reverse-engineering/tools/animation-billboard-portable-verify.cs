using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Geometry;
public static class BillboardMeshPacketsVerify
{
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static float F(object v){return PcObjectImage.FromBits(U(v));}static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static string Hash(byte[] v){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(v)).Replace("-","").ToLowerInvariant();}
    static void Write(RenderPacketMemory m,uint p,float[] a){for(int i=0;i<a.Length;++i)m.Dword(p+(uint)i*4,PcObjectImage.ToBits(a[i]));}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<billboard-native-fixtures.json.gz> <result.json>");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var reader=new StreamReader(z))fixture=M(json.DeserializeObject(reader.ReadToEnd()));uint d=U(fixture["base"]),owner=d+0x100,table=d+0x200,record=d+0x300,command=d+0x400,world=d+0x600,resource=d+0x680,origin=d+0x690,output=d+0x720,arena=d+0x800;int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);int seed=Convert.ToInt32(c["seed"]);var memory=new RenderPacketMemory(d,new byte[Convert.ToInt32(fixture["size"])]);for(int i=0x800;i<memory.Bytes.Length;++i)memory.Byte(d+(uint)i,(byte)((i*37+seed*17)&255));
            Write(memory,world,Floats(c["world"]));memory.Dword(resource,U(c["flags"]));Write(memory,origin,Floats(c["origin"]));memory.Dword(d,arena+(uint)(seed%16));memory.Dword(record,owner);memory.Dword(owner+0x50,table);memory.Dword(table,0x12345678);memory.Dword(record+0x14,d+0x780);memory.Dword(record+0x18,d+0x7a0);memory.Byte(command,0x8f);memory.Dword(command+4,resource);for(uint i=0;i<12;++i)memory.Byte(output+i,0xa5);
            string kind=(string)c["kind"];uint? result=null;
            if(kind=="payload")result=BillboardMeshPackets.BuildPayload(memory,d,world,resource,Floats(c["view"]),Floats(c["forward"]));
            else if(kind=="camera")Write(memory,arena,BillboardMeshPackets.FaceCamera(Floats(c["view"]),Floats(c["origin"])));
            else if(kind=="axis")Write(memory,arena,BillboardMeshPackets.FaceAxis(Floats(c["forward"]),Floats(c["origin"])));
            else if(kind=="resource")result=BillboardMeshPackets.ResourceIdentity(U(c["resourceValue"]));
            else BillboardMeshPackets.Build(memory,d,record,command,world,output,U(c["alpha"]),Floats(c["view"]),Floats(c["forward"]));
            // Dispatch cases use its proven billboard branch; no caller skin,
            // morph, cache or material state is needed by this packet adapter.
            string digest=Hash(memory.Bytes);bool pass=digest==(string)c["nativeSha256"]&&(c["nativeResult"]==null?!result.HasValue:result.HasValue&&result.Value==U(c["nativeResult"]));++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind,digest,expected=c["nativeSha256"],result,expectedResult=c["nativeResult"]});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
