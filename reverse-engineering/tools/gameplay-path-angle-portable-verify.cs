using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathAngleVerify
{
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=(Dictionary<string,object>)json.DeserializeObject(File.ReadAllText(args[0]));object[] raw=(object[])root["table"];ushort[] table=new ushort[raw.Length];for(int i=0;i<raw.Length;i++)table[i]=Convert.ToUInt16(raw[i]);int checks=0,mismatches=0;List<object> errors=new List<object>();
        foreach(object item in (object[])root["cases"])
        {
            object[] c=(object[])item;string kind=(string)c[0];float x=PcObjectImage.FromBits(Convert.ToUInt32(c[1])),z=PcObjectImage.FromBits(Convert.ToUInt32(c[2]));uint got=kind=="quadrant"?PathAngles.FirstQuadrant(x,z,table):kind=="direction"?unchecked((uint)PathAngles.Direction(x,z,table)):PcObjectImage.ToBits(PathAngles.Radians(x,z,table));uint want=Convert.ToUInt32(c[3]);checks++;if(got!=want){mismatches++;if(errors.Count<15)errors.Add(new{index=checks-1,got,want});}
        }
        string result=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[1],result);Console.WriteLine(result);return mismatches==0?0:1;
    }
}
