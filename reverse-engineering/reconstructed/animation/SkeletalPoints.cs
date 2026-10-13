// PC point-of-interest matrix outputs; no Android joint255 fallback is inferred.
using System;
namespace Recovered.Animation
{
    public sealed class SkeletalPoint
    {
        public float[] LocalMatrix;
        public byte JointIndex;
    }
    public sealed class SkeletalPointBindings
    {
        public SkeletalPoint[] Points;
        public byte[] Lookup;
        // Native model+14 has16uints. Any nonzero word enables the output slot.
        public uint[] EnabledSlots;
    }
    public static class SkeletalPoints
    {
        static void Matrix(float[] m){if(m==null||m.Length!=16)throw new ArgumentException("Sixteen matrix values required");foreach(float v in m)if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite point matrix required");}
        // 0x5daae0: pointLocal*jointWorld, then the stored result*objectWorld.
        // Lookup and joint indices must resolve into supplied finite arrays.
        // Joint255 is used literally; it requires an explicit matrix slot255.
        public static float[] EvaluatePoint(SkeletalPointBindings bindings,byte logicalIndex,float[] objectWorld,float[][] jointWorld,SkeletalMatrixConcatenator concatenate)
        {
            if(bindings==null||bindings.Lookup==null||bindings.Points==null||jointWorld==null||concatenate==null)throw new ArgumentNullException();
            if(logicalIndex>=bindings.Lookup.Length||bindings.Lookup[logicalIndex]>=bindings.Points.Length)throw new ArgumentException("Unresolved point lookup");var point=bindings.Points[bindings.Lookup[logicalIndex]];
            if(point==null||point.JointIndex>=jointWorld.Length)throw new ArgumentException("Unresolved point joint matrix");Matrix(point.LocalMatrix);Matrix(jointWorld[point.JointIndex]);Matrix(objectWorld);
            float[] local=concatenate(point.LocalMatrix,jointWorld[point.JointIndex]);Matrix(local);float[] result=concatenate(local,objectWorld);Matrix(result);return result;
        }
        // 0x62e1e0: iterate exactly16slots, preserving disabled destinations.
        // positions and matrices may independently be null. Both null returns
        // before reading the model or point bindings, as in the original routine.
        public static void WritePoints(SkeletalPointBindings bindings,float[] objectWorld,float[][] jointWorld,float[][] positions,float[][] matrices,SkeletalMatrixConcatenator concatenate)
        {
            if(positions==null&&matrices==null)return;
            if(bindings==null||bindings.EnabledSlots==null||bindings.EnabledSlots.Length!=16)throw new ArgumentException("Sixteen point-enable words required");
            if((positions!=null&&positions.Length!=16)||(matrices!=null&&matrices.Length!=16))throw new ArgumentException("Sixteen output slots required");
            for(int i=0;i<16;++i)if(bindings.EnabledSlots[i]!=0)
            {
                float[] matrix=EvaluatePoint(bindings,(byte)i,objectWorld,jointWorld,concatenate);
                if(positions!=null)positions[i]=new float[]{matrix[12],matrix[13],matrix[14]};if(matrices!=null)matrices[i]=matrix;
            }
        }
        // Extends the recovered0x62e290 branch to its optional POI outputs.
        // Morph output remains absent. No selected layers means no pose or POI
        // writes; packet contents remain unchanged. Slot enablement is supplied
        // from model state, not inferred from the raw source lookup alone.
        public static SkeletalPoseResult EvaluatePacket(AnimationPacket packet,SkeletalPacketModel model,uint layerMask,SkeletalPointBindings bindings,float[] objectWorld,float[][] positions,float[][] matrices,float[] sineTable,SkeletalMatrixConcatenator concatenate)
        {
            var pose=SkeletalPacketDispatch.Evaluate(packet,model,layerMask,sineTable,concatenate);if(pose!=null)WritePoints(bindings,objectWorld,pose.WorldMatrices,positions,matrices,concatenate);return pose;
        }
    }
}
