// Original takeover cleanup bodies, plus ordered prepared-memory55e4e0 reset projection.
// Existing PathRelocation.ResetControls retains its owned-image API; no duplicate credit.
using System;
namespace Recovered.Gameplay
{
 public abstract class TakeoverCleanupServices
 {
  public abstract void FinishAction(TakeoverReleaseMemory m,uint actor,uint mode);
  public abstract void Camera(TakeoverReleaseMemory m,uint camera,float duration,float blend,uint mode);
 }
 public static class TakeoverCleanup
 {
  static int Context(TakeoverReleaseMemory m,uint actor){return unchecked((sbyte)m.Read8(actor+0x7b5));}
  static int Signed(uint v){return unchecked((int)v);}
  static uint Add(uint p,int v){return unchecked(p+(uint)v);}
  // 4a25b0: cached context selects8/27/29; callback mutations do not change selection.
  public static void ClearAction(TakeoverReleaseMemory m,TakeoverCleanupServices services,uint actor,uint mode)
  {
   int context=Context(m,actor);
   if(context==8){if((m.Read8(actor+0x1fc)&0x80)!=0)services.Camera(m,m.Read32(0x8021b4),1,0,1);services.FinishAction(m,actor,mode);}
   else if(context==27){uint linked=m.Read32(actor+0x790);if(linked!=0){if(m.Read8(linked+0x7b5)==28){m.Write8(linked+0x7b5,255);m.Write32(linked+0x790,0);}m.Write32(actor+0x790,0);}services.FinishAction(m,actor,mode);}
   else if(context==29)
   {
    uint gizmo=m.Read32(actor+0xcb8);
    if(gizmo!=0){int shift=m.Read8(actor+0x280)&31;byte mask=(byte)(1u<<shift);m.Write8(gizmo+0x206,(byte)(m.Read8(gizmo+0x206)&~mask));gizmo=m.Read32(actor+0xcb8);if(m.Read8(gizmo+0x206)==0)m.Write8(gizmo+0x206,255);gizmo=m.Read32(actor+0xcb8);float timer=m.Float(0x7fb084);if(Single.IsNaN(timer)||Single.IsInfinity(timer))throw new ArgumentOutOfRangeException("finite cleanup timer backing");m.Write32(gizmo+0xe8,m.Read32(0x7fb084));m.Write32(actor+0xcb8,0);}
    m.Write8(actor+0x7b5,255);services.FinishAction(m,actor,mode);
   }
  }
  // 58ff10 compares signed context to a full32-bit global; sentinel guards actor read.
  public static void ResetActor(TakeoverReleaseMemory m,TakeoverCleanupServices services,uint actor,uint mode)
  {int configured=Signed(m.Read32(0x802860));if(configured==-1)return;if(Context(m,actor)!=configured)return;m.Write8(actor+0x7b5,255);services.Camera(m,m.Read32(0x8021b4),.5f,mode!=0?BitConverter.ToSingle(BitConverter.GetBytes(0x3f19999au),0):0,1);}
  // 59cb00: table lookup is unchecked and precedes all clear/camera writes.
  public static void StopActor(TakeoverReleaseMemory m,TakeoverCleanupServices services,uint actor)
  {uint registry=m.Read32(0x7fb0e4);int context=Context(m,actor);if((m.Read32(Add(registry,context*16+8))&0x2000)==0)return;int configured=Signed(m.Read32(0x802854));if(configured!=-1&&context==configured)services.Camera(m,0,.5f,0,1);m.Write8(actor+0x7b5,255);m.Write32(actor+0xdc4,0);}
  // 58d8e0: only non-sentinel context can match globals; mandatory tail always runs.
  public static void PrepareActor(TakeoverReleaseMemory m,uint actor)
  {int context=Context(m,actor);if(context!=-1&&(context==Signed(m.Read32(0x802864))||context==Signed(m.Read32(0x802868))))m.Write8(actor+0x7b5,255);m.Write32(actor+0xe20,m.Read32(actor+0xe20)&0xfffeffff);m.Write32(actor+0xd3c,0);m.Write8(actor+0xe33,0);}
  // 55e4e0 receives actor+6c4. Pointer cache/re-read and pre-RNG fault order matter.
  public static void ResetControls(TakeoverReleaseMemory m,uint p)
  {
   bool held=(m.Read8(p+0x75e)&1)!=0;m.Write32(p+0xfc,0);m.Write8(p+0x100,255);m.Write32(p+0x678,held?0x3f800000u:0);uint pad=m.Read32(p+0x5e0);m.Write32(p+0x67c,0x40a00000);m.Write8(p+0x76f,0);m.Write32(p+0x66c,0);m.Write8(p+0xf1,255);m.Write32(p+0x674,0);m.Write8(p+0xf5,0);m.Write32(p+0x664,0);m.Write8(p+0xf4,0);
   m.Write16(pad+0x5a,(ushort)(m.Read16(pad+0x5a)&0xfffb));pad=m.Read32(p+0x5e0);m.Write16(pad+0x5a,(ushort)(m.Read16(pad+0x5a)&0xffef));m.Write32(p+0x75c,m.Read32(p+0x75c)&0xfffffbff);m.Write32(p+0x65c,0);m.Write32(p+0x648,0);
   QRandom rng=new QRandom{State=m.Read32(0x80253c)};uint draw=rng.Next();m.Write32(0x80253c,draw);m.Write32(p+0x694,0);m.Write32(p+0x698,0);m.Write32(p+0x670,0);m.Write32(p+0x6d0,0);m.Write32(p+0x6e8,0);m.Write8(p+0x77d,(byte)(draw>>15));m.Write32(p+0x700,0);m.Write32(p+0x714,0);m.Write16(p+0xe8,0);m.Write32(p+0x720,0);m.Write8(p+0xee,0);m.Write8(p+0x76e,0);m.Write32(p+0x724,0);m.Write32(p+0x60c,0);m.Write16(p+0x74c,65535);m.Write16(p+0x750,65535);m.Write16(p+0x752,65535);
  }
 }
 // Fresh adapter composes cleanup into immutable phase13 pipeline; other ports remain.
 public sealed class RecoveredCleanupPipelinePorts:TakeoverPipelinePorts
 {
  readonly TakeoverPipelinePorts remaining;readonly TakeoverCleanupServices cleanup;
  public RecoveredCleanupPipelinePorts(TakeoverPipelinePorts remaining,TakeoverCleanupServices cleanup){this.remaining=remaining;this.cleanup=cleanup;}
  public override void ClearAction(TakeoverReleaseMemory m,uint a){TakeoverCleanup.ClearAction(m,cleanup,a,0);}
  public override void ResetActor(TakeoverReleaseMemory m,uint a){TakeoverCleanup.ResetActor(m,cleanup,a,0);}
  public override void StopActor(TakeoverReleaseMemory m,uint a){TakeoverCleanup.StopActor(m,cleanup,a);}
  public override void ResetAnimation(TakeoverReleaseMemory m,uint p){TakeoverCleanup.ResetControls(m,p);}
  public override void PrepareActor(TakeoverReleaseMemory m,uint a){TakeoverCleanup.PrepareActor(m,a);}
  public override void Rebind(TakeoverReleaseMemory m,uint a){remaining.Rebind(m,a);}
  public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return remaining.ChangeTakenOverState(m,p);}
  public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return remaining.ChangeReleasedState(m,p);}
  public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){remaining.RunScript(m,s,a,p,d);}
  public override void VehicleResponse(TakeoverReleaseMemory m,uint v,uint a){remaining.VehicleResponse(m,v,a);}
  public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return remaining.DistanceFactor(m,p,t);}
  public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){remaining.DirectedJump(m,a,t,s,d);}
  public override void Camera(TakeoverReleaseMemory m,uint c,float d){remaining.Camera(m,c,d);}
 }
}
