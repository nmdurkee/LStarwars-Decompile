using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;
using System.Web.Script.Serialization;
using Recovered.Gameplay;
using Recovered.Animation;
public class GameplayPathAliasVerify
{
    static Dictionary<string,object> Obj(object v){return (Dictionary<string,object>)v;}
    static object[] Arr(object v){return (object[])v;}
    static int I(object v){return Convert.ToInt32(v);}
    static uint U(object v){return Convert.ToUInt32(v);}
    static int Opt(Dictionary<string,object> o,string k,int d){return o.ContainsKey(k)?I(o[k]):d;}
    static uint OptU(Dictionary<string,object> o,string k,uint d){return o.ContainsKey(k)?U(o[k]):d;}
    static float OptF(Dictionary<string,object> o,string k,float d){return o.ContainsKey(k)?Convert.ToSingle(o[k]):d;}
    static bool Flag(Dictionary<string,object> o,string k){return o.ContainsKey(k)&&Convert.ToBoolean(o[k]);}
    static float[] Floats(object v){object[] a=Arr(v);float[] b=new float[a.Length];for(int i=0;i<a.Length;i++)b[i]=Convert.ToSingle(a[i]);return b;}
    static readonly float[] Identity={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};
    static bool Equal(object a,object b)
    {
        if(a==null||b==null)return a==b;IDictionary ad=a as IDictionary,bd=b as IDictionary;if(ad!=null&&bd!=null){if(ad.Count!=bd.Count)return false;foreach(object k in ad.Keys)if(!bd.Contains(k)||!Equal(ad[k],bd[k]))return false;return true;}IList al=a as IList,bl=b as IList;if(al!=null&&bl!=null){if(al.Count!=bl.Count)return false;for(int i=0;i<al.Count;i++)if(!Equal(al[i],bl[i]))return false;return true;}if(a is string||b is string||a is bool||b is bool)return Object.Equals(a,b);return Convert.ToDecimal(a)==Convert.ToDecimal(b);
    }
    static void Put(ReinitializationRecord r,int offset,uint value,int size){for(int i=0;i<size;i++)r.Set8(offset+i,(int)(value>>(i*8)));}
    static List<object> Changes(byte[] before,byte[] after)
    {List<object> result=new List<object>();int i=0;while(i<before.Length){if(before[i]==after[i]){i++;continue;}int start=i;string hex="";while(i<before.Length&&before[i]!=after[i])hex+=after[i++].ToString("x2");result.Add(new object[]{start,hex});}return result;}
    const uint NodeBase=0x10101000,EdgeBase=0x10103000,Normal=0x10108000,Instance=0x10109000,Display=0x1010a000,Anim=0x1010b000;
    public static object Run(Dictionary<string,object> o,string kind,ushort[] table,float[] sine)
    {
        int index=Opt(o,"node",0),animated=Opt(o,"animated",0);string refKind=o.ContainsKey("kind")?(string)o["kind"]:"normal";float[] matrix=o.ContainsKey("matrix")?Floats(o["matrix"]):(float[])Identity.Clone();if(!o.ContainsKey("matrix"))matrix[12]=10;float[] fallback=o.ContainsKey("fallback")?Floats(o["fallback"]):(float[])Identity.Clone();
        PathSceneAnimation animation=new PathSceneAnimation{Matrix=new PathSceneMatrix{Identity=Anim,Values=matrix},Speed40=OptF(o,"speed",1),Flags50=OptU(o,"animationFlags",1)};
        PathSceneNormal normal=new PathSceneNormal{Matrix=new PathSceneMatrix{Identity=Instance,Values=animated==1?fallback:matrix},Animation=Opt(o,"normalAnimated",animated)==1?animation:null,Flags44=OptU(o,"normalFlags",OptU(o,"visible",1))};
        PathSceneDisplay display=new PathSceneDisplay{Matrix=new PathSceneMatrix{Identity=Display+0x40,Values=animated==1?fallback:matrix},Animation=Opt(o,"displayAnimated",animated)==1?animation:null,FlagsB8=OptU(o,"displayFlags",OptU(o,"visible",1)<<1)};
        PathSceneReference reference=new PathSceneReference{ScenePresent=!o.ContainsKey("scene")||Flag(o,"scene"),Normal=refKind=="normal"||refKind=="both"?normal:null,Display=refKind=="display"||refKind=="both"?display:null};
        CorridorPath path=new CorridorPath{ContextIdentity=0x12345678,Points=new ReinitializationRecord[4],Sine=sine};PathAttachmentWorld world=new PathAttachmentWorld{Path=path,AngleTable=table};List<object> events=new List<object>();
        if(o.ContainsKey("seen")){object[] seen=Arr(o["seen"]);for(int i=0;i<32;i++)path.RefreshedBits[i]=(byte)I(seen[i]);}
        object[] endpointRows=o.ContainsKey("edges")?Arr(o["edges"]):new object[]{new object[]{0,1},new object[]{2,0},new object[]{1,2}};ReinitializationRecord[] edges=new ReinitializationRecord[endpointRows.Length];
        for(int i=0;i<edges.Length;i++){object[] ends=Arr(endpointRows[i]);ReinitializationRecord e=new ReinitializationRecord(EdgeBase+(uint)(i*0x24),new byte[0x24]);e.Set32(0,OptU(o,"edgeFlags0",0x55));e.Set32(4,OptU(o,"edgeFlags1",0xaa));e.Set8(0x10,I(ends[0]));e.Set8(0x11,I(ends[1]));Put(e,0x12,1234,2);e.Set32(0x1c,PcObjectImage.ToBits(99));e.Set32(0x20,PcObjectImage.ToBits(OptF(o,"extra",1)));edges[i]=e;}
        float[][] positions={new float[]{0,0,0},new float[]{0,0,10},new float[]{5,0,0},new float[]{5,0,10}};float[] local=o.ContainsKey("local")?Floats(o["local"]):new float[]{1,2,3};
        for(int i=0;i<4;i++)
        {
            ReinitializationRecord p=new ReinitializationRecord(NodeBase+(uint)(i*0x5c),new byte[0x5c]);path.Points[i]=p;float[] pos=o.ContainsKey("positions")?Floats(Arr(o["positions"])[i]):positions[i];if(i==index&&Flag(o,"samePosition"))pos=SceneAnimationBounds.TransformPoint(matrix,local);for(int j=0;j<3;j++)p.Set32(4+j*4,PcObjectImage.ToBits(pos[j]));p.Set32(0x10,PcObjectImage.ToBits(o.ContainsKey("radii")?Convert.ToSingle(Arr(o["radii"])[i]):2));p.Set32(0x18,PcObjectImage.ToBits(-999));p.Set32(0x20,PcObjectImage.ToBits(999));p.Set32(0x1c,PcObjectImage.ToBits(OptF(o,"lowOffset",-1)));p.Set32(0x24,PcObjectImage.ToBits(OptF(o,"highOffset",1)));p.Set8(0x2a,i==index?Opt(o,"dynamic",1):0);p.Set8(0x2b,i==index?Opt(o,"flags",0):Opt(o,"otherFlags",0));List<ReinitializationRecord> adj=new List<ReinitializationRecord>();foreach(ReinitializationRecord e in edges)if(e.U8(0x10)==i||e.U8(0x11)==i)adj.Add(e);p.Set8(0x28,adj.Count);p.Set32(0x34,0x10104000+(uint)(i*0x100));world.Adjacency.Add(p.Identity,adj.ToArray());
            if(i==index){p.Set32(0x40,reference.ScenePresent?1u:0);p.Set32(0x44,reference.Normal==null?0:Normal);p.Set32(0x48,reference.Display==null?0:Display);for(int j=0;j<3;j++)p.Set32(0x4c+4*j,PcObjectImage.ToBits(local[j]));world.References.Add(p.Identity,reference);}
        }
        if(kind=="reference"){PathSceneMatrix transform=PathSceneBindings.Transform(reference);PathSceneAnimation selected=PathSceneBindings.Animation(reference);return new Dictionary<string,object>{{"visible",PathSceneBindings.Visible(reference)},{"matrix",transform==null?0u:transform.Identity},{"animation",selected==null?0u:selected.Matrix.Identity}};}
        if(Flag(o,"callback"))world.ResolveUnavailable=delegate(PathAttachmentWorld w,ReinitializationRecord p)
        {
            events.Add(new object[]{"resolve",w.Path.ContextIdentity,index});if(Flag(o,"repair")){p.Set32(0x40,1);p.Set32(0x44,Normal);p.Set32(0x48,0);reference.ScenePresent=true;reference.Normal=normal;reference.Display=null;}
            if(o.ContainsKey("effects"))foreach(object item in Arr(o["effects"])){Dictionary<string,object> e=Obj(item);Put(p,I(e["offset"]),U(e["value"]),Opt(e,"size",4));}return Flag(o,"resolve");
        };
        if(kind=="aliasRefresh")
        {
            Dictionary<string,object> aliasOptions=new Dictionary<string,object>{{"groups",o["aliasGroups"]},{"normalFlags",new object[]{0,0,0,0}},{"displayFlags",new object[]{2,2,2,2}}};
            PathAliasWorld aliases=Aliases(aliasOptions,Normal,Display);aliases.Normals[Normal]=normal;aliases.Displays[Display]=display;PathReferenceAliases.Attach(world,delegate{events.Add(new object[]{"resolve",world.Path.ContextIdentity,index});return aliases;});
        }
        byte[][] beforeNodes=new byte[4][],beforeEdges=new byte[edges.Length][];for(int i=0;i<4;i++)beforeNodes[i]=(byte[])path.Points[i].Bytes.Clone();for(int i=0;i<edges.Length;i++)beforeEdges[i]=(byte[])edges[i].Bytes.Clone();
        int result=0;byte[] hitBytes=new byte[32];for(int i=0;i<32;i++)hitBytes[i]=(byte)(i*17+3);ReinitializationRecord hit=new ReinitializationRecord(0x1010c100,hitBytes);
        if(kind=="corridor"){PathPointRefresh.Attach(world);float[] q=o.ContainsKey("query")?Floats(o["query"]):new float[]{11,2,3};result=PathCorridor.Contains(path,edges[0],new SpawnVector(q[0],q[1],q[2]),null,255,OptF(o,"margin",0),0,hit)?1:0;}else PathPointRefresh.Update(world,path.Points[index]);
        List<object> nc=new List<object>(),ec=new List<object>();for(int i=0;i<4;i++)nc.Add(Changes(beforeNodes[i],path.Points[i].Bytes));for(int i=0;i<edges.Length;i++)ec.Add(Changes(beforeEdges[i],edges[i].Bytes));object state=new Dictionary<string,object>{{"nodes",nc},{"edges",ec},{"seen",path.RefreshedBits},{"events",events}};return kind=="corridor"?new Dictionary<string,object>{{"result",result},{"state",state},{"hit",Changes(hitBytes,hit.Bytes)}}:state;
    }
    static PathAliasReference Reference(object value,uint normalBase,uint displayBase)
    {if(value==null)return null;object[] a=Arr(value);return new PathAliasReference(U(a[0]),I(a[1])==0?0:normalBase+(U(a[1])-1)*0x100,I(a[2])==0?0:displayBase+(U(a[2])-1)*0x100);}
    static object Logical(PathAliasReference r,uint normalBase,uint displayBase)
    {return r==null?null:new object[]{r.Scene,r.Normal==0?0:(r.Normal-normalBase)/0x100+1,r.Display==0?0:(r.Display-displayBase)/0x100+1};}
    static PathAliasWorld Aliases(Dictionary<string,object> o,uint normalBase,uint displayBase)
    {
        object[] groups=o.ContainsKey("groups")?Arr(o["groups"]):new object[0];PathAliasWorld w=new PathAliasWorld{Count=Opt(o,"count",groups.Length),Groups=Flag(o,"noGroups")?null:new PathAliasGroup[groups.Length]};
        for(int i=0;i<4;i++){w.Normals.Add(normalBase+(uint)(i*0x100),new PathSceneNormal{Flags44=o.ContainsKey("normalFlags")?U(Arr(o["normalFlags"])[i]):(uint)(i%2)});w.Displays.Add(displayBase+(uint)(i*0x100),new PathSceneDisplay{FlagsB8=o.ContainsKey("displayFlags")?U(Arr(o["displayFlags"])[i]):(uint)(i%2*2)});}
        if(w.Groups!=null)for(int i=0;i<groups.Length;i++){Dictionary<string,object> g=Obj(groups[i]);object[] rr=Arr(g["refs"]);PathAliasGroup group=new PathAliasGroup{Count=(short)Opt(g,"count",rr.Length),References=new PathAliasReference[rr.Length]};for(int j=0;j<rr.Length;j++)group.References[j]=Reference(rr[j],normalBase,displayBase);w.Groups[i]=group;}return w;
    }
    static object Direct(Dictionary<string,object> o,string kind)
    {
        const uint normalBase=0x10110000,displayBase=0x10120000;PathAliasReference r=Reference(o["ref"],normalBase,displayBase);
        if(kind=="valid")return PathReferenceAliases.Valid(r)?1:0;
        if(kind=="same")return PathReferenceAliases.Same(r,Reference(o["other"],normalBase,displayBase))?1:0;
        PathAliasWorld world=Aliases(o,normalBase,displayBase);bool result=kind=="callback"?PathReferenceAliases.GameResolve(delegate{return world;},r):PathReferenceAliases.Resolve(world,r);return new Dictionary<string,object>{{"result",result?1:0},{"ref",Logical(r,normalBase,displayBase)}};
    }
    public static int Main(string[] args)
    {
        if(args.Length!=4)throw new ArgumentException("fixture JSON, angle table u16, sine table f32, output JSON");JavaScriptSerializer json=new JavaScriptSerializer{MaxJsonLength=int.MaxValue};Dictionary<string,object> root=Obj(json.DeserializeObject(File.ReadAllText(args[0])));byte[] raw=File.ReadAllBytes(args[1]);ushort[] table=new ushort[513];for(int i=0;i<table.Length;i++)table[i]=BitConverter.ToUInt16(raw,2*i);byte[] sr=File.ReadAllBytes(args[2]);float[] sine=new float[32768];for(int i=0;i<sine.Length;i++)sine[i]=BitConverter.ToSingle(sr,i*4);int checks=0,mismatches=0,index=0;List<object> errors=new List<object>();
        foreach(object item in Arr(root["cases"]))try
        {
            Dictionary<string,object> c=Obj(item),o=Obj(c["options"]);string kind=(string)c["kind"];object got;
            if(kind=="refreshChain"){Dictionary<string,object> input=new Dictionary<string,object>(o);input["visible"]=0;input["displayFlags"]=2;got=Run(input,"aliasRefresh",table,sine);}else got=Direct(o,kind);
            checks++;if(!Equal(got,c["native"])){mismatches++;if(errors.Count<15)errors.Add(new{index,got,want=c["native"]});}index++;
        }
        catch(Exception e){mismatches++;if(errors.Count<15)errors.Add(new{index,error=e.ToString()});index++;}
        string result=json.Serialize(new{checks,mismatches,errors});File.WriteAllText(args[3],result);Console.WriteLine(result);return mismatches==0?0:1;
    }
}
