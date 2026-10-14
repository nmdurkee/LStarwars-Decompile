// Whole raw table configuration/release bodies. Application allocator service remains explicit.
namespace Recovered.Gameplay
{
 public abstract class ScriptContainerTableServices
 {
  public abstract uint Allocate(TakeoverReleaseMemory m,uint size,uint source,uint line);
  public abstract void Release(TakeoverReleaseMemory m,uint pointer,uint source,uint line);
 }
 public static class RecoveredScriptContainerTables
 {
  public static void Configure(TakeoverReleaseMemory m,ScriptContainerTableServices s,uint count){if(count!=m.Read32(0x91eea8)){uint one=m.Read32(0x91eeac);if(one!=0)s.Release(m,one,0x75e978,0xa58);uint two=m.Read32(0x91eeb0);if(two!=0)s.Release(m,two,0x75e978,0xa59);m.Write32(0x91eea8,count);uint first=s.Allocate(m,unchecked(count<<4),0x75e978,0xa5d);m.Write32(0x91eeac,first);uint second=s.Allocate(m,unchecked(m.Read32(0x91eea8)<<4),0x75e978,0xa5e);m.Write32(0x91eeb0,second);}m.Write32(0x91ce64,0);m.Write32(0x91ee80,0);}
  public static void Release(TakeoverReleaseMemory m,ScriptContainerTableServices s){uint one=m.Read32(0x91eeac);if(one!=0){s.Release(m,one,0x75e978,0xa68);m.Write32(0x91eeac,0);}uint two=m.Read32(0x91eeb0);if(two!=0){s.Release(m,two,0x75e978,0xa6d);m.Write32(0x91eeb0,0);}m.Write32(0x91eea8,0);}
 }
}
