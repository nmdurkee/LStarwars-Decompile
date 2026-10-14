// Player-to-locator callbacks gate only actor-pointer presence, then raw player references and minimum squared ranges.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptPlayerLocator
 {
  static SpawnVector Vector(TakeoverReleaseMemory m,uint p){float x=m.Float(p),y=m.Float(p+4),z=m.Float(p+8);if(float.IsNaN(x)||float.IsInfinity(x)||float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(z)||float.IsInfinity(z))throw new ArgumentException("Finite player-locator coordinates required.");return new SpawnVector(x,y,z);}
  static float Square(TakeoverReleaseMemory m,uint player,uint locator){float s=LocatorCommands.DistanceSquared(Vector(m,player+0x5c),Vector(m,locator+0x10),false);if(float.IsNaN(s)||float.IsInfinity(s))throw new ArgumentException("Finite squared range required.");return s;}
  public static uint Player(TakeoverReleaseMemory m,uint system,uint packet,uint actor,uint bound){if(actor==0||system==0)return m.Read32(0x75ecf0);uint player=m.Read32(system+0x138c);if(player==0)return m.Read32(0x75ecf0);uint locator=bound!=0?bound:m.Read32(packet+0xa4);return locator==0?m.Read32(0x75ecf0):TakeoverReleaseMemory.Bits((float)Math.Sqrt(Square(m,player,locator)));}
  public static uint Nearest(TakeoverReleaseMemory m,uint system,uint packet,uint actor,uint bound){uint fallback=m.Read32(0x75ecf0);if(actor==0||system==0)return fallback;float best=BitConverter.ToSingle(BitConverter.GetBytes(fallback),0);uint locator=bound!=0?bound:m.Read32(packet+0xa4);if(locator!=0){uint player=m.Read32(system+0x138c);if(player!=0)best=Square(m,player,locator);player=m.Read32(system+0x1390);if(player!=0){float other=Square(m,player,locator);if(other<best)best=other;}}double sentinel=BitConverter.Int64BitsToDouble(unchecked((long)(((ulong)m.Read32(0x76000c)<<32)|m.Read32(0x760008))));return TakeoverReleaseMemory.Bits((double)best==sentinel?best:(float)Math.Sqrt(best));}
 }
}
