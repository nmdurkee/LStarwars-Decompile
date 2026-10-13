using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathCornerMathVerify
{
    static SpawnVector Vector(object raw){object[] a=(object[])raw;return new SpawnVector(PcObjectImage.FromBits(Convert.ToUInt32(a[0])),PcObjectImage.FromBits(Convert.ToUInt32(a[1])),PcObjectImage.FromBits(Convert.ToUInt32(a[2])));}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=(Dictionary<string,object>)json.DeserializeObject(File.ReadAllText(args[0]));int checks=0,mismatches=0;List<object> errors=new List<object>();
        foreach(object item in (object[])root["cases"])
        {
            Dictionary<string,object> c=(Dictionary<string,object>)item;string kind=(string)c["kind"];object got;bool equal;
            if(kind=="lines"){object[] vectors=(object[])c["vectors"],native=(object[])c["native"];float a,b;bool result=PathCornerMath.LineParameters(Vector(vectors[0]),Vector(vectors[1]),Vector(vectors[2]),Vector(vectors[3]),out a,out b);uint[] words={(uint)(result?1:0),PcObjectImage.ToBits(a),PcObjectImage.ToBits(b)};got=words;equal=words[0]==Convert.ToUInt32(native[0])&&words[1]==Convert.ToUInt32(native[1])&&words[2]==Convert.ToUInt32(native[2]);}
            else{object[] input=(object[])c["input"];int a=unchecked((int)Convert.ToUInt32(input[0])),b=unchecked((int)Convert.ToUInt32(input[1]));uint value=unchecked((uint)(kind=="add"?PathCornerMath.AddAngles(a,b):PathCornerMath.DifferenceAngles(a,b)));got=value;equal=value==Convert.ToUInt32(c["native"]);}
            checks++;if(!equal){mismatches++;if(errors.Count<15)errors.Add(new{index=checks-1,got,want=c["native"]});}
        }
        string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
