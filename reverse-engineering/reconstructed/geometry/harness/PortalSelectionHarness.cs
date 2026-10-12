using System;
using System.Collections.Generic;
using System.IO;
using Recovered.Geometry;

// Ordinary managed executable; no original binary, native DLL, or emulator.
public static class PortalSelectionHarness
{
    sealed class Scene
    {
        public PortalRoom[] Rooms;
        public PortalLink[] Portals;
    }
    static int Count(BinaryReader r,int maximum)
    {
        int value=r.ReadInt32();
        if(value<0 || value>maximum) throw new InvalidDataException("Fixture count outside bound.");
        return value;
    }
    static PortalPlane Plane(BinaryReader r)
    {return new PortalPlane(r.ReadSingle(),r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    public static int Main(string[] args)
    {
        if(args.Length!=2) {Console.Error.WriteLine("PortalSelectionHarness fixture.bin results.bin");return 2;}
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        {
            if(r.ReadUInt32()!=0x31534d52) throw new InvalidDataException("Expected RMS1.");
            Scene[] scenes=new Scene[Count(r,100000)];
            for(int s=0;s<scenes.Length;++s)
            {
                Scene scene=new Scene();int nr=Count(r,32767),np=Count(r,32767);
                scene.Rooms=new PortalRoom[nr];scene.Portals=new PortalLink[np];
                for(int i=0;i<nr;++i)
                {
                    uint flags=r.ReadUInt32();byte priority=r.ReadByte();int pc=r.ReadByte(),ic=r.ReadByte();r.ReadByte();
                    PortalPlane[] planes=new PortalPlane[pc];short[] indices=new short[ic];
                    for(int j=0;j<pc;++j) planes[j]=Plane(r);
                    for(int j=0;j<ic;++j) indices[j]=r.ReadInt16();
                    scene.Rooms[i]=new PortalRoom(planes,indices,priority,flags);
                }
                for(int i=0;i<np;++i) scene.Portals[i]=new PortalLink(Plane(r),r.ReadInt16(),r.ReadInt16());
                scenes[s]=scene;
            }
            int count=Count(r,1000000);w.Write(0x4f534d52U);w.Write(count);
            for(int i=0;i<count;++i)
            {
                int si=r.ReadInt32();bool hasPoint=r.ReadBoolean();Point3? p=null;
                if(hasPoint) p=new Point3(r.ReadSingle(),r.ReadSingle(),r.ReadSingle());
                if(si < -1 || si>=scenes.Length) throw new InvalidDataException("Scene index outside fixture table.");
                Scene scene=si==-1?null:scenes[si];
                w.Write(PortalSelection.SelectRoom(scene==null?null:scene.Rooms,scene==null?null:scene.Portals,p));
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Room selection cases: "+count);
        }
        return 0;
    }
}
