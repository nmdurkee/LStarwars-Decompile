// Remaining compact builtin script predicates and IAm binding callback.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptIdentityBindingServices{public abstract uint Resolve(TakeoverReleaseMemory m,uint callback,uint system,uint name);}
 public static class PreparedScriptActorPredicates
 {
  static uint Bool(bool b){return b?0x3f800000u:0;}
  static uint Stored(uint bits){if((bits&0x7f800000)==0x7f800000&&(bits&0x7fffff)!=0&&(bits&0x400000)==0)throw new ArgumentException("Signaling NaN outside paired store domain.");return bits;}
  public static uint PathBlocked(TakeoverReleaseMemory m,uint actor){return Bool(actor!=0&&(m.Read32(actor+0x1e8)&0x400000)!=0);}
  public static uint InterruptID(TakeoverReleaseMemory m,uint packet){return packet==0?Stored(m.Read32(0x751768)):TakeoverReleaseMemory.Bits((float)m.Read8(packet+0xb5));}
  public static uint BindIdentity(TakeoverReleaseMemory m,ScriptIdentityBindingServices s,uint system,uint name){if(name==0)return 0;uint callback=m.Read32(0x923904);return callback==0?0:s.Resolve(m,callback,system,name);}
  public static uint IAm(TakeoverReleaseMemory m,uint actor,uint arg14,uint arg18){if(actor==0)return 0;uint controller=m.Read32(actor+0xd0);if(controller==0)return 0;if(controller==arg18)return 0x3f800000;uint identity=m.Read32(controller+0x54);if(identity==0)return 0;uint name=m.Read32(identity+0xc);return Bool(name!=0&&arg14!=0&&PreparedConditionLoading.Equal(m,name,arg14));}
  public static uint StuckTime(TakeoverReleaseMemory m,uint actor){if(actor==0)return 0;uint controller=m.Read32(actor+0xd0);return controller==0?0:Stored(m.Read32(controller+0x1d8));}
  public static uint OpponentIsAThreat(TakeoverReleaseMemory m,uint actor){return Bool(actor!=0&&m.Read32(actor+0xe4)!=0&&(m.Read32(actor+0x1e8)&0x800)!=0);}
  public static uint OpponentOnSamePath(TakeoverReleaseMemory m,uint actor){if(actor==0)return 0;uint reference=m.Read32(actor+0xe4);if(reference==0)return 0;uint path=m.Read32(actor+0x158);if(path==0)return 0;uint controller=m.Read32(reference+4);return Bool(controller!=0&&m.Read32(controller+0x158)==path);}
  public static bool TryEvaluate(TakeoverReleaseMemory m,uint callback,uint packet,uint actor,uint arg14,uint arg18,out uint value){switch(callback){case 0x5156f0:value=PathBlocked(m,actor);break;case 0x515710:value=InterruptID(m,packet);break;case 0x515750:value=IAm(m,actor,arg14,arg18);break;case 0x515790:value=StuckTime(m,actor);break;case 0x5151e0:value=OpponentIsAThreat(m,actor);break;case 0x515210:value=OpponentOnSamePath(m,actor);break;default:value=0;return false;}return true;}
 }
 public sealed class RecoveredActorConditionServices:ScriptConditionServices
 {
  readonly ScriptConditionServices remaining;public RecoveredActorConditionServices(ScriptConditionServices other){remaining=other;}
  public override uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint arg14,uint arg18){uint value;if(PreparedScriptActorPredicates.TryEvaluate(m,callback,packet,actor,arg14,arg18,out value))return value;if(remaining==null)throw new NotSupportedException("Unrecovered predicate.");return remaining.Predicate(m,callback,system,packet,actor,arg14,arg18);}
  public override uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint text){return remaining.Expression(m,actor,packet,text);}
 }
}
