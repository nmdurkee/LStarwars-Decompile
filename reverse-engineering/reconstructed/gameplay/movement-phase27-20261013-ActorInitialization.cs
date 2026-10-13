using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class ActorInitializationWorld
 {
  public OriginPathMemory Memory,AnimationMemory;
  public uint Registry,World,StartTable,AnimationPool,Emitter;
  public uint[] DefaultPosition;
  public ushort[] SpecialTypes;
  public float BoundPadding;
  public QRandom Random;
  public Action<uint> DimensionsUpdated;
  //Address, implicit actor register, actual explicit arguments. Unrecovered child services.
  public Func<uint,uint,uint[],uint> Service;
 }
 public static class ActorInitialization
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
  static uint Call(ActorInitializationWorld w,uint address,uint actor,params uint[]args){if(w.Service==null)throw new InvalidOperationException("Original child service required.");return w.Service(address,actor,args);}
  static ushort Word(OriginPathMemory m,uint p){return unchecked((ushort)m.U32(p));}
  static void SetWord(OriginPathMemory m,uint p,ushort v){m.Set8(p,v&255);m.Set8(p+1,v>>8);}
  public static uint Initialize(ActorInitializationWorld w,uint actor,int type,uint mode)
  {
   w.Emitter=0;if(type<0||type>=0x154)return 0;var m=w.Memory;uint map=m.U32(w.Registry+0x1c);if(Word(m,map+(uint)type*2)==0xffff)return 0;uint record=m.U32(w.Registry+0x20)+(uint)type*0x4c;m.Set32(actor+0x54,record);uint data=m.U32(record+0x24);m.Set32(actor+0x1048,m.U32(data+0xa0));m.Set32(actor+0x1f8,0);SetWord(m,actor+0x1070,0xffff);for(uint j=0;j<0x788;j++)m.Set8(actor+0x6c4+j,0);m.Set8(actor+0x280,255);
   uint position=ActorInitializationPrimitives.StartPointer(m,actor,w.StartTable),x=m.U32(position),y=m.U32(position+4),z=m.U32(position+8);m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|2);if(mode!=0)m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|0x4000);if((m.U32(m.U32(w.World+0x128)+0x64)&0x40000)==0)m.Set32(actor+0x1f8,m.U32(actor+0x1f8)|0x40);
   uint packet=ActorInitializationPrimitives.AllocateAnimation(w.AnimationMemory,w.AnimationPool);m.Set32(actor+0xca4,packet);w.AnimationMemory.Set8(packet+0x25,1);record=m.U32(actor+0x54);data=m.U32(record+0x24);byte state=m.U8(data+0xf4);m.Set8(actor+0x107e,state);m.Set8(actor+0x107f,state);Call(w,0x4148a0,actor,actor+0x6c4,record);
   m.Set32(actor+0x200,w.DefaultPosition[0]);m.Set32(actor+0x204,w.DefaultPosition[1]);m.Set32(actor+0x208,w.DefaultPosition[2]);data=m.U32(m.U32(actor+0x54)+0x24);m.Set8(actor+0xe38,m.U8(data+0xf5));m.Set8(actor+0xe39,4);SetWord(m,actor+0x1064,unchecked((ushort)type));map=m.U32(w.Registry+0x1c);int modelIndex=unchecked((short)Word(m,map+(uint)type*2));m.Set32(actor+0x50,unchecked(m.U32(w.Registry+0x18)+(uint)(modelIndex*0x54)));uint suit=Call(w,0x4cca00,actor,unchecked((uint)(short)type));m.Set32(actor+0xcbc,suit);m.Set8(actor+0x400,255);ActorInitializationPrimitives.InstallDimensions(m,actor);m.SetFloat(actor+0x100c,.5f);
   m.Set32(actor+0x8c,x);m.Set32(actor+0x5c,x);m.Set32(actor+0x98,x);m.Set32(actor+0x80,x);m.Set32(actor+0x90,y);m.Set32(actor+0x60,y);m.Set32(actor+0x9c,y);m.Set32(actor+0x84,y);m.Set32(actor+0x94,z);m.Set32(actor+0x64,z);m.Set32(actor+0xa0,z);m.Set32(actor+0x88,z);ActorCollisionDimensions.HeightFactor(m,actor);ActorCollisionDimensions.Update(m,actor,w.DimensionsUpdated);
   uint model=m.U32(actor+0x50);SetWord(m,actor+0x3e,1);if(model!=0){uint clips=m.U32(model+0xc);if(m.U32(clips+4)==0)for(uint j=0;j<0xe9;j++)if(m.U32(clips+j*4)!=0){SetWord(m,actor+0x3e,(ushort)j);break;}}
   Call(w,0x62e650,actor,actor+8,unchecked((uint)(short)Word(m,actor+0x3e)));uint moves=Call(w,0x415050,actor,actor);Call(w,0x4150d0,actor,actor,2,moves);Call(w,0x595840,actor,actor+0x5c,actor+0x4d8,m.U32(w.World+0x2ab4));m.SetFloat(actor+0x3e8,(N.From(m.F32(actor+0x1dc))+N.From(w.BoundPadding)).Store());Call(w,0x55d2b0,actor,actor);
   x=m.U32(actor+0x5c);y=m.U32(actor+0x60);z=m.U32(actor+0x64);m.Set32(actor+0x1b4,x);m.Set32(actor+0x10bc,x);m.Set32(actor+0x1b8,y);m.Set32(actor+0x1bc,z);m.Set32(actor+0x10c0,y);m.Set32(actor+0x10c4,z);data=m.U32(m.U32(actor+0x54)+0x24);uint flags=m.U32(actor+0xef4),value=m.U32(data+0x90)>>6;m.Set32(actor+0xef4,flags^((value^flags)&0x800));ushort actual=Word(m,actor+0x1064);
   if(actual==w.SpecialTypes[0])Call(w,0x41a9c0,actor);else if(actual==w.SpecialTypes[1])Call(w,0x41ab00,actor);else if(actual==w.SpecialTypes[2])Call(w,0x41ab90,actor);else if(actual==w.SpecialTypes[3])Call(w,0x41ac40,actor);else if(actual==w.SpecialTypes[4]){uint random=w.Random.Next();flags=m.U32(actor+0xef0);m.Set32(actor+0xef0,flags^(((random<0x8000?0x200u:0)^flags)&0x200));}ActorInitializationPrimitives.TypeFlag(m,actor);return 1;
  }
 }
}
