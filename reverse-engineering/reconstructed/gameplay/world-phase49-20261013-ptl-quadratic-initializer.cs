using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlQuadraticInitializer {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static uint Next(SoundSetupImage m){uint s=m.Word(0x810900);float r=SoundPlayback.RandomFraction(ref s);m.Word(0x810900,s);return Bits(r);}
  static uint RandomAxis(SoundSetupImage m,uint r,uint field,bool bias){N random=N.Word(Next(m));N doubled=N.Add(random,random);N scaled=N.Mul(doubled,N.Word(m.Word(r+field)));N value=N.Sub(scaled,N.Word(m.Word(r+field)));if(bias)value=N.Add(value,N.Word(m.Word(r+0x48)));return value.Store();}
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Node(SoundSetupImage m){return unchecked(m.Word(m.Word(0x2923198)+m.Word(0x2947b70)*4));}
  // 682290 complete quadratic-command initializer: cursor stays unchanged through root test/publication/callback, then advances once.
  public static uint Initialize(SoundSetupImage m,uint emitter,uint record,uint time,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   if((short)m.Half(emitter+0x18a)>=(short)m.Half(emitter+0x186))m.Half(emitter+0x18a,0);if(m.Byte(record+0x2e)==7)return 0;int cursor=(short)m.Half(emitter+0x18a);uint chunk=m.Word(emitter+0x100+(uint)(cursor/32)*4),p=chunk+(uint)(cursor%32+1)*32;m.Word(p+12,time);m.Word(emitter+0x324,time);uint lifetime=m.Word(record+0xa4);m.Word(p+28,(lifetime&0x7fffffff)==0?(lifetime&0x80000000)|0x7f800000u:N.Divide(N.Integer(64),N.Word(lifetime)).Store());
   uint[] point=PtlParticleMath.TransformWords(m,new uint[]{RandomAxis(m,record,0x58,false),RandomAxis(m,record,0x5c,false),RandomAxis(m,record,0x60,false)},emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+i*4,point[i]);
   point=PtlParticleMath.TransformWords(m,new uint[]{RandomAxis(m,record,0x4c,false),RandomAxis(m,record,0x50,true),RandomAxis(m,record,0x54,false)},emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+16+i*4,point[i]);
   uint displacement=N.Sub(N.Word(m.Word(p+4)),N.Word(m.Word(emitter+0x2e0))).Store();uint first,second;if(PtlQuadraticRoots.Values(m.Word(record+0xa0),m.Word(p+20),displacement,out first,out second)!=0){uint maximum=F(first)>=F(second)?first:second;if(F(maximum)>0&&F(maximum)<F(m.Word(record+0xa4))){PtlEmitterBurst.Acquire(m);int limit=(int)(m.Word(0x8108e8)+m.Word(0x8108ec));uint count=m.Word(0x2947b70);if((int)count<limit){uint initial=m.Word(m.Word(0x2923198)+count*4);m.Word(initial,chunk);m.Word(Node(m)+4,N.Add(N.Word(maximum),N.Word(time)).Store());m.Word(Node(m)+8,5);m.Word(Node(m)+12,0);m.Half(Node(m)+28,m.Half(emitter+0x182));m.Half(Node(m)+32,0);m.Half(Node(m)+30,0);m.Word(Node(m)+36,m.Word(emitter+0x2e0));m.Word(Node(m)+40,m.Word(emitter+0x2e4));m.Word(Node(m)+20,(uint)((short)m.Half(emitter+0x18a)%32));m.Word(Node(m)+24,maximum);PtlParticleLinks.Timed(m,Node(m),0x292fbfc);m.Word(0x2947b70,m.Word(0x2947b70)+1);}m.Word(0x2962058,0);}}
   uint callback=m.Word(emitter+0x1c4);if(callback!=0)service(m,callback,new uint[]{emitter,record,p});
   m.Half(emitter+0x18a,(ushort)(m.Half(emitter+0x18a)+1));for(uint i=0;i<3;i++)m.Word(p+i*4,N.Add(N.Word(m.Word(emitter+0x19c+i*4)),N.Word(m.Word(p+i*4))).Store());for(uint i=0;i<3;i++)m.Word(p+16+i*4,N.Add(N.Word(m.Word(emitter+0x1a8+i*4)),N.Word(m.Word(p+16+i*4))).Store());
   if(m.Word(record+0x2a8)==0)service(m,0x600260,new uint[]{record});return p;
  }}
 }
}
