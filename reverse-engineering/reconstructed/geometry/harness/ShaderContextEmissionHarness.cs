using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class ShaderContextEmissionHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="SEMI")throw new InvalidDataException();int count=r.ReadInt32();
            if(count<0 || count>1000000)throw new InvalidDataException();w.Write(new byte[]{83,69,79,85});w.Write(count);
            for(int i=0;i<count;++i)
            {
                uint entry=r.ReadUInt32();int size=r.ReadInt32();if(size<0 || size>0x100000)throw new InvalidDataException();
                byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();
                uint control=r.ReadUInt32(),shader=r.ReadUInt32(),record=r.ReadUInt32(),descriptor=r.ReadUInt32(),token=r.ReadUInt32(),captureReturn=r.ReadUInt32();
                RenderPacketMemory memory=new RenderPacketMemory(0x11000000,bytes);uint result=0;IList<uint> calls=new List<uint>{entry};
                switch(entry)
                {
                    case 0x607590:calls=ShaderContextEmission.Emit(memory,control,record,shader,descriptor,token);break;
                    case 0x5fcdf0:result=ShaderContextEmission.BuildVectorMatrixPayload(memory,control,shader);break;
                    case 0x5fcef0:result=ShaderContextEmission.BuildOptionalScalarPayload(memory,control,shader);break;
                    case 0x5fcf30:result=ShaderContextEmission.BuildWordPayload(memory,control,shader);break;
                    case 0x5fcf60:result=ShaderContextEmission.BuildConditionalWordsPayload(memory,control,shader);break;
                    case 0x5fcfd0:result=ShaderContextEmission.BuildSignedBytePayload(memory,control,descriptor);break;
                    default:throw new InvalidDataException();
                }
                w.Write(sha.ComputeHash(bytes));w.Write(captureReturn!=0?result:0);w.Write(calls.Count);foreach(uint address in calls)w.Write(address);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}

