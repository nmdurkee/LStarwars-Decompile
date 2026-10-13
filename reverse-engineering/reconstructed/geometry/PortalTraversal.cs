// Original PC portal runtime, with explicit camera state and bounded storage.
// Native/Python evidence: geometry-portal-runtime-native-validation.json.
// Compiled C# execution remains pending; no original GPU behavior is claimed.
using System;
using System.Collections.Generic;
using Recovered.Animation;
using Wide=Recovered.Animation.PlaybackWide;

namespace Recovered.Geometry
{
    public sealed class PortalCamera
    {
        public readonly float[] World,Projection;
        public readonly float FieldOfView,Aspect;
        public readonly PortalPlane CameraPlane;
        public readonly NativeSineTable Sine;
        public Point3 Position {get{return new Point3(World[12],World[13],World[14]);}}
        public PortalCamera(float[] world,float[] projection,float fieldOfView,float aspect,PortalPlane cameraPlane,NativeSineTable sine)
        {
            if(world==null || projection==null || world.Length!=16 || projection.Length!=16 || sine==null) throw new ArgumentException("Prepared camera matrices and original sine table required.");
            foreach(float v in world) NativeFrustum.Finite(v);
            foreach(float v in projection) NativeFrustum.Finite(v);
            NativeFrustum.Finite(fieldOfView);NativeFrustum.Finite(aspect);PortalVolumePredicates.CheckPlane(cameraPlane);
            if(aspect==0) throw new ArgumentException("Zero aspect outside finite domain.");
            World=(float[])world.Clone();Projection=(float[])projection.Clone();FieldOfView=fieldOfView;Aspect=aspect;CameraPlane=cameraPlane;Sine=sine;
        }
    }

    public static class PortalProjection
    {
        private static Wide Dot(Point3 v,float a,float b,float c,float d)
        {
            Wide xy=Wide.Add(Wide.Multiply(Wide.From(v.X),Wide.From(a)),Wide.Multiply(Wide.From(v.Y),Wide.From(b)));
            return Wide.Add(Wide.Add(xy,Wide.Multiply(Wide.From(v.Z),Wide.From(c))),Wide.From(d));
        }
        private static float Finite(float value) {NativeFrustum.Finite(value);return value;}
        private static float Divide(float a,float b) {return Finite(Wide.Divide(Wide.From(a),Wide.From(b)).Store());}
        private static float Clamp(float value) {return Math.Min(1,Math.Max(-1,value));}

        // Original0x5d9f50 bounding/projection result. The native function also
        //updates an inverse-matrix cache; this portable result does not do so.
        //Each reciprocal is storedfloat32 before multiplying an unrounded dot.
        public static void Bounds(IList<Point3> vertices,float[] matrix,out Point3 minimum,out Point3 maximum)
        {
            if(vertices==null || vertices.Count<1 || vertices.Count>32767 || matrix==null || matrix.Length!=16) throw new ArgumentException("Invalid prepared projection data.");
            foreach(float v in matrix) NativeFrustum.Finite(v);
            minimum=new Point3();maximum=new Point3();
            for(int i=0;i<vertices.Count;++i)
            {
                Point3 v=vertices[i];NativeFrustum.CheckPoint(v);
                float w=Finite(Dot(v,matrix[3],matrix[7],matrix[11],matrix[15]).Store());
                float reciprocal=w==0 ? 0 : Divide(1,w);float[] p=new float[3];
                for(int k=0;k<3;++k) p[k]=Finite(Wide.Multiply(Dot(v,matrix[k],matrix[4+k],matrix[8+k],matrix[12+k]),Wide.From(reciprocal)).Store());
                if(i==0) {minimum=new Point3(p[0],p[1],p[2]);maximum=minimum;}
                else
                {
                    minimum=new Point3(Math.Min(minimum.X,p[0]),Math.Min(minimum.Y,p[1]),Math.Min(minimum.Z,p[2]));
                    maximum=new Point3(Math.Max(maximum.X,p[0]),Math.Max(maximum.Y,p[1]),Math.Max(maximum.Z,p[2]));
                }
            }
            minimum=new Point3(Clamp(minimum.X),Clamp(minimum.Y),Clamp(minimum.Z));maximum=new Point3(Clamp(maximum.X),Clamp(maximum.Y),Clamp(maximum.Z));
        }

