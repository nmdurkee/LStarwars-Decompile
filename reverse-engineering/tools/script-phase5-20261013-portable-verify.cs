using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase520261013Verify
{
 static Dictionary<string,object> O(object v){return(Dictionary<string,object>)v;}
 static object[] A(object v){return(object[])v;}
 static int I(object v){return Convert.ToInt32(v);}
 static uint U(object v){return Convert.ToUInt32(v);}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static bool Flag(Dictionary<string,object> c,string key,bool fallback){return c.ContainsKey(key)?Convert.ToBoolean(c[key]):fallback;}
 static int Integer(Dictionary<string,object> c,string key,int fallback){return c.ContainsKey(key)?I(c[key]):fallback;}
 static uint Word(Dictionary<string,object> c,string key,uint fallback){return c.ContainsKey(key)?U(c[key]):fallback;}
 static List<object> errors=new List<object>();static int checks,failures;
 static bool Equal(object a,object b)
 {
  if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
  if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object key in ad.Keys)if(!bd.Contains(key)||!Equal(ad[key],bd[key]))return false;return true;}
  IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
  if(a is bool||b is bool||a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
 }
 static void Check(object got,object want,string group,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<20)errors.Add(new{group,index,got,want});}}
 static Phase5ActorRecord[] references;static Phase5ActorRecord self,boundAlive;static List<object> callbacks;
 static Phase5ActorRecord Reference(int i){return i<0?null:references[i];}
 static Phase5ConditionWorld World(Dictionary<string,object> c)
 {
  self=new Phase5ActorRecord{HasSplineE64=Flag(c,"spline",true),SplineFinishedE6b=(byte)Integer(c,"splineFinished",0)};
  references=new[]{new Phase5ActorRecord{WorldObject=Flag(c,"worldObject",true)?self:null},new Phase5ActorRecord{WorldObject=new Phase5ActorRecord()},new Phase5ActorRecord{WorldObject=self}};
  boundAlive=new Phase5ActorRecord{Flags1fc=Word(c,"flags",0x1000),Dead28b=(byte)Integer(c,"dead",0),Definition4=Flag(c,"definition",true)?new Phase5ActorDefinition():null};
  if(Flag(c,"group",false)&&boundAlive.Definition4!=null)
  {
   object[] members=c.ContainsKey("members")?A(c["members"]):new object[]{new Dictionary<string,object>{{"flags",0x1001},{"dead",0}}};
   Phase5LifeGroup group=new Phase5LifeGroup{Count7=(byte)Integer(c,"groupCount",members.Length)};boundAlive.Definition4.Group144=group;
   foreach(object row in members)group.Members.Add(row==null?null:new Phase5ActorRecord{Flags1fc=U(O(row)["flags"]),Dead28b=(byte)I(O(row)["dead"])});
  }
  callbacks=new List<object>();Phase5ConditionWorld w=new Phase5ConditionWorld{SystemPresent=Flag(c,"system",true),Player1Reference138c=Reference(Integer(c,"player1",0)),Player2Reference1390=Reference(Integer(c,"player2",1)),BaddiesSeeingPlayers=Integer(c,"baddiesSeeing",17)};
  if(c.ContainsKey("actors"))foreach(object row in A(c["actors"]))w.Actors.Add(new Phase5ActorRecord{Flags1f8=U(O(row)["flags1f8"]),Flags1fc=U(O(row)["flags1fc"])});
  w.ActorCount=Integer(c,"actorCount",w.Actors.Count);
  if(Flag(c,"callback",true))w.ResolveCharacter=delegate(string name)
  {
   callbacks.Add(new Dictionary<string,object>{{"system",w.SystemPresent},{"name",name}});string key=(name??"").ToLowerInvariant();return key=="first"?references[0]:key=="second"?references[1]:key=="alias"?references[2]:key=="alive"?boundAlive:null;
  };
  return w;
 }
 static Phase5ScriptCreature Creature(Dictionary<string,object> c)
 {return Flag(c,"creature",true)?new Phase5ScriptCreature{ReferenceD0=Flag(c,"reference",true)?references[0]:null}:null;}
 static ScriptPacket Packet(Dictionary<string,object> c){return Flag(c,"packet",true)?new ScriptPacket{SetId=(byte)Integer(c,"setId",7)}:null;}
 static float Evaluate(string name,Dictionary<string,object> c)
 {
  Phase5ConditionWorld w=World(c);
  switch(name)
  {
   case "EitherPlayerIs":return Phase5Conditions.EitherPlayerIs(w,Reference(Integer(c,"bound",0)));
   case "Player1Is":return Phase5Conditions.Player1Is(w,Reference(Integer(c,"bound",0)));
   case "Player2Is":return Phase5Conditions.Player2Is(w,Reference(Integer(c,"bound",0)));
   case "FinishedSpline":return Phase5Conditions.FinishedSpline(Creature(c));
   case "NumBaddies":return Phase5Conditions.NumBaddies(w);
   case "IsAlive":return Phase5Conditions.IsAlive(Flag(c,"bound",true)?boundAlive:null);
   case "MySet":return Phase5Conditions.MySet(Packet(c));
   case "NumBaddiesThatCanSeePlayers":return Phase5Conditions.NumBaddiesThatCanSeePlayers(w);
   default:throw new ArgumentException("Unknown condition "+name);
  }
 }
 static uint Pointer(Phase5ActorRecord record)
 {if(record==null)return 0;if(Object.ReferenceEquals(record,boundAlive))return 0x10109000u;int i=Array.IndexOf(references,record);if(i<0)throw new ArgumentException("Unknown prepared record.");return 0x10105000u+(uint)i*0x1100;}
 public static int Main(string[] args)
 {
  checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in A(data["cases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);string name=(string)v["command"];bool fault=v.ContainsKey("nativeFault");
   try{float result=Evaluate(name,c);if(fault)Check(false,true,name+"-native-fault",index);else Check(Bits(result),U(v["nativeBits"]),name+"-body",index);}
   catch(ArgumentException e){if(fault)Check(true,true,name+"-native-fault",index);else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["initializers"]))
  {
   Dictionary<string,object> v=O(row);Phase5ConditionWorld w=World(v);uint pointer=(string)v["command"]=="NumBaddies"?(uint)Phase5Conditions.BindNumBaddies():Pointer(Phase5Conditions.BindReference(w,(string)v["operand"]));Check(pointer,U(v["nativePointer"]),"condition-initializer",index);Check(callbacks,v["callbackCalls"],"initializer-callback-gates",index);++index;
  }
  foreach(object row in A(data["shipped"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);string name=(string)v["command"],operand=(string)v["operand"];Phase5ConditionWorld w=World(c);Phase5ActorRecord initialized=null;float result=0;
   if(name=="EitherPlayerIs"||name=="Player1Is"||name=="Player2Is"||name=="IsAlive")
   {
    w.ResolveCharacter=delegate(string text){callbacks.Add(new Dictionary<string,object>{{"system",true},{"name",text}});return operand!=null&&String.Equals(text,operand,StringComparison.OrdinalIgnoreCase)?name=="IsAlive"?boundAlive:references[0]:null;};
    initialized=Phase5Conditions.BindReference(w,operand);
    result=name=="EitherPlayerIs"?Phase5Conditions.EitherPlayerIs(w,initialized):name=="Player1Is"?Phase5Conditions.Player1Is(w,initialized):name=="Player2Is"?Phase5Conditions.Player2Is(w,initialized):Phase5Conditions.IsAlive(initialized);
   }
   else if(name=="FinishedSpline")result=Phase5Conditions.FinishedSpline(Creature(c));
   else if(name=="NumBaddies")result=Phase5Conditions.NumBaddies(w);
   else if(name=="MySet")result=Phase5Conditions.MySet(Packet(c));
   else result=Phase5Conditions.NumBaddiesThatCanSeePlayers(w);
   Check(Pointer(initialized),U(v["nativePointer"]),"shipped-"+name+"-initializer",index);Check(callbacks,v["callbackCalls"],"shipped-"+name+"-callbacks",index);Check(Bits(result),U(v["nativeBits"]),"shipped-"+name+"-body",index);
   Dictionary<string,object> compare=O(v["comparison"]);string op=(string)compare["operator"];float rhs=F(U(compare["thresholdBits"]));bool matched=op=="=="?result==rhs:op=="!="?result!=rhs:op=="<"?result<rhs:op==">"?result>rhs:op=="<="?result<=rhs:result>=rhs;Check(matched,Convert.ToBoolean(compare["matched"]),"shipped-"+name+"-comparison",index);++index;
  }
  string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
 }
}
