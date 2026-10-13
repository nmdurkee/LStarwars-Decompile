using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class PodCreationWorld
 {
  public OriginPathMemory Memory;
  public uint Race,Pacemaker;
  public uint[] MatrixTemplate;
  public float[] SineTable;
  public ushort[] AngleTable;
  public float Delta,LookAhead;
  public ScriptPacket Numbers;
  public Func<string,uint> Definition;
  public Func<ushort,uint> ActorType;
  //Original actor creator receives (signed type, spline, 0,0,0,0,1,0,0,0,0).
  public Func<int,uint,uint> CreateActor;
 }
 public static class PodCreationCommands
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator-(N a){return Make(PlaybackWide.Multiply(a.v,PlaybackWide.From(-1)),!a.neg);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N operator/(N a,N b){return Make(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static float Add(float a,float b){return(N.From(a)+N.From(b)).Store();}
  static float Sub(float a,float b){return(N.From(a)-N.From(b)).Store();}
  static float Mul(float a,float b){return(N.From(a)*N.From(b)).Store();}
  static float Number(PodCreationWorld w,uint context,string text)
  {
   if(context==0)return MessageNumbers.Resolve(null,text);
   if(w.Numbers!=null)for(int j=0;j<4;j++)w.Numbers.Parameters[j]=w.Memory.F32(context+0x14+(uint)j*4);
   return MessageNumbers.Resolve(w.Numbers,text);
  }
  public static bool Create(PodCreationWorld w,uint numericContext,string[]tokens,bool first,uint scratch)
  {
   if(!first||tokens==null||tokens.Length==0)return true;
   var m=w.Memory;float start=0,end=1,timeFactor=1;uint id=UInt32.MaxValue;ushort type=UInt16.MaxValue;bool pacemaker=false,damaged=false;
   for(int j=0;j<tokens.Length;j++)
   {
    string t=tokens[j];MessageNumbers.RequireAscii(t);int at;
    if((at=t.IndexOf("spline_id=",StringComparison.OrdinalIgnoreCase))>=0)id=unchecked((uint)PlaybackWide.From(Number(w,numericContext,t.Substring(at+10))).TruncateInt32());
    else if((at=t.IndexOf("type=",StringComparison.OrdinalIgnoreCase))>=0){if(w.Definition!=null&&w.ActorType!=null){type=(byte)w.Definition(t.Substring(at+5));if(type!=255)type=unchecked((ushort)w.ActorType(type));}}
    else if((at=t.IndexOf("spline_start=",StringComparison.OrdinalIgnoreCase))>=0)start=Number(w,numericContext,t.Substring(at+13));
    else if((at=t.IndexOf("spline_end=",StringComparison.OrdinalIgnoreCase))>=0)end=Number(w,numericContext,t.Substring(at+11));
    else if((at=t.IndexOf("time_factor=",StringComparison.OrdinalIgnoreCase))>=0)timeFactor=Number(w,numericContext,t.Substring(at+12));
    else if(String.Equals(t,"pacemaker",StringComparison.OrdinalIgnoreCase))pacemaker=true;
    else if(String.Equals(t,"damaged",StringComparison.OrdinalIgnoreCase))damaged=true;
   }
   if(id>31||type==UInt16.MaxValue)return true;uint race=w.Race,spline=race;
   for(uint j=0;j<32;j++){spline=unchecked(race+j*0x530);if(m.U32(spline+0x524)==id)break;}
   if(start<0)start=0;else if(start>1)start=1;if(end<0)end=0;else if(end>1)end=1;
   if(spline==0||m.U32(spline+0x400)==0||start==end)return true;uint pod=PodMemoryHelpers.FindFree(m,w.Race);if(pod==0)return true;
   m.SetFloat(pod+0x84,start);m.Set32(pod+0x88,(m.U32(pod+0x88)&0xffff0000u)|type);m.Set32(pod+0x94,1);m.Set32(pod+0x80,spline);
   PlaybackWide time=PlaybackWide.Multiply(PlaybackWide.From(m.F32(race+0xb00c)),PlaybackWide.From(timeFactor));float rate=1;
   if(time.StoreDouble()>0)rate=(N.From(Sub(end,start))*N.From(m.F32(spline+0x410))/(N.From(m.F32(race+0xb00c))*N.From(timeFactor))).Store();m.SetFloat(pod+0x7c,rate);
   PodCurveEvaluation.Distance(m,spline,scratch,Mul(start,m.F32(spline+0x410)));PodCurveEvaluation.Distance(m,spline,scratch+0x10,((N.From(w.LookAhead)+N.From(start))*N.From(m.F32(spline+0x410))).Store());
   if(w.MatrixTemplate==null||w.MatrixTemplate.Length!=16)throw new ArgumentException("Runtime matrix template requires 16 words.");for(uint j=0;j<16;j++)m.Set32(scratch+0x40+j*4,w.MatrixTemplate[j]);PodMemoryHelpers.CopyFloatMatrix(m,scratch+0x40,pod);
   for(uint j=0;j<4;j++)m.Set32(pod+0x30+j*4,m.U32(scratch+j*4));for(uint j=0;j<3;j++)m.SetFloat(scratch+0x20+j*4,Sub(m.F32(scratch+0x10+j*4),m.F32(scratch+j*4)));
   PodHeadingCommands.Apply(new PodHeadingWorld{Memory=m,SineTable=w.SineTable,AngleTable=w.AngleTable,Delta=w.Delta},pod,scratch+0x20,1,0,scratch+0x80);
   for(uint j=0;j<3;j++)m.Set32(pod+0x40+j*4,0);m.SetFloat(pod+0x4c,1);for(uint j=0;j<4;j++)m.Set32(pod+0x50+j*4,m.U32(scratch+j*4));m.SetFloat(pod+0x8c,start);
   if(w.CreateActor==null)throw new InvalidOperationException("Original actor creation service required.");uint actor=w.CreateActor(unchecked((short)m.U32(pod+0x88)),spline);m.Set32(pod+0x90,actor);
   if(actor!=0){m.Set32(actor+0xef4,m.U32(actor+0xef4)|0x4000000u);m.Set8(m.U32(pod+0x90)+0x107a,5);if(pacemaker){actor=m.U32(pod+0x90);m.Set32(actor+0xef4,m.U32(actor+0xef4)|0x20u);w.Pacemaker=actor;}if(damaged){actor=m.U32(pod+0x90);m.Set32(actor+0xef4,m.U32(actor+0xef4)|0x8000000u);}}
   return true;
  }
 }
}
