using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class MaterialLifecycleHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="MLCI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{77,76,67,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int size=r.ReadInt32();if(size!=0x18000)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();int capacity=r.ReadInt32(),pending=r.ReadInt32();uint variant=r.ReadUInt32(),type=r.ReadUInt32();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);uint manager=0x10110000,device=0x10100800;List<uint[]> trace=new List<uint[]>();List<uint> declarations=new List<uint>();MaterialLifecycleState state=new MaterialLifecycleState();state.Cache=0x10100100;state.CurrentThread=77;state.MaterialTypeWord=type;state.Pool=new MaterialPoolState();state.Pool.Pool=0x10104000;state.Pool.PendingMaterials=0x10109000;state.Pool.Capacity=capacity;state.Pool.PendingCount=pending;state.Refresh=new MaterialRefreshServices();state.Refresh.Manager=manager;state.Refresh.DeviceState=device;
                state.Refresh.ResolveDeclaration=delegate(uint layout){declarations.Add(layout);return layout^0x76543210;};
                state.Refresh.Factory=delegate(RenderPacketMemory memory,uint mgr,uint runtime,uint material,uint mode,uint zeroA,uint zeroB)
                {
                    int ordinal=trace.Count;uint first=manager+8*0x4d8+4,second=manager+9*0x4d8+4;uint p=ordinal==0||(variant&1)!=0?first:second;memory.Dword(p+4,unchecked(memory.Dword(p+4)+1));if(ordinal==1&&(variant&2)!=0)memory.Word(first,33);if(ordinal==0&&(variant&4)!=0)memory.Byte(device+0x654,(byte)(memory.Byte(device+0x654)^32));if(ordinal==0&&(variant&8)!=0)memory.Word(material+0x74,0);trace.Add(new uint[]{mgr,runtime,material,mode,zeroA,zeroB});return p;
                };
                uint result=MaterialLifecycle.Merge(m,state,0x10100400,0x10102000);w.Write(sha.ComputeHash(bytes));w.Write(result);w.Write(state.Pool.PendingCount);w.Write(trace.Count);foreach(uint[] row in trace)foreach(uint word in row)w.Write(word);w.Write(declarations.Count);foreach(uint layout in declarations)w.Write(layout);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
