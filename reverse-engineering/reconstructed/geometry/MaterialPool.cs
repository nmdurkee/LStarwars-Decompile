// Original material pool/default initialization CPU behavior. Successful
// capacity and zero-lock branch only; no shader or GPU construction here.
using System;
namespace Recovered.Geometry
{
    public sealed class MaterialPoolState
    {
        public uint Pool,PendingMaterials;
        public int Capacity,PendingCount,LockToken;
    }
    public static class MaterialPool
    {
        // Original5e5140. Null pointer is a no-op; reset exactly520 bytes.
        public static void ResetRuntime(RenderPacketMemory m,uint runtime)
        {
            if(runtime==0)return;m.Block(runtime,new byte[0x208]);
            m.Dword(runtime+0x1b8,0x1000);m.Dword(runtime+0x24,0x3f800000);m.Dword(runtime+0x13c,0x101);m.Dword(runtime,0x1000);m.Dword(runtime+0x14,0xff8080ff);
            for(uint i=0;i<4;++i)m.Dword(runtime+0x10c+i*4,0xffffffff);
        }
        private static uint ColorByte(RenderPacketMemory m,uint p)
        {
            float value=BitConverter.ToSingle(m.Block(p,4),0);double scaled=(double)value*255.0;
            if(Double.IsNaN(scaled)||Double.IsInfinity(scaled)||scaled<Int32.MinValue||scaled>Int32.MaxValue)throw new ArgumentException("Finite Int32-range color products required.");
            // Native forces x87 rounding toward zero before each FISTP.
            // Float32*255 has at most32 significant bits, exact in double.
            return unchecked((uint)(int)scaled)&255;
        }
        // Original600f20. Only the final allocation in a native chain invokes
        // this routine. Colors wrap low bytes; they are not clamped/rounded.
        public static void Initialize(RenderPacketMemory m,uint material,int registered)
        {
            ResetRuntime(m,checked(material+0xb4));short count=unchecked((short)m.Word(material+0x74));
            if(count<1)m.Dword(material+0xc8,0xff000000|(ColorByte(m,material+0x5c)<<16)|(ColorByte(m,material+0x58)<<8)|ColorByte(m,material+0x54));
            else
            {
                m.Dword(material+0xb8,(uint)count);if(m.Byte(material+0x15c)==0)m.Byte(material+0x15c,1);
                uint format=m.Dword(material+0x1f0);if((format&0x3800)==0)m.Dword(material+0x1f0,(format&0xffffcfff)|0x800);
            }
            if(registered==0)m.Dword(material+0x1f0,m.Dword(material+0x1f0)|0x40000);
        }
        // Original5e4b20: ECX=count,EAX=typeWord,stackarg=registered.
        // Fixed pool globals/registration queue become mutable explicit state.
        // Native exhaustion invokes fatal diagnostics and continues unsafely;
        // this projection requires sufficient free slots and queue capacity.
        public static uint Allocate(RenderPacketMemory m,MaterialPoolState state,int count,uint typeWord,int registered)
        {
            if(m==null||state==null||state.Pool==0||count<=0||count>1000000||state.Capacity<=0||state.Capacity>1000000)throw new ArgumentException("Positive bounded successful pool allocation required.");
            if(state.LockToken!=0)throw new NotSupportedException("Only original zero-lock branch is represented.");
            if(registered!=0&&(state.PendingCount<0||(long)state.PendingCount+count>600))throw new ArgumentException("Native600-entry pending queue capacity required.");
            uint head=0;
            for(int j=0;j<count;++j)
            {
                uint p=0;for(int i=0;i<state.Capacity;++i){uint candidate=checked(state.Pool+(uint)i*708);if((m.Byte(candidate)&1)==0&&m.Dword(candidate+0x3c)==0){p=candidate;break;}}
                if(p==0)throw new ArgumentException("Native material pool exhausted.");m.Block(p,new byte[708]);
                m.Dword(p+0x54,0x3f800000);m.Dword(p+0x58,0x3f800000);m.Dword(p+0x5c,0x3f800000);m.Dword(p+0x70,0x3f800000);m.Dword(p+0x44,0x10);m.Dword(p+0x40,0x3f962010);m.Word(p,(ushort)(((typeWord&255)<<4)|5));
                if(registered==0)m.Dword(p+0x44,m.Dword(p+0x44)|0x800000);
                else {m.Dword(checked(state.PendingMaterials+(uint)state.PendingCount*4),p);++state.PendingCount;}
                m.Dword(p+0x30,head);head=p;
            }
            Initialize(m,head,registered);return head;
        }
    }
}
