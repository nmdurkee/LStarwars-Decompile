using System;
namespace Recovered.Gameplay {
 public interface IDispatchAllocationCallbacks {
  // Original ABI is callback(world). Descriptor/entry identify observed call context, not extra native arguments.
  uint Invoke(SoundSetupImage m,uint callback,uint world,uint descriptor,uint entry);
 }
 public static class WorldRuntimeAllocation {
  // 0x559610: strict unsigned PREALIGNMENT end test,16-byte alignment; even zero destination is passed to memset.
  public static uint Allocate16(SoundSetupImage m,uint cursorRef,uint endRef,uint size) {
   unchecked{if(cursorRef==0||endRef==0)return 0;uint raw=m.Word(cursorRef);if(raw+size>=m.Word(endRef))return 0;
    uint at=(raw+15)&0xfffffff0;m.Word(cursorRef,at+size);m.Zero(at,size);return at;}
  }
  // 0x59a620:24-byte pool header followed by64-byte slots. Cursor is aligned even when allocation fails.
  public static uint CreatePool(SoundSetupImage m,uint world,uint cursorRef,uint endRef,int capacity) {
   unchecked{uint header=(m.Word(cursorRef)+15)&0xfffffff0;m.Word(cursorRef,header);uint slots=(uint)capacity*64,size=slots+24;
    if(capacity==0||header+size>m.Word(endRef))return 0;
    m.Zero(header,size);uint items=m.Word(cursorRef)+24;m.Word(cursorRef,items);m.Word(header,items);m.Word(header+16,(uint)capacity);m.Word(header+12,world);m.Word(header+8,items);
    uint previous=items;for(int i=1;i<capacity-1;i++){uint next=m.Word(header)+(uint)i*64;m.Word(previous+56,next);previous=next;}
    m.Word(cursorRef,m.Word(cursorRef)+slots);return header;
   }
  }
  // 0x59a6b0: removing an unmatched nonnull node still decrements count when active list is nonempty.
  public static void ReleasePoolNode(SoundSetupImage m,uint pool,uint node) {
   unchecked{if(pool==0||node==0)return;uint at=m.Word(pool+4);if(at==0)return;
    if(at==node){m.Word(pool+4,m.Word(node+56));m.Word(node+56,m.Word(pool+8));m.Word(pool+20,m.Word(pool+20)-1);m.Word(pool+8,node);return;}
    while(m.Word(at+56)!=0){uint next=m.Word(at+56);if(next==node){m.Word(at+56,m.Word(node+56));m.Word(node+56,m.Word(pool+8));m.Word(pool+8,node);break;}at=next;}
    m.Word(pool+20,m.Word(pool+20)-1);
   }
  }
  // 0x5598e0:12-byte header,20-byte descriptor rows and optional8-byte per-item rows.
  public static uint CreateDispatchState(SoundSetupImage m,uint world,uint cursorRef,uint endRef,IDispatchAllocationCallbacks callbacks) {
   unchecked{if(m.Word(0x93b268)==0)return 0;
    if(cursorRef==0||endRef==0||m.Word(cursorRef)+12>=m.Word(endRef))return 0; //559570 is an actual RET-only no-op.
    uint header=(m.Word(cursorRef)+15)&0xfffffff0;m.Word(cursorRef,header+12);m.Word(header,0);m.Word(header+4,0);m.Word(header+8,0);
    uint rows=Allocate16(m,cursorRef,endRef,m.Word(m.Word(0x93b268))*20);m.Word(header,rows);
    if(rows!=0){uint registry=m.Word(0x93b268),descriptor=m.Word(registry+8),entry=rows;int index=0;
     while(index<(int)m.Word(m.Word(0x93b268))){m.Word(entry,descriptor);uint callback=m.Word(descriptor+44);
      if(callback!=0)m.Word(entry+8,callbacks.Invoke(m,callback,world,descriptor,entry));
      uint count=m.Word(entry+8);if(count!=0)m.Word(entry+12,Allocate16(m,cursorRef,endRef,count*8));
      callback=m.Word(descriptor+136);if(callback!=0)m.Word(entry+16,callbacks.Invoke(m,callback,world,descriptor,entry));
      index++;entry+=20;descriptor+=156;
     }
    }
    uint extra=m.Word(0x802724);if(extra!=0)m.Word(header+4,Allocate16(m,cursorRef,endRef,extra));return header;
   }
  }
 }
}
