using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Input;
public static class InputDifferential
{
    static Dictionary<string,object> Map(object o){return (Dictionary<string,object>)o;}
    static int I(Dictionary<string,object> m,string k){return Convert.ToInt32(m[k]);}
    static byte[] Unhex(string h){byte[] b=new byte[h.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(h.Substring(i*2,2),16);return b;}
    static bool Equal(object a,object b)
    {
        Array aa=a as Array,bb=b as Array;
        if(aa!=null||bb!=null){if(aa==null||bb==null||aa.Length!=bb.Length)return false;for(int i=0;i<aa.Length;i++)if(!Equal(aa.GetValue(i),bb.GetValue(i)))return false;return true;}
        if(a is string)return String.Equals((string)a,(string)b,StringComparison.OrdinalIgnoreCase);
        return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length<2)throw new ArgumentException("Fixture files followed by output report required.");
        JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=Int32.MaxValue;int cases=0,failed=0;var examples=new List<object>();var counts=new Dictionary<string,int>();
        for(int f=0;f<args.Length-1;f++)foreach(object item in (object[])Map(json.DeserializeObject(File.ReadAllText(args[f])))["vectors"])
        {
            var v=Map(item);string name=v.ContainsKey("contract")?(string)v["contract"]:"pad";cases++;
            if(!counts.ContainsKey(name))counts[name]=0;counts[name]++;
            try
            {
                object actual,expected;
                if(name=="pad")
                {
                    byte[] pad=Unhex((string)v["before"]);ControllerInput.ProcessPad(pad,I(v,"scaled")!=0,Convert.ToSingle(v["frame"]));
                    actual=BitConverter.ToString(pad).Replace("-","");expected=v["after"];
                }
                else if(name=="circleToSquare")
                {
                    object[] a=(object[])v["input"];short x=Convert.ToInt16(a[0]),y=Convert.ToInt16(a[1]);ControllerInput.CircleToSquare(ref x,ref y);actual=new object[]{x,y};expected=v["native"];
                }
                else
                {
                    var m=Map(v["input"]);expected=v["native"];
                    if(name=="movementAngle")actual=ControllerInput.MovementAngle(Convert.ToBoolean(m["player"]),(sbyte)I(m,"socketIndex"),Convert.ToBoolean(m["socketFlag40"]),(ushort)I(m,"stickAngle"),Convert.ToUInt32(m["cameraYaw"]),(ushort)I(m,"objectYaw"),(ushort)I(m,"socketYaw"));
                    else if(name=="defaultXbox")
                    {
                        object[] a=(object[])m["axes"],t=(object[])m["triggers"];
                        actual=ControllerInput.MapDefaultXbox((ushort)I(m,"physical"),Convert.ToInt16(a[0]),Convert.ToInt16(a[1]),Convert.ToInt16(a[2]),Convert.ToInt16(a[3]),Convert.ToByte(t[0]),Convert.ToByte(t[1]));
                    }
                    else throw new ArgumentException("Unknown input contract");
                }
                if(!Equal(actual,expected)){failed++;if(examples.Count<20)examples.Add(new{contract=name,actual=actual,native=expected});}
            }
            catch(Exception e){failed++;if(examples.Count<20)examples.Add(new{contract=name,error=e.Message});}
        }
        File.WriteAllText(args[args.Length-1],json.Serialize(new{cases=cases,failures=failed,contracts=counts,examples=examples}));
        Console.WriteLine("Input compiled differential: "+cases+" cases, "+failed+" failures");return failed==0?0:1;
    }
}
