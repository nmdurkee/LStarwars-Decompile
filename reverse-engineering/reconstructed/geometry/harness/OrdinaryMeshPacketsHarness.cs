using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class OrdinaryMeshPacketsHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="OMPI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0 || count>1000000)throw new InvalidDataException();w.Write(new byte[]{79,77,80,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32(),size=r.ReadInt32();if(kind<0 || kind>3 || size<0 || size>0x2000000)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();uint[] a=new uint[10],uv=new uint[4];for(int j=0;j<10;++j)a[j]=r.ReadUInt32();for(int j=0;j<4;++j)uv[j]=r.ReadUInt32();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);IList<uint> calls;uint result=0;
                if(kind==0){OrdinaryMeshPackets.Transpose(m,a[2],a[3]);calls=new uint[]{0x5f7610};}
                else if(kind==1){result=OrdinaryMeshPackets.BuildTransform(m,a[0],a[3],a[6],a[7],uv);calls=new uint[]{0x603580,0x5d6190,0x5d6180,0x5b45a0,0x5b4500,0x5f7610};}
                else if(kind==2)calls=OrdinaryMeshPackets.BuildOrdinary(m,a[0],a[1],a[2],a[3],a[4],a[5],a[8],unchecked((int)a[9]),a[6],a[7],uv);
                else calls=OrdinaryMeshPackets.BuildWithPrefix(m,a[0],a[1],a[2],a[3],a[4],a[5],a[8],a[6],a[7],uv);
                w.Write(sha.ComputeHash(bytes));w.Write(result);w.Write(calls.Count);foreach(uint address in calls)w.Write(address);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
