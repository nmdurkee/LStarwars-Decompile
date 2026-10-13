using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class RuntimeReaderWorld
 {
  public OriginPathMemory Memory;
  public uint GlobalWorld;
  public byte MusicState;
 }
 public static class RuntimeStateReaders
 {
  //0x443390: null creature/reference gives1e9; null reference's object pointer faults.
  public static float LastAttackerRange(RuntimeReaderWorld w,uint creature)
  {
   if(creature==0)return PcObjectImage.FromBits(0x4e6e6b28);OriginPathMemory m=w.Memory;uint reference=m.U32(creature+0xd0);if(reference==0)return PcObjectImage.FromBits(0x4e6e6b28);
   uint actor=m.U32(reference);uint attacker=m.U32(actor+0x10a8);if(attacker==0)return PcObjectImage.FromBits(0x4e6e6b28);
   float[] a=m.Vector(actor+0x5c),b=m.Vector(attacker+0x5c);return LocatorRandomConditions.Distance(new SpawnVector(a[0],a[1],a[2]),new SpawnVector(b[0],b[1],b[2]));
  }
  //0x442d10: world is dereferenced before any creature guard; reference carries index.
  public static float HelpWithTriggers(RuntimeReaderWorld w,uint creature)
  {
   OriginPathMemory m=w.Memory;uint physics=m.U32(w.GlobalWorld+0x4678);if(physics==0||creature==0)return 0;uint reference=m.U32(creature+0xd0);if(reference==0)return 0;uint index=m.U8(reference+0x28d);
   if(m.U8(physics+0x42c0+index)==255)return 0;
   int block=unchecked((sbyte)m.U8(physics+0x4280+index));uint p=unchecked(physics+(uint)(block*0x214)+0x20e);
   return(m.U8(p)|m.U8(p+1)<<8)==0?0:1;
  }
  //0x443dc0: raw nonzero music byte, no actor/system gate.
  public static float MusicOn(RuntimeReaderWorld w){return w.MusicState==0?0:1;}
 }
}
