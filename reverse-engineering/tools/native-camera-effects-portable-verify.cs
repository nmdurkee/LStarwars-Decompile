using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
public static class CameraEffectsVerify
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue,RecursionLimit=100};
 static Dictionary<string,object> M(object o){return(Dictionary<string,object>)o;}
 static uint U(Dictionary<string,object> v,string k){return Convert.ToUInt32(v[k]);}
 static bool B(Dictionary<string,object> v,string k){return Convert.ToBoolean(v[k]);}
 static float F(uint v){return BitConverter.ToSingle(BitConverter.GetBytes(v),0);}
 static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("vectors.json.gz output.json");
  string input;using(var f=File.OpenRead(args[0]))using(var z=new GZipStream(f,CompressionMode.Decompress))using(var r=new StreamReader(z))input=r.ReadToEnd();
  var root=M(Json.DeserializeObject(input));int count=0,errors=0;List<object> examples=new List<object>();
  foreach(object raw in(object[])root["records"])
  {
   var row=M(raw);var v=M(row["input"]);object[] defaults=(object[])v["defaults"];
   GameCameraImage camera=new GameCameraImage(Convert.FromBase64String((string)v["camera"])),alternate=new GameCameraImage(Convert.FromBase64String((string)v["alternate"]));
   CameraEffectWorld w=new CameraEffectWorld{Camera=camera,Cuts=new CameraCutState{End=F(U(v,"end")),Elapsed=F(U(v,"elapsed")),BlendOut=F(U(v,"blendOut")),Selected=new CameraCutRecord{Identity=U(v,"selected")}},CutActive=B(v,"active"),Random=new QRandom{State=U(v,"seed")},ResetValueCb=Convert.ToByte(defaults[0]),ResetValueCc=Convert.ToByte(defaults[1])};
   byte[] bindings=Convert.FromBase64String((string)v["bindings"]);Array.Copy(bindings,w.CutBindings,bindings.Length);w.Cuts.Builtin.RemainingBlend=BitConverter.ToSingle(bindings,8);
   ScriptPacket packet=new ScriptPacket{Script=new ScriptDefinition()};string[] parameterNames={"alpha","beta","gamma","delta"};float[] parameters={2.75f,1.5f,3,4};for(int i=0;i<4;i++){packet.Script.ParameterNames[i]=parameterNames[i];packet.Parameters[i]=parameters[i];}
   object[] rawTokens=(object[])v["tokens"];string[] tokens=new string[rawTokens.Length];for(int i=0;i<tokens.Length;i++)tokens[i]=(string)rawTokens[i];
   string op=(string)row["operation"];uint result=1;GameCameraImage target=B(v,"nullCamera")?null:alternate;
   switch(op)
   {
    case "end":CameraEffects.EndCut(w,packet,tokens,B(v,"first"));break;
    case "shake":CameraEffects.Shake(w,packet,tokens,B(v,"first"));break;
    case "judder":CameraEffects.Judder(w,packet,tokens,B(v,"first"));break;
    case "reset":CameraEffects.ResetCommand(w,B(v,"first"));break;
    case "setShake":CameraEffects.SetShake(w,target,F(U(v,"magnitude")),F(U(v,"time")),F(U(v,"speed")));break;
    case "setJudder":CameraEffects.SetJudder(w,target,F(U(v,"magnitude")),unchecked((byte)U(v,"axis")));break;
    case "resetHelper":CameraEffects.Reset(w,target);break;
    case "clearBindings":CameraEffects.ClearBindings(w);break;
    case "behind":object[] p=(object[])v["position"];result=Bits(CameraEffects.Behind(w,U(v,"gate")==3?new CameraPoint{Position=new SpawnVector(Convert.ToSingle(p[0]),Convert.ToSingle(p[1]),Convert.ToSingle(p[2]))}:null));break;
    default:throw new ArgumentException("Unknown operation.");
   }
   var actual=new Dictionary<string,object>{{"camera",Convert.ToBase64String(camera.Bytes)},{"alternate",Convert.ToBase64String(alternate.Bytes)},{"bindings",Convert.ToBase64String(w.CutBindings)},{"end",Bits(w.Cuts.End)},{"elapsed",Bits(w.Cuts.Elapsed)},{"blendOut",Bits(w.Cuts.BlendOut)},{"selected",w.Cuts.Selected==null?0:w.Cuts.Selected.Identity},{"active",w.CutActive},{"seed",w.Random.State}};
   var expected=M(row["expected"]);List<string> differing=new List<string>();foreach(var pair in expected)if(Json.Serialize(pair.Value)!=Json.Serialize(actual[pair.Key]))differing.Add(pair.Key);if(result!=U(row,"result"))differing.Add("result");count++;if(differing.Count!=0){errors++;if(examples.Count<12)examples.Add(new{index=count-1,operation=op,fields=differing});}
  }
  var report=new{cases=count,mismatches=errors,examples=examples};File.WriteAllText(args[1],Json.Serialize(report));Console.WriteLine(Json.Serialize(new{cases=count,mismatches=errors}));return errors==0?0:1;
 }
}
