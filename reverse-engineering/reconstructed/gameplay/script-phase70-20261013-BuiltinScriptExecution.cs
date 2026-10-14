// Loaded-script execution closes condition/reference callbacks through the complete builtin runtime adapter.
namespace Recovered.Gameplay
{
 public static class PreparedBuiltinScriptExecution
 {
  public static void Tick(TakeoverReleaseMemory m,RecoveredAllBuiltinConditions conditions,ScriptDispatcherServices gameActions,uint system,uint actor,uint packet,uint deltaBits)
  {
   PreparedEvaluatedScriptDispatcher.Tick(m,gameActions,conditions,system,actor,packet,deltaBits);
  }
 }
}
