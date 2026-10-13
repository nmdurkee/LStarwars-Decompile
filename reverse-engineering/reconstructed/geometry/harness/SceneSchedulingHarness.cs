using System;
using System.IO;
using System.Security.Cryptography;
using Recovered.Geometry;

public static class SceneSchedulingHarness
{
    private sealed class Scene
    {
        public PortalRuntimeScene Runtime;
        public PortalRoom[] Selection;
        public ClipObject[] Clips;
        public ClipBounds[] Bounds;
        public ScheduledSpecial[] Specials;
        public uint[] RoomFlags;
        public float[] Fade;
        public int MaterialCount;
    }
    private static Point3 Point(BinaryReader r) {return new Point3(r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static PortalPlane Plane(BinaryReader r) {return new PortalPlane(r.ReadSingle(),r.ReadSingle(),r.ReadSingle(),r.ReadSingle());}
    private static float[] Floats(BinaryReader r,int count) {float[] v=new float[count];for(int i=0;i<count;++i) v[i]=r.ReadSingle();return v;}
    private static void Calls(BinaryWriter w,SchedulingState s) {w.Write(s.Calls.Count);foreach(uint a in s.Calls) w.Write(a);}
    private static byte[] ShaderBytes(uint[] words) {byte[] b=new byte[420];for(int i=0;i<105;++i) {uint v=words[i];for(int j=0;j<4;++j) b[i*4+j]=(byte)(v>>(j*8));}return b;}
    private static uint[] Template(uint value,bool stepped) {uint[] v=new uint[105];for(int i=0;i<105;++i) v[i]=value+(stepped?(uint)(i*17):0);return v;}
    private static SchedulingState State(byte[] bits,uint[] flags)
    {
        short[] path=new short[16];for(int i=0;i<16;++i) path[i]=-1;
        PortalEntryState portal=new PortalEntryState(bits,flags,path);portal.SelectedHeader=0x12345678;portal.SelectedGlobal=0x7777;
        portal.Volumes.Add(new PortalClipVolume(new PortalPlane[0],new float[32],new Point3(),new Point3(),-7));
        return new SchedulingState {Portal=portal,ContextFlags=0xffffffff,ContextScratch=0x77777777,InstanceTreeBits=new byte[]{0x88},ShaderContext=Template(0xa5a5a5a5,false)};
    }
    private static Scene ReadScene(BinaryReader r)
    {
        int bounds=r.ReadInt32(),rooms=r.ReadInt32(),portals=r.ReadInt32(),clips=r.ReadInt32(),materials=r.ReadInt32(),specials=r.ReadInt32();
        Scene s=new Scene();PortalRuntimeScene v=new PortalRuntimeScene();v.Centers=new Point3[bounds];v.Extents=new Point3[bounds];s.Bounds=new ClipBounds[bounds];
        for(int i=0;i<bounds;++i) {v.Centers[i]=Point(r);v.Extents[i]=Point(r);s.Bounds[i]=new ClipBounds {Center=v.Centers[i],Extent=v.Extents[i]};}
        v.InstanceFlags=r.ReadBytes(bounds);v.OverrideBits=r.ReadBytes(625);v.Rooms=new RuntimePortalRoom[rooms];s.RoomFlags=new uint[rooms];s.Selection=new PortalRoom[rooms];
        for(int i=0;i<rooms;++i)
        {
            uint flags=r.ReadUInt32();byte priority=r.ReadByte();short[] instances=new short[r.ReadInt32()],links=new short[r.ReadInt32()];PortalPlane[] planes=new PortalPlane[r.ReadInt32()];
            for(int j=0;j<instances.Length;++j) instances[j]=r.ReadInt16();for(int j=0;j<links.Length;++j) links[j]=r.ReadInt16();for(int j=0;j<planes.Length;++j) planes[j]=Plane(r);
            v.Rooms[i]=new RuntimePortalRoom {Instances=instances,Portals=links,Priority=priority};s.RoomFlags[i]=flags;s.Selection[i]=new PortalRoom(planes,links,priority,flags);
        }
        v.Portals=new RuntimePortal[portals];
        for(int i=0;i<portals;++i)
        {
            RuntimePortal p=new RuntimePortal();p.Plane=Plane(r);p.FrontRoom=r.ReadInt16();p.BackRoom=r.ReadInt16();p.ActiveFlags=r.ReadUInt32();p.Vertices=new Point3[r.ReadInt32()];
            for(int j=0;j<p.Vertices.Length;++j) p.Vertices[j]=Point(r);v.Portals[i]=p;
        }
        s.Clips=new ClipObject[clips];
        for(int i=0;i<clips;++i)
        {
            ClipObject c=new ClipObject {LodDistanceSquared=r.ReadSingle(),FarClipDistance=r.ReadSingle(),MaterialIndices=new int[r.ReadInt32()]};
            for(int j=0;j<c.MaterialIndices.Length;++j) c.MaterialIndices[j]=r.ReadInt32();s.Clips[i]=c;
        }
        s.Fade=Floats(r,bounds*2);s.Specials=new ScheduledSpecial[specials];
        for(int i=0;i<specials;++i)
        {
            ScheduledSpecial p=new ScheduledSpecial {Flags=r.ReadUInt32(),BoundsIndex=r.ReadInt32(),Matrix=Floats(r,16)};
            if(r.ReadBoolean()) p.OverrideMatrix=Floats(r,16);s.Specials[i]=p;
        }
        s.Runtime=v;s.MaterialCount=materials;return s;
    }
    public static void Main(string[] args)
    {
        if(args.Length!=3) throw new ArgumentException("Input fixture,sine table and output file required.");
        NativeSineTable sine=NativeSineTable.DecodeLittleEndian(File.ReadAllBytes(args[1]));
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[2])))
        using(SHA256 hash=SHA256.Create())
        {
            if(new string(r.ReadChars(4))!="PSCI") throw new InvalidDataException("PSCI header required.");
            Scene[] scenes=new Scene[r.ReadInt32()];for(int i=0;i<scenes.Length;++i) scenes[i]=ReadScene(r);
            int count=r.ReadInt32();w.Write(new byte[]{80,83,67,79});w.Write(count);
            for(int ci=0;ci<count;++ci)
            {
                Scene source=scenes[r.ReadInt32()];int mode=r.ReadByte(),parity=r.ReadByte();bool enabled=r.ReadBoolean(),filter=r.ReadBoolean();
                PortalEntryCamera camera=new PortalEntryCamera {World=Floats(r,16),Projection=Floats(r,16),FieldOfView=r.ReadSingle(),Aspect=r.ReadSingle(),Near=r.ReadSingle()};Point3 selection=Point(r);int depth=r.ReadInt32();NativeFrustum frustum=NativeFrustum.DecodeNativePlaneBlock(r.ReadBytes(336),1000);
                byte[] flags=(byte[])source.Runtime.InstanceFlags.Clone();if(mode==1) for(int i=0;i<flags.Length;++i) flags[i]=1;
                PortalRuntimeScene runtime=new PortalRuntimeScene {Rooms=source.Runtime.Rooms,Centers=source.Runtime.Centers,Extents=source.Runtime.Extents,InstanceFlags=flags,OverrideBits=mode==0?source.Runtime.OverrideBits:new byte[625],Portals=new RuntimePortal[source.Runtime.Portals.Length]};
                for(int i=0;i<runtime.Portals.Length;++i) {RuntimePortal p=source.Runtime.Portals[i];runtime.Portals[i]=new RuntimePortal {Vertices=p.Vertices,Plane=p.Plane,FrontRoom=p.FrontRoom,BackRoom=p.BackRoom,ActiveFlags=mode==0?p.ActiveFlags:p.ActiveFlags|1u};}
                SceneVisibility visibility=new SceneVisibility(source.Clips,source.Bounds,flags,source.MaterialCount);visibility.Flags=0x4000u|((uint)parity<<15);visibility.FadeRanges=source.Fade;
                SchedulingScene scene=new SchedulingScene {PortalScene=runtime,SelectionRooms=source.Selection,Static=visibility,Specials=source.Specials,LegacyInstanceCount=source.Bounds.Length,PortalMarkerPresent=true};
                byte[] bits=new byte[625];for(int i=0;i<bits.Length;++i) bits[i]=0xa5;uint[] roomFlags=(uint[])source.RoomFlags.Clone();for(int i=0;i<roomFlags.Length;++i) roomFlags[i]|=4;
                SchedulingState state=State(bits,roomFlags);SchedulingOptions options=new SchedulingOptions {PortalsEnabled=enabled,DynamicPortalFiltering=filter};
                SceneScheduling.Run(scene,options,state,Template(0x12340000,true),camera,selection,depth,sine,frustum);
                Calls(w,state);w.Write(visibility.Flags);w.Write(state.ContextCount);w.Write(state.ContextScratch);w.Write(state.InstanceTreeBits==null?0u:1u);w.Write(state.ContextFlags);w.Write(options.CurrentCameraMode);w.Write(state.VisibilityActive?1:0);foreach(uint value in state.ShaderContext) w.Write(value);
                w.Write(visibility.MaterialBits[parity]);w.Write(visibility.ClipBits[parity]);w.Write(state.Dynamic.Count);
                foreach(DynamicSubmission d in state.Dynamic) {w.Write(d.SpecialIndex);w.Write(d.UsesOverride);foreach(float v in d.Matrix) w.Write(v);}
                int alphaCount=0;for(int i=0;i<source.Clips.Length;++i) if(((visibility.ClipBits[parity][i>>2]>>((i&3)*2))&3)!=0) ++alphaCount;
                w.Write(alphaCount);for(int i=0;i<source.Clips.Length;++i) if(((visibility.ClipBits[parity][i>>2]>>((i&3)*2))&3)!=0) {w.Write(i);w.Write(visibility.AlphaValues[i]);}
                w.Write(hash.ComputeHash(state.Portal.VisibilityBits));SceneScheduling.Run(scene,options,state,Template(0x12340000,true),camera,selection,depth,sine,frustum);Calls(w,state);options.SkipAll=true;SceneScheduling.Run(scene,options,state,Template(0x12340000,true),camera,selection,depth,sine,frustum);Calls(w,state);
            }
            int boundaryCount=r.ReadInt32();w.Write(boundaryCount);
            float[] identity={1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1};PortalEntryCamera emptyCamera=new PortalEntryCamera {World=identity,Projection=identity,FieldOfView=1,Aspect=.75f,Near=.1f};NativeFrustum emptyFrustum=NativeFrustum.DecodeNativePlaneBlock(new byte[336],1000);
            for(int ci=0;ci<boundaryCount;++ci)
            {
                bool skip=r.ReadBoolean(),dirty=r.ReadBoolean(),skipDynamic=r.ReadBoolean(),flag16=r.ReadBoolean(),marker=r.ReadBoolean(),enabled=r.ReadBoolean(),filter=r.ReadBoolean();
                byte[] flags={0,8,0,0,8,0,0,0};ClipBounds[] bounds=new ClipBounds[8];for(int i=0;i<8;++i) bounds[i]=new ClipBounds();
                SceneVisibility visibility=new SceneVisibility(new ClipObject[0],bounds,flags,0);visibility.Flags=0x4000u|(dirty?4u:0)|(flag16?0x10000u:0);
                ScheduledSpecial[] specials=new ScheduledSpecial[8];for(int i=0;i<8;++i) specials[i]=new ScheduledSpecial {Flags=i%4!=3?2u:0,BoundsIndex=i,Matrix=new float[16],OverrideMatrix=i%3==2?new float[16]:null};
                PortalRuntimeScene runtime=new PortalRuntimeScene {Rooms=new RuntimePortalRoom[0],Portals=new RuntimePortal[0],Centers=new Point3[8],Extents=new Point3[8],InstanceFlags=flags,OverrideBits=new byte[625]};
                SchedulingScene scene=new SchedulingScene {PortalScene=runtime,SelectionRooms=new PortalRoom[0],Static=visibility,Specials=specials,LegacyInstanceCount=8,PortalMarkerPresent=marker};byte[] bits=new byte[625];bits[0]=0x24;
                SchedulingState state=State(bits,new uint[0]);SchedulingOptions options=new SchedulingOptions {SkipAll=skip,SkipDynamic=skipDynamic,PortalsEnabled=enabled,DynamicPortalFiltering=filter};
                SceneScheduling.Run(scene,options,state,Template(0x19191919,false),emptyCamera,null,0,sine,emptyFrustum);
                Calls(w,state);w.Write(visibility.Flags);w.Write(hash.ComputeHash(ShaderBytes(state.ShaderContext)));w.Write(state.Dynamic.Count);foreach(DynamicSubmission d in state.Dynamic) {w.Write(d.SpecialIndex);w.Write(d.UsesOverride);}
            }
            int prepareCount=r.ReadInt32();w.Write(prepareCount);
            for(int ci=0;ci<prepareCount;++ci)
            {
                bool workspace=r.ReadBoolean(),enabled=r.ReadBoolean(),alternate=r.ReadBoolean();int alternateCount=r.ReadInt32();
                SchedulingScene scene=new SchedulingScene {LegacyInstanceCount=8,AlternateInstanceCount=alternate?(int?)alternateCount:null};SchedulingOptions options=new SchedulingOptions {VisibilityEnabled=enabled};SchedulingState state=State(new byte[625],new uint[0]);state.ContextCount=0x12345678;
                VisibilityInputs result=SceneScheduling.PrepareVisibility(scene,options,state,workspace,null,null,0,null);
                w.Write(result!=null);w.Write(state.ContextCount);w.Write(state.ContextScratch);w.Write(state.InstanceTreeBits!=null);w.Write(state.ContextFlags);w.Write(state.VisibilityActive?1u:0u);
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} authored scheduling cases and {1} boundary cases.",count,boundaryCount+prepareCount);
        }
    }
}
