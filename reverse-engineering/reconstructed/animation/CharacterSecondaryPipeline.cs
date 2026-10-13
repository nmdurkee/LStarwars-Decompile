// Character layer orchestration with recovered secondary visibility/cache.
using System;
namespace Recovered.Animation
{
    public static class CharacterSecondaryPipeline
    {
        // Refines5f4ff0 without duplicating its layer selection or matrix math.
        // Both state projections represent966384/9715a0; character state is
        // authoritative. Dynamic draw remains the supplied explicit service.
        public static uint Submit(CharacterRenderModel model,float[] world,float[][] joints,int requestedCount,short[] layerMap,uint[] morphIdentities,CharacterSubmissionState state,CharacterPipelineEnvironment environment,SecondaryVisibilityState secondary)
        {
            if(state==null||environment==null||secondary==null)throw new ArgumentNullException();
            secondary.Count=state.SecondaryVisibilityCount;secondary.CacheFlag=state.SubmissionFlag;
            var resolved=new CharacterPipelineEnvironment{Camera=environment.Camera,CenterBoundsOnRoot=environment.CenterBoundsOnRoot,Shadows=environment.Shadows,ShadowBindings=environment.ShadowBindings,SuppressShadow=environment.SuppressShadow,Submit=environment.Submit};
            resolved.SecondaryVisibility=delegate(float[] first,float[] second,int refresh)
            {
                secondary.Count=state.SecondaryVisibilityCount;secondary.CacheFlag=state.SubmissionFlag;
                int visible=SecondaryVisibility.Evaluate(secondary,first,second,refresh);state.SubmissionFlag=secondary.CacheFlag;return visible;
            };
            uint flags=CharacterRenderPipeline.Submit(model,world,joints,requestedCount,layerMap,morphIdentities,state,resolved);
            // Outer native5f4ff0 always clears9715a0, including early cull.
            secondary.CacheFlag=state.SubmissionFlag;return flags;
        }
    }
}
