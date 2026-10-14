// Actual table→application debug allocation/release→whole private-pool graph; no heap ports.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredPrivatePoolApplicationHeapServices:ScriptApplicationHeapServices
 {
  public override uint CrtAllocate(ConditionParserMemory m,uint capacity){throw new InvalidOperationException("CRT allocation is outside the prepared private-pool domain.");}
  public override void CrtFree(ConditionParserMemory m,uint block){throw new InvalidOperationException("CRT free is outside the prepared private-pool domain.");}
  public override uint PoolAllocate(ConditionParserMemory m,uint pool,uint capacity,uint alignment){return RecoveredScriptPrivatePool.Allocate(m,pool,capacity,alignment);}
  public override void PoolFree(ConditionParserMemory m,uint pool,uint block){RecoveredScriptPrivatePool.Free(m,pool,block);}
 }
 public static class RecoveredScriptPrivatePoolContainerTables
 {
  public static void Configure(ConditionParserMemory m,uint count){if(m.Read32(0x88ab2c)==0)throw new ArgumentException("Prepared active private pool required.");RecoveredScriptApplicationContainerTables.Configure(m,new RecoveredPrivatePoolApplicationHeapServices(),count);}
  public static void Release(ConditionParserMemory m){if(m.Read32(0x88ab2c)==0)throw new ArgumentException("Prepared active private pool required.");RecoveredScriptApplicationContainerTables.Release(m,new RecoveredPrivatePoolApplicationHeapServices());}
 }
}
