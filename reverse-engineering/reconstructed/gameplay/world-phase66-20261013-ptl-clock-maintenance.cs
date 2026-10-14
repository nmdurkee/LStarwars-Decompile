using System;using Recovered.Animation;namespace Recovered.Gameplay {public static class PtlClockMaintenance {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static bool Greater(N a,N b){return Sub(a,b).v.StoreDouble()>0;}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
public static void Tick(SoundSetupImage m){for(int bank=0;bank<2;bank++){uint clock=bank==0?0x296205cU:0x2962060U,backup=bank==0?0x2962064U:0x2962068U;N cachedBackup=N.Word(m.Word(backup)),current=N.Word(m.Word(clock));if(N.Greater(N.Sub(current,N.Integer(1)),cachedBackup))PtlTimeRebase.Rebase(m,bank);else if(N.Greater(current,N.Integer(900)))m.Word(backup,N.Sub(cachedBackup,N.Integer(800)).Store());}}}}
