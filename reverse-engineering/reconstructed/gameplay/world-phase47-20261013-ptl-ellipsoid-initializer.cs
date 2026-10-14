using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlEllipsoidInitializer {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public int IntegerPart(bool spill){PlaybackWide a=spill?PlaybackWide.FromDouble(v.StoreDouble()):v;try{return a.TruncateInt32();}catch(OverflowException){return int.MinValue;}}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static N Sin(SoundSetupImage m,int a){return N.Word(m.Word(0x29899a0+(uint)((a>>1)&32767)*4));}
  static uint[] TurnX(SoundSetupImage m,uint radius,int yaw,int pitch){N x=N.Word(radius),s=Sin(m,pitch),c=Sin(m,unchecked(pitch+16384)),z=N.Word(0);uint a=N.Sub(N.Mul(c,x),N.Mul(s,z)).Store(),b=N.Add(N.Mul(x,s),N.Mul(c,z)).Store();x=N.Word(a);s=Sin(m,yaw);c=Sin(m,unchecked(yaw+16384));return new uint[]{N.Add(N.Mul(s,z),N.Mul(c,x)).Store(),b,N.Sub(N.Mul(z,c),N.Mul(x,s)).Store()};}
  // Private matrix-value projection of existing5c11d0; no additional address credit.
  static uint[] Transform(uint[] point,uint[] matrix){uint[] result=new uint[3];for(uint axis=1;axis<3;axis++){N sum=N.Add(N.Mul(N.Word(matrix[axis]),N.Word(point[0])),N.Mul(N.Word(matrix[4+axis]),N.Word(point[1])));sum=N.Add(sum,N.Mul(N.Word(matrix[8+axis]),N.Word(point[2])));result[axis]=N.Add(sum,N.Word(matrix[12+axis])).Store();}N x=N.Add(N.Mul(N.Word(matrix[4]),N.Word(point[1])),N.Mul(N.Word(point[0]),N.Word(matrix[0])));x=N.Add(x,N.Mul(N.Word(matrix[8]),N.Word(point[2])));result[0]=N.Add(x,N.Word(matrix[12])).Store();return result;}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static uint Next(SoundSetupImage m){uint s=m.Word(0x810900);float r=SoundPlayback.RandomFraction(ref s);m.Word(0x810900,s);return Bits(r);}
  static uint RandomAxis(SoundSetupImage m,uint r,uint field,bool bias){N random=N.Word(Next(m));N doubled=N.Add(random,random);N scaled=N.Mul(doubled,N.Word(m.Word(r+field)));N value=N.Sub(scaled,N.Word(m.Word(r+field)));if(bias)value=N.Add(value,N.Word(m.Word(r+0x48)));return value.Store();}
  static uint Select(SoundSetupImage m,uint e,uint r){unchecked{short cursor=(short)m.Half(e+0x18a);if(cursor>=(short)m.Half(e+0x186)){m.Half(e+0x18a,0);}cursor=(short)m.Half(e+0x18a);int unit=m.Byte(r+0x2e)==7?12:32;int bank=cursor/unit,within=cursor%unit;uint p=m.Word(e+0x100+(uint)bank*4)+(uint)(within+1)*32;m.Half(e+0x18a,(ushort)(m.Half(e+0x18a)+1));return p;}}
  // 681f70 complete ellipsoid sampler: square-root radius, uniform random yaw, inverse-sine pitch, template/physical-axis scaling and original frame paths.
  public static uint Initialize(SoundSetupImage m,uint emitter,uint record,uint time,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   uint p=Select(m,emitter,record);m.Word(p+12,time);m.Word(emitter+0x324,time);uint lifetime=m.Word(record+0xa4);m.Word(p+28,(lifetime&0x7fffffff)==0?(lifetime&0x80000000)|0x7f800000u:N.Divide(N.Integer(64),N.Word(lifetime)).Store());
   uint radial=Bits(BuildEffectSound.SquareRoot(F(Next(m))));int yaw=N.Mul(N.Word(Next(m)),N.Integer(65536)).IntegerPart(m.Word(0x29a9c48)!=0);N random=N.Word(Next(m));uint sampled=N.Sub(N.Add(random,random),N.Integer(1)).Store();int pitch=(short)PtlInverseAngle.FromSine(sampled,m.Word(0x29a9c48));uint[] point=TurnX(m,radial,yaw,pitch);uint[] matrix=new uint[16];for(uint i=0;i<16;i++)matrix[i]=m.Word(0x8065c0+i*4);matrix[0]=m.Word(record+0x58);matrix[5]=m.Word(record+0x5c);matrix[10]=m.Word(record+0x60);point=Transform(point,matrix);point=PtlParticleMath.TransformWords(m,point,emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+i*4,point[i]);
   uint[] velocity=new uint[]{RandomAxis(m,record,0x4c,false),RandomAxis(m,record,0x50,true),RandomAxis(m,record,0x54,false)};point=PtlParticleMath.TransformWords(m,velocity,emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+16+i*4,point[i]);uint callback=m.Word(emitter+0x1c4);if(callback!=0)service(m,callback,new uint[]{emitter,record,p});
   for(uint i=0;i<3;i++)m.Word(p+i*4,N.Add(N.Word(m.Word(emitter+0x19c+i*4)),N.Word(m.Word(p+i*4))).Store());for(uint i=0;i<3;i++)m.Word(p+16+i*4,N.Add(N.Word(m.Word(emitter+0x1a8+i*4)),N.Word(m.Word(p+16+i*4))).Store());
   if((sbyte)m.Byte(record+0x410)>0){int index=0;do{uint destination=Select(m,emitter,record);index++;for(uint i=0;i<32;i+=4)m.Word(destination+i,m.Word(p+i));N delay=N.Mul(N.Integer(index),N.Word(m.Word(record+0x414)));m.Word(destination+12,N.Add(delay,N.Word(m.Word(destination+12))).Store());}while(index<(sbyte)m.Byte(record+0x410));}
   if(m.Word(record+0x2a8)==0)service(m,0x600260,new uint[]{record});return p;
  }}
 }
}
