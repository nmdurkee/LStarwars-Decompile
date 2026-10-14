// Actual container table lifecycle composes full application allocator and release bodies.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredApplicationContainerTableServices:ScriptContainerTableServices
 {
  readonly ScriptApplicationHeapServices heap;public RecoveredApplicationContainerTableServices(ScriptApplicationHeapServices services){heap=services;}
  static ConditionParserMemory Shared(TakeoverReleaseMemory m){ConditionParserMemory shared=m as ConditionParserMemory;if(shared==null)throw new ArgumentException("Shared application image required.");return shared;}
  public override uint Allocate(TakeoverReleaseMemory m,uint size,uint source,uint line){return RecoveredScriptApplicationAllocation.Allocate(Shared(m),heap,size,source,line);}
  public override void Release(TakeoverReleaseMemory m,uint pointer,uint source,uint line){RecoveredScriptApplicationAllocation.Release(Shared(m),heap,pointer,source,line);}
 }
 public static class RecoveredScriptApplicationContainerTables
 {
  public static void Configure(ConditionParserMemory m,ScriptApplicationHeapServices heap,uint count){RecoveredScriptContainerTables.Configure(m,new RecoveredApplicationContainerTableServices(heap),count);}
  public static void Release(ConditionParserMemory m,ScriptApplicationHeapServices heap){RecoveredScriptContainerTables.Release(m,new RecoveredApplicationContainerTableServices(heap));}
 }
}
