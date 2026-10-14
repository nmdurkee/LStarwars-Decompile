// Raw ordered64-byte inline trigger-name records, signed live count and nullable byte comparator.
namespace Recovered.Gameplay
{
 public static class PreparedScriptTriggerLookup
 {
  public static uint Find(TakeoverReleaseMemory m,uint system,uint name){if(system==0||unchecked((int)m.Read32(system+0x34))<=0)return 0;uint index=0,offset=0;do{uint area=m.Read32(system+0x38)+offset;if(name!=0&&area!=0&&PreparedConditionLoading.Equal(m,name,area))return area;index++;offset+=64;}while(unchecked((int)index)<unchecked((int)m.Read32(system+0x34)));return 0;}
 }
 public sealed class RecoveredScriptTriggerBindings:ScriptTriggerBindingServices
 {
  public override uint Find(TakeoverReleaseMemory m,uint system,uint name){return PreparedScriptTriggerLookup.Find(m,system,name);}
 }
}
