// Whole raw swap16/swap32 and file-endian exchange/get bodies.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptFileEndian
 {
  public static uint Swap16(TakeoverReleaseMemory m,uint pointer){byte a=m.Read8(pointer),b=m.Read8(pointer+1);m.Write8(pointer,b);m.Write8(pointer+1,a);return pointer;}
  public static uint Swap32(TakeoverReleaseMemory m,uint pointer){byte a=m.Read8(pointer),b=m.Read8(pointer+1),c=m.Read8(pointer+2),d=m.Read8(pointer+3);m.Write8(pointer,d);m.Write8(pointer+1,c);m.Write8(pointer+2,b);m.Write8(pointer+3,a);return pointer;}
  //Plain MOV load/store, not an atomic XCHG. Any nonzero value selects reversal in original typed writers.
  public static uint Exchange(TakeoverReleaseMemory m,uint value){uint old=m.Read32(0x91eea0);m.Write32(0x91eea0,value);return old;}
  public static uint Get(TakeoverReleaseMemory m){return m.Read32(0x91eea0);}
 }
}