        // Original0x5d9a00 FOV-derived child planes. Half-FOV storesfloat32;
        //the original double scale is exactly10430.3779296875. Native converts
        //toInt64, then uses low32 bits; this adapter admits signed32 phases only.
        public static PortalClipVolume FromRectangle(Point3 minimum,Point3 maximum,short room,PortalCamera camera)
        {
            if(camera==null) throw new ArgumentNullException("camera");
            NativeFrustum.CheckPoint(minimum);NativeFrustum.CheckPoint(maximum);
            float half=(float)((double)camera.FieldOfView*.5);
            int index=Wide.Multiply(Wide.From(half),Wide.FromDouble(10430.3779296875)).TruncateInt32();
            float tangent=Divide(camera.Sine[(index>>1)&32767],camera.Sine[(unchecked(index+0x4000)>>1)&32767]);
            float horizontal=Divide(tangent,camera.Aspect);
            float[] slopes={(float)((double)maximum.X*horizontal),(float)((double)minimum.X*horizontal),(float)((double)minimum.Y*tangent),(float)((double)maximum.Y*tangent)};
            float[] normalizers=new float[4];
            for(int i=0;i<4;++i)
            {
                float slope=Finite(slopes[i]);
                float squared=Finite(Wide.Add(Wide.Multiply(Wide.From(slope),Wide.From(slope)),Wide.From(1)).Store());
                normalizers[i]=Divide(1,(float)Math.Sqrt(squared));
            }
            Point3[] local={new Point3(-normalizers[0],0,(float)((double)slopes[0]*normalizers[0])),new Point3(normalizers[1],0,(float)(-(double)slopes[1]*normalizers[1])),new Point3(0,normalizers[2],(float)(-(double)slopes[2]*normalizers[2])),new Point3(0,-normalizers[3],(float)((double)slopes[3]*normalizers[3]))};
            PortalPlane[] planes=new PortalPlane[4];float[] m=camera.World;
            for(int i=0;i<4;++i)
            {
                Point3 v=local[i];Point3 normal=new Point3(Dot(v,m[0],m[4],m[8],0).Store(),Dot(v,m[1],m[5],m[9],0).Store(),Dot(v,m[2],m[6],m[10],0).Store());
                NativeFrustum.CheckPoint(normal);float constant=Finite(-Dot(camera.Position,normal.X,normal.Y,normal.Z,0).Store());planes[i]=new PortalPlane(normal.X,normal.Y,normal.Z,constant);
            }
            return new PortalClipVolume(planes,PortalVolumes.Pack(planes,camera.CameraPlane),minimum,maximum,room);
        }
    }

    public sealed class RuntimePortal
    {
        public Point3[] Vertices;
        public PortalPlane Plane;
        public short FrontRoom,BackRoom;
        public uint ActiveFlags;
    }
    public sealed class RuntimePortalRoom
    {
        public short[] Instances,Portals;
        public byte Priority;
    }
    public sealed class PortalRuntimeScene
    {
        public RuntimePortalRoom[] Rooms;
        public RuntimePortal[] Portals;
        public Point3[] Centers,Extents;
        public byte[] InstanceFlags,OverrideBits;
    }
    public struct PortalVisit
    {
        public short Current,Previous;
        public int Depth;
        public PortalVisit(short current,short previous,int depth) {Current=current;Previous=previous;Depth=depth;}
    }
    public sealed class PortalTraversalState
    {
        public readonly byte[] VisibilityBits;
        public readonly uint[] RoomFlags;
        public readonly short[] Path;
        public readonly List<PortalClipVolume> Volumes=new List<PortalClipVolume>();
        public readonly List<PortalVisit> Entries=new List<PortalVisit>();
        public PortalTraversalState(byte[] visibilityBits,uint[] roomFlags,short[] path,PortalClipVolume initial)
        {
            if(visibilityBits==null || visibilityBits.Length!=625 || roomFlags==null || path==null || path.Length!=16 || initial==null) throw new ArgumentException("Invalid bounded traversal state.");
            VisibilityBits=(byte[])visibilityBits.Clone();RoomFlags=(uint[])roomFlags.Clone();Path=(short[])path.Clone();Volumes.Add(initial);
        }
    }
    public static class PortalTraversal
    {
        // Original0x5ee750.0reject,1new rectangular volume,4camera-plane straddle.
        //The caller keeps/copies its current planes on4. On0/4 no output is made.
        public static int Partial(RuntimePortal portal,PortalClipVolume parent,short target,PortalCamera camera,out PortalClipVolume child)
        {
            if(portal==null || portal.Vertices==null || parent==null || camera==null) throw new ArgumentNullException();
            if(portal.Vertices.Length>32767) throw new ArgumentException("Signed16 portal count exceeded.");
            child=null;int positive=0;
            foreach(Point3 v in portal.Vertices) {NativeFrustum.CheckPoint(v);if(PortalVolumePredicates.Distance(camera.CameraPlane,v)>0) ++positive;}
            if(positive==0) return 0;
            if(positive!=portal.Vertices.Length) return 4;
            Point3 minimum,maximum;PortalProjection.Bounds(portal.Vertices,camera.Projection,out minimum,out maximum);
            if(!PortalVolumes.IntersectXY(parent.ScreenMinimum,parent.ScreenMaximum,minimum,maximum,ref minimum,ref maximum)) return 0;
            child=PortalProjection.FromRectangle(minimum,maximum,target,camera);return 1;
        }

