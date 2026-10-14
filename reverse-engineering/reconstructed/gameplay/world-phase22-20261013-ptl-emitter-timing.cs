using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlEmitterTiming {
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  static float Float(uint word){return BitConverter.ToSingle(BitConverter.GetBytes(word),0);}
  struct N {
   PlaybackWide value;bool negative;bool Zero{get{return value.StoreDouble()==0;}}
   N(PlaybackWide v,bool sign){value=v;double d=v.StoreDouble();negative=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(Float(w)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Plus(N a,N b){return new N(PlaybackWide.Add(a.value,b.value),a.Zero&&b.Zero&&a.negative&&b.negative);}
   public static N Times(N a,N b){return new N(PlaybackWide.Multiply(a.value,b.value),a.negative!=b.negative);}
   public static N Divide(N a,N b){return new N(PlaybackWide.Divide(a.value,b.value),a.negative!=b.negative);}
   public static N Minus(N a,N b){return Plus(a,new N(PlaybackWide.Multiply(b.value,PlaybackWide.From(-1)),!b.negative));}
   public uint Store(){uint w=Bits(value.Store());if(Zero&&negative)w|=0x80000000;return w;}
   public int Convert(SoundSetupImage m){return m.Word(0x29a9c48)==0?value.TruncateInt32():PlaybackWide.FromDouble(value.StoreDouble()).TruncateInt32();}
  }
  static N Read(SoundSetupImage m,uint p){return N.Word(m.Word(p));}
  static N Random(SoundSetupImage m){uint state=m.Word(0x810900);float fraction=SoundPlayback.RandomFraction(ref state);m.Word(0x810900,state);return N.Word(Bits(fraction));}
  // 0x655c30: finite timing, original x87 precision/store order and supplied RNG state.
  // Runtime conversion mode0 uses the x87 helper; mode1 spills binary64 before CVTTSD2SI.
  // Both are qualified here to finite signed32 conversion results. Positive cycle period
  // and a terminating native float subtraction loop are required in the zero-spread branch.
  public static void Schedule(SoundSetupImage m,uint emitter,uint time){unchecked{
   N t=N.Word(time);int ticks=N.Times(t,N.Integer(60)).Convert(m);if(emitter==0)return;
   int physical=(short)m.Half(emitter+0x182);uint record=m.Word(m.Word(0x296209c)+(uint)physical*4);N clock=Read(m,m.Byte(record+0x2f1)==4?0x2962060u:0x296205cu);N start=clock;
   if(Float(m.Word(record+0x20))==0&&Float(m.Word(record+0x28))==0){
    N period=N.Word(N.Plus(Read(m,record+0x1c),Read(m,record+0x24)).Store());int cycles=N.Divide(clock,period).Convert(m);N boundary=N.Word(N.Times(N.Integer(cycles),period).Store());
    if(m.Byte(record+0x2c)==7&&Float(m.Word(record+0x24))==0){N tick=N.Word(N.Integer(ticks).Store());m.Half(emitter+0x1d0,(ushort)N.Times(tick,Read(m,record+0x50)).Convert(m));m.Half(emitter+0x1d2,(ushort)N.Times(tick,Read(m,record+0x54)).Convert(m));start=N.Plus(boundary,period);}
    else start=N.Plus(N.Plus(t,boundary),period);
    m.Word(emitter+0x1e0,start.Store());while(Float(m.Word(emitter+0x1e0))>Float(clock.Store()))m.Word(emitter+0x1e0,N.Minus(Read(m,emitter+0x1e0),period).Store());
   }else m.Word(emitter+0x1e0,start.Store());
   N random=Random(m);N noise=N.Times(random,Read(m,record+0x20));N value=N.Plus(N.Plus(Read(m,record+0x1c),Read(m,emitter+0x1e0)),noise);m.Word(emitter+0x1e4,value.Store());m.Word(emitter+0x1dc,0xc1200000);
  }}
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> fallback){if(address==0x655c30){Schedule(m,args[0],args[1]);return 0;}return fallback(m,address,args);}
 }
}
