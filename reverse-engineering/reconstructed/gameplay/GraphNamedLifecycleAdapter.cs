using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
    public abstract class GraphActorRemainingServices
    {
        public abstract void Release(ActorStateRecord actor);
        public abstract void BuildFailureEffects(SceneryObject buildIt);
    }
    // Composition only: no additional native function is claimed. The graph
    // captures its world for player-name tests, whereas each named lifecycle
    // call resolves the then-current world after possible release callbacks.
    public sealed class GraphNamedLifecycleAdapter:GraphActorServices
    {
        public Func<NamedActorWorld> CurrentWorld;
        public GraphActorRemainingServices Remaining;
        // Optional explicit aliases into an actor image. Ordinary graph buildit
        // positions use the existing shared uint[3] directly, without a copy.
        public readonly Dictionary<GraphActorPlacement,ActorPlacementSource> PlacementSources=new Dictionary<GraphActorPlacement,ActorPlacementSource>();
        public override ActorStateRecord Activate(string name,GraphActorPlacement placement,ushort heading)
        {
            ActorPlacementSource source=null;
            if(placement!=null&&!PlacementSources.TryGetValue(placement,out source))source=new ActorPlacementSource{Words=placement.PositionWords};
            return NamedActorLifecycle.Activate(CurrentWorld(),name,source,heading);
        }
        public override void Deactivate(string name){NamedActorLifecycle.Deactivate(CurrentWorld(),name);}
        public override void Release(ActorStateRecord actor){Remaining.Release(actor);}
        public override void BuildFailureEffects(SceneryObject buildIt){Remaining.BuildFailureEffects(buildIt);}
    }
}
