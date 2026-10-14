// Actual loaded-container catalog/file/parser transport binds to the complete builtin graph and runtime.
namespace Recovered.Gameplay
{
 public static class RecoveredLoadedContainerScriptCatalog
 {
  public static uint LoadAndBind(ConditionParserMemory m,RecoveredGameScriptFileIO files,ScriptExpressionServices symbols,ScriptParserLifecycleServices lifecycle,ScriptGraphBindingServices graph,uint container,uint folder,uint top,uint bottom,uint system,uint packet,uint nameLocal,uint outputLocal,uint pathLocal,uint informationLocal)
  {
   m.Write32(0x91ee88,container);var archive=new RecoveredReleaseScriptArchive(files,pathLocal,informationLocal);var provider=new RecoveredAllocatedScriptProvider(archive,files,pathLocal);var transport=new RecoveredAllocatedScriptTransport(provider,files,archive);var body=PreparedScriptFileClosure.Create(transport,symbols,new RecoveredMemoryScriptLifecycle(files,lifecycle),files.Read,null,null);var catalog=new RecoveredFullScriptCatalogServices(archive,files,body,files.Read,nameLocal,outputLocal);return PreparedBuiltinScriptProgram.LoadAndBind(m,catalog,graph,0,folder,top,bottom,system,packet);
  }
 }
}