        // Original0x5ee940, authored modern-display branch. Caller supplies the
        //root room, initial volume and already initialized bits/room flags/path.
        //The original header stores16 clip pointers; a17th corrupts adjacent
        //state. This bounded projection throws before that allocation. Debug
        //render calls are omitted only under the verified disabled-debug mode.
        public static void Traverse(PortalRuntimeScene scene,PortalCamera camera,short root,int depthLimit,PortalTraversalState state)
        {
            if(scene==null || camera==null || state==null || scene.Rooms==null || scene.Portals==null || scene.InstanceFlags==null || scene.OverrideBits==null || scene.Centers==null || scene.Extents==null) throw new ArgumentNullException();
            if(scene.Rooms.Length>32767 || state.RoomFlags.Length!=scene.Rooms.Length || root<0 || root>=scene.Rooms.Length || scene.InstanceFlags.Length>5000 || scene.Centers.Length!=scene.InstanceFlags.Length || scene.Extents.Length!=scene.InstanceFlags.Length || scene.OverrideBits.Length!=625) throw new ArgumentException("Invalid scene arrays.");
            byte[] priorities=new byte[scene.Rooms.Length];
            for(int ri=0;ri<scene.Rooms.Length;++ri)
            {
                RuntimePortalRoom r=scene.Rooms[ri];
                if(r==null || r.Instances==null || r.Portals==null || r.Instances.Length>32767 || r.Portals.Length>255) throw new ArgumentException("Invalid room arrays.");
                priorities[ri]=r.Priority;
                foreach(short i in r.Instances) if(i<0 || i>=scene.InstanceFlags.Length) throw new ArgumentException("Invalid instance ID.");
                foreach(short i in r.Portals)
                {
                    if(i<0 || i>=scene.Portals.Length) throw new ArgumentException("Invalid portal ID.");
                    RuntimePortal p=scene.Portals[i];
                    if(p==null || p.Vertices==null || p.Vertices.Length<3 || p.Vertices.Length>32767 || p.FrontRoom<0 || p.BackRoom<0 || p.FrontRoom>=scene.Rooms.Length || p.BackRoom>=scene.Rooms.Length || (p.FrontRoom!=ri && p.BackRoom!=ri)) throw new ArgumentException("Invalid portal endpoint or winding.");
                }
            }
            Walk(scene,camera,root,root,-1,0,depthLimit,state,state.Volumes[0],priorities);
        }
        private static PortalClipVolume Add(PortalTraversalState state,PortalClipVolume child)
        {if(state.Volumes.Count>=16) throw new ArgumentException("Original clip pointer list capacity exceeded.");state.Volumes.Add(child);return child;}
        private static void Walk(PortalRuntimeScene scene,PortalCamera camera,short root,short current,short previous,int depth,int depthLimit,PortalTraversalState state,PortalClipVolume clip,byte[] priorities)
        {
            state.Entries.Add(new PortalVisit(current,previous,depth));
            for(int i=0;i<depth-1;++i) if(state.Path[i]==current) return;
            if(depth>=16) return;
            state.Path[depth]=current;RuntimePortalRoom room=scene.Rooms[current];
            if(current==root) PortalVisibility.MarkUnclipped(room.Instances,true,state.VisibilityBits,null);
            else PortalVisibility.MarkClipped(room.Instances,state.VisibilityBits,scene.OverrideBits,scene.InstanceFlags,true,scene.Centers,scene.Extents,null,clip.Planes,camera.CameraPlane);
            state.RoomFlags[current]|=4;
            if(depth>=depthLimit) return;
            foreach(short pi in room.Portals)
            {
                RuntimePortal portal=scene.Portals[pi];short target=portal.FrontRoom==current ? portal.BackRoom : portal.FrontRoom;
                if(target==previous || (portal.ActiveFlags&1)==0) continue;
                int result=PortalPredicates.ClassifyPortal(portal.Vertices,portal.Plane,portal.FrontRoom,portal.BackRoom,current,priorities,camera.Position,clip.Planes);
                if(result==1)
                {
                    Point3 minimum,maximum;PortalProjection.Bounds(portal.Vertices,camera.Projection,out minimum,out maximum);
                    PortalClipVolume child=PortalVolumes.FromPortalEdges(portal.Vertices,portal.Plane,camera.Position,camera.CameraPlane,minimum,maximum,target);
                    Walk(scene,camera,root,target,current,depth+1,depthLimit,state,Add(state,child),priorities);
                }
                else if(result==2)
                {
                    PortalClipVolume child;result=Partial(portal,clip,target,camera,out child);
                    if(result==1) Walk(scene,camera,root,target,current,depth+1,depthLimit,state,Add(state,child),priorities);
                    else if(result==4)
                    {child=clip.ShallowCopy();child.Room=target;Walk(scene,camera,root,target,current,depth+1,depthLimit,state,Add(state,child),priorities);}
                }
                else if(result!=0) Walk(scene,camera,root,target,current,depth+1,depthLimit,state,clip,priorities);
            }
        }
    }
}
