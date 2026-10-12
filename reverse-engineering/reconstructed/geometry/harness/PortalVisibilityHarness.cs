using System;
using System.IO;
using System.Security.Cryptography;
using Recovered.Geometry;

public static class PortalVisibilityHarness
{
    private sealed class Scene
    {
        public Point3[] Center,Extent;
        public byte[] Flags,Overrides;
        public short[][] Rooms;
    }
    private static Point3 Point(BinaryReader r) {return new Point3(r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static PortalPlane Plane(BinaryReader r) {return new PortalPlane(r.ReadSingle(),r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    public static void Main(string[] args)
    {
        if(args.Length!=2) throw new ArgumentException("Input fixture and output path required.");
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        using(SHA256 hash=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="PVIS") throw new InvalidDataException("PVIS header required.");
            Scene[] scenes=new Scene[r.ReadInt32()];
            for(int si=0;si<scenes.Length;++si)
            {
                Scene s=new Scene();int count=r.ReadInt32(),rooms=r.ReadInt32();
                s.Center=new Point3[count];s.Extent=new Point3[count];s.Rooms=new short[rooms][];
                for(int i=0;i<count;++i) {s.Center[i]=Point(r);s.Extent[i]=Point(r);}
                s.Flags=r.ReadBytes(count);s.Overrides=r.ReadBytes(PortalVisibility.ByteCount);
                for(int ri=0;ri<rooms;++ri)
                {
                    s.Rooms[ri]=new short[r.ReadInt32()];
                    for(int i=0;i<s.Rooms[ri].Length;++i) s.Rooms[ri][i]=r.ReadInt16();
                }
                scenes[si]=s;
            }
            int clipCount=r.ReadInt32();PortalPlane[][] clips=new PortalPlane[clipCount][];PortalPlane[] cameraPlanes=new PortalPlane[clipCount];
            for(int ci=0;ci<clipCount;++ci)
            {
                clips[ci]=new PortalPlane[r.ReadInt32()];
                for(int i=0;i<clips[ci].Length;++i) clips[ci][i]=Plane(r);
                cameraPlanes[ci]=Plane(r);
            }
            int cases=r.ReadInt32();w.Write(new byte[]{80,86,73,79});w.Write(cases);
            for(int ci=0;ci<cases;++ci)
            {
                Scene s=scenes[r.ReadInt32()];short[] members=s.Rooms[r.ReadInt32()];int clip=r.ReadInt32();byte mode=r.ReadByte();
                byte[] flags=(byte[])s.Flags.Clone(),overrides=(byte[])s.Overrides.Clone(),bits=new byte[PortalVisibility.ByteCount];
                if(mode>3) throw new InvalidDataException("Invalid fixture mode.");
                if(mode!=0)
                {
                    for(int i=0;i<flags.Length;++i) flags[i]=mode==1 ? (byte)1 : mode==2 ? (byte)0 : (byte)9;
                    for(int i=0;i<bits.Length;++i) {overrides[i]=mode==2 ? (byte)0x55 : (byte)0;bits[i]=mode==3 ? (byte)0x24 : (byte)0;}
                }
                PortalVisibility.MarkClipped(members,bits,overrides,flags,true,s.Center,s.Extent,null,clips[clip],cameraPlanes[clip]);
                w.Write(hash.ComputeHash(bits));
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} compiled visibility hashes.",cases);
        }
    }
}
