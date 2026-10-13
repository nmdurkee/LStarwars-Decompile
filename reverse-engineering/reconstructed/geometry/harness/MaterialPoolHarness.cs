using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class MaterialPoolHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="MPLI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{77,80,76,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32(),size=r.ReadInt32();if(kind<0||kind>3||size!=0xb000)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();int argc=r.ReadInt32();if(argc<0||argc>3)throw new InvalidDataException();uint[] a=new uint[argc];for(int j=0;j<argc;++j)a[j]=r.ReadUInt32();int capacity=r.ReadInt32(),pending=r.ReadInt32();uint xor=r.ReadUInt32(),type=r.ReadUInt32();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);MaterialPoolState state=new MaterialPoolState();state.Pool=0x10104000;state.PendingMaterials=0x10109000;state.Capacity=capacity;state.PendingCount=pending;uint result=0;
                if(kind==0)MaterialPool.ResetRuntime(m,a[0]);
                else if(kind==1)MaterialPool.Initialize(m,a[0],unchecked((int)a[1]));
                else if(kind==2)result=MaterialPool.Allocate(m,state,unchecked((int)a[0]),a[1],unchecked((int)a[2]));
                else
                {
                    MaterialCloneServices services=new MaterialCloneServices();services.CurrentThread=77;services.MaterialTypeWord=type;
                    services.AllocateMaterial=delegate(uint t){return MaterialPool.Allocate(m,state,1,t,1);};services.ResolveDeclaration=delegate(uint layout){return layout^0x76543210;};
                    services.RefreshMaterial=delegate(RenderPacketMemory memory,uint p){memory.Dword(p+0x1f0,memory.Dword(p+0x1f0)^xor);memory.Word(p+0x2c0,65535);memory.Dword(p+0x2b8,0xface1234);};
                    result=MaterialCloneCache.Merge(m,0x10100100,0x10100400,0x10102000,services);
                }
                w.Write(sha.ComputeHash(bytes));w.Write(result);w.Write(state.PendingCount);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
