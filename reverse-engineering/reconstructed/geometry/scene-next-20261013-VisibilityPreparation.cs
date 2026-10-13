// PC0x5f3c80 dispatcher composition, with declared camera/tree service edges.
// Evidence:scene-next-20261013-native-validation.json. Not a full renderer.
using System;
namespace Recovered.Geometry
{
    public sealed class SceneVisibilityPreparationServices
    {
        // Camera service owns the actual matrix/global-mode update. It executes
        //before context clearing, so its changes are visible to later branches.
        public Action<SceneVisibilityPreparationCall,int> SwitchCamera;
        public Action<SceneVisibilityPreparationCall> RestoreCamera;
        public Action<SceneVisibilityPreparationCall> TraverseTree;
        // Null selects recovered PortalEntry.Run; nonnull is an explicit host
        //portal service boundary, useful when supplying other native domains.
        public Action<SceneVisibilityPreparationCall> EnterPortal;
    }
    public sealed class SceneVisibilityPreparationCall
    {
        public SchedulingScene Scene;
        public SchedulingOptions Options;
        public SchedulingState State;
        // Raw workspace identity is preserved in ContextScratch on tree branch.
        public int WorkspaceToken;
        public VisibilityGrid Grid;
        public VisibilityGridCache GridCache;
        public VisibilityGridContext GridGlobals;
        public PortalEntryCamera Camera;
        public Point3? SelectionOverride;
        public int PortalDepthLimit;
        public NativeSineTable Sine;
        public SceneVisibilityPreparationServices Services;
    }
    public static class SceneVisibilityPreparation
    {
        // Refines existing0x5f3c80 mapping. Returns the existing scene-context
        //projection; callbacks and grid/portal producers retain source ordering.
        //The diagnostics list is not a native persistent field.
        public static VisibilityInputs Prepare(SceneVisibilityPreparationCall call)
        {
            if(call==null||call.Scene==null||call.Options==null||call.State==null)throw new ArgumentNullException();
            SchedulingScene scene=call.Scene;SchedulingOptions options=call.Options;SchedulingState state=call.State;
            if(call.WorkspaceToken==0||!options.VisibilityEnabled)return null;
            if(call.Services==null||call.Services.SwitchCamera==null)throw new ArgumentException("Camera switch service required.");
            state.Calls.Add(0x5d6900);call.Services.SwitchCamera(call,options.RequestedCameraMode);
            state.ContextScratch=0;state.InstanceTreeBits=null;
            state.ContextCount=scene.AlternateInstanceCount.HasValue?scene.AlternateInstanceCount.Value:scene.LegacyInstanceCount;
            state.ContextFlags&=0xffffffea;state.VisibilityActive=true;
            if(options.GridEnabled&&scene.GridPresent)
            {
                if(call.Grid==null||call.GridCache==null||call.GridGlobals==null||call.Camera==null||call.Camera.World==null||call.Camera.World.Length!=16)throw new ArgumentException("Resolved grid/cache/globals and prepared camera required.");
                call.GridGlobals.InstanceTreeBits=state.InstanceTreeBits;
                state.Calls.Add(0x5d6f30);GridVisibility.Produce(call.Grid,call.Camera.World[12],call.Camera.World[14],call.GridCache,call.GridGlobals);
                state.InstanceTreeBits=call.GridGlobals.InstanceTreeBits;
            }
            if(scene.PortalMarkerPresent&&options.PortalsEnabled)
            {
                state.Calls.Add(0x5eeb30);
                if(call.Services.EnterPortal!=null)call.Services.EnterPortal(call);
                else
                {
                    if(state.Portal==null)throw new ArgumentException("Portal state required.");
                    PortalEntry.Run(scene.PortalScene,scene.SelectionRooms,true,call.Camera,call.SelectionOverride,call.PortalDepthLimit,call.Sine,state.Portal);
                }
            }
            else if(scene.TreePresent&&options.TreeEnabled)
            {
                if(call.Services.TraverseTree==null)throw new ArgumentException("Tree traversal service required.");
                state.ContextScratch=call.WorkspaceToken;state.Calls.Add(0x5d8fb0);call.Services.TraverseTree(call);state.ContextFlags|=1;
            }
            if(options.CurrentCameraMode==1)
            {
                if(call.Services.RestoreCamera==null)throw new ArgumentException("Camera restore service required.");
                state.Calls.Add(0x603cc0);call.Services.RestoreCamera(call);
            }
            return new VisibilityInputs{InstanceTreeBits=state.InstanceTreeBits,PortalMarkerPresent=scene.PortalMarkerPresent,PortalsEnabled=options.PortalsEnabled,PortalBits=state.Portal==null?null:state.Portal.VisibilityBits};
        }
    }
}
