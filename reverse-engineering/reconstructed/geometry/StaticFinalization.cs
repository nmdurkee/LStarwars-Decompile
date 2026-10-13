// CPU display-command finishing contracts. Native evidence:
// geometry-static-finish-native-validation.json. Managed execution pending.
using System;
using System.Collections.Generic;

namespace Recovered.Geometry
{
    public sealed class MaterialGateBytes
    {
        // Original material+0xf8/+0xf9/+0xfa. Their broader semantic name
        //is unresolved; these are raw gate bytes, not assumed RGB values.
        public byte A,B,C;
        public MaterialGateBytes(byte a,byte b,byte c) {A=a;B=b;C=c;}
    }
    public sealed class MaterialControlTarget
    {
        public int MaterialIndex,ItemIndex;
    }
    public sealed class StaticFinishScene
    {
        public SceneVisibility Visibility;
        public byte[] Items;
        // Indexed by mesh command. References to the preceding command's
        //matrix preserve aliasing: several items may target one matrix.
        public float[][] AlphaTargetsByItem;
        public MaterialGateBytes[] Materials;
        public MaterialControlTarget[] MaterialTargets;
    }
    public sealed class StaticFinishCallbacks
    {
        public Action<int> EnterGate,LeaveGate;
        public Action FlushDynamicLists,FinalizeSortedPackets;
    }
    public static class StaticFinalization
    {
        // Original0x5df880. Only active item type0x82 writes alpha to the
        //preceding transform's float+0x3c. Native clamp preserves unordered
        //NaN and signed zero; the existing verified clamp is reused here.
        public static void PatchAlpha(StaticFinishScene scene)
        {
            if(scene==null || scene.Visibility==null) throw new ArgumentNullException();
            SceneVisibility v=scene.Visibility;if(v.AlphaValues==null) return;
            if(v.AlphaValues.Length<v.Clips.Length || scene.Items==null || (scene.Items.Length&15)!=0) throw new ArgumentException("Invalid alpha/command dimensions.");
            for(int ci=0;ci<v.Clips.Length;++ci)
            {
                int[] indices=v.Clips[ci].ItemIndices;
                if(indices==null || indices.Length>65535) throw new ArgumentException("Native clip item counts are unsigned16.");
                foreach(int index in indices)
                {
                    if(index<=0 || index>=scene.Items.Length/16) throw new ArgumentException("Invalid item predecessor.");
                    if(scene.Items[index*16+1]==0 || scene.Items[index*16]!=0x82) continue;
                    if(scene.AlphaTargetsByItem==null || index>=scene.AlphaTargetsByItem.Length || scene.AlphaTargetsByItem[index]==null || scene.AlphaTargetsByItem[index].Length!=16) throw new ArgumentException("Valid preceding transform required.");
                    scene.AlphaTargetsByItem[index][15]=SceneSubmission.ClampInstanceAlpha(v.AlphaValues[ci]);
                }
            }
        }

        // Original0x5e0bd0. Equal visibility bytes skip all eight records in
        //that byte. A missing first material suppresses the whole helper,
        //whereas a missing later selected material only bypasses its gate.
        public static void PatchMaterials(StaticFinishScene scene,int gateMode)
        {
            if(scene==null || scene.Materials==null || scene.Materials.Length==0 || scene.Materials[0]==null) return;
            if(scene.Visibility==null || scene.Items==null || (scene.Items.Length&15)!=0 || scene.MaterialTargets==null) throw new ArgumentException("Material/command records required.");
            int parity=(int)((scene.Visibility.Flags>>15)&1);byte[] current=scene.Visibility.MaterialBits[parity],previous=scene.Visibility.MaterialBits[1-parity];int count=scene.MaterialTargets.Length;
            if(current.Length<(count+7)/8 || previous.Length<(count+7)/8) throw new ArgumentException("Material bitsets too short.");
            for(int i=0;i<count;++i)
            {
                if(current[i>>3]==previous[i>>3]) continue;
                MaterialControlTarget t=scene.MaterialTargets[i];
                if(t==null || t.MaterialIndex<0 || t.MaterialIndex>=scene.Materials.Length || t.ItemIndex<0 || t.ItemIndex>=scene.Items.Length/16) throw new ArgumentException("Invalid material control target.");
                bool active=(current[i>>3]&(1<<(i&7)))!=0;MaterialGateBytes g=scene.Materials[t.MaterialIndex];
                if(g!=null) active=active && (gateMode!=1?g.A!=255:g.A==255 || g.A+g.B+g.C==0);
                scene.Items[t.ItemIndex*16+1]=(byte)(active?0:1);
            }
        }

        // Original0x5f0d70 orchestration. Dynamic-list flush and ordered
        //packet completion remain explicit external callbacks. The real
        //patchers, registered-source order and24-DWORD statistics copy are
        //retained. Returned addresses are diagnostic call-order evidence.
        public static IList<uint> Finish(StaticFinishScene globalScene,IList<StaticFinishScene> registered,uint[] currentCounters,uint[] previousCounters,int gateMode,int lockHandle,StaticFinishCallbacks callbacks)
        {
            if(registered==null || registered.Count>256 || currentCounters==null || previousCounters==null || currentCounters.Length!=24 || previousCounters.Length!=24 || callbacks==null || callbacks.EnterGate==null || callbacks.LeaveGate==null || callbacks.FlushDynamicLists==null || callbacks.FinalizeSortedPackets==null) throw new ArgumentException("Bounded registry,counter arrays and explicit finish boundaries required.");
            List<uint> calls=new List<uint>();calls.Add(0x5f0d70);calls.Add(0x4ffaa0);callbacks.EnterGate(lockHandle);calls.Add(0x5de440);callbacks.FlushDynamicLists();calls.Add(0x603920);
            calls.Add(0x5e0bd0);PatchMaterials(globalScene,gateMode);
            for(int i=0;i<registered.Count;++i)
            {
                if(i>=256) throw new ArgumentException("Original256-scene registry capacity exceeded.");
                StaticFinishScene scene=registered[i];if(scene==null || scene.Visibility==null) throw new ArgumentException("Null registered display scene.");
                if((scene.Visibility.Flags&4)!=0)
                {
                    calls.Add(0x5df910);SceneSubmission.PatchClipControls(scene.Visibility,scene.Items);calls.Add(0x5df880);PatchAlpha(scene);
                }
                if((scene.Visibility.Flags&6)!=0) {calls.Add(0x5e0bd0);PatchMaterials(scene,gateMode);}
            }
            Array.Copy(currentCounters,previousCounters,24);calls.Add(0x5e0d00);callbacks.FinalizeSortedPackets();calls.Add(0x4ffac0);callbacks.LeaveGate(lockHandle);return calls;
        }
    }
}
