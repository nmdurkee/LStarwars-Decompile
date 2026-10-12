// Original PC child-volume CPU contracts. Evidence:
// reports/geometry-portal-volume-native-validation.json.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Geometry
{
    public sealed class PortalClipVolume
    {
        // Native header+0x80 points to shared plane storage. Shallow copies
        //retain this identity; PackedPlanes are the copied header's own bytes.
        public readonly PortalPlane[] Planes;
        public readonly float[] PackedPlanes;
        public Point3 ScreenMinimum,ScreenMaximum;
        public short Room;
        public PortalClipVolume(PortalPlane[] planes,float[] packed,Point3 minimum,Point3 maximum,short room)
        {
            if(planes==null || packed==null || packed.Length!=32) throw new ArgumentException("Invalid volume arrays.");
            if(planes.Length>32767) throw new ArgumentException("Signed16 native plane count exceeded.");
            Planes=planes;PackedPlanes=packed;ScreenMinimum=minimum;ScreenMaximum=maximum;Room=room;
        }

        // Original0x5d91b0. It allocates a new160-byte header and plane reserve,
        //then copies the old header over the new pointer. Its subsequent plane
        //copy aliases the source. Portable allocation omits unused arena bytes.
        public PortalClipVolume ShallowCopy()
        {return new PortalClipVolume(Planes,(float[])PackedPlanes.Clone(),ScreenMinimum,ScreenMaximum,Room);}
    }

    public static class PortalVolumes
    {
        // Original0x5d9850. First three planes are unconditionally read by the
        //native helper, hence the lower bound. It packs at most eight planes;
        //unused columns repeat the separate camera plane.
        public static float[] Pack(IList<PortalPlane> planes,PortalPlane cameraPlane)
        {
            PortalVolumePredicates.CheckPlanes(planes);PortalVolumePredicates.CheckPlane(cameraPlane);
            if(planes.Count<3) throw new ArgumentException("Native packer requires at least three valid planes.");
            float[] packed=new float[32];
            for(int i=0;i<8;++i)
            {
                PortalPlane p=i<planes.Count ? planes[i] : cameraPlane;
                int offset=(i/4)*16+i%4;
                packed[offset]=p.X;packed[offset+4]=p.Y;packed[offset+8]=p.Z;packed[offset+12]=p.W;
            }
            return packed;
        }

        // Plane-building component of original0x5da100. Screen bounds are
        //supplied by the caller: original5d9f50 projection/cache is not ported.
        //Camera-at-vertex/degenerate edges produce zero normals, as native does.
        //Native-vs-Python numerical equality is verified; compiled C# execution
        //is pending. Exact signed-zero bits are not claimed by that model.
        public static PortalClipVolume FromPortalEdges(IList<Point3> vertices,PortalPlane portalPlane,
            Point3 camera,PortalPlane cameraPlane,Point3 screenMinimum,Point3 screenMaximum,short room)
        {
            if(vertices==null || vertices.Count<3 || vertices.Count>32767) throw new ArgumentException("Invalid winding count.");
            NativeFrustum.CheckPoint(camera);NativeFrustum.CheckPoint(screenMinimum);NativeFrustum.CheckPoint(screenMaximum);
            PortalVolumePredicates.CheckPlane(portalPlane);PortalVolumePredicates.CheckPlane(cameraPlane);
            foreach(Point3 vertex in vertices) NativeFrustum.CheckPoint(vertex);
            bool flip=PortalVolumePredicates.Distance(portalPlane,camera)>=0;
            PortalPlane[] planes=new PortalPlane[vertices.Count];
            for(int i=0;i<vertices.Count;++i)
            {
                Point3 a=Subtract(camera,vertices[i]),b=Subtract(camera,vertices[(i+1)%vertices.Count]);
                Point3 cross=new Point3(
                    FiniteX87.Dot3PlusConstant(a.Y,a.Z,0,b.Z,-b.Y,0,0),
                    FiniteX87.Dot3PlusConstant(a.Z,a.X,0,b.X,-b.Z,0,0),
                    FiniteX87.Dot3PlusConstant(a.X,a.Y,0,b.Y,-b.X,0,0));
                NativeFrustum.CheckPoint(cross);
                float squared=FiniteX87.Dot3PlusConstant(cross.X,cross.Y,cross.Z,cross.X,cross.Y,cross.Z,0);
                NativeFrustum.Finite(squared);
                // Original5c0240 explicitly stores sqrt tofloat32; the reciprocal
                //and each component multiplication also have float32 stores.
                float length=(float)Math.Sqrt(squared);
                float reciprocal=length>0 ? (float)(1.0/(double)length) : 0;
                NativeFrustum.Finite(reciprocal);
                Point3 normal=new Point3((float)((double)cross.X*reciprocal),
                    (float)((double)cross.Y*reciprocal),(float)((double)cross.Z*reciprocal));
                float constant=FiniteX87.Dot3PlusConstant(camera.X,camera.Y,camera.Z,normal.X,normal.Y,normal.Z,0);
                NativeFrustum.Finite(constant);
                planes[i]=flip ? new PortalPlane(-normal.X,-normal.Y,-normal.Z,constant)
                    : new PortalPlane(normal.X,normal.Y,normal.Z,-constant);
            }
            return new PortalClipVolume(planes,Pack(planes,cameraPlane),screenMinimum,screenMaximum,room);
        }
        private static Point3 Subtract(Point3 a,Point3 b)
        {
            Point3 v=new Point3((float)((double)a.X-b.X),(float)((double)a.Y-b.Y),(float)((double)a.Z-b.Z));
            NativeFrustum.CheckPoint(v);return v;
        }

        // Original0x5da040, custom-register inputs decoded into explicit bounds.
        //Strict inequalities reject touching rectangles. It writes only XY and
        //preserves output Z and every output component on rejection. Native does
        //not independently validate min<=max; reversed finite bounds are retained.
        public static bool IntersectXY(Point3 minimumA,Point3 maximumA,Point3 minimumB,Point3 maximumB,
            ref Point3 outputMinimum,ref Point3 outputMaximum)
        {
            NativeFrustum.CheckPoint(minimumA);NativeFrustum.CheckPoint(maximumA);
            NativeFrustum.CheckPoint(minimumB);NativeFrustum.CheckPoint(maximumB);
            if(!(minimumA.X<maximumB.X) || !(minimumA.Y<maximumB.Y)
                || !(minimumB.X<maximumA.X) || !(minimumB.Y<maximumA.Y)) return false;
            outputMinimum.X=minimumB.X<=minimumA.X ? minimumA.X : minimumB.X;
            outputMinimum.Y=minimumB.Y<=minimumA.Y ? minimumA.Y : minimumB.Y;
            outputMaximum.X=maximumA.X<=maximumB.X ? maximumA.X : maximumB.X;
            outputMaximum.Y=maximumB.Y<maximumA.Y ? maximumB.Y : maximumA.Y;
            return true;
        }
    }
}
