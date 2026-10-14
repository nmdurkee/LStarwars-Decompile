// Raw bump storage creation/destruction wrappers composed with full application allocator/release.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptBumpStorage
 {
  //Temporarily disables current bump allocation before allocating its backing, then restores the old pointer.
  public static uint Create(ConditionParserMemory m,ScriptApplicationHeapServices heap,uint capacity){uint saved=m.Read32(0x88ab20);m.Write32(0x88ab20,0);uint record=RecoveredScriptApplicationAllocation.Allocate(m,heap,unchecked(capacity+16),0x75e93c,0x73);m.Write32(0x88ab20,saved);if(record!=0){m.Write32(record,capacity);m.Write32(record+4,capacity);m.Write32(record+8,unchecked(record+16));}return record;}
  //Original destroy leaves88AB20 untouched, even when it points into the released backing.
  public static void Destroy(ConditionParserMemory m,ScriptApplicationHeapServices heap,uint record){RecoveredScriptApplicationAllocation.Release(m,heap,record,0x75e93c,0x82);}
 }
}
