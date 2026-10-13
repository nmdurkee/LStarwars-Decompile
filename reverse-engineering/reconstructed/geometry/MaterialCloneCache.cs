// Original material override cache/list/copy CPU behavior. Constructor and
// shader/device services are explicit boundaries, not invented allocations.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public sealed class MaterialCloneServices
    {
        // Original5e4b20(registered=1), ECX=1 and EAX=MaterialTypeWord.
        public Func<uint,uint> AllocateMaterial;
        // Original7418c0(layout); native fixtures use its real cached branch.
        public Func<uint,uint> ResolveDeclaration;
        // Original601030(material); may mutate the material before counter++.
        public Action<RenderPacketMemory,uint> RefreshMaterial;
        public uint MaterialTypeWord,CurrentThread;
    }
    public static class MaterialCloneCache
    {
        // Original547580. Nodes have a16-byte prefix; next is payload-12.
        public static uint Next(RenderPacketMemory m,uint container,uint previous)
        {uint node=m.Dword(previous==0?container+8:previous-12);return node==0?0:checked(node+16);}
        // Original5471c0 same-thread branch. External lock callbacks are not
        // represented; an exhausted free list returns0 before the thread test.
        public static uint AllocateNode(RenderPacketMemory m,uint container,uint currentThread)
        {
            uint node=m.Dword(container);if(node==0)return 0;
            if(m.Dword(container+24)!=currentThread)throw new NotSupportedException("Cross-thread list synchronization remains separate.");
            uint next=m.Dword(node+4);m.Dword(container,next);if(next==0)m.Dword(container+4,0);else m.Dword(next+8,0);
            uint active=m.Dword(container+8);m.Dword(node+4,active);if(active==0)m.Dword(container+12,node);else m.Dword(active+8,node);
            m.Dword(node+8,0);m.Word(container+22,unchecked((ushort)(m.Word(container+22)+1)));m.Dword(container+8,node);m.Word(node+14,(ushort)(m.Word(node+14)|1));return checked(node+16);
        }
        // Original5e4ee0; native EDI replacement becomes an explicit argument.
        // Match compares clone+1f0, NOT the cached layout word at payload+8.
        public static uint Find(RenderPacketMemory m,uint container,uint replacement,uint layout)
        {
            HashSet<uint> seen=new HashSet<uint>();uint p=Next(m,container,0);
            while(p!=0)
            {
                if(seen.Count>=1000000||!seen.Add(p))throw new ArgumentException("Finite acyclic cache list required.");
                if(m.Dword(p+4)==replacement){uint material=m.Dword(p);if(m.Dword(material+0x1f0)==layout)return material;}
                p=Next(m,container,p);
            }
            return 0;
        }
        // Original5e4f30 copy/cache orchestration. Native5e4f9a saves allocated
        // +28 to a LOCAL stack slot: two outstanding pushed arguments mean
        // [esp+18] here is not the earlier [esp+18] replacement argument.
        // Replacement remains unchanged across all requested layouts.
        public static void EnsureLayouts(RenderPacketMemory m,uint container,uint replacement,uint layouts,int count,MaterialCloneServices services)
        {
            if(count<=0)return;if(count>1000000||services==null)throw new ArgumentException("Bounded clone request and explicit services required.");uint current=replacement;
            for(int i=0;i<count;++i)
            {
                uint layout=m.Dword(layouts+(uint)i*4);if(Find(m,container,current,layout)!=0)continue;
                if(services.AllocateMaterial==null||services.ResolveDeclaration==null||services.RefreshMaterial==null)throw new NotSupportedException("Explicit constructor/declaration/refresh services required for a cache miss.");
                uint node=AllocateNode(m,container,services.CurrentThread);if(node==0)throw new ArgumentException("Native cache exhaustion would dereference null; successful allocation domain required.");
                uint clone=services.AllocateMaterial(services.MaterialTypeWord);if(clone==0)throw new ArgumentException("Successful material constructor required.");
                m.Dword(node,clone);m.Dword(node+4,current);m.Dword(node+8,layout);uint preserved28=m.Dword(clone+0x28),preserved2c=m.Dword(clone+0x2c);
                if((ulong)clone<(ulong)current+708&&(ulong)current<(ulong)clone+708)throw new ArgumentException("Disjoint clone/template images required.");
                m.Block(clone,m.Block(current,708));
                m.Word(clone+0x1f6,0);m.Word(clone+0x1f4,0);m.Dword(clone+0x2c,preserved2c);m.Dword(clone+0x28,preserved28);m.Word(clone,(ushort)(m.Word(clone)|1));m.Dword(clone+0x1f0,layout);
                m.Dword(clone+0x2bc,services.ResolveDeclaration(m.Dword(clone+0x1f0)));services.RefreshMaterial(m,clone);m.Word(clone+0x2c0,unchecked((ushort)(m.Word(clone+0x2c0)+1)));
            }
        }
        // Original5e5020. Re-read source layout after the miss service sequence,
        // retaining the second lookup instead of directly returning the clone.
        public static uint Merge(RenderPacketMemory m,uint container,uint source,uint replacement,MaterialCloneServices services)
        {
            uint existing=Find(m,container,replacement,m.Dword(source+0x1f0));if(existing!=0)return existing;
            EnsureLayouts(m,container,replacement,source+0x1f0,1,services);return Find(m,container,replacement,m.Dword(source+0x1f0));
        }
    }
}
