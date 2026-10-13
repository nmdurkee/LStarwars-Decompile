// Prepared-memory vehicle response and action finish; original native callback order retained.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public abstract class VehicleResponseServices
 {
  public abstract void Feedback(TakeoverReleaseMemory m,uint controller,float duration,uint mode);
  public abstract void Notify(TakeoverReleaseMemory m,uint callback,uint actor);
  public abstract void Camera(TakeoverReleaseMemory m,uint camera,float duration,float blend,uint mode);
 }
 public static class VehicleResponseProducer
 {
  static uint Add(uint p,int offset){return unchecked(p+(uint)offset);}
  static int Signed(uint v){return unchecked((int)v);}
  static short Short(ushort v){return unchecked((short)v);}
  // 5a0320: full DWORD sentinel, signed WORD clip indexing, then live callback rereads.
  public static void Respond(TakeoverReleaseMemory m,VehicleResponseServices services,uint actor,uint other)
  {
   if(m.Read32(0x8028a8)==0xffffffff)return;short action=Short(m.Read16(0x804d08));if(action==-1)return;
   uint clips=m.Read32(m.Read32(actor+0x50)+0xc);if(m.Read32(Add(clips,action*4))==0)return;
   if(other!=0)services.Feedback(m,m.Read32(m.Read32(other+0xca4)),BitConverter.ToSingle(BitConverter.GetBytes(0x3f19999au),0),0);
   m.Write8(actor+0x7b5,m.Read8(0x8028a8));action=Short(m.Read16(0x804d08));int type=Short(m.Read16(actor+0x1064));m.Write16(actor+0x7aa,unchecked((ushort)action));
   m.Write32(actor+0x77c,TakeoverReleaseMemory.Bits(DurationForResponse(m,type,action)));
   uint callback=m.Read32(0x95660c);if(callback!=0)services.Notify(m,callback,actor);
  }
  // Fixed 62e040(actor.signedType, signedAction, 0, 0, 1) bridge. Existing address, zero new credit.
  // Uses the shared 64-significand x87 core and original stores, registry reads and global blend write.
  public static float DurationForResponse(TakeoverReleaseMemory m,int type,int action)
  {
   if(type<0)return 0;uint registry=m.Read32(0x29130e4);if(type>=Signed(m.Read32(registry)))return 0;
   if(action<0||action>=Signed(m.Read32(registry+8)))return 0;short slot=Short(m.Read16(Add(m.Read32(registry+0x1c),type*2)));if(slot==-1)return 0;
   uint model=Add(m.Read32(registry+0x18),slot*0x54);uint header=m.Read32(Add(m.Read32(model+0xc),action*4));if(header==0)return 0;
   uint magic=m.Read32(header);float frames;
   if(magic==0x414e4934||magic==0x414e4935){ushort end=m.Read16(header+0xe),start=m.Read16(header+0xa);byte[] b=new byte[16];Buffer.BlockCopy(BitConverter.GetBytes(magic),0,b,0,4);Buffer.BlockCopy(BitConverter.GetBytes(end),0,b,14,2);Buffer.BlockCopy(BitConverter.GetBytes(start),0,b,10,2);frames=AnimationPlayback.EndFrame(b);}else frames=BitConverter.ToSingle(BitConverter.GetBytes(magic),0);
   if(Single.IsNaN(frames)||Single.IsInfinity(frames))throw new ArgumentOutOfRangeException("finite response frames");
   float span=PlaybackWide.Add(PlaybackWide.From(frames),PlaybackWide.From(-1)).Store();
   uint timing=m.Read32(Add(m.Read32(model+8),action*4));float fps=m.Float(timing+0x18);
   if(!(fps>0)||Single.IsInfinity(fps))throw new ArgumentOutOfRangeException("positive finite response FPS");
   PlaybackWide rate=PlaybackWide.Divide(PlaybackWide.From(fps),PlaybackWide.FromDouble(30));
   PlaybackWide seconds=PlaybackWide.Divide(PlaybackWide.From(1),rate);seconds=PlaybackWide.Multiply(seconds,PlaybackWide.FromDouble(0.03333333507180214));
   float stored=PlaybackWide.Multiply(seconds,PlaybackWide.From(span)).Store();
   uint blendBits=m.Read32(timing+0x14);float blend=BitConverter.ToSingle(BitConverter.GetBytes(blendBits),0);if(Single.IsNaN(blend)||Single.IsInfinity(blend)||Single.IsInfinity(stored))throw new ArgumentOutOfRangeException("finite response duration");
   m.Write32(0x29a99a4,blendBits);float result=PlaybackWide.Add(PlaybackWide.From(stored),PlaybackWide.From(-blend)).Store();
   if(stored==0&&blend==0)return BitConverter.ToSingle(BitConverter.GetBytes(TakeoverReleaseMemory.Bits(stored)&(blendBits^0x80000000u)&0x80000000u),0);return result;
  }
  // 4a1f50: second forwarded caller argument is ignored; camera reset always runs.
  public static void Finish(TakeoverReleaseMemory m,VehicleResponseServices services,uint actor)
  {if(actor!=0&&(m.Read32(actor+0x1f8)&0x40000)==0){m.Write32(actor+0xe20,m.Read32(actor+0xe20)&0xfffdffff);m.Write32(actor+0xd14,0);m.Write32(actor+0xd18,0);m.Write8(actor+0x7b5,255);}services.Camera(m,m.Read32(0x8021b4),.5f,0,1);}
 }
 public sealed class RecoveredActionFinishServices:TakeoverCleanupServices
 {readonly VehicleResponseServices services;public RecoveredActionFinishServices(VehicleResponseServices services){this.services=services;}public override void FinishAction(TakeoverReleaseMemory m,uint actor,uint mode){VehicleResponseProducer.Finish(m,services,actor);}public override void Camera(TakeoverReleaseMemory m,uint c,float d,float b,uint mode){services.Camera(m,c,d,b,mode);}}
 public sealed class RecoveredVehicleResponsePorts:TakeoverPipelinePorts
 {
  readonly TakeoverPipelinePorts remaining;readonly VehicleResponseServices services;
  public RecoveredVehicleResponsePorts(TakeoverPipelinePorts remaining,VehicleResponseServices services){this.remaining=remaining;this.services=services;}
  public override void VehicleResponse(TakeoverReleaseMemory m,uint actor,uint other){VehicleResponseProducer.Respond(m,services,actor,other);}
  public override void Rebind(TakeoverReleaseMemory m,uint a){remaining.Rebind(m,a);}public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return remaining.ChangeTakenOverState(m,p);}public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return remaining.ChangeReleasedState(m,p);}
  public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){remaining.RunScript(m,s,a,p,d);}public override void ClearAction(TakeoverReleaseMemory m,uint a){remaining.ClearAction(m,a);}public override void ResetActor(TakeoverReleaseMemory m,uint a){remaining.ResetActor(m,a);}public override void StopActor(TakeoverReleaseMemory m,uint a){remaining.StopActor(m,a);}public override void ResetAnimation(TakeoverReleaseMemory m,uint p){remaining.ResetAnimation(m,p);}public override void PrepareActor(TakeoverReleaseMemory m,uint a){remaining.PrepareActor(m,a);}public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return remaining.DistanceFactor(m,p,t);}public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){remaining.DirectedJump(m,a,t,s,d);}public override void Camera(TakeoverReleaseMemory m,uint c,float d){remaining.Camera(m,c,d);}
 }
}
