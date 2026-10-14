// Entire raw archive record/comparator/hash/invalidation leaves; no repaired signed behavior.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptContainerLeaves
 {
  static uint Record(uint handle){return unchecked(0x297dc60+(handle-0x800)*48);}
  //4f0a20 returns only0/1: right record greater than left, not a three-way comparison.
  public static uint RightGreater(TakeoverReleaseMemory m,uint left,uint right){short a=unchecked((short)m.Read16(left+22)),b=unchecked((short)m.Read16(right+22));if(a!=b)return b>a?1u:0u;uint[] offsets={20,19,18,17,16};foreach(uint offset in offsets){sbyte x=unchecked((sbyte)m.Read8(left+offset)),y=unchecked((sbyte)m.Read8(right+offset));if(x!=y)return y>x?1u:0u;}return 0;}
  public static ulong Position(TakeoverReleaseMemory m,uint handle){uint p=Record(handle);ulong begin=m.Read32(p+8)|((ulong)m.Read32(p+12)<<32),current=m.Read32(p+16)|((ulong)m.Read32(p+20)<<32);return unchecked(current-begin);}
  //4f0b70 uses a signed byte XOR and multiplier00199933, distinct from standard FNV-1a.
  public static uint Hash(TakeoverReleaseMemory m,uint source){uint hash=0x811c9dc5;while(true){byte b=m.Read8(source);if(b==0)return hash;hash=unchecked((hash^(uint)(int)(sbyte)b)*0x199933);source++;}}
  public static void Invalidate(TakeoverReleaseMemory m,uint handle){uint p=Record(handle);int index=unchecked((int)m.Read32(p+32));if(index>=0){uint owner=m.Read32(p);m.Write32(unchecked(owner+(uint)index*16+0x34),0xffffffff);}m.Write32(p+36,0);}
 }
}
