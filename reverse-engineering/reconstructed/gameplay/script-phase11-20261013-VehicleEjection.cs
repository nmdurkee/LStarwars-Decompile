// Original ejection5a01f0 with exact stored-F32 boundaries and shared x87 arithmetic.
// Internal PlaybackWide is compiled with the reconstructed runtime, not a new mapped function.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class VehicleEjection
 {
  static uint Bits(float f){return TakeoverReleaseMemory.Bits(f);}
  static float From(uint bits){return BitConverter.ToSingle(BitConverter.GetBytes(bits),0);}
  static float Finite(float f){if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentOutOfRangeException("finite ejection stored arithmetic");return f;}
  static double Double(TakeoverReleaseMemory m,uint p){ulong bits=m.Read32(p)|((ulong)m.Read32(p+4)<<32);return BitConverter.Int64BitsToDouble(unchecked((long)bits));}
  static uint Draw(TakeoverReleaseMemory m){QRandom rng=new QRandom{State=m.Read32(0x80253c)};uint value=rng.Next();m.Write32(0x80253c,value);return value;}
  static float Multiply(float a,float b)
  {Finite(a);Finite(b);if(a==0||b==0)return From((Bits(a)^Bits(b))&0x80000000);return Finite(PlaybackWide.Multiply(PlaybackWide.From(a),PlaybackWide.From(b)).Store());}
  static float Add(float a,float b)
  {Finite(a);Finite(b);if(a==0&&b==0)return From((Bits(a)&Bits(b))&0x80000000);return Finite(PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(b)).Store());}
  static float Subtract(float a,float b)
  {return Add(a,From(Bits(b)^0x80000000));}
  static float Speed(TakeoverReleaseMemory m,uint speedDraw)
  {PlaybackWide speedWide=PlaybackWide.FromDouble(speedDraw);speedWide=PlaybackWide.Multiply(speedWide,PlaybackWide.FromDouble(Double(m,0x751700)));speedWide=PlaybackWide.Multiply(speedWide,PlaybackWide.FromDouble(Double(m,0x7586e8)));return Finite(PlaybackWide.Add(speedWide,PlaybackWide.FromDouble(Double(m,0x7531a8))).Store());}
  // 5a01f0. Terminal audio is the only callback boundary; original context is phase10.
  public static void Eject(TakeoverReleaseMemory m,JumpContextAudio audio,uint rider,uint vehicle)
  {
   uint angle=Draw(m),speedDraw=Draw(m);float speed=Speed(m,speedDraw);
   uint xIndex=angle>>1,zIndex=((angle+0x4000)>>1)&0x7fff;
   m.Write32(rider+0x68,Bits(Multiply(m.Float(0x29899a0+xIndex*4),speed)));
   m.Write32(rider+0x70,Bits(Multiply(speed,m.Float(0x29899a0+zIndex*4))));
   JumpContextProducer.Enter(m,audio,rider,0);
   m.Write8(rider+0x7c5,(byte)(m.Read8(rider+0x7c5)|1));m.Write32(rider+0x68,0);
   uint input=m.Read32(rider+0xca4);m.Write32(rider+0x70,0);m.Write32(rider+0xd1c,vehicle);m.Write32(input+4,0);m.Write32(m.Read32(rider+0xca4)+8,0);
   float top=Finite(m.Float(vehicle+0x194));uint definition=m.Read32(vehicle+0x54),vehicleType=m.Read32(definition+0x24);
   if((m.Read32(vehicleType+0x94)&0x20000)!=0)top=Add(Finite(m.Float(0x805714)),top);
   definition=m.Read32(rider+0x54);float delta=Subtract(top,Finite(m.Float(rider+0x1a0)));uint riderType=m.Read32(definition+0x24);
   delta=Finite(PlaybackWide.Add(PlaybackWide.From(delta),PlaybackWide.FromDouble(Double(m,0x751788))).Store());
   if(m.Float(riderType+0x34)<delta)
   {
    float gravity=Finite(m.Float(riderType+0x24));double scale=Double(m,0x7598e8);float argument;
    if(gravity==0||delta==0){uint sign=(Bits(gravity)^Bits(delta)^(BitConverter.DoubleToInt64Bits(scale)<0?0x80000000u:0))&0x80000000;argument=From(sign);}
    else argument=Finite(PlaybackWide.Multiply(PlaybackWide.Multiply(PlaybackWide.From(gravity),PlaybackWide.FromDouble(scale)),PlaybackWide.From(delta)).Store());
    m.Write32(rider+0x6c,Bits(BuildEffectSound.SquareRoot(argument)));
   }
  }
 }
}
