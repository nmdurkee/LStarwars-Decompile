using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class ActorInitializationPrimitives
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
  public static uint StartPointer(OriginPathMemory m,uint actor,uint table)
  {
   uint[]p=new uint[8];for(uint j=0;j<8;j++)p[j]=m.U32(table+j*16);return CharacterContexts.SelectStartPositionPointer(unchecked((sbyte)m.U8(actor+0x280)),m.U8(actor+0x28d),p);
  }
  public static uint AllocateAnimation(OriginPathMemory m,uint pool)
  {
   for(uint j=0;j<64;j++){uint p=pool+j*0x60;if((m.U8(p+0x5a)&1)==0){m.Set8(p+0x5a,m.U8(p+0x5a)|1);return p;}}return 0;
  }
  public static void Dimensions(OriginPathMemory m,uint actor)
  {
   uint type=m.U32(actor+0x54);m.SetFloat(actor+0xa4,(N.From(m.F32(type+0x2c))*N.From(m.F32(actor+0xa8))).Store());float radius=(N.From(m.F32(actor+0xffc))*N.From(m.F32(actor+0xa8))).Store();m.SetFloat(actor+0xac,radius);m.SetFloat(actor+0xb0,(N.From(radius)*N.From(m.F32(actor+0x1004))).Store());m.SetFloat(actor+0xb4,((N.From(m.F32(type+0x38))-N.From(m.F32(type+0x34)))*N.From(m.F32(actor+0xff8))).Store());
  }
  public static void InstallDimensions(OriginPathMemory m,uint actor)
  {
   uint type=m.U32(actor+0x54);m.Set32(actor+0xa8,m.U32(type+0x3c));m.Set32(actor+0xffc,m.U32(type+0x30));m.Set32(actor+0xff0,m.U32(type+0x34));m.Set32(actor+0xff4,m.U32(type+0x38));Dimensions(m,actor);
  }
  public static void TypeFlag(OriginPathMemory m,uint actor)
  {
   uint data=m.U32(m.U32(actor+0x54)+0x24);if((m.U32(data+0x90)&0x8000)!=0)m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|0x20000u);else m.Set32(actor+0x1f8,m.U32(actor+0x1f8)&0xfffdffffu);
  }
 }
}
