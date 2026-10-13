// Original PC secondary box visibility, volume masks and shared cache.
using System;
namespace Recovered.Animation
{
    public sealed class SecondaryVisibilityVolume
    {
        // Native context + volumeIndex*0x380 +0x1a0, four floats per plane;
        // signed plane count at +0x260. Resolved finite planes, count0..12.
        public float[][] Planes;
    }
    public sealed class SecondaryVisibilityContext
    {
        // Original volume count at context+0x710. Mask shifts wrap modulo32.
        public SecondaryVisibilityVolume[] Volumes;
    }
    public sealed class SecondaryVisibilityState
    {
        // Native count966384, pointers96d9d0, masks96e550 and flag9715a0.
        public int Count;
        public SecondaryVisibilityContext[] Contexts;
        public uint[] Masks;
        public uint CacheFlag;
    }
    public static class SecondaryVisibility
    {
        static float Finite(float v)
        {if(Single.IsNaN(v)||Single.IsInfinity(v))throw new ArgumentException("Finite secondary visibility math required.");return v;}
        static float Distance(float x,float y,float z,float[] plane)
        {
            if(plane==null||plane.Length!=4)throw new ArgumentException("Four plane coefficients required.");
            var a=PlaybackWide.Multiply(PlaybackWide.From(Finite(x)),PlaybackWide.From(Finite(plane[0])));
            var b=PlaybackWide.Multiply(PlaybackWide.From(Finite(y)),PlaybackWide.From(Finite(plane[1])));
            var c=PlaybackWide.Multiply(PlaybackWide.From(Finite(z)),PlaybackWide.From(Finite(plane[2])));
            // Two distinct original float stores: dotXYZ, then dotXYZ+D.
            float dot=Finite(PlaybackWide.Add(PlaybackWide.Add(a,b),c).Store());
            return Finite(PlaybackWide.Add(PlaybackWide.From(dot),PlaybackWide.From(Finite(plane[3]))).Store());
        }
        //0x5c6dc0, boolean AL result only. Endpoints need not be ordered.
        public static bool IntersectsVolume(SecondaryVisibilityVolume volume,float[] first,float[] second)
        {
            if(volume==null||volume.Planes==null||volume.Planes.Length>12)throw new ArgumentException("Resolved bounded volume required.");
            if(first==null||second==null||first.Length<3||second.Length<3)throw new ArgumentException("Two three-coordinate endpoints required.");
            foreach(float[] plane in volume.Planes)
            {
                bool accepted=false;
                // Original corners: 000,010,110,100,001,011,111,101.
                for(int i=0;i<8&&!accepted;++i)
                {
                    int q=i&3;float x=(q==2||q==3)?second[0]:first[0];float y=(q==1||q==2)?second[1]:first[1];float z=(i&4)!=0?second[2]:first[2];
                    accepted=Distance(x,y,z,plane)>0;
                }
                if(!accepted)return false;
            }
            return true;
        }
        //0x5c7050. Empty volume list returns0 without reading endpoints.
        public static uint BuildMask(SecondaryVisibilityContext context,float[] first,float[] second)
        {
            if(context==null||context.Volumes==null||context.Volumes.Length>128)throw new ArgumentException("Resolved bounded context required.");
            uint mask=0;for(int i=0;i<context.Volumes.Length;++i)if(IntersectsVolume(context.Volumes[i],first,second))mask|=1u<<(i&31);return mask;
        }
        //0x5ea6a0. Nonzero refresh forces recomputation. A valid cache reads
        // neither context pointers nor endpoint arrays. Native positivity is
        // signed: a mask with bit31 set does not pass the aggregate test.
        public static int Evaluate(SecondaryVisibilityState state,float[] first,float[] second,int refresh)
        {
            if(state==null||state.Count<0||state.Count>128||state.Masks==null||state.Masks.Length<state.Count)throw new ArgumentException("Valid bounded secondary cache required.");
            if(refresh!=0)state.CacheFlag=0;
            else if(state.CacheFlag!=0)
            {for(int i=0;i<state.Count;++i)if(unchecked((int)state.Masks[i])>0)return 1;return 0;}
            if(state.Count>0&&(state.Contexts==null||state.Contexts.Length<state.Count))throw new ArgumentException("Resolved contexts required for recomputation.");
            int result=0;for(int i=0;i<state.Count;++i){uint mask=BuildMask(state.Contexts[i],first,second);state.Masks[i]=mask;if(unchecked((int)mask)>0)result=1;}
            state.CacheFlag=1;return result;
        }
    }
}
