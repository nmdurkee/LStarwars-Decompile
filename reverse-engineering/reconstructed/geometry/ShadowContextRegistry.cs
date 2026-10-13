// Original PC four-slot secondary/shadow context registry. CPU state only.
using System;
namespace Recovered.Geometry
{
    public sealed class ShadowContextRegistryState
    {
        public int Count;
        public uint CacheFlag;
        // Logical pointer and mask arrays; unused slots are deliberately kept.
        public uint[] Contexts,Masks;
    }
    public static class ShadowContextRegistry
    {
        static void ValidCount(ShadowContextRegistryState s)
        {if(s==null||s.Count<0||s.Count>4)throw new ArgumentException("Registry count0..4 required.");}
        static void Slot(uint[] slots,int index)
        {if(slots==null||slots.Length<4||index<0||index>=4)throw new ArgumentException("Resolved four-slot registry required.");}
        //0x5d0560: full registry returns before reading the supplied context.
        // Nonzero context+808 enables registration; +824 prevents duplicates.
        public static void Register(RenderPacketMemory memory,ShadowContextRegistryState state,uint context)
        {
            ValidCount(state);if(state.Count>=4)return;
            if(memory==null)throw new ArgumentNullException("memory");
            if(memory.Dword(context+0x808)==0||memory.Dword(context+0x824)!=0)return;
            Slot(state.Contexts,state.Count);memory.Dword(context+0x824,1);state.Contexts[state.Count]=context;++state.Count;state.CacheFlag=0;
        }
        //0x5d05b0; entry thunks0x596950/0x596970 jump to this exact helper.
        public static void Reset(RenderPacketMemory memory,ShadowContextRegistryState state)
        {
            ValidCount(state);for(int i=0;i<state.Count;++i){Slot(state.Contexts,i);memory.Dword(state.Contexts[i]+0x824,0);}state.Count=0;state.CacheFlag=0;
        }
        //0x5d05f0 and0x5d0600 preserve signed query semantics, including counts
        // outside the mutating registry's supported0..4 domain.
        public static int GetCount(ShadowContextRegistryState state)
        {if(state==null)throw new ArgumentNullException("state");return state.Count;}
        public static bool HasContexts(ShadowContextRegistryState state)
        {return GetCount(state)>0;}
        //0x5d0610 reads a slot without checking the active count.
        public static uint GetContext(ShadowContextRegistryState state,int index)
        {if(state==null)throw new ArgumentNullException("state");Slot(state.Contexts,index);return state.Contexts[index];}
        //0x5d0630: invalid cache returns all bits before reading any slot.
        public static uint GetMask(ShadowContextRegistryState state,int index)
        {if(state==null)throw new ArgumentNullException("state");if(state.CacheFlag==0)return UInt32.MaxValue;Slot(state.Masks,index);return state.Masks[index];}
    }
}
