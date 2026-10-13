using System;
namespace Recovered.Gameplay
{
 public static class SoundRecordInitialization
 {
  //0x651530. The name slot follows the global sound count, not the index argument.
  //Only listed bytes reset; link, comment bit, trailing name and padding survive.
  public static void Initialize(SoundSetupImage m,int index)
  {
   uint offset=unchecked((uint)index*64),record=unchecked(m.Word(0x2947b74)+offset);
   m.Word(record+4,(m.Word(record+4)&0xff880000u)|0x7fff);
   m.Word(record,unchecked(0x293b318+m.Word(0x296201c)*32));m.Word(record+8,0x5622);m.Byte(record+12,0);
   m.Half(record+0x12,0x3fff);m.Half(record+0x14,0xffff);m.Half(record+0x16,0);
   for(uint at=0x18;at<=0x38;at+=4)m.Word(record+at,0);
   uint backup=unchecked(m.Word(0x292fda4)+offset);
   //Original REP MOVSD copies forward, including its observable overlap behavior.
   for(uint i=0;i<16;i++)m.Word(backup+i*4,m.Word(record+i*4));
  }
 }
}
