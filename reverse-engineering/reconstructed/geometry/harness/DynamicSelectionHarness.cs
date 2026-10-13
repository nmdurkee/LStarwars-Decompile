using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using Recovered.Geometry;
public static class DynamicSelectionHarness
{
    private static void Material(BinaryReader r,BinaryWriter w)
    {
        byte tag=checked((byte)r.ReadInt32());bool tablePresent=r.ReadInt32()!=0,tableEntry=r.ReadInt32()!=0,globalEntry=r.ReadInt32()!=0,sameLayout=r.ReadInt32()!=0;int mode=r.ReadInt32();RenderPacketMemory m=new RenderPacketMemory(0x10100000,new byte[0x10000]);uint[] p=new uint[6];for(uint i=0;i<6;++i){p[i]=0x10104000+i*0x400;m.Dword(p[i]+0x1f0,7);}
        m.Byte(p[0]+0x9a,tag);m.Dword(0x10103400+(uint)tag*4,tableEntry?p[2]:0);m.Dword(p[1]+0x1f0,sameLayout?7U:8U);m.Dword(p[2]+0x1f0,sameLayout?7U:8U);
        int[] starts=new int[]{0,1,2,5};byte[,] gates=new byte[,]{{0,0,0},{255,0,0},{1,0,0},{0,1,0}};
        for(int i=0;i<starts.Length;++i){uint a=p[starts[i]];m.Dword(a+0x30,p[3]);for(uint j=0;j<3;++j)m.Byte(a+248+j,gates[i,j]);}
        m.Dword(p[3]+0x30,p[4]);for(uint j=0;j<3;++j)m.Byte(p[3]+248+j,255);bool merged=false;
        uint first=DynamicSelection.ChooseMaterial(m,p[0],globalEntry?p[1]:0,tablePresent?0x10103400U:0,delegate(uint source,uint replacement){merged=true;return p[5];});IList<uint> selected=DynamicSelection.FilterChain(m,first,mode);w.Write(merged?1U:0);w.Write(selected.Count);foreach(uint material in selected)w.Write((material-0x10104000)/0x400);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        {
            if(new string(r.ReadChars(4))!="DSSI")throw new InvalidDataException();int count=r.ReadInt32();if(count<0||count>1000000)throw new InvalidDataException();w.Write(new byte[]{68,83,83,79});w.Write(count);
            for(int i=0;i<count;++i)
            {
                int kind=r.ReadInt32();if(kind==1){Material(r,w);continue;}if(kind!=0)throw new InvalidDataException();int n=r.ReadInt32();if(n<=0||n>1000000)throw new InvalidDataException();float[] thresholds=new float[n];for(int j=0;j<n;++j)thresholds[j]=r.ReadSingle();float distance=r.ReadSingle();int forced=r.ReadInt32();w.Write(DynamicSelection.SelectLod(thresholds,distance,forced));
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture");
        }
        return 0;
    }
}
