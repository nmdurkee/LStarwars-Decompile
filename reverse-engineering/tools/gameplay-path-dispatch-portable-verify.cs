using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathDispatchVerify
{
    const uint A=0x10100000,P=A+0x2c8,REF=A+0x2000,EDGE=A+0x4000,PATH=A+0x4100,NODES=A+0x5000,ATTACH=A+0x6000,CHAR=A+0x7000,TUNING=A+0x7100,QUERY=0x12345678;
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static object Opt(Dictionary<string,object> o,string k,object d){return o.ContainsKey(k)?o[k]:d;}
    static bool Equal(object a,object b)
    {if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    sealed class Services:PathActionServices
    {
        public Dictionary<string,object> Options;public List<object> Events=new List<object>();
        public override int ChangeBaseState(PathActionWorld w,uint p,string name){Events.Add(new object[]{"state",p,name});return unchecked((int)U(Opt(Options,"stateReturn",0)));}
        public override int Relocate(PathActionWorld w,uint actor,ReinitializationRecord point,int mode){Events.Add(new object[]{"tail",actor,point.Identity,mode});return unchecked((int)U(Opt(Options,"tailReturn",0)));}
        public override int Invoke(uint entry,PathActionWorld w,PcObjectImage reference,uint query)
        {
            Events.Add(new object[]{"handler",entry,P,REF,query});Dictionary<string,object> m=Obj(Opt(Options,"mutation",new Dictionary<string,object>()));if(m.ContainsKey("flags"))w.Owner.Set32(0x2c8+0x1e8,U(m["flags"]));if(m.ContainsKey("actorFlags"))w.Owner.Set8(0x7c5,I(m["actorFlags"]));if(m.ContainsKey("gate"))w.Gate876ce4=Convert.ToSingle(m["gate"]);if(m.ContainsKey("direction"))w.Owner.Set8(0x2c8+0x160,I(m["direction"]));if(m.ContainsKey("requirements")){object[] a=Arr(m["requirements"]);w.Records[EDGE].Set32(0,U(a[0]));w.Records[EDGE].Set32(4,U(a[1]));}return unchecked((int)U(Opt(Options,"handlerReturn",0)));
        }
    }
    static PcObjectImage Pattern(){byte[] bytes=new byte[PcObjectImage.Size];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*37+11);return new PcObjectImage(bytes);}
    static object Run(string mode,Dictionary<string,object> o)
    {
        Services services=new Services{Options=o};PcObjectImage actor=Pattern(),reference=Pattern();PathActionWorld w=new PathActionWorld{OwnerIdentity=A,Owner=actor,Services=services,SpecialMask802278=U(Opt(o,"specialMask",0x240)),Gate876ce4=Convert.ToSingle(Opt(o,"gate",1))};w.Actors[A]=actor;actor.Set32(0x54,CHAR);actor.Set32(0xca4,ATTACH);actor.Set8(0x7b5,I(Opt(o,"state",0)));actor.Set8(0x7c5,I(Opt(o,"actorFlags",0)));actor.Set32(0xea4,U(Opt(o,"link",0)));actor.Set32(0x2c8+0x15c,EDGE);actor.Set32(0x2c8+0x158,PATH);actor.Set8(0x2c8+0x160,I(Opt(o,"direction",0)));actor.Set32(0x2c8+0x1f4,U(Opt(o,"capabilities",0xffffffffu)));actor.Set32(0x2c8+0x1e8,U(Opt(o,"flags",0)));reference.Set32(0,A);reference.Set32(4,P);reference.Set16(0x292,I(Opt(o,"referenceFlags",0x4321)));
        foreach(uint id in new uint[]{EDGE,ATTACH,CHAR,TUNING})w.Records.Add(id,new ReinitializationRecord(id,new byte[0x100]));object[] requirements=Arr(Opt(o,"requirements",new object[]{0,0})),ends=Arr(Opt(o,"endpoints",new object[]{2,5}));w.Records[EDGE].Set32(0,U(requirements[0]));w.Records[EDGE].Set32(4,U(requirements[1]));w.Records[EDGE].Set8(0x10,I(ends[0]));w.Records[EDGE].Set8(0x11,I(ends[1]));w.Records[CHAR].Set32(0x24,TUNING);w.Records[TUNING].Set8(0x90,I(Opt(o,"tuning",0)));w.Records[ATTACH].Set32(8,U(Opt(o,"attachment",0x1234)));w.Paths[PATH]=new ReinitializationRecord[256];for(int i=0;i<256;i++)w.Paths[PATH][i]=new ReinitializationRecord(NODES+(uint)(i*0x5c),new byte[0x5c]);byte[] oldActor=(byte[])actor.Bytes.Clone(),oldRef=(byte[])reference.Bytes.Clone();bool result=mode=="0x4078d0"?PathActionDispatch.Default(w,reference,QUERY):mode=="0x4813d0"?PathActionDispatch.Variant(w,reference,QUERY):PathActionDispatch.Alternate(w,reference,QUERY);return new Dictionary<string,object>{{"result",result?1:0},{"actor",Changes(oldActor,actor.Bytes)},{"reference",Changes(oldRef,reference.Bytes)},{"attachment",w.Records[ATTACH].U32(8)},{"events",services.Events}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();foreach(object item in Arr(root["cases"]))try{Dictionary<string,object> c=Obj(item);object got=Run((string)c["mode"],Obj(c["options"]));checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;}catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
