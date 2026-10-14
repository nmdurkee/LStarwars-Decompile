// Whole original private-pool queries, including sentinel/root traversal.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptPrivatePoolQueries
 {
  public static uint Allocated(TakeoverReleaseMemory m,uint pool){return m.Read32(pool+8);}
  public static uint Used(TakeoverReleaseMemory m,uint pool){return m.Read32(pool+12);}
  //Native4efc00 increments after loading each next link, thus counting initial root too.
  public static uint Nodes(TakeoverReleaseMemory m,uint pool){uint node=unchecked(m.Read32(pool)+16),count=0;while(node!=0){node=m.Read32(node+4);count=unchecked(count+1);}return count;}
  public static uint FreeBytes(TakeoverReleaseMemory m,uint pool){uint node=unchecked(m.Read32(pool)+16),total=0;while(node!=0){uint size=m.Read32(node);node=m.Read32(node+4);total=unchecked(total+(size&0x7fffffff));}return total;}
 }
}
