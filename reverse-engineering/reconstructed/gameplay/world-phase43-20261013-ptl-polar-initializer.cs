using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlPolarInitializer {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=Bits(v.Store());return Zero&&neg?w|0x80000000:w;}
   public bool Positive{get{return v.StoreDouble()>0;}}
   public int IntegerPart(bool spill){PlaybackWide a=spill?PlaybackWide.FromDouble(v.StoreDouble()):v;try{return a.TruncateInt32();}catch(OverflowException){return int.MinValue;}}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static N Random(SoundSetupImage m){uint state=m.Word(0x810900);float f=SoundPlayback.RandomFraction(ref state);m.Word(0x810900,state);return N.Word(Bits(f));}
  static N Range(SoundSetupImage m,uint r,uint spread,uint bias){N random=Random(m);N value=N.Sub(N.Mul(N.Add(random,random),N.Word(m.Word(r+spread))),N.Word(m.Word(r+spread)));return N.Add(value,N.Word(m.Word(r+bias)));}
  static N Sin(SoundSetupImage m,int angle){return N.Word(m.Word(0x29899a0+(uint)((angle>>1)&32767)*4));}
  static N Cos(SoundSetupImage m,int angle){return Sin(m,unchecked(angle+16384));}
  // Value refinements of existing5b3690/5b3620 mappings for private in-place caller vectors; no new rotation entry credit.
  static uint[] Turn(SoundSetupImage m,uint radius,int azimuth,int elevation){N s=Sin(m,elevation),c=Cos(m,elevation),x=N.Word(0),y=N.Word(radius);uint first=N.Sub(N.Mul(c,x),N.Mul(s,y)).Store(),second=N.Add(N.Mul(x,s),N.Mul(c,y)).Store();s=Sin(m,azimuth);c=Cos(m,azimuth);x=N.Word(first);N z=N.Word(0);return new uint[]{N.Add(N.Mul(s,z),N.Mul(c,x)).Store(),second,N.Sub(N.Mul(z,c),N.Mul(x,s)).Store()};}
  static void Reset(SoundSetupImage m,uint e){if((short)m.Half(e+0x18a)>=(short)m.Half(e+0x186))m.Half(e+0x18a,0);}
  static uint Select32(SoundSetupImage m,uint e){unchecked{int cursor=(short)m.Half(e+0x18a);uint p=m.Word(e+0x100+(uint)(cursor/32)*4)+(uint)(cursor%32+1)*32;m.Half(e+0x18a,(ushort)(cursor+1));return p;}}
  // 653f40 complete polar initializer: stored drift plus physical coordinates, cached signed angles, then post-publication angle advances.
  public static uint Initialize(SoundSetupImage m,uint emitter,uint record,uint time,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   Reset(m,emitter);if(m.Byte(record+0x2e)==7)return 0;uint p=Select32(m,emitter);m.Word(p+12,time);m.Word(emitter+0x324,time);uint life=m.Word(record+0xa4);m.Word(p+28,(life&0x7fffffff)==0?(life&0x80000000)|0x7f800000u:N.Divide(N.Integer(64),N.Word(life)).Store());
   uint elapsed=N.Sub(N.Word(time),N.Word(m.Word(emitter+0x1e0))).Store();uint[] coordinates=PtlParticleMath.ScaleWords(m,record+0x64,elapsed);for(uint i=0;i<3;i++)coordinates[i]=N.Add(N.Word(coordinates[i]),N.Word(m.Word(record+0x58+i*4))).Store();int azimuth=N.Add(N.Word(coordinates[1]),N.Integer((short)m.Half(emitter+0x1d0))).IntegerPart(m.Word(0x29a9c48)!=0),elevation=N.Add(N.Word(coordinates[2]),N.Integer((short)m.Half(emitter+0x1d2))).IntegerPart(m.Word(0x29a9c48)!=0);uint radius=coordinates[0];
   uint[] point=PtlParticleMath.TransformWords(m,Turn(m,radius,azimuth,elevation),emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+i*4,point[i]);radius=Range(m,record,0x4c,0x48).Store();point=PtlParticleMath.TransformWords(m,Turn(m,radius,azimuth,elevation),emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+16+i*4,point[i]);uint callback=m.Word(emitter+0x1c4);if(callback!=0)service(m,callback,new uint[]{emitter,record,p});
   for(uint i=0;i<3;i++)m.Word(p+i*4,N.Add(N.Word(m.Word(emitter+0x19c+i*4)),N.Word(m.Word(p+i*4))).Store());for(uint i=0;i<3;i++)m.Word(p+16+i*4,N.Add(N.Word(m.Word(emitter+0x1a8+i*4)),N.Word(m.Word(p+16+i*4))).Store());
   if((sbyte)m.Byte(record+0x410)>0){int index=0;do{Reset(m,emitter);uint destination=Select32(m,emitter);for(uint i=0;i<32;i+=4)m.Word(destination+i,m.Word(p+i));index++;m.Word(destination+12,N.Add(N.Mul(N.Integer(index),N.Word(m.Word(record+0x414))),N.Word(m.Word(destination+12))).Store());}while(index<(sbyte)m.Byte(record+0x410));}
   if(m.Word(record+0x2a8)==0)service(m,0x600260,new uint[]{record});uint advance=m.Word(record+0x50);if((advance&0x7fffffff)==0)m.Half(emitter+0x1d0,0);else m.Half(emitter+0x1d0,(ushort)(m.Half(emitter+0x1d0)+N.Word(advance).IntegerPart(m.Word(0x29a9c48)!=0)));advance=m.Word(record+0x54);if((advance&0x7fffffff)==0)m.Half(emitter+0x1d2,0);else m.Half(emitter+0x1d2,(ushort)(m.Half(emitter+0x1d2)+N.Word(advance).IntegerPart(m.Word(0x29a9c48)!=0)));return p;
  }}
 }
}
