using System;
namespace Recovered.Gameplay {
 public static class PtlPhysicalSnapshotCleanup {
  const uint Packets=0x2961fec,Returns=0x2923198,ReturnCount=0x2947b70;
  static int Limit(SoundSetupImage m){return unchecked((int)(m.Word(0x8108e8)+m.Word(0x8108ec)));}
  // 0x655730: snapshot owner must be zero and physical pointer must match.
  // Busy lock is acquired even when capacity is nonpositive. Cached scan base
  // survives skipped rows; successful rows refresh global packet routes after cancellation/unlink.
  public static void Cleanup(SoundSetupImage m,uint physical){unchecked{
   while(m.Word(0x2962058)!=0){}int limit=Limit(m);m.Word(0x2962058,1);
   if(limit>0){uint route=m.Word(Packets),off=0;int i=0;for(;;){uint packet=route+off;
    if(m.Word(packet+8)==0&&m.Word(packet+4)==physical){uint chunk=m.Word(packet);PtlParticleUnlinks.CancelReturns(m,chunk);
     uint node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node,m.Word(m.Word(Packets)+off));node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+8,m.Byte(physical+0x2e)==7?9u:2u);node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+12,0);
     bool bankB=m.Byte(physical+0x2f1)==4;node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);m.Word(node+4,m.Word(bankB?0x2962060u:0x296205cu));node=m.Word(m.Word(Returns)+m.Word(ReturnCount)*4);PtlParticleLinks.Timed(m,node,bankB?0x292fc00u:0x292fbfcu);m.Word(ReturnCount,m.Word(ReturnCount)+1);
     int bank=(sbyte)m.Byte(physical+0x2f1);packet=m.Word(Packets)+off;PtlParticleUnlinks.Priority(m,packet,0x292fd30+(uint)bank*4);m.Word(m.Word(Packets)+off,0);m.Word(m.Word(Packets)+off+4,0);route=m.Word(Packets);
    }
    i++;off+=0x64;if(i>=Limit(m))break;
   }}
   m.Word(0x2962058,0);
  }}
 }
}
