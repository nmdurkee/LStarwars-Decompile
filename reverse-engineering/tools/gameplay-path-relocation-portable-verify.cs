using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathRelocationVerify
{
    const uint A=0x10100000,Ref=0x10102000,Pad=0x10104000,Point=0x10105000;
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static uint U(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?Convert.ToUInt32(o[k]):d;}
    static float F(Dictionary<string,object> o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
    static bool B(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
    static float[] Floats(object v){object[] a=Arr(v);float[] b=new float[a.Length];for(int i=0;i<a.Length;i++)b[i]=Convert.ToSingle(a[i]);return b;}
    static float[] Values(Dictionary<string,object> o,string k,float[] d){return o.ContainsKey(k)?Floats(o[k]):d;}
    static byte[] Pattern(int count,int mult,int plus){byte[] b=new byte[count];for(int i=0;i<count;i++)b[i]=(byte)(i*mult+plus);return b;}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    sealed class Services:PathRelocationServices
    {
        public Dictionary<string,object> Options;public List<object> Events=new List<object>();
        public override void RefreshGround(PathRelocationWorld w,uint id,PcObjectImage actor){Events.Add(new object[]{"ground",id});actor.SetFloat(0x21c,F(Options,"groundHeight",2000000));}
        public override void ResetActor(PathRelocationWorld w,uint id,PcObjectImage actor,int mode){Events.Add(new object[]{"reset",id,mode});}
        public override int Alternate(PathRelocationWorld w,uint id,PcObjectImage actor,ReinitializationRecord point){Events.Add(new object[]{"alternate",id,point.Identity+4});return unchecked((int)U(Options,"alternateReturn",0));}
    }
    static object Run(Dictionary<string,object> o,string kind)
    {
        PcObjectImage actor=new PcObjectImage(Pattern(PcObjectImage.Size,37,11)),reference=new PcObjectImage(Pattern(PcObjectImage.Size,37,11));
        ReinitializationRecord pad=new ReinitializationRecord(Pad,Pattern(96,13,5)),point=new ReinitializationRecord(Point,new byte[0x5c]);
        actor.Set32(0x398,B(o,"aliasReference")?A:Ref);actor.Set32(0xca4,Pad);actor.Set32(0x1f8,U(o,"flags",0));actor.Set8(0x42e,(int)U(o,"pathFlags",1));actor.Set8(0x288,(int)U(o,"byte288",0));actor.Set8(0x7c5,(int)U(o,"byte7c5",0));actor.Set32(0xcd0,U(o,"companion",0));actor.Set8(0x6c4+0x75e,(int)U(o,"controlFlags",0));
        int[] offsets={0xf10,0x1e0,0x21c,0x17c,0xff0,0xa8,0x60};string[] keys={"delay","radius","floor","alternateHeight","bottom","scale","y"};float[] defaults={0,1,3,4,-.5f,1,5};for(int i=0;i<offsets.Length;i++)actor.SetFloat(offsets[i],F(o,keys[i],defaults[i]));
        uint pf=U(o,"padFlags",65535);pad.Set8(0x5a,(int)pf);pad.Set8(0x5b,(int)(pf>>8));float[] p=Values(o,"point",new float[]{0,0,20}),velocity=Values(o,"velocity",new float[]{0,0,0});for(int i=0;i<3;i++)point.Set32(4+i*4,PcObjectImage.ToBits(p[i]));
        Services services=new Services{Options=o};PathRelocationWorld world=new PathRelocationWorld{LevelFlags=U(o,"worldFlags",0),RandomState=U(o,"random",12345),Gate876ce4=F(o,"gate",1),Origin93d620=new uint[]{0x12345678,0xabcdef01,0xdeadbeef},Services=services};
        world.View=new LocatorView{ViewMatrix=Values(o,"view",new float[]{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}),PlaneMatrix=Values(o,"planes",new float[]{1,-1,0,0,0,0,1,-1,1,1,1,1,0,0,0,0}),Near=F(o,"near",1),Far=F(o,"far",10)};world.Actors.Add(A,actor);world.Actors.Add(Ref,reference);world.Records.Add(Pad,pad);for(int i=0;i<3;i++)world.Velocity93b0cc[i]=PcObjectImage.ToBits(velocity[i]);
        byte[] before=(byte[])actor.Bytes.Clone(),beforeRef=(byte[])reference.Bytes.Clone(),beforePad=(byte[])pad.Bytes.Clone();object result=null;
        if(kind=="reset")PathRelocation.ResetControls(world,actor);else if(kind=="floor")result=PathRelocation.SnapFloor(world,actor,U(o,"mode",0))?1:0;else result=PathRelocation.Relocate(world,A,point,U(o,"mode",0))?1:0;
        return new Dictionary<string,object>{{"result",result},{"actor",Changes(before,actor.Bytes)},{"reference",Changes(beforeRef,reference.Bytes)},{"pad",Changes(beforePad,pad.Bytes)},{"origin",world.Origin93d620},{"random",world.RandomState},{"events",services.Events}};
    }
    static bool Equal(object a,object b)
    {if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();
        foreach(object item in Arr(root["cases"]))try{Dictionary<string,object> c=Obj(item);object got=Run(Obj(c["options"]),(string)c["kind"]);checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;}catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}
        string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
