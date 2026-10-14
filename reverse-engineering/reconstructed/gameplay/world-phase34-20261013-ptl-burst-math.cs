using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlBurstMath {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide value,bool sign){v=value;double d=value.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public static N Div(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);if(Zero&&neg)w|=0x80000000;return w;}
  }
  //64fde0: either signed zero returns positivezero; otherwise finite64-bit divide with explicit binary32 spill/reload return.
  public static uint SafeDivide(uint numerator,uint denominator){if((numerator&0x7fffffff)==0||(denominator&0x7fffffff)==0)return 0;return N.Div(N.Word(numerator),N.Word(denominator)).Store();}
  //5b3860: destination=base+delta*scale. Scale is cached, component operands read before each ordered binary32 store.
  public static void ScaledAdd(SoundSetupImage m,uint destination,uint basis,uint delta,uint scale){unchecked{N s=N.Word(scale);for(uint i=0;i<3;i++){N d=N.Word(m.Word(delta+i*4)),b=N.Word(m.Word(basis+i*4));m.Word(destination+i*4,N.Add(N.Mul(d,s),b).Store());}}}
 }
}
