using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase320261013Verify
{
 static Dictionary<string,object> O(object v){return(Dictionary<string,object>)v;}
 static object[] A(object v){return(object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int I(object v){return Convert.ToInt32(v);}
 static bool Flag(Dictionary<string,object> c,string key,bool fallback){return c.ContainsKey(key)?Convert.ToBoolean(c[key]):fallback;}
 static uint Word(Dictionary<string,object> c,string key,uint fallback){return c.ContainsKey(key)?U(c[key]):fallback;}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static int checks,failures;static List<object> errors=new List<object>();
 static bool Equal(object a,object b)
 {
  if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
  if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}
  IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
  if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
 }
 static void Check(object got,object want,string group,int index)
 {++checks;if(!Equal(got,want)){++failures;if(errors.Count<20)errors.Add(new{group,index,got,want});}}
 static string[] Tokens(object raw){object[] rows=A(raw);string[] values=new string[rows.Length];for(int i=0;i<rows.Length;i++)values[i]=(string)rows[i];return values;}
 static Phase3Actor[] actors;static Phase3ActorReference[] references;static Phase3ActorInput[] inputs;static List<object> callbacks;
 static Phase3ActorWorld World(Dictionary<string,object> c)
 {
  actors=new Phase3Actor[3];references=new Phase3ActorReference[4];inputs=new Phase3ActorInput[3];callbacks=new List<object>();
  for(int i=0;i<3;i++)
  {
   uint value=Word(c,"initialFlags",0x81234567u)^unchecked((uint)i*0x11111111u);inputs[i]=new Phase3ActorInput{Flags8=value};
   actors[i]=new Phase3Actor{Flags1fc=value,FlagsEec=value,FlagsEf0=value,Flags1044=value,InputCa4=Flag(c,"input",true)?inputs[i]:null};
   references[i]=new Phase3ActorReference{Target=i==0&&!Flag(c,"worldObject",true)?null:actors[i]};
  }
  references[3]=new Phase3ActorReference();Phase3ActorWorld w=new Phase3ActorWorld{SystemPresent=Flag(c,"system",true),JumpButtonMask=Word(c,"jumpMask",0x40)};
  if(Flag(c,"callback",true))w.ResolveCharacter=delegate(string name)
  {
   callbacks.Add(new Dictionary<string,object>{{"system",w.SystemPresent},{"name",name}});string key=(name??"").ToLowerInvariant();int index=key=="self"?0:key=="other"?1:key=="third"?2:key=="empty"?3:-1;return index<0?null:references[index];
  };
  return w;
 }
 static Phase3ScriptCreature Creature(Dictionary<string,object> c)
 {return !Flag(c,"creature",true)?null:new Phase3ScriptCreature{ReferenceD0=Flag(c,"reference",true)?references[0]:null};}
 static object[] Snapshot()
 {
  object[] snapshot=new object[3];for(int i=0;i<3;i++)snapshot[i]=new Dictionary<string,object>{{"flags1fc",actors[i].Flags1fc},{"flagsEec",actors[i].FlagsEec},{"flagsEf0",actors[i].FlagsEf0},{"flags1044",actors[i].Flags1044},{"inputFlags",inputs[i].Flags8}};return snapshot;
 }
 static int Execute(string name,Phase3ActorWorld w,Phase3ScriptCreature c,string[] tokens,bool first)
 {
  switch(name)
  {
   case "PressJumpButton":return Phase3ActorCommands.PressJumpButton(w,c);
   case "PrefersPlayers":return Phase3ActorCommands.PrefersPlayers(c,tokens);
   case "CanShootOffScreen":return Phase3ActorCommands.CanShootOffScreen(c,tokens,first);
   case "CanOpenDoors":return Phase3ActorCommands.CanOpenDoors(c,tokens,first);
   case "CanDefend":return Phase3ActorCommands.CanDefend(c,tokens,first);
   case "Respawnable":return Phase3ActorCommands.Respawnable(c,tokens,first);
   case "SetBoss":return Phase3ActorCommands.SetBoss(c,tokens,first);
   case "SetDontMove":return Phase3ActorCommands.SetDontMove(w,c,tokens,first);
   default:throw new ArgumentException("Unknown saved action "+name);
  }
 }
 static uint Pointer(Phase3Actor actor)
 {if(actor==null)return 0;int index=Array.IndexOf(actors,actor);if(index<0)throw new ArgumentException("Actor not prepared.");return 0x10105000u+(uint)index*0x1100;}
 public static int Main(string[] args)
 {
  checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in A(data["cases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);string name=(string)v["command"];Phase3ActorWorld w=World(c);bool fault=v.ContainsKey("nativeFault");
   try
   {
    if(name=="UnderPlayerControl")
    {
     actors[0].Flags1fc=U(c["flags1fc"]);Check(Bits(Phase3ActorCommands.UnderPlayerControl(Flag(c,"bound",true)?actors[0]:null)),U(v["nativeBits"]),name+"-body",index);
    }
    else
    {
     int ret=Execute(name,w,Creature(c),Tokens(v["tokens"]),Flag(c,"first",true));
     if(fault)Check(false,true,name+"-native-fault",index);
     else{Check(ret,I(v["nativeReturn"]),name+"-return",index);Check(Snapshot(),v["nativeState"],name+"-state",index);Check(callbacks,v["callbackCalls"],name+"-callback-order",index);}
    }
   }
   catch(ArgumentException e){if(fault)Check(true,true,name+"-native-fault",index);else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["initializers"]))
  {
   Dictionary<string,object> v=O(row);Phase3ActorWorld w=World(v);Phase3Actor bound=Phase3ActorCommands.BindUnderPlayerControl(w,(string)v["operand"]);Check(Pointer(bound),U(v["nativePointer"]),"under-player-control-initializer",index);Check(callbacks,v["callbackCalls"],"under-player-control-initializer-callbacks",index);++index;
  }
  foreach(object row in A(data["shipped"]))
  {
   Dictionary<string,object> v=O(row);if((string)v["command"]!="UnderPlayerControl")continue;
   Phase3ActorWorld w=World(new Dictionary<string,object>());string operand=(string)v["operand"];int line=I(v["line"]);actors[0].Flags1fc=0x80;actors[1].Flags1fc=line%2!=0?0x80u:0u;
   w.ResolveCharacter=delegate(string name){callbacks.Add(new Dictionary<string,object>{{"system",true},{"name",name}});return operand!=null&&String.Equals(name,operand,StringComparison.OrdinalIgnoreCase)?references[1]:null;};
   Phase3Actor bound=Phase3ActorCommands.BindUnderPlayerControl(w,operand);float result=Phase3ActorCommands.UnderPlayerControl(bound);Check(Pointer(bound),U(v["nativePointer"]),"shipped-control-initializer",index);Check(callbacks,v["callbackCalls"],"shipped-control-callbacks",index);Check(Bits(result),U(v["nativeBits"]),"shipped-control-body",index);
   Dictionary<string,object> compare=O(v["comparison"]);float rhs=F(U(compare["thresholdBits"]));bool matched=(string)compare["operator"]=="=="?result==rhs:result!=rhs;Check(matched,Convert.ToBoolean(compare["matched"]),"shipped-control-comparison",index);++index;
  }
  string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
 }
}
