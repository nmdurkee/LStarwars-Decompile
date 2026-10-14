using System;
namespace Recovered.Gameplay
{
 public sealed class PodProjectileEffectWorld
 {
  public OriginPathMemory Memory;
  public uint World;
  public short ParticleId;
  public int SoundId;
  public Action<uint,int,uint> Particle;
  public Action<int,uint,int> Sound;
 }
 public static class PodProjectileEffects
 {
  // 4d9710: particle ID is signed16, while the independent sound ID is signed32.
  public static void Publish(PodProjectileEffectWorld w,uint projectile)
  {
   short particle=w.ParticleId;uint position=unchecked(projectile+0x30);
   if(particle!=-1)w.Particle(w.Memory.U32(w.World+0x134),particle,position);
   int sound=w.SoundId;if(sound!=-1)w.Sound(sound,position,1);
  }
 }
}
