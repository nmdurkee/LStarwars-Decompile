// Original0x5efff0 CPU pending-list finalization. No GPU execution.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public sealed class PendingPacketState
    {
        // Explicit adapters for9736e0,973ec8,973ecc,973e78/80/84,
        // and the24 pointer slots973ed4 with count973ed0.
        public uint AllocatorControl,ReservationCount,SortedHead,GlobalCache,GlobalHead,GlobalTail;
        public int Count;
        public uint[] Descriptors;
    }
    public static class PendingPackets
    {
        static uint Reserve(RenderPacketMemory m,uint control,uint alignment,uint bytes)
        {
            ulong start=((ulong)m.Dword(control)+alignment-1)&~((ulong)alignment-1),end=start+bytes;
            if(end>UInt32.MaxValue||bytes>Int32.MaxValue)throw new ArgumentException("Nonwrapping finite arena required.");
            m.Block((uint)start,(int)bytes);m.Dword(control,(uint)end);return(uint)start;
        }
        static void CopyWords(RenderPacketMemory m,uint destination,uint source,int count)
        {for(uint i=0;i<count;++i)m.Dword(checked(destination+i*4),m.Dword(checked(source+i*4)));}
        static void ResetCache(RenderPacketMemory m,uint cache)
        {byte[] bytes=m.Block(cache,0x30);FrameReset.ResetCommandContext(bytes);m.Block(cache,bytes);}
        static void Terminator(RenderPacketMemory m,uint address)
        {m.Byte(address,0x84);m.Dword(address+4,0);m.Byte(address+1,4);}
        // Valid disjoint metadata/arena, acyclic linked nodes, complete material
        // ranges and reservation capacity are required. Source command aliases
        // and repeated material references retain sequential native effects.
        public static int FinalizeList(RenderPacketMemory m,PendingPacketState state)
        {
            if(m==null||state==null||state.Descriptors==null||state.Descriptors.Length<24||state.Count<0||state.Count>=24||state.ReservationCount>1000000)
                throw new ArgumentException("Bounded24-slot pending state required.");
            uint table=Reserve(m,state.AllocatorControl,16,checked(state.ReservationCount*4+4));int emitted=0;uint node=state.SortedHead;var visited=new HashSet<uint>();
            while(node!=0)
            {
                if(visited.Count>=1000000||!visited.Add(node))throw new ArgumentException("Finite acyclic sort list required.");
                uint owner=m.Dword(node+0x1c),flags=owner==0?0:m.Dword(owner+0x74),selected=0;
                if(owner!=0&&(flags&0x10)!=0)
                {
                    if((flags&2)!=0)
                    {
                        uint clone=Reserve(m,state.AllocatorControl,4,0x24),payload=m.Dword(state.AllocatorControl);m.Dword(clone,m.Dword(node));m.Dword(clone+4,payload);m.Dword(clone+0x1c,m.Dword(node+0x1c));m.Word(clone+0x20,m.Word(node+0x20));m.Word(clone+0x22,m.Word(node+0x22));
                        int start=m.Word(node+0x22),count=m.Word(node+0x20),pairs=0;
                        if((ulong)start+(ulong)count>m.Dword(owner+0x4c))throw new ArgumentException("Complete source material range required.");
                        for(int i=0;i<count;++i)
                        {
                            uint record=m.Dword(checked(m.Dword(owner+0x54)+(uint)(start+i)*4)),first=m.Dword(record+0x10),tail=m.Dword(record+0x14);if(tail==first)continue;
                            uint control=m.Dword(record+12),source=checked(control+(m.Byte(control+0x10)==0x80?0x10u:0x30u)),destination=checked(payload+(uint)pairs*32);
                            CopyWords(m,destination,source,4);CopyWords(m,destination+16,first,4);++pairs;m.Dword(m.Dword(record+0x14)+4,checked(payload+(uint)pairs*32));m.Dword(record+0x14,m.Dword(record+0x10));ResetCache(m,m.Dword(record+8));
                        }
                        uint length=checked((uint)pairs*32+16);Terminator(m,checked(payload+length-16));Reserve(m,state.AllocatorControl,1,length);selected=clone;
                    }
                }
                else if((m.Byte(node+0x14)&2)==0&&(owner==0||(flags&6)!=0))selected=node;
                if(selected!=0)
                {
                    if((uint)emitted>state.ReservationCount)throw new ArgumentException("Insufficient reserved pointer slots.");
                    m.Dword(checked(table+(uint)emitted*4),selected);++emitted;m.Dword(selected+0x14,m.Dword(selected+0x14)|2);
                }
                node=m.Dword(node+8);
            }
            // Even an empty result has already consumed its pointer-table space.
            if(emitted==0&&state.GlobalTail==state.GlobalHead)return -1;
            uint descriptor=Reserve(m,state.AllocatorControl,4,0x18);state.Descriptors[state.Count]=descriptor;m.Dword(descriptor,(uint)emitted);m.Dword(descriptor+4,table);
            if(state.GlobalTail!=state.GlobalHead)
            {Terminator(m,state.GlobalTail);CopyWords(m,descriptor+8,state.GlobalHead,4);ResetCache(m,state.GlobalCache);state.GlobalTail=state.GlobalHead;}
            else Terminator(m,descriptor+8);
            return state.Count++;
        }
    }
}
