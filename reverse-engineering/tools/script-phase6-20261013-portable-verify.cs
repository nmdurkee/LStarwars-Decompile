using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptPhase620261013Verify
{
 static Dictionary<string,object> O(object v){return(Dictionary<string,object>)v;}
 static object[] A(object v){return(object[])v;}
 static int I(object v){return Convert.ToInt32(v);}
 static uint U(object v){return Convert.ToUInt32(v);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
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
 static string[] Tokens(object v){if(v==null)return new string[0];object[] a=A(v);string[] t=new string[a.Length];for(int i=0;i<a.Length;i++)t[i]=(string)a[i];return t;}
 static ScriptPacket Packet(Dictionary<string,object> c)
 {
  if(!Flag(c,"packet",true))return null;ScriptPacket p=new ScriptPacket();float[] values={1.75f,2f,7f,-1f};if(c.ContainsKey("parameters")){object[] vv=A(c["parameters"]);for(int i=0;i<4;i++)values[i]=Convert.ToSingle(vv[i]);}for(int i=0;i<4;i++)p.Parameters[i]=values[i];if(Flag(c,"script",true)){p.Script=new ScriptDefinition();string[] names={"alpha","beta","gamma","delta"};for(int i=0;i<4;i++)p.Script.ParameterNames[i]=names[i];}return p;
 }
 static List<Phase6Hint> rows;static uint[] doneBacking;
 static Phase6HintWorld Hints(Dictionary<string,object> c,object rowData)
 {
  rows=new List<Phase6Hint>();foreach(object row in A(rowData)){Dictionary<string,object> h=O(row);rows.Add(new Phase6Hint{Id=(short)I(h["id"]),Flags2=(byte)I(h["flags"]),Complete14=(byte)I(h["complete"]),Cooldown0cBits=U(h["cooldownBits"]),Timer18Bits=U(h["timerBits"])});}
  HashSet<int> registered=new HashSet<int>();if(c.ContainsKey("registered")){foreach(object id in A(c["registered"]))registered.Add(I(id));}else foreach(int id in new[]{0,1,2,7})registered.Add(id);
  object[] words=c.ContainsKey("doneWords")?A(c["doneWords"]):new object[]{0x80000000u,0x12340000u};doneBacking=new uint[words.Length];for(int i=0;i<words.Length;i++)doneBacking[i]=U(words[i]);
  Phase6HintWorld w=new Phase6HintWorld{Records=Flag(c,"list",true)?rows:null,Active=c.ContainsKey("activeIndex")&&c["activeIndex"]!=null?rows[I(c["activeIndex"])]:null,LastVariantBd=(byte)Integer(c,"lastVariant",0),Random=new QRandom{State=Word(c,"rng",1)},PresentationC8Bits=Word(c,"counterC8Bits",Bits(12.5f)),PresentationCcBits=Word(c,"counterCcBits",Bits(-3.25f)),DoneWords=Flag(c,"bitmap",true)?doneBacking:null,DoneWordCount=Integer(c,"doneWordCount",words.Length)};w.Registered=delegate(int id){return registered.Contains(id);};return w;
 }
 static object HintSnapshot(Phase6HintWorld w)
 {
  List<object> r=new List<object>();foreach(Phase6Hint row in rows)r.Add(new Dictionary<string,object>{{"complete",row.Complete14},{"timerBits",row.Timer18Bits}});
  return new Dictionary<string,object>{{"activeIndex",w.Active==null?(object)null:rows.IndexOf(w.Active)},{"lastVariant",w.LastVariantBd},{"rng",w.Random.State},{"counterC8Bits",w.PresentationC8Bits},{"counterCcBits",w.PresentationCcBits},{"rows",r},{"doneWords",doneBacking}};
 }
 static object DefaultRows()
 {return new object[]{new Dictionary<string,object>{{"id",1},{"flags",0},{"complete",0},{"cooldownBits",Bits(2.5f)},{"timerBits",0}},new Dictionary<string,object>{{"id",2},{"flags",1},{"complete",0},{"cooldownBits",Bits(5f)},{"timerBits",0}},new Dictionary<string,object>{{"id",-1},{"flags",0},{"complete",0},{"cooldownBits",0},{"timerBits",0}}};}
 static SceneryGizmo record;
 static Phase6ForceWorld Force(Dictionary<string,object> c,string name)
 {
  record=new SceneryGizmo{Type=(byte)Integer(c,"recordType",1),Target=Flag(c,"target",true)?new SceneryObject{Name=name}:null};
  SceneryRegistry registry=new SceneryRegistry{NameBuckets=new SceneryNameBucket[4],Outputs=Flag(c,"typeTable",true)?new Func<SceneryGizmo,uint,int,uint>[Integer(c,"typeCount",3)]:null};
  SceneryNameBindings bindings=new SceneryNameBindings{TypeCount=Integer(c,"typeCount",3),NameAccessors=Flag(c,"typeTable",true)?new Func<SceneryGizmo,string>[4]:null};
  Phase6ForceWorld w=new Phase6ForceWorld{ForceType=Integer(c,"forceType",1),Scenery=new SceneryWorld{Registry=registry,Bindings=bindings}};
  if(record.Target!=null)w.Fields.Add(record.Target,new Phase6ForceAttachment{Mode88=(short)Integer(c,"mode",-1),Link40Present=Flag(c,"link",true),LinkFlags24=(byte)Integer(c,"linkFlags",6),Fields=new ForceObjectState{Shared=new ForcePlatformState{FlagsA0=Word(c,"flags",0)},Flags74=Word(c,"flags74",0),Timer4c=F(Word(c,"timerBits",0)),GroupPresent=Flag(c,"group",true),GroupState=Integer(c,"groupState",2)}});
  for(int i=0;i<4;i++){registry.NameBuckets[i]=new SceneryNameBucket{Count=1};registry.NameBuckets[i].Records.Add(record);if(bindings.NameAccessors!=null)bindings.NameAccessors[i]=SceneryNameBindings.ObjectName;}
  if(registry.Outputs!=null&&Flag(c,"callback",true))for(int i=0;i<registry.Outputs.Length;i++)registry.Outputs[i]=delegate(SceneryGizmo gizmo,uint output,int include){return Phase6WorldConditions.ForceOutput(w,gizmo,output,include);};return w;
 }
 static Phase6SocketActor selfSocket;
 static Phase6SocketWorld Sockets(Dictionary<string,object> c)
 {
  Phase6SocketRegistry registry=Flag(c,"registry",true)?new Phase6SocketRegistry():null;
  if(registry!=null)foreach(sbyte id in new sbyte[]{-2,0,1,2}){Phase6Socket s=new Phase6Socket();registry.Sockets[id]=s;foreach(short seg in new short[]{-2,-1,0,1,2})s.Segments[seg]=new Phase6SocketRow{Scale78=F(Word(c,"scaleBits",Bits(10f))),Offset7c=F(Word(c,"offsetBits",Bits(3f)))};}
  selfSocket=new Phase6SocketActor{Socket670=new Phase6SocketPosition{Socket1=(sbyte)Integer(c,"selfSocket",0),Segment2=(short)Integer(c,"selfSegment",0),Progress4=F(Word(c,"selfProgressBits",Bits(.25f)))}};
  return new Phase6SocketWorld{Registry=registry,PrimaryPlayer=Flag(c,"player",true)?new Phase6SocketActor{Socket670=new Phase6SocketPosition{Socket1=(sbyte)Integer(c,"playerSocket",0),Segment2=(short)Integer(c,"playerSegment",0),Progress4=F(Word(c,"playerProgressBits",Bits(.75f)))}}:null};
 }
 static Phase6SocketCreature SocketCreature(Dictionary<string,object> c)
 {return Flag(c,"creature",true)?new Phase6SocketCreature{ReferenceD0=Flag(c,"reference",true)?new Phase6SocketReference{Target=Flag(c,"target",true)?selfSocket:null}:null}:null;}
 public static int Main(string[] args)
 {
  checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in A(data["hintCases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);Phase6HintWorld w=Hints(c,v["rows"]);string method=(string)v["method"];bool fault=v.ContainsKey("nativeFault");
   try
   {
    if(method=="SetHint")Check(Phase6HintCommands.SetHint(w,Packet(c),Tokens(v["tokens"]),Flag(c,"first",true)),1,"set-hint-return",index);
    else if(method=="Request")Phase6HintCommands.Request(w,I(v["requested"]),Convert.ToBoolean(v["force"]),Convert.ToBoolean(v["ignore"]));
    else if(method=="Activate")Phase6HintCommands.Activate(w,v["target"]==null?null:rows[I(v["target"])],Convert.ToBoolean(v["force"]),Convert.ToBoolean(v["ignore"]));
    else Phase6HintCommands.MarkDone(w,rows[I(v["target"])]);
    if(fault)Check(false,true,"hint-native-fault",index);else Check(HintSnapshot(w),v["native"],"hint-full-state-"+method,index);
   }
   catch(ArgumentException e){if(fault){Check(true,true,"hint-native-fault",index);Check(HintSnapshot(w),v["native"],"hint-state-before-fault",index);}else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["currentCases"]))
  {
   Dictionary<string,object> v=O(row);Phase6HintWorld w=new Phase6HintWorld{Active=Convert.ToBoolean(v["active"])?new Phase6Hint{Id=(short)I(v["id"])}:null};Check(unchecked((uint)Phase6HintCommands.CurrentHintIdValue(w)),U(v["nativeInt"]),"current-hint-int",index);Check(Bits(Phase6HintCommands.CurrentHintId(w)),U(v["nativeBits"]),"current-hint-float",index);++index;
  }
  foreach(object row in A(data["forceCases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);Phase6ForceWorld w=Force(c,"Alpha");bool fault=v.ContainsKey("nativeFault");
   try{if((string)v["method"]=="Output")Check(Phase6WorldConditions.ForceOutput(w,record,U(v["output"]),I(v["include"])),U(v["nativeReturn"]),"force-all-outputs",index);else{float result=Phase6WorldConditions.ForceAtEnd(w,Flag(c,"bound",true)?record:null);if(fault)Check(false,true,"force-native-fault",index);else Check(Bits(result),U(v["nativeBits"]),"force-at-end",index);}}
   catch(ArgumentException e){if(fault)Check(true,true,"force-native-fault",index);else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["socketCases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);Phase6SocketWorld w=Sockets(c);bool fault=v.ContainsKey("nativeFault");
   try{float result=(string)v["method"]=="Scalar"?Phase6WorldConditions.SocketScalar(w.Registry,selfSocket.Socket670):Phase6WorldConditions.SockDistanceToPlayer(w,SocketCreature(c));if(fault)Check(false,true,"socket-native-fault",index);else Check(Bits(result),U(v["nativeBits"]),"socket-"+(string)v["method"],index);}
   catch(ArgumentException e){if(fault)Check(true,true,"socket-native-fault",index);else{++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}}
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["initializers"]))
  {
   Dictionary<string,object> v=O(row);Phase6ForceWorld w=Force(v,"Alpha");SceneryGizmo initialized=Phase6WorldConditions.BindForceAtEnd(w,(string)v["operand"]);Check(initialized==null?0u:0x10126000u,U(v["nativePointer"]),"force-at-end-initializer",index);++index;
  }
  foreach(object row in A(data["shipped"]))
  {
   Dictionary<string,object> v=O(row);string name=(string)v["command"];if(name=="SetHint")continue;Dictionary<string,object> c=O(v["context"]);float result;uint pointer=0;
   if(name=="CurrentHintId")result=Phase6HintCommands.CurrentHintId(Hints(c,DefaultRows()));
   else if(name=="ForceAtEnd"){Phase6ForceWorld w=Force(c,(string)v["operand"]);SceneryGizmo initialized=Phase6WorldConditions.BindForceAtEnd(w,(string)v["operand"]);pointer=initialized==null?0u:0x10126000u;result=Phase6WorldConditions.ForceAtEnd(w,initialized);}
   else{Phase6SocketWorld w=Sockets(c);result=Phase6WorldConditions.SockDistanceToPlayer(w,SocketCreature(c));}
   Check(pointer,U(v["nativePointer"]),"shipped-"+name+"-initializer",index);Check(Bits(result),U(v["nativeBits"]),"shipped-"+name+"-body",index);
   if(v["comparison"]!=null){Dictionary<string,object> compare=O(v["comparison"]);string op=(string)compare["operator"];float rhs=F(U(compare["thresholdBits"]));bool match=op=="=="?result==rhs:op=="!="?result!=rhs:op=="<"?result<rhs:op==">"?result>rhs:op=="<="?result<=rhs:result>=rhs;Check(match,Convert.ToBoolean(compare["matched"]),"shipped-"+name+"-comparison",index);}++index;
  }
  string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
 }
}
