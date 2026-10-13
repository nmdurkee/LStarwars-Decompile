using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathTransitionVerify
{
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?I(o[k]):d;}
    static uint OptU(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?U(o[k]):d;}
    static float[] Floats(object v){object[] a=Arr(v);float[] b=new float[a.Length];for(int i=0;i<a.Length;i++)b[i]=Convert.ToSingle(a[i]);return b;}
    static uint PathId(int i){return i<0?0:0x10104000u+(uint)(i*0x100);}
    static bool Equal(object a,object b)
    {if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    static object Run(Dictionary<string,object> o,string kind)
    {
        PathTransitionWorld world=new PathTransitionWorld{Binding=new ActorReinitializationWorld()};byte[] bytes=new byte[PcObjectImage.Size];for(int i=0;i<bytes.Length;i++)bytes[i]=(byte)(i*37+11);PcObjectImage actor=new PcObjectImage(bytes),reference=new PcObjectImage(new byte[PcObjectImage.Size]);const int P=0x2c8;actor.Set32(P+0x158,PathId(0));actor.Set32(P+0x15c,0x10103000);actor.Set32(P+0x1cc,PathId(Opt(o,"target",3)));actor.Set32(P+0xd0,0x10102000);actor.Set32(P+0x130,OptU(o,"memberLow",1));actor.Set32(P+0x134,OptU(o,"memberHigh",0));float[] query=o.ContainsKey("query")?Floats(o["query"]):new float[]{1,0,1},position=o.ContainsKey("position")?Floats(o["position"]):new float[]{0,0,5};for(int i=0;i<3;i++){actor.SetFloat(P+0x1b4+4*i,query[i]);reference.SetFloat(0x5c+4*i,position[i]);}
        ReinitializationRecord edge=new ReinitializationRecord(0x10103000,new byte[0x24]);edge.Set8(0x10,o.ContainsKey("endpoints")?I(Arr(o["endpoints"])[0]):0);edge.Set8(0x11,o.ContainsKey("endpoints")?I(Arr(o["endpoints"])[1]):1);world.Connections.Add(edge.Identity,edge);
        for(int i=0;i<4;i++)
        {
            object[] candidates=o.ContainsKey("candidates")?Arr(Arr(o["candidates"])[i]):new object[]{0,1};TransitionPath path=new TransitionPath{Identity=PathId(i),Candidates=new byte[candidates.Length],GroupIndices=new short[candidates.Length],Points=new ReinitializationRecord[3]};world.Paths.Add(path.Identity,path);world.Binding.PathSets.Add(path.Identity,new ReinitializationPathSet{MembershipMasks=new ulong[]{1,2,0x100000000ul}});
            for(int j=0;j<candidates.Length;j++){path.Candidates[j]=(byte)I(candidates[j]);path.GroupIndices[j]=(short)(o.ContainsKey("groupIndices")?I(Arr(o["groupIndices"])[j%2]):j%2);}
            for(int j=0;j<3;j++)
            {
                ReinitializationRecord point=new ReinitializationRecord(0x10110000u+(uint)(i*0x1000+j*0x5c),new byte[0x5c]);path.Points[j]=point;float[] pos=o.ContainsKey("points")?Floats(Arr(Arr(o["points"])[i])[j]):new float[]{i*10+(j==2?2:0),0,j==0?0:j==1?10:5};for(int c=0;c<3;c++)point.Set32(4+c*4,PcObjectImage.ToBits(pos[c]));point.Set32(0x14,PcObjectImage.ToBits(i==0&&o.ContainsKey("scores")?Convert.ToSingle(Arr(o["scores"])[j]):0));point.Set8(0x30,i==0?(o.ContainsKey("links")?I(Arr(o["links"])[j]):j==2?255:j):0);
            }
        }
        Dictionary<string,object> groups=o.ContainsKey("groups")?Obj(o["groups"]):new Dictionary<string,object>{{"0",new object[]{1,2}},{"1",new object[]{2,1}}};foreach(KeyValuePair<string,object> row in groups){object[] ids=Arr(row.Value);uint[] members=new uint[ids.Length];for(int i=0;i<ids.Length;i++)members[i]=PathId(I(ids[i]));world.Groups.Add(Int16.Parse(row.Key),members);}
        if(kind=="nearest"){uint selected=OptU(o,"outPoint",0x12345678);float distance=PcObjectImage.FromBits(OptU(o,"outDistanceWord",0x42c80000));bool found=PathTransitions.Nearest(world.Paths[PathId(Opt(o,"path",1))],new SpawnVector(query[0],query[1],query[2]),ref selected,ref distance);return new object[]{found?1:0,selected,PcObjectImage.ToBits(distance)};}
        byte[] before=(byte[])actor.Bytes.Clone();bool result=PathTransitions.Select(world,actor,reference);return new Dictionary<string,object>{{"result",result?1:0},{"changes",Changes(before,actor.Bytes)}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2)throw new ArgumentException("fixture JSON, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();foreach(object item in Arr(root["cases"]))try{Dictionary<string,object> c=Obj(item);object got=Run(Obj(c["options"]),(string)c["kind"]);checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;}catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[1],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
