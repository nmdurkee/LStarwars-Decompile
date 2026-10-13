using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase420261013Verify
{
 static Dictionary<string,object> O(object v){return(Dictionary<string,object>)v;}
 static object[] A(object v){return(object[])v;}
 static int I(object v){return Convert.ToInt32(v);}
 static uint U(object v){return Convert.ToUInt32(v);}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static bool Flag(Dictionary<string,object> c,string key,bool fallback){return c.ContainsKey(key)?Convert.ToBoolean(c[key]):fallback;}
 static int Integer(Dictionary<string,object> c,string key,int fallback){return c.ContainsKey(key)?I(c[key]):fallback;}
 static List<object> errors=new List<object>();static int checks,failures;
 static bool Equal(object a,object b)
 {
  if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;
  if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object key in ad.Keys)if(!bd.Contains(key)||!Equal(ad[key],bd[key]))return false;return true;}
  IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}
  if(a is bool||b is bool||a is string||b is string)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
 }
 static void Check(object got,object want,string group,int index){++checks;if(!Equal(got,want)){++failures;if(errors.Count<20)errors.Add(new{group,index,got,want});}}
 static string[] Tokens(object v){object[] array=A(v);string[] result=new string[array.Length];for(int i=0;i<array.Length;i++)result[i]=(string)array[i];return result;}
 static Phase4Actor[] actors;static Phase4ActorReference[] references;static List<object> callbacks;
 static Phase4ScriptWorld World(Dictionary<string,object> c)
 {
  actors=new Phase4Actor[2];references=new Phase4ActorReference[3];callbacks=new List<object>();
  for(int i=0;i<2;i++)
  {
   actors[i]=new Phase4Actor{Set378=(byte)Integer(c,"initialSet",5),Context7b5=(byte)Integer(c,i==0?"contextByte":"boundContextByte",59)};
   if(Flag(c,"linked",true)&&(i==0||Flag(c,"boundLinked",true)))actors[i].LinkedCd0=new Phase4Vehicle{Type1064=(short)Integer(c,i==0?"vehicleType":"boundVehicleType",7)};
   references[i]=new Phase4ActorReference{Target=i==0&&!Flag(c,"worldObject",true)?null:actors[i]};
  }
  references[2]=new Phase4ActorReference();Phase4ScriptWorld w=new Phase4ScriptWorld{SystemPresent=Flag(c,"system",true),SpeederBikeType=(short)Integer(c,"bikeType",7),AliveCounts=new byte[17]};
  if(c.ContainsKey("counts")){object[] values=A(c["counts"]);for(int i=0;i<17;i++)w.AliveCounts[i]=(byte)I(values[i]);}
  else for(int i=0;i<17;i++)w.AliveCounts[i]=(byte)((i*13+Integer(c,"countSeed",11))&255);
  if(Flag(c,"callback",true))w.ResolveCharacter=delegate(string name)
  {
   callbacks.Add(new Dictionary<string,object>{{"system",w.SystemPresent},{"name",name}});string key=(name??"").ToLowerInvariant();int i=key=="self"?0:key=="other"?1:key=="empty"?2:-1;return i<0?null:references[i];
  };
  return w;
 }
 static Phase4ScriptCreature Creature(Dictionary<string,object> c)
 {return Flag(c,"creature",true)?new Phase4ScriptCreature{ReferenceD0=Flag(c,"reference",true)?references[0]:null}:null;}
 static ScriptPacket Packet(Dictionary<string,object> c)
 {
  if(!Flag(c,"packet",true))return null;ScriptPacket packet=new ScriptPacket();float[] values={2.75f,1f,16f,17f};if(c.ContainsKey("parameters")){object[] vv=A(c["parameters"]);for(int i=0;i<4;i++)values[i]=Convert.ToSingle(vv[i]);}
  for(int i=0;i<4;i++)packet.Parameters[i]=values[i];if(Flag(c,"script",true)){packet.Script=new ScriptDefinition();string[] names={"alpha","beta","gamma","delta"};for(int i=0;i<4;i++)packet.Script.ParameterNames[i]=names[i];}return packet;
 }
 static uint Pointer(Phase4Actor actor){if(actor==null)return 0;int i=Array.IndexOf(actors,actor);if(i<0)throw new ArgumentException("Unknown actor.");return 0x10106000u+(uint)i*0x1100;}
 public static int Main(string[] args)
 {
  checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in A(data["setCases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);Phase4ScriptWorld w=World(c);
   try{int ret=Phase4ScriptCommands.AddToSet(w,Packet(c),Creature(c),Tokens(v["tokens"]),Flag(c,"first",true));Check(ret,I(v["nativeReturn"]),"add-to-set-return",index);Check(actors[0].Set378,I(v["nativeSet"]),"add-to-set-actor-byte",index);Check(w.AliveCounts,v["nativeCounts"],"add-to-set-all-count-bytes",index);}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["bikeCases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);Phase4ScriptWorld w=World(c);bool fault=v.ContainsKey("nativeFault");
   try{float value=Phase4ScriptCommands.OnSpeederBike(w,Creature(c),Flag(c,"bound",false)?actors[1]:null);if(fault)Check(false,true,"bike-null-creature-native-fault",index);else Check(Bits(value),U(v["nativeBits"]),"bike-body",index);}
   catch(ArgumentException e){if(fault)Check(true,true,"bike-null-creature-native-fault",index);else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["initializers"]))
  {
   Dictionary<string,object> v=O(row);Phase4ScriptWorld w=World(v);Phase4Actor bound=Phase4ScriptCommands.BindOnSpeederBike(w,(string)v["operand"]);Check(Pointer(bound),U(v["nativePointer"]),"bike-name-initializer",index);Check(callbacks,v["callbackCalls"],"bike-name-callback-order",index);++index;
  }
  foreach(object row in A(data["shipped"]))
  {
   Dictionary<string,object> v=O(row);if((string)v["command"]!="OnSpeederBike")continue;Dictionary<string,object> c=O(v["context"]);Phase4ScriptWorld w=World(c);string operand=(string)v["operand"];
   w.ResolveCharacter=delegate(string name){callbacks.Add(new Dictionary<string,object>{{"system",true},{"name",name}});return operand!=null&&String.Equals(name,operand,StringComparison.OrdinalIgnoreCase)?references[1]:null;};
   Phase4Actor bound=Phase4ScriptCommands.BindOnSpeederBike(w,operand);float result=Phase4ScriptCommands.OnSpeederBike(w,Creature(c),bound);Check(Pointer(bound),U(v["nativePointer"]),"shipped-bike-name-initializer",index);Check(callbacks,v["callbackCalls"],"shipped-bike-callbacks",index);Check(Bits(result),U(v["nativeBits"]),"shipped-bike-body",index);
   Dictionary<string,object> compare=O(v["comparison"]);float rhs=F(U(compare["thresholdBits"]));bool matched=(string)compare["operator"]=="=="?result==rhs:result!=rhs;Check(matched,Convert.ToBoolean(compare["matched"]),"shipped-bike-comparison",index);++index;
  }
  string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
 }
}
