using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class DynamicCommandSupportHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="DSPI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0 || count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,83,80,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32(),size=r.ReadInt32(),argc=r.ReadInt32();if(kind<0 || kind>3 || size<0 || size>0x2000000 || argc<2 || argc>6)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();uint[] a=new uint[argc];for(int j=0;j<argc;++j)a[j]=r.ReadUInt32();RenderPacketMemory memory=new RenderPacketMemory(0x10100000,bytes);uint result=0;
                switch(kind)
                {
                    case 0:result=DynamicCommandSupport.Reserve(memory,a[0],a[1],checked((int)a[2]));break;
                    case 1:DynamicCommandSupport.StoreAlpha(memory,a[0],a[1]);break;
                    case 2:DynamicCommandSupport.StoreSignedMetadata(memory,a[0],unchecked((int)a[1]));break;
                    case 3:DynamicCommandSupport.SetOverride(memory,a[0],a[1],a[3],a[5]);break;
                }
                w.Write(sha.ComputeHash(bytes));w.Write(result);
            }
            int branches=r.ReadInt32();if(branches<0 || branches>1000000)throw new InvalidDataException();w.Write(branches);
            for(int i=0;i<branches;++i){byte opcode=checked((byte)r.ReadUInt32()),previous=checked((byte)r.ReadUInt32());uint flags=r.ReadUInt32();int commands=r.ReadInt32(),mode=r.ReadInt32();w.Write(DynamicCommandSupport.SelectPacketRoutine(opcode,previous,flags,commands,mode));}
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
