using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlEmitterEventRing {
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide value,bool sign){v=value;double d=value.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);if(Zero&&neg)w|=0x80000000;return w;}
  }
  static float F(uint w){return BitConverter.ToSingle(BitConverter.GetBytes(w),0);}
  static uint Row(SoundSetupImage m,uint e,uint field){return unchecked(e+(uint)(int)(short)m.Half(e+0x2c8)*28+field);}
  //656080 args: cue pointer,time bits,physical record,emitter pointer,raw latch flag.
  // Gate/countdown paths have ordinary unordered comparisons; event creation requires finite consumed arithmetic; zero signed rate retains masked x87 infinity/indefinite results.
  public static void Produce(SoundSetupImage m,uint cue,uint time,uint physical,uint emitter,uint latch){unchecked{
   if(!(F(m.Word(emitter+0x2cc))<=F(time)))return;short countdown=(short)m.Half(emitter+0x2ca);if(countdown>0){m.Half(emitter+0x2ca,(ushort)(countdown-1));return;}
   N t=N.Word(time);m.Word(Row(m,emitter,0x200),time);
   for(uint axis=0;axis<3;axis++){uint destination=Row(m,emitter,0x1e8+axis*4);N sum=N.Add(N.Word(m.Word(emitter+0x190+axis*4)),N.Word(m.Word(cue+axis*4)));m.Word(destination,sum.Store());}
   uint row=Row(m,emitter,0x1f4);for(uint i=0;i<3;i++)m.Word(row+i*4,m.Word(cue+0x10+i*4));
   m.Half(emitter+0x2c8,(ushort)(m.Half(emitter+0x2c8)+1));int count=(sbyte)m.Byte(physical+0x2f0);if((short)m.Half(emitter+0x2c8)>=count)m.Half(emitter+0x2c8,0);if(latch!=0)m.Half(emitter+0x2ca,m.Half(emitter+0x2c8));
   count=(sbyte)m.Byte(physical+0x2f0);uint lifetime=m.Word(physical+0xa4);if(count==0){m.Word(emitter+0x2cc,(lifetime&0x7fffffff)==0?0xffc00000u:(lifetime&0x80000000)|0x7f800000u);}else{N delay=N.Divide(N.Word(lifetime),N.Integer(count));m.Word(emitter+0x2cc,N.Add(t,delay).Store());}
  }}
 }
}
