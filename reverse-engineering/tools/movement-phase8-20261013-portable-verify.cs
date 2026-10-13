using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Navigation;
public static class MovementPhase820261013Verify
{
 static Dictionary<string,object> M(object v){return(Dictionary<string,object>)v;}
 static int I(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?Convert.ToInt32(o[k]):d;}
 static uint U(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
 static bool B(Dictionary<string,object> o,string k,bool d){return o.ContainsKey(k)?Convert.ToBoolean(o[k]):d;}
 static byte[] Image(object text){using(var s=new MemoryStream(Convert.FromBase64String((string)text)))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var o=new MemoryStream()){z.CopyTo(o);return o.ToArray();}}
 static uint Word(byte[] b,int o){return(uint)b[o]|(uint)b[o+1]<<8|(uint)b[o+2]<<16|(uint)b[o+3]<<24;}
 static void Set(byte[] b,int o,uint v){for(int i=0;i<4;i++)b[o+i]=unchecked((byte)(v>>(8*i)));}
 static bool Equal(byte[] a,byte[] b){if(a.Length!=b.Length)return false;for(int i=0;i<a.Length;i++)if(a[i]!=b[i])return false;return true;}
 static string[] Tokens(object o){object[] a=(object[])o;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output paths required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int count=0,failed=0,checks=0;var errors=new List<object>();
  foreach(object v in(object[])data["vectors"])
  {
   var row=M(v);var input=M(row["input"]);count++;try
   {
    byte[] image=Image(row["before"]);var edges=new NavigationConnection[3];for(int j=0;j<3;j++){int p=0x4000+j*0x40;edges[j]=new NavigationConnection{ForwardFlags=Word(image,p),ReverseFlags=Word(image,p+4),Endpoint0=image[p+0x10],Endpoint1=image[p+0x11]};}
    object[] names=input.ContainsKey("names")?(object[])input["names"]:new object[]{"A","B","C"};var path=new NavigationPath();
    for(int j=0;j<I(input,"nodeCount",3);j++){var node=new NavigationLocator{Name=(string)names[j]};for(int k=0;k<I(input,"edgeCount",3);k++)node.Connections.Add(edges[k]);path.Locators.Add(node);}
    string gate=input.ContainsKey("gate")?(string)input["gate"]:null;var world=new PathConnectionFlagWorld{HasWorld=gate!="world",HasLevelHeader=gate!="header",LevelHeaderActive=gate!="inactive",GoodiesFlag=U(input,"good",0x80),BaddiesFlag=U(input,"bad",0x100)};
    world.Navigation.DefaultPath=B(input,"noPath",false)?null:path;world.Navigation.FlagDialect=I(input,"dialect",1);world.Navigation.BigJumpFlag=U(input,"bigJump",4);world.Navigation.RequiresPermissionFlag=U(input,"permission",0x1000000);world.Navigation.NoDestinationCheckFlag=U(input,"noDestination",0x4000000);
    bool result=PathConnectionFlagCommands.Set(world,Tokens(row["tokens"]),Convert.ToBoolean(row["first"]));for(int j=0;j<3;j++){int p=0x4000+j*0x40;Set(image,p,edges[j].ForwardFlags);Set(image,p+4,edges[j].ReverseFlags);}
    bool same=Equal(image,Image(row["after"])),ret=(result?1:0)==Convert.ToInt32(row["result"]);checks+=2;if(!same||!ret){failed++;if(errors.Count<10)errors.Add(new{input=input,tokens=row["tokens"],state=same,ret=ret});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{cases=count,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Path connection flag comparisons:"+count+", failures:"+failed);return failed==0?0:1;
 }
}
