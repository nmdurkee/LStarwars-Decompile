// Normal CPU scheduling recovered from 0x5f3c80/0x5f5830/0x5fd0d0.
// Evidence: geometry-scene-scheduling-native-validation.json. Prepared camera
//and modern portal data; dynamic packet builder remains an explicit handoff.
using System;
using System.Collections.Generic;

namespace Recovered.Geometry
{
    public sealed class ScheduledSpecial
    {
        public uint Flags;
        public int BoundsIndex;
        public float[] Matrix,OverrideMatrix;
    }
    public sealed class DynamicSubmission
    {
        public readonly int SpecialIndex;
        public readonly float[] Matrix;
        public readonly bool UsesOverride;
        public DynamicSubmission(int index,float[] matrix,bool usesOverride)
        {SpecialIndex=index;Matrix=matrix;UsesOverride=usesOverride;}
    }
    public sealed class SchedulingScene
    {
        public PortalRuntimeScene PortalScene;
        public IList<PortalRoom> SelectionRooms;
        public SceneVisibility Static;
        public ScheduledSpecial[] Specials;
        public int LegacyInstanceCount;
        public int? AlternateInstanceCount;
        public bool PortalMarkerPresent,GridPresent,TreePresent;
    }
    public sealed class SchedulingOptions
    {
        public bool SkipAll,SkipDynamic,ShadowMode;
        public bool VisibilityEnabled=true,PortalsEnabled=true,DynamicPortalFiltering=true;
        public bool GridEnabled,TreeEnabled;
        public int RequestedCameraMode,CurrentCameraMode;
    }
    public sealed class SchedulingState
    {
        public PortalEntryState Portal;
        public int ContextCount,ContextScratch;
        public byte[] InstanceTreeBits;
        public uint ContextFlags;
        public bool VisibilityActive;
        public uint[] ShaderContext=new uint[105];
        // Ordered call diagnostics and the dynamic packet-builder boundary.
        //These collections represent observations, not original linked lists.
        public readonly List<uint> Calls=new List<uint>();
        public readonly List<DynamicSubmission> Dynamic=new List<DynamicSubmission>();
    }
    public static class SceneScheduling
    {
        // Original0x5fd0d0 copies105 DWORDs from its global template, then
        //clears fields+0x168,+0x110,+0x34,+0x180 in that order.
        public static void CopyShaderContext(uint[] template,uint[] output)
        {
            if(template==null || output==null || template.Length!=105 || output.Length!=105) throw new ArgumentException("Expected105-DWORD shader contexts.");
            Array.Copy(template,output,105);output[0x5a]=0;output[0x44]=0;output[0xd]=0;output[0x60]=0;
        }

        // Original0x5f3c80, normal camera/grid/tree-disabled branch. Null
        //return preserves state when workspace or global visibility is off.
        //The native return aliases GSNH+0x120; this is a typed projection.
        public static VisibilityInputs PrepareVisibility(SchedulingScene scene,SchedulingOptions options,SchedulingState state,bool workspacePresent,PortalEntryCamera camera,Point3? selectionOverride,int depth,NativeSineTable sine)
        {
            if(scene==null || options==null || state==null) throw new ArgumentNullException();
            if(!workspacePresent || !options.VisibilityEnabled) return null;
            if(options.RequestedCameraMode!=0 || options.CurrentCameraMode!=0) throw new NotSupportedException("Alternate camera save/restore is outside the normal prepared-camera projection.");
            if(options.GridEnabled && scene.GridPresent) throw new NotSupportedException("Grid visibility producer remains separate.");
            if((!scene.PortalMarkerPresent || !options.PortalsEnabled) && options.TreeEnabled && scene.TreePresent) throw new NotSupportedException("Tree visibility producer remains separate.");
            state.ContextScratch=0;state.InstanceTreeBits=null;state.ContextCount=scene.AlternateInstanceCount.HasValue?scene.AlternateInstanceCount.Value:scene.LegacyInstanceCount;
            state.ContextFlags&=0xffffffea;state.VisibilityActive=true;
            if(scene.PortalMarkerPresent && options.PortalsEnabled)
            {
                if(state.Portal==null) throw new ArgumentException("Portal state required.");
                PortalEntry.Run(scene.PortalScene,scene.SelectionRooms,true,camera,selectionOverride,depth,sine,state.Portal);
            }
            return new VisibilityInputs {InstanceTreeBits=state.InstanceTreeBits,PortalMarkerPresent=scene.PortalMarkerPresent,PortalsEnabled=options.PortalsEnabled,PortalBits=state.Portal==null?null:state.Portal.VisibilityBits};
        }

