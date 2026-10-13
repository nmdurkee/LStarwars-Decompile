using System;
using System.IO;
using System.IO.Compression;
using System.Collections.Generic;
using System.Security.Cryptography;
using Recovered.Geometry;
public static class FrameResetHarness
{
    sealed class Spec
    { public int ClipCount; public int[] Table,RecordContexts;public byte[][] Records,Contexts; }
    sealed class Installed
    { public DisplayResetState State; public MaterialResetRecord[] Records;public byte[][] Contexts; }
    static byte[] Seq(int n,int seed)
    { byte[] b=new byte[n];for(int i=0;i<n;++i)b[i]=(byte)(((i*37+seed*19)^(i>>3))&255);return b; }
    static void Word(byte[] b,int p,uint v)
    { b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24); }
    static byte[] Copy(byte[] b){return (byte[])b.Clone();}
    static byte[] Blob(BinaryReader r)
    { int n=r.ReadInt32();if(n<0 || n>10000000)throw new InvalidDataException();byte[] b=r.ReadBytes(n);if(b.Length!=n)throw new EndOfStreamException();return b; }
    static int[] Integers(BinaryReader r,int count)
    { if(count<0 || count>1000000)throw new InvalidDataException();int[] a=new int[count];for(int i=0;i<count;++i)a[i]=r.ReadInt32();return a; }
    static Spec ReadSpec(BinaryReader r)
    {
        Spec s=new Spec();s.ClipCount=r.ReadInt32();int tc=r.ReadInt32(),rc=r.ReadInt32(),cc=r.ReadInt32(),rcc=r.ReadInt32();
        s.Table=Integers(r,tc);s.Records=new byte[rc][];s.Contexts=new byte[cc][];
        for(int i=0;i<rc;++i)s.Records[i]=Blob(r);for(int i=0;i<cc;++i)s.Contexts[i]=Blob(r);s.RecordContexts=Integers(r,rcc);return s;
    }
    static Installed Install(Spec s,uint flags,int seed,bool owner)
    {
        Installed x=new Installed();x.Records=new MaterialResetRecord[s.Records.Length];x.Contexts=new byte[s.Contexts.Length][];
        for(int i=0;i<x.Contexts.Length;++i)x.Contexts[i]=Copy(s.Contexts[i]);
        for(int i=0;i<x.Records.Length;++i)x.Records[i]=new MaterialResetRecord{Bytes=Copy(s.Records[i]),Context=x.Contexts[s.RecordContexts[i]]};
        MaterialResetRecord[] table=new MaterialResetRecord[s.Table.Length];for(int i=0;i<table.Length;++i)table[i]=x.Records[s.Table[i]];
        int cb=FrameReset.ClipBufferBytes(s.ClipCount),mb=FrameReset.MaterialBufferBytes(table.Length);
        x.State=new DisplayResetState{Flags=flags,ClipCount=s.ClipCount,Materials=table,ClipBuffers=new byte[][]{Seq(cb+16,seed),Seq(cb+16,seed+1)},MaterialBuffers=new byte[][]{Seq(mb+16,seed+2),Seq(mb+16,seed+3)},Owner=owner?Seq(0x50,seed+9):null};return x;
    }
    static void StateBytes(BinaryWriter w,Installed x)
    {
        w.Write(x.State.Flags);foreach(byte[] b in x.State.ClipBuffers)w.Write(b);foreach(byte[] b in x.State.MaterialBuffers)w.Write(b);
        foreach(MaterialResetRecord r in x.Records)w.Write(r.Bytes);foreach(byte[] b in x.Contexts)w.Write(b);
    }
    public static int Main(string[] args)
    {
        if(args.Length!=2){Console.Error.WriteLine("compressedInputFixture outputFile");return 2;}
        using(BinaryReader r=new BinaryReader(new GZipStream(File.OpenRead(args[0]),CompressionMode.Decompress)))
        using(BinaryWriter output=new BinaryWriter(File.Create(args[1])))
        using(SHA256 sha=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="FRST")throw new InvalidDataException();
            int sc=r.ReadInt32(),sourceCount=r.ReadInt32(),caseCount=r.ReadInt32();Spec[] specs=new Spec[sc];for(int i=0;i<sc;++i)specs[i]=ReadSpec(r);
            output.Write(new byte[]{70,82,79,85});output.Write(caseCount);
            for(int ci=0;ci<caseCount;++ci)
            {
                int kind=r.ReadByte();IList<uint> calls=new List<uint>();
                using(MemoryStream ms=new MemoryStream())
                using(BinaryWriter stateOutput=new BinaryWriter(ms))
                {
                    if(kind==0)
                    {
                        int si=r.ReadInt32();uint flags=r.ReadUInt32(),force=r.ReadUInt32();int seed=r.ReadInt32();Installed x=Install(specs[si],flags,seed,false);
                        calls=FrameReset.ResetDisplay(x.State,force);StateBytes(stateOutput,x);
                    }
                    else if(kind<4)
                    {
                        int seed=r.ReadInt32();bool alias=r.ReadBoolean();byte[] global=Seq(420,seed+47),obj=Seq(kind==1?52:420,seed);
                        if(alias)obj=global;
                        if(kind==1)FrameReset.ResetCommandContext(obj);
                        else if(kind==2)FrameReset.ResetShaderContext(obj,global);
                        else FrameReset.ResetGlobalShaderContext(global);
                        if(kind!=3)stateOutput.Write(obj);stateOutput.Write(global);
                    }
                    else if(kind==4)
                    {
                        int count=r.ReadInt32(),pattern=r.ReadInt32();List<Installed> all=new List<Installed>();Installed global=Install(specs[sourceCount+2],(uint)(pattern|0x8000),pattern,false);all.Add(global);
                        List<DisplayResetState> registry=new List<DisplayResetState>();
                        for(int i=0;i<count;++i)
                        {
                            uint flags=(uint)(((i+pattern)%16)|((i&1)<<15));Installed x=Install(specs[sourceCount+i%4],flags,i+pattern+23,i%3!=0);all.Add(x);registry.Add(x.State);
                        }
                        int nodeCount=new int[]{0,1,7,31}[pattern];SortedResetNode[] nodes=new SortedResetNode[nodeCount];
                        for(int i=0;i<nodeCount;++i){byte[] bytes=Seq(32,i+pattern);Word(bytes,8,0);nodes[i]=new SortedResetNode{Bytes=bytes};}
                        for(int i=0;i+1<nodeCount;++i)nodes[i].Next=nodes[i+1];
                        FrameResetState frame=new FrameResetState{Global=global.State,Registered=registry,SortedHead=nodeCount==0?null:nodes[0],PendingCount=0xdeadbeef,ShaderTemplate=Seq(420,pattern+39)};
                        calls=FrameReset.Advance(frame,0,delegate(int value){},delegate(int value){});
                        foreach(Installed x in all){StateBytes(stateOutput,x);if(x.State.Owner!=null)stateOutput.Write(x.State.Owner);}
                        foreach(SortedResetNode node in nodes)stateOutput.Write(node.Bytes);stateOutput.Write(frame.PendingCount);stateOutput.Write(frame.ShaderTemplate);
                    }
                    else throw new InvalidDataException();
                    stateOutput.Flush();output.Write(sha.ComputeHash(ms.ToArray()));output.Write(calls.Count);foreach(uint address in calls)output.Write(address);
                }
            }
            if(r.BaseStream.ReadByte()!=-1)throw new InvalidDataException("Trailing fixture data");
        }
        return 0;
    }
}

