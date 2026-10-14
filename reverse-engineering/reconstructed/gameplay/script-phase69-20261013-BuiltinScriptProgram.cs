// Caller composition for catalog loading, complete builtin graph binding and packet condition evaluation.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedBuiltinScriptProgram
 {
  // Composes recovered52c470,5143a0 and514640; preparednonnull scoped system,first script andBASE state.
  public static uint LoadAndBind(TakeoverReleaseMemory m,ScriptCatalogServices catalog,ScriptGraphBindingServices graph,uint archive,uint basePath,uint top,uint bottom,uint system,uint packet)
  {
   if(system==0||packet==0)throw new ArgumentException("Prepared scoped system and packet required.");
   PreparedScriptCatalog.Load(m,catalog,archive,basePath,top,bottom,system);
   PreparedScriptGraphBinding.BindSystem(m,graph,system);
   uint script=m.Read32(system+0x1c);
   if(script==0)throw new ArgumentException("Prepared loaded first script required.");
   uint state=m.Read32(script+0x38);
   if(state==0)throw new ArgumentException("Prepared BASE state required.");
   PreparedScriptBinding.Bind(m,packet,script,state,0);
   return script;
  }
  public static uint EvaluateCurrent(TakeoverReleaseMemory m,ScriptConditionServices conditions,uint system,uint actor,uint packet)
  {
   uint state=m.Read32(packet+8);
   if(state==0)throw new ArgumentException("Prepared bound current state required.");
   return PreparedScriptConditions.Evaluate(m,conditions,0,system,state+8,actor,packet);
  }
 }
}
