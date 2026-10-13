using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class MaterialCloneCacheHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="MCCI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{77,67,67,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32(),size=r.ReadInt32();if(kind<0||kind>4||size!=0xb000)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();int argc=r.ReadInt32();if(argc<0||argc>3)throw new InvalidDataException();uint[] a=new uint[argc];for(int j=0;j<argc;++j)a[j]=r.ReadUInt32();uint thread=r.ReadUInt32(),type=r.ReadUInt32(),xor=r.ReadUInt32(),counter=r.ReadUInt32();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);List<uint[]> trace=new List<uint[]>();int allocations=0;
                MaterialCloneServices services=new MaterialCloneServices();services.CurrentThread=thread;services.MaterialTypeWord=type;
                services.AllocateMaterial=delegate(uint t){trace.Add(new uint[]{0x5e4b20,1,1,t});return 0x10108000+(uint)(allocations++)*0x300;};
                services.ResolveDeclaration=delegate(uint layout){trace.Add(new uint[]{0x7418c0,layout});return layout^0x76543210;};
                services.RefreshMaterial=delegate(RenderPacketMemory memory,uint clone){trace.Add(new uint[]{0x601030,clone});memory.Dword(clone+0x1f0,memory.Dword(clone+0x1f0)^xor);memory.Word(clone+0x2c0,(ushort)counter);memory.Dword(clone+0x2b8,0xface1234);};
                uint result=0;switch(kind)
                {
                    case 0:result=MaterialCloneCache.Next(m,0x10100100,a[0]);break;
                    case 1:result=MaterialCloneCache.AllocateNode(m,0x10100100,thread);break;
                    case 2:result=MaterialCloneCache.Find(m,0x10100100,a[0],a[1]);break;
                    case 3:MaterialCloneCache.EnsureLayouts(m,0x10100100,a[0],a[1],unchecked((int)a[2]),services);break;
                    case 4:result=MaterialCloneCache.Merge(m,0x10100100,a[0],a[1],services);break;
                }
                w.Write(sha.ComputeHash(bytes));w.Write(result);w.Write(trace.Count);foreach(uint[] row in trace){w.Write(row.Length);foreach(uint word in row)w.Write(word);}
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
