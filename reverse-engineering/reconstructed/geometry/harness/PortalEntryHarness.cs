using System;
using System.IO;
using System.Security.Cryptography;
using Recovered.Geometry;

public static class PortalEntryHarness
{
    private sealed class Scene
    {
        public PortalRuntimeScene Runtime;
        public PortalRoom[] SelectionRooms;
        public uint[] RoomFlags;
    }
    private static Point3 Point(BinaryReader r) {return new Point3(r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static PortalPlane Plane(BinaryReader r) {return new PortalPlane(r.ReadSingle(),r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static void WritePoint(BinaryWriter w,Point3 p) {w.Write(p.X);w.Write(p.Y);w.Write(p.Z);}
    private static void WritePlane(BinaryWriter w,PortalPlane p) {w.Write(p.X);w.Write(p.Y);w.Write(p.Z);w.Write(p.W);}
    public static void Main(string[] args)
    {
        if(args.Length!=3) throw new ArgumentException("Input fixture,sine table and output path required.");
        NativeSineTable sine=NativeSineTable.DecodeLittleEndian(File.ReadAllBytes(args[1]));
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[2])))
        using(SHA256 hash=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="PENT") throw new InvalidDataException("PENT header required.");
            Scene[] scenes=new Scene[r.ReadInt32()];
            for(int si=0;si<scenes.Length;++si)
            {
                int bounds=r.ReadInt32(),rooms=r.ReadInt32(),portals=r.ReadInt32();Scene s=new Scene();PortalRuntimeScene v=new PortalRuntimeScene();
                v.Centers=new Point3[bounds];v.Extents=new Point3[bounds];
                for(int i=0;i<bounds;++i) {v.Centers[i]=Point(r);v.Extents[i]=Point(r);}
                v.InstanceFlags=r.ReadBytes(bounds);v.OverrideBits=r.ReadBytes(625);v.Rooms=new RuntimePortalRoom[rooms];s.RoomFlags=new uint[rooms];s.SelectionRooms=new PortalRoom[rooms];
                for(int i=0;i<rooms;++i)
                {
                    uint flags=r.ReadUInt32();byte priority=r.ReadByte();short[] instances=new short[r.ReadInt32()],links=new short[r.ReadInt32()];PortalPlane[] planes=new PortalPlane[r.ReadInt32()];
                    for(int j=0;j<instances.Length;++j) instances[j]=r.ReadInt16();
                    for(int j=0;j<links.Length;++j) links[j]=r.ReadInt16();
                    for(int j=0;j<planes.Length;++j) planes[j]=Plane(r);
                    v.Rooms[i]=new RuntimePortalRoom {Instances=instances,Portals=links,Priority=priority};s.RoomFlags[i]=flags;s.SelectionRooms[i]=new PortalRoom(planes,links,priority,flags);
                }
                v.Portals=new RuntimePortal[portals];
                for(int i=0;i<portals;++i)
                {
                    RuntimePortal p=new RuntimePortal();p.Plane=Plane(r);p.FrontRoom=r.ReadInt16();p.BackRoom=r.ReadInt16();p.ActiveFlags=r.ReadUInt32();p.Vertices=new Point3[r.ReadInt32()];
                    for(int j=0;j<p.Vertices.Length;++j) p.Vertices[j]=Point(r);v.Portals[i]=p;
                }
                s.Runtime=v;scenes[si]=s;
            }
            PortalEntryCamera[] cameras=new PortalEntryCamera[r.ReadInt32()];
            for(int i=0;i<cameras.Length;++i)
            {
                PortalEntryCamera c=new PortalEntryCamera {World=new float[16],Projection=new float[16]};
                for(int j=0;j<16;++j) c.World[j]=r.ReadSingle();for(int j=0;j<16;++j) c.Projection[j]=r.ReadSingle();
                c.FieldOfView=r.ReadSingle();c.Aspect=r.ReadSingle();c.Near=r.ReadSingle();cameras[i]=c;
            }
            int cases=r.ReadInt32();w.Write(new byte[]{80,69,78,79});w.Write(cases);
            for(int ci=0;ci<cases;++ci)
            {
                Scene source=scenes[r.ReadInt32()];byte mode=r.ReadByte();bool useOverride=r.ReadBoolean();byte gate=r.ReadByte();Point3 point=Point(r);PortalEntryCamera camera=cameras[r.ReadInt32()];int depth=r.ReadInt32();
                PortalRuntimeScene original=source.Runtime;
                if(mode>1 || gate>4) throw new InvalidDataException("Unsupported fixture mode.");
                PortalRuntimeScene scene=new PortalRuntimeScene {Rooms=gate==3?new RuntimePortalRoom[0]:original.Rooms,Centers=gate==4?new Point3[0]:original.Centers,Extents=original.Extents,InstanceFlags=(byte[])original.InstanceFlags.Clone(),OverrideBits=mode==0?original.OverrideBits:new byte[625],Portals=new RuntimePortal[gate==2?0:original.Portals.Length]};
                if(mode==1) for(int i=0;i<scene.InstanceFlags.Length;++i) scene.InstanceFlags[i]=1;
                for(int i=0;i<scene.Portals.Length;++i)
                {
                    RuntimePortal p=original.Portals[i];scene.Portals[i]=new RuntimePortal {Vertices=p.Vertices,Plane=p.Plane,FrontRoom=p.FrontRoom,BackRoom=p.BackRoom,ActiveFlags=mode==0?p.ActiveFlags:p.ActiveFlags|1u};
                }
                byte[] bits=new byte[625];for(int i=0;i<bits.Length;++i) bits[i]=0xa5;
                uint[] flags=(uint[])source.RoomFlags.Clone();for(int i=0;i<flags.Length;++i) flags[i]|=4;
                short[] path=new short[16];for(int i=0;i<16;++i) path[i]=-1;
                PortalEntryState state=new PortalEntryState(bits,flags,path);state.SelectedGlobal=0x7777;state.SelectedHeader=0x12345678;
                state.CameraCopy=new float[16];for(int i=0;i<16;++i) state.CameraCopy[i]=i;
                state.CachedPosition=new Point3(91,92,93);state.CameraPlane=new PortalPlane(-1,2,-3,4);state.NearPlane=new PortalPlane(5,-6,7,-8);
                state.Volumes.Add(new PortalClipVolume(new PortalPlane[0],new float[32],new Point3(),new Point3(),-7));
                bool returned=PortalEntry.Run(scene,source.SelectionRooms,gate!=1,camera,useOverride?(Point3?)point:null,depth,sine,state);
                w.Write(returned);w.Write(state.VisibilityAttached);w.Write(state.CameraBound);w.Write(state.SelectedGlobal);w.Write(state.SelectedHeader);
                foreach(float value in state.CameraCopy) w.Write(value);WritePoint(w,state.CachedPosition);WritePlane(w,state.CameraPlane);WritePlane(w,state.NearPlane);w.Write(hash.ComputeHash(state.VisibilityBits));
                foreach(uint value in state.RoomFlags) w.Write(value);w.Write(state.Entries.Count);
                foreach(PortalVisit e in state.Entries) {w.Write(e.Current);w.Write(e.Previous);w.Write(e.Depth);}
                foreach(short value in state.Path) w.Write(value);w.Write(state.Volumes.Count);
                for(int vi=0;vi<state.Volumes.Count;++vi)
                {
                    PortalClipVolume v=state.Volumes[vi];int alias=0;while(!Object.ReferenceEquals(v.Planes,state.Volumes[alias].Planes)) ++alias;
                    w.Write(v.Room);w.Write(alias);w.Write(v.Planes.Length);foreach(PortalPlane p in v.Planes) WritePlane(w,p);
                    foreach(float value in v.PackedPlanes) w.Write(value);WritePoint(w,v.ScreenMinimum);WritePoint(w,v.ScreenMaximum);
                }
                if(returned)
                {
                    int roomCount=source.RoomFlags.Length;
                    for(int room=-2;room<=roomCount;++room) w.Write((byte)(PortalRoomOutputs.HasClipForRoom(true,state.Volumes,(short)room)?1:0));
                    byte[] mask=new byte[roomCount+16];for(int i=0;i<mask.Length;++i) mask[i]=0xa5;
                    PortalRoomOutputs.WriteRoomMask(true,roomCount,state.SelectedGlobal,state.Volumes,mask);w.Write(mask);
                }
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} portal-entry cases.",cases);
        }
    }
}