        // Original0x5f5830 normal-path caller projection. The selected special
        //and transform are handed off in source order; this does not run
        //original5f0f00 packet/material/GPU work. Grid/tree/shadow branches are
        //explicitly unsupported instead of supplying fabricated visibility.
        public static void Run(SchedulingScene scene,SchedulingOptions options,SchedulingState state,uint[] shaderTemplate,PortalEntryCamera camera,Point3? selectionOverride,int depth,NativeSineTable sine,NativeFrustum frustum)
        {
            if(scene==null || scene.Static==null || options==null || state==null) throw new ArgumentNullException();
            state.Calls.Clear();state.Dynamic.Clear();state.Calls.Add(0x5f5830);
            if(options.SkipAll) return;
            if((scene.Static.Flags&4)!=0) {state.Calls.Add(0x5c12f0);return;}
            if(options.ShadowMode) throw new NotSupportedException("Shadow submission remains separate.");
            if(!options.VisibilityEnabled) throw new NotSupportedException("Native caller dereferences the missing context; only nonnull normal contexts are admitted.");
            state.Calls.Add(0x5fd0d0);CopyShaderContext(shaderTemplate,state.ShaderContext);
            state.Calls.Add(0x5f3c80);VisibilityInputs visibility=PrepareVisibility(scene,options,state,true,camera,selectionOverride,depth,sine);
            if((state.ContextFlags&1)==0)
            {
                if(camera==null || camera.World==null || camera.World.Length!=16 || frustum==null) throw new ArgumentException("Prepared camera and native frustum required.");
                state.Calls.Add(0x5f5380);
                if(scene.Static.Clips.Length==0) scene.Static.AlphaValues=scene.Static.FadeRanges==null?null:new float[0];
                else SceneSubmission.EvaluateVisibility(scene.Static,new Point3(camera.World[12],camera.World[13],camera.World[14]),visibility,delegate(ClipBounds b,float limit){return frustum.Classify(b.Center,b.Extent,limit);});
            }
            if(scene.Static.Clips.Length!=0) scene.Static.Flags|=4;
            state.Calls.Add(0x603960); // Original empty instrumentation callback.
            if((scene.Static.Flags&0x10000)!=0 || options.SkipDynamic) return;
            if(scene.Specials==null) throw new ArgumentException("Declared special array required.");
            bool filter=options.DynamicPortalFiltering && scene.PortalMarkerPresent && options.PortalsEnabled;
            for(int i=0;i<scene.Specials.Length;++i)
            {
                ScheduledSpecial special=scene.Specials[i];if(special==null) throw new ArgumentException("Null special record.");
                if((special.Flags&2)==0) continue;
                if(filter)
                {
                    int index=special.BoundsIndex;
                    if(index<0 || index>=scene.Static.InstanceFlags.Length || visibility.PortalBits==null || index/8>=visibility.PortalBits.Length) throw new ArgumentException("Special bounds index outside visibility arrays.");
                    if((scene.Static.InstanceFlags[index]&8)==0 && (visibility.PortalBits[index>>3]&(1<<(index&7)))==0) continue;
                }
                bool useOverride=special.OverrideMatrix!=null;float[] transform=useOverride?special.OverrideMatrix:special.Matrix;
                if(transform==null || transform.Length!=16) throw new ArgumentException("Selected special transform must contain16 floats.");
                state.Calls.Add(0x5f0f00);state.Dynamic.Add(new DynamicSubmission(i,transform,useOverride));
            }
        }
    }
}
