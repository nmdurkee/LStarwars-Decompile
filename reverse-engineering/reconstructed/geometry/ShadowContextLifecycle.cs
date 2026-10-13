// Original selective shallow copies and copy-before-reset frame snapshot.
using System;
namespace Recovered.Geometry
{
    public static class ShadowContextLifecycle
    {
        static void CopyDomain(uint destination,uint source,uint size)
        {if(destination!=source&&(ulong)destination<(ulong)source+size&&(ulong)source<(ulong)destination+size)throw new NotSupportedException("Partial copy overlap is outside verified domain.");}
        static void Words(RenderPacketMemory m,uint destination,uint source,uint first,uint end)
        {for(uint p=first;p<end;p+=4)m.Dword(checked(destination+p),m.Dword(checked(source+p)));}
        //0x5c8a00: gaps114..11f,264..26f,378..37f are untouched.
        public static void CopyVolume(RenderPacketMemory m,uint destination,uint source)
        {CopyDomain(destination,source,0x380);Words(m,destination,source,0,0x114);Words(m,destination,source,0x120,0x264);Words(m,destination,source,0x270,0x378);}
        //0x5e8da0: two selective volumes and context tail, retaining padding.
        public static void CopyContext(RenderPacketMemory m,uint destination,uint source)
        {
            CopyDomain(destination,source,0x830);CopyVolume(m,destination,source);CopyVolume(m,checked(destination+0x380),checked(source+0x380));Words(m,destination,source,0x700,0x714);Words(m,destination,source,0x720,0x828);
        }
        static int VolumeCount(RenderPacketMemory m,uint context)
        {int count=unchecked((int)m.Dword(context+0x70c));if(count>2)throw new ArgumentException("Constructed context has at most two volumes.");return count;}
        //0x55f3e0: only disabled->nonzero rewinds tails. Raw flag is retained;
        // there is no registry/cache invalidation in this original helper.
        public static void SetEnabled(RenderPacketMemory m,uint context,uint value)
        {
            if(value!=0&&m.Dword(context+0x808)==0)for(int vi=0;vi<VolumeCount(m,context);++vi)for(uint alternate=0;alternate<2;++alternate){uint record=context+(uint)vi*0x380+0x2a4+alternate*0x44;m.Dword(record+0x14,m.Dword(record+0x10));}m.Dword(context+0x808,value);
        }
        //0x5f3020: destination preserves old fields and shallow pointers. Then
        // original SOURCE counts/tails and shared cache/head resources reset.
        // Requires disjoint successful arena and resources; pointer wrapping
        // and partial overlap are outside the verified native fixture domain.
        public static uint Snapshot(RenderPacketMemory m,uint source,uint allocatorControl)
        {
            ulong wide=((ulong)m.Dword(allocatorControl)+31UL)&~31UL;if(wide+0x830UL>UInt32.MaxValue)throw new ArgumentException("Nonwrapping snapshot capacity required.");uint destination=(uint)wide;CopyDomain(destination,source,0x830);if(destination==source)throw new ArgumentException("Snapshot arena must be disjoint from source.");m.Dword(allocatorControl,destination+0x830);CopyContext(m,destination,source);
            for(int vi=0;vi<VolumeCount(m,source);++vi)
            {
                uint volume=source+(uint)vi*0x380;m.Dword(volume+0x374,0);
                for(uint alternate=0;alternate<2;++alternate)
                {
                    uint record=volume+0x2a4+alternate*0x44,shader=m.Dword(record+8);byte[] cache=m.Block(shader,0x40);FrameReset.ResetCommandContext(cache);m.Block(shader,cache);uint head=m.Dword(record+0x10);m.Dword(record+0x14,head);m.Byte(head,0x8d);m.Dword(head+4,0);m.Byte(head+1,1);
                }
            }
            return destination;
        }
    }
}
