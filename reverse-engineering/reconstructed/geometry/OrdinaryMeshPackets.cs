// Ordinary dynamic mesh packet writers and original matrix payload producer.
// Evidence: geometry-ordinary-packets-native-validation.json. Managed pending.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public static class OrdinaryMeshPackets
    {
        private static void RequireWord(uint word)
        {if((word&0x7f800000)==0x7f800000 && (word&0x7fffff)!=0 && (word&0x400000)==0)throw new ArgumentException("Signaling NaN outside validated float-copy domain.");}
        private static void Pair(RenderPacketMemory m,uint destination,uint source,uint a,uint b)
        {uint temp=m.Dword(source+a*4);m.Dword(destination+a*4,m.Dword(source+b*4));m.Dword(destination+b*4,temp);}
        // Original5f7610. Ordered pairs retain in-place and partial-overlap
        // behavior, which differs from first copying a complete source array.
        public static void Transpose(RenderPacketMemory m,uint destination,uint source)
        {
            for(uint i=0;i<16;++i)RequireWord(m.Dword(source+i*4));
            m.Dword(destination,m.Dword(source));Pair(m,destination,source,1,4);Pair(m,destination,source,2,8);Pair(m,destination,source,3,12);m.Dword(destination+20,m.Dword(source+20));Pair(m,destination,source,6,9);Pair(m,destination,source,7,13);m.Dword(destination+40,m.Dword(source+40));Pair(m,destination,source,11,14);m.Dword(destination+60,m.Dword(source+60));
        }
        // Original603580: first two inputs are allocator control and matrix.
        // Three trailing native arguments (material,mesh,prior payload) do not
        // affect this PC helper. Global80e258..64 and two scratch destinations
        // become explicit. The two context getter results are unused.
        public static uint BuildTransform(RenderPacketMemory m,uint allocatorControl,uint matrix,uint scaleScratch,uint translationScratch,uint[] inputs)
        {
            if(inputs==null || inputs.Length!=4)throw new ArgumentException("Four scratch input words required.");foreach(uint word in inputs)RequireWord(word);
            m.Block(scaleScratch,new byte[64]);m.Dword(scaleScratch,inputs[0]);m.Dword(scaleScratch+20,inputs[1]);m.Dword(scaleScratch+40,0x3f800000);m.Dword(scaleScratch+60,0x3f800000);
            m.Block(translationScratch,new byte[64]);for(uint i=0;i<4;++i)m.Dword(translationScratch+i*20,0x3f800000);m.Dword(translationScratch+48,inputs[2]);m.Dword(translationScratch+52,inputs[3]);
            ulong address=((ulong)m.Dword(allocatorControl)+3UL)&~3UL;if(address+64>uint.MaxValue)throw new ArgumentException("Native pointer wrapping outside supported domain.");uint result=(uint)address;m.Dword(allocatorControl,result);Transpose(m,result,matrix);m.Dword(allocatorControl,m.Dword(allocatorControl)+64);return result;
        }
        private static uint WriteCommand(RenderPacketMemory m,uint record,byte opcode,uint resource)
        {uint p=m.Dword(record+0x24);m.Byte(p,opcode);m.Byte(p+1,3);m.Dword(p+4,resource);m.Dword(record+0x24,p+16);return p;}
        private static IList<uint> Build(RenderPacketMemory m,uint allocatorControl,uint record,uint command,uint matrix,uint cache,uint output,uint alphaWord,int metadata,uint scaleScratch,uint translationScratch,uint[] inputs,bool prefix)
        {
            List<uint> calls=new List<uint>();calls.Add(prefix?0x5e02b0U:0x5e0200U);calls.Add(0x603530);
            if(prefix)m.Dword(allocatorControl,checked((uint)(((ulong)m.Dword(allocatorControl)+15UL)&~15UL)));
            DynamicCommandSupport.Reserve(m,allocatorControl,record,prefix?3:2);uint resource=m.Dword(command+4);
            if(prefix)m.Dword(output,WriteCommand(m,record,m.Byte(command-32),m.Dword(command-28)));
            // Original computes these valid-memory reads before invoking603580,
            // even though that helper ignores the material and cached payload.
            uint owner=m.Dword(record);m.Dword(m.Dword(owner+0x50)+m.Dword(record+4)*4);m.Dword(cache);
            uint payload=BuildTransform(m,allocatorControl,matrix,scaleScratch,translationScratch,inputs);calls.AddRange(new uint[]{0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610});m.Dword(cache,payload);
            uint first=WriteCommand(m,record,0x8c,payload);m.Dword(output+(prefix?4U:0U),first);uint second=WriteCommand(m,record,0x82,resource);m.Dword(output+(prefix?8U:4U),second);calls.Add(0x603ad0);DynamicCommandSupport.StoreAlpha(m,first,alphaWord);
            if(!prefix){calls.Add(0x603b10);DynamicCommandSupport.StoreSignedMetadata(m,first,metadata);}return calls;
        }
        // Original5e0200: two commands8c(transform),82(mesh), alpha + metadata.
        public static IList<uint> BuildOrdinary(RenderPacketMemory m,uint allocatorControl,uint record,uint command,uint matrix,uint cache,uint output,uint alphaWord,int metadata,uint scaleScratch,uint translationScratch,uint[] inputs)
        {return Build(m,allocatorControl,record,command,matrix,cache,output,alphaWord,metadata,scaleScratch,translationScratch,inputs,false);}
        // Original5e02b0 copies source command-32 opcode/resource, then8c/82.
        // Only alpha is patched; the metadata lane retains its matrix value.
        public static IList<uint> BuildWithPrefix(RenderPacketMemory m,uint allocatorControl,uint record,uint command,uint matrix,uint cache,uint output,uint alphaWord,uint scaleScratch,uint translationScratch,uint[] inputs)
        {return Build(m,allocatorControl,record,command,matrix,cache,output,alphaWord,0,scaleScratch,translationScratch,inputs,true);}
    }
}
