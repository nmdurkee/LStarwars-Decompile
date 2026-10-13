using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Animation;
using Recovered.Gameplay;
public static class MovementPhase620261013Verify
{
 static Dictionary<string,object> M(object x){return(Dictionary<string,object>)x;}
 static int I(Dictionary<string,object> x,string k,int d){return x.ContainsKey(k)?Convert.ToInt32(x[k]):d;}
 static uint U(Dictionary<string,object> x,string k,uint d){return x.ContainsKey(k)?Convert.ToUInt32(x[k]):d;}
 static bool B(Dictionary<string,object> x,string k,bool d){return x.ContainsKey(k)?Convert.ToBoolean(x[k]):d;}
 static byte[] Bytes(string s){byte[] b=new byte[s.Length/2];for(int i=0;i<b.Length;i++)b[i]=Convert.ToByte(s.Substring(i*2,2),16);return b;}
 static string Hex(byte[] b){return BitConverter.ToString(b).Replace("-","").ToLowerInvariant();}
 static string[] Tokens(object o){object[] a=(object[])o;string[] r=new string[a.Length];for(int i=0;i<a.Length;i++)r[i]=(string)a[i];return r;}
 sealed class ObservedLocators:LocatorWorld
 {
  public List<object> Events;
  public override LocatorRecord Find(string name){Events.Add(new object[]{"lookup",name});return base.Find(name);}
 }
 public static int Main(string[] args)
 {
  if(args.Length!=2)throw new ArgumentException("Fixture/output paths required.");var json=new JavaScriptSerializer{MaxJsonLength=Int32.MaxValue};Dictionary<string,object> data;
  using(var s=File.OpenRead(args[0]))using(var z=new GZipStream(s,CompressionMode.Decompress))using(var r=new StreamReader(z))data=M(json.DeserializeObject(r.ReadToEnd()));
  int actions=0,rngCases=0,checks=0,failed=0;var errors=new List<object>();
  foreach(object v in(object[])data["rngVectors"])
  {
   var row=M(v);rngCases++;try{var random=new LocatorIntegerRandom();uint seed=Convert.ToUInt32(row["seed"]);random.Global.State=seed;var local=new LocatorIntegerState{State=seed};bool useLocal=Convert.ToBoolean(row["local"]);uint result=random.Next(useLocal?local:null);uint state=useLocal?local.State:random.Global.State;checks+=2;if(result!=Convert.ToUInt32(row["result"])||state!=Convert.ToUInt32(row["state"])){failed++;if(errors.Count<10)errors.Add(new{kind="rng",input=row,result=result,state=state});}}catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind="rng",error=e.Message});}
  }
  foreach(object v in(object[])data["vectors"])
  {
   var row=M(v);var input=M(row["input"]);actions++;try
   {
    object[] before=(object[])row["before"];var actors=new PcObjectImage[]{new PcObjectImage(Bytes((string)before[0])),new PcObjectImage(Bytes((string)before[1]))};var events=new List<object>();var world=new DoomedLocatorWorld(new ObservedLocators{Events=events});world.Random.Global.State=U(input,"seed",123);
    foreach(object rr in(object[])data["records"]){var r=M(rr);world.Locators.Locators.Add(new LocatorRecord{Name=(string)r["name"]});}
    world.LocatorAddress=delegate(LocatorRecord record){return 0x10110000u+(uint)world.Locators.Locators.IndexOf(record)*0x3c;};
    world.CharacterName=delegate(uint definition){return definition==0x10102000?"Hero":"Other";};
    if(B(input,"characterCallback",true))world.ResolveCharacter=delegate(string name){events.Add(new object[]{"character",name});return name=="Self"?(I(input,"gate",3)==2?null:actors[0]):name=="Other"?actors[1]:null;};
    var packet=new ScriptPacket{Script=new ScriptDefinition()};packet.Script.ParameterNames[0]="factor";packet.Parameters[0]=.5f;packet.Parameters[1]=2;packet.Parameters[2]=-1;packet.Parameters[3]=7;
    DoomedLocatorActions.Set(world,packet,I(input,"gate",3)==3?actors[0]:null,Tokens(row["tokens"]),Convert.ToBoolean(row["first"]));object[] after=(object[])row["after"];
    bool first=Hex(actors[0].Bytes)==(string)after[0],second=Hex(actors[1].Bytes)==(string)after[1],seed=world.Random.Global.State==Convert.ToUInt32(row["seed"]),order=json.Serialize(events)==json.Serialize(row["events"]);checks+=4;
    if(!first||!second||!seed||!order){failed++;if(errors.Count<10)errors.Add(new{kind="action",input=input,first=first,second=second,seed=seed,order=order,events=events});}
   }catch(Exception e){failed++;if(errors.Count<10)errors.Add(new{kind="action",input=input,error=e.Message});}
  }
  File.WriteAllText(args[1],json.Serialize(new{actionCases=actions,rngCases=rngCases,assertionGroups=checks,failures=failed,examples=errors}));Console.WriteLine("Doomed locator/RNG comparisons:"+(actions+rngCases)+", failures:"+failed);return failed==0?0:1;
 }
}
