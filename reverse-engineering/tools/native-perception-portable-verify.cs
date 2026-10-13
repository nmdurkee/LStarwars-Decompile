using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public static class PerceptionDifferential
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=100};
 static Dictionary<string,object>M(object v){return(Dictionary<string,object>)v;}
 static uint U(Dictionary<string,object>v,string k){return Convert.ToUInt32(v[k]);}
 static int I(Dictionary<string,object>v,string k){return Convert.ToInt32(v[k]);}
 static bool B(Dictionary<string,object>v,string k){return Convert.ToBoolean(v[k]);}
 static float F(object v){return PcObjectImage.FromBits(Convert.ToUInt32(v));}
 sealed class World:PerceptionWorld
 {
  public readonly List<object> Events=new List<object>();
  public override float CharacterDefault(int type,PerceptionValue kind){Events.Add(new object[]{"default",(int)kind,type});return base.CharacterDefault(type,kind);}
 }
 static object Snapshot(PerceptionController c,PerceptionReference r)
 {return new{controllerFlags=c.Flags1e8,objectFlags=r.Flags1fc,objectStateFlags=r.Flags1f8,values=Array.ConvertAll(r.Values,x=>PcObjectImage.ToBits(x)),moveRadius=PcObjectImage.ToBits(c.MoveRadius)};}
 static bool Same(object a,object b)
 {
  if(a==null||b==null)return a==null&&b==null;
  Dictionary<string,object>ma=a as Dictionary<string,object>,mb=b as Dictionary<string,object>;
  if(ma!=null||mb!=null){if(ma==null||mb==null||ma.Count!=mb.Count)return false;foreach(string k in ma.Keys)if(!mb.ContainsKey(k)||!Same(ma[k],mb[k]))return false;return true;}
  object[]aa=a as object[],bb=b as object[];if(aa!=null||bb!=null){if(aa==null||bb==null||aa.Length!=bb.Length)return false;for(int i=0;i<aa.Length;i++)if(!Same(aa[i],bb[i]))return false;return true;}
  return Convert.ToString(a,System.Globalization.CultureInfo.InvariantCulture)==Convert.ToString(b,System.Globalization.CultureInfo.InvariantCulture);
 }
 public static int Main(string[]args)
 {
  if(args.Length!=2)throw new ArgumentException("native-perception-vectors.json output.json");
  Dictionary<string,object>root=M(Json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,failures=0;List<object>examples=new List<object>();
  foreach(object raw in(object[])root["cases"])
  {
   Dictionary<string,object>row=M(raw),v=M(row["input"]);string name=(string)row["name"];
   PerceptionReference reference=new PerceptionReference{Flags1f8=U(v,"objectStateFlags"),Flags1fc=U(v,"objectFlags"),CharacterType=(short)I(v,"characterType"),Radius=F(v["radius"])};
   for(int i=0;i<4;i++)reference.Values[i]=F(((object[])v["values"])[i]);
   PerceptionController controller=new PerceptionController{Reference=B(v,"reference")?reference:null,TemplateIndex=(byte)I(v,"template"),Flags1e8=U(v,"controllerFlags"),MoveRadius=F(v["moveRadius"])};
   World world=new World{Templates=new float[255][],CharacterDefinitions=new float[8][]};
   for(int i=0;i<255;i++)world.Templates[i]=Array.ConvertAll((object[])v["templateDefaults"],x=>F(x));
   for(int i=0;i<8;i++)world.CharacterDefinitions[i]=Array.ConvertAll((object[])v["characterDefaults"],x=>F(x));
   for(int i=0;i<4;i++)world.DefaultCallbacks[i]=Convert.ToBoolean(((object[])v["callbacks"])[i]);
   ScriptPacket packet=new ScriptPacket{Script=new ScriptDefinition()};string[]names={"alpha","beta","gamma","delta"};float[]numbers={2.75f,1.5f,3,4};
   for(int i=0;i<4;i++){packet.Parameters[i]=numbers[i];packet.Script.ParameterNames[i]=names[i];}
   world.Evaluate=delegate(PerceptionController c,ScriptPacket p,string text){world.Events.Add(new object[]{"number",text,Snapshot(controller,reference)});return MessageNumbers.Resolve(p,text);};
   string[]tokens=Array.ConvertAll((object[])v["tokens"],x=>(string)x);int result;
   if(name=="SetViewDistance"||name=="SetHearDistance"||name=="SetMaxViewHeight"||name=="SetMinViewHeight"||name=="SetMoveRadius")result=PerceptionCommands.SetValue(world,B(v,"controller")?controller:null,packet,tokens,B(v,"first"),(PerceptionValue)Enum.Parse(typeof(PerceptionValue),name.Substring(3)));
   else result=PerceptionCommands.SetFlag(B(v,"controller")?controller:null,tokens,B(v,"first"),(PerceptionFlag)Enum.Parse(typeof(PerceptionFlag),name));
   object actual=Json.DeserializeObject(Json.Serialize(new{state=Snapshot(controller,reference),events=world.Events,result=result}));checks++;
   if(!Same(actual,row["expected"])){failures++;if(examples.Count<12)examples.Add(new{name=name,input=v,expected=row["expected"],actual=actual});}
  }
  object report=new{cases=checks,mismatches=failures,examples=examples};File.WriteAllText(args[1],Json.Serialize(report));Console.WriteLine(Json.Serialize(new{cases=checks,mismatches=failures}));return failures==0?0:1;
 }
}
