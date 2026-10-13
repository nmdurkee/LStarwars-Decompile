// Original camera transition and controller request wrappers. Driver remains an explicit port.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class ControllerRequestPort {public abstract void Request(TakeoverReleaseMemory m,uint controller,uint firstBits,uint amount,uint fourthBits,uint durationBits);}
 public static class CleanupEffects
 {
  static uint Quiet(uint bits){if((bits&0x7f800000)==0x7f800000&&(bits&0x7fffff)!=0&&(bits&0x400000)==0)throw new ArgumentOutOfRangeException("Signaling NaN float-store behavior is outside the verified move contract");return bits;}
  // 54a3e0: default pointer is resolved before the positive-duration gate. Ordered loads/stores retain partial faults.
  public static void Transition(TakeoverReleaseMemory m,uint camera,float duration,float blend,uint mode)
  {
   if(camera==0)camera=m.Read32(0x8021b4);if(!(duration>0)||m.Read8(camera+0x22c)==255)return;
   ushort one=m.Read16(camera+0x21e),two=m.Read16(camera+0x222);m.Write32(camera+0x1c4,Quiet(TakeoverReleaseMemory.Bits(blend)));m.Write16(camera+0x21c,one);m.Write32(camera+0x1bc,0);
   ushort three=m.Read16(camera+0x226);m.Write32(camera+0x1c0,TakeoverReleaseMemory.Bits(duration));m.Write16(camera+0x220,two);m.Write16(camera+0x224,three);byte state=m.Read8(camera+0x22d);m.Write8(camera+0x22b,(byte)(mode!=0?2:1));
   uint x=m.Read32(camera+0x140);m.Write8(camera+0x22e,state);uint y=m.Read32(camera+0x144);m.Write32(camera+0x134,x);uint z=m.Read32(camera+0x148);m.Write32(camera+0x138,y);uint px=m.Read32(camera+0x128);m.Write32(camera+0x164,px);uint pz=m.Read32(camera+0x130);m.Write32(camera+0x13c,z);uint py=m.Read32(camera+0x12c);m.Write32(camera+0x168,py);x=m.Read32(camera+0x140);m.Write32(camera+0x16c,pz);
   y=m.Read32(camera+0x144);m.Write32(camera+0x14c,x);z=m.Read32(camera+0x148);m.Write32(camera+0x150,y);px=m.Read32(camera+0x128);m.Write32(camera+0x17c,px);pz=m.Read32(camera+0x130);m.Write32(camera+0x154,z);py=m.Read32(camera+0x12c);m.Write32(camera+0x180,py);m.Write8(camera+0x22a,1);m.Write32(camera+0x184,pz);
  }
  // 54a850: mode argument from callers is unused. Nonnull controller gates all conversion.
  // Native 6e6b90 SSE/qword and legacy conversion produce the same finite Int32 result here.
  public static void Feedback(TakeoverReleaseMemory m,ControllerRequestPort port,uint controller,float duration)
  {
   if(controller==0)return;PlaybackWide scaled=PlaybackWide.Multiply(PlaybackWide.From(duration),PlaybackWide.FromDouble(255));m.Read32(0x29a9c48);int amount=scaled.TruncateInt32();if(amount>255)amount=255;port.Request(m,controller,0,unchecked((uint)amount),0,TakeoverReleaseMemory.Bits(duration));
  }
  // 54a8a0: nonnull controller sends the supplied scalar in the first float slot, with remaining slots zero.
  public static void Forward(TakeoverReleaseMemory m,ControllerRequestPort port,uint controller,float value)
  {if(controller!=0)port.Request(m,controller,Quiet(TakeoverReleaseMemory.Bits(value)),0,0,0);}
 }
 public sealed class RecoveredCleanupEffectServices:VehicleResponseServices
 {
  readonly VehicleResponseServices remaining;readonly ControllerRequestPort controller;
  public RecoveredCleanupEffectServices(VehicleResponseServices remaining,ControllerRequestPort controller){this.remaining=remaining;this.controller=controller;}
  public override void Feedback(TakeoverReleaseMemory m,uint input,float duration,uint mode){CleanupEffects.Feedback(m,controller,input,duration);}
  public override void Notify(TakeoverReleaseMemory m,uint callback,uint actor){remaining.Notify(m,callback,actor);}
  public override void Camera(TakeoverReleaseMemory m,uint camera,float duration,float blend,uint mode){CleanupEffects.Transition(m,camera,duration,blend,mode);}
 }
 public sealed class RecoveredCameraPipelinePorts:TakeoverPipelinePorts
 {
  readonly TakeoverPipelinePorts remaining;public RecoveredCameraPipelinePorts(TakeoverPipelinePorts remaining){this.remaining=remaining;}
  public override void Camera(TakeoverReleaseMemory m,uint c,float d){CleanupEffects.Transition(m,c,d,0,1);}
  public override void Rebind(TakeoverReleaseMemory m,uint a){remaining.Rebind(m,a);}public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return remaining.ChangeTakenOverState(m,p);}public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return remaining.ChangeReleasedState(m,p);}
  public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){remaining.RunScript(m,s,a,p,d);}public override void ClearAction(TakeoverReleaseMemory m,uint a){remaining.ClearAction(m,a);}public override void ResetActor(TakeoverReleaseMemory m,uint a){remaining.ResetActor(m,a);}public override void StopActor(TakeoverReleaseMemory m,uint a){remaining.StopActor(m,a);}public override void ResetAnimation(TakeoverReleaseMemory m,uint p){remaining.ResetAnimation(m,p);}public override void PrepareActor(TakeoverReleaseMemory m,uint a){remaining.PrepareActor(m,a);}public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return remaining.DistanceFactor(m,p,t);}public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){remaining.DirectedJump(m,a,t,s,d);}public override void VehicleResponse(TakeoverReleaseMemory m,uint a,uint o){remaining.VehicleResponse(m,a,o);}
 }
}
