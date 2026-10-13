// Prepared replay only. Do not launch where managed execution is denied.
using System;
using System.IO;
using System.IO.Compression;
using System.Collections;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class LegacyShadowConsumerVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}static object[] A(object v){return(object[])v;}
    static uint U(object v){return Convert.ToUInt32(v);}static int I(object v){return Convert.ToInt32(v);}
    static byte[] Expand(byte[] b){using(var i=new MemoryStream(b))using(var z=new GZipStream(i,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
    static Dictionary<string,object> Read(string p){return M(Json.DeserializeObject(System.Text.Encoding.UTF8.GetString(Expand(File.ReadAllBytes(p)))));}
    static string Hash(byte[] b){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(b)).Replace("-","").ToLowerInvariant();}
    static float[] Values(object v){return Array.ConvertAll(A(v),x=>PcObjectImage.FromBits(U(x)));}
    static uint[] Words(float[] v){return Array.ConvertAll(v,PcObjectImage.ToBits);}
    static bool Same(object a,object b)
    {
        if(a==null||b==null)return a==null&&b==null;IDictionary da=a as IDictionary,db=b as IDictionary;
        if(da!=null&&db!=null){if(da.Count!=db.Count)return false;foreach(object key in da.Keys)if(!db.Contains(key)||!Same(da[key],db[key]))return false;return true;}
        IList aa=a as IList,bb=b as IList;if(aa!=null&&bb!=null){if(aa.Count!=bb.Count)return false;for(int i=0;i<aa.Count;++i)if(!Same(aa[i],bb[i]))return false;return true;}
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static object Ring(LegacyShadowDirectionState s){return Array.ConvertAll(s.Circle,Words);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");var fixture=Read(args[0]);var sineSource=M(fixture["sine"]);string root=Path.GetDirectoryName(Path.GetDirectoryName(Path.GetFullPath(args[0])));byte[] raw=File.ReadAllBytes(Path.Combine(root,(string)sineSource["path"]));if(Hash(raw)!=(string)sineSource["sha256"])throw new InvalidDataException("Sine table changed");var sine=new float[32768];Buffer.BlockCopy(raw,0,sine,0,raw.Length);var angles=Array.ConvertAll(A(fixture["angleTable"]),x=>Convert.ToUInt16(x));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in A(fixture["cases"]))
        {
            var row=M(item);string kind=(string)row["kind"];var state=new LegacyShadowDirectionState{AngleTable=angles,SineTable=sine};for(int i=0;i<8;++i)state.Circle[i]=new[]{(float)(i*3-12),(float)(i*3-11),(float)(i*3-10)};bool pass;
            if(kind=="queue")
            {
                byte[] bytes=Expand(Convert.FromBase64String((string)row["queueZ"]));string before=Hash(bytes);var queue=new CharacterShadowQueueState{Count=I(row["count"]),Records=bytes};var pairs=M(row["pairs"]);var events=new List<object>();var environment=new LegacyShadowConsumerState{Camera=Values(row["camera"]),Direction=state,GeneratedValue=0xa5a5a5a5};
                environment.ReadPair=p=>Array.ConvertAll(A(pairs[p.ToString()]),U);
                environment.Emit=delegate(LegacyShadowShapeCall call)
                {
                    var e=new Dictionary<string,object>{{"entry",call.NativeEntry},{"record",call.RecordIndex},{"direction",Words(call.Direction)}};
                    if(call.NativeEntry==0x5e4280){e["first"]=call.First;e["second"]=call.Second;}else e["resource"]=call.Resource;
                    if(call.NativeEntry==0x5e3b50){e["upper"]=PcObjectImage.ToBits(call.Upper);e["lower"]=PcObjectImage.ToBits(call.Lower);}events.Add(e);environment.GeneratedValue=unchecked(environment.GeneratedValue+(call.NativeEntry&255)+1);
                };
                LegacyShadowConsumer.Process(queue,environment);var expected=M(row["native"]);
                pass=Hash(bytes)==before&&queue.Count==I(row["count"])&&Same(Words(environment.Camera),row["camera"])&&Same(events,expected["events"])&&Same(Ring(state),expected["circle"])&&environment.GeneratedValue==U(expected["generated"]);
                // Original helper-call counts are checked against the independent
                // native model. This replay checks their exact persistent outputs.
            }
            else
            {
                float[] vector=Values(row["vector"]),result;float pitch=PcObjectImage.FromBits(U(row["pitch"])),yaw=PcObjectImage.FromBits(U(row["yaw"]));
                if(kind=="angles"){result=LegacyShadowConsumer.Angles(vector,angles);pass=Same(Words(vector),row["vector"]);}
                else if(kind=="rotate"){LegacyShadowConsumer.Rotate(vector,pitch,yaw,sine);result=vector;pass=true;}
                else{LegacyShadowConsumer.Prepare(state,vector);result=vector;pass=Same(Ring(state),row["circle"]);}
                pass=pass&&Same(Words(result),row["native"]);
            }
            ++checks;if(!pass){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
