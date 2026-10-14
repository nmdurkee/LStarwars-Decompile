using System;using Recovered.Animation;namespace Recovered.Gameplay {public static class PtlRenderSupport {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide x,bool sign){v=x;double d=x.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(F(w)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Sub(N a,N b){return Add(a,new N(PlaybackWide.Multiply(b.v,PlaybackWide.FromDouble(-1)),!b.neg));}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);return Zero&&neg?w|0x80000000:w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
static uint Bits(float value){return BitConverter.ToUInt32(BitConverter.GetBytes(value),0);}public static void ScaleAxis(SoundSetupImage m,uint matrix,uint scale){N cached=N.Word(scale);for(uint i=0;i<3;i++)m.Word(matrix+i*4,N.Mul(N.Word(m.Word(matrix+i*4)),cached).Store());}public static void Modifier(SoundSetupImage m,uint pointer){m.Word(0x2854ce8,pointer);}public static uint Distance(SoundSetupImage m,uint point){uint reference=m.Word(0x2962080);if(reference==0)return 0;uint[] delta=new uint[3];for(uint i=0;i<3;i++)delta[i]=N.Sub(N.Word(m.Word(point+i*4)),N.Word(m.Word(reference+i*4))).Store();N x=N.Word(delta[0]),y=N.Word(delta[1]),z=N.Word(delta[2]);uint squared=N.Add(N.Add(N.Mul(x,x),N.Mul(y,y)),N.Mul(z,z)).Store();return Bits(BuildEffectSound.SquareRoot(F(squared)));}}}
