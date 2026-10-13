// Recovered PC character shadow-group queue production. No shadow rasterization.
using System;
namespace Recovered.Animation
{
    public sealed class CharacterShadowBinding
    {
        // Relocated pointers at +0/+4/+8, followed by counts and joint byte.
        public uint EllipsePointer,CylinderPointer,OtherPointer;
        public byte EllipseCount,CylinderCount,OtherCount,JointIndex;
    }
    public sealed class CharacterShadowQueueState
    {
        public const int Capacity=280,RecordSize=104;
        public byte[] Records=new byte[Capacity*RecordSize];
        // Original globals 973fe8,973fdc,9718a4.
        public int Count;
        public uint Sequence,SubmissionFlag;
        // Original globals 8264c4,8264bc,80babc.
        public byte Enabled;
        public int Mode;
        public uint SubmissionEnabled;
        // Original globals 2854bf4/8/c,2854c00,973fe0/4.
        public uint Parameter0,Parameter1,Parameter2,PackedParameter;
        public float FadeDistance,MaximumDistance;
    }
    public static class CharacterShadowQueue
    {
        static void U32(byte[] b,int p,uint v)
        {b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
        static uint Bits(float v){return BitConverter.ToUInt32(BitConverter.GetBytes(v),0);}
        static void CheckState(CharacterShadowQueueState state)
        {if(state==null||state.Count<0)throw new ArgumentException("Nonnegative queue count required");}
        // 0x5f9ed0. Matrix is a raw 64-byte copy; it is not evaluated here.
        // Source and destination are disjoint. Float metadata must be finite.
        public static void Enqueue(CharacterShadowQueueState state,byte[] matrix,CharacterShadowBinding binding)
        {
            CheckState(state);if(state.Count>=CharacterShadowQueueState.Capacity)return;
            if(matrix==null||matrix.Length!=64||binding==null||state.Records==null||state.Records.Length<CharacterShadowQueueState.Capacity*CharacterShadowQueueState.RecordSize)throw new ArgumentException("Matrix, binding and fixed-capacity queue required");
            if(Single.IsNaN(state.FadeDistance)||Single.IsInfinity(state.FadeDistance)||Single.IsNaN(state.MaximumDistance)||Single.IsInfinity(state.MaximumDistance))throw new ArgumentException("Finite distance metadata required");
            int p=state.Count*CharacterShadowQueueState.RecordSize;
            U32(state.Records,p+0x5c,Bits(state.FadeDistance));U32(state.Records,p+0x60,Bits(state.MaximumDistance));
            U32(state.Records,p+0x4c,state.Parameter0);U32(state.Records,p+0x50,state.Parameter1);U32(state.Records,p+0x54,state.Parameter2);
            U32(state.Records,p+0x58,unchecked((uint)(int)(sbyte)(state.PackedParameter>>24)));
            Buffer.BlockCopy(matrix,0,state.Records,p,64);
            U32(state.Records,p+0x40,binding.EllipsePointer);U32(state.Records,p+0x44,binding.CylinderPointer);U32(state.Records,p+0x48,binding.OtherPointer);
            state.Records[p+0x64]=binding.EllipseCount;state.Records[p+0x65]=binding.CylinderCount;state.Records[p+0x66]=binding.OtherCount;
            state.Records[p+0x67]=(byte)state.Sequence;
            ++state.Count;state.Sequence=unchecked(state.Sequence+1);
        }
        // 0x5f9fa0. The array retains the native joint=255 terminator.
        // Records after that marker are not read. A full queue still scans it.
        public static void Submit(CharacterShadowQueueState state,CharacterShadowBinding[] bindings,byte suppress,float[] world,float[][] joints)
        {
            CheckState(state);
            if(state.Enabled==0||state.Mode!=1||bindings==null||suppress!=0)return;
            for(int i=0;i<bindings.Length;++i)
            {
                var binding=bindings[i];if(binding==null)throw new ArgumentException("Valid terminated bindings required");if(binding.JointIndex==255)return;
                if(state.Count<CharacterShadowQueueState.Capacity&&state.SubmissionEnabled!=0)
                {
                    if(joints==null||binding.JointIndex>=joints.Length)throw new ArgumentException("Resolved joint matrix required");
                    float[] combined=CharacterLayerSubmission.Concatenate(joints[binding.JointIndex],world);byte[] bytes=new byte[64];Buffer.BlockCopy(combined,0,bytes,0,64);
                    Enqueue(state,bytes,binding);state.SubmissionFlag=1;
                }
            }
            throw new ArgumentException("Native joint=255 terminator required");
        }
    }
}
