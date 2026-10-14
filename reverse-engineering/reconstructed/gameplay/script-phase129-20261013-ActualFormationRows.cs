// Caller composition: actual formation row algorithms close the raw scheduler/FollowPlayer seam.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredActualFormationRows:ScriptFormationRowServices
 {
  readonly ScriptFormationStepServices movement;readonly ScriptFormationRowServices remaining;
  public RecoveredActualFormationRows(ScriptFormationStepServices step,ScriptFormationRowServices customRows){movement=step;remaining=customRows;}
  public override uint Row(TakeoverReleaseMemory m,uint callback,uint formation,uint row,uint previous,uint owner)
  {
   if(callback==0x51cbc0)return PreparedScriptFormationFollowRow.Execute(m,movement,formation,row,previous,owner);
   if(callback==0x51c6a0)return PreparedScriptFormationRandomRow.Execute(m,movement,formation,row,previous,owner);
   if(remaining==null)throw new NotSupportedException("Custom formation row callback required.");return remaining.Row(m,callback,formation,row,previous,owner);
  }
 }
 public static class RecoveredFormationFollowServices
 {
  public static RecoveredScriptFollowScheduler Create(ScriptFormationStepServices movement,ScriptFormationRowServices customRows,Func<TakeoverReleaseMemory,uint> implicitFormation){return new RecoveredScriptFollowScheduler(new RecoveredActualFormationRows(movement,customRows),implicitFormation);}
 }
}
