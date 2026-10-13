using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathSteeringVerify
{
    const uint D=0x10100000,A=D+0x90000,P=A+0x2c8,REF=D+0x92000,QUERY=D+0x94000,PATH=D,NODES=D+0x10000,EDGES=D+0x20000,CTX=0x12345678;
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static object Opt(Dictionary<string,object> o,string k,object d){return o.ContainsKey(k)?o[k]:d;}
    static object N(Dictionary<string,object> o,string k,int i,object d){return o.ContainsKey(k)?Arr(o[k])[i]:d;}
    static float F(object v){return Convert.ToSingle(v);}
    static uint Bits(object v){return PcObjectImage.ToBits(F(v));}
    static uint Eid(int i){return i<0?0:EDGES+(uint)(i*0x24);}
    static bool Equal(object a,object b)
    {if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    static PcObjectImage Pattern(){byte[] b=new byte[PcObjectImage.Size];for(int i=0;i<b.Length;i++)b[i]=(byte)(i*37+11);return new PcObjectImage(b);}
    static void S16(ReinitializationRecord r,int off,int v){r.Set8(off,v);r.Set8(off+1,v>>8);}
    static void Vec(PcObjectImage a,int off,object v){object[] p=Arr(v);for(int j=0;j<3;j++)a.SetFloat(off+j*4,F(p[j]));}
    static byte[][] Base(){return new byte[][]{new byte[]{255,0,0,0},new byte[]{0,255,1,1},new byte[]{0,0,255,1},new byte[]{0,0,0,255}};}
    static object Run(Dictionary<string,object> o,float[] sine,ushort[] angles)
    {
        PcObjectImage actor=Pattern(),reference=Pattern();ActorPathBindingWorld binding=new ActorPathBindingWorld{Sine=sine};PathSteeringWorld w=new PathSteeringWorld{ContextIdentity=CTX,OwnerIdentity=A,Owner=actor,Binding=binding,AngleTable=angles};w.References[REF]=reference;List<object> events=new List<object>();w.Transition=delegate(PathSteeringWorld x){events.Add(new object[]{"transition",CTX,P});};if(Convert.ToBoolean(Opt(o,"callback",false)))w.Special=delegate(PathSteeringWorld x,PcObjectImage refer,uint query){events.Add(new object[]{"special",P,REF,query});if(o.ContainsKey("callbackFlags"))actor.Set32(0x2c8+0x1e8,U(o["callbackFlags"]));return unchecked((int)U(Opt(o,"callbackReturn",0)));};
        ReinitializationRecord[] points=new ReinitializationRecord[5];CorridorPath corridor=new CorridorPath{ContextIdentity=CTX,Points=points,Marker78=7,RefreshedBits=new byte[32],Sine=sine};for(int i=0;i<32;i++)corridor.RefreshedBits[i]=255;RoutingPath routing=new RoutingPath{Points=new RoutingPoint[4],BaseNextSlots=Base(),Groups=new RoutingGroup[2]};for(int i=0;i<2;i++)routing.Groups[i]=new RoutingGroup{PointCount=4,PointMap=new byte[]{0,1,2,3},Exits=new byte[0],NextSlots=Base()};if(o.ContainsKey("base")){object[] rows=Arr(o["base"]);for(int i=0;i<4;i++){object[] row=Arr(rows[i]);for(int j=0;j<4;j++)routing.BaseNextSlots[i][j]=(byte)I(row[j]);}}
        int[][] adjacency={new int[]{0},new int[]{0,1},new int[]{1,2},new int[]{2},new int[0]};TargetingPath targeting=new TargetingPath{Identity=PATH,PointCount=(byte)I(Opt(o,"pointCount",4)),CandidateCount=0,Points=points,PointConnections=new uint[5][]};w.Paths.Add(PATH,new SteeringPath{Identity=PATH,Targeting=targeting,Corridor=corridor,Routing=routing});binding.Paths.Add(PATH,new ActorPathSet{RouteCount=2,Points=points});object[] positions=Arr(Opt(o,"positions",new object[]{new object[]{0,0,0},new object[]{0,0,10},new object[]{10,0,10},new object[]{10,0,20},new object[]{100,0,100}}));
        for(int i=0;i<5;i++)
        {
            ReinitializationRecord p=new ReinitializationRecord(NODES+(uint)(i*0x5c),new byte[0x5c]);points[i]=p;object[] pos=Arr(positions[i]);for(int j=0;j<3;j++)p.Set32(4+j*4,Bits(pos[j]));p.Set32(0x10,Bits(N(o,"radii",i,2)));object[] height=Arr(N(o,"heights",i,new object[]{(double)F(pos[1])-2,(double)F(pos[1])+2}));p.Set32(0x18,Bits(height[0]));p.Set32(0x20,Bits(height[1]));p.Set8(0x2a,I(N(o,"dynamic",i,0)));targeting.PointConnections[i]=new uint[adjacency[i].Length];for(int j=0;j<adjacency[i].Length;j++)targeting.PointConnections[i][j]=Eid(adjacency[i][j]);p.Set8(0x28,adjacency[i].Length);
            if(i<4){S16(p,0x58,I(N(o,"members",i,3)));S16(p,0x5a,I(N(o,"boundaries",i,0)));p.Set8(0x2e,255);p.Set8(0x2f,255);p.Set32(0x38,Bits(10.25+i));p.Set32(0x3c,Bits(20.5+i));routing.Points[i]=new RoutingPoint{Adjacency=targeting.PointConnections[i]};}
        }
        ReinitializationRecord[] edges=new ReinitializationRecord[3];
        for(int i=0;i<3;i++)
        {
            bool reverse=Convert.ToBoolean(N(o,"reversed",i,false));ReinitializationRecord e=new ReinitializationRecord(Eid(i),new byte[0x24]);edges[i]=e;binding.Connections[e.Identity]=e;object[] required=Arr(N(o,"requirements",i,new object[]{0,0}));e.Set32(0,U(required[0]));e.Set32(4,U(required[1]));e.Set8(0x10,i+(reverse?1:0));e.Set8(0x11,i+(reverse?0:1));S16(e,0x12,I(N(o,"angles",i,i==1?16384:0))+(reverse?32768:0));S16(e,0x14,I(N(o,"masks",i,3)));e.Set32(0x18,Bits(N(o,"distances",i,10)));e.Set32(0x1c,Bits(N(o,"lengths",i,10)));e.Set8(0x17,3);RoutingConnection v=new RoutingConnection{Identity=e.Identity,Endpoint0=e.U8(0x10),Endpoint1=e.U8(0x11),RouteMask=(ushort)I(N(o,"masks",i,3)),Distance=e.F32(0x18)};routing.Connections[e.Identity]=v;targeting.Connections[e.Identity]=v;
        }
        object position=Opt(o,"position",new object[]{0,0,2}),target=Opt(o,"target",new object[]{10,0,18}),queryPosition=Opt(o,"query",position);Vec(reference,0x5c,position);reference.Set16(0x27e,I(Opt(o,"attachmentSlot",65535)));reference.SetFloat(0xac,F(Opt(o,"bodyRadius",.5)));actor.Set32(0x2c8+0xd0,REF);actor.Set32(0x2c8+0x158,PATH);actor.Set32(0x2c8+0x15c,Eid(I(Opt(o,"current",0))));actor.Set32(0x2c8+0x1cc,Convert.ToBoolean(Opt(o,"newTarget",false))?0:PATH);actor.Set32(0x2c8+0x1d0,Eid(I(Opt(o,"targetEdge",2))));actor.Set32(0x2c8+0x190,0);actor.Set32(0x2c8+0x194,0);actor.Set32(0x2c8+0x17c,0);
        actor.Set8(0x2c8+0x160,I(Opt(o,"direction",0)));actor.Set16(0x2c8+0x166,I(Opt(o,"stateFlags",5)));actor.Set8(0x2c8+0x13c,I(Opt(o,"route",255)));actor.Set8(0x2c8+0x13d,I(Opt(o,"cursor",0)));actor.Set16(0x2c8+0x13a,I(Opt(o,"membership",3)));actor.Set8(0x2c8+0x142,0);actor.Set8(0x2c8+0x143,255);actor.Set32(0x2c8+0x1f4,U(Opt(o,"permission",0xffffffffu)));actor.Set32(0x2c8+0x1e8,U(Opt(o,"flags",0)));actor.Set32(0x2c8+0x1ec,U(Opt(o,"targetFlags",0)));actor.SetFloat(0x2c8+0x168,F(Opt(o,"progress",.2)));actor.SetFloat(0x2c8+0x1dc,F(Opt(o,"targetProgress",.8)));actor.SetFloat(0x2c8+0x1c0,F(Opt(o,"acceptedRadius",0)));actor.SetFloat(0x2c8+0x1c4,F(Opt(o,"targetRadius",0)));Vec(actor,0x2c8+0x1b4,target);Vec(actor,0x2c8+0x14c,queryPosition);
        byte[] oldActor=(byte[])actor.Bytes.Clone(),oldRef=(byte[])reference.Bytes.Clone();byte[][] oldPoints=new byte[5][],oldEdges=new byte[3][];for(int i=0;i<5;i++)oldPoints[i]=(byte[])points[i].Bytes.Clone();for(int i=0;i<3;i++)oldEdges[i]=(byte[])edges[i].Bytes.Clone();PathSteering.Update(w,reference,QUERY);object[] pd=new object[5],ed=new object[3];for(int i=0;i<5;i++)pd[i]=Changes(oldPoints[i],points[i].Bytes);for(int i=0;i<3;i++)ed[i]=Changes(oldEdges[i],edges[i].Bytes);return new Dictionary<string,object>{{"actor",Changes(oldActor,actor.Bytes)},{"reference",Changes(oldRef,reference.Bytes)},{"nodes",pd},{"edges",ed},{"events",events}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=4)throw new ArgumentException("fixture JSON, sine f32, angle u16, output JSON");byte[] raw=File.ReadAllBytes(args[1]);if(raw.Length!=32768*4)throw new ArgumentException("sine table length");float[] sine=new float[32768];Buffer.BlockCopy(raw,0,sine,0,raw.Length);raw=File.ReadAllBytes(args[2]);if(raw.Length!=513*2)throw new ArgumentException("angle table length");ushort[] angles=new ushort[513];Buffer.BlockCopy(raw,0,angles,0,raw.Length);JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();foreach(object item in Arr(root["cases"]))try{Dictionary<string,object> c=Obj(item);object got=Run(Obj(c["options"]),sine,angles);checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;}catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}string output=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[3],output);Console.WriteLine(output);return mismatches==0?0:1;
    }
}
