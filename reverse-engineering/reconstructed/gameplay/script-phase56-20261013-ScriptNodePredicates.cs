// Raw level-node predicates use signed index from wrapped pointer subtraction /92 and signed actor node IDs.
namespace Recovered.Gameplay
{
 public abstract class ScriptNodeBindingServices{public abstract uint Find(TakeoverReleaseMemory m,uint system,uint level,uint name);}
 public static class PreparedScriptNodePredicates
 {
  static uint Bool(bool b){return b?0x3f800000u:0;}
  static int Index(TakeoverReleaseMemory m,uint system,uint bound){uint level=m.Read32(system+0x10),world=m.Read32(level+8),basis=m.Read32(world+0x7c);return unchecked((int)(bound-basis))/92;}
  static short Node(TakeoverReleaseMemory m,uint controller){return unchecked((short)m.Read16(controller+0x124));}
  public static uint InLevelNode(TakeoverReleaseMemory m,uint system,uint actor,uint bound){if(actor==0||bound==0||system==0)return 0;int index=Index(m,system,bound);return Bool(Node(m,actor)==index);}
  public static uint PlayerInLevelNode(TakeoverReleaseMemory m,uint system,uint bound){if(system==0)return 0;uint reference=m.Read32(system+0x138c);if(reference==0||bound==0)return 0;int index=Index(m,system,bound);return Bool(Node(m,m.Read32(reference+4))==index);}
  public static uint EitherPlayerInLevelNode(TakeoverReleaseMemory m,uint system,uint bound){if(system==0||bound==0)return 0;uint reference=m.Read32(system+0x138c);if(reference!=0){int index=Index(m,system,bound);if(Node(m,m.Read32(reference+4))==index)return 0x3f800000;}reference=m.Read32(system+0x1390);if(reference==0)return 0;int second=Index(m,system,bound);return Bool(Node(m,m.Read32(reference+4))==second);}
  public static uint Bind(TakeoverReleaseMemory m,ScriptNodeBindingServices s,uint system,uint name){if(system==0)return 0;uint level=m.Read32(system+0x10);if(level==0||m.Read8(level)==0)return 0;uint world=m.Read32(level+8);return s.Find(m,system,world,name);}
 }
 public sealed class RecoveredNodeConditionServices:ScriptConditionServices
 {
  readonly ScriptConditionServices remaining;public RecoveredNodeConditionServices(ScriptConditionServices other){remaining=other;}
  public override uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint arg14,uint arg18){switch(callback){case 0x514e20:return PreparedScriptNodePredicates.InLevelNode(m,system,actor,arg18);case 0x514e70:return PreparedScriptNodePredicates.PlayerInLevelNode(m,system,arg18);case 0x514ec0:return PreparedScriptNodePredicates.EitherPlayerInLevelNode(m,system,arg18);}return remaining.Predicate(m,callback,system,packet,actor,arg14,arg18);}
  public override uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint text){return remaining.Expression(m,actor,packet,text);}
 }
}
