using System;
using System.IO;
using Recovered.Geometry;

public static class PortalVolumeHarness
{
    private sealed class Portal
    {
        public Point3[] Vertices;
        public PortalPlane Plane;
        public short Room;
    }
    private static Point3 Point(BinaryReader r) {return new Point3(r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static PortalPlane Plane(BinaryReader r) {return new PortalPlane(r.ReadSingle(),r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    public static void Main(string[] args)
    {
        if(args.Length!=2) throw new ArgumentException("Input fixture and output path required.");
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        {
            if(new string(r.ReadChars(4))!="PVOL") throw new InvalidDataException("PVOL header required.");
            Portal[] portals=new Portal[r.ReadInt32()];
            for(int i=0;i<portals.Length;++i)
            {
                Portal p=new Portal();p.Vertices=new Point3[r.ReadInt32()];p.Plane=Plane(r);p.Room=r.ReadInt16();
                for(int k=0;k<p.Vertices.Length;++k) p.Vertices[k]=Point(r);
                portals[i]=p;
            }
            int cases=r.ReadInt32();w.Write(new byte[]{80,86,76,79});w.Write(cases);
            for(int ci=0;ci<cases;++ci)
            {
                Portal p=portals[r.ReadInt32()];Point3 camera=Point(r);PortalPlane cameraPlane=Plane(r);
                Point3 minimum=Point(r),maximum=Point(r);
                PortalClipVolume volume=PortalVolumes.FromPortalEdges(p.Vertices,p.Plane,camera,cameraPlane,minimum,maximum,p.Room);
                foreach(PortalPlane plane in volume.Planes) {w.Write(plane.X);w.Write(plane.Y);w.Write(plane.Z);w.Write(plane.W);}
                foreach(float value in volume.PackedPlanes) w.Write(value);
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} compiled edge volumes.",cases);
        }
    }
}
