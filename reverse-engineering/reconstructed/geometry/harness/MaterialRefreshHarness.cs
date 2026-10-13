using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class MaterialRefreshHarness
{
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="MRFI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{77,82,70,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32(),size=r.ReadInt32();if(kind<0||kind>6||size!=0x10000)throw new InvalidDataException();byte[] bytes=r.ReadBytes(size);if(bytes.Length!=size)throw new EndOfStreamException();int argc=r.ReadInt32();if(argc<0||argc>3)throw new InvalidDataException();uint[] a=new uint[argc];for(int j=0;j<argc;++j)a[j]=r.ReadUInt32();uint variant=r.ReadUInt32();RenderPacketMemory m=new RenderPacketMemory(0x10100000,bytes);uint manager=0x10104000,device=0x10100800,material=0x10102000;List<uint[]> trace=new List<uint[]>();MaterialRefreshServices services=new MaterialRefreshServices();services.Manager=manager;services.DeviceState=device;
                services.ResolveDeclaration=delegate(uint layout){return layout^0x76543210;};
                services.Factory=delegate(RenderPacketMemory memory,uint mgr,uint runtime,uint mat,uint mode,uint zeroA,uint zeroB)
                {
                    int ordinal=trace.Count;uint first=manager+8*0x4d8+4,second=manager+9*0x4d8+4;uint p=ordinal==0||(variant&1)!=0?first:second;memory.Dword(p+4,unchecked(memory.Dword(p+4)+1));if(ordinal==1&&(variant&2)!=0)memory.Word(first,33);if(ordinal==0&&(variant&4)!=0)memory.Byte(device+0x654,(byte)(memory.Byte(device+0x654)^32));if(ordinal==0&&(variant&8)!=0)memory.Word(material+0x74,0);trace.Add(new uint[]{mgr,runtime,mat,mode,zeroA,zeroB});return p;
                };
                uint result=0;switch(kind)
                {
                    case 0:MaterialRefresh.Refresh(m,material,services);break;
                    case 1:result=MaterialRefresh.ProgramByIndex(manager,a[0]);break;
                    case 2:MaterialRefresh.Release(m,a[0]);break;
                    case 3:result=MaterialRefresh.FirstMode(m,device);break;
                    case 4:result=MaterialRefresh.SecondMode(m,device);break;
                    case 5:result=MaterialRefresh.RequestDefault(m,services,a[0],a[1]);break;
                    case 6:result=MaterialRefresh.RequestMode(m,services,a[0],a[1],a[2]);break;
                }
                w.Write(sha.ComputeHash(bytes));w.Write(result);w.Write(trace.Count);foreach(uint[] row in trace)foreach(uint word in row)w.Write(word);
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
