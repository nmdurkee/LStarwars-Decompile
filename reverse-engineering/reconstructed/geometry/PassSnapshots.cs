// Original CPU pass snapshot5f3950 and direct entry thunk5f39e0.
using System;
namespace Recovered.Geometry
{
    public static class PassSnapshots
    {
        static uint Read(byte[] b,int p){return BitConverter.ToUInt32(b,p);}
        static void Write(byte[] b,int p,uint v){Array.Copy(BitConverter.GetBytes(v),0,b,p,4);}
        // Current adapts9718a0; snapshots adapts9640f0; count adapts95fbb8.
        // Distinct arrays, valid finite capacity, volumes0/1, and at most eight
        // pending indices per volume are required. No draw/GPU callback occurs.
        public static void Capture(RenderPacketMemory memory,PendingPacketState pending,byte[] current,byte[] snapshots,ref int count)
        {
            if(current==null||current.Length<0x218||snapshots==null||Object.ReferenceEquals(current,snapshots)||count<0||((long)count+1)*0x218>snapshots.Length)
                throw new ArgumentException("Disjoint complete pass buffers and available snapshot capacity required.");
            int index=PendingPackets.FinalizeList(memory,pending);Write(current,0,unchecked((uint)index));
            if(Read(current,0x38)!=0&&index!=-1)
            {
                uint context=Read(current,0x3c);
                if(memory.Dword(checked(context+0x808))==0)Write(current,0x38,0);
                else
                {
                    uint volume=Read(current,0x40);if(volume>1)throw new ArgumentException("Constructed volume index0/1 required.");
                    uint address=checked(context+volume*0x380),entries=memory.Dword(address+0x374);
                    if(entries>=8)throw new ArgumentException("Eight-entry volume pass-index capacity required.");
                    memory.Dword(checked(address+0x354+entries*4),(uint)index);memory.Dword(address+0x374,entries+1);
                }
                // Includes the disabled-context branch, where index is dropped.
                Write(current,0,UInt32.MaxValue);
            }
            Array.Copy(current,0,snapshots,count*0x218,0x218);++count;
        }
        // Direct jmp5f3950. The caller's extra stack argument is unused.
        public static void CaptureThunk(RenderPacketMemory memory,PendingPacketState pending,byte[] current,byte[] snapshots,ref int count)
        {Capture(memory,pending,current,snapshots,ref count);}
    }
}
