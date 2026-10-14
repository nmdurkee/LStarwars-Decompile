using System;using Recovered.Animation;namespace Recovered.Gameplay {public static class PtlDescriptorEviction {
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
public static void SetStep(SoundSetupImage m,uint bits){m.Word(0x8108e4,bits);}public static void Evict(SoundSetupImage m){unchecked{int count=(int)m.Word(0x2962098);uint table=m.Word(0x296209c),first=m.Word(0x296205c),second=m.Word(0x2962060);int selected=0;float maximum=0;for(int i=1;i<count;i++){uint record=m.Word(table+(uint)i*4);if(record==0||m.Word(record+0x2a8)==0)continue;uint clock=m.Byte(record+0x2f1)==4?second:first;uint age=N.Sub(N.Word(clock),N.Word(m.Word(record+0x2ac))).Store();float value=F(age);if(value>maximum){maximum=value;selected=i;}}if(selected==0)return;uint live=m.Word(0x2924b44)-1;m.Word(0x2924b44,live);uint recordPointer=m.Word(table+(uint)selected*4),descriptor=m.Word(recordPointer+0x2a8);m.Word(m.Word(0x2962090)+live*4,descriptor);recordPointer=m.Word(m.Word(0x296209c)+(uint)selected*4);m.Word(recordPointer+0x2a8,0);}}}}
