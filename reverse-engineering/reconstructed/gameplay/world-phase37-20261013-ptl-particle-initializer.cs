using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlParticleInitializer {
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
  static uint Select(SoundSetupImage m,uint e,uint r){unchecked{short cursor=(short)m.Half(e+0x18a);if(cursor>=(short)m.Half(e+0x186)){m.Half(e+0x18a,0);}cursor=(short)m.Half(e+0x18a);int unit=m.Byte(r+0x2e)==7?12:32;int bank=cursor/unit,within=cursor%unit;uint p=m.Word(e+0x100+(uint)bank*4)+(uint)(within+1)*32;m.Half(e+0x18a,(ushort)(m.Half(e+0x18a)+1));return p;}}
  // 653970: default particle initializer. The selected attribute callback and descriptor producer remain mutable services.
  public static uint Initialize(SoundSetupImage m,uint emitter,uint record,uint time,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   uint p=Select(m,emitter,record);N t=N.Word(time);m.Word(p+12,time);m.Word(emitter+0x324,time);uint lifetime=m.Word(record+0xa4);m.Word(p+28,(lifetime&0x7fffffff)==0?(lifetime&0x80000000)|0x7f800000u:N.Divide(N.Integer(64),N.Word(lifetime)).Store());
   uint dt=N.Sub(t,N.Word(m.Word(emitter+0x1e0))).Store();uint[] drift=PtlParticleMath.ScaleWords(m,record+0x64,dt);uint[] random=new uint[3];for(uint i=0;i<3;i++)random[i]=RandomAxis(m,record,0x58+i*4,false);uint[] point=PtlParticleMath.TransformWords(m,random,emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+i*4,N.Add(N.Word(drift[i]),N.Word(point[i])).Store());
   random[0]=RandomAxis(m,record,0x4c,false);random[1]=RandomAxis(m,record,0x50,true);random[2]=RandomAxis(m,record,0x54,false);point=PtlParticleMath.TransformWords(m,random,emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+16+i*4,point[i]);uint callback=m.Word(emitter+0x1c4);if(callback!=0)service(m,callback,new uint[]{emitter,record,p});
   for(uint i=0;i<3;i++)m.Word(p+i*4,N.Add(N.Word(m.Word(emitter+0x19c+i*4)),N.Word(m.Word(p+i*4))).Store());for(uint i=0;i<3;i++)m.Word(p+16+i*4,N.Add(N.Word(m.Word(emitter+0x1a8+i*4)),N.Word(m.Word(p+16+i*4))).Store());
   if((sbyte)m.Byte(record+0x410)>0){int index=0;do{uint destination=Select(m,emitter,record);index++;for(uint i=0;i<32;i+=4)m.Word(destination+i,m.Word(p+i));N delay=N.Mul(N.Integer(index),N.Word(m.Word(record+0x414)));m.Word(destination+12,N.Add(delay,N.Word(m.Word(destination+12))).Store());}while(index<(sbyte)m.Byte(record+0x410));}
   if(m.Word(record+0x2a8)==0)service(m,0x600260,new uint[]{record});return p;
  }}
  // 654930: binary32 time forwarding wrapper, preserving the returned original particle pointer.
  public static uint Forward(SoundSetupImage m,uint emitter,uint record,uint time,Func<SoundSetupImage,uint,uint[],uint> service){return Initialize(m,emitter,record,time,service);}
 }
}
