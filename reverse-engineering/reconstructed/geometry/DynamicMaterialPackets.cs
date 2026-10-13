// Dynamic material packet dependencies. Original x86 checks:
// geometry-dynamic-packets-native-validation.json. C# execution pending.
using System;
namespace Recovered.Geometry
{
    public static class DynamicMaterialPackets
    {
        private static void Reserved(RenderPacketMemory m,uint packet)
        {m.Byte(packet,0x87);m.Dword(packet+4,0);m.Byte(packet+1,0);}
        // Original PC setters have additional ignored caller arguments.
        public static void SetReserved1(RenderPacketMemory m,uint packet){Reserved(m,packet);} //603440
        public static void SetReserved2(RenderPacketMemory m,uint packet){Reserved(m,packet);} //603450
        public static void SetMaterial(RenderPacketMemory m,uint packet,uint material) //603460
        {m.Byte(packet,0x80);m.Dword(packet+4,material);m.Byte(packet+1,3);}
        public static void SetReserved4(RenderPacketMemory m,uint packet){Reserved(m,packet);} //603480
        public static void SetReserved5(RenderPacketMemory m,uint packet){Reserved(m,packet);} //603490

        // Original0x5de100. No alignment is performed; always reserve128bytes.
        // Link index replaces global80baa8 (original image value8). The first
        // and fourth original caller arguments do not affect this PC helper.
        public static uint ConstructMaterial(RenderPacketMemory m,uint material,uint allocatorControl,uint linkCommandCount)
        {
            if(m==null || linkCommandCount<1 || linkCommandCount>255)throw new ArgumentException("Finite link count1..255 required.");
            uint p=m.Dword(allocatorControl);if((ulong)p+linkCommandCount*16>UInt32.MaxValue || p>UInt32.MaxValue-128)throw new ArgumentException("Pointer wrap outside finite image.");
            m.Dword(allocatorControl,p+128);m.Byte(p,0x85);m.Dword(p+4,p+linkCommandCount*16-16);m.Byte(p+1,1);
            SetReserved1(m,p+16);SetReserved2(m,p+32);SetMaterial(m,p+48,material);SetReserved4(m,p+64);SetReserved5(m,p+80);
            m.Dword(p+100,p+linkCommandCount*16-16);m.Byte(p+96,0x8b);m.Byte(p+97,1);
            m.Byte(p+112,0x84);m.Dword(p+116,0);m.Byte(p+113,4);return p;
        }
        // Inline native key expression, not an independently mapped entry.
        // The left shift truncates to signed16 before the arithmetic right
        // shift; priority+0x76 is also signed16.
        public static int MaterialSortKey(RenderPacketMemory m,uint material)
        {
            int layer=unchecked((short)(m.Word(material)<<4))>>8;
            return unchecked(layer*0x20000+(short)m.Word(material+0x76));
        }
        // Original0x5de390. Sum unsigned16 sort counts and search that many
        // material pointers for each nonempty group. A missing key leaves the
        // existing first index unchanged. Counts are caller-validated finite.
        public static void RefreshRanges(RenderPacketMemory m,uint scene)
        {
            if(m==null)throw new ArgumentNullException("m");uint count=m.Dword(scene+0x60);
            if(count>1000000)throw new ArgumentException("Nonnegative finite sort count required.");
            uint nodes=m.Dword(scene+0x64),total=0;
            for(uint i=0;i<count;++i)
            {
                total+=m.Word(nodes+i*36+0x20);if(total>1000000)throw new ArgumentException("Finite material search domain exceeded.");
            }
            for(uint i=0;i<count;++i)
            {
                uint node=m.Dword(scene+0x64)+i*36;
                if(m.Word(node+0x20)==0 || total==0)continue;
                uint table=m.Dword(scene+0x50);
                for(uint j=0;j<total;++j)
                {
                    if(unchecked((uint)MaterialSortKey(m,m.Dword(table+j*4)))==m.Dword(node))
                    {m.Word(node+0x22,unchecked((ushort)j));break;}
                }
            }
        }
    }
}

