// Composition of sealed original-PC release/transfer/selector/bounds/ejection sources.
// Remaining script/animation/camera callbacks stay explicit ports. No new address credit.
namespace Recovered.Gameplay
{
 public abstract class TakeoverPipelinePorts
 {
  public abstract void Rebind(TakeoverReleaseMemory m,uint actor);
  public abstract int ChangeTakenOverState(TakeoverReleaseMemory m,uint packet);
  public abstract int ChangeReleasedState(TakeoverReleaseMemory m,uint packet);
  public abstract void RunScript(TakeoverReleaseMemory m,uint system,uint actor,uint packet,uint deltaBits);
  public abstract void ClearAction(TakeoverReleaseMemory m,uint actor);
  public abstract void ResetActor(TakeoverReleaseMemory m,uint actor);
  public abstract void StopActor(TakeoverReleaseMemory m,uint actor);
  public abstract void ResetAnimation(TakeoverReleaseMemory m,uint embedded);
  public abstract void PrepareActor(TakeoverReleaseMemory m,uint actor);
  public abstract void VehicleResponse(TakeoverReleaseMemory m,uint vehicle,uint rider);
  public abstract float DistanceFactor(TakeoverReleaseMemory m,uint position,uint target);
  public abstract void DirectedJump(TakeoverReleaseMemory m,uint rider,uint target,float speed,float duration);
  public abstract void Camera(TakeoverReleaseMemory m,uint camera,float duration);
 }
 public sealed class RecoveredTakeoverPipeline:TakeoverReleaseServices
 {
  readonly TakeoverPipelinePorts ports;readonly JumpContextAudio audio;readonly TransferStage transfer;
  public RecoveredTakeoverPipeline(TakeoverPipelinePorts ports,JumpContextAudio audio)
  {this.ports=ports;this.audio=audio;transfer=new TransferStage(ports);}
  sealed class TransferStage:TakeoverTransferServices
  {
   readonly TakeoverPipelinePorts ports;public TransferStage(TakeoverPipelinePorts p){ports=p;}
   public override void Rebind(TakeoverReleaseMemory m,uint a){ports.Rebind(m,a);}
   public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return ports.ChangeTakenOverState(m,p);}
   public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){ports.RunScript(m,s,a,p,d);}
   public override void ClearAction(TakeoverReleaseMemory m,uint a){ports.ClearAction(m,a);}
   public override void ResetActor(TakeoverReleaseMemory m,uint a){ports.ResetActor(m,a);}
   public override void StopActor(TakeoverReleaseMemory m,uint a){ports.StopActor(m,a);}
   public override void ResetAnimation(TakeoverReleaseMemory m,uint p){ports.ResetAnimation(m,p);}
   public override void PrepareActor(TakeoverReleaseMemory m,uint a){ports.PrepareActor(m,a);}
   public override void SelectTakeoverAnimation(TakeoverReleaseMemory m,uint vehicle,uint rider){TakeoverAnimationSelector.Select(m,vehicle,rider);}
   public override void Camera(TakeoverReleaseMemory m,uint c,float d){ports.Camera(m,c,d);}
  }
  public void Release(TakeoverReleaseMemory m,uint input){TakeoverRelease.Release(m,this,input);}
  public override int Transfer(TakeoverReleaseMemory m,uint a,uint b){return TakeoverTransfer.Transfer(m,transfer,a,b,false);}
  public override void Rebind(TakeoverReleaseMemory m,uint a){ports.Rebind(m,a);}
  public override void RefreshPose(TakeoverReleaseMemory m,uint a){PreparedCharacterBounds.Refresh(m,a);}
  public override void Eject(TakeoverReleaseMemory m,uint a,uint b){VehicleEjection.Eject(m,audio,a,b);}
  public override void VehicleResponse(TakeoverReleaseMemory m,uint b,uint a){ports.VehicleResponse(m,b,a);}
  public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return ports.DistanceFactor(m,p,t);}
  public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){ports.DirectedJump(m,a,t,s,d);}
  public override void Camera(TakeoverReleaseMemory m,uint c,float d){ports.Camera(m,c,d);}
  public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return ports.ChangeReleasedState(m,p);}
  public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){ports.RunScript(m,s,a,p,d);}
 }
}
