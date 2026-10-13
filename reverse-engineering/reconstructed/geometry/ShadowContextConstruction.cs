// Original CPU shadow context pools and construction. No device operations.
using System;
namespace Recovered.Geometry
{
    public static class ShadowContextConstruction
    {
        static uint Allocate(RenderPacketMemory m,uint pool,uint stride)
        {
            uint bits=checked(pool+stride*8),cursor=m.Dword(bits+4);if(cursor>=8)throw new ArgumentException("Pool cursor0..7 required.");
            for(uint offset=0;offset<8;++offset)
            {
                uint index=(cursor+offset)&7;byte mask=m.Byte(bits);
                if((mask&(1<<(int)index))!=0)continue;
                m.Byte(bits,(byte)(mask|(1<<(int)index)));m.Dword(bits+4,(index+1)&7);return checked(pool+index*stride);
            }
            return 0;
        }
        // Original5f20c0,5f2160,5f2200; each scans forward then wraps.
        public static uint AllocateContext(RenderPacketMemory m,uint pool){return Allocate(m,pool,0x830);}
        public static uint AllocateShaderContext(RenderPacketMemory m,uint pool){return Allocate(m,pool,0x40);}
        public static uint AllocateCommand(RenderPacketMemory m,uint pool){return Allocate(m,pool,0x10);}
        // Original5f5ce0. Requires two available slots in each subordinate
        // pool, disjoint valid buffers; native exhausted resources dereference0.
        public static uint InitializeVolume(RenderPacketMemory m,uint volume,uint commandPool,uint shaderPool)
        {
            m.Dword(volume+0x100,0x3c23d70a);m.Dword(volume+0x104,0x3a83126f);m.Dword(volume+0x374,0);m.Dword(volume+0x110,0x3f800000);m.Dword(volume+0x260,0);
            for(uint i=0;i<2;++i)
            {
                uint head=AllocateCommand(m,commandPool);m.Dword(volume+0x334+i*4,head);uint shader=AllocateShaderContext(m,shaderPool);m.Dword(volume+0x32c+i*4,shader);
                if(head==0||shader==0)throw new NotSupportedException("Native constructor requires successful subordinate pool allocations.");
                uint record=checked(volume+0x2a4+i*0x44);m.Block(record,new byte[0x44]);m.Dword(record+0x10,head);m.Byte(head,0x8d);m.Dword(head+4,0);m.Byte(head+1,1);m.Dword(record+0x14,head);m.Dword(record+8,shader);
                byte[] cache=m.Block(shader,0x40);FrameReset.ResetCommandContext(cache);m.Block(shader,cache);m.Dword(record+0x14,m.Dword(record+0x10));
            }
            return volume;
        }
        // Original5f5d90 initializes exactly two volumes, then scalar defaults.
        public static uint InitializeContext(RenderPacketMemory m,uint context,uint commandPool,uint shaderPool)
        {
            InitializeVolume(m,context,commandPool,shaderPool);InitializeVolume(m,checked(context+0x380),commandPool,shaderPool);
            m.Dword(context+0x810,0x40800000);m.Dword(context+0x808,0);m.Dword(context+0x710,0);m.Dword(context+0x814,0x3e800000);m.Dword(context+0x800,0);m.Dword(context+0x804,0);m.Dword(context+0x80c,0x3f4ccccd);m.Dword(context+0x824,0);m.Dword(context+0x818,0);m.Dword(context+0x70c,2);m.Dword(context+0x81c,0x42c80000);m.Dword(context+0x820,0x42dc0000);return context;
        }
        // Original5f7420 replaces fixed pool globals by explicit addresses.
        // An exhausted context pool returns0 without touching other pools.
        public static uint Create(RenderPacketMemory m,uint contextPool,uint commandPool,uint shaderPool)
        {uint context=AllocateContext(m,contextPool);return context==0?0:InitializeContext(m,context,commandPool,shaderPool);}
    }
}
