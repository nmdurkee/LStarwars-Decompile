// PC0x603710 CPU morph deformation and joint-palette payload, successful lock.
using System;
namespace Recovered.Animation
{
    public interface IMorphVertexBuffer
    {
        // Original wrapper6e5b90 invokes COM vtable+2c with flag0x10.
        // Return exactly byteCount copied bytes from the requested buffer range.
        byte[] Lock(uint byteOffset,uint byteCount,uint flags);
        void Unlock();
    }
    public sealed class MorphMeshResource
    {
        public uint SourceAddress;
        public byte[] Descriptor;
        public float[][] TargetDeltas;
        public IMorphVertexBuffer VertexBuffer;
    }
    public sealed class MorphMeshBuild
    {
        public bool DescriptorCopied;
        public uint DescriptorAddress,VertexAddress,PaletteAddress,NextCursor;
        public byte[] Descriptor,Vertices,Palette;
    }
    public static class MorphMeshDeformation
    {
        static uint U(byte[] b,int p){return(uint)b[p]|(uint)b[p+1]<<8|(uint)b[p+2]<<16|(uint)b[p+3]<<24;}
        static void Put(byte[] b,int p,uint v){for(int i=0;i<4;++i)b[p+i]=(byte)(v>>(8*i));}
        static uint Align(uint p){return checked(p+31)&0xffffffe0;}
        static void Finite(float v){if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite deformation values required");}
        static float AddProduct(float value,float delta,float weight)
        {
            Finite(value);Finite(delta);Finite(weight);var exact=PlaybackWide.Add(PlaybackWide.Multiply(PlaybackWide.From(delta),PlaybackWide.From(weight)),PlaybackWide.From(value));float result=exact.Store();
            if(result==0){double signed=(double)delta*weight+value;result=PcObjectImage.FromBits(BitConverter.DoubleToInt64Bits(signed)<0?0x80000000u:0u);}Finite(result);return result;
        }
        // Native input pointers/allocator are projected into owned byte arrays
        // and logical32-bit addresses. Lock/Unlock is the explicit GPU service
        // boundary. No GPU submission or live device interaction occurs here.
        public static MorphMeshBuild Build(MorphMeshResource mesh,float[] weights,byte[][] jointMatrices,uint cursor)
        {
            if(mesh==null||mesh.Descriptor==null||mesh.Descriptor.Length!=56)throw new ArgumentException("56-byte PC mesh descriptor required");
            var result=new MorphMeshBuild();byte[] raw=mesh.Descriptor;int stride=raw[8]|raw[9]<<8;uint vertexCount=U(raw,24),targetCount=U(raw,40);bool deform=weights!=null&&targetCount!=0;
            if(deform)
            {
                if(stride<12||vertexCount>Int32.MaxValue||targetCount>Int32.MaxValue||weights.Length<targetCount||mesh.TargetDeltas==null||mesh.TargetDeltas.Length<targetCount||mesh.VertexBuffer==null)throw new ArgumentException("Valid deformation arrays and stride required");
                uint byteCount=checked(vertexCount*(uint)stride),byteOffset=checked(U(raw,20)*(uint)stride);if(byteCount>Int32.MaxValue)throw new ArgumentException("Vertex buffer range too large");
                result.DescriptorCopied=true;result.DescriptorAddress=Align(cursor);cursor=checked(result.DescriptorAddress+56);result.Descriptor=(byte[])raw.Clone();
                byte[] original=mesh.VertexBuffer.Lock(byteOffset,byteCount,0x10);if(original==null||original.Length!=byteCount)throw new ArgumentException("Successful exact vertex buffer lock required");
                result.VertexAddress=Align(cursor);cursor=checked(result.VertexAddress+byteCount);Put(result.Descriptor,52,result.VertexAddress);result.Vertices=(byte[])original.Clone();
                for(int i=0;i<(int)vertexCount;++i)for(int j=0;j<(int)targetCount;++j)
                {
                    float[] delta=mesh.TargetDeltas[j];float weight=weights[j];if(delta==null||weight==0)continue;
                    if(delta.Length<checked((int)vertexCount*3))throw new ArgumentException("Morph target has insufficient vertices");
                    for(int axis=0;axis<3;++axis){int p=checked(i*stride+4*axis);float value=PcObjectImage.FromBits(U(result.Vertices,p));Put(result.Vertices,p,PcObjectImage.ToBits(AddProduct(value,delta[i*3+axis],weight)));}
                }
                mesh.VertexBuffer.Unlock();
            }
            else{Put(raw,52,0);result.Descriptor=raw;result.DescriptorAddress=mesh.SourceAddress;}
            // Palette starts immediately after vertices; native does not add a
            // further alignment here. Byte255 terminates within eight indices.
            int count=0;while(count<8&&raw[10+count]!=255)++count;result.PaletteAddress=cursor;result.Palette=new byte[checked(4+count*64)];Put(result.Palette,0,(uint)count);
            for(int i=0;i<count;++i){int index=raw[10+i];if(jointMatrices==null||index>=jointMatrices.Length||jointMatrices[index]==null||jointMatrices[index].Length!=64)throw new ArgumentException("Resolved64-byte joint matrices required");Array.Copy(jointMatrices[index],0,result.Palette,4+64*i,64);}
            result.NextCursor=checked(cursor+(uint)result.Palette.Length);return result;
        }
    }
}
