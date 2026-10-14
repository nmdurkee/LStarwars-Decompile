using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class PodFrameWorld
 {
  public OriginPathMemory Memory;
  public uint World,TimeState,SpecialGame,ProjectileGame;
  public int SpecialMode;
  public float Delta,LookAhead;
  public uint DisplacementW;
  public ushort ProjectileType;
  public float[] SineTable;
  public ushort[] AngleTable;
 }
 public static class PodFrameMotion
 {
  struct N
  {
   PlaybackWide v;bool neg;
   static N Make(PlaybackWide v,bool zero){double d=v.StoreDouble();return new N{v=v,neg=d<0||(d==0&&zero)};}
   public static N From(float f){return new N{v=PlaybackWide.From(f),neg=(PcObjectImage.ToBits(f)&0x80000000u)!=0};}
   public static N D(double f){return new N{v=PlaybackWide.FromDouble(f),neg=BitConverter.DoubleToInt64Bits(f)<0};}
   public static N operator+(N a,N b){return Make(PlaybackWide.Add(a.v,b.v),a.neg&&b.neg);}
   public static N operator-(N a){return Make(PlaybackWide.Multiply(a.v,PlaybackWide.From(-1)),!a.neg);}
   public static N operator-(N a,N b){return a+-b;}
   public static N operator*(N a,N b){return Make(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N operator/(N a,N b){return Make(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public float Store(){float f=v.Store();return f==0?PcObjectImage.FromBits(neg?0x80000000u:0):f;}
  }
  static void Difference(OriginPathMemory m,uint pod,out float[]d,out float square,out float dot)
  {
   d=new float[3];for(uint j=0;j<3;j++)d[j]=(N.From(m.F32(pod+0x50+j*4))-N.From(m.F32(pod+0x30+j*4))).Store();N x=N.From(d[0]),y=N.From(d[1]),z=N.From(d[2]);square=(y*y+x*x+z*z).Store();dot=(y*N.From(m.F32(pod+0x24))+x*N.From(m.F32(pod+0x20))+z*N.From(m.F32(pod+0x28))).Store();
  }
  public static void CommitPose(OriginPathMemory m,uint pod)
  {
   m.SetFloat(pod+0x3c,1);uint actor=m.U32(pod+0x90);if(actor==0)return;for(uint j=0;j<16;j++)m.Set32(actor+0xc04+j*4,m.U32(pod+j*4));actor=m.U32(pod+0x90);m.Set32(actor+0x5c,m.U32(actor+0xc34));m.Set32(actor+0x60,m.U32(actor+0xc38));m.Set32(actor+0x64,m.U32(actor+0xc3c));actor=m.U32(pod+0x90);for(uint j=0;j<3;j++)m.Set32(actor+0x10bc+j*4,m.U32(actor+0x5c+j*4));
  }
  // Whole guard, curve look-ahead, motion/heading and pose tail. Projectile
  // eligible worlds are excluded until their own inline creation branch is bound.
  public static uint UpdateWithoutProjectile(PodFrameWorld w,uint pod,uint scratch)
  {
   var m=w.Memory;if(m.U32(pod+0x80)==0)return 0;uint actor=m.U32(pod+0x90);if(actor==0||(m.U8(actor+0x1fc)&1)==0||m.U8(actor+0x28b)!=0){for(uint j=0;j<0xa0;j++)m.Set8(pod+j,0);return 0;}
   if(m.F32(w.TimeState+0xb000)>0){CommitPose(m,pod);return 1;}float[]d;float square,dot;Difference(m,pod,out d,out square,out dot);
   if(m.F32(pod+0x84)<=1)
   {
    int guard=0;while(square<1||dot<0){if(++guard>8192)throw new InvalidOperationException("Nonterminating look-ahead outside prepared domain.");float phase=(N.From(m.F32(pod+0x84))+N.From(w.LookAhead)).Store();m.SetFloat(pod+0x84,phase);if(phase>1){m.SetFloat(pod+0x84,1);break;}PodCurveEvaluation.Normalized(m,m.U32(pod+0x80),pod+0x50,phase);Difference(m,pod,out d,out square,out dot);}
   }
   float length=(float)Math.Sqrt(square);bool moved=false;
   if(m.F32(pod+0x84)<1)
   {
    if(length!=0)
    {
     float speed=m.F32(pod+0x7c),ratio=(N.From(m.F32(w.TimeState+0xb004))/N.From(m.F32(w.TimeState+0xb00c))).Store();if(ratio>1)ratio=1;N desired;
     if(m.U32(w.World+0x128)==w.SpecialGame&&w.SpecialMode==1){speed=(N.From(speed)/N.D((double).995f)).Store();if(ratio<.01f)desired=N.From(speed)*N.From(ratio)/N.D((double).01f);else desired=N.From(speed)*N.D(1.5)-(N.From(ratio)-N.D((double).01f))*N.From(speed);}
     else desired=N.From(speed)*N.D(1.5)-N.From(ratio)*N.From(speed);
     float target=desired.Store(),scale=(N.From(target)/N.From(length)).Store();for(uint j=0;j<3;j++)m.SetFloat(pod+0x40+j*4,(N.From(scale)*N.From(d[j])).Store());moved=true;
    }
   }
   else moved=true;
   if(moved)
   {
    for(uint j=0;j<3;j++)m.SetFloat(scratch+j*4,(N.From(w.Delta)*N.From(m.F32(pod+0x40+j*4))).Store());m.Set32(scratch+0xc,w.DisplacementW);for(uint j=0;j<3;j++)m.SetFloat(pod+0x30+j*4,(N.From(m.F32(pod+0x30+j*4))+N.From(m.F32(scratch+j*4))).Store());float factor=(N.From(length)/N.D(5)).Store();PodHeadingCommands.Apply(new PodHeadingWorld{Memory=m,SineTable=w.SineTable,AngleTable=w.AngleTable,Delta=w.Delta},pod,scratch,factor,0,scratch+0x40);for(uint j=0;j<4;j++)m.Set32(pod+0x60+j*4,m.U32(scratch+j*4));
   }
   if(m.U32(w.World+0x128)==w.ProjectileGame&&m.U32(pod+0x90)!=0&&(ushort)m.U32(pod+0x88)==w.ProjectileType)throw new InvalidOperationException("Inline projectile branch requires recovered binding.");CommitPose(m,pod);return 1;
  }
 }
}
