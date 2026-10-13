// Bounded PC grid visibility projection. Evidence: scene-visibility-20261013-native-validation.json.
using System;
using Recovered.Animation;
namespace Recovered.Geometry
{
    public sealed class VisibilityGrid
    {
        public int Width, StorageMode, DecodedByteCount;
        public float MinimumX, MaximumX, MinimumZ, MaximumZ, ScaleX, ScaleZ;
        // Resolved pointers at native grid+0x2c; null entries remain null.
        public byte[][] Cells;
    }
    public sealed class VisibilityGridCache
    {
        // Native global0x80b9e4 has no grid-identity component.
        public int LastCell=-1;
        //625 is this projection's tested bound, not a recovered native capacity.
        public readonly byte[] Scratch=new byte[625];
    }
    public sealed class VisibilityGridContext
    {
        public byte[] InstanceTreeBits;
        public bool GridActive;
    }
    public static class GridVisibility
    {
        private static void Finite(float value)
        {if(float.IsNaN(value)||float.IsInfinity(value))throw new ArgumentException("Finite grid inputs required.");}
        // Original0x5d6f00: argument is a stack float32, absent from pseudocode.
        public static int Floor(float value)
        {
            Finite(value);double f=Math.Floor((double)value);
            if(f<int.MinValue||f>int.MaxValue)throw new ArgumentOutOfRangeException("value");
            return (int)f;
        }
        private static float Coordinate(float value,float minimum,float scale)
        {
            return PlaybackWide.Multiply(PlaybackWide.Add(PlaybackWide.From(value),PlaybackWide.From(-minimum)),PlaybackWide.From(scale)).Store();
        }
        // Original0x5d6f30 decoder loop. Exact-length valid streams only; native
        //overshoot/truncation/unterminated input has unsafe memory behavior.
        public static byte[] Decode(byte[] encoded,int length)
        {
            if(encoded==null)throw new ArgumentNullException("encoded");
            if(length<0||length>625)throw new ArgumentOutOfRangeException("length");
            byte[] result=new byte[length];int input=0,output=0;
            while(output<length)
            {
                if(input>=encoded.Length)throw new ArgumentException("Truncated grid stream.");
                byte header=encoded[input++];int count=header>>2,tag=header&3;
                if(count>length-output)throw new ArgumentException("Grid run exceeds declared output.");
                if(tag<2)
                {byte value=tag==0?(byte)0:(byte)255;for(int j=0;j<count;++j)result[output+j]=value;}
                else
                {
                    if(count>encoded.Length-input)throw new ArgumentException("Truncated grid literal.");
                    Array.Copy(encoded,input,result,output,count);input+=count;
                }
                output+=count;
            }
            return result;
        }
        // Original0x5d6f30. Outside bounds returns with both context pointer and
        //global active state untouched. Raw mask selection aliases the cell;
        //compressed selection always aliases shared scratch, including hits.
        public static void Produce(VisibilityGrid grid,float cameraX,float cameraZ,VisibilityGridCache cache,VisibilityGridContext context)
        {
            if(grid==null||cache==null||context==null)throw new ArgumentNullException();
            Finite(cameraX);Finite(cameraZ);Finite(grid.MinimumX);Finite(grid.MaximumX);Finite(grid.MinimumZ);Finite(grid.MaximumZ);Finite(grid.ScaleX);Finite(grid.ScaleZ);
            if(grid.Width<=0||grid.MinimumX>grid.MaximumX||grid.MinimumZ>grid.MaximumZ||grid.ScaleX<0||grid.ScaleZ<0||grid.Cells==null)throw new ArgumentException("Invalid grid projection.");
            if(cameraX<grid.MinimumX||cameraX>grid.MaximumX||cameraZ<grid.MinimumZ||cameraZ>grid.MaximumZ)return;
            int z=Floor(Coordinate(cameraZ,grid.MinimumZ,grid.ScaleZ)),x=Floor(Coordinate(cameraX,grid.MinimumX,grid.ScaleX));
            long wide=(long)z*grid.Width+x;
            if(x<0||z<0||wide<0||wide>=grid.Cells.Length||wide>int.MaxValue)throw new ArgumentException("Native cell lookup outside resolved table.");
            int cell=(int)wide;byte[] data=grid.Cells[cell];context.InstanceTreeBits=data;context.GridActive=data!=null;
            if(grid.StorageMode!=1||data==null)return;
            context.InstanceTreeBits=cache.Scratch;
            if(cell==cache.LastCell)return;
            byte[] decoded=Decode(data,grid.DecodedByteCount);
            cache.LastCell=cell;Array.Copy(decoded,cache.Scratch,decoded.Length);
        }
    }
}
