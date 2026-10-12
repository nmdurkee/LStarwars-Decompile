// Bounded original PC portal-room visibility consumers.
// Evidence: reports/geometry-portal-visibility-native-validation.json.
// Prepared clipping planes are inputs; this does not construct child volumes.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Geometry
{
    public struct PortalSphere
    {
        public Point3 Center;
        public float Radius;
        public PortalSphere(Point3 center,float radius) {Center=center;Radius=radius;}
    }

    public static class PortalVolumePredicates
    {
        internal static float Distance(PortalPlane p,Point3 v)
        {return FiniteX87.Dot3PlusConstant(v.X,v.Y,v.Z,p.X,p.Y,p.Z,p.W);}
        internal static void CheckPlane(PortalPlane p)
        {NativeFrustum.Finite(p.X);NativeFrustum.Finite(p.Y);NativeFrustum.Finite(p.Z);NativeFrustum.Finite(p.W);}
        internal static void CheckPlanes(IList<PortalPlane> planes)
        {
            if(planes==null) throw new ArgumentNullException("planes");
            if(planes.Count>32767) throw new ArgumentException("Native clipping count is signed16.");
            foreach(PortalPlane plane in planes) CheckPlane(plane);
        }

        // Original0x5d94a0. The separate camera plane is always tested, even
        //when the volume has no planes. Tangency returns2, not fully-inside1.
        public static int ClassifySphere(PortalSphere sphere,IList<PortalPlane> planes,PortalPlane cameraPlane)
        {
            NativeFrustum.CheckPoint(sphere.Center);NativeFrustum.Finite(sphere.Radius);
            if(sphere.Radius<0) throw new ArgumentOutOfRangeException("sphere");
            CheckPlanes(planes);CheckPlane(cameraPlane);bool fullyInside=true;
            for(int i=0;i<=planes.Count;++i)
            {
                float d=Distance(i==planes.Count ? cameraPlane : planes[i],sphere.Center);
                if(d < -sphere.Radius) return 0;
                if(!(sphere.Radius<d)) fullyInside=false;
            }
            return fullyInside ? 1 : 2;
        }

        // Original0x5d9580. Enumerates all eight min/max corners. A corner
        //on a plane is inside.0=reject,1=fully inside,2=partial overlap.
        public static int ClassifyMinMax(Point3 minimum,Point3 maximum,IList<PortalPlane> planes)
        {
            NativeFrustum.CheckPoint(minimum);NativeFrustum.CheckPoint(maximum);CheckPlanes(planes);
            if(minimum.X>maximum.X || minimum.Y>maximum.Y || minimum.Z>maximum.Z)
                throw new ArgumentException("Reversed bounds outside validated domain.");
            bool partial=false;
            foreach(PortalPlane plane in planes)
            {
                int inside=0;
                for(int corner=0;corner<8;++corner)
                {
                    Point3 v=new Point3((corner&1)==0 ? minimum.X : maximum.X,
                        (corner&2)==0 ? minimum.Y : maximum.Y,(corner&4)==0 ? minimum.Z : maximum.Z);
                    if(Distance(plane,v)>=0) ++inside;
                }
                if(inside==0) return 0;
                if(inside!=8) partial=true;
            }
            return partial ? 2 : 1;
        }

        // Original0x5d9770. No extra camera-plane test in this helper.
        //Center and radius projections have separate observed float32 stores.
        public static bool AcceptCenterExtent(Point3 center,Point3 extent,IList<PortalPlane> planes)
        {
            NativeFrustum.CheckPoint(center);NativeFrustum.CheckPoint(extent);CheckPlanes(planes);
            if(extent.X<0 || extent.Y<0 || extent.Z<0) throw new ArgumentOutOfRangeException("extent");
            foreach(PortalPlane plane in planes)
            {
                float radius=FiniteX87.Dot3PlusConstant(extent.X,extent.Y,extent.Z,
                    Math.Abs(plane.X),Math.Abs(plane.Y),Math.Abs(plane.Z),0);
                if(Distance(plane,center)<-radius) return false;
            }
            return true;
        }
    }

    public static class PortalVisibility
    {
        // Original0x280a2f0 is exactly625bytes, independent of scene count.
        public const int ByteCount=625, InstanceLimit=5000;
        private static void CheckBits(byte[] bits)
        {if(bits==null || bits.Length!=ByteCount) throw new ArgumentException("Expected625-byte visibility bitset.");}
        private static void CheckMembers(IList<short> indices,int count)
        {
            if(indices==null) throw new ArgumentNullException("indices");
            if(indices.Count>32767) throw new ArgumentException("Native member count is signed16.");
            foreach(short index in indices)
                if(index<0 || index>=count) throw new ArgumentException("Invalid instance index.");
        }
        private static bool IsSet(byte[] bits,int i) {return (bits[i>>3]&(1<<(i&7)))!=0;}
        private static void Set(byte[] bits,int i) {bits[i>>3]|=(byte)(1<<(i&7));}

        // Original0x600c60/0x600cb0. Caller chooses the branch by whether
        //GSNH+0x110 is nonnull. Legacy storage is flags at+0x44 in80Brecords.
        public static void SetAll(bool enabled,bool hasDisplayScene,byte[] bits,uint[] legacyFlags)
        {
            if(hasDisplayScene)
            {
                CheckBits(bits);byte value=enabled ? (byte)255 : (byte)0;
                for(int i=0;i<ByteCount;++i) bits[i]=value;
            }
            else
            {
                if(legacyFlags==null) throw new ArgumentNullException("legacyFlags");
                for(int i=0;i<legacyFlags.Length;++i)
                    legacyFlags[i]=enabled ? legacyFlags[i]|4u : legacyFlags[i]&~4u;
            }
        }

        // Original0x600be0. Root-room membership is unconditional: flags,
        //overrides and geometric bounds are not consulted.
        public static void MarkUnclipped(IList<short> indices,bool hasDisplayScene,byte[] bits,uint[] legacyFlags)
        {
            if(hasDisplayScene)
            {
                CheckBits(bits);CheckMembers(indices,InstanceLimit);
                foreach(short i in indices) Set(bits,i);
            }
            else
            {
                if(legacyFlags==null) throw new ArgumentNullException("legacyFlags");
                CheckMembers(indices,legacyFlags.Length);
                foreach(short i in indices) legacyFlags[i]|=4u;
            }
        }

        // Original0x600d00, nonnull display scene only. Mode4000 selects
        //center/extent bounds. Without it bounds are min/max plus spheres.
        //An existing bit skips all work; override bits precede the visible
        //flag gate; flag8 skips geometry. Only mode4000 requires flag1.
        public static void MarkClipped(IList<short> indices,byte[] bits,byte[] overrides,
            byte[] instanceFlags,bool mode4000,IList<Point3> firstBounds,IList<Point3> secondBounds,
            IList<PortalSphere> spheres,IList<PortalPlane> planes,PortalPlane cameraPlane)
        {
            CheckBits(bits);CheckBits(overrides);
            if(instanceFlags==null || firstBounds==null || secondBounds==null) throw new ArgumentNullException();
            int count=instanceFlags.Length;
            if(count>InstanceLimit || firstBounds.Count!=count || secondBounds.Count!=count)
                throw new ArgumentException("Invalid parallel instance arrays.");
            if(!mode4000 && (spheres==null || spheres.Count!=count)) throw new ArgumentException("Missing alternate-mode spheres.");
            CheckMembers(indices,count);PortalVolumePredicates.CheckPlanes(planes);PortalVolumePredicates.CheckPlane(cameraPlane);
            foreach(short i in indices)
            {
                if(IsSet(bits,i)) continue;
                bool accept=IsSet(overrides,i);
                if(!accept)
                {
                    byte flags=instanceFlags[i];
                    if(mode4000)
                    {
                        if((flags&1)==0) continue;
                        accept=(flags&8)!=0 || PortalVolumePredicates.AcceptCenterExtent(firstBounds[i],secondBounds[i],planes);
                    }
                    else if((flags&8)!=0) accept=true;
                    else
                    {
                        int sphere=PortalVolumePredicates.ClassifySphere(spheres[i],planes,cameraPlane);
                        accept=sphere==1 || (sphere==2 && PortalVolumePredicates.ClassifyMinMax(firstBounds[i],secondBounds[i],planes)!=0);
                    }
                }
                if(accept) Set(bits,i);
            }
        }
    }
}
