using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class ScriptContract20261013Verify
{
 static Dictionary<string,object> O(object v){return (Dictionary<string,object>)v;}
 static object[] A(object v){return (object[])v;}
 static int I(object v){return Convert.ToInt32(v);}
 static uint U(object v){return Convert.ToUInt32(v);}
 static bool B(object v){return Convert.ToBoolean(v);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 static int Selector(object v){uint n=unchecked((uint)Convert.ToInt64(v));return unchecked((int)n);}
 static List<object> errors=new List<object>();static int checks,failures;
 static void Check(object got,object want,string group,int index)
 {
  ++checks;bool same=(got is bool||want is bool)?Object.Equals(got,want):Convert.ToDecimal(got)==Convert.ToDecimal(want);
  if(!same){++failures;if(errors.Count<20)errors.Add(new{group,index,got,want});}
 }
 static Dictionary<ScriptContractBuildReference,uint> buildPointers;
 static Dictionary<ScriptContractRigidAnimation,uint> rigidPointers;
 static List<uint> calls;
 static ScriptContractConditionWorld World()
 {
  ScriptContractConditionWorld w=new ScriptContractConditionWorld{BuildTypeIndex=1,RigidScene=new ScriptContractRigidScene{Count=3}};
  rigidPointers=new Dictionary<ScriptContractRigidAnimation,uint>();buildPointers=new Dictionary<ScriptContractBuildReference,uint>();calls=new List<uint>();
  string[] names={"Alpha","Dupe","DUPE"};
  for(int i=0;i<3;i++)
  {
   ScriptContractRigidAnimation animation=new ScriptContractRigidAnimation{Frame4c=i+.25f};rigidPointers.Add(animation,0x10108000u+(uint)i*0x100);
   w.RigidScene.Records.Add(new ScriptContractRigidRecord{Name44=names[i],Attachment40=new ScriptContractRigidAttachment{Animation48=animation}});
  }
  ScriptContractBuildRegistry registry=new ScriptContractBuildRegistry{TypeCount=3,NameAccessors=new Func<ScriptContractBuildReference,string>[4],Buckets=new ScriptContractBuildBucket[4]};w.BuildRegistry=registry;
  Dictionary<ScriptContractBuildReference,string> recordNames=new Dictionary<ScriptContractBuildReference,string>();
  for(int t=0;t<4;t++)
  {
   registry.Buckets[t]=new ScriptContractBuildBucket{Count=3};
   registry.NameAccessors[t]=delegate(ScriptContractBuildReference r){calls.Add(buildPointers[r]);return recordNames[r];};
   for(int i=0;i<3;i++)
   {
    ScriptContractBuildReference record=new ScriptContractBuildReference{Target=new ScriptContractBuildObject{Completion6d=(byte)(i==0?2:1)}};
    registry.Buckets[t].Records.Add(record);recordNames[record]=names[i];buildPointers.Add(record,0x1011c000u+(uint)t*0x100+(uint)i*8);
   }
  }
  return w;
 }
 static uint BuildPointer(ScriptContractBuildReference r){return r==null?0:buildPointers[r];}
 static uint RigidPointer(ScriptContractRigidAnimation r){return r==null?0:rigidPointers[r];}
 public static int Main(string[] args)
 {
  checks=failures=0;errors.Clear();JavaScriptSerializer json=new JavaScriptSerializer();json.MaxJsonLength=128*1024*1024;Dictionary<string,object> data=O(json.DeserializeObject(File.ReadAllText(args[0])));int index=0;
  foreach(object row in A(data["cases"]))
  {
   Dictionary<string,object> v=O(row),c=O(v["context"]);string name=(string)v["command"];float result=0;ScriptContractConditionWorld w=new ScriptContractConditionWorld();int bound=Selector(v["initialized"]);
   try
   {
    if(name=="PartyUnderCover"){w.PartyUnderCoverValue=I(c["partyCover"]);result=ScriptContractConditions.PartyUnderCover(w);}
    else if(name=="CannotReachDestination")result=ScriptContractConditions.CannotReachDestination(B(c["creature"])?new ScriptContractCreature{Flags1e8=U(c["flags"])}:null);
    else if(name=="RigidAnimFrame")result=ScriptContractConditions.RigidAnimFrame(bound!=0?new ScriptContractRigidAnimation{Frame4c=F(U(c["frameBits"]))}:null);
    else if(name=="BuildItComplete")result=ScriptContractConditions.BuildItComplete(bound!=0?new ScriptContractBuildReference{Target=B(c["target"])?new ScriptContractBuildObject{Completion6d=(byte)I(c["status"])}:null}:null);
    else
    {
     w.ReadAliveCount=delegate(byte ignored){return (byte)I(c["count"]);};ScriptContractPacket packet=new ScriptContractPacket{SetIdB0=(byte)(c.ContainsKey("setId")?I(c["setId"]):0)};
     result=ScriptContractConditions.IsSetAlive(w,packet,bound);
    }
    Check(Bits(result),U(v["nativeBits"]),name+"-body",index);
   }
   catch(Exception e){++failures;if(errors.Count<20)errors.Add(new{index,error=e.ToString()});}++index;
  }
  foreach(object row in A(data["initializers"]))
  {
   Dictionary<string,object> v=O(row);string name=(string)v["command"],operand=(string)v["operand"];ScriptContractConditionWorld w=World();
   if(name=="IsSetAlive")Check(unchecked((uint)ScriptContractConditions.BindIsSetAlive(operand)),U(v["selector"]),name+"-initializer",index);
   else if(name=="RigidAnimFrame")
   {
    ScriptContractRigidAnimation r=ScriptContractConditions.BindRigidAnimFrame(w,operand);Check(RigidPointer(r),U(v["initializedPointer"]),name+"-initializer",index);Check(Bits(ScriptContractConditions.RigidAnimFrame(r)),U(v["nativeBits"]),name+"-initialized-body",index);
   }
   else
   {
    w.BuildTypeIndex=I(v["type"]);ScriptContractBuildReference r=ScriptContractConditions.BindBuildItComplete(w,operand);Check(BuildPointer(r),U(v["initializedPointer"]),name+"-initializer",index);Check(Bits(ScriptContractConditions.BuildItComplete(r)),U(v["nativeBits"]),name+"-initialized-body",index);
    object[] expected=A(v["callbackRecords"]);Check(calls.Count,expected.Length,name+"-callback-count",index);for(int i=0;i<Math.Min(calls.Count,expected.Length);i++)Check(calls[i],U(expected[i]),name+"-callback-order",index);
   }
   ++index;
  }
  foreach(object row in A(data["shipped"]))
  {
   Dictionary<string,object> v=O(row);string name=(string)v["command"],operand=(string)v["operand"];ScriptContractConditionWorld w=World();int line=I(v["line"]);float result=0;uint pointer=0;
   if(name=="PartyUnderCover"){w.PartyUnderCoverValue=line%2;result=ScriptContractConditions.PartyUnderCover(w);}
   else if(name=="CannotReachDestination")result=ScriptContractConditions.CannotReachDestination(new ScriptContractCreature{Flags1e8=line%2!=0?0x400000u:0u});
   else if(name=="RigidAnimFrame")
   {
    w.RigidScene.Records[0].Name44=operand??"";ScriptContractRigidAnimation r=ScriptContractConditions.BindRigidAnimFrame(w,operand);pointer=RigidPointer(r);w.RigidScene.Records[0].Attachment40.Animation48.Frame4c=line*.25f;result=ScriptContractConditions.RigidAnimFrame(r);
   }
   else if(name=="BuildItComplete")
   {
    ScriptContractBuildReference first=w.BuildRegistry.Buckets[1].Records[0];w.BuildRegistry.NameAccessors[1]=delegate(ScriptContractBuildReference candidate){return candidate==first?operand??"":"other";};ScriptContractBuildReference r=ScriptContractConditions.BindBuildItComplete(w,operand);pointer=BuildPointer(r);first.Target.Completion6d=(byte)(line%2!=0?2:1);result=ScriptContractConditions.BuildItComplete(r);
   }
   else
   {
    int selector=ScriptContractConditions.BindIsSetAlive(operand);pointer=unchecked((uint)selector);w.ReadAliveCount=delegate(byte ignored){return(byte)(line%2);};result=ScriptContractConditions.IsSetAlive(w,new ScriptContractPacket{SetIdB0=7},selector);
   }
   Check(pointer,U(v["initializedPointer"]),"shipped-"+name+"-initializer",index);Check(Bits(result),U(v["nativeBits"]),"shipped-"+name+"-body",index);
   if(v["comparison"]!=null)
   {
    Dictionary<string,object> c=O(v["comparison"]);float rhs=F(U(c["thresholdBits"]));string op=(string)c["operator"];bool matched=op=="=="?result==rhs:op=="!="?result!=rhs:op=="<"?result<rhs:op==">"?result>rhs:op=="<="?result<=rhs:result>=rhs;
    Check(matched,B(c["matched"]),"shipped-"+name+"-comparison",index);
   }
   ++index;
  }
  string output=json.Serialize(new{checks,mismatches=failures,errors,binarySha256=data["binarySha256"]});File.WriteAllText(args[1],output);Console.WriteLine(output);return failures==0?0:1;
 }
}
