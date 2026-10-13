using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public static class GameplayPathArcSineVerify
{
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");
        JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};
        Dictionary<string,object> root=(Dictionary<string,object>)json.DeserializeObject(File.ReadAllText(args[0]));int checks=0,failures=0;List<object> errors=new List<object>();
        foreach(object item in (object[])root["cases"])
        {
            object[] pair=(object[])item;uint bits=Convert.ToUInt32(pair[0]);int expected=Convert.ToInt32(pair[1]),actual=PathArcSine.Evaluate(PcObjectImage.FromBits(bits));++checks;
            if(actual!=expected){++failures;if(errors.Count<15)errors.Add(new{bits,actual,expected});}
        }
        string output=json.Serialize(new{checks,mismatches=failures,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
    }
}
