// Original5ffee0 with exact65536-biased6e6b90 qword truncation, then low DWORD subtraction.
// Live REA ev_1b04e019bde4a542c42c8a92707c2ae9615554ed2f5c12a599c1d972487654fe. Finite nonzero-period prepared arithmetic; signed-zero/alias order retained.
using System;using Recovered.Animation;namespace Recovered.Gameplay {public static class PtlScreenWrap {
  struct N {
   public PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
internal static uint TruncateQwordLow(PlaybackWide value){try{PlaybackWide unit=PlaybackWide.FromDouble(4294967296.0);int high=PlaybackWide.Divide(value,unit).TruncateInt32();PlaybackWide remain=PlaybackWide.Add(value,PlaybackWide.Multiply(PlaybackWide.Multiply(PlaybackWide.FromDouble(high),unit),PlaybackWide.FromDouble(-1)));if(high==Int32.MinValue&&remain.StoreDouble()<0)return 0;PlaybackWide shortUnit=PlaybackWide.FromDouble(65536);int shortHigh=PlaybackWide.Divide(remain,shortUnit).TruncateInt32();PlaybackWide shortRemain=PlaybackWide.Add(remain,PlaybackWide.Multiply(PlaybackWide.Multiply(PlaybackWide.FromDouble(shortHigh),shortUnit),PlaybackWide.FromDouble(-1)));return unchecked((uint)(shortHigh*65536+shortRemain.TruncateInt32()));}catch(OverflowException){return 0;}}public static void Wrap(SoundSetupImage m,uint point){unchecked{N origin=N.Word(m.Word(0x96d9c4)),period=N.Word(m.Word(0x9715a4));uint[] normalized=new uint[3];normalized[0]=N.Divide(N.Sub(N.Word(m.Word(point)),origin),period).Store();for(uint i=1;i<3;i++)normalized[i]=N.Divide(N.Sub(N.Word(m.Word(point+i*4)),N.Word(m.Word(0x96d9c4+i*4))),N.Word(m.Word(0x9715a4+i*4))).Store();uint[] wrapped=new uint[3];for(uint i=0;i<3;i++){N value=N.Word(normalized[i]);uint rounded=TruncateQwordLow(N.Add(value,N.Integer(65536)).v);int shift=(int)(rounded-65536);wrapped[i]=N.Sub(value,N.Integer(shift)).Store();}m.Word(point,N.Add(N.Mul(N.Word(wrapped[0]),period),origin).Store());for(uint i=1;i<3;i++)m.Word(point+i*4,N.Add(N.Mul(N.Word(m.Word(0x9715a4+i*4)),N.Word(wrapped[i])),N.Word(m.Word(0x96d9c4+i*4))).Store());}}}}
