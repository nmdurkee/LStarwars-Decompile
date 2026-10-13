// Original561ba0 jump/ejection context producer plus sound router547f30.
// Audio backends remain explicit services; prepared memory is phase7 interface.
using System;
namespace Recovered.Gameplay
{
 public abstract class JumpContextAudio
 {
  // Original681e90 receives two stack arguments after the router's tail jump.
  public abstract void PlayerSound(TakeoverReleaseMemory m,int sound,uint position);
  public abstract void WorldSound(TakeoverReleaseMemory m,int sound,uint position,float volume);
 }
 public static class JumpContextProducer
 {
  static uint FloatBits(TakeoverReleaseMemory m,uint p){float f=m.Float(p);if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentOutOfRangeException("finite jump context float backing");return m.Read32(p);}
  // 547f30: definition flags0x40 precedes0x08; special modes use full uint range.
  public static void Sound(TakeoverReleaseMemory m,JumpContextAudio audio,uint actor,uint mode)
  {
   uint flags=m.Read32(m.Read32(actor+0x54)+4),slot;
   if((flags&0x40)!=0)slot=0x15a;
   else if((flags&8)==0)slot=0x158;
   else{if(mode>4)return;uint[] slots={0x15c,0x15e,0x164,0x160,0x162};slot=slots[(int)mode];}
   int id=unchecked((short)m.Read16(m.Read32(0x8020bc)+slot));if(id==-1)return;
   if((m.Read8(actor+0x1fc)&0x80)!=0||(m.Read32(actor+0xeec)&0x08000000)!=0)audio.PlayerSound(m,id,actor+0x19c);
   else audio.WorldSound(m,id,actor+0x19c,.5f);
  }
  // Prepared-memory projection of already recovered62e650 with action=-1.
  static void ResetAnimation(TakeoverReleaseMemory m,uint p)
  {if(p==0)return;m.Write32(p+4,0x3f800000);m.Write16(p+0x3a,65535);m.Write32(p+0x14,0x3f800000);m.Write16(p+0x38,65535);m.Write32(p,0x3f800000);m.Write16(p+0x36,65535);m.Write8(p+0x31,0);m.Write8(p+0x30,4);m.Write16(p+0x42,65535);m.Write8(p+0x3e,0);m.Write8(p+0x3c,0);m.Write8(p+0x3d,0);}
  // 561ba0: full mode comparisons select flag10000, low byte6/7 suppresses sound.
  // Global context==-1 skips the first block, but mandatory tail still executes.
  public static void Enter(TakeoverReleaseMemory m,JumpContextAudio audio,uint actor,uint mode)
  {
   uint context=m.Read32(0x802838);
   if(context!=0xffffffff)
   {
    m.Write8(actor+0x7b5,(byte)context);m.Write8(actor+0x7b8,(byte)mode);ushort animation=m.Read16(0x804bec);m.Write32(actor+0x77c,0);m.Write16(actor+0x7aa,animation);
    uint flags=m.Read32(actor+0x7bc),height=FloatBits(m,actor+0x17c);m.Write32(actor+0x78c,height);m.Write32(actor+0x788,0);m.Write8(actor+0x7b9,1);m.Write32(actor+0x7bc,(flags&0xfffe6fff)|((mode==3||mode==4)?0x10000u:0));
    if((byte)mode!=6&&(byte)mode!=7)Sound(m,audio,actor,0);
   }
   uint definition=m.Read32(actor+0x54);m.Write8(actor+0x281,0);m.Write16(actor+0x1050,0);uint type=m.Read32(definition+0x24),impulse=FloatBits(m,type+0x2c);m.Write32(actor+0xe20,m.Read32(actor+0xe20)|0x100000);m.Write32(actor+0x6c,impulse);m.Write32(actor+0xd48,0);m.Write32(actor+0xd2c,0);m.Write32(actor+0xd1c,0);
   ResetAnimation(m,actor+8);m.Write16(actor+0x278,0);m.Write16(actor+0x27c,0);m.Write8(actor+0x107a,2);
  }
 }
}
