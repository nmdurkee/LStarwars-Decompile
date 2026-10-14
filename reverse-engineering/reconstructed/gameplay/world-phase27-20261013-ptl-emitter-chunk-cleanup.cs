using System;
namespace Recovered.Gameplay {
 public static class PtlEmitterChunkCleanup {
  const uint Emitters=0x29620a4,Slots=0x296209c,Packets=0x2961fec,Returns=0x2923198,ReturnCount=0x2947b70;
  static uint At(uint b,uint id,uint field){return unchecked(b+id*0x330+field);}
  static int PacketLimit(SoundSetupImage m){return unchecked((int)(m.Word(0x8108ec)+m.Word(0x8108e8)));}
  // 0x6553f0: ID is read through a reference at the original mutation boundaries.
  // Initial emitter route survives lock acquisition; per-chunk and later packet routes
  // are refreshed at exactly the original mutation boundaries. Lists and queues are prepared.
  public static void Cleanup(SoundSetupImage m,uint idPointer){unchecked{
   uint route=m.Word(Emitters),id=m.Word(idPointer);ushort physical=m.Half(At(route,id,0x182));if(physical==0)return;bool empty=m.Half(At(route,id,0x180))==0;uint original=m.Word(m.Word(Slots)+(uint)(int)(short)physical*4);if(empty)return;
   while(m.Word(0x2962058)!=0){}id=m.Word(idPointer);route=m.Word(Emitters);bool positive=(short)m.Half(At(route,id,0x180))>0;m.Word(0x2962058,1);
   if(positive)for(uint i=0;;){uint chunk=m.Word(At(route,id,0x100+i*4));PtlParticleUnlinks.CancelReturns(m,chunk);
    id=m.Word(idPointer);uint table=m.Word(Returns),count=m.Word(ReturnCount);uint node=m.Word(table+count*4);route=m.Word(Emitters);m.Word(node,m.Word(At(route,id,0x100+i*4)));
    node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+8,m.Byte(original+0x2e)==7?9u:2u);node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+12,0);
    bool bankB=m.Byte(original+0x2f1)==4;node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+4,m.Word(bankB?0x2962060u:0x296205cu));
    node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);PtlParticleLinks.Timed(m,node,bankB?0x292fc00u:0x292fbfcu);m.Word(ReturnCount,m.Word(ReturnCount)+1);
    id=m.Word(idPointer);route=m.Word(Emitters);int current=(short)m.Half(At(route,id,0x180));i++;if((int)i>=current)break;
   }
   int limit=PacketLimit(m);m.Word(0x2962058,0);
   if(limit>0){uint off=0;int i=0;for(;;){id=m.Word(idPointer);uint emitter=At(route,id,0),packet=m.Word(Packets)+off;uint first=m.Word(packet);
     if(first==m.Word(emitter+0x100)){if(m.Byte(emitter+0x2f6)!=0){int bank=(sbyte)m.Byte(original+0x2f1);PtlParticleUnlinks.Priority(m,packet,0x292fd30+(uint)bank*4);}m.Word(m.Word(Packets)+off,0);m.Word(m.Word(Packets)+off+4,0);route=m.Word(Emitters);}
     i++;off+=0x64;if(i>=PacketLimit(m))break;
   }}
   id=m.Word(idPointer);if((short)m.Half(At(route,id,0x180))>0)for(uint i=0;;){m.Word(At(route,id,0x100+i*4),0);id=m.Word(idPointer);route=m.Word(Emitters);int count=(short)m.Half(At(route,id,0x180));i++;if((int)i>=count)break;}
   m.Half(At(route,m.Word(idPointer),0x186),0);id=m.Word(idPointer);route=m.Word(Emitters);m.Half(At(route,id,0x180),0);id=m.Word(idPointer);route=m.Word(Emitters);m.Half(At(route,id,0x18e),0);id=m.Word(idPointer);route=m.Word(Emitters);m.Half(At(route,id,0x18c),0);id=m.Word(idPointer);route=m.Word(Emitters);m.Half(At(route,id,0x188),0);id=m.Word(idPointer);route=m.Word(Emitters);m.Half(At(route,id,0x18a),0);
  }}
 }
}
