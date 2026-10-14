// Compact raw builtin predicates for actual condition callbacks; pointer chains remain live.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedBuiltinPredicates
 {
  static uint Stored(uint bits){if((bits&0x7f800000)==0x7f800000&&(bits&0x7fffff)!=0&&(bits&0x400000)==0)throw new ArgumentException("Signaling NaN stores/status outside paired predicate domain.");return bits;}
  static uint Bool(bool value){return value?0x3f800000u:0;}
  public static uint Timer(TakeoverReleaseMemory m,uint packet){return Stored(m.Read32(packet+0x24));}
  public static uint Random(TakeoverReleaseMemory m){uint state=unchecked(m.Read32(0x95e5d4)*0x19660d+0x3c6ef35f);m.Write32(0x95e5d4,state);return TakeoverReleaseMemory.Bits((state&0x7fffff)/8388608f);}
  public static uint AlwaysTrue(uint fifthArgumentBits){return Stored(fifthArgumentBits);}
  public static uint GotLocator(TakeoverReleaseMemory m,uint packet){return Bool(m.Read32(packet+0xa4)!=0);}
  public static uint GotLocatorSet(TakeoverReleaseMemory m,uint packet){return Bool(m.Read32(packet+0xa8)!=0);}
  public static uint OnPath(TakeoverReleaseMemory m,uint actor){return Bool(actor!=0&&(m.Read8(actor+0x166)&1)!=0);}
  public static uint PlayerOnPath(TakeoverReleaseMemory m,uint system){uint reference=m.Read32(system+0x138c);return Bool(reference!=0&&(m.Read8(m.Read32(reference+4)+0x166)&1)!=0);}
  public static uint OpponentOnPath(TakeoverReleaseMemory m,uint actor){if(actor==0)return 0;uint reference=m.Read32(actor+0xe4);return Bool(reference!=0&&(m.Read8(m.Read32(reference+4)+0x166)&1)!=0);}
  public static uint TimeOffPath(TakeoverReleaseMemory m,uint actor){return actor==0?0:Stored(m.Read32(actor+0x208));}
  public static uint CurrentLocatorIs(TakeoverReleaseMemory m,uint packet,uint fifthArgument){return Bool(fifthArgument!=0&&m.Read32(packet+0xa4)==fifthArgument);}
  public static uint GotTriggerArea(TakeoverReleaseMemory m,uint packet){return Bool(m.Read32(packet+0xa0)!=0);}
  public static uint GotOpponent(TakeoverReleaseMemory m,uint actor){return Bool(actor!=0&&m.Read32(actor+0xe4)!=0);}
  public static uint Param(TakeoverReleaseMemory m,ScriptExpressionServices symbols,uint packet,uint actor,uint fourthArgumentText){return PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,fourthArgumentText);}
  // Native callbacks share cdecl(system,packet,actor,condition14,condition18), ST0 result.
  public static bool TryEvaluate(TakeoverReleaseMemory m,ScriptExpressionServices symbols,uint callback,uint system,uint packet,uint actor,uint arg14,uint arg18,out uint result)
  {switch(callback){case 0x514990:result=Timer(m,packet);break;case 0x5149a0:result=Random(m);break;case 0x5149f0:result=AlwaysTrue(arg18);break;case 0x514ae0:result=GotLocator(m,packet);break;case 0x514b00:result=GotLocatorSet(m,packet);break;case 0x514b20:result=OnPath(m,actor);break;case 0x514b40:result=PlayerOnPath(m,system);break;case 0x514b60:result=OpponentOnPath(m,actor);break;case 0x514b90:result=TimeOffPath(m,actor);break;case 0x514bb0:result=CurrentLocatorIs(m,packet,arg18);break;case 0x514f90:result=GotTriggerArea(m,packet);break;case 0x5151c0:result=GotOpponent(m,actor);break;case 0x5157b0:result=Param(m,symbols,packet,actor,arg14);break;default:result=0;return false;}return true;}
 }
 public sealed class RecoveredBuiltinConditionServices:ScriptConditionServices
 {
  readonly ScriptConditionServices remaining;readonly ScriptExpressionServices symbols;public RecoveredBuiltinConditionServices(ScriptConditionServices otherPredicates,ScriptExpressionServices gameSymbols){remaining=otherPredicates;symbols=gameSymbols;}
  public override uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint arg14,uint arg18){uint result;if(PreparedBuiltinPredicates.TryEvaluate(m,symbols,callback,system,packet,actor,arg14,arg18,out result))return result;if(remaining==null)throw new NotSupportedException("Unrecovered predicate "+callback.ToString("x"));return remaining.Predicate(m,callback,system,packet,actor,arg14,arg18);}
  public override uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint text){return PreparedScriptExpressions.Evaluate(m,symbols,actor,packet,text);}
 }
}
