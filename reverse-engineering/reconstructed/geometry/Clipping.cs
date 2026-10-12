// Original PC CPU predicates, reconstructed with explicit prepared camera state.
// Evidence: reports/geometry-clipping-native-validation.json.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Geometry
{
    public sealed class NativeFrustum
    {
        private readonly float[] outer, scissor, nearFar, absOuter, absScissor;
        private readonly float globalFar;
        private NativeFrustum(float[] a,float[] b,float[] nf,float[] aa,float[] ab,float far)
        { outer=a; scissor=b; nearFar=nf; absOuter=aa; absScissor=ab; globalFar=far; }

        // Adapter for the contiguous original0x963fa0..0x9640ef global block.
        // The predicate consumes already prepared world-space clipping planes.
        // This is not a replacement for the complete native camera producer.
        public static NativeFrustum DecodeNativePlaneBlock(byte[] block,float cameraFar)
        {
            if(block==null || block.Length!=336) throw new ArgumentException("Expected336-byte prepared plane block.");
            Finite(cameraFar);
            return new NativeFrustum(Matrix(block,0),Matrix(block,64),Matrix(block,128),Matrix(block,208),Matrix(block,272),cameraFar);
        }
        private static float[] Matrix(byte[] b,int offset)
        {
            float[] result=new float[16];
            for(int i=0;i<16;++i) {result[i]=UvMaterial.ReadFloat32(b,offset+i*4);Finite(result[i]);}
            return result;
        }
        // Original0x5d69a0.0=outside,1=accepted without side clipping,
        //2=accepted and requires side clipping. Near/far overlap alone does
        //not return2. Tangency to outer planes is accepted.
        public int Classify(Point3 center,Point3 extent,float farOverride)
        {
            CheckPoint(center); CheckPoint(extent); Finite(farOverride);
            if(extent.X<0 || extent.Y<0 || extent.Z<0) throw new ArgumentOutOfRangeException("extent");
            float farConstant=nearFar[12];
            if(farOverride!=0)
            {
                // Native stores subtraction to float32 before adding override.
                float withoutFar=(float)((double)farConstant-globalFar);
                farConstant=(float)((double)farOverride+withoutFar);
            }
            float[] distance=new float[6],radius=new float[6];
            for(int i=0;i<4;++i)
            {
                distance[i]=Project(outer,center,i,outer[12+i]);
                radius[i]=Project(absOuter,extent,i,i<3 ? absOuter[12+i] : 0);
            }
            distance[4]=Project(nearFar,center,0,farConstant);
            distance[5]=Project(nearFar,center,1,nearFar[13]);
            radius[4]=Project(nearFar,extent,2,0);
            radius[5]=Project(nearFar,extent,3,0);
            for(int i=0;i<6;++i) if(distance[i]<-radius[i]) return 0;
            bool sideOverlap=false;
            for(int i=0;i<4;++i) if(distance[i]<radius[i]) sideOverlap=true;
            if(sideOverlap)
                for(int i=0;i<4;++i)
                    if(Project(scissor,center,i,scissor[12+i])<Project(absScissor,extent,i,absScissor[12+i])) return 2;
            return 1;
        }
        // Shared software x87 arithmetic preserves64-bit significand rounding
        //before the observed float32 store. Compiled validation remains pending.
        private static float Project(float[] matrix,Point3 p,int column,float translation)
        { return FiniteX87.Dot3PlusConstant(p.X,p.Y,p.Z,matrix[column],matrix[4+column],matrix[8+column],translation); }
        internal static void Finite(float value)
        { if(Single.IsNaN(value)||Single.IsInfinity(value)) throw new ArgumentException("Nonfinite value outside validated domain."); }
        internal static void CheckPoint(Point3 p) {Finite(p.X);Finite(p.Y);Finite(p.Z);}
    }
    public struct PortalPlane
    {
        public float X,Y,Z,W;
        public PortalPlane(float x,float y,float z,float w) {X=x;Y=y;Z=z;W=w;}
    }
    public static class PortalPredicates
    {
        // Original0x5d9220. A room's outward-facing planes require every
        //dot(normal,point)+constant <=0. An empty plane list accepts any point.
        //This does not perform room-priority selection or portal traversal.
        public static bool ContainsPoint(IList<PortalPlane> planes,Point3 point)
        {
            if(planes==null) throw new ArgumentNullException("planes");
            if(planes.Count>255) throw new ArgumentException("Native room plane count is an unsigned byte.");
            NativeFrustum.CheckPoint(point);
            foreach(PortalPlane p in planes)
            {
                NativeFrustum.Finite(p.X);NativeFrustum.Finite(p.Y);NativeFrustum.Finite(p.Z);NativeFrustum.Finite(p.W);
                float distance=Distance(p,point);
                if(distance>0) return false;
            }
            return true;
        }
        private static float Distance(PortalPlane plane,Point3 point)
        { return FiniteX87.Dot3PlusConstant(point.X,point.Y,point.Z,plane.X,plane.Y,plane.Z,plane.W); }

        // Original0x5d9ce0 within its recursive-traversal caller contract:
        //currentRoom must be one endpoint; target is the opposite endpoint.
        //Room priorities come from the shared room array, including self-links.
        //0=reject,1=fully inside,2=partly clipped. Active-portal bit is checked
        //by the caller, not this predicate. Clip planes use positive-inside.
        public static int ClassifyPortal(IList<Point3> vertices,PortalPlane portalPlane,
            short frontRoom,short backRoom,short currentRoom,IList<byte> roomPriorities,
            Point3 camera,IList<PortalPlane> clipPlanes)
        {
            if(vertices==null || roomPriorities==null || clipPlanes==null) throw new ArgumentNullException();
            if(vertices.Count>32767 || clipPlanes.Count>32767) throw new ArgumentException("Signed16 native counts exceeded.");
            if(frontRoom<0 || backRoom<0 || frontRoom>=roomPriorities.Count || backRoom>=roomPriorities.Count)
                throw new ArgumentOutOfRangeException("Room endpoint outside priority array.");
            if(currentRoom!=frontRoom && currentRoom!=backRoom) throw new ArgumentException("Current room must be a portal endpoint.");
            NativeFrustum.CheckPoint(camera);CheckPlane(portalPlane);
            foreach(Point3 vertex in vertices) NativeFrustum.CheckPoint(vertex);
            foreach(PortalPlane plane in clipPlanes) CheckPlane(plane);
            short targetRoom=currentRoom==frontRoom ? backRoom : frontRoom;
            if(roomPriorities[currentRoom]<roomPriorities[targetRoom])
            {
                float cameraDistance=Distance(portalPlane,camera);
                if((backRoom==currentRoom && cameraDistance<0) || (frontRoom==currentRoom && cameraDistance>0)) return 0;
            }
            bool partial=false;
            foreach(PortalPlane plane in clipPlanes)
            {
                int outside=0;
                foreach(Point3 vertex in vertices) if(Distance(plane,vertex)<0) ++outside;
                if(outside==vertices.Count) return 0;
                if(outside!=0) partial=true;
            }
            return partial ? 2 : 1;
        }
        private static void CheckPlane(PortalPlane plane)
        {NativeFrustum.Finite(plane.X);NativeFrustum.Finite(plane.Y);NativeFrustum.Finite(plane.Z);NativeFrustum.Finite(plane.W);}
    }
}
