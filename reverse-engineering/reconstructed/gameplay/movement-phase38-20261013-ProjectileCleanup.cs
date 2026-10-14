using System;
namespace Recovered.Gameplay
{
 public sealed class ProjectileCleanupWorld
 {
  public OriginPathMemory Memory;
  public Action<uint> ReleaseEmitter,ReleaseLink;
  public Action<uint,uint,int> Callback;
  public Action<uint,int,uint,uint,uint,uint,uint> Audio;
 }
 public static class ProjectileCleanup
 {
  // 64ac90; lifecycle services may mutate the object between each fresh read.
  public static void Release(ProjectileCleanupWorld w,uint projectile,int reason,uint scratch)
  {
   var m=w.Memory;uint flags=m.U32(projectile+0x144);if((flags&1)==0)return;m.Set32(projectile+0x144,flags&0xfffffffeu);
   if((m.U32(projectile+0x108)&0x20000)!=0){uint emitter=m.U32(projectile+0x1d8);if(emitter!=0)w.ReleaseEmitter(emitter);}
   uint link=m.U32(projectile+0x1dc);if(link!=0){w.ReleaseLink(m.U32(link));link=m.U32(projectile+0x1dc);m.Set32(link,0xffffffff);}
   uint callback=m.U32(projectile+0x1c0);if(callback!=0)w.Callback(callback,projectile,reason);
   if(reason==6)return;int sound=unchecked((int)m.U32(projectile+0x1f4));if(sound==-1)return;uint gain=m.U32(projectile+0x1fc);m.Set32(scratch,0xffffffff);w.Audio(scratch,sound,projectile+0x30,0,0,1,gain);
  }
 }
}
