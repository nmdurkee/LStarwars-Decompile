// Original PC room selector0x5d92b0, including observed priority/flag ordering.
// Evidence: geometry-room-selection-native-validation.json. GPU work excluded.
using System;
using System.Collections.Generic;
using Recovered.Animation;

namespace Recovered.Geometry
{
    public sealed class PortalRoom
    {
        public readonly IList<PortalPlane> Planes;
        public readonly IList<short> PortalIndices;
        public readonly byte Priority;
        public readonly uint Flags;
        public PortalRoom(IList<PortalPlane> planes,IList<short> portalIndices,byte priority,uint flags)
        {
            if(planes==null || portalIndices==null) throw new ArgumentNullException();
            if(planes.Count>255 || portalIndices.Count>255) throw new ArgumentException("Native room counts are unsigned bytes.");
            Planes=planes;PortalIndices=portalIndices;Priority=priority;Flags=flags;
        }
    }
    public struct PortalLink
    {
        public PortalPlane Plane;
        public short FrontRoom,BackRoom;
        public PortalLink(PortalPlane plane,short frontRoom,short backRoom)
        {Plane=plane;FrontRoom=frontRoom;BackRoom=backRoom;}
    }
    public static class PortalSelection
    {
        // Native null scene/point yields-1. In the bounded adapter, null rooms
        //represent a null scene. Portal records are only required if a common
        //portal is found. The selected endpoint need not itself be in the
        //candidate pair; the original returns the authored endpoint directly.
        public static short SelectRoom(IList<PortalRoom> rooms,IList<PortalLink> portals,Point3? point)
        {
            if(rooms==null || !point.HasValue) return -1;
            if(rooms.Count>32767) throw new ArgumentException("Native room scan uses a signed16 index.");
            NativeFrustum.CheckPoint(point.Value);
            int first=0,second=0,matches=0;
            for(int index=0;index<rooms.Count;++index)
            {
                PortalRoom room=rooms[index];
                if(room==null) throw new ArgumentException("Null room record.");
                if(!PortalPredicates.ContainsPoint(room.Planes,point.Value)) continue;
                PortalRoom oldFirst=rooms[first],oldSecond=rooms[second];
                if(oldFirst==null || oldSecond==null) throw new ArgumentException("Null room record.");
                // The third match compares the two existing candidates' priorities,
                //not the new room's. Native debug calls on ties/flags are empty.
                if(matches==2)
                {
                    if(oldFirst.Priority<oldSecond.Priority) first=index;
                    else second=index;
                }
                // The original has six local signed16 slots. A seventh stored
                //match overwrites its return address; do not reproduce corruption.
                if(matches==6) throw new ArgumentException("More than six stored overlapping rooms is outside the safe native domain.");
                if(matches==0) first=index;
                else if(matches==1) second=index;
                ++matches;
                // These are the OLD candidates, read before storing this match.
                //On the second match oldSecond is still room0, not the new room.
                if(matches==2 && (oldFirst.Flags&1)==0 && (oldSecond.Flags&1)==0) break;
            }
            if(matches==0) return -1;
            if(matches==1) return (short)first;
            foreach(short a in rooms[first].PortalIndices)
                foreach(short b in rooms[second].PortalIndices)
                    if(a==b)
                    {
                        if(portals==null || a<0 || a>=portals.Count) throw new ArgumentException("Common portal index outside supplied array.");
                        PortalLink portal=portals[a];PortalPlane p=portal.Plane;
                        NativeFrustum.Finite(p.X);NativeFrustum.Finite(p.Y);NativeFrustum.Finite(p.Z);NativeFrustum.Finite(p.W);
                        Point3 q=point.Value;
                        float distance=FiniteX87.Dot3PlusConstant(q.X,q.Y,q.Z,p.X,p.Y,p.Z,p.W);
                        return distance>=0 ? portal.BackRoom : portal.FrontRoom;
                    }
            return -1;
        }
    }
}
