using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlLobedInitializer {
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
  // 6545d0 complete lobed initializer. Signed nonzero part count drives integer division and a stored sine-weighted radial profile.
  public static uint Initialize(SoundSetupImage m,uint emitter,uint record,uint time,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   Reset(m,emitter);if(m.Byte(record+0x2e)==7)return 0;uint p=Select32(m,emitter);m.Word(p+12,time);m.Word(emitter+0x324,time);uint life=m.Word(record+0xa4);m.Word(p+28,(life&0x7fffffff)==0?(life&0x80000000)|0x7f800000u:N.Divide(N.Integer(64),N.Word(life)).Store());
   int azimuth=Range(m,record,0x50,0x5c).IntegerPart(m.Word(0x29a9c48)!=0),elevation=Range(m,record,0x54,0x60).IntegerPart(m.Word(0x29a9c48)!=0);uint ramp=m.Word(record+0x418),radius=m.Word(record+0x58);if((ramp&0x7fffffff)!=0){N elapsed=N.Sub(N.Word(m.Word(0x296205c)),N.Word(m.Word(emitter+0x320)));if(N.Sub(N.Word(ramp),elapsed).Positive)radius=N.Mul(N.Divide(elapsed,N.Word(m.Word(record+0x418))),N.Word(m.Word(record+0x58))).Store();}
   int parts=(sbyte)m.Byte(record+0x411),step=65536/parts,remainder=(azimuth+65536)%step;uint fraction=N.Divide(N.Integer(remainder),N.Integer(step)).Store();int sample=N.Mul(N.Word(fraction),N.Integer(32768)).IntegerPart(m.Word(0x29a9c48)!=0);uint notch=N.Sub(N.Integer(1),Sin(m,sample)).Store();N weight=N.Add(N.Mul(N.Sub(N.Integer(1),N.Word(m.Word(record+0x41c))),N.Word(notch)),N.Word(m.Word(record+0x41c)));uint storedWeight=weight.Store();radius=N.Mul(N.Word(storedWeight),N.Word(radius)).Store();
   uint[] point=PtlParticleMath.TransformWords(m,Turn(m,radius,azimuth,elevation),emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+i*4,point[i]);radius=Range(m,record,0x4c,0x48).Store();point=PtlParticleMath.TransformWords(m,Turn(m,radius,azimuth,elevation),emitter+0x80);for(uint i=0;i<3;i++)m.Word(p+16+i*4,point[i]);uint callback=m.Word(emitter+0x1c4);if(callback!=0)service(m,callback,new uint[]{emitter,record,p});
   for(uint i=0;i<3;i++)m.Word(p+i*4,N.Add(N.Word(m.Word(emitter+0x19c+i*4)),N.Word(m.Word(p+i*4))).Store());for(uint i=0;i<3;i++)m.Word(p+16+i*4,N.Add(N.Word(m.Word(emitter+0x1a8+i*4)),N.Word(m.Word(p+16+i*4))).Store());
   if((sbyte)m.Byte(record+0x410)>0){int index=0;do{Reset(m,emitter);uint destination=Select32(m,emitter);for(uint i=0;i<32;i+=4)m.Word(destination+i,m.Word(p+i));index++;m.Word(destination+12,N.Add(N.Mul(N.Integer(index),N.Word(m.Word(record+0x414))),N.Word(m.Word(destination+12))).Store());}while(index<(sbyte)m.Byte(record+0x410));}
   if(m.Word(record+0x2a8)==0)service(m,0x600260,new uint[]{record});return p;
  }}
 }
}
