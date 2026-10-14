// Opponent-to-locator variants read the raw opponent reference directly; all missing-target paths return max-float.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptOpponentLocator
 {
  static SpawnVector Vector(TakeoverReleaseMemory m,uint p){float x=m.Float(p),y=m.Float(p+4),z=m.Float(p+8);if(float.IsNaN(x)||float.IsInfinity(x)||float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(z)||float.IsInfinity(z))throw new ArgumentException("Finite opponent coordinates required.");return new SpawnVector(x,y,z);}
  public static uint Evaluate(TakeoverReleaseMemory m,uint packet,uint actor,uint bound,int mode){if(mode<0||mode>2)throw new ArgumentException("Range mode0=3D,1=XZ,2=Y required.");if(actor==0)return m.Read32(0x75ecf0);uint opponent=m.Read32(actor+0xe4);if(opponent==0)return m.Read32(0x75ecf0);uint locator=bound;if(locator==0){locator=m.Read32(packet+0xa4);if(locator==0)return m.Read32(0x75ecf0);}if(mode==2){float y=m.Float(opponent+0x60),target=m.Float(locator+0x14);if(float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(target)||float.IsInfinity(target))throw new ArgumentException("Finite Y offset required.");if(TakeoverReleaseMemory.Bits(y)==0x80000000&&TakeoverReleaseMemory.Bits(target)==0)return 0x80000000;return TakeoverReleaseMemory.Bits(PlaybackWide.Add(PlaybackWide.From(y),PlaybackWide.Multiply(PlaybackWide.From(target),PlaybackWide.From(-1f))).Store());}float square=LocatorCommands.DistanceSquared(Vector(m,opponent+0x5c),Vector(m,locator+0x10),mode==1);if(float.IsNaN(square)||float.IsInfinity(square))throw new ArgumentException("Finite squared range required.");return TakeoverReleaseMemory.Bits((float)Math.Sqrt(square));}
 }
}
