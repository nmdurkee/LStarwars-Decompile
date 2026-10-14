// Complete148-byte original private-pool initializer.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptPrivatePoolInitialization
 {
  //Unused middle argument preserved in signature. Size<80 returns0 before dereferencing cursor.
  //Cursor may alias header fields; later header writes intentionally override the consumed cursor value.
  public static uint Initialize(TakeoverReleaseMemory m,uint cursor,uint reserved,uint capacity){unchecked{if(capacity<80)return 0;uint block=m.Read32(cursor),end=block+capacity;m.Write32(cursor,end);m.Write32(block+24,0);uint root=block+16;m.Write32(root,0);uint free=block+48;m.Write32(root+4,free);m.Write32(root+12,root);m.Write32(block+36,0);m.Write32(block+40,0);uint before=block+32;m.Write32(before,0x80000000);m.Write32(before+12,before);uint last=end-16;m.Write32(last+4,0);m.Write32(last+8,0);m.Write32(last,0x80000000);m.Write32(last+12,last);uint remaining=capacity-80;m.Write32(free,remaining);m.Write32(free+4,0);m.Write32(free+8,root);m.Write32(free+(remaining&0x7fffffff)+12,free);m.Write32(block+4,capacity);m.Write32(block+8,0);m.Write32(block+12,0);m.Write32(block,block);return block;}}
 }
}
