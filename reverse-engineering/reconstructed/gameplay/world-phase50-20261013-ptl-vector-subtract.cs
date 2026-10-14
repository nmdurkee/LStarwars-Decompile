using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlVectorSubtract {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide value,bool sign){v=value;double d=value.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Sub(N a,N b){PlaybackWide opposite=PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1));return new N(PlaybackWide.Add(a.v,opposite),a.Zero&&b.Zero&&a.neg&&!b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  // 5b3800 complete sequential vector subtraction. Both source pointers are reread after earlier stores.
  public static void Subtract(SoundSetupImage m,uint destination,uint first,uint second){for(uint i=0;i<3;i++)m.Word(destination+i*4,N.Sub(N.Word(m.Word(first+i*4)),N.Word(m.Word(second+i*4))).Store());}
  // Private-stack array projection for recovered callers; no separate entry credit.
  public static uint[] Words(uint[] first,uint[] second){uint[] result=new uint[3];for(uint i=0;i<3;i++)result[i]=N.Sub(N.Word(first[i]),N.Word(second[i])).Store();return result;}
 }
}
