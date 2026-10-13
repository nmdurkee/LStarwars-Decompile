using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class ActorCollisionDimensions
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
  public static void HeightFactor(OriginPathMemory m,uint actor)
  {
   uint type=m.U32(actor+0x54);m.Set32(actor+0xff0,m.U32(type+0x34));float top=m.F32(type+0x38);m.SetFloat(actor+0xff4,top);float radius=m.F32(actor+0xffc);if(radius==0){m.SetFloat(actor+0x1004,0);return;}m.SetFloat(actor+0x1004,((N.From(top)-N.From(m.F32(actor+0xff0)))/(N.From(radius)+N.From(radius))).Store());
  }
  public static void Update(OriginPathMemory m,uint actor,Action<uint> callback)
  {
   bool special=false;uint data=0;
   if(m.U8(actor+0x1079)!=0&&m.F32(actor+0xd30)==1){data=m.U32(m.U32(actor+0x54)+0x24);int clip=unchecked((sbyte)m.U8(data+0x10d));if(clip!=-1&&m.U32(unchecked(m.U32(actor+0x50)+0x14+(uint)(clip*4)))!=0&&m.U8(actor+0x28c)!=0)special=true;}
   if(special){float value=(N.From(m.F32(data+0x4c))*N.From(m.F32(actor+0xff8))).Store();m.SetFloat(actor+0x1e0,value);m.SetFloat(actor+0x1dc,value);}else{m.Set32(actor+0x1dc,m.U32(actor+0xac));m.Set32(actor+0x1e0,m.U32(actor+0xb0));}if(callback!=null)callback(actor);
  }
 }
}
