// Bounded CPU portal-entry orchestration recovered from original PC 0x5eeb30.
// Modern display0x4000; prepared camera input; debug rendering disabled.
// Native/Python evidence: geometry-portal-entry-native-validation.json.
// Compiled execution remains pending. No GPU or live camera-producer claim.
using System;
using System.Collections.Generic;
using Wide=Recovered.Animation.PlaybackWide;

namespace Recovered.Geometry
{
    public sealed class PortalEntryCamera
    {
        public float[] World,Projection;
        public float FieldOfView,Aspect,Near;
    }
    public sealed class PortalEntryState
    {
        public readonly byte[] VisibilityBits;
        public readonly uint[] RoomFlags;
        public readonly short[] Path;
        public readonly List<PortalClipVolume> Volumes=new List<PortalClipVolume>();
        // Diagnostic recursion entries are not an original persistent field.
        public readonly List<PortalVisit> Entries=new List<PortalVisit>();
        public bool VisibilityAttached,CameraBound;
        public int SelectedHeader;
        public short SelectedGlobal;
        public float[] CameraCopy;
        public Point3 CachedPosition;
        public PortalPlane CameraPlane,NearPlane;
        public PortalEntryState(byte[] bits,uint[] roomFlags,short[] path)
        {
            if(bits==null || bits.Length!=625 || roomFlags==null || path==null || path.Length!=16) throw new ArgumentException("Invalid bounded entry state.");
            VisibilityBits=(byte[])bits.Clone();RoomFlags=(uint[])roomFlags.Clone();Path=(short[])path.Clone();
        }
    }
    public static class PortalEntry
    {
        private static float Offset(float position,float normal,float near)
        {return Wide.Add(Wide.From(position),Wide.Multiply(Wide.From(normal),Wide.From(near))).Store();}
        private static float Constant(Point3 normal,Point3 position)
        {
            Wide xy=Wide.Add(Wide.Multiply(Wide.From(position.X),Wide.From(normal.X)),Wide.Multiply(Wide.From(position.Y),Wide.From(normal.Y)));
            // Negating after the final store can differ only in signed-zero
            //representation from the original fchs before float32 store.
            return -Wide.Add(xy,Wide.Multiply(Wide.From(position.Z),Wide.From(normal.Z))).Store();
        }

        // Original0x5eeb30. Visibility attachment occurs before every gate.
        //Disabled writes all625 visibility bytes toFF. Missing required counts
        //return false without changing prior bits,root,clips or camera caches.
        //Eligible calls clear bits and clip count and cache the camera before
        //selection. Failed selection retains old room flags and plane caches.
        public static bool Run(PortalRuntimeScene scene,IList<PortalRoom> selectionRooms,bool enabled,PortalEntryCamera input,Point3? selectionOverride,int depthLimit,NativeSineTable sine,PortalEntryState state)
        {
            if(scene==null || state==null) throw new ArgumentNullException();
            state.VisibilityAttached=true;state.Entries.Clear();
            if(!enabled)
            {
                for(int i=0;i<625;++i) state.VisibilityBits[i]=255;
                return false;
            }
            if(scene.Portals==null || scene.Rooms==null || scene.Centers==null) throw new ArgumentException("Declared scene arrays required.");
            if(scene.Portals.Length==0 || scene.Rooms.Length==0 || scene.Centers.Length==0) return false;
            if(selectionRooms==null || selectionRooms.Count!=scene.Rooms.Length || state.RoomFlags.Length!=scene.Rooms.Length) throw new ArgumentException("Room records must match the declared count.");
            if(input==null || input.World==null || input.World.Length!=16) throw new ArgumentException("Prepared camera world matrix required.");
            foreach(float value in input.World) NativeFrustum.Finite(value);
            NativeFrustum.Finite(input.Near);
            state.Volumes.Clear();Array.Clear(state.VisibilityBits,0,625);
            state.CameraCopy=(float[])input.World.Clone();state.CameraBound=true;
            state.CachedPosition=new Point3(input.World[12],input.World[13],input.World[14]);
            PortalRoom[] rooms=new PortalRoom[selectionRooms.Count];PortalLink[] links=new PortalLink[scene.Portals.Length];
            for(int i=0;i<rooms.Length;++i)
            {
                PortalRoom r=selectionRooms[i];if(r==null) throw new ArgumentException("Null room record.");
                rooms[i]=new PortalRoom(r.Planes,r.PortalIndices,r.Priority,state.RoomFlags[i]);
            }
            for(int i=0;i<links.Length;++i)
            {
                RuntimePortal p=scene.Portals[i];if(p==null) throw new ArgumentException("Null portal record.");
                links[i]=new PortalLink(p.Plane,p.FrontRoom,p.BackRoom);
            }
            short selected=PortalSelection.SelectRoom(rooms,links,selectionOverride.HasValue?selectionOverride:state.CachedPosition);
            state.SelectedGlobal=selected;state.SelectedHeader=selected;
            if(selected==-1) return false;
            Point3 normal=new Point3(input.World[8],input.World[9],input.World[10]);
            Point3 shifted=new Point3(Offset(state.CachedPosition.X,normal.X,input.Near),Offset(state.CachedPosition.Y,normal.Y,input.Near),Offset(state.CachedPosition.Z,normal.Z,input.Near));
            state.NearPlane=new PortalPlane(normal.X,normal.Y,normal.Z,Constant(normal,shifted));
            state.CameraPlane=new PortalPlane(normal.X,normal.Y,normal.Z,Constant(normal,state.CachedPosition));
            PortalCamera camera=new PortalCamera(input.World,input.Projection,input.FieldOfView,input.Aspect,state.CameraPlane,sine);
            PortalClipVolume initial=PortalProjection.FromRectangle(new Point3(-1,-1,-1),new Point3(1,1,1),-2,camera);
            for(int i=0;i<state.RoomFlags.Length;++i) state.RoomFlags[i]&=~4u;
            PortalTraversalState traversal=new PortalTraversalState(state.VisibilityBits,state.RoomFlags,state.Path,initial);
            PortalTraversal.Traverse(scene,camera,selected,depthLimit,traversal);
            Array.Copy(traversal.VisibilityBits,state.VisibilityBits,625);Array.Copy(traversal.RoomFlags,state.RoomFlags,state.RoomFlags.Length);Array.Copy(traversal.Path,state.Path,16);
            state.Volumes.AddRange(traversal.Volumes);state.Entries.AddRange(traversal.Entries);
            return true;
        }
    }
}
