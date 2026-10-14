// Origin-range callbacks preserve optional923908 override and live per-actor fallback selector/system records.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptOriginServices{public abstract uint Origin(TakeoverReleaseMemory m,uint callback,uint system,uint actor);}
 public static class PreparedScriptOriginRanges
 {
  static SpawnVector Vector(TakeoverReleaseMemory m,uint p){float x=m.Float(p),y=m.Float(p+4),z=m.Float(p+8);if(float.IsNaN(x)||float.IsInfinity(x)||float.IsNaN(y)||float.IsInfinity(y)||float.IsNaN(z)||float.IsInfinity(z))throw new ArgumentException("Finite origin coordinates required.");return new SpawnVector(x,y,z);}
  static uint Distance(TakeoverReleaseMemory m,uint p,uint origin){float square=LocatorCommands.DistanceSquared(Vector(m,p),Vector(m,origin),false);if(float.IsNaN(square)||float.IsInfinity(square))throw new ArgumentException("Finite squared origin distance required.");return TakeoverReleaseMemory.Bits((float)Math.Sqrt(square));}
  static uint Choose(TakeoverReleaseMemory m,ScriptOriginServices s,uint system,uint actor){uint callback=m.Read32(0x923908);if(callback!=0){uint origin=s.Origin(m,callback,system,actor);if(origin!=0)return origin;}if(system==0)return 0;byte selector=m.Read8(actor+0x138);return selector==255?0:m.Read32(system+0x18)+(uint)selector*0xa4+0x20;}
  public static uint OriginRange(TakeoverReleaseMemory m,ScriptOriginServices s,uint system,uint actor){if(actor==0)return 0;uint origin=Choose(m,s,system,actor);return origin==0?0:Distance(m,actor+0x14c,origin);}
  public static uint OpponentToOrigin(TakeoverReleaseMemory m,ScriptOriginServices s,uint system,uint actor){if(actor==0||m.Read32(actor+0xe4)==0)return m.Read32(0x75ecf0);uint origin=Choose(m,s,system,actor);return origin==0?m.Read32(0x75ecf0):Distance(m,m.Read32(actor+0xe4)+0x5c,origin);}
  public static uint PlayerToOrigin(TakeoverReleaseMemory m,ScriptOriginServices s,uint system,uint actor){if(actor==0||system==0||m.Read32(system+0x138c)==0)return m.Read32(0x75ecf0);uint origin=Choose(m,s,system,actor);return origin==0?m.Read32(0x75ecf0):Distance(m,m.Read32(system+0x138c)+0x5c,origin);}
 }
}
