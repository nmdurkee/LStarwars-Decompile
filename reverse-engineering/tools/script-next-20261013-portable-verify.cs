using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptNext20261013Verify
{
 static Dictionary<string,object> O(object v){return(Dictionary<string,object>)v;}
 static object[] A(object v){return(object[])v;}
 static int I(object v){return Convert.ToInt32(v);}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int S(object v){return unchecked((int)(uint)Convert.ToInt64(v));}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static bool Flag(Dictionary<string,object> c,string key,bool fallback){return c.ContainsKey(key)?Convert.ToBoolean(c[key]):fallback;}
 static int Integer(Dictionary<string,object> c,string key,int fallback){return c.ContainsKey(key)?I(c[key]):fallback;}
 static uint Word(Dictionary<string,object> c,string key,uint fallback){return c.ContainsKey(key)?U(c[key]):fallback;}
 static int checks,failures;static List<object> errors=new List<object>();
 static void Check(object got,object want,string group,int index)
 {
  ++checks;bool same=(got is bool||want is bool)?Object.Equals(got,want):Convert.ToDecimal(got)==Convert.ToDecimal(want);
  if(!same){++failures;if(errors.Count<20)errors.Add(new{group,index,got,want});}
 }
 static NextScriptConditionWorld World(Dictionary<string,object> c)
 {
  NextScriptConditionWorld w=new NextScriptConditionWorld{ForceType=Integer(c,"forceType",1),PrimaryPlayer=Flag(c,"player",true)?new NextScriptActor{DefinitionFlags4=Word(c,"definitionFlags",0),ClassFlags90=Word(c,"classFlags90",0),ClassFlags94=Word(c,"classFlags94",0)}:null,CategoryTablePresent=Flag(c,"categoryTable",true),CategoryCount=Integer(c,"categoryCount",3)};
  foreach(string name in new[]{"Alpha","Dupe","DUPE"})w.Categories.Add(new NextScriptCategory{Name=name,DefinitionMask=Word(c,"definitionMask",0),ClassMask=Word(c,"classMask",0)});
  if(c.ContainsKey("activeHint")&&c["activeHint"]!=null)w.ActiveHintId=(short)I(c["activeHint"]);
  HashSet<int> registered=new HashSet<int>();if(c.ContainsKey("registeredHints")){foreach(object id in A(c["registeredHints"]))registered.Add(I(id));}else foreach(int id in new[]{0,1,2,7})registered.Add(id);
  w.HintRegistered=delegate(int id){return registered.Contains(id);};
  if(Flag(c,"hintList",true))
  {
   w.Hints=new List<NextScriptHint>();
   if(c.ContainsKey("hints"))foreach(object row in A(c["hints"]))
   {Dictionary<string,object> h=O(row);w.Hints.Add(new NextScriptHint{Id=(short)I(h["id"]),Complete14=(byte)I(h["complete"]),Timer18=F(U(h["timerBits"]))});}
   else{w.Hints.Add(new NextScriptHint{Id=1});w.Hints.Add(new NextScriptHint{Id=2,Complete14=1});w.Hints.Add(new NextScriptHint{Id=-1});}
  }
  return w;
 }
 static NextScriptCreature Creature(Dictionary<string,object> c)
 {
  if(!Flag(c,"creature",true))return null;NextScriptReference reference=null;
  if(Flag(c,"reference",true))reference=new NextScriptReference{WorldObject=Flag(c,"worldObject",true)?new NextScriptActor{Context7b5=unchecked((sbyte)Integer(c,"contextByte",23))}:null};
  return new NextScriptCreature{Flags1e8=Word(c,"flags",0),SelfD0=reference,OpponentE4=reference};
 }
 static NextScriptForceTarget ForceTarget(Dictionary<string,object> c)
 {return Flag(c,"bound",true)?new NextScriptForceTarget{FlagsA0=Word(c,"flags",0),HasUser3c=Flag(c,"hasUser",false),Group28=Flag(c,"group",false)?new NextScriptPlaybackGroup{State0c=Integer(c,"groupState",2)}:null}:null;}
 static float Evaluate(string name,Dictionary<string,object> c,int selector)
 {
  NextScriptConditionWorld w=World(c);
  switch(name)
  {
   case "OpponentIsAThreat":return NextScriptConditions.OpponentIsAThreat(Creature(c));
   case "ForceBeingUsed":return NextScriptConditions.ForceBeingUsed(ForceTarget(c));
   case "ForceFinished":return NextScriptConditions.ForceFinished(ForceTarget(c));
   case "ForceFinishedHelper":return NextScriptConditions.IsForcePlaybackFinished(ForceTarget(c))?1f:0f;
   case "PlayerCategoryIs":return NextScriptConditions.PlayerCategoryIs(w,selector);
   case "InContext":return NextScriptConditions.InContext(Creature(c),selector);
   case "OpponentContext":return NextScriptConditions.OpponentContext(Creature(c),selector);
   case "HintAvailable":return NextScriptConditions.HintAvailable(w,selector);
   case "HintComplete":return NextScriptConditions.HintComplete(w,selector);
   case "HintAvailableHelper":return NextScriptConditions.IsHintAvailable(w,selector)?1f:0f;
   case "HintCompleteHelper":return NextScriptConditions.ReadHintComplete(w,selector);
   default:throw new ArgumentException("Unknown saved command "+name);
  }
 }
 public static int Main(string[] args)
 {
  checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in A(data["cases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);string name=(string)v["command"];bool fault=v.ContainsKey("nativeFault");
   try{float result=Evaluate(name,c,S(v["selector"]));if(fault)Check(false,true,name+"-native-fault",index);else Check(Bits(result),U(v["nativeBits"]),name+"-body",index);}
   catch(ArgumentException e){if(fault)Check(true,true,name+"-native-fault",index);else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["initializers"]))
  {
   Dictionary<string,object> v=O(row);string name=(string)v["command"],operand=(string)v["operand"];
   if(name=="Context")Check(NextScriptConditions.BindContext(operand),I(v["nativeSelector"]),"context-initializer",index);
   else if(name=="Hint")Check(unchecked((uint)NextScriptConditions.BindHint(operand)),U(v["nativeSelector"]),"hint-initializer",index);
   else if(name=="PlayerCategoryIs")
   {
    Dictionary<string,object> c=new Dictionary<string,object>{{"categoryTable",v["table"]}};Check(unchecked((uint)NextScriptConditions.BindPlayerCategory(World(c),Convert.ToBoolean(v["system"]),operand)),U(v["nativeSelector"]),"player-category-initializer",index);
   }
   else
   {
    NextScriptConditionWorld w=World(new Dictionary<string,object>());List<uint> calls=new List<uint>();NextScriptForceTarget[] targets={new NextScriptForceTarget(),new NextScriptForceTarget(),new NextScriptForceTarget()};bool nullTarget=Convert.ToBoolean(v["nullTarget"]);string gate=(string)v["gate"];
    // Explicit test adapter composes previously recovered registry lookup.
    w.ResolveForceTarget=delegate(int type,string text)
    {
     if(type!=1)throw new ArgumentException("Incorrect native Force type passed.");if(gate!="none")return null;string[] names={"Alpha","Dupe","DUPE"};
     for(int i=0;i<names.Length;i++){calls.Add(0x1011b100u+(uint)i*8);if(String.Equals(names[i],text,StringComparison.OrdinalIgnoreCase))return i==0&&nullTarget?null:targets[i];}return null;
    };
    NextScriptForceTarget bound=NextScriptConditions.BindForceTarget(w,operand);int targetIndex=Array.IndexOf(targets,bound);uint pointer=bound==null?0:0x1010a000u+(uint)targetIndex*0x100;Check(pointer,U(v["nativePointer"]),"force-initializer-target",index);
    object[] expected=A(v["callbackRecords"]);Check(calls.Count,expected.Length,"force-initializer-callback-count",index);for(int i=0;i<Math.Min(calls.Count,expected.Length);i++)Check(calls[i],U(expected[i]),"force-initializer-callback-order",index);
   }
   ++index;
  }
  foreach(object row in A(data["shipped"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);string name=(string)v["command"],operand=(string)v["operand"];int selector=0;uint initialized=0;NextScriptConditionWorld w=World(c);
   if(name=="ForceBeingUsed"||name=="ForceFinished")
   {
    NextScriptForceTarget target=ForceTarget(c);w.ResolveForceTarget=delegate(int type,string text){return type==1&&text==operand?target:null;};NextScriptForceTarget bound=NextScriptConditions.BindForceTarget(w,operand);initialized=bound==null?0:0x1010a000u;
   }
   else if(name=="InContext"||name=="OpponentContext"){selector=NextScriptConditions.BindContext(operand);initialized=unchecked((uint)selector);}
   else if(name=="PlayerCategoryIs"){w.Categories[0].Name=operand??"";selector=NextScriptConditions.BindPlayerCategory(w,true,operand);initialized=unchecked((uint)selector);}
   else if(name=="HintAvailable"||name=="HintComplete"){selector=NextScriptConditions.BindHint(operand);initialized=unchecked((uint)selector);}
   Check(initialized,U(v["initialized"]),"shipped-"+name+"-initializer",index);float result=Evaluate(name,c,selector);Check(Bits(result),U(v["nativeBits"]),"shipped-"+name+"-body",index);
   if(v["comparison"]!=null)
   {
    Dictionary<string,object> compare=O(v["comparison"]);string op=(string)compare["operator"];float rhs=F(U(compare["thresholdBits"]));bool matched=op=="=="?result==rhs:op=="!="?result!=rhs:op=="<"?result<rhs:op==">"?result>rhs:op=="<="?result<=rhs:result>=rhs;Check(matched,Convert.ToBoolean(compare["matched"]),"shipped-"+name+"-comparison",index);
   }
   ++index;
  }
  string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
 }
}
