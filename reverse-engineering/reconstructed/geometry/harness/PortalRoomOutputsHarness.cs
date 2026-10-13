using System;
using System.IO;
using Recovered.Geometry;

public static class PortalRoomOutputsHarness
{
    public static void Main(string[] args)
    {
        if(args.Length!=2) throw new ArgumentException("Input fixture and output path required.");
        using(BinaryReader r=new BinaryReader(File.OpenRead(args[0])))
        using(BinaryWriter w=new BinaryWriter(File.Create(args[1])))
        {
            if(new string(r.ReadChars(4))!="PROI") throw new InvalidDataException("PROI header required.");
            int count=r.ReadInt32();w.Write(new byte[]{80,82,79,79});w.Write(count);
            for(int ci=0;ci<count;++ci)
            {
                int roomCount=r.ReadInt32();short root=r.ReadInt16();PortalClipVolume[] volumes=new PortalClipVolume[r.ReadInt32()];
                for(int vi=0;vi<volumes.Length;++vi) volumes[vi]=new PortalClipVolume(new PortalPlane[0],new float[32],new Point3(),new Point3(),r.ReadInt16());
                for(int room=-2;room<=roomCount;++room) w.Write((byte)(PortalRoomOutputs.HasClipForRoom(true,volumes,(short)room)?1:0));
                byte[] mask=new byte[roomCount+16];for(int i=0;i<mask.Length;++i) mask[i]=0xa5;
                PortalRoomOutputs.WriteRoomMask(true,roomCount,root,volumes,mask);w.Write(mask);
            }
            for(int present=0;present<2;++present)
            {
                foreach(short room in new short[]{-32768,-2,-1,0,1,32767}) w.Write((byte)(PortalRoomOutputs.HasClipForRoom(false,null,room)?1:0));
                foreach(byte value in new byte[]{0,0xa5,255})
                {
                    byte[] mask=new byte[16];for(int i=0;i<mask.Length;++i) mask[i]=value;
                    PortalRoomOutputs.WriteRoomMask(false,0,-1,null,mask);w.Write(mask);
                }
            }
            if(r.BaseStream.Position!=r.BaseStream.Length) throw new InvalidDataException("Trailing fixture bytes.");
            Console.WriteLine("Wrote {0} room-output cases.",count);
        }
    }
}
