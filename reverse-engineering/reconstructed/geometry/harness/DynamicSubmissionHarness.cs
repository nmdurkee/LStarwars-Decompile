using System;
using System.IO;
using System.IO.Compression;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class DynamicSubmissionHarness
{
    private static float[] ReadFloats(BinaryReader r,int n){float[] v=new float[n];for(int i=0;i<n;++i)v[i]=r.ReadSingle();return v;}
    private static float[] ImageFloats(RenderPacketMemory m,uint p,int n){float[] v=new float[n];for(int i=0;i<n;++i)v[i]=BitConverter.ToSingle(m.Block(p+(uint)i*4,4),0);return v;}
    private static void Store(RenderPacketMemory m,uint p,float[] v){for(int i=0;i<v.Length;++i)m.Block(p+(uint)i*4,BitConverter.GetBytes(v[i]));}
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="DYNI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,89,78,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int size=r.ReadInt32();if(size!=65536)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);
                uint handle=r.ReadUInt32(),matrix=r.ReadUInt32();DynamicSubmissionState s=new DynamicSubmissionState();s.ForcedVisibility=r.ReadInt32();s.ForcedLod=r.ReadInt32();s.FilterMode=r.ReadInt32();s.ShadowMask=r.ReadUInt32();s.ShadowMetadataDisabled=r.ReadInt32();s.GlobalOverride=r.ReadUInt32();s.OverrideTable=r.ReadUInt32();s.OverrideFirst=r.ReadUInt32();s.OverrideScalarWord=r.ReadUInt32();s.ScratchInputs=new uint[4];for(int j=0;j<4;++j)s.ScratchInputs[j]=r.ReadUInt32();s.CameraPosition=ReadFloats(r,3);s.Box=new DynamicBoxState();s.Box.View=ReadFloats(r,16);s.Box.Near=r.ReadSingle();s.Box.Far=r.ReadSingle();s.Box.FarOverride=r.ReadSingle();s.Box.HorizontalSlope=r.ReadSingle();s.Box.VerticalSlope=r.ReadSingle();s.Box.Enabled=r.ReadInt32()!=0;
                s.AllocatorControl=0x10100000;s.Shader=0x10106000;s.TokenBase=0x12345678;s.ScaleScratch=0x10106200;s.TranslationScratch=0x10106240;s.CacheScratch=0x10106300;s.OutputScratch=0x10106310;s.Box.CombinedMatrix=ImageFloats(m,0x10106400,16);s.Box.FarLanes=ImageFloats(m,0x10106440,4);
                DynamicSubmissionResult result=DynamicObjectSubmission.Submit(m,s,handle,matrix);Store(m,0x10106400,s.Box.CombinedMatrix);Store(m,0x10106440,s.Box.FarLanes);m.Block(0x10106300,new byte[32]);w.Write(sha.ComputeHash(bytes));w.Write(result.Visibility);w.Write(s.ShadowMask);w.Write(result.Draws.Count);foreach(uint[] draw in result.Draws)foreach(uint word in draw)w.Write(word);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
