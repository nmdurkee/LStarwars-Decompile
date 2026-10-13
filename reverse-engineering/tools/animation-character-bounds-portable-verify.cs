using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class CharacterPredictedBoundsVerify
{
    static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
    static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
    static object[] A(object v){return(object[])v;}static uint U(object v){return Convert.ToUInt32(v);}
    static float F(object v){return PcObjectImage.FromBits(U(v));}
    static float[] Floats(object v){return Array.ConvertAll(A(v),F);}
    static string Hash(byte[] v){using(var h=SHA256.Create())return BitConverter.ToString(h.ComputeHash(v)).Replace("-","").ToLowerInvariant();}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<character-bounds-native-fixtures.json.gz> <result.json>");Dictionary<string,object> fixture;
        using(var file=File.OpenRead(args[0]))using(var zip=new GZipStream(file,CompressionMode.Decompress))using(var reader=new StreamReader(zip))fixture=M(Json.DeserializeObject(reader.ReadToEnd()));
        int checks=0,failures=0;var errors=new List<object>();var kinds=new Dictionary<string,int>();
        foreach(object item in A(fixture["cases"]))
        {
            var c=M(item);string kind=(string)c["kind"];bool same;object actual,expected;
            if(kind=="bounds")
            {
                var e=M(c["environment"]);var o=new PcObjectImage(Convert.FromBase64String((string)c["before"]));
                var environment=new CharacterBoundsEnvironment{PredictionSeconds=F(e["dt"]),PrimaryPoint=Convert.ToSByte(e["primary"]),FallbackPoint=Convert.ToSByte(e["fallback"]),PointEnabledSlots=Array.ConvertAll(A(e["enabled"]),U),ContextFlags=U(e["contextFlags"])};
                CharacterPredictedBounds.Update(o,environment);actual=Hash(o.Bytes);expected=c["nativeSha256"];same=Object.Equals(actual,expected);
            }
            else
            {
                float[] vector=Floats(c["vector"]);byte[] preserved=new byte[12];Buffer.BlockCopy(vector,0,preserved,0,12);
                float[] output=kind=="direction"?CharacterPredictedBounds.TransformDirection(vector,Floats(c["matrix"])):CharacterPredictedBounds.AddVectors(vector,Floats(c["other"]));
                uint[] words=Array.ConvertAll(output,PcObjectImage.ToBits),native=Array.ConvertAll(A(c["native"]),U);actual=words;expected=native;same=words.Length==native.Length;
                for(int i=0;i<words.Length&&same;++i)same=words[i]==native[i];
                byte[] after=new byte[12];Buffer.BlockCopy(vector,0,after,0,12);same=same&&Hash(preserved)==Hash(after);
                // Native fixtures include exact in-place destinations; this API
                // returns owned arrays and compares their numeric result only.
            }
            ++checks;if(!kinds.ContainsKey(kind))kinds[kind]=0;++kinds[kind];
            if(!same){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,kind,actual,expected});}
        }
        File.WriteAllText(args[1],Json.Serialize(new{checks,failures,kinds,errors}));return failures==0?0:1;
    }
}
