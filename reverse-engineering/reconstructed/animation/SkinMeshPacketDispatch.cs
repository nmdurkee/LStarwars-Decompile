// Original PC5e0530 non-billboard dispatch, including actual packet writers.
using System;
using Recovered.Geometry;
namespace Recovered.Animation
{
    public static class SkinMeshPacketDispatch
    {
        // Complete selector composition. Billboard precedence is evaluated
        // before any material, skin, weight or cache dereference. The prior
        // Build API below retains its original non-billboard contract.
        public static uint BuildWithBillboards(RenderPacketMemory memory,uint allocatorControl,uint record,uint material,int commandIndex,
            uint command,uint matrix,uint cache,uint output,MorphMeshResource resource,float[] weights,byte[][] jointMatrices,
            uint alphaWord,int metadata,uint scaleScratch,uint translationScratch,uint[] scratchInputs,float[] view,float[] cameraForward)
        {
            if(memory==null)throw new ArgumentNullException("memory");
            if(memory.Byte(command)==0x8f)
            {
                BillboardMeshPackets.Build(memory,allocatorControl,record,command,matrix,output,alphaWord,view,cameraForward);return 0x5e0490;
            }
            return Build(memory,allocatorControl,record,material,commandIndex,command,matrix,cache,output,resource,weights,jointMatrices,alphaWord,metadata,scaleScratch,translationScratch,scratchInputs);
        }
        // Original registers: ECX command, EDX world matrix, ESI record.
        // Stack: material,index,output,cache,skin,morph,alpha,metadata.
        // A null jointMatrices value represents a null skin pointer; a nonnull
        // empty array still selects the skin writer. There is no mode argument.
        // Return value is host diagnostic writer identity, not native EAX.
        public static uint Build(RenderPacketMemory memory,uint allocatorControl,uint record,uint material,int commandIndex,
            uint command,uint matrix,uint cache,uint output,MorphMeshResource resource,float[] weights,byte[][] jointMatrices,
            uint alphaWord,int metadata,uint scaleScratch,uint translationScratch,uint[] scratchInputs)
        {
            if(memory==null)throw new ArgumentNullException("memory");byte opcode=memory.Byte(command);
            if(opcode==0x8f)throw new NotSupportedException("Original billboard writer5e0490 remains outside this composition.");
            uint flags=0;byte previous=0;
            if(jointMatrices==null)
            {
                flags=memory.Dword(material+0xb4);
                if((flags&0x80000000)!=0&&commandIndex>1)previous=memory.Byte(command-32);
            }
            uint writer=DynamicCommandSupport.SelectPacketRoutine(opcode,previous,flags,commandIndex,jointMatrices==null?0:1);
            if(writer==0x5e0390)MorphMeshPackets.Build(memory,allocatorControl,record,command,matrix,cache,output,resource,weights,jointMatrices,metadata,scaleScratch,translationScratch,scratchInputs);
            else if(writer==0x5e02b0)OrdinaryMeshPackets.BuildWithPrefix(memory,allocatorControl,record,command,matrix,cache,output,alphaWord,scaleScratch,translationScratch,scratchInputs);
            else OrdinaryMeshPackets.BuildOrdinary(memory,allocatorControl,record,command,matrix,cache,output,alphaWord,metadata,scaleScratch,translationScratch,scratchInputs);
            return writer;
        }
    }
}
