using System;
namespace Recovered.Gameplay
{
 public sealed class SoundHashTableState
 {
  public int Initialized;
  public uint TableOffset;
  public uint[] Table;
 }
 public static class SoundHashInitialization
 {
  //0x650280: persistent gate, four-byte arena alignment and256 CRC words.
  //Arena offsets replace process addresses; cursor and table storage disjoint.
  public static void Initialize(SoundHashTableState state,ref uint cursor)
  {
   if(state.Initialized!=0)return;
   state.TableOffset=unchecked(cursor+3)&0xfffffffcu;cursor=unchecked(state.TableOffset+0x400);state.Table=new uint[256];
   for(uint i=0;i<256;i++)
   {
    uint value=i<<24;for(int bit=0;bit<8;bit++)value=unchecked((value<<1)^((value&0x80000000)!=0?0x04c11db7u:0));state.Table[i]=value;
   }
   state.Initialized=1;
  }
  //0x650470: same ASCII hash as650430, with unsigned maximum byte count.
  public static uint HashPrefix(EffectSoundRegistry registry,string name,uint limit)
  {
   if(name==null)throw new ArgumentNullException("name");name=SceneryText.C(name);uint value=0;
   for(int i=0;i<name.Length&&(uint)i<limit;i++)
   {
    char raw=name[i];if(raw>127)throw new ArgumentException("ASCII hash input required.");uint c=raw>='a'&&raw<='z'?(uint)raw-32:(uint)raw;int index=(int)(c^(value>>24));
    if(registry.HashTable==null||registry.HashTable.Length<=index)throw new ArgumentException("Missing sound hash table.");value=unchecked((value<<8)^registry.HashTable[index]);
   }
   return value;
  }
 }
}
