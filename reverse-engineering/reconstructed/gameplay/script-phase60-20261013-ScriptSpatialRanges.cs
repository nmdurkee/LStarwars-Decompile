// Raw locator3D/XZ and level-node ranges compose existing finite x87 distance helpers.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptSpatialRanges
 {
  static SpawnVector Vector(TakeoverReleaseMemory m,uint p){float x=m.Float(p),y=m.Float(p+4),z=m.Float(p+8);if(float.IsNaN(x)||float.IsInfinity(x)||float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(z)||float.IsInfinity(z))throw new ArgumentException("Finite distance coordinates required.");return new SpawnVector(x,y,z);}
  static uint Distance(TakeoverReleaseMemory m,uint a,uint b,bool xz){float square=LocatorCommands.DistanceSquared(Vector(m,a),Vector(m,b),xz);if(float.IsNaN(square)||float.IsInfinity(square))throw new ArgumentException("Finite squared distance required.");return TakeoverReleaseMemory.Bits((float)Math.Sqrt(square));}
  static uint Fallback(TakeoverReleaseMemory m){return m.Read32(0x75ecf0);}
  public static uint LocatorRange(TakeoverReleaseMemory m,uint packet,uint actor,uint bound,bool xz){if(actor==0||m.Read32(actor+0xd0)==0)return Fallback(m);uint locator=bound;if(locator==0){locator=m.Read32(packet+0xa4);if(locator==0)return Fallback(m);}return Distance(m,actor+0x14c,locator+0x10,xz);}
  public static uint NodeRange(TakeoverReleaseMemory m,uint actor,uint bound){if(actor==0)return Fallback(m);uint controller=m.Read32(actor+0xd0);if(controller==0||bound==0)return Fallback(m);return Distance(m,bound+4,controller+0x5c,false);}
 }
}
