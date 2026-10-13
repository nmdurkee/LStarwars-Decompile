using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class DynamicMaterialPacketsHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="DMAT")throw new InvalidDataException();int count=r.ReadInt32();
            if(count<0 || count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,77,79,85});w.Write(count);
            for(int i=0;i<count;++i)
            {
                uint entry=r.ReadUInt32(),linkCount=r.ReadUInt32();int argc=r.ReadInt32();
                if(argc<1 || argc>4)throw new InvalidDataException();uint[] a=new uint[argc];for(int j=0;j<argc;++j)a[j]=r.ReadUInt32();
                int size=r.ReadInt32();if(size<0 || size>0x2000000)throw new InvalidDataException();byte[] b=r.ReadBytes(size);if(b.Length!=size)throw new EndOfStreamException();
                RenderPacketMemory m=new RenderPacketMemory(0x11000000,b);uint result=0;uint[] calls=new uint[]{entry};
                switch(entry)
                {
                    case 0x603440:DynamicMaterialPackets.SetReserved1(m,a[0]);break;
                    case 0x603450:DynamicMaterialPackets.SetReserved2(m,a[0]);break;
                    case 0x603460:DynamicMaterialPackets.SetMaterial(m,a[0],a[1]);break;
                    case 0x603480:DynamicMaterialPackets.SetReserved4(m,a[0]);break;
                    case 0x603490:DynamicMaterialPackets.SetReserved5(m,a[0]);break;
                    case 0x5de100:result=DynamicMaterialPackets.ConstructMaterial(m,a[1],a[2],linkCount);calls=new uint[]{entry,0x603440,0x603450,0x603460,0x603480,0x603490};break;
                    case 0x5de390:DynamicMaterialPackets.RefreshRanges(m,a[0]);break;
                    default:throw new InvalidDataException();
                }
                w.Write(sha.ComputeHash(b));w.Write(result);w.Write(calls.Length);foreach(uint value in calls)w.Write(value);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}

