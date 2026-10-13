using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    //Host composition of existing mapped bodies. No new native entry mappings.
    public static class PathSteeringAdapters
    {
        public static void AttachTransition(PathSteeringWorld steering,PathTransitionWorld transitions)
        {
            steering.Transition=delegate(PathSteeringWorld world)
            {PathTransitions.Select(transitions,world.Owner,world.References[world.Owner.U32(0x2c8+0xd0)]);};
        }
        public static void AttachSpecial(PathSteeringWorld steering,PathActionWorld actions,PathActionMode mode)
        {
            if(!Object.ReferenceEquals(steering.Owner,actions.Owner))throw new ArgumentException("Steering and action packet must share backing.");
            steering.Special=delegate(PathSteeringWorld world,PcObjectImage reference,uint query)
            {
                bool handled=mode==PathActionMode.Default4078d0?PathActionDispatch.Default(actions,reference,query):mode==PathActionMode.Variant4813d0?PathActionDispatch.Variant(actions,reference,query):PathActionDispatch.Alternate(actions,reference,query);return handled?1:0;
            };
        }
    }
}
