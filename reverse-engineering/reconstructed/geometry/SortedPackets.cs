// Original CPU sorted command completion and command append projection.
// Native checks: geometry-sorted-packets-native-validation.json.
// Compiled C# behavior remains pending; no GPU execution is represented.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    // Bounded caller-provided memory image retains original pointer aliasing.
    // This adapter is not mapped to a native entry.
    public sealed class RenderPacketMemory
    {
        public readonly uint BaseAddress;
        public readonly byte[] Bytes;
        public RenderPacketMemory(uint baseAddress,byte[] bytes)
        {
            if(bytes==null || (ulong)baseAddress+(ulong)bytes.Length>0x100000000UL)throw new ArgumentException("Invalid finite address image.");
            BaseAddress=baseAddress;Bytes=bytes;
        }
        private int Offset(uint p,int n)
        {
            if(n<0 || p<BaseAddress || (ulong)p+(ulong)n>(ulong)BaseAddress+(ulong)Bytes.Length)throw new ArgumentOutOfRangeException("address");
            return (int)(p-BaseAddress);
        }
        public byte Byte(uint p){return Bytes[Offset(p,1)];}
        public ushort Word(uint p){int o=Offset(p,2);return (ushort)(Bytes[o]|(Bytes[o+1]<<8));}
        public uint Dword(uint p)
        {int o=Offset(p,4);return (uint)Bytes[o]|((uint)Bytes[o+1]<<8)|((uint)Bytes[o+2]<<16)|((uint)Bytes[o+3]<<24);}
        public void Byte(uint p,byte v){Bytes[Offset(p,1)]=v;}
        public void Word(uint p,ushort v){int o=Offset(p,2);Bytes[o]=(byte)v;Bytes[o+1]=(byte)(v>>8);}
        public void Dword(uint p,uint v)
        {int o=Offset(p,4);Bytes[o]=(byte)v;Bytes[o+1]=(byte)(v>>8);Bytes[o+2]=(byte)(v>>16);Bytes[o+3]=(byte)(v>>24);}
        public byte[] Block(uint p,int n)
        {int o=Offset(p,n);byte[] result=new byte[n];Array.Copy(Bytes,o,result,0,n);return result;}
        public void Block(uint p,byte[] data)
        {int o=Offset(p,data.Length);Array.Copy(data,0,Bytes,o,data.Length);}
    }
    public static class SortedPackets
    {
        // Fixture/adapter guard only. It deliberately rejects the shader
        // emission branches whose side effects are still separate work.
        public static void RequireCurrentShader(RenderPacketMemory memory,uint record,uint shader)
        {
            if(shader!=0 && memory.Dword(memory.Dword(record+8)+0x20)!=memory.Dword(shader+0x20))
                throw new NotSupportedException("Shader context emission callback is required for changed context.");
        }
        private static void ResetShader(RenderPacketMemory memory,uint shader,uint template)
        {
            // Whole aliases are retained; partial overlap is excluded here.
            if(shader!=template && (ulong)shader<(ulong)template+420 && (ulong)template<(ulong)shader+420)
                throw new ArgumentException("Partially overlapping shader images are outside the decoded domain.");
            byte[] a=memory.Block(shader,420),b=shader==template?a:memory.Block(template,420);
            FrameReset.ResetShaderContext(a,b);memory.Block(shader,a);memory.Block(template,b);
        }
        // Original0x5e0d00. Finite acyclic sort lists and valid material tables.
        // The shader callback may mutate memory, and all dependent native
        // fields are re-read after it. The tested callback takes only the
        // original already-current branch; mutating emission remains separate.
        public static IList<uint[]> Complete(RenderPacketMemory memory,uint sortedHead,IList<uint> registered,uint globalTemplate,Action<RenderPacketMemory,uint,uint> emitShader)
        {
            if(memory==null || registered==null || registered.Count>256 || emitShader==null)throw new ArgumentException("Valid bounded state and explicit shader boundary required.");
            List<uint[]> calls=new List<uint[]>();calls.Add(new uint[]{0x5e0d00});calls.Add(new uint[]{0x5fca40});
            // Original local command context is reset but only passed to two
            // literal-return helpers. Its uninitialized padding is not read.
            uint lastShader=0,node=sortedHead;HashSet<uint> seen=new HashSet<uint>();
            while(node!=0)
            {
                if(seen.Count>=1000000 || !seen.Add(node))throw new ArgumentException("Finite acyclic sort list required.");
                uint owner=memory.Dword(node+0x1c);
                if(owner==0)calls.Add(new uint[]{0x5fca80}); // original ret
                else if((memory.Dword(owner+0x74)&6)!=0)
                {
                    int count=memory.Word(node+0x20),start=memory.Word(node+0x22);
                    if((ulong)start+(ulong)count>memory.Dword(owner+0x4c))throw new ArgumentException("Invalid material range.");
                    for(int i=0;i<count;++i)
                    {
                        uint index=(uint)(start+i),record=memory.Dword(memory.Dword(owner+0x54)+index*4),control=memory.Dword(record+0xc);
                        if(memory.Byte(control+1)!=0)continue;
                        uint material=memory.Dword(memory.Dword(owner+0x50)+index*4),shader=memory.Dword(owner+0x80);
                        if(shader==0 || (memory.Dword(owner+0x74)&4)==0)lastShader=0;
                        else if(memory.Dword(record+0x14)!=memory.Dword(record+0x10) || lastShader!=shader)
                        {
                            calls.Add(new uint[]{0x607590,record,shader});emitShader(memory,record,shader);lastShader=memory.Dword(owner+0x80);
                        }
                        uint first=memory.Dword(record+0x10),tail=memory.Dword(record+0x14),saved=memory.Dword(record+0x18);
                        if(tail==first)
                        {
                            uint slot=memory.Dword(record+0x34);if(slot>1)throw new ArgumentException("Invalid packet buffer slot.");
                            uint selected=memory.Dword(record+0x28+slot*4);
                            if(selected==memory.Dword(record+0x30))memory.Dword(saved+4,saved+16);
                            else
                            {
                                memory.Dword(saved+4,selected);uint current=memory.Dword(record+0x30);
                                memory.Byte(current,0x8d);memory.Byte(current+1,1);memory.Dword(current+4,saved+16);
                            }
                        }
                        else
                        {
                            // Original four sequential DWORD copies, preserving
                            // forward-copy effects if command regions overlap.
                            for(uint j=0;j<4;++j)memory.Dword(saved+j*4,memory.Dword(first+j*4));
                            if((memory.Dword(owner+0x74)&4)==0)
                            {
                                memory.Dword(memory.Dword(record+0x14)+4,memory.Dword(memory.Dword(record+0xc)+4));
                                memory.Dword(record+0x14,memory.Dword(record+0x10));
                            }
                            else
                            {
                                uint slot=memory.Dword(record+0x34);if(slot>1)throw new ArgumentException("Invalid packet buffer slot.");
                                uint selected=memory.Dword(record+0x28+slot*4);
                                if(selected!=memory.Dword(record+0x30))
                                {
                                    memory.Dword(memory.Dword(record+0x14)+4,selected);uint current=memory.Dword(record+0x30);
                                    memory.Byte(current,0x8d);memory.Byte(current+1,1);memory.Dword(current+4,memory.Dword(record+0x18)+16);
                                }
                                memory.Dword(record+0x14,memory.Dword(record+0x10));
                            }
                        }
                        calls.Add(new uint[]{0x5fca70}); // original ret
                        byte mask=(byte)(memory.Dword(owner+0x74)>>5);
                        if(mask!=0 && (mask&(byte)(memory.Dword(material+0x44)>>14))!=0)
                        {
                            control=memory.Dword(record+0xc);memory.Byte(control+1,1);uint mi=memory.Dword(record+4);
                            if(mi>=memory.Dword(owner+0x4c))throw new ArgumentException("Material bit index outside finite table.");
                            uint bits=memory.Dword(owner+0x58+((memory.Dword(owner+0x74)>>15)&1)*4)+mi/8;
                            memory.Byte(bits,(byte)(memory.Byte(bits)&~(1<<(int)(mi&7))));
                        }
                    }
                }
                node=memory.Dword(node+8);
            }
            foreach(uint owner in registered)
            {
                uint shader=memory.Dword(owner+0x80);
                if(shader!=0){calls.Add(new uint[]{0x5fd100});ResetShader(memory,shader,globalTemplate);}
            }
            return calls;
        }

        // Original0x6034b0. Return value is the allocator-control pointer for
        // inline payload allocation, or0 for an explicit payload. It is not
        // the appended packet address. Native padding bytes remain untouched.
        public static uint Append(RenderPacketMemory memory,uint allocatorControl,uint record,uint typeCode,uint payload)
        {
            uint old=memory.Dword(allocatorControl);if(old>UInt32.MaxValue-47)throw new ArgumentException("Allocation wrap outside finite image.");
            uint packet=(old+15)&0xfffffff0;
            memory.Dword(allocatorControl,packet);
            memory.Dword(memory.Dword(record+0x14)+4,memory.Dword(allocatorControl));
            memory.Byte(memory.Dword(allocatorControl),(byte)typeCode);
            memory.Byte(memory.Dword(allocatorControl)+1,3);
            uint current=memory.Dword(allocatorControl);memory.Dword(current+4,payload==0?current+32:payload);
            memory.Byte(memory.Dword(allocatorControl)+16,0x8d);memory.Byte(memory.Dword(allocatorControl)+17,1);
            memory.Dword(memory.Dword(allocatorControl)+20,memory.Dword(record+0x18)+16);
            memory.Dword(record+0x14,memory.Dword(allocatorControl)+16);
            memory.Dword(allocatorControl,memory.Dword(allocatorControl)+32);return payload==0?allocatorControl:0;
        }
    }
}

