// Original PC room-output consumers; separate from recursive traversal core.
// Evidence: geometry-portal-room-outputs-native-validation.json.
using System;
using System.Collections.Generic;

namespace Recovered.Geometry
{
    public static class PortalRoomOutputs
    {
        // Original0x5da2d0. Scene null or no authored portals defaults true.
        //Only allocated clip room IDs are searched; root is not added here.
        public static bool HasClipForRoom(bool hasPortalScene,IList<PortalClipVolume> volumes,short room)
        {
            if(!hasPortalScene) return true;
            CheckVolumes(volumes);
            foreach(PortalClipVolume v in volumes) if(v.Room==room) return true;
            return false;
        }
        // Original0x5da330. Disabled/null scene leaves the caller's bytes alone.
        //Otherwise clears exactly roomCount bytes,adds root,then nonnegative
        //allocated clip room IDs. Bytes beyond roomCount remain untouched.
        public static void WriteRoomMask(bool hasPortalScene,int roomCount,short root,IList<PortalClipVolume> volumes,byte[] output)
        {
            if(!hasPortalScene) return;
            CheckVolumes(volumes);
            if(output==null || roomCount<1 || roomCount>32767 || output.Length<roomCount || root<0 || root>=roomCount) throw new ArgumentException("Valid successful-entry room state required.");
            foreach(PortalClipVolume v in volumes) if(v.Room>=roomCount) throw new ArgumentException("Invalid clip room ID.");
            for(int i=0;i<roomCount;++i) output[i]=0;
            output[root]=1;
            foreach(PortalClipVolume v in volumes) if(v.Room>=0) output[v.Room]=1;
        }
        private static void CheckVolumes(IList<PortalClipVolume> volumes)
        {
            if(volumes==null || volumes.Count>16) throw new ArgumentException("Invalid original clip-header list.");
            foreach(PortalClipVolume v in volumes) if(v==null) throw new ArgumentException("Null clip header.");
        }
    }
}
