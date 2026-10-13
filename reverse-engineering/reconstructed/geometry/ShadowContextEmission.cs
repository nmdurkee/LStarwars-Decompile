// Original0x607820 CPU shadow-context update; GPU interpretation separate.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public static class ShadowContextEmission
    {
        // Original global allocator/descriptor become explicit inputs. Valid
        // bounded disjoint writable context/payload/command images required.
        public static IList<uint> Emit(RenderPacketMemory memory,uint allocatorControl,uint record,uint shader,uint signedByteDescriptor)
        {
            if(memory==null)throw new ArgumentNullException("memory");var calls=new List<uint>();calls.Add(0x607820);
            if(shader==0||memory.Dword(memory.Dword(record+8)+0x20)==memory.Dword(shader+0x20))return calls;
            if(memory.Word(memory.Dword(record+8)+0x30)!=memory.Word(shader+0x30))
            {
                calls.Add(0x5fcfd0);uint payload=ShaderContextEmission.BuildSignedBytePayload(memory,allocatorControl,signedByteDescriptor);
                if(payload!=0){calls.Add(0x6034b0);SortedPackets.Append(memory,allocatorControl,record,0xa9,payload);}
                memory.Word(memory.Dword(record+8)+0x30,memory.Word(shader+0x30));
            }
            memory.Dword(memory.Dword(record+8)+0x20,memory.Dword(shader+0x20));return calls;
        }
    }
}
