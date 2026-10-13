using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlEmitterRuntime {
  public const uint Instances=0x2924b50,Origin=0x2920abc,Selected=0x29231a8,ParticlePointers=0x296209c,Emitters=0x29620a4;
  static float F(SoundSetupImage m,uint at){return BitConverter.ToSingle(BitConverter.GetBytes(m.Word(at)),0);}
  static PlaybackWide W(float x){return PlaybackWide.From(x);}
  static PlaybackWide Plus(PlaybackWide a,PlaybackWide b){return PlaybackWide.Add(a,b);}
  static PlaybackWide Minus(PlaybackWide a,PlaybackWide b){return Plus(a,PlaybackWide.Multiply(b,W(-1)));}
  static PlaybackWide Times(PlaybackWide a,PlaybackWide b){return PlaybackWide.Multiply(a,b);}
  static float Add(float a,float b){return Plus(W(a),W(b)).Store();}
  // 0x683e90. Readable emitter/table backing; child allocation683560 is explicit and mutable.
  public static void SetCount(SoundSetupImage m,uint emitter,int count,Action<SoundSetupImage,uint> allocate){unchecked{
   int id=(short)m.Half(emitter+0x182);uint physical=m.Word(m.Word(ParticlePointers)+(uint)id*4);m.Half(emitter+0x18e,(ushort)count);
   int chunks=m.Byte(physical+0x2e)==7?(count+11)/12:(count+31)/32;m.Half(emitter+0x18c,(ushort)chunks);
   if((short)m.Half(emitter+0x18c)>32){m.Half(emitter+0x18c,32);m.Half(emitter+0x18e,(ushort)(m.Byte(physical+0x2e)==7?384:1024));}
   ushort requested=m.Half(emitter+0x18c),current=m.Half(emitter+0x180);
   if(requested==current)m.Half(emitter+0x186,m.Half(emitter+0x18e));else if(requested!=0&&current==0)allocate(m,emitter);
  }}
  // 0x68cfd0. Finite, terminating duty cycles and integral product fitting Int32.
  // Nonpositive lifetime follows the native invalid-conversion low-word clamp, without exposing FPU status.
  public static void Normalize(SoundSetupImage m,uint record,Action<SoundSetupImage,uint> allocate){unchecked{
   float lifetime=F(m,record+0xa4),active=0,total=0;int count=1;
   if(lifetime>0){PlaybackWide cycle=Plus(W(F(m,record+0x20)),W(F(m,record+0x1c)));
    do{float remaining=Minus(W(lifetime),W(total)).Store();PlaybackWide end;
     if(Minus(W(remaining),cycle).StoreDouble()<0){active=Add(remaining,active);end=Plus(W(remaining),W(total));}
     else{active=Plus(W(active),cycle).Store();end=Plus(W(total),cycle);}
     float endStored=end.Store();float rest=Minus(W(lifetime),W(endStored)).Store();float gap=F(m,record+0x24);
     total=Add(endStored,gap<=rest?gap:rest);
    }while(total<lifetime);
    float fraction=PlaybackWide.Divide(W(active),W(total)).Store();PlaybackWide amount=Times(Times(W(fraction),W((short)m.Half(record+0x16))),W(lifetime));
    count=(short)amount.TruncateInt32();if(count<1)count=1;
   }
   m.Half(record+0x14,(ushort)((((sbyte)m.Byte(record+0x410))+1)*count));
   for(uint at=Instances+16;at<Instances+0xb010;at+=0x58){int id=(int)m.Word(at);if(id==-1||id==99999)continue;uint emitter=m.Word(Emitters)+(uint)id*0x330;int particle=(short)m.Half(emitter+0x182);
    if(m.Word(m.Word(ParticlePointers)+(uint)particle*4)==record)SetCount(m,emitter,(short)m.Half(record+0x14),allocate);
   }
  }}
  static float Distance(SoundSetupImage m,uint at){PlaybackWide x=W(Minus(W(F(m,Origin)),W(F(m,at))).Store()),y=W(Minus(W(F(m,Origin+4)),W(F(m,at+4))).Store()),z=W(Minus(W(F(m,Origin+8)),W(F(m,at+8))).Store());return Plus(Plus(Times(y,y),Times(x,x)),Times(z,z)).Store();}
  // 0x661f60. 512 original rows, strict squared threshold, first ties and zero-distance retention.
  public static void Select(SoundSetupImage m,float threshold){unchecked{
   int selected=(int)m.Word(Selected);if(selected!=-1){uint at=Instances+(uint)selected*0x58;uint id=m.Word(at+16);if(id!=0xffffffff&&id!=99999&&Distance(m,at)==0)return;}
   m.Word(Selected,0xffffffff);for(uint i=0;i<512;i++){uint at=Instances+i*0x58,id=m.Word(at+16);if(id==0xffffffff||id==99999)continue;float distance=Distance(m,at);if(threshold<0||distance<threshold){m.Word(Selected,i);threshold=distance;}}
  }}
 }
 public sealed class PtlRecoveredEmitterServices:IPtlRecordServices {
  readonly Action<SoundSetupImage,uint> allocate;
  public PtlRecoveredEmitterServices(Action<SoundSetupImage,uint> allocateEmitter){allocate=allocateEmitter;}
  public void Normalize(SoundSetupImage m,uint record){PtlEmitterRuntime.Normalize(m,record,allocate);}
  public void Select(SoundSetupImage m,uint thresholdBits){PtlEmitterRuntime.Select(m,BitConverter.ToSingle(BitConverter.GetBytes(thresholdBits),0));}
 }
}
