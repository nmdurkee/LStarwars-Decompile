// Cached opponent distance predicates; presence words are never dereferenced.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptCachedRanges
 {
  static uint Stored(uint bits){if((bits&0x7f800000)==0x7f800000&&(bits&0x7fffff)!=0&&(bits&0x400000)==0)throw new ArgumentException("Signaling NaN store outside paired domain.");return bits;}
  public static uint Opponent(TakeoverReleaseMemory m,uint actor){return Stored(actor!=0&&m.Read32(actor+0xe4)!=0?m.Read32(actor+0xe8):m.Read32(0x75ecf0));}
  public static uint NearestOpponent(TakeoverReleaseMemory m,uint actor){return Stored(actor!=0&&m.Read32(actor+0xd4)!=0?m.Read32(actor+0xd8):m.Read32(0x75ecf0));}
 }
 public sealed class RecoveredCachedRangeConditions:ScriptConditionServices
 {
  readonly ScriptConditionServices remaining;public RecoveredCachedRangeConditions(ScriptConditionServices other){remaining=other;}
  public override uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint arg14,uint arg18){if(callback==0x515250)return PreparedScriptCachedRanges.Opponent(m,actor);if(callback==0x515270)return PreparedScriptCachedRanges.NearestOpponent(m,actor);return remaining.Predicate(m,callback,system,packet,actor,arg14,arg18);}
  public override uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint text){return remaining.Expression(m,actor,packet,text);}
 }
}
