using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class ShadowPassStateHarness
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}
    static byte[] Hex(string s){var b=new byte[s.Length/2];for(int i=0;i<b.Length;++i)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static byte[] Inflate(byte[] b){using(var f=new MemoryStream(b))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
    static bool Same(uint[] actual,object expected){object[] e=A(expected);if(actual.Length!=e.Length)return false;for(int i=0;i<actual.Length;++i)if(actual[i]!=U(e[i]))return false;return true;}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=M(Json.DeserializeObject(System.Text.Encoding.UTF8.GetString(Inflate(File.ReadAllBytes(args[0])))));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);var original=M(c["state"]);byte[] bytes=Inflate(Convert.FromBase64String((string)c["beforeZ"])),pass=Hex((string)c["passBefore"]);var memory=new RenderPacketMemory(U(fixture["base"]),bytes);var state=new ShadowContextRegistryState{Count=Convert.ToInt32(original["count"]),CacheFlag=U(original["flag"]),Contexts=Array.ConvertAll(A(original["contexts"]),v=>U(v)),Masks=Array.ConvertAll(A(original["masks"]),v=>U(v))};uint mode=U(c["mode"]),returned=0;
            switch((string)c["kind"])
            {
                case "reset":returned=ShadowPassState.Reset(pass);break;
                case "adapter":returned=ShadowPassState.ResetAdapter(pass,U(c["value"]));break;
                case "select":ShadowPassState.SelectVolume(pass,U(c["context"]),U(c["value"]));break;
                case "mode":returned=ShadowPassState.SetMode(ref mode,U(c["enabled"]),U(c["value"]));break;
                case "invalidate":ShadowPassState.Invalidate(state);break;
                case "tail":ShadowPassState.RegisterPrimaryTail(memory,state,Convert.ToByte(c["feature"]),U(c["configuration"]),U(c["context"]));break;
                case "call":ShadowPassState.RegisterPrimaryCall(memory,state,Convert.ToByte(c["feature"]),U(c["configuration"]),U(c["context"]));break;
                default:throw new ArgumentException("Unknown fixture operation.");
            }
            byte[] all=new byte[bytes.Length+pass.Length+4];Array.Copy(bytes,all,bytes.Length);Array.Copy(pass,0,all,bytes.Length,pass.Length);Array.Copy(BitConverter.GetBytes(mode),0,all,bytes.Length+pass.Length,4);string digest=Hash(all);var expected=M(c["nativeState"]);bool stateMatch=state.Count==Convert.ToInt32(expected["count"])&&state.CacheFlag==U(expected["flag"])&&Same(state.Contexts,expected["contexts"])&&Same(state.Masks,expected["masks"]);++checks;
            if(digest!=(string)c["nativeSHA256"]||!stateMatch||(c["nativeReturn"]!=null&&returned!=U(c["nativeReturn"])))
            {++failures;if(errors.Count<12)errors.Add(new{index=checks-1,digest,expected=c["nativeSHA256"],stateMatch,returned});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
