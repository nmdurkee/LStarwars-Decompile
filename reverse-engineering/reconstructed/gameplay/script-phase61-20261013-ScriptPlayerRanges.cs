// Raw player/nearest-player ranges preserve live controller reread, squared-distance comparison and max-float sentinel.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptPlayerRanges
 {
  static SpawnVector Vector(TakeoverReleaseMemory m,uint p){float x=m.Float(p),y=m.Float(p+4),z=m.Float(p+8);if(float.IsNaN(x)||float.IsInfinity(x)||float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(z)||float.IsInfinity(z))throw new ArgumentException("Finite player coordinates required.");return new SpawnVector(x,y,z);}
  static float Square(TakeoverReleaseMemory m,uint a,uint b,bool xz){float s=LocatorCommands.DistanceSquared(Vector(m,a),Vector(m,b),xz);if(float.IsNaN(s)||float.IsInfinity(s))throw new ArgumentException("Finite player squared distance required.");return s;}
  public static uint Player(TakeoverReleaseMemory m,uint system,uint actor){if(actor==0)return m.Read32(0x75ecf0);uint controller=m.Read32(actor+0xd0);if(controller==0||system==0)return m.Read32(0x75ecf0);uint player=m.Read32(system+0x138c);if(player==0)return m.Read32(0x75ecf0);return TakeoverReleaseMemory.Bits((float)Math.Sqrt(Square(m,player+0x5c,controller+0x5c,false)));}
  public static uint Nearest(TakeoverReleaseMemory m,uint system,uint actor,bool xz){uint fallback=m.Read32(0x75ecf0);if(actor==0)return fallback;uint controller=m.Read32(actor+0xd0);if(controller==0||system==0)return fallback;float best=BitConverter.ToSingle(BitConverter.GetBytes(fallback),0);uint player=m.Read32(system+0x138c);if(player!=0)best=Square(m,player+0x5c,controller+0x5c,xz);player=m.Read32(system+0x1390);if(player!=0){float other=Square(m,player+0x5c,m.Read32(actor+0xd0)+0x5c,xz);if(other<best)best=other;}double sentinel=BitConverter.Int64BitsToDouble(unchecked((long)(((ulong)m.Read32(0x76000c)<<32)|m.Read32(0x760008))));return TakeoverReleaseMemory.Bits((double)best==sentinel?best:(float)Math.Sqrt(best));}
 }
}
