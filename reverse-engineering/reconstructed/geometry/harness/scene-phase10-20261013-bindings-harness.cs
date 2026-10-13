using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Geometry;
public static class RenderTargetBindingPhase10Harness
{
 static readonly JavaScriptSerializer Json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};
 static Dictionary<string,object> Map(object v){return(Dictionary<string,object>)v;}
 static object[] Arr(object v){return(object[])v;}
 static uint U(object v){return Convert.ToUInt32(v);}
 static int I(object v){return Convert.ToInt32(v);}
 static int[] Ints(object v){var a=Arr(v);var r=new int[a.Length];for(int i=0;i<r.Length;++i)r[i]=I(a[i]);return r;}
 static bool Equal(int[] a,object value){var b=Ints(value);return a!=null&&a.Length==2&&b.Length==2&&a[0]==b[0]&&a[1]==b[1];}
 static int checks,failures;static List<string> errors=new List<string>();
 static void Check(bool passed,string label){++checks;if(!passed){++failures;if(errors.Count<20)errors.Add(label);}}
 static RenderTargetBindingState State(object value){var v=Map(value);return new RenderTargetBindingState{BackendWidth=I(v["contextWidth"]),BackendHeight=I(v["contextHeight"]),Flag=U(v["flag"]),Primary=U(v["primary"]),Secondary=U(v["secondary"]),Active=U(v["active"]),Screen=Ints(v["screen"]),Origin=Ints(v["origin"])};}
 static RenderTargetSurface Surface(object value){var v=Map(value);return new RenderTargetSurface{Handle=U(v["surfaceHandle"]),Width=Convert.ToUInt16(v["surfaceWidth"]),Height=Convert.ToUInt16(v["surfaceHeight"])};}
 static bool Matches(RenderTargetBindingState s,RenderTargetSurface t,object value){var v=Map(value);return s.BackendWidth==I(v["contextWidth"])&&s.BackendHeight==I(v["contextHeight"])&&s.Flag==U(v["flag"])&&s.Primary==U(v["primary"])&&s.Secondary==U(v["secondary"])&&s.Active==U(v["active"])&&t.Handle==U(v["surfaceHandle"])&&t.Width==Convert.ToUInt16(v["surfaceWidth"])&&t.Height==Convert.ToUInt16(v["surfaceHeight"])&&Equal(s.Screen,v["screen"])&&Equal(s.Origin,v["origin"]);}
 static void Change(RenderTargetBindingState s,RenderTargetSurface t,object value){var c=Map(value);foreach(var item in c){switch(item.Key){case "contextWidth":s.BackendWidth=I(item.Value);break;case "contextHeight":s.BackendHeight=I(item.Value);break;case "flag":s.Flag=U(item.Value);break;case "primary":s.Primary=U(item.Value);break;case "secondary":s.Secondary=U(item.Value);break;case "active":s.Active=U(item.Value);break;case "surfaceHandle":t.Handle=U(item.Value);break;case "surfaceWidth":t.Width=Convert.ToUInt16(item.Value);break;case "surfaceHeight":t.Height=Convert.ToUInt16(item.Value);break;case "screen":var screen=Ints(item.Value);s.Screen[0]=screen[0];s.Screen[1]=screen[1];break;case "origin":var origin=Ints(item.Value);s.Origin[0]=origin[0];s.Origin[1]=origin[1];break;default:throw new ArgumentException("Unknown explicit service mutation.");}}}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("nativeFixturesJsonGzip resultJson");Dictionary<string,object> f;using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))f=Map(Json.DeserializeObject(r.ReadToEnd()));int cases=0;
  foreach(object value in Arr(f["cases"]))
  {
   var c=Map(value);var state=State(c["before"]);var surface=Surface(c["before"]);var plan=Map(c["plan"]);var events=Arr(c["nativeEvents"]);int at=0;
   Func<string,uint[],bool,uint> invoke=delegate(string edge,uint[] callArgs,bool receiver){if(at>=events.Length)throw new InvalidOperationException("Unexpected binding service.");var item=Map(events[at++]);var wanted=Arr(item["args"]);bool same=wanted.Length==callArgs.Length;for(int i=0;same&&i<callArgs.Length;++i)same=U(wanted[i])==callArgs[i];Check(receiver&&same&&(string)item["edge"]==edge&&Matches(state,surface,item["before"]),"ordered original binding service "+cases+"/"+at);var action=Map(plan[edge]);Change(state,surface,action["changes"]);return U(action["return"]);};
   var services=new RenderTargetBindingServices{Bind=delegate(uint slot,uint handle){return invoke("bind",new[]{slot,handle},true);},State=delegate(uint index,uint word){return invoke("state",new[]{index,word},true);},Refresh=delegate(RenderTargetBindingState current){return invoke("refresh",new uint[0],Object.ReferenceEquals(current,state));}};uint result=RenderTargetDimensionBinding.Apply(state,Convert.ToBoolean(c["present"])?surface:null,U(c["slot"]),services);Check(Matches(state,surface,c["native"]),"complete caller owned state "+cases);Check(result==U(c["nativeResult"]),"opaque service return "+cases);Check(at==events.Length,"all service calls "+cases);++cases;
  }
  File.WriteAllText(args[1],Json.Serialize(new{checks,failures,errors,portableReplayCases=cases,scope="Original target binding caller, signed/unsigned concrete dimensions, truncating origin and callback mutation ordering. Device binding/state/context refresh remain explicit services."}));return failures==0?0:1;
 }
}
