// Original CPU shader-context payload emission, not GPU shader execution.
// Evidence: geometry-shader-emission-native-validation.json.
// Native/Python differential passed; compiled C# execution remains pending.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public static class ShaderContextEmission
    {
        // Integration adapter, not a new native entry. Connects the recovered
        // sorted caller to its recovered mutating shader emission callback.
        public static IList<uint[]> CompleteSorted(RenderPacketMemory memory,uint sortedHead,IList<uint> registered,uint globalTemplate,uint allocatorControl,uint descriptor,uint tokenBase)
        {
            List<IList<uint>> nested=new List<IList<uint>>();
            IList<uint[]> outer=SortedPackets.Complete(memory,sortedHead,registered,globalTemplate,
                delegate(RenderPacketMemory m,uint record,uint shader){nested.Add(Emit(m,allocatorControl,record,shader,descriptor,tokenBase));});
            List<uint[]> result=new List<uint[]>();int index=0;
            foreach(uint[] call in outer)
            {
                result.Add(call);
                if(call[0]==0x607590)
                {
                    IList<uint> inner=nested[index++];
                    for(int i=1;i<inner.Count;++i)result.Add(new uint[]{inner[i]});
                }
            }
            return result;
        }
        private static uint Align(RenderPacketMemory m,uint control)
        {
            uint p=m.Dword(control);if(p>UInt32.MaxValue-15)throw new ArgumentException("Allocator wrap outside finite image.");
            p=(p+15)&0xfffffff0;m.Dword(control,p);return p;
        }
        private static void Advance(RenderPacketMemory m,uint control,uint p,uint size)
        {
            if((ulong)p+size>UInt32.MaxValue)throw new ArgumentException("Allocator wrap outside finite image.");
            m.Dword(control,p+size);
        }
        // Original0x5fcdf0. Opaque vector/matrix words are copied exactly;
        // inserted vector W values are1.0 bits. No float arithmetic occurs.
        public static uint BuildVectorMatrixPayload(RenderPacketMemory m,uint control,uint shader)
        {
            uint p=Align(m,control);Advance(m,control,p,188);
            int[,] pairs=new int[,]{{0,0x38},{4,0x68},{16,0x44},{8,0x74},{20,0x50},{12,0x80},{24,0x5c}};
            for(int k=0;k<7;++k)
            {
                for(int j=0;j<3;++j)m.Dword(p+(uint)((pairs[k,0]+j)*4),m.Dword(shader+(uint)(pairs[k,1]+j*4)));
                m.Dword(p+(uint)((pairs[k,0]+3)*4),0x3f800000);
            }
            for(uint j=0;j<16;++j)m.Dword(p+(28+j)*4,m.Dword(shader+0x90+j*4));
            for(uint j=0;j<3;++j)m.Dword(p+(44+j)*4,m.Dword(shader+0xd0+j*4));return p;
        }
        // Original0x5fcef0: default1.0 or raw shader+0xf8, selected by+0xf4.
        public static uint BuildOptionalScalarPayload(RenderPacketMemory m,uint control,uint shader)
        {
            uint p=Align(m,control);m.Dword(p,m.Dword(shader+0xf4)!=0?m.Dword(shader+0xf8):0x3f800000);Advance(m,control,p,4);return p;
        }
        // Original0x5fcf30.
        public static uint BuildWordPayload(RenderPacketMemory m,uint control,uint shader)
        {
            uint p=Align(m,control);m.Dword(p,m.Dword(shader+0x194));Advance(m,control,p,4);return p;
        }
        // Original0x5fcf60: one word if+0x16c is0,otherwise five words.
        public static uint BuildConditionalWordsPayload(RenderPacketMemory m,uint control,uint shader)
        {
            uint p=Align(m,control);uint enabled=m.Dword(shader+0x16c);m.Dword(p,enabled);Advance(m,control,p,4);
            if(enabled!=0)
            {
                int[] offsets=new int[]{0x178,0x170,0x174,0x17c};
                for(int i=0;i<4;++i){m.Dword(p+4+(uint)i*4,m.Dword(shader+(uint)offsets[i]));Advance(m,control,p,8+(uint)i*4);}
            }
            return p;
        }
        // Original0x5fcfd0. Global descriptor argument replaces0x9738a4.
        // Count and secondary byte become DWORDs; signed source bytes become
        // exact float32 integers. Rounded trailing slots retain arena bytes.
        public static uint BuildSignedBytePayload(RenderPacketMemory m,uint control,uint descriptor)
        {
            if(descriptor==0)return 0;
            uint p=Align(m,control);byte count=m.Byte(descriptor);m.Dword(p,count);m.Dword(p+4,m.Byte(descriptor+2));
            Advance(m,control,p,8+(uint)((count+3)/4)*16);uint source=m.Dword(descriptor+4);
            for(uint j=0;j<count;++j)
            {
                float value=(sbyte)m.Byte(source+j);
                uint bits=unchecked((uint)BitConverter.ToInt32(BitConverter.GetBytes(value),0));m.Dword(p+8+j*4,bits);
            }
            return p;
        }
        private static uint BuildMatrixPayload(RenderPacketMemory m,uint control,uint shader,uint tokenBase)
        {
            uint p=Align(m,control);m.Dword(shader+0x110,p);
            uint token=unchecked((uint)((short)m.Word(shader+0x2c)+5)*(m.Dword(shader+0x20)+13)+tokenBase);
            m.Dword(p,token);Advance(m,control,p,4);
            for(uint i=0;i<16;++i)m.Dword(p+4+i*4,m.Dword(shader+0x114+i*4));Advance(m,control,p,68);
            // Original memset initializes this64-byte stack-derived matrix;
            // five explicitly assigned words replace zeroes before copying.
            byte[] block=new byte[64];RenderPacketMemory local=new RenderPacketMemory(0,block);
            int[,] map=new int[,]{{0,0x154},{20,0x158},{40,0x15c},{44,0x160},{56,0x164}};
            for(int i=0;i<5;++i)local.Dword((uint)map[i,0],m.Dword(shader+(uint)map[i,1]));
            m.Block(p+68,block);Advance(m,control,p,132);
            for(uint i=0;i<4;++i){m.Dword(p+132+i*4,m.Dword(shader+0x184+i*4));Advance(m,control,p,136+i*4);}
            return p;
        }
        // Original0x607590. Three supplied values replace its fixed globals:
        // allocatorControl0x9736e0,descriptor0x9738a4,tokenBase0x297dc00.
        // Valid disjoint record/context/arena storage and uint address domain.
        public static IList<uint> Emit(RenderPacketMemory m,uint allocatorControl,uint record,uint shader,uint signedByteDescriptor,uint tokenBase)
        {
            if(m==null)throw new ArgumentNullException("m");List<uint> calls=new List<uint>();calls.Add(0x607590);
            if(shader==0 || m.Dword(m.Dword(record+8)+0x20)==m.Dword(shader+0x20))return calls;
            uint context=m.Dword(record+8);
            int[] keys=new int[]{0x24,0x2c,0x2e,0x1e,0x32,0x30},caches=new int[]{0x34,0x110,0x168,0x180,0x198,0};
            uint[] helpers=new uint[]{0x5fcdf0,0,0x5fcf60,0x5fcef0,0x5fcf30,0x5fcfd0},commands=new uint[]{0x94,0x9a,0xa6,0xa5,0xab,0xa9};
            for(int i=0;i<6;++i)
            {
                if(m.Word(context+(uint)keys[i])==m.Word(shader+(uint)keys[i]))continue;
                uint payload=caches[i]==0?0:m.Dword(shader+(uint)caches[i]);
                if(i==5)
                {
                    calls.Add(0x5fcfd0);payload=BuildSignedBytePayload(m,allocatorControl,signedByteDescriptor);
                }
                else if(payload==0)
                {
                    if(helpers[i]!=0)calls.Add(helpers[i]);
                    switch(i)
                    {
                        case 0:payload=BuildVectorMatrixPayload(m,allocatorControl,shader);break;
                        case 1:payload=BuildMatrixPayload(m,allocatorControl,shader,tokenBase);break;
                        case 2:payload=BuildConditionalWordsPayload(m,allocatorControl,shader);break;
                        case 3:payload=BuildOptionalScalarPayload(m,allocatorControl,shader);break;
                        case 4:payload=BuildWordPayload(m,allocatorControl,shader);break;
                    }
                    m.Dword(shader+(uint)caches[i],payload);
                }
                if(payload!=0){calls.Add(0x6034b0);SortedPackets.Append(m,allocatorControl,record,commands[i],payload);}
                m.Word(context+(uint)keys[i],m.Word(shader+(uint)keys[i]));
            }
            m.Dword(context+0x20,m.Dword(shader+0x20));return calls;
        }
    }
}

