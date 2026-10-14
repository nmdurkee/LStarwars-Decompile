// Actual node-command composition through full formation scheduler and row bodies.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredActualNodeFormation
 {
  public static uint Execute(TakeoverReleaseMemory m,ScriptFormationStepServices step,ScriptCircleServices tokens,ScriptExpressionServices symbols,uint address,uint system,uint packet,uint actor,uint args,int count,uint first)
  {
   var follow=RecoveredFormationFollowServices.Create(step,null,delegate(TakeoverReleaseMemory memory){return memory.Read32(actor+0x144);});
   if(address==0x535fc0)return PreparedNullableScriptNodeActions.Go(m,follow,tokens,symbols,system,packet,actor,args,count,first);
   if(address==0x536fc0)return PreparedNullableScriptNodeActions.Away(m,follow,tokens,symbols,system,packet,actor,args,count,first);
   if(address==0x536190)return PreparedScriptRandomNode.Execute(m,follow,tokens,symbols,system,packet,actor,args,count,first);
   throw new ArgumentException("Unknown prepared node command.");
  }
 }
}
