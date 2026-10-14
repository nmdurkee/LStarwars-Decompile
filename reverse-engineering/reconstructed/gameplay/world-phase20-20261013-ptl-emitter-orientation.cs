using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlEmitterOrientation {
  const uint Sine=0x29899a0,Template=0x8065c0,Emitters=0x29620a4;
  static uint Bits(float f){return BitConverter.ToUInt32(BitConverter.GetBytes(f),0);}
  struct N {
   PlaybackWide value;bool negative;
   bool Zero{get{return value.StoreDouble()==0;}}
   N(PlaybackWide wide,bool sign){value=wide;double stored=wide.StoreDouble();negative=stored<0||(stored==0&&sign);}
   public static N Word(uint word){float f=BitConverter.ToSingle(BitConverter.GetBytes(word),0);return new N(PlaybackWide.From(f),(word&0x80000000)!=0);}
   public static N Plus(N a,N b){return new N(PlaybackWide.Add(a.value,b.value),a.Zero&&b.Zero&&a.negative&&b.negative);}
   public static N Times(N a,N b){return new N(PlaybackWide.Multiply(a.value,b.value),a.negative!=b.negative);}
   public static N Minus(N a,N b){return Plus(a,new N(PlaybackWide.Multiply(b.value,PlaybackWide.From(-1.0f)),!b.negative));}
   public uint Store(){uint word=Bits(value.Store());if(Zero&&negative)word|=0x80000000;return word;}
  }
  static N Load(SoundSetupImage m,uint p){return N.Word(m.Word(p));}
  static void Store(SoundSetupImage m,uint p,N v){m.Word(p,v.Store());}
  // 0x64ff80: ordered16binary32 loads/stores, including shifted-overlap propagation; signaling-NaN behavior remains outside the portable projection.
  public static void Copy(SoundSetupImage m,uint destination,uint source){for(uint i=0;i<64;i+=4)m.Word(destination+i,m.Word(source+i));}
  static void Rotate(SoundSetupImage m,uint matrix,int angle,int axis){unchecked{
   N c=Load(m,Sine+(((uint)(angle+0x4000)>>1)&0x7fff)*4),s=Load(m,Sine+(((uint)angle>>1)&0x7fff)*4);
   uint a=axis==0?4u:0u,b=axis==2?4u:8u;N[] first=new N[4];for(uint r=0;r<4;r++)first[r]=Load(m,matrix+r*16+a);
   for(uint r=0;r<4;r++){uint pa=matrix+r*16+a,pb=matrix+r*16+b;N v=Load(m,pb);
    Store(m,pa,axis==1?N.Plus(N.Times(first[r],c),N.Times(s,v)):N.Minus(N.Times(first[r],c),N.Times(s,v)));
    v=Load(m,pb);Store(m,pb,axis==1?N.Minus(N.Times(c,v),N.Times(s,first[r])):N.Plus(N.Times(c,v),N.Times(s,first[r])));
   }
  }}
  // 0x64ffe0 /0x6500c0 /0x6501a0: finite4x4 row-vector rotation, exact supplied runtime sine table.
  public static void RotateX(SoundSetupImage m,uint matrix,int angle){Rotate(m,matrix,angle,0);}
  public static void RotateY(SoundSetupImage m,uint matrix,int angle){Rotate(m,matrix,angle,1);}
  public static void RotateZ(SoundSetupImage m,uint matrix,int angle){Rotate(m,matrix,angle,2);}
  static uint At(SoundSetupImage m,uint offset,uint field){return unchecked(m.Word(Emitters)+offset+field);}
  // 0x684640: two signed16angles, live emitter-base reads between actual matrix bodies.
  public static void Primary(SoundSetupImage m,uint id,uint first,uint second){unchecked{if(id==0xffffffff)return;uint off=id*0x330;Copy(m,At(m,off,0x40),Template);RotateZ(m,At(m,off,0x40),(short)first);RotateY(m,At(m,off,0x40),(short)second);m.Word(At(m,off,0x300),0);}}
  // 0x6846a0: Z then Y then X, leaves all unmodified cells intact.
  public static void Secondary(SoundSetupImage m,uint id,uint first,uint second,uint third){unchecked{if(id==0xffffffff)return;uint off=id*0x330;Copy(m,At(m,off,0x80),Template);RotateZ(m,At(m,off,0x80),(short)first);RotateY(m,At(m,off,0x80),(short)second);RotateX(m,At(m,off,0x80),(short)third);m.Word(At(m,off,0x300),0);}}
  // 0x684720: mode byte publishes first, X then Y; no+300 reset on the tail path.
  public static void Mode(SoundSetupImage m,uint id,uint mode,uint first,uint second){unchecked{if(id==0xffffffff)return;uint off=id*0x330;m.Byte(At(m,off,0x2fa),(byte)mode);Copy(m,At(m,off,0xc0),Template);RotateX(m,At(m,off,0xc0),(short)first);RotateY(m,At(m,off,0xc0),(short)second);}}
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> fallback){if(address==0x684640){Primary(m,args[0],args[1],args[2]);return 0;}if(address==0x6846a0){Secondary(m,args[0],args[1],args[2],args[3]);return 0;}if(address==0x684720){Mode(m,args[0],args[1],args[2],args[3]);return 0;}return fallback(m,address,args);}
 }
}
