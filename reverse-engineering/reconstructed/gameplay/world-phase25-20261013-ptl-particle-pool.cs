using System;
using Recovered.Animation;
namespace Recovered.Gameplay {
 public static class PtlParticlePool {
  const uint Slots=0x296209c,Packets=0x2961fec,ReturnTable=0x2923198,ReturnCount=0x2947b70;
  static uint Physical(SoundSetupImage m,uint e){return unchecked(m.Word(Slots)+(uint)(int)(short)m.Half(e+0x182)*4);}
  static uint Chunk(SoundSetupImage m,uint e,int index){return unchecked(e+0x100+(uint)index*4);}
  struct N {
   PlaybackWide v;bool neg;bool Zero{get{return v.StoreDouble()==0;}}
   N(PlaybackWide value,bool sign){v=value;double d=value.StoreDouble();neg=d<0||(d==0&&sign);}
   public static N Word(uint w){return new N(PlaybackWide.From(BitConverter.ToSingle(BitConverter.GetBytes(w),0)),(w&0x80000000)!=0);}
   public static N Integer(int i){return new N(PlaybackWide.FromDouble(i),i<0);}
   public static N Add(N a,N b){return new N(PlaybackWide.Add(a.v,b.v),a.Zero&&b.Zero&&a.neg&&b.neg);}
   public static N Mul(N a,N b){return new N(PlaybackWide.Multiply(a.v,b.v),a.neg!=b.neg);}
   public uint Store(){uint w=BitConverter.ToUInt32(BitConverter.GetBytes(v.Store()),0);if(Zero&&neg)w|=0x80000000;return w;}
  }
  static int PacketLimit(SoundSetupImage m){return unchecked((int)(m.Word(0x8108e8)+m.Word(0x8108ec)));}
  static int FindPacket(SoundSetupImage m,uint table,int limit,uint value){for(int i=0;i<limit;i++)if(m.Word(unchecked(table+(uint)i*0x64))==value)return i;return -1;}
  static void Snapshot(SoundSetupImage m,uint emitter,uint offset){unchecked{
   m.Word(m.Word(Packets)+offset+8,0);uint destination=m.Word(Packets)+offset+12;
   for(uint i=0;i<64;i+=4)m.Word(destination+i,m.Word(emitter+0x40+i));
   uint x=m.Word(emitter+0x190);m.Word(m.Word(Packets)+offset+0x4c,x);m.Word(m.Word(Packets)+offset+0x50,m.Word(emitter+0x194));m.Word(m.Word(Packets)+offset+0x54,m.Word(emitter+0x198));m.Half(m.Word(Packets)+offset+0x60,m.Half(emitter+0x328));
  }}
  static void EnqueuePacket(SoundSetupImage m,uint emitter,uint record,uint offset){unchecked{if(m.Byte(emitter+0x2f6)==0)return;int bank=(sbyte)m.Byte(record+0x2f1);uint head=0x292fd30+(uint)bank*4;PtlParticleLinks.Priority(m,m.Word(Packets)+offset,head);}}
  // 0x683560: complete prepared pool transfer, real command/priority/time link children.
  // The global spin lock is assumed initially free; original busy-lock behavior is not bounded here.
  public static void Transfer(SoundSetupImage m,uint emitter){unchecked{
   uint original=m.Word(Physical(m,emitter));int delta=(short)m.Half(emitter+0x18c)-(short)m.Half(emitter+0x180);if(delta==0)return;
   if(delta>0){
    bool special=m.Byte(original+0x2e)==7;uint used=special?0x2947d84u:0x2948e98u,capacity=special?0x8108ecu:0x8108e8u,freeTable=special?0x29211fcu:0x2921200u;
    if((int)(m.Word(used)+(uint)delta)>=(int)m.Word(capacity))return;
    for(int i=0;i<delta;i++){int old=(short)m.Half(emitter+0x180);uint pointer=m.Word(m.Word(freeTable)+(m.Word(used)+(uint)i)*4);m.Word(Chunk(m,emitter,old+i),pointer);
     int particles=special?12:32;for(int j=0;j<particles;j++){uint p=m.Word(Chunk(m,emitter,(short)m.Half(emitter+0x180)+i));m.Word(p+0x2c+(uint)j*32,0);p=m.Word(Chunk(m,emitter,(short)m.Half(emitter+0x180)+i));m.Word(p+0x3c+(uint)j*32,0x47000000);}
    }
    if(m.Half(emitter+0x180)==0){int limit=PacketLimit(m);uint table=m.Word(Packets);int index=FindPacket(m,table,limit,0);if(index>=0){uint off=(uint)index*0x64;uint first=m.Word(emitter+0x100);m.Word(table+off,first);m.Word(m.Word(Packets)+off+4,original);m.Word(m.Word(Packets)+off+8,emitter);m.Half(m.Word(Packets)+off+0x60,m.Half(emitter+0x328));EnqueuePacket(m,emitter,original,off);}}
    m.Half(emitter+0x180,(ushort)(m.Half(emitter+0x180)+delta));if(m.Half(emitter+0x180)==m.Half(emitter+0x18c))m.Half(emitter+0x186,m.Half(emitter+0x18e));else m.Half(emitter+0x186,(ushort)(m.Half(emitter+0x186)+(special?12:32)));m.Word(used,m.Word(used)+(uint)delta);PtlParticleLinks.Commands(m,emitter+0x100,(short)m.Half(emitter+0x180));return;
   }
   int maxReturns=PacketLimit(m)*2;if((int)(m.Word(ReturnCount)-(uint)delta)>maxReturns)return;while(m.Word(0x2962058)!=0){}m.Word(0x2962058,1);
   for(int i=delta;i<0;i++){
    uint table=m.Word(ReturnTable),count=m.Word(ReturnCount),node=m.Word(table+count*4);m.Word(node,m.Word(Chunk(m,emitter,(short)m.Half(emitter+0x180)+i)));
    node=m.Word(m.Word(ReturnTable)+m.Word(ReturnCount)*4);m.Word(node+8,m.Byte(original+0x2e)==7?7u:0u);
    bool clockB=m.Byte(original+0x2f1)==4;uint record=m.Word(Physical(m,emitter));int frames=(sbyte)m.Byte(record+0x410);N product=N.Mul(N.Word(m.Word(record+0x414)),N.Integer(frames));N clock=N.Add(N.Word(m.Word(record+0xa4)),N.Word(m.Word(clockB?0x2962060u:0x296205cu)));uint time=N.Add(clock,product).Store();table=m.Word(ReturnTable);count=m.Word(ReturnCount);node=m.Word(table+count*4);m.Word(node+4,time);
    node=m.Word(m.Word(ReturnTable)+m.Word(ReturnCount)*4);PtlParticleLinks.Timed(m,node,clockB?0x292fc00u:0x292fbfcu);m.Word(ReturnCount,m.Word(ReturnCount)+1);
   }
   int current=(short)m.Half(emitter+0x180);m.Word(0x2962058,0);
   if(delta==-current){int limit=PacketLimit(m);uint table=m.Word(Packets),first=m.Word(emitter+0x100);int index=FindPacket(m,table,limit,first);if(index>=0){uint off=(uint)index*0x64,record=m.Word(Physical(m,emitter));m.Word(table+off+4,record);Snapshot(m,emitter,off);}}
   else {PtlParticleLinks.Commands(m,Chunk(m,emitter,current+delta),-delta);int limit=PacketLimit(m);uint table=m.Word(Packets);int index=FindPacket(m,table,limit,0);if(index>=0){uint off=(uint)index*0x64;uint first=m.Word(Chunk(m,emitter,(short)m.Half(emitter+0x180)+delta));m.Word(table+off,first);uint record=m.Word(Physical(m,emitter));m.Word(m.Word(Packets)+off+4,record);Snapshot(m,emitter,off);if(m.Byte(emitter+0x2f6)!=0){record=m.Word(Physical(m,emitter));EnqueuePacket(m,emitter,record,off);}}}
   for(int i=delta;i<0;i++)m.Word(Chunk(m,emitter,(short)m.Half(emitter+0x180)+i),0);ushort wanted=m.Half(emitter+0x18e),chunks=m.Half(emitter+0x18c);m.Half(emitter+0x180,chunks);m.Half(emitter+0x186,wanted);if(wanted!=0)PtlParticleLinks.Commands(m,emitter+0x100,(short)chunks);
  }}
 }
}
