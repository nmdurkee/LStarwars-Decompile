// Actual pool initialization composed with full application/table/privatepool lifecycle.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptInitializedPrivatePoolTables
 {
  public static uint InitializeAndConfigure(ConditionParserMemory m,uint cursor,uint capacity,uint count){uint pool=RecoveredScriptPrivatePoolInitialization.Initialize(m,cursor,0,capacity);if(pool!=0){m.Write32(0x88ab2c,pool);RecoveredScriptPrivatePoolContainerTables.Configure(m,count);}return pool;}
  public static void Release(ConditionParserMemory m){RecoveredScriptPrivatePoolContainerTables.Release(m);}
 }
}
