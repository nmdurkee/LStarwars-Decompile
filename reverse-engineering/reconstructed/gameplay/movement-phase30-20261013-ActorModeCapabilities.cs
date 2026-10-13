using System;
namespace Recovered.Gameplay
{
 public static class ActorModeCapabilities
 {
  static void Or(OriginPathMemory m,uint actor,uint bits){m.Set32(actor+0x4bc,m.U32(actor+0x4bc)|bits);}
  static uint Clip(OriginPathMemory m,uint model,uint at){return m.U32(m.U32(model+0xc)+at);}
  static uint Data(OriginPathMemory m,uint metadata){return m.U32(m.U32(metadata+0x24)+0x90);}
  public static void Normal(OriginPathMemory m,uint actor)
  {
   uint model=m.U32(actor+0x50),metadata=m.U32(actor+0x54),initial=m.U32(metadata+0x44)|0x20000040;m.Set32(actor+0x4bc,initial);uint clips=m.U32(model+0xc);
   if(m.U32(clips+0x220)!=0&&m.U32(clips+0x224)!=0){initial|=(Data(m,metadata)&0x80000)!=0?0x40000u:0x80000u;m.Set32(actor+0x4bc,initial);}clips=m.U32(model+0xc);if(m.U32(clips+0x228)!=0&&m.U32(clips+0x22c)!=0&&m.U32(clips+0x230)!=0)Or(m,actor,0x400000);if(Clip(m,model,0x334)!=0)Or(m,actor,0x100000);if(Clip(m,model,0x18)!=0)Or(m,actor,1);if((Data(m,metadata)&0x400000)!=0)Or(m,actor,0x20);if((Data(m,metadata)&0x40000000)!=0)Or(m,actor,2);uint suit=m.U32(actor+0xcbc);if(suit!=0)Or(m,actor,m.U32(suit+0x10));uint flags=m.U32(actor+0x1f8);if((flags&1)!=0)Or(m,actor,0x100);else if((flags&4)==0)Or(m,actor,0x80);Or(m,actor,0x1000);
   if((m.U32(metadata+4)&0x40000)!=0)Or(m,actor,0x10);if((m.U32(metadata+4)&0x100000)!=0)Or(m,actor,8);if((m.U32(metadata+4)&0x2000)!=0)Or(m,actor,0x10000);if((m.U8(metadata+4)&0x88)!=0||(Data(m,metadata)&0x40)!=0)Or(m,actor,0x8000);if(m.U8(actor+0x280)!=255)Or(m,actor,0x20000);if((Data(m,metadata)&0x4000000)!=0)Or(m,actor,0x800000);
  }
  public static void Alternate(OriginPathMemory m,uint actor,ushort specialType)
  {
   uint flags=m.U32(actor+0x1f8);m.Set32(actor+0x4bc,0x20000000);if((flags&1)!=0)m.Set32(actor+0x4bc,0x20000200);else if((flags&4)==0)m.Set32(actor+0x4bc,0x20000100);uint model=m.U32(actor+0x50);if(Clip(m,model,0x18)!=0)Or(m,actor,3);uint metadata=m.U32(actor+0x54);if((m.U32(metadata+4)&0x200000)==0)Or(m,actor,4);if((m.U32(metadata+4)&0x100000)!=0)Or(m,actor,8);if((ushort)m.U32(actor+0x1064)==specialType)Or(m,actor,0x400);if(Clip(m,model,0x334)!=0)Or(m,actor,0x10);
  }
  public static void Special(OriginPathMemory m,uint actor,ushort specialType)
  {
   uint flags=m.U32(actor+0x1f8),metadata=m.U32(actor+0x54),initial=m.U32(metadata+0x44)|0x20180040;m.Set32(actor+0x4bc,initial);if((flags&1)!=0){initial|=0x100;m.Set32(actor+0x4bc,initial);}else if((flags&4)==0){initial|=0x80;m.Set32(actor+0x4bc,initial);}uint model=m.U32(actor+0x50);if(Clip(m,model,0x18)!=0)Or(m,actor,1);uint typeFlags=m.U32(metadata+4);if((typeFlags&0x200000)==0&&(typeFlags&8)!=0)Or(m,actor,0x1000);if((m.U8(metadata+4)&8)!=0)Or(m,actor,3);if((Data(m,metadata)&0x400000)!=0)Or(m,actor,0x23);if((m.U32(metadata+4)&0x40000)!=0)Or(m,actor,0x10);if((m.U8(metadata+4)&0x40)!=0)Or(m,actor,0x4004);if((m.U32(metadata+4)&0x100000)!=0)Or(m,actor,8);if((m.U32(metadata+4)&0x2000)!=0)Or(m,actor,0x10000);if((m.U8(metadata+4)&0x88)!=0||(Data(m,metadata)&0x40)!=0)Or(m,actor,0x8000);if(m.U8(actor+0x280)!=255)Or(m,actor,0x20000);if((ushort)m.U32(actor+0x1064)==specialType)Or(m,actor,0x4000);
  }
 }
}
