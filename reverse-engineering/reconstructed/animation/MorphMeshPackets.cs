// PC0x5e0390 morph packet writer, composing recovered CPU payload producers.
using System;
using System.Collections.Generic;
using Recovered.Geometry;
namespace Recovered.Animation
{
    public static class MorphMeshPackets
    {
        static uint Command(RenderPacketMemory memory,uint record,byte opcode,uint payload)
        {
            uint address=memory.Dword(record+0x24);memory.Byte(address,opcode);memory.Byte(address+1,3);memory.Dword(address+4,payload);memory.Dword(record+0x24,checked(address+16));return address;
        }
        // EAX(record) and EDI(output) become explicit parameters. The memory
        // image retains packet/payload pointers; decoded delta arrays and the
        // successful vertex-buffer lock are the existing CPU morph adapters.
        // Source, targets, arena, matrix and control storage must be disjoint.
        public static IList<uint> Build(RenderPacketMemory memory,uint allocatorControl,uint record,uint command,
            uint matrix,uint cache,uint output,MorphMeshResource resource,float[] weights,byte[][] jointMatrices,
            int metadata,uint scaleScratch,uint translationScratch,uint[] scratchInputs)
        {
            if(memory==null||resource==null||resource.SourceAddress!=memory.Dword(command+4))throw new ArgumentException("Resolved source mesh must match command resource");
            var calls=new List<uint>();calls.Add(0x5e0390);memory.Dword(allocatorControl,checked((uint)(((ulong)memory.Dword(allocatorControl)+15UL)&~15UL)));
            DynamicCommandSupport.Reserve(memory,allocatorControl,record,3);calls.Add(0x603530);
            // These valid reads occur in the original even though603580 ignores
            // the material and previous cached payload passed by the caller.
            uint owner=memory.Dword(record);memory.Dword(memory.Dword(owner+0x50)+memory.Dword(record+4)*4);memory.Dword(cache);
            uint transform=OrdinaryMeshPackets.BuildTransform(memory,allocatorControl,matrix,scaleScratch,translationScratch,scratchInputs);
            calls.AddRange(new uint[]{0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610});memory.Dword(cache,transform);
            uint first=Command(memory,record,0x8c,transform);memory.Dword(output,first);
            resource.Descriptor=memory.Block(resource.SourceAddress,56);bool deform=weights!=null&&memory.Dword(resource.SourceAddress+40)!=0;
            MorphMeshBuild built=MorphMeshDeformation.Build(resource,weights,jointMatrices,memory.Dword(allocatorControl));calls.Add(0x603710);
            memory.Block(resource.SourceAddress,resource.Descriptor);memory.Block(built.DescriptorAddress,built.Descriptor);
            if(deform){memory.Block(built.VertexAddress,built.Vertices);calls.AddRange(new uint[]{0x6e5b90,0x4ef660,0x6e5bc0});}
            memory.Block(built.PaletteAddress,built.Palette);memory.Dword(allocatorControl,built.NextCursor);
            uint palette=Command(memory,record,0x99,built.PaletteAddress);memory.Dword(output+4,palette);
            uint mesh=Command(memory,record,0x98,built.DescriptorAddress);memory.Dword(output+4,mesh);
            // output+4 is overwritten with the LAST command. output+8 remains
            // untouched: original603710 ignores its sixth caller argument.
            DynamicCommandSupport.StoreAlpha(memory,first,0x3f800000);calls.Add(0x603ad0);
            DynamicCommandSupport.StoreSignedMetadata(memory,first,metadata);calls.Add(0x603b10);return calls;
        }
    }
}
