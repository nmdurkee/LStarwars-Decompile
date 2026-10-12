// Bounded CPU projections of original PC scene submission contracts.
// Evidence: geometry-visibility-native-validation.json and geometry-render-integration.json.
// This does not calculate the original frustum/portal visibility or issue GPU draws.
using System;
using System.Collections.Generic;

namespace Recovered.Geometry
{
    public struct Point3
    {
        public float X, Y, Z;
        public Point3(float x, float y, float z) { X=x; Y=y; Z=z; }
    }
    public sealed class ClipBounds
    {
        public Point3 Center, Extent;
    }
    public sealed class ClipObject
    {
        public float LodDistanceSquared, FarClipDistance;
        public int[] MaterialIndices = new int[0];
        public int[] ItemIndices = new int[0];
    }
    public sealed class SceneVisibility
    {
        public readonly ClipObject[] Clips;
        public readonly ClipBounds[] Bounds;
        public readonly byte[] InstanceFlags;
        public readonly byte[][] MaterialBits, ClipBits;
        public uint Flags;
        public float[] FadeRanges; // null, or start/end pairs for each instance.
        public float[] AlphaValues; // fresh scratch, only selected visible clips meaningful.
        public SceneVisibility(ClipObject[] clips, ClipBounds[] bounds, byte[] flags, int materialCount)
        {
            if(clips==null || bounds==null || flags==null) throw new ArgumentNullException();
            if(flags.Length!=bounds.Length || materialCount<0) throw new ArgumentException("Invalid scene dimensions.");
            Clips=clips; Bounds=bounds; InstanceFlags=flags;
            MaterialBits=new byte[][] {new byte[(materialCount+7)/8],new byte[(materialCount+7)/8]};
            ClipBits=new byte[][] {new byte[((clips.Length+15)/16)*4],new byte[((clips.Length+15)/16)*4]};
        }
    }
    public sealed class VisibilityInputs
    {
        public byte[] InstanceTreeBits, PortalBits;
        public bool PortalMarkerPresent, PortalsEnabled;
    }
    public sealed class SortRecord
    {
        public int SortKey;
        public object Payload;
    }

    public static class SceneSubmission
    {
        // Original0x5de060 insertion contract, with managed collection replacing
        // next pointers. Equal signed keys insert BEFORE existing equal entries.
        public static void InsertSortRecord(IList<SortRecord> sorted, SortRecord record)
        {
            if(sorted==null || record==null) throw new ArgumentNullException();
            int i=0; while(i<sorted.Count && sorted[i].SortKey<record.SortKey) ++i;
            sorted.Insert(i,record);
        }
        // Key adjustment observed inside registration0x5ded80, not a whole
        // registration implementation. Arithmetic deliberately wraps32 bits.
        public static int ApplyPriorityBias(int key,int priorityBias)
        { return unchecked(key+(priorityBias<<17)); }

        // Extracted strict comparison branch from0x5f5380. Zero ends a group.
        public static int SelectLod(ClipObject[] clips,int first,float distanceSquared)
        {
            if(clips==null || first<0 || first>=clips.Length) throw new ArgumentOutOfRangeException("first");
            RequireFinite(distanceSquared);
            int i=first;
            if(clips[i].LodDistanceSquared!=0 && distanceSquared<clips[i].LodDistanceSquared)
            {
                do { if(++i>=clips.Length) throw new ArgumentException("Unterminated LOD group."); }
                while(distanceSquared<clips[i].LodDistanceSquared);
            }
            return i;
        }

        // Original0x5df7b0, finite nonnegative distance domain. Original sqrt
        // helper0x5c0240 rounds sqrt to float32 before the fade calculation.
        public static float DistanceFade(float distanceSquared,float start,float end)
        {
            RequireFinite(distanceSquared); RequireFinite(start); RequireFinite(end);
            if(distanceSquared<0) throw new ArgumentOutOfRangeException("distanceSquared");
            if(end<=start)
            {
                if(distanceSquared<=(double)end*end) return 0;
                float root=(float)Math.Sqrt(distanceSquared);
                float value=(float)(((double)root-end)/((double)start-end));
                // Equal endpoints can yield0/0 after float32 sqrt rounding.
                // Native comparison retains that NaN instead of forcing1.
                return value>1 ? 1 : value;
            }
            if(distanceSquared<=(double)start*start) return 1;
            float result=(float)(((double)end-(float)Math.Sqrt(distanceSquared))/((double)end-start));
            return result<0 ? 0 : result;
        }

