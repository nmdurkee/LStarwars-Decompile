using System;
using System.IO;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class CameraCommandVerify
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

 static uint PointIdentity(CameraPoint p,Dictionary<CameraPoint,uint> ids){uint v;return p==null?0:ids.TryGetValue(p,out v)?v:0xffffffff;}
 static SpawnVector VF(object o){object[] a=(object[])o;return new SpawnVector(Convert.ToSingle(a[0]),Convert.ToSingle(a[1]),Convert.ToSingle(a[2]));}
 public static int Main(string[] args)
 {
  if(args.Length!=3)throw new ArgumentException("vectors.json sine.f32 output.json");
  byte[] sb=File.ReadAllBytes(args[1]);float[] sine=new float[32768];Buffer.BlockCopy(sb,0,sine,0,sb.Length);
  var root=M(Json.DeserializeObject(File.ReadAllText(args[0])));int count=0,errors=0;List<object> examples=new List<object>();
  foreach(object raw in(object[])root["records"])
  {
   var row=M(raw);var o=M(row["input"]);var v=M(o["state"]);
   CameraPoint a=new CameraPoint{Position=V(v["pointA"])},z=new CameraPoint{Position=V(v["pointZ"])};
   CameraCutRecord current=new CameraCutRecord{Identity=0x10100000,Duration=F(U(v,"duration")),RemainingBlend=F(U(v,"currentBlend"))},other=new CameraCutRecord{Identity=0x10100100};
   CameraCutState s=new CameraCutState{Current=B(v,"current")?current:null,Selected=other,FollowTarget=a,FollowCamera=z,SuppressFlags=U(v,"suppressFlags")!=0,Progress=F(U(v,"progress")),Start=F(U(v,"start")),End=F(U(v,"end")),BlendIn=F(U(v,"blendIn")),BlendOut=F(U(v,"blendOut")),Elapsed=F(U(v,"elapsed")),BorderAmount=F(U(v,"borderAmount")),WorldPrevious=F(U(v,"worldPrevious")),WorldCurrent=F(U(v,"worldCurrent")),Flags=U(v,"flags"),Borders=U(v,"borders"),TransitionWord=(ushort)U(v,"transitionWord"),TransitionByte=(byte)U(v,"transitionByte"),WorldMode=(byte)U(v,"worldMode")};
   s.Builtin.Kind=(ushort)U(v,"kind");s.Builtin.VectorBytes=(ushort)U(v,"vectorBytes");s.Builtin.PositionStorage=U(v,"positionStorage");s.Builtin.Extra=U(v,"extra");s.StoredCamera.Position=V(v["camera"]);s.StoredTarget.Position=V(v["target"]);
   if(B(v,"currentBuiltin")){current=s.Builtin;s.Current=current;current.RemainingBlend=F(U(v,"currentBlend"));}

   CameraCommandWorld w=new CameraCommandWorld{State=s,SineTable=sine,CurrentCamera=new CameraPoint{Position=VF(o["currentCamera"])},Scene=new CameraScene{Dynamic=(string)o["sceneMode"]=="dynamic"},Actors=new ActorStateWorld{ActiveCount=1,NameCallback=B(o,"callback")}};
   var identities=new Dictionary<CameraPoint,uint>{{a,0x10102000},{z,0x10102100}};
   CameraPoint loc=new CameraPoint{Position=VF(o["locator"])},camloc=new CameraPoint{Position=VF(o["cameraLocator"])},actorPoint=new CameraPoint{Position=VF(o["actor"])},scenePoint=new CameraPoint{Position=VF(o["scene"])},overridePoint=new CameraPoint{Position=VF(o["overridePosition"])};
   identities[loc]=0x10108010;identities[camloc]=0x1010804c;identities[actorPoint]=0x10110080;identities[scenePoint]=w.Scene.Dynamic?0x10135070u:0x10133030u;identities[overridePoint]=0x10136030;
   w.Locators.Add(new CameraNamedPoint{Name=B(o,"missingLocator")?"absent":(string)o["locatorName"],Point=loc});w.Locators.Add(new CameraNamedPoint{Name=(string)o["cameraLocatorName"],Point=camloc});
   ActorStateRecord actor=new ActorStateRecord{Flags1fc=1,Definition=new ActorStateDefinition{Name=B(o,"missingCharacter")?"absent":(string)o["characterName"]}};actor.WorldObject=actor;w.Actors.Actors.Add(actor);w.Actors.PrimaryPlayer=actor;w.Actors.Players[0]=actor;w.ActorOrigins[actor]=actorPoint;
   string ov=(string)o["override"];w.Scene.Objects.Add(new CameraSceneObject{Name=B(o,"missingScene")?"absent":(string)o["sceneName"],Position=scenePoint,OverridePosition=ov=="valid"?overridePoint:null,OverrideIsMinusOne=ov=="minusone"});
   object[] rawTokens=(object[])o["tokens"];string[] tokens=new string[rawTokens.Length];for(int i=0;i<tokens.Length;i++)tokens[i]=(string)rawTokens[i];
   ScriptPacket packet=new ScriptPacket{Script=new ScriptDefinition()};
   string[] parameterNames={"alpha","beta","gamma","delta"};float[] parameters={2.75f,1.5f,3,4};for(int i=0;i<4;i++){packet.Script.ParameterNames[i]=parameterNames[i];packet.Parameters[i]=parameters[i];}

   bool result=CameraCommands.Cut(w,packet,B(o,"selfReference")?actor:null,tokens,B(o,"first"));
   var actual=new Dictionary<string,object>{{"progress",Bits(s.Progress)},{"blendIn",Bits(s.BlendIn)},{"borders",s.Borders},{"selected",s.Selected==null?0:s.Selected.Identity},{"end",Bits(s.End)},{"blendOut",Bits(s.BlendOut)},{"positionStorage",s.Builtin.PositionStorage},{"extra",s.Builtin.Extra},{"start",Bits(s.Start)},{"flags",s.Flags},{"elapsed",Bits(s.Elapsed)},{"followTarget",PointIdentity(s.FollowTarget,identities)},{"followCamera",PointIdentity(s.FollowCamera,identities)},{"kind",s.Builtin.Kind},{"vectorBytes",s.Builtin.VectorBytes},{"transitionWord",s.TransitionWord},{"transitionByte",s.TransitionByte},{"borderAmount",Bits(s.BorderAmount)},{"worldMode",s.WorldMode},{"worldPrevious",Bits(s.WorldPrevious)},{"worldCurrent",Bits(s.WorldCurrent)},{"currentBlend",Bits(current.RemainingBlend)},{"camera",VB(s.StoredCamera.Position)},{"target",VB(s.StoredTarget.Position)}};

   var expected=M(M(row["expected"])["state"]);List<string> differing=new List<string>();foreach(var pair in expected)if(Json.Serialize(pair.Value)!=Json.Serialize(actual[pair.Key]))differing.Add(pair.Key);if(!result)differing.Add("result");
   count++;if(differing.Count!=0){errors++;if(examples.Count<12)examples.Add(new{index=count-1,fields=differing,expected=expected,actual=actual});}
  }
  foreach(object raw in(object[])root["rotation"])
  {var row=M(raw);SpawnVector value=CameraCommands.RotateX(V(row["input"]),Convert.ToInt32(row["angle"]),sine);uint[] actual=VB(value);count++;if(Json.Serialize(actual)!=Json.Serialize(row["expected"])){errors++;if(examples.Count<12)examples.Add(new{rotation=true,input=row,actual=actual});}}
  var report=new{cases=count,mismatches=errors,examples=examples,scope="State/result replay. Original-native fixture separately checks argument values and lookup/numeric call order."};File.WriteAllText(args[2],Json.Serialize(report));Console.WriteLine(Json.Serialize(new{cases=count,mismatches=errors}));return errors==0?0:1;
 }
}
