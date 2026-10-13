using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class CameraStateVerify
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=100};
 static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
 static uint U(Dictionary<string,object> v,string k){return Convert.ToUInt32(v[k]);}
 static bool B(Dictionary<string,object> v,string k){return Convert.ToBoolean(v[k]);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 static SpawnVector V(object o){object[] a=(object[])o;return new SpawnVector(F(Convert.ToUInt32(a[0])),F(Convert.ToUInt32(a[1])),F(Convert.ToUInt32(a[2])));}
 static uint[] VB(SpawnVector v){return new uint[]{Bits(v.X),Bits(v.Y),Bits(v.Z)};}
 static uint Pointer(CameraPoint p,CameraPoint a,CameraPoint z){return p==null?0:p==a?0x10102000u:p==z?0x10102100u:0xffffffff;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("vectors.json output.json");
  Dictionary<string,object> root=M(Json.DeserializeObject(File.ReadAllText(args[0])));int count=0,errors=0;List<object> examples=new List<object>();
  foreach(object raw in(object[])root["records"])
  {
   var row=M(raw);var v=M(row["input"]);var q=M(row["arguments"]);
   CameraPoint a=new CameraPoint{Position=V(v["pointA"])},z=new CameraPoint{Position=V(v["pointZ"])};
   CameraCutRecord current=new CameraCutRecord{Identity=0x10100000,Duration=F(U(v,"duration")),RemainingBlend=F(U(v,"currentBlend"))},other=new CameraCutRecord{Identity=0x10100100};
   CameraCutState s=new CameraCutState{Current=B(v,"current")?current:null,Selected=other,FollowTarget=a,FollowCamera=z,SuppressFlags=U(v,"suppressFlags")!=0,Progress=F(U(v,"progress")),Start=F(U(v,"start")),End=F(U(v,"end")),BlendIn=F(U(v,"blendIn")),BlendOut=F(U(v,"blendOut")),Elapsed=F(U(v,"elapsed")),BorderAmount=F(U(v,"borderAmount")),WorldPrevious=F(U(v,"worldPrevious")),WorldCurrent=F(U(v,"worldCurrent")),Flags=U(v,"flags"),Borders=U(v,"borders"),TransitionWord=(ushort)U(v,"transitionWord"),TransitionByte=(byte)U(v,"transitionByte"),WorldMode=(byte)U(v,"worldMode")};
   s.Builtin.Kind=(ushort)U(v,"kind");s.Builtin.VectorBytes=(ushort)U(v,"vectorBytes");s.Builtin.PositionStorage=U(v,"positionStorage");s.Builtin.Extra=U(v,"extra");s.StoredCamera.Position=V(v["camera"]);s.StoredTarget.Position=V(v["target"]);
   if(B(v,"currentBuiltin")){current=s.Builtin;s.Current=current;current.RemainingBlend=F(U(v,"currentBlend"));}
   string op=(string)row["operation"];
   if(op=="finish")CameraState.FinishCurrent(s);
   else if(op=="select")CameraState.Select(s,B(q,"record")?other:null,F(U(q,"start")),F(U(q,"end")),F(U(q,"blendIn")),F(U(q,"blendOut")),U(q,"borders"),U(q,"flags"));
   else CameraState.Configure(s,B(q,"camera")?a:null,B(q,"target")?z:null,U(q,"extra"),F(U(q,"start")),F(U(q,"end")),F(U(q,"blendIn")),F(U(q,"blendOut")),B(q,"followTarget"),B(q,"followCamera"),U(q,"borders"));
   var actual=new Dictionary<string,object>{{"progress",Bits(s.Progress)},{"blendIn",Bits(s.BlendIn)},{"borders",s.Borders},{"selected",s.Selected==null?0:s.Selected.Identity},{"end",Bits(s.End)},{"blendOut",Bits(s.BlendOut)},{"positionStorage",s.Builtin.PositionStorage},{"extra",s.Builtin.Extra},{"start",Bits(s.Start)},{"flags",s.Flags},{"elapsed",Bits(s.Elapsed)},{"followTarget",Pointer(s.FollowTarget,a,z)},{"followCamera",Pointer(s.FollowCamera,a,z)},{"kind",s.Builtin.Kind},{"vectorBytes",s.Builtin.VectorBytes},{"transitionWord",s.TransitionWord},{"transitionByte",s.TransitionByte},{"borderAmount",Bits(s.BorderAmount)},{"worldMode",s.WorldMode},{"worldPrevious",Bits(s.WorldPrevious)},{"worldCurrent",Bits(s.WorldCurrent)},{"currentBlend",Bits(current.RemainingBlend)},{"camera",VB(s.StoredCamera.Position)},{"target",VB(s.StoredTarget.Position)}};
   var expected=M(row["expected"]);List<string> differing=new List<string>();foreach(var pair in expected)if(Json.Serialize(pair.Value)!=Json.Serialize(actual[pair.Key]))differing.Add(pair.Key);
   count++;if(differing.Count!=0){errors++;if(examples.Count<12)examples.Add(new{index=count-1,fields=differing,expected=expected,actual=actual});}
  }
  var report=new{cases=count,mismatches=errors,examples=examples};File.WriteAllText(args[1],Json.Serialize(report));Console.WriteLine(Json.Serialize(new{cases=count,mismatches=errors}));return errors==0?0:1;
 }
}
