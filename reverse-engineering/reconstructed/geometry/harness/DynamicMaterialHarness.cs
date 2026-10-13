using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class DynamicMaterialHarness
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
            if(new string(r.ReadChars(4))!="DMCI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,77,67,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int size=r.ReadInt32();if(size!=0x30000)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);uint handle=r.ReadUInt32(),matrix=r.ReadUInt32();DynamicSubmissionState s=new DynamicSubmissionState();s.ForcedVisibility=r.ReadInt32();s.ForcedLod=r.ReadInt32();s.FilterMode=r.ReadInt32();s.ShadowMask=r.ReadUInt32();s.ShadowMetadataDisabled=r.ReadInt32();s.GlobalOverride=r.ReadUInt32();s.OverrideTable=r.ReadUInt32();s.OverrideFirst=r.ReadUInt32();s.OverrideScalarWord=r.ReadUInt32();s.ScratchInputs=new uint[4];for(int j=0;j<4;++j)s.ScratchInputs[j]=r.ReadUInt32();s.CameraPosition=ReadFloats(r,3);s.Box=new DynamicBoxState();s.Box.View=ReadFloats(r,16);s.Box.Near=r.ReadSingle();s.Box.Far=r.ReadSingle();s.Box.FarOverride=r.ReadSingle();s.Box.HorizontalSlope=r.ReadSingle();s.Box.VerticalSlope=r.ReadSingle();s.Box.Enabled=r.ReadInt32()!=0;s.AllocatorControl=0x10100000;s.Shader=0x10106000;s.TokenBase=0x12345678;s.ScaleScratch=0x10106200;s.TranslationScratch=0x10106240;s.CacheScratch=0x10106300;s.OutputScratch=0x10106310;s.Box.CombinedMatrix=ImageFloats(m,0x10106400,16);s.Box.FarLanes=ImageFloats(m,0x10106440,4);
                uint type=r.ReadUInt32(),variant=r.ReadUInt32(),manager=0x10120000,device=0x1011a000;List<uint[]> trace=new List<uint[]>();List<uint> declarations=new List<uint>();MaterialLifecycleState lifecycle=new MaterialLifecycleState();lifecycle.Cache=0x10119000;lifecycle.CurrentThread=77;lifecycle.MaterialTypeWord=type;lifecycle.Pool=new MaterialPoolState();lifecycle.Pool.Pool=0x10110000;lifecycle.Pool.PendingMaterials=0x10118000;lifecycle.Pool.Capacity=16;lifecycle.Pool.PendingCount=(int)m.Dword(0x1011a700);lifecycle.Refresh=new MaterialRefreshServices();lifecycle.Refresh.Manager=manager;lifecycle.Refresh.DeviceState=device;
                lifecycle.Refresh.ResolveDeclaration=delegate(uint layout){declarations.Add(layout);return layout^0x76543210;};
                lifecycle.Refresh.Factory=delegate(RenderPacketMemory memory,uint mgr,uint runtime,uint material,uint mode,uint zeroA,uint zeroB)
                {
                    int ordinal=trace.Count;uint first=manager+8*0x4d8+4,second=manager+9*0x4d8+4;uint p=ordinal==0||(variant&1)!=0?first:second;memory.Dword(p+4,unchecked(memory.Dword(p+4)+1));if(ordinal==1&&(variant&2)!=0)memory.Word(first,33);if(ordinal==0&&(variant&4)!=0)memory.Byte(device+0x654,(byte)(memory.Byte(device+0x654)^32));if(ordinal==0&&(variant&8)!=0)memory.Word(material+0x74,0);trace.Add(new uint[]{mgr,runtime,material,mode,zeroA,zeroB});return p;
                };
                DynamicSubmissionResult result=DynamicObjectSubmission.SubmitWithMaterialMerge(m,s,handle,matrix,delegate(uint source,uint replacement){return MaterialLifecycle.Merge(m,lifecycle,source,replacement);});Store(m,0x10106400,s.Box.CombinedMatrix);Store(m,0x10106440,s.Box.FarLanes);m.Block(0x10106300,new byte[32]);m.Dword(0x1011a700,(uint)lifecycle.Pool.PendingCount);w.Write(sha.ComputeHash(bytes));w.Write(result.Visibility);w.Write(s.ShadowMask);w.Write(result.Draws.Count);foreach(uint[] draw in result.Draws)foreach(uint word in draw)w.Write(word);w.Write(trace.Count);foreach(uint[] row in trace)foreach(uint word in row)w.Write(word);w.Write(declarations.Count);foreach(uint layout in declarations)w.Write(layout);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
