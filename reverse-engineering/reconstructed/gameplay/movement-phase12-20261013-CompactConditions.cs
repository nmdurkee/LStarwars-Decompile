using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class CompactRuntimeConditions
 {
  static float Distance(OriginPathMemory m,uint a,uint b){float[] p=m.Vector(a),q=m.Vector(b);return LocatorRandomConditions.Distance(new SpawnVector(p[0],p[1],p[2]),new SpawnVector(q[0],q[1],q[2]));}
  public static float TakeOverRange(OriginPathMemory m,uint creature)
  {
   if(creature==0)return PcObjectImage.FromBits(0x4e6e6b28);uint reference=m.U32(creature+0xd0);if(reference==0)return PcObjectImage.FromBits(0x4e6e6b28);uint actor=m.U32(reference);if(actor==0)return PcObjectImage.FromBits(0x4e6e6b28);uint target=m.U32(actor+0xea4);return target==0?PcObjectImage.FromBits(0x4e6e6b28):Distance(m,target+0x5c,reference+0x5c);
  }
  public static float StuckTime(OriginPathMemory m,uint creature){if(creature==0)return 0;uint reference=m.U32(creature+0xd0);return reference==0?0:m.F32(reference+0x1d8);}
  public static float TurretAlive(OriginPathMemory m,uint turret){return turret==0||(m.U8(turret+0x13a)&0x30)!=0?0:1;}
  public static float CheatProgress(){return 0;}
  public static float OpponentToLocatorY(OriginPathMemory m,uint packet,uint creature,uint locator)
  {
   if(creature==0)return PcObjectImage.FromBits(0x7f7fffff);uint opponent=m.U32(creature+0xe4);if(opponent==0)return PcObjectImage.FromBits(0x7f7fffff);if(locator==0){locator=m.U32(packet+0xa4);if(locator==0)return PcObjectImage.FromBits(0x7f7fffff);}return(float)(m.F32(opponent+0x60)-m.F32(locator+0x14));
  }
 }
}
