using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
    public static class PathAngles
    {
        //0x5be030. Nonnegative finite X/Z, not both zero; original513-word table.
        public static ushort FirstQuadrant(float x,float z,ushort[] table)
        {
            bool invert=z<x;float numerator=invert?z:x,denominator=invert?x:z;
            int index=PlaybackWide.Divide(PlaybackWide.Multiply(PlaybackWide.From(numerator),PlaybackWide.From(512)),PlaybackWide.From(denominator)).TruncateInt32();
            return (ushort)(invert?16384-table[index]:table[index]);
        }
        //0x5be2d0 returns a signed full-width integer; fourth quadrant is negative.
        public static int Direction(float x,float z,ushort[] table)
        {
            if(x==0)return z<0?32768:0;if(z==0)return x<0?49152:16384;
            int q=FirstQuadrant(Math.Abs(x),Math.Abs(z),table);
            return x<0?(z<0?q+32768:-q):(z<0?32768-q:q);
        }
        //0x5bfe00 explicitly stores the scaled angle to float32 before return.
        public static float Radians(float x,float z,ushort[] table)
        {return PlaybackWide.Multiply(PlaybackWide.From(Direction(x,z,table)),PlaybackWide.FromDouble(9.58738019107841e-05)).Store();}
        //Observed51af40 call composition, not an additional native mapping.
        public static ushort StoredHeading(float x,float z,ushort[] table)
        {return unchecked((ushort)PlaybackWide.Multiply(PlaybackWide.From(Radians(x,z,table)),PlaybackWide.FromDouble(10430.3779296875)).TruncateInt32());}
    }
}
