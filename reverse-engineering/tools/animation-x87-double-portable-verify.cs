using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
public static class PlaybackWideDoubleVerify
{
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("<x87-double-tests.json> <result.json>");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var fixture=(Dictionary<string,object>)json.DeserializeObject(File.ReadAllText(args[0]));int checks=0,failures=0;var errors=new List<object>();
        foreach(object item in(object[])fixture["cases"])
        {
            var c=(Dictionary<string,object>)item;double a=BitConverter.Int64BitsToDouble(unchecked((long)Convert.ToUInt64(c["a"]))),b=BitConverter.Int64BitsToDouble(unchecked((long)Convert.ToUInt64(c["b"])));var wa=PlaybackWide.FromDouble(a);var wb=PlaybackWide.FromDouble(b);int op=Convert.ToInt32(c["op"]);var wide=op==0?wa:op==1?PlaybackWide.Add(wa,wb):PlaybackWide.Multiply(wa,wb);ulong actual=unchecked((ulong)BitConverter.DoubleToInt64Bits(wide.StoreDouble())),expected=Convert.ToUInt64(c["nativeBits"]);++checks;if(actual!=expected){++failures;if(errors.Count<12)errors.Add(new{index=checks-1,actual,expected});}
        }
        File.WriteAllText(args[1],json.Serialize(new{checks,failures,errors}));return failures==0?0:1;
    }
}
