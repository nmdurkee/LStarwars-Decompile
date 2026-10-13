// Original dynamic command support. Native evidence:
// geometry-dynamic-command-native-validation.json. Managed equality pending.
using System;
namespace Recovered.Geometry
{
    public static class DynamicCommandSupport
    {
        private static void RequireStoredFloatWord(uint word)
        {
            if((word&0x7f800000)==0x7f800000 && (word&0x7fffff)!=0 && (word&0x400000)==0)
                throw new ArgumentException("Signaling NaN excluded: isolated emulator load/store behavior is not physical-PC evidence.");
        }
        // Original603530 returns the allocator-control pointer in EAX.
        // Caller reserves count16-byte slots followed by the native8d link.
        public static uint Reserve(RenderPacketMemory memory,uint allocatorControl,uint record,int count)
        {
            if(memory==null || count<0 || count>1000000)throw new ArgumentException("Finite command reservation required.");
            ulong wide=((ulong)memory.Dword(allocatorControl)+15UL)&~15UL;
            if(wide+(ulong)count*16UL+16UL>uint.MaxValue)throw new ArgumentException("Native pointer wrapping outside supported domain.");
            uint start=(uint)wide;memory.Dword(allocatorControl,start);memory.Dword(memory.Dword(record+0x14)+4,start);memory.Dword(record+0x24,start);
            uint tail=start+(uint)count*16;memory.Dword(allocatorControl,tail);memory.Byte(tail,0x8d);memory.Byte(tail+1,1);memory.Dword(tail+4,memory.Dword(record+0x18)+16);memory.Dword(record+0x14,tail);memory.Dword(allocatorControl,tail+16);return allocatorControl;
        }
        // Original603ad0, complete command.resource+3c store. The second
        // native command argument is unused. Raw words preserve quiet-NaN
        // payload and signed zero without depending on host NaN arithmetic.
        public static void StoreAlpha(RenderPacketMemory memory,uint command,uint word)
        {
            RequireStoredFloatWord(word);uint magnitude=word&0x7fffffff,result=word;
            if(magnitude<=0x7f800000)
            {
                if((word&0x80000000)!=0 && magnitude!=0)result=0;
                else if((word&0x80000000)==0 && word>0x3f800000)result=0x3f800000;
            }
            memory.Dword(memory.Dword(command+4)+60,result);
        }
        // Original603b10 signed32 FILD followed by float32 store.
        // The second native command argument is unused.
        public static void StoreSignedMetadata(RenderPacketMemory memory,uint command,int value)
        {memory.Block(memory.Dword(command+4)+56,BitConverter.GetBytes((float)value));}
        // Original5fd220. The native second and fourth arguments are unused.
        // Shader state0x9868a0 becomes an explicit pointer; both IDs wrap.
        public static void SetOverride(RenderPacketMemory memory,uint shader,uint first,uint scalarWord,uint material)
        {
            RequireStoredFloatWord(scalarWord);memory.Dword(shader+0xf8,scalarWord);memory.Dword(shader+0xfc,material);memory.Dword(shader+0x20,unchecked(memory.Dword(shader+0x20)+1));memory.Word(shader+0x1e,unchecked((ushort)(memory.Word(shader+0x1e)+1)));memory.Dword(shader+0xf4,first);memory.Dword(shader+0x180,0);
        }
        // Selection branch only from5e0530: the selected packet writer and
        // its argument/register forwarding remain outside this pure adapter.
        public static uint SelectPacketRoutine(byte opcode,byte previousOpcode,uint materialFlags,int commandCount,int mode)
        {
            if(opcode==0x8f)return 0x5e0490;
            if(mode!=0)return 0x5e0390;
            if((materialFlags&0x80000000)!=0 && commandCount>1 && (previousOpcode==0xb0 || previousOpcode==0xae || previousOpcode==0xaf))return 0x5e02b0;
            return 0x5e0200;
        }
    }
}
