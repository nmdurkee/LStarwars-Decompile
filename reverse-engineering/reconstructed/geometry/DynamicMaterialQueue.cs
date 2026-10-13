// Original5de440 finite dynamic-material queue contract.
// Native evidence: geometry-dynamic-queue-native-validation.json.
// Includes explicit guards for stale/cyclic lists and unavailable capacity;
// one controlled original-fault fixture is preserved separately.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public static class DynamicMaterialQueue
    {
        private static uint Get(RenderPacketMemory m,uint root,uint offset){return m.Dword(root+offset);}
        private static void Reindex(RenderPacketMemory m,uint materialTable,uint references,uint capacity)
        {
            for(uint i=0;i<capacity;++i)if(m.Byte(references+i)!=0)m.Dword(m.Dword(m.Dword(materialTable+i*4)+0x3c)+4,i);
        }
        private static void Refresh(RenderPacketMemory m,uint root,List<uint> calls)
        {calls.Add(0x5de390);DynamicMaterialPackets.RefreshRanges(m,root);}
        private static void Construct(RenderPacketMemory m,uint packet,uint material,List<uint> calls)
        {
            // Native passes a pointer to a stack-local cursor. A private image
            // models that local without adding writes to the caller's arena.
            byte[] local=new byte[132];Array.Copy(m.Block(packet,128),local,128);
            RenderPacketMemory temp=new RenderPacketMemory(packet,local);temp.Dword(packet+128,packet);
            DynamicMaterialPackets.ConstructMaterial(temp,material,packet+128,8);m.Block(packet,temp.Block(packet,128));
            calls.AddRange(new uint[]{0x5de100,0x603440,0x603450,0x603460,0x603480,0x603490});
        }
        private static void GuardNode(HashSet<uint> seen,uint node)
        {if(node==0 || seen.Count>=1000000 || !seen.Add(node))throw new ArgumentException("Native sort traversal is stale/cyclic; outside supported domain.");}
        // Globals belonging to the extended display rooted at973dbc become
        // explicit root-relative memory. Packet constants stay original8/6/7.
        public static IList<uint> Flush(RenderPacketMemory m,uint root)
        {
            if(m==null)throw new ArgumentNullException("m");List<uint> calls=new List<uint>();calls.Add(0x5de440);
            if((Get(m,root,0x90)|Get(m,root,0x98))==0)return calls;
            uint capacity=Get(m,root,0x4c),table=Get(m,root,0x50),records=Get(m,root,0x54),references=Get(m,root,0xa0),nodes=Get(m,root,0x64),pool=Get(m,root,0xa8),used=Get(m,root,0xb0);
            if(capacity>4096 || Get(m,root,0x60)>600 || Get(m,root,0x90)>1000000 || Get(m,root,0x98)>1000000)throw new ArgumentException("Finite queue capacity exceeded.");
            for(uint qi=0;qi<Get(m,root,0x98);++qi)
            {
                uint material=m.Dword(Get(m,root,0x9c)+qi*4);if(m.Dword(material+0x3c)==0)continue;
                int found=-1;for(uint i=0;i<capacity;++i)if(m.Dword(table+i*4)==material){found=(int)i;break;}
                if(found<0)continue;uint index=(uint)found;
                m.Byte(references+index,unchecked((byte)(m.Byte(references+index)-1)));if(m.Byte(references+index)!=0)continue;
                int order=DynamicMaterialPackets.MaterialSortKey(m,material),sortIndex=-1;
                for(uint i=0;i<Get(m,root,0x60);++i)if(unchecked((int)m.Dword(nodes+i*36))==order)sortIndex=(int)i;
                if(sortIndex<0)throw new ArgumentException("Missing native removal sort record.");
                uint node=nodes+(uint)sortIndex*36,command=m.Dword(m.Dword(material+0x3c)+0xc);bool removed=false;
                if(m.Dword(node+4)==command){m.Dword(node+4,m.Dword(command+116));removed=true;}
                else
                {
                    for(uint i=0;i<m.Word(node+0x20);++i)
                    {
                        uint candidate=m.Dword(m.Dword(m.Dword(table+((uint)m.Word(node+0x22)+i)*4)+0x3c)+0xc);
                        if(m.Dword(candidate+116)==command){m.Dword(candidate+116,m.Dword(command+116));removed=true;break;}
                    }
                }
                if(removed){m.Byte(command+113,4);m.Dword(command+116,0);m.Byte(command+112,0x84);}
                for(uint i=0;i<capacity;++i)if(m.Byte(used+i)!=0 && command==pool+i*128){m.Byte(used+i,0);break;}
                m.Word(node+0x20,unchecked((ushort)(m.Word(node+0x20)-1)));
                if(m.Word(node+0x20)==0)
                {
                    uint previous=0,current=Get(m,root,0x110);HashSet<uint> seen=new HashSet<uint>();
                    while(current!=node){GuardNode(seen,current);previous=current;current=m.Dword(current+8);}
                    if(previous==0)m.Dword(root+0x110,m.Dword(current+8));else m.Dword(previous+8,m.Dword(current+8));
                    m.Dword(root+0x10c,unchecked(Get(m,root,0x10c)-1));
                    for(uint i=(uint)sortIndex;i+1<Get(m,root,0x60);++i)
                        for(uint j=0;j<9;++j)m.Dword(nodes+i*36+j*4,m.Dword(nodes+(i+1)*36+j*4));
                    m.Dword(root+0x60,Get(m,root,0x60)-1);
                }
                uint saved=m.Dword(records+index*4);
                for(uint i=index;i+1<capacity;++i)
                {m.Dword(table+i*4,m.Dword(table+(i+1)*4));m.Dword(records+i*4,m.Dword(records+(i+1)*4));m.Byte(references+i,m.Byte(references+i+1));}
                m.Dword(records+(capacity-1)*4,saved);m.Byte(references+capacity-1,0);
                Reindex(m,table,references,capacity);Refresh(m,root,calls);m.Dword(material+0x3c,0);
            }
            m.Dword(root+0x98,0);
            for(uint qi=0;qi<Get(m,root,0x90);++qi)
            {
                uint material=m.Dword(Get(m,root,0x94)+qi*4);int found=-1;
                for(uint i=0;i<capacity;++i)if(m.Dword(table+i*4)==material){found=(int)i;break;}
                if(found>=0){uint p=references+(uint)found;m.Byte(p,unchecked((byte)(m.Byte(p)+1)));continue;}
                int free=-1,slot=-1;
                for(uint i=0;i<capacity;++i){if(free<0 && m.Byte(references+i)==0)free=(int)i;if(slot<0 && m.Byte(used+i)==0)slot=(int)i;}
                if(free<0 || slot<0)throw new ArgumentException("Original material/packet pool exhausted.");
                m.Byte(used+(uint)slot,1);int order=DynamicMaterialPackets.MaterialSortKey(m,material),sortIndex=-1;
                for(uint i=0;i<Get(m,root,0x60);++i)if(unchecked((int)m.Dword(nodes+i*36))==order)sortIndex=(int)i;
                int position=free;
                for(uint i=0;i<capacity;++i)if(m.Byte(references+i)!=0 && order<=DynamicMaterialPackets.MaterialSortKey(m,m.Dword(table+i*4))){position=(int)i;break;}
                uint saved=m.Dword(records+(capacity-1)*4);
                for(int i=(int)capacity-2;i>=position;--i)
                {m.Dword(table+(uint)(i+1)*4,m.Dword(table+(uint)i*4));m.Dword(records+(uint)(i+1)*4,m.Dword(records+(uint)i*4));m.Byte(references+(uint)i+1,m.Byte(references+(uint)i));}
                uint pos=(uint)position;m.Dword(records+pos*4,saved);m.Byte(references+pos,0);Reindex(m,table,references,capacity);m.Byte(references+pos,1);
                uint record=m.Dword(records+pos*4),command=pool+(uint)slot*128;m.Dword(material+0x3c,record);Construct(m,command,material,calls);
                m.Dword(table+pos*4,material);m.Dword(record+0xc,command);m.Dword(record+0x18,command+96);m.Dword(record,root);m.Dword(record+4,pos);
                if(sortIndex<0)
                {
                    sortIndex=(int)Get(m,root,0x60);if(sortIndex>=600)throw new ArgumentException("Original600-node sort pool exhausted.");
                    uint node=nodes+(uint)sortIndex*36;m.Dword(node,unchecked((uint)order));m.Dword(node+4,command);m.Dword(node+0x18,Get(m,root,0xa4));m.Word(node+0x20,0);
                    uint previous=0,current=Get(m,root,0x110);HashSet<uint> seen=new HashSet<uint>();
                    while(current!=0 && order>unchecked((int)m.Dword(current))){GuardNode(seen,current);previous=current;current=m.Dword(current+8);}
                    m.Dword(node+8,current);if(previous==0)m.Dword(root+0x110,node);else m.Dword(previous+8,node);
                    m.Dword(root+0x10c,Get(m,root,0x10c)+1);m.Dword(root+0x60,Get(m,root,0x60)+1);
                }
                else
                {
                    uint node=nodes+(uint)sortIndex*36;
                    if(pos==0 || DynamicMaterialPackets.MaterialSortKey(m,m.Dword(table+(pos-1)*4))!=order)
                    {m.Byte(command+112,0x8d);m.Dword(command+116,m.Dword(node+4));m.Byte(command+113,1);m.Dword(node+4,command);}
                    else
                    {
                        uint previous=m.Dword(m.Dword(m.Dword(table+(pos-1)*4)+0x3c)+0xc),next=m.Dword(previous+116);
                        m.Byte(command+112,0x8d);m.Dword(command+116,next);m.Byte(command+113,1);m.Dword(previous+116,command);
                    }
                }
                uint group=nodes+(uint)sortIndex*36;m.Word(group+0x20,unchecked((ushort)(m.Word(group+0x20)+1)));Refresh(m,root,calls);
            }
            m.Dword(root+0x90,0);return calls;
        }
    }
}

