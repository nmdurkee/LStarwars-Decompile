// Live byte-count, ordered92-byte level-node name lookup and concrete binding composition.
namespace Recovered.Gameplay
{
 public static class PreparedScriptNodeLookup
 {
  public static uint Find(TakeoverReleaseMemory m,uint system,uint explicitWorld,uint name){uint world=explicitWorld;if(world==0){if(system==0)return 0;uint level=m.Read32(system+0x10);if(level==0||m.Read8(level)==0)return 0;world=m.Read32(level+8);if(world==0)return 0;}uint index=0,offset=0;if(m.Read8(world+0x10)==0)return 0;do{uint array=m.Read32(world+0x7c),candidate=m.Read32(array+offset);if(candidate!=0&&name!=0&&PreparedConditionLoading.Equal(m,candidate,name))return m.Read32(world+0x7c)+index*92;index++;offset+=92;}while(index<m.Read8(world+0x10));return 0;}
 }
 public sealed class RecoveredScriptNodeBindings:ScriptNodeBindingServices
 {
  public override uint Find(TakeoverReleaseMemory m,uint system,uint level,uint name){return PreparedScriptNodeLookup.Find(m,system,level,name);}
 }
}
