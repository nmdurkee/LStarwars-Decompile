using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class DynamicMaterialQueueHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="DQUE")throw new InvalidDataException();int count=r.ReadInt32();
            if(count<0 || count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,81,79,85});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int size=r.ReadInt32();if(size<0 || size>0x2000000)throw new InvalidDataException();
                byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();
                RenderPacketMemory memory=new RenderPacketMemory(0x973dbc,bytes);IList<uint> calls=DynamicMaterialQueue.Flush(memory,0x973dbc);
                w.Write(sha.ComputeHash(bytes));w.Write(calls.Count);foreach(uint address in calls)w.Write(address);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}

