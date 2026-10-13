// Recovered CPU frame reset. Original-vs-Python evidence:
// reports/geometry-frame-reset-native-validation.json. C# execution pending.
using System;
using System.Collections.Generic;

namespace Recovered.Geometry
{
    public sealed class MaterialResetRecord
    {
        // Opaque record words remain untouched except +0x14/+0x30/+0x34.
        // Context is the decoded +8 pointer. Repeated references must alias.
        public byte[] Bytes,Context;
    }
    public sealed class DisplayResetState
    {
        public uint Flags;
        public int ClipCount;
        // Buffers retain native padded allocation size, not only active bits.
        public byte[][] ClipBuffers,MaterialBuffers;
        public MaterialResetRecord[] Materials;
        // Optional original GSNH owner. Registered owners clear word +0x44.
        public byte[] Owner;
    }
    public sealed class SortedResetNode
    {
        public byte[] Bytes;
        public SortedResetNode Next;
    }
    public sealed class FrameResetState
    {
        public DisplayResetState Global;
        public IList<DisplayResetState> Registered;
        public SortedResetNode SortedHead;
        public uint PendingCount;
        public byte[] ShaderTemplate;
    }
    public static class FrameReset
    {
        // This finite capacity is a portable validation boundary, not a
        // newly inferred original limit. Counts above it are not supported.
        public const int MaximumDecodedCount=1000000;
        private static void Need(byte[] b,int size)
        { if(b==null || b.Length<size) throw new ArgumentException("Truncated native record/buffer."); }
        private static uint Read(byte[] b,int p)
        { return (uint)b[p]|((uint)b[p+1]<<8)|((uint)b[p+2]<<16)|((uint)b[p+3]<<24); }
        private static void Write(byte[] b,int p,uint v)
        { b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24); }
        private static void Fill(byte[] b,int count,byte value)
        { Need(b,count);for(int i=0;i<count;++i)b[i]=value; }
        private static void Count(int n)
        { if(n<0 || n>MaximumDecodedCount)throw new ArgumentOutOfRangeException("count"); }
        public static int MaterialBufferBytes(int count)
        { Count(count);return count==0?0:((((count+7)/8)/16)+1)*16; }
        public static int ClipBufferBytes(int count)
        { Count(count);return count==0?0:(((((count+7)/8)*2)/16)+1)*16; }

        // Original 0x5fca40: seven explicitly sized sentinel writes.
        public static void ResetCommandContext(byte[] state)
        {
            Need(state,0x30);Write(state,8,0);Write(state,0x14,UInt32.MaxValue);Write(state,0x20,UInt32.MaxValue);
            foreach(int p in new int[]{0x24,0x2c,0x2e,0x1e}) {state[p]=255;state[p+1]=255;}
        }
        private static void ClearShaderSlots(byte[] state)
        {
            Need(state,0x19c);
            foreach(int p in new int[]{0xf4,0x100,0x168,0x34,0x110,0x180,0x198})Write(state,p,0);
        }
        // Original 0x5fd100: object cache first, global command context next.
        // Passing one array for both arguments preserves the alias case.
        public static void ResetShaderContext(byte[] state,byte[] globalTemplate)
        { ClearShaderSlots(state);ResetCommandContext(globalTemplate); }
        // Original 0x5fd160: both writes address the same global template.
        public static void ResetGlobalShaderContext(byte[] globalTemplate)
        { ClearShaderSlots(globalTemplate);ResetCommandContext(globalTemplate); }

        // Original 0x5ddd10: force is any nonzero32-bit value. Non-force reset
        // normalizes a material slot to (old==0), not old XOR1. Duplicate
        // record references therefore preserve repeated toggles in order.
        public static IList<uint> ResetDisplay(DisplayResetState scene,uint force)
        {
            if(scene==null)throw new ArgumentNullException("scene");
            List<uint> calls=new List<uint>();calls.Add(0x5ddd10);
            if(force==0 && (scene.Flags&6)==0)return calls;
            if(scene.Materials==null)throw new ArgumentException("Decoded material table required.");
            int parity=(int)((scene.Flags>>15)&1),mc=scene.Materials.Length;
            Count(mc);Count(scene.ClipCount);
            if(mc!=0)
            {
                if(scene.MaterialBuffers==null || scene.MaterialBuffers.Length!=2)throw new ArgumentException("Material parity buffers required.");
                Fill(scene.MaterialBuffers[parity],MaterialBufferBytes(mc),0);
            }
            if(scene.ClipCount!=0)
            {
                if(scene.ClipBuffers==null || scene.ClipBuffers.Length!=2)throw new ArgumentException("Clip parity buffers required.");
                int bytes=ClipBufferBytes(scene.ClipCount);Fill(scene.ClipBuffers[parity],bytes,0);
                if(force!=0)Fill(scene.ClipBuffers[1-parity],bytes,255);
            }
            foreach(MaterialResetRecord record in scene.Materials)
            {
                if(record==null)throw new ArgumentException("Null material record.");
                Need(record.Bytes,0x38);byte[] b=record.Bytes;Write(b,0x14,Read(b,0x10));
                uint slot=force!=0?0u:(Read(b,0x34)==0?1u:0u);Write(b,0x34,slot);Write(b,0x30,Read(b,0x28+(int)slot*4));
                calls.Add(0x5fca40);ResetCommandContext(record.Context);
            }
            scene.Flags&=0xfffffff1;return calls;
        }

        // Original 0x5dfab0 caller. The global display, registry and linked
        // list are decoded objects; their identity/aliasing is retained.
        // Only synchronization is an external callback; all resets are here.
        public static IList<uint> Advance(FrameResetState state,int lockHandle,Action<int> enterGate,Action<int> leaveGate)
        {
            if(state==null || state.Global==null || state.Registered==null || state.Registered.Count>256 || enterGate==null || leaveGate==null)throw new ArgumentException("Valid bounded frame state and explicit gate callbacks required.");
            List<uint> calls=new List<uint>();calls.Add(0x5dfab0);calls.Add(0x4ffaa0);enterGate(lockHandle);
            state.Global.Flags^=0x8000;calls.AddRange(ResetDisplay(state.Global,0));
            foreach(DisplayResetState scene in state.Registered)
            {
                if(scene==null)throw new ArgumentException("Null registered scene.");
                scene.Flags^=0x8000;calls.AddRange(ResetDisplay(scene,0));
                if(scene.Owner!=null){Need(scene.Owner,0x48);Write(scene.Owner,0x44,0);}
            }
            state.PendingCount=0;HashSet<SortedResetNode> seen=new HashSet<SortedResetNode>();
            for(SortedResetNode node=state.SortedHead;node!=null;node=node.Next)
            {
                if(seen.Count>=MaximumDecodedCount || !seen.Add(node))throw new ArgumentException("Finite acyclic sort list required.");
                Need(node.Bytes,0x18);Write(node.Bytes,0x14,Read(node.Bytes,0x14)&0xfffffffd);
            }
            calls.Add(0x5fd160);ResetGlobalShaderContext(state.ShaderTemplate);calls.Add(0x4ffac0);leaveGate(lockHandle);return calls;
        }
    }
}

