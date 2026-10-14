using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlParticleDescriptor {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Double(double d){return new N(PlaybackWide.FromDouble(d),d<0);}
   public static N Integer(int i){return Double(i);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public N SpillDouble(){return new N(PlaybackWide.FromDouble(v.StoreDouble()),neg);}
   public uint Store(){uint w=Bits(v.Store());return Zero&&neg?w|0x80000000:w;}
   public int IntegerPart(){try{return v.TruncateInt32();}catch(OverflowException){return int.MinValue;}}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static uint LowInteger64(uint w){double f=F(w);if(double.IsNaN(f)||double.IsInfinity(f)||f< -9223372036854775808.0||f>=9223372036854775808.0)return 0;return unchecked((uint)(long)f);}
  static N Sine(SoundSetupImage m,N angle){if(m.Word(0x29a9c48)!=0)angle=angle.SpillDouble();int index=(angle.IntegerPart()>>1)&32767;return N.Word(m.Word(0x29899a0+(uint)index*4));}
  static uint Curve(SoundSetupImage m,uint record,uint field,uint time){for(uint i=0;i<7;i++){uint at=record+field+i*8,a=m.Word(at),b=m.Word(at+8);if(F(a)<=F(time)&&F(time)<=F(b)){uint delta=N.Sub(N.Word(time),N.Word(a)).Store();if((delta&0x7fffffff)==0)return m.Word(at+4);uint length=N.Sub(N.Word(b),N.Word(a)).Store();N fraction=N.Divide(N.Word(delta),N.Word(length));N difference=N.Sub(N.Word(m.Word(at+12)),N.Word(m.Word(at+4)));return N.Add(N.Mul(difference,fraction),N.Word(m.Word(at+4))).Store();}}return 0;}
  // 600260: complete descriptor allocation/header and original 64 sampled geometry/color rows.
  // Failure tail-call5f74a0 remains explicit. Literal cells and sine table have authenticated original backing.
  public static void Produce(SoundSetupImage m,uint record,Func<SoundSetupImage,uint,uint[],uint> service){unchecked{
   if(m.Word(record+0x2a8)==0){uint count=m.Word(0x2924b44);if((int)count>=(int)m.Word(0x8108fc)){service(m,0x5f74a0,new uint[0]);return;}m.Word(record+0x2a8,m.Word(m.Word(0x2962090)+count*4));m.Word(0x2924b44,m.Word(0x2924b44)+1);}
   uint destination=m.Word(record+0x2a8);m.Word(destination+16,m.Word(record+0xa0));for(uint i=0;i<4;i++)m.Word(destination+40+i*4,N.Mul(N.Integer((int)(LowInteger64(m.Word(record+0x298+i*4))&511)),N.Double(0.003921568859368563)).Store());
   for(int index=0;index<64;index++){
    uint time=N.Mul(N.Integer(index),N.Double(0.015625)).Store();uint width=Curve(m,record,0x150,time),height=Curve(m,record,0x190,time),angle=Curve(m,record,0x1d8,time);
    N phase=N.Mul(N.Mul(N.Word(time),N.Word(m.Word(record+0xb0))),N.Integer(65536));uint oscillationX=N.Mul(Sine(m,phase),N.Word(m.Word(record+0xb4))).Store();phase=N.Mul(N.Mul(N.Word(time),N.Word(m.Word(record+0xb8))),N.Integer(65536));uint oscillationY=N.Mul(Sine(m,phase),N.Word(m.Word(record+0xbc))).Store();destination=m.Word(record+0x2a8)+0x4c+(uint)index*40;
    uint rotation=N.Sub(N.Word(angle),N.Integer(16384)).Store();N sineC=Sine(m,N.Add(N.Integer(16384),N.Word(rotation))),sineD=Sine(m,N.Word(rotation));N halfWidth=N.Mul(N.Word(width),N.Double(0.25)),halfHeight=N.Mul(N.Word(height),N.Double(0.25));N cWidth=N.Mul(sineC,halfWidth),dHeight=N.Mul(sineD,halfHeight),dHeightDouble=dHeight.SpillDouble();
    uint firstY=N.Sub(N.Word(oscillationY),N.Add(dHeight,cWidth)).Store();N cHeight=N.Mul(halfHeight,sineC),dWidth=N.Mul(sineD,halfWidth);uint firstX=N.Sub(N.Word(oscillationX),N.Add(dWidth,cHeight)).Store();uint otherY=N.Add(N.Sub(dHeightDouble,cWidth),N.Word(oscillationY)).Store();N newHalf=N.Mul(N.Word(width),N.Double(0.5));uint newD=N.Mul(sineD,newHalf).Store(),newC=N.Mul(newHalf,sineC).Store();uint otherX=N.Add(N.Sub(cHeight,dWidth),N.Word(oscillationX)).Store();N factor=N.Double(0.00048828125);
    m.Word(destination,N.Mul(N.Word(otherX),factor).Store());m.Word(destination+4,N.Mul(N.Word(firstY),factor).Store());m.Word(destination+8,0);m.Word(destination+12,N.Mul(N.Word(firstX),factor).Store());m.Word(destination+16,N.Mul(N.Word(otherY),factor).Store());m.Word(destination+20,0);m.Word(destination+24,N.Mul(N.Add(N.Word(firstX),N.Word(newD)),factor).Store());m.Word(destination+28,N.Mul(N.Add(N.Word(otherY),N.Word(newC)),factor).Store());m.Word(destination+32,0);
    uint[] color=new uint[3];for(uint i=0;i<7;i++){uint at=record+0xc0+i*8,a=m.Word(at),b=m.Word(at+8);if(F(a)<=F(time)&&F(time)<=F(b)){uint length=N.Sub(N.Word(b),N.Word(a)).Store(),delta=N.Sub(N.Word(time),N.Word(a)).Store();if((delta&0x7fffffff)==0){for(uint j=0;j<3;j++)color[j]=Bits(m.Byte(at+4+j));}else{N fraction=N.Divide(N.Word(delta),N.Word(length));for(uint j=0;j<3;j++){int start=m.Byte(at+4+j),difference=m.Byte(at+12+j)-start;color[j]=N.Add(N.Mul(N.Integer(difference),fraction),N.Integer(start)).Store();}}break;}}
    uint alpha=Curve(m,record,0x100,time);alpha=N.Add(N.Word(alpha),N.Word(alpha)).Store();if(F(alpha)>=255)alpha=Bits(255);uint packed=LowInteger64(alpha)<<8;packed=(packed|LowInteger64(color[0]))<<8;packed=(packed|LowInteger64(color[1]))<<8;packed|=LowInteger64(color[2]);m.Word(destination+36,packed);
   }
  }}
 }
}
