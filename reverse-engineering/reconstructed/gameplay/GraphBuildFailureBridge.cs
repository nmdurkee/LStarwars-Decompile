using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 //Host identity bridge for graph590690 fallback; no additional native address.
 public sealed class GraphBuildFailureBridge:GraphActorServices
 {
  public GraphActorServices Lifecycle;
  public BuildFailureWorld Effects;
  public readonly Dictionary<SceneryObject,BuildFailureObject> Objects=new Dictionary<SceneryObject,BuildFailureObject>();
  public override ActorStateRecord Activate(string name,GraphActorPlacement placement,ushort heading){return Lifecycle.Activate(name,placement,heading);}
  public override void Deactivate(string name){Lifecycle.Deactivate(name);}
  public override void Release(ActorStateRecord actor){Lifecycle.Release(actor);}
  public override void BuildFailureEffects(SceneryObject buildIt)
  {
   BuildFailureObject target;if(!Objects.TryGetValue(buildIt,out target))throw new ArgumentException("Missing buildit group identity.");
   Recovered.Gameplay.BuildFailureEffects.Create(Effects,target);
  }
 }
}
