using System;
namespace Recovered.Gameplay {
 public static class PtlEmitterConstruction {
  const uint Base=0x29620a4,Head=0x29620a8,Slots=0x296209c,Capacity=0x2962098,Next=0x29211e8;
  static uint At(SoundSetupImage m,uint offset,uint field){return unchecked(m.Word(Base)+offset+field);}
  static float F(uint word){return BitConverter.ToSingle(BitConverter.GetBytes(word),0);}
  // 0x6550b0: signed capacity/cursor gate, signed16 free-order entries and live base on every store.
  public static uint Allocate(SoundSetupImage m){unchecked{
   int cursor=(int)m.Word(Next);if(cursor>=(int)m.Word(0x2962094))return 0xffffffff;int id=(short)m.Half(m.Word(0x2962084)+(uint)cursor*2);m.Word(Next,(uint)(cursor+1));uint off=(uint)id*0x330;
   for(uint i=0;i<32;i++)m.Word(At(m,off,0x100+i*4),0);
   foreach(uint field in new uint[]{0x180,0x18a,0x186,0x18c,0x18e,0x188})m.Half(At(m,off,field),0);
   m.Half(At(m,off,0x2f2),0xffff);m.Word(At(m,off,0x2fc),0);m.Byte(At(m,off,0x2f4),1);m.Byte(At(m,off,0x2f6),1);m.Byte(At(m,off,0x2f7),1);m.Word(At(m,off,0x32c),0);m.Half(At(m,off,0x32a),(ushort)id);m.Byte(At(m,off,0x2fa),0);return (uint)id;
  }}
  // 0x655940: finite binary32 argument copies, exact sentinel guard and positivezero+300 reset.
  public static void Position(SoundSetupImage m,uint id,uint x,uint y,uint z){unchecked{if(id==0xffffffff)return;uint off=id*0x330;m.Word(At(m,off,0x190),x);m.Word(At(m,off,0x194),y);m.Word(At(m,off,0x198),z);m.Word(At(m,off,0x300),0);}}
  // 0x655ba0: low16 short fields and finite binary32 fields, fresh base between each store.
  public static void Fields(SoundSetupImage m,uint id,uint first,uint second,uint a,uint b){unchecked{if(id==0xffffffff)return;uint off=id*0x330;m.Half(At(m,off,0x2dc),(ushort)first);m.Half(At(m,off,0x2de),(ushort)second);m.Word(At(m,off,0x2e0),a);m.Word(At(m,off,0x2e4),b);}}
  // 0x655da0: no ID guard; original timing655c30 remains explicit and mutable.
  public static void Schedule(SoundSetupImage m,uint id,uint time,Func<SoundSetupImage,uint,uint[],uint> call){call(m,0x655c30,new uint[]{At(m,unchecked(id*0x330),0),time});}
  // 0x684ee0: complete prepared own body, real allocator/position/fields/orientation and explicit timing only.
  public static void Create(SoundSetupImage m,uint output,uint physical,uint x,uint y,uint z,Func<SoundSetupImage,uint,uint[],uint> call){unchecked{
   if(physical==0xffffffff||physical==0||(int)physical>=(int)m.Word(Capacity))return;uint record=m.Word(m.Word(Slots)+physical*4);if(record==0||m.Byte(record+0x13)!=0)return;
   bool fresh=m.Word(output)==0xffffffff;if(fresh)m.Word(output,Allocate(m));uint id=m.Word(output);if(id==0xffffffff)return;uint off=id*0x330;
   uint clock=m.Word(m.Byte(record+0x2f1)==4?0x2962060u:0x296205cu);m.Half(At(m,off,0x182),(ushort)physical);m.Byte(At(m,off,0x184),0);Schedule(m,id,m.Word(record+0x18),call);
   int selector=(sbyte)m.Byte(record+0x2c);m.Word(At(m,off,0x1c0),m.Word(0x810910+(uint)selector*4));selector=(sbyte)m.Byte(record+0x2d);m.Word(At(m,off,0x1c4),m.Word(0x810944+(uint)selector*4));
   m.Word(At(m,off,0x1d4),0);m.Half(At(m,off,0x1d0),0);m.Half(At(m,off,0x1d2),0);m.Half(At(m,off,0x2c8),0);m.Word(At(m,off,0x2cc),0);
   for(int i=0;i<(sbyte)m.Byte(m.Word(m.Word(Slots)+physical*4)+0x2f0);i++)m.Word(At(m,off,0x200+(uint)i*0x1c),0xbf800000);
   foreach(uint field in new uint[]{0x19c,0x1a0,0x1a4,0x1a8,0x1ac,0x1b0,0x1b4,0x1b8,0x1bc})m.Word(At(m,off,field),0);
   m.Half(At(m,off,0x2f2),0xffff);m.Byte(At(m,off,0x1da),7);m.Word(At(m,off,0x2fc),0);m.Word(At(m,off,0x300),0);m.Word(At(m,off,0x31c),0x497423f0);m.Byte(At(m,off,0x2f5),0);m.Word(At(m,off,0x320),clock);m.Byte(At(m,off,0x2f9),1);m.Word(At(m,off,0x32c),0);m.Byte(At(m,off,0x2fa),0);
   uint liveBase=m.Word(Base),duration=m.Word(liveBase+off+0x1e4);m.Word(liveBase+off+0x324,F(duration)<F(clock)?duration:clock);m.Half(At(m,off,0x1d8),0);
   int type=(sbyte)m.Byte(record+0x2e);m.Half(At(m,off,0x328),(ushort)(type==2?50000:type==3?40000:type==7?20000:30000));
   for(uint i=0;i<4;i++){uint at=record+0x3e0+i*12;m.Half(At(m,off,0x2e8+i*2),9999);if(m.Word(at)!=0xffffffff){uint kind=m.Word(at+4);if(kind==3||kind==4)m.Half(At(m,off,0x2e8+i*2),1);m.Byte(At(m,off,0x2f5),1);}}
   Position(m,id,x,y,z);PtlEmitterOrientation.Secondary(m,id,0,0,0);PtlEmitterOrientation.Primary(m,id,0,0);Fields(m,id,0,0,0,0x3f666666);m.Word(At(m,off,0x2d0),0);m.Word(At(m,off,0x2d4),0xffffffff);m.Word(At(m,off,0x2d8),0);
   if(fresh){uint emitter=m.Word(Base)+off,head=m.Word(Head);if(head!=0){m.Word(head+0x1cc,emitter);head=m.Word(Head);}m.Word(emitter+0x1c8,head);m.Word(Head,emitter);}
  }}
  public static uint Invoke(SoundSetupImage m,uint address,uint[] args,Func<SoundSetupImage,uint,uint[],uint> fallback){if(address==0x684ee0){Create(m,args[0],args[1],args[2],args[3],args[4],fallback);return 0;}return PtlEmitterOrientation.Invoke(m,address,args,fallback);}
 }
}
