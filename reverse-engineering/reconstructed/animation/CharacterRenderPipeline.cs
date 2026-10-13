// Host composition of recovered PC layer selection, visibility and shadow queue.
using System;
using Recovered.Geometry;
namespace Recovered.Animation
{
    public sealed class CharacterPipelineEnvironment
    {
        public DynamicBoxState Camera;
        public bool CenterBoundsOnRoot;
        public CharacterShadowQueueState Shadows;
        public CharacterShadowBinding[] ShadowBindings;
        public byte SuppressShadow;
        // Remaining native 5ea6a0 secondary visibility and 5f0f00 draw boundary.
        public Func<float[],float[],int,int> SecondaryVisibility;
        public CharacterLayerSubmitter Submit;
    }
    public static class CharacterRenderPipeline
    {
        // Refines 0x5f4ff0 composition; no new native entry point is claimed.
        // The existing layer routine owns all cache, allocation and call order.
        public static uint Submit(CharacterRenderModel model,float[] world,float[][] joints,int requestedCount,short[] layerMap,uint[] morphIdentities,CharacterSubmissionState state,CharacterPipelineEnvironment environment)
        {
            if(environment==null)throw new ArgumentNullException("environment");
            var services=new CharacterSubmissionServices
            {
                SecondaryVisibility=environment.SecondaryVisibility,
                Submit=environment.Submit,
                ResolveVisibility=delegate(CharacterRenderModel m,float[] w,float[][] j)
                {
                    // A cached result never enters this closure. Root matrices
                    // are only needed by the native center-on-root branch.
                    float[] root=environment.CenterBoundsOnRoot&&j.Length>0?j[0]:null;
                    return CharacterVisibility.Classify(environment.Camera,m.BoundsMinimum,m.BoundsMaximum,w,root,environment.CenterBoundsOnRoot);
                },
                SubmitAttachments=delegate(CharacterRenderModel m,float[] w,float[][] j)
                {CharacterShadowQueue.Submit(environment.Shadows,environment.ShadowBindings,environment.SuppressShadow,w,j);}
            };
            return CharacterLayerSubmission.Submit(model,world,joints,requestedCount,layerMap,morphIdentities,state,services);
        }
    }
}