        // Projection of the normal (non-shadow) branch0x5f5380. Caller supplies
        // original-equivalent visibility bitsets/frustum result. This method
        // deliberately does not stand in for5f3c80 portal/tree evaluation or
        //5d69a0 frustum math. Optional debug occlusion mode is excluded.
        // Existing bitsets are ORed, as native; caller clears at frame reset.
        public static void EvaluateVisibility(SceneVisibility scene,Point3 camera,VisibilityInputs visibility,
            Func<ClipBounds,float,int> frustum)
        {
            if(scene==null || visibility==null || frustum==null) throw new ArgumentNullException();
            if(scene.FadeRanges!=null && scene.FadeRanges.Length!=scene.Bounds.Length*2)
                throw new ArgumentException("Fade ranges must match instances.");
            scene.AlphaValues=scene.FadeRanges==null ? null : new float[scene.Clips.Length];
            int parity=(int)((scene.Flags>>15)&1),clip=0,instance=0;
            while(clip<scene.Clips.Length)
            {
                if(instance>=scene.Bounds.Length) throw new ArgumentException("LOD groups exceed bounds.");
                byte flags=scene.InstanceFlags[instance];
                bool visible=visibility.InstanceTreeBits==null || GetBit(visibility.InstanceTreeBits,instance);
                if(visibility.PortalMarkerPresent && visibility.PortalsEnabled)
                    visible=(flags&8)!=0 || GetBit(visibility.PortalBits,instance);
                if(visible && (flags&1)!=0)
                {
                    ClipBounds bound=scene.Bounds[instance];
                    float x=(float)((double)camera.X-bound.Center.X),y=(float)((double)camera.Y-bound.Center.Y),z=(float)((double)camera.Z-bound.Center.Z);
                    float distance=(float)((double)z*z+(double)y*y+(double)x*x);
                    clip=SelectLod(scene.Clips,clip,distance);
                    float limit=scene.Clips[clip].FarClipDistance;
                    bool fade=scene.FadeRanges!=null && (flags&64)!=0;
                    if(fade && scene.FadeRanges[instance*2]<scene.FadeRanges[instance*2+1]) limit=scene.FadeRanges[instance*2+1];
                    int result=frustum(bound,limit);
                    if(result<0 || result>3) throw new ArgumentOutOfRangeException("frustum","Clip result must fit two bits.");
                    if(result!=0)
                    {
                        if(scene.AlphaValues!=null) scene.AlphaValues[clip]=fade ? DistanceFade(distance,scene.FadeRanges[instance*2],scene.FadeRanges[instance*2+1]) : 1;
                        foreach(int material in scene.Clips[clip].MaterialIndices) SetBit(scene.MaterialBits[parity],material);
                        scene.ClipBits[parity][clip>>2]|=(byte)(result<<((clip&3)*2));
                    }
                }
                while(scene.Clips[clip].LodDistanceSquared!=0)
                    if(++clip>=scene.Clips.Length) throw new ArgumentException("Unterminated LOD group.");
                ++clip; ++instance;
            }
            if(instance!=scene.Bounds.Length) throw new ArgumentException("LOD groups differ from bounds.");
        }

        // Original0x5df910, byte controls only. Unchanged32-bit clip words
        // retain previous item bytes. Selected item and preceding transform
        // both become0(skip) for result0, or3(callback) for result1/2/3.
        public static void PatchClipControls(SceneVisibility scene,byte[] items)
        {
            if(scene==null || items==null || (items.Length&15)!=0) throw new ArgumentException("Invalid display stream.");
            int parity=(int)((scene.Flags>>15)&1);byte[] current=scene.ClipBits[parity],previous=scene.ClipBits[1-parity];
            for(int word=0;word<current.Length;word+=4)
            {
                bool same=true;for(int b=0;b<4;++b) if(current[word+b]!=previous[word+b]) same=false;
                if(same) continue;
                int end=Math.Min(scene.Clips.Length,word*4+16);
                for(int c=word*4;c<end;++c)
                {
                    byte control=(byte)(((current[c>>2]>>((c&3)*2))&3)==0 ? 0 : 3);
                    foreach(int index in scene.Clips[c].ItemIndices)
                    {
                        if(index<=0 || index>=items.Length/16) throw new ArgumentOutOfRangeException("ItemIndices");
                        items[index*16+1]=control;items[(index-1)*16+1]=control;
                    }
                }
            }
        }
        // Exact clamp branch in0x603ad0, extracted from its pointer store.
        public static float ClampInstanceAlpha(float alpha)
        { return alpha<0 ? 0 : (alpha>1 ? 1 : alpha); }
        private static bool GetBit(byte[] bits,int index)
        {
            if(bits==null || index<0 || index/8>=bits.Length) throw new ArgumentException("Visibility bitset too short.");
            return (bits[index>>3]&(1<<(index&7)))!=0;
        }
        private static void SetBit(byte[] bits,int index)
        {
            if(index<0 || index/8>=bits.Length) throw new ArgumentOutOfRangeException("MaterialIndices");
            bits[index>>3]|=(byte)(1<<(index&7));
        }
        private static void RequireFinite(float value)
        { if(Single.IsNaN(value)||Single.IsInfinity(value)) throw new ArgumentException("Nonfinite input outside validated domain."); }
    }
}
