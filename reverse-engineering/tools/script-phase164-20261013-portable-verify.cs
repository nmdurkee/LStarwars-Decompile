using System;using System.IO;using System.Collections.Generic;using System.Web.Script.Serialization;using Recovered.Gameplay;
public static class ScriptPhase16420261013Verify
{
 static Dictionary<string,object> O(object v){return (Dictionary<string,object>)v;}static uint U(object v){return Convert.ToUInt32(v);}
 public static int Run(string root){var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};var data=O(json.DeserializeObject(File.ReadAllText(Path.Combine(root,"reports/script-phase164-20261013-native-fixtures.json"))));int checks=0;foreach(object item in(object[])data["cases"]){var row=O(item);var x=O(row["inputs"]);var r=PreparedScriptUnsignedDivision.Execute(U(x["numeratorLow"]),U(x["numeratorHigh"]),U(x["divisorLow"]),U(x["divisorHigh"]));uint[] actual={r.Eax,r.Edx,r.Ebx,r.Ecx};var expected=(object[])row["registers"];for(int i=0;i<4;i++){checks++;if(actual[i]!=U(expected[i]))throw new InvalidOperationException("Unsigned division register mismatch");}}Console.WriteLine(checks+" unsigned division comparisons passed.");return 0;}
 public static int Main(string[] args){return Run(args.Length==0?"reverse-engineering":args[0]);}
}
