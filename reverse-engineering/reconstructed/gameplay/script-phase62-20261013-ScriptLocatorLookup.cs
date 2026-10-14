// Raw locator/locator-set inline names, signed live counts and nullable locator binding closures.
namespace Recovered.Gameplay
{
 public static class PreparedScriptLocatorLookup
 {
  public static uint Find(TakeoverReleaseMemory m,uint system,uint name,bool locatorSet){if(system==0)return 0;uint countOffset=locatorSet?0x2cu:0x24u,arrayOffset=locatorSet?0x30u:0x28u,stride=locatorSet?28u:60u;if(unchecked((int)m.Read32(system+countOffset))<=0)return 0;uint index=0,offset=0;do{uint candidate=m.Read32(system+arrayOffset)+offset;if(candidate!=0&&name!=0&&PreparedConditionLoading.Equal(m,candidate,name))return m.Read32(system+arrayOffset)+index*stride;index++;offset+=stride;}while(unchecked((int)index)<unchecked((int)m.Read32(system+countOffset)));return 0;}
  public static uint Bind(TakeoverReleaseMemory m,uint system,uint name){return name==0?0:Find(m,system,name,false);}
 }
 public sealed class RecoveredScriptLocatorBindings:ScriptLocatorBindingServices
 {
  public override uint Find(TakeoverReleaseMemory m,uint system,uint name){return PreparedScriptLocatorLookup.Find(m,system,name,false);}
 }
}
