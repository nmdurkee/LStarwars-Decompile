// Complete builtin initializer adapter: all14 nonzero initializer entries close through recovered lookups/binders.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredAllBuiltinGraphBindings:ScriptGraphBindingServices
 {
  readonly ScriptIdentityBindingServices identities;readonly ScriptGraphBindingServices remaining;readonly ScriptTriggerBindingServices triggers=new RecoveredScriptTriggerBindings();readonly ScriptNodeBindingServices nodes=new RecoveredScriptNodeBindings();
  public RecoveredAllBuiltinGraphBindings(ScriptIdentityBindingServices identityResolver,ScriptGraphBindingServices customInitializers){identities=identityResolver;remaining=customInitializers;}
  public override uint ResolveScript(TakeoverReleaseMemory m,uint system,uint name,uint one,uint scoped,uint global){return PreparedScriptGraphBinding.ResolveScript(m,system,name,one,scoped,global);}
  public override uint Initialize(TakeoverReleaseMemory m,uint callback,uint system,uint argument,uint script){switch(callback){case 0x5149b0:return PreparedScriptGraphBinding.AlwaysTrueInitializer(m,argument);case 0x52d070:case 0x52d090:case 0x52d1e0:case 0x52d200:return PreparedScriptLocatorLookup.Bind(m,system,argument);case 0x52d0b0:case 0x52d160:case 0x52d180:case 0x52d1a0:case 0x52d1c0:return PreparedScriptTriggerPredicates.Bind(m,triggers,system,argument);case 0x52d0d0:case 0x52d100:case 0x52d130:return PreparedScriptNodePredicates.Bind(m,nodes,system,argument);case 0x515730:return PreparedScriptActorPredicates.BindIdentity(m,identities,system,argument);}if(remaining==null)throw new NotSupportedException("Custom initializer service required for "+callback.ToString("x"));return remaining.Initialize(m,callback,system,argument,script);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){if(remaining!=null)remaining.Diagnostic(m,callback,arguments);}
 }
}
