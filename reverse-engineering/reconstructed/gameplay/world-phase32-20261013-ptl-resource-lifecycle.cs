using System;
namespace Recovered.Gameplay {
 public static class PtlResourceLifecycle {
  //655380 scans reserved index1 onward, retains cached table on skipped rows and refreshes it after successful recycle.
  public static void RecycleDescriptors(SoundSetupImage m){unchecked{uint i=1;if((int)m.Word(0x2962098)<=1)return;uint table=m.Word(0x296209c);for(;;){uint record=m.Word(table+i*4);if(record!=0&&m.Word(record+0x2a8)!=0){uint count=m.Word(0x2924b44),free=m.Word(0x2962090);count--;m.Word(0x2924b44,count);record=m.Word(table+i*4);uint descriptor=m.Word(record+0x2a8);m.Word(free+count*4,descriptor);record=m.Word(m.Word(0x296209c)+i*4);m.Word(record+0x2a8,0);table=m.Word(0x296209c);}i++;if((int)i>=(int)m.Word(0x2962098))break;}}}
  //655fc0: no ID sentinel guard, lowbyte mask1da.
  public static void EmitterMask(SoundSetupImage m,uint id,uint mask){unchecked{uint off=id*0x330;m.Byte(m.Word(0x29620a4)+off+0x1da,(byte)mask);}}
  //655fe0: prior-head backward link stores before global head reread and new forward link publication.
  public static void PrependEmitter(SoundSetupImage m,uint emitter){unchecked{uint head=m.Word(0x29620a8);if(head!=0){m.Word(head+0x1cc,emitter);head=m.Word(0x29620a8);}m.Word(emitter+0x1c8,head);m.Word(0x29620a8,emitter);}}
  //656010: previous-zero path replaces global head without a membership check; fresh next/previous reload after first splice.
  public static void UnlinkEmitter(SoundSetupImage m,uint emitter){unchecked{uint previous=m.Word(emitter+0x1cc);if(previous==0){uint next=m.Word(emitter+0x1c8);m.Word(0x29620a8,next);if(next!=0)m.Word(next+0x1cc,0);}else{uint next=m.Word(emitter+0x1c8);m.Word(previous+0x1c8,next);next=m.Word(emitter+0x1c8);if(next!=0)m.Word(next+0x1cc,m.Word(emitter+0x1cc));}m.Word(emitter+0x1c8,0);m.Word(emitter+0x1cc,0);}}
 }
}
