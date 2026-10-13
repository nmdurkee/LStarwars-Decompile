using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class PendingPacketsHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Inflate(byte[] b){using(var f=new MemoryStream(b))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
    static PendingPacketState State(Dictionary<string,object> s){return new PendingPacketState{AllocatorControl=U(s["allocator"]),ReservationCount=U(s["reservationCount"]),SortedHead=U(s["head"]),GlobalCache=U(s["globalCache"]),GlobalHead=U(s["globalHead"]),GlobalTail=U(s["globalTail"]),Count=Convert.ToInt32(s["count"]),Descriptors=Array.ConvertAll(A(s["descriptors"]),v=>U(v))};}
    static bool Same(PendingPacketState a,PendingPacketState b)
    {if(a.AllocatorControl!=b.AllocatorControl||a.ReservationCount!=b.ReservationCount||a.SortedHead!=b.SortedHead||a.GlobalCache!=b.GlobalCache||a.GlobalHead!=b.GlobalHead||a.GlobalTail!=b.GlobalTail||a.Count!=b.Count)return false;for(int i=0;i<24;++i)if(a.Descriptors[i]!=b.Descriptors[i])return false;return true;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=M(Json.DeserializeObject(System.Text.Encoding.UTF8.GetString(Inflate(File.ReadAllBytes(args[0])))));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);byte[] bytes=Inflate(Convert.FromBase64String((string)c["beforeZ"]));var memory=new RenderPacketMemory(U(fixture["base"]),bytes);var state=State(M(c["state"]));int returned=PendingPackets.FinalizeList(memory,state);string digest=Hash(bytes);bool stateMatch=Same(state,State(M(c["nativeState"])));++checks;
            if(digest!=(string)c["nativeSHA256"]||!stateMatch||returned!=Convert.ToInt32(c["nativeReturn"]))
            {++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],stateMatch,returned});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
