using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class SceneryNameDifferential
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=100};
 static Dictionary<string,object> M(object value){return(Dictionary<string,object>)value;}
 static bool B(Dictionary<string,object> v,string k){return v.ContainsKey(k)&&Convert.ToBoolean(v[k]);}
 static int I(Dictionary<string,object> v,string k){return Convert.ToInt32(v[k]);}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("vectors.json output.json");
  Dictionary<string,object> root=M(Json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,failures=0;List<object> examples=new List<object>();
  foreach(object raw in(object[])root["lookup"])
  {
   Dictionary<string,object> row=M(raw),v=M(row["input"]);object[] buckets=(object[])v["buckets"];List<object> calls=new List<object>();
   SceneryRegistry registry=new SceneryRegistry{NameBuckets=new SceneryNameBucket[buckets.Length]};
   SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=I(v,"count"),NameAccessors=new Func<SceneryGizmo,string>[buckets.Length]};
   Dictionary<SceneryGizmo,int[]> identities=new Dictionary<SceneryGizmo,int[]>();
   for(int i=0;i<buckets.Length;i++)
   {
    Dictionary<string,object> b=M(buckets[i]);SceneryNameBucket bucket=registry.NameBuckets[i]=new SceneryNameBucket{Count=I(b,"count")};int j=0;
    foreach(object name in(object[])b["names"]){SceneryGizmo record=new SceneryGizmo{Target=name==null?null:new SceneryObject{Name=(string)name}};bucket.Records.Add(record);identities[record]=new int[]{i,j++};}
    if(B(b,"accessor"))bindings.NameAccessors[i]=delegate(SceneryGizmo record){calls.Add(identities[record]);return SceneryNameBindings.ObjectName(record);};
   }
   if(B(v,"globalMissing"))bindings.NameAccessors=null;
   SceneryGizmo found=bindings.Find(B(v,"registryMissing")?null:registry,I(v,"type"),(string)v["name"]);
   object actual=new{record=found==null?null:identities[found],calls=calls};Dictionary<string,object> expected=M(row["native"]);
   string a=Json.Serialize(actual),e=Json.Serialize(expected);checks++;if(a!=e){failures++;if(examples.Count<12)examples.Add(new{input=v,expected=expected,actual=actual});}
  }
  object report=new{cases=checks,mismatches=failures,examples=examples,nativeOnlyAccessorPointerCases=((object[])root["accessors"]).Length};
  File.WriteAllText(args[1],Json.Serialize(report));Console.WriteLine(Json.Serialize(new{cases=checks,mismatches=failures}));return failures==0?0:1;
 }
}
