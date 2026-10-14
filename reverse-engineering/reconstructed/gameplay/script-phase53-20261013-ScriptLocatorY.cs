// Raw locator Y-offset predicate and nullable locator name-binding initializer.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class ScriptLocatorBindingServices{public abstract uint Find(TakeoverReleaseMemory m,uint system,uint name);}
 public static class PreparedScriptLocatorPredicates
 {
  public static uint Bind(TakeoverReleaseMemory m,ScriptLocatorBindingServices s,uint system,uint name){return name==0?0:s.Find(m,system,name);}
  public static uint RangeY(TakeoverReleaseMemory m,uint packet,uint actor,uint bound){if(actor==0)return 0;uint controller=m.Read32(actor+0xd0);if(controller==0)return 0;uint locator=bound;if(locator==0){locator=m.Read32(packet+0xa4);if(locator==0)return 0;}float y=m.Float(controller+0x60),target=m.Float(locator+0x14);if(float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(target)||float.IsInfinity(target))throw new ArgumentException("Finite Y-offset arithmetic required.");if(TakeoverReleaseMemory.Bits(y)==0x80000000&&TakeoverReleaseMemory.Bits(target)==0)return 0x80000000;return TakeoverReleaseMemory.Bits(PlaybackWide.Add(PlaybackWide.From(y),PlaybackWide.Multiply(PlaybackWide.From(target),PlaybackWide.From(-1f))).Store());}
 }
}
