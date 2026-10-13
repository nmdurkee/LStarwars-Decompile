// Actual two-slot player queries used by original shadow selection596a30.
using System;
namespace Recovered.Geometry
{
    public static class ShadowPlayers
    {
        static float Finite(float v){if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite player aggregate required.");return v;}
        static float F(RenderPacketMemory m,uint p){return Finite(BitConverter.ToSingle(BitConverter.GetBytes(m.Dword(p)),0));}
        static void Slots(RenderPacketMemory m,uint[] players){if(m==null||players==null||players.Length!=2)throw new ArgumentException("Exactly two resolved player slots required.");}
        static bool Active(RenderPacketMemory m,uint actor){return actor!=0&&(m.Byte(checked(actor+0x1fc))&0x80)!=0;}
        //0x55e340, null auxiliary branch used by596a30. No active actor leaves
        // output untouched. Optional541bc0 collision query is outside this helper.
        public static bool AveragePosition(RenderPacketMemory m,uint[] players,float[] output)
        {
            Slots(m,players);var value=new float[3];int count=0;foreach(uint actor in players)if(Active(m,actor)){for(int j=0;j<3;++j)value[j]=Finite((float)((double)value[j]+F(m,checked(actor+0x5c+(uint)j*4))));++count;}
            if(count==0)return false;if(output==null||output.Length<3)throw new ArgumentException("Complete output required for active players.");float reciprocal=(float)(1.0/count);for(int j=0;j<3;++j)output[j]=Finite((float)((double)value[j]*reciprocal));return true;
        }
        //0x5967b0: original output registerEDI, strength pointer stackarg1.
        // Seed adapts global95e5c8. It is added before active-count division.
        public static int AverageDirection(RenderPacketMemory m,uint[] players,float[] seed,float[] output,out float strength)
        {
            Slots(m,players);if(seed==null||seed.Length<3||output==null||output.Length<3)throw new ArgumentException("Complete seed and output required.");var value=new float[3];for(int j=0;j<3;++j)value[j]=Finite(seed[j]);strength=-1;int count=0;
            foreach(uint actor in players)if(Active(m,actor)){for(int j=0;j<3;++j)value[j]=Finite((float)((double)value[j]+F(m,checked(actor+0x5fc+(uint)j*4))));float candidate=F(m,checked(actor+0x608));if(strength<=candidate)strength=candidate;++count;}
            if(count>0){float reciprocal=(float)(1.0/count);for(int j=0;j<3;++j)value[j]=Finite((float)((double)value[j]*reciprocal));}Array.Copy(value,output,3);return count;
        }
    }
}
