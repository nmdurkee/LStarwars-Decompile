using System;
using System.IO;
using System.Security.Cryptography;
using Recovered.Geometry;

public static class PortalTraversalHarness
{
    private sealed class Scene
    {
        public PortalRuntimeScene Runtime;
        public uint[] RoomFlags;
    }
    private static Point3 Point(BinaryReader r) {return new Point3(r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static PortalPlane Plane(BinaryReader r) {return new PortalPlane(r.ReadSingle(),r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static void WritePoint(BinaryWriter w,Point3 p) {w.Write(p.X);w.Write(p.Y);w.Write(p.Z);}
    public static void Main(string[] args)
    {
        if(args.Length!=3) throw new ArgumentException("Input fixture,sine table and output path required.");
        NativeSineTable sine=NativeSineTable.DecodeLittleEndian(File.ReadAllBytes(args[1]));
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[2])))
        using(SHA256 hash=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="PTRV") throw new InvalidDataException("PTRV header required.");
            Scene[] scenes=new Scene[r.ReadInt32()];
            for(int si=0;si<scenes.Length;++si)
            {
                int count=r.ReadInt32(),roomCount=r.ReadInt32(),portalCount=r.ReadInt32();Scene s=new Scene();PortalRuntimeScene scene=new PortalRuntimeScene();
                scene.Centers=new Point3[count];scene.Extents=new Point3[count];
                for(int i=0;i<count;++i) {scene.Centers[i]=Point(r);scene.Extents[i]=Point(r);}
                scene.InstanceFlags=r.ReadBytes(count);scene.OverrideBits=r.ReadBytes(625);scene.Rooms=new RuntimePortalRoom[roomCount];s.RoomFlags=new uint[roomCount];
                for(int i=0;i<roomCount;++i)
                {
                    RuntimePortalRoom room=new RuntimePortalRoom();s.RoomFlags[i]=r.ReadUInt32();room.Priority=r.ReadByte();room.Instances=new short[r.ReadInt32()];room.Portals=new short[r.ReadInt32()];
                    for(int k=0;k<room.Instances.Length;++k) room.Instances[k]=r.ReadInt16();
                    for(int k=0;k<room.Portals.Length;++k) room.Portals[k]=r.ReadInt16();scene.Rooms[i]=room;
                }
                scene.Portals=new RuntimePortal[portalCount];
                for(int i=0;i<portalCount;++i)
                {
                    RuntimePortal p=new RuntimePortal();p.Plane=Plane(r);p.FrontRoom=r.ReadInt16();p.BackRoom=r.ReadInt16();p.ActiveFlags=r.ReadUInt32();p.Vertices=new Point3[r.ReadInt32()];
                    for(int k=0;k<p.Vertices.Length;++k) p.Vertices[k]=Point(r);scene.Portals[i]=p;
                }
                s.Runtime=scene;scenes[si]=s;
            }
            PortalCamera[] cameras=new PortalCamera[r.ReadInt32()];
            for(int i=0;i<cameras.Length;++i)
            {
                float[] world=new float[16],projection=new float[16];for(int k=0;k<16;++k) world[k]=r.ReadSingle();for(int k=0;k<16;++k) projection[k]=r.ReadSingle();
                float fov=r.ReadSingle(),aspect=r.ReadSingle();PortalPlane eye=Plane(r);cameras[i]=new PortalCamera(world,projection,fov,aspect,eye,sine);
            }
            int cases=r.ReadInt32();w.Write(new byte[]{80,84,82,79});w.Write(cases);
            for(int ci=0;ci<cases;++ci)
            {
                Scene source=scenes[r.ReadInt32()];short root=r.ReadInt16();byte mode=r.ReadByte();int depth=r.ReadInt32();PortalCamera camera=cameras[r.ReadInt32()];PortalRuntimeScene original=source.Runtime;
                PortalRuntimeScene scene=new PortalRuntimeScene {Rooms=original.Rooms,Centers=original.Centers,Extents=original.Extents,InstanceFlags=(byte[])original.InstanceFlags.Clone(),OverrideBits=mode==0 ? original.OverrideBits : new byte[625],Portals=new RuntimePortal[original.Portals.Length]};
                if(mode>1) throw new InvalidDataException("Unsupported fixture mode.");
                if(mode==1) for(int i=0;i<scene.InstanceFlags.Length;++i) scene.InstanceFlags[i]=1;
                for(int i=0;i<scene.Portals.Length;++i)
                {
                    RuntimePortal p=original.Portals[i];scene.Portals[i]=new RuntimePortal {Vertices=p.Vertices,Plane=p.Plane,FrontRoom=p.FrontRoom,BackRoom=p.BackRoom,ActiveFlags=mode==0 ? p.ActiveFlags : p.ActiveFlags|1u};
                }
                PortalClipVolume initial=PortalProjection.FromRectangle(new Point3(-1,-1,-1),new Point3(1,1,1),-2,camera);short[] path=new short[16];for(int i=0;i<16;++i) path[i]=-1;
                PortalTraversalState state=new PortalTraversalState(new byte[625],source.RoomFlags,path,initial);PortalTraversal.Traverse(scene,camera,root,depth,state);
                w.Write(hash.ComputeHash(state.VisibilityBits));foreach(uint flags in state.RoomFlags) w.Write(flags);w.Write(state.Entries.Count);
                foreach(PortalVisit entry in state.Entries) {w.Write(entry.Current);w.Write(entry.Previous);w.Write(entry.Depth);}
                foreach(short value in state.Path) w.Write(value);w.Write(state.Volumes.Count);
                for(int vi=0;vi<state.Volumes.Count;++vi)
                {
                    PortalClipVolume v=state.Volumes[vi];int alias=0;while(!Object.ReferenceEquals(v.Planes,state.Volumes[alias].Planes)) ++alias;
                    w.Write(v.Room);w.Write(alias);w.Write(v.Planes.Length);
                    foreach(PortalPlane p in v.Planes) {w.Write(p.X);w.Write(p.Y);w.Write(p.Z);w.Write(p.W);}
                    foreach(float value in v.PackedPlanes) w.Write(value);WritePoint(w,v.ScreenMinimum);WritePoint(w,v.ScreenMaximum);
                }
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} compiled portal traversals.",cases);
        }
    }
}
