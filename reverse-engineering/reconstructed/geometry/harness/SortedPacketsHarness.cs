using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class SortedPacketsHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="SPKT")throw new InvalidDataException();int count=r.ReadInt32();
            if(count<0 || count>1000000)throw new InvalidDataException();
            w.Write(new byte[]{83,80,79,85});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadByte(),size=r.ReadInt32();if(size<0 || size>0x2000000)throw new InvalidDataException();
                byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();
                RenderPacketMemory memory=new RenderPacketMemory(0x11000000,bytes);uint result=0;IList<uint[]> calls;
                if(kind==0)
                {
                    uint head=r.ReadUInt32(),global=r.ReadUInt32();int n=r.ReadInt32();if(n<0 || n>256)throw new InvalidDataException();
                    uint[] registry=new uint[n];for(int j=0;j<n;++j)registry[j]=r.ReadUInt32();
                    calls=SortedPackets.Complete(memory,head,registry,global,SortedPackets.RequireCurrentShader);
                }
                else if(kind==1)
                {
                    uint control=r.ReadUInt32(),record=r.ReadUInt32(),type=r.ReadUInt32(),payload=r.ReadUInt32();
                    result=SortedPackets.Append(memory,control,record,type,payload);calls=new List<uint[]>{new uint[]{0x6034b0}};
                }
                else throw new InvalidDataException();
                w.Write(sha.ComputeHash(bytes));w.Write(result);w.Write(calls.Count);
                foreach(uint[] call in calls){w.Write(call.Length);foreach(uint v in call)w.Write(v);}
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}

