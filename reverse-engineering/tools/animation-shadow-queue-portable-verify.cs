using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class CharacterShadowQueueVerify
{
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static CharacterShadowBinding Binding(object v)
    {var a=A(v);return new CharacterShadowBinding{EllipsePointer=U(a[0]),CylinderPointer=U(a[1]),OtherPointer=U(a[2]),EllipseCount=Convert.ToByte(a[3]),CylinderCount=Convert.ToByte(a[4]),OtherCount=Convert.ToByte(a[5]),JointIndex=Convert.ToByte(a[6])};}
    static string Sha(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;if(a is string||b is string)return Convert.ToString(a)==Convert.ToString(b);
        var ma=a as IDictionary;var mb=b as IDictionary;if(ma!=null&&mb!=null){if(ma.Count!=mb.Count)return false;foreach(object k in ma.Keys)if(!mb.Contains(k)||!Same(ma[k],mb[k]))return false;return true;}
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<shadow-queue-fixtures.json.gz> <result.json>");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> fixture;
        using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var reader=new StreamReader(z))fixture=M(json.DeserializeObject(reader.ReadToEnd()));var rigs=A(fixture["rigs"]);int checks=0,failures=0;var errors=new List<object>();
        foreach(var item in A(fixture["cases"]))
        {
            var c=M(item);var input=M(c["state"]);var p=A(input["parameters"]);var d=A(input["distances"]);
            var state=new CharacterShadowQueueState{Count=Convert.ToInt32(input["count"]),Sequence=U(input["sequence"]),SubmissionFlag=U(input["flag"]),Enabled=Convert.ToByte(input["enabled"]),Mode=Convert.ToInt32(input["mode"]),SubmissionEnabled=U(input["submissionEnabled"]),Parameter0=U(p[0]),Parameter1=U(p[1]),Parameter2=U(p[2]),PackedParameter=U(p[3]),FadeDistance=F(d[0]),MaximumDistance=F(d[1])};
            for(int i=0;i<state.Records.Length;++i)state.Records[i]=0xa5;
            if(c.ContainsKey("direct"))
            {var direct=M(c["direct"]);CharacterShadowQueue.Enqueue(state,Hex((string)direct["matrix"]),Binding(direct["binding"]));}
            else
            {
                var r=M(rigs[Convert.ToInt32(c["rig"])]);CharacterShadowBinding[] bindings=r["bindings"]==null?null:Array.ConvertAll(A(r["bindings"]),Binding);float[][] joints=Array.ConvertAll(A(r["joints"]),Floats);
                CharacterShadowQueue.Submit(state,bindings,Convert.ToByte(input["suppress"]),Floats(input["world"]),joints);
            }
            object actual=new{count=state.Count,sequence=state.Sequence,flag=state.SubmissionFlag,queueSha256=Sha(state.Records)};actual=json.DeserializeObject(json.Serialize(actual));var expected=new Dictionary<string,object>(M(c["native"]));expected.Remove("calls");
            // Original probes also observe native helper order; the managed API
            // exposes final queue/state effects, not internal pure helper calls.
            ++checks;if(!Same(actual,expected)){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,actual,expected});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
