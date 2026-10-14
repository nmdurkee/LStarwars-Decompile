using System;
namespace Recovered.Gameplay {
 public static class PtlParticleUnlinks {
  // 0x654ea0: remove priority packet; fresh neighbor reloads after first splice preserve aliases.
  public static void Priority(SoundSetupImage m,uint node,uint headPointer){unchecked{
   if(m.Word(headPointer)==node){uint next=m.Word(node+0x5c);m.Word(headPointer,next);if(next!=0)m.Word(next+0x58,0);}
   else {uint previous=m.Word(node+0x58);if(previous!=0){uint next=m.Word(node+0x5c);m.Word(previous+0x5c,next);next=m.Word(node+0x5c);if(next!=0)m.Word(next+0x58,m.Word(node+0x58));}}
   m.Word(node+0x58,0);m.Word(node+0x5c,0);
  }}
  // 0x655210: node.next clears even when node is absent or the head is null.
  public static void Timed(SoundSetupImage m,uint node,uint headPointer){unchecked{
   uint cursor=headPointer;if(m.Word(cursor)!=0)for(;;){uint current=m.Word(cursor);if(current==node){m.Word(cursor,m.Word(node+0x10));break;}cursor=current+0x10;if(m.Word(cursor)==0)break;}m.Word(node+0x10,0);
  }}
  // 0x655250: both clock banks; capture next before unlink, then live return count,
  // captured return table base, decrement/store free entry and clear chunk tag.
  public static void CancelReturns(SoundSetupImage m,uint chunk){unchecked{
   for(uint head=0x292fbfc;head<0x292fc04;head+=4){uint current=m.Word(head);while(current!=0){bool match=m.Word(current)==chunk;uint next=m.Word(current+0x10);if(match){Timed(m,current,head);uint count=m.Word(0x2947b70),table=m.Word(0x2923198);count--;m.Word(0x2947b70,count);m.Word(table+count*4,current);m.Word(current,0);}current=next;}}
  }}
 }
}
