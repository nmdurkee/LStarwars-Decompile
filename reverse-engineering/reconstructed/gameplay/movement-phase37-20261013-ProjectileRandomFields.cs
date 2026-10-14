using System;
namespace Recovered.Gameplay
{
 public static class ProjectileRandomFields
 {
  static uint Step(OriginPathMemory m,uint random){uint value=unchecked(m.U32(random)*1664525u+1013904223u);m.Set32(random,value);return value;}
  static long SignedNumerator(uint value){return(long)(value&0x7fffffu)*2-8388608L;}
  // 64a740. Rejected second selector consumes only its integer RNG step.
  public static void Axes(OriginPathMemory m,uint projectile,uint random)
  {
   int slot=0,guard=0;while(slot<2)
   {
    if(++guard>10000)throw new InvalidOperationException("Random selector outside prepared terminating domain.");uint value=Step(m,random);m.Set8(projectile+0x142+(uint)slot,(byte)((value%65535u)/21845u+1));if(slot==1&&m.U8(projectile+0x143)==m.U8(projectile+0x142))continue;
    // Native computes (2*fraction-1)*65536 in x87, then truncates.
    // Both operations are exact dyadic arithmetic; integer division preserves truncation.
    value=Step(m,random);m.Set32(projectile+0x130+(uint)slot*4,unchecked((uint)(SignedNumerator(value)/128L)));slot++;
   }
  }
  // 64a7c0. Signed integer amplitudes are read after their RNG advance.
  public static void Offsets(OriginPathMemory m,uint projectile,uint random)
  {
   for(uint j=0;j<3;j++){uint value=Step(m,random);int amplitude=unchecked((int)m.U32(projectile+0x118+j*4));long displacement=SignedNumerator(value)*amplitude/8388608L;m.Set32(projectile+0x124+j*4,unchecked((uint)displacement+m.U32(projectile+0x10c+j*4)));}
  }
 }
}
