using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlInverseAngle {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Double(double d){return new N(PlaybackWide.FromDouble(d),d<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public bool Positive{get{return v.StoreDouble()>0;}}
   public uint Store(){uint w=Bits(v.Store());return Zero&&neg?w|0x80000000:w;}
   public int IntegerPart(bool spill){PlaybackWide a=spill?PlaybackWide.FromDouble(v.StoreDouble()):v;try{return a.TruncateInt32();}catch(OverflowException){return int.MinValue;}}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static N Clamp(N x){N one=N.Double(1);if(N.Sub(x,one).Positive)return one;if(N.Sub(N.Double(-1),x).Positive)return N.Double(-1);return x;}
  // 64fe20 complete320-byte inverse-angle approximation, ending in the original tail-JMP CRT conversion.
  // Literal multiply at64fe7e targets ST1; interpreting it as ST0 changes normalization completely.
  public static int FromSine(uint input,uint conversionSelector){
   N x=N.Word(input);uint squared=N.Sub(N.Double(1),N.Mul(x,x)).Store();uint root=Bits(BuildEffectSound.SquareRoot(F(squared))),absolute=input&0x7fffffff;uint minimum=F(absolute)>F(root)?root:absolute;
   N large=N.Double(3.402820018375656e38);N direction=N.Mul(N.Sub(N.Word(absolute),N.Double(0.7071067690849304)),large);uint branch=Clamp(direction).Store();uint sign=Clamp(N.Mul(large,x)).Store();N signedBranch=N.Mul(N.Word(sign),N.Word(branch)),a=N.Mul(N.Word(minimum),signedBranch),a2=N.Mul(a,a),a3=N.Mul(a2,a),a4=N.Mul(a2,a2);uint baseline=N.Add(signedBranch,N.Word(sign)).Store();N result=N.Add(N.Mul(N.Double(-1),a),N.Mul(N.Word(baseline),N.Double(0.785398006439209)));
   N term=N.Mul(N.Mul(a,N.Double(-0.16666699945926666)),a2);result=N.Add(result,term);term=N.Mul(N.Mul(N.Double(-0.07500000298023224),a2),a3);result=N.Add(result,term);term=N.Mul(N.Mul(a3,N.Double(-0.04464289918541908)),a4);result=N.Add(result,term);term=N.Mul(N.Mul(a4,N.Double(-0.03038189932703972)),N.Mul(a2,a3));result=N.Add(result,term);return N.Mul(result,N.Double(10430.400390625)).IntegerPart(conversionSelector!=0);
  }
 }
}
