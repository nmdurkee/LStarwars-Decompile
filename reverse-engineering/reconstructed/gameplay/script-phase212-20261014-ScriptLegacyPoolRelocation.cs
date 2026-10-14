// Complete raw201-byte relocation; exact observed offsets, without repairing the legacy record layout.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptLegacyPoolRelocation
 {
  public static uint Relocate(TakeoverReleaseMemory m,uint pool,uint pointer){unchecked{if(pointer==0)return 0;uint size=m.Read32(pointer-12)&0x7fffffff,free=m.Read32(pointer+size+4);if((free&0x80000000)!=0)return pointer;free&=0x7fffffff;uint previous=m.Read32(pointer+size+12);if(previous!=0)m.Write32(previous+4,m.Read32(pointer+size+8));uint next=m.Read32(pointer+size+8);if(next!=0)m.Write32(next+8,m.Read32(pointer+size+12));uint destination=pointer+free+28;for(uint i=size;i!=0;i--)m.Write8(destination+i-1,m.Read8(pointer+i-1));uint block=pointer+free+16;m.Write32(block+4,0);m.Write32(block+8,0);m.Write32(block,size|0x80000000);m.Write32(block+size+12,block);m.Write32(pointer,free);m.Write32(pointer+4,0);m.Write32(pointer+8,0);m.Write32(pointer+free+12,pointer);uint root=m.Read32(pool)+16,head=m.Read32(root+4);if(head!=0)m.Write32(head+8,pointer);m.Write32(pointer+4,m.Read32(root+4));m.Write32(pointer+8,root);m.Write32(root+4,pointer);return destination;}}
 }
}
