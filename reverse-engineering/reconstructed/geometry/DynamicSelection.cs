// Pure LOD/material-selection branches extracted from original5f0f00.
// This is not a complete dynamic scene submission implementation.
// Native evidence: geometry-dynamic-selection-native-validation.json.
using System;
using System.Collections.Generic;
namespace Recovered.Geometry
{
    public static class DynamicSelection
    {
        // Native consumes a float32 squared distance after a negative clamp.
        // Zero forced LOD uses strict distance<threshold; any other signed
        // value walks toward that index until a zero terminator is reached.
        public static int SelectLod(float[] thresholds,float distanceSquared,int forcedLod)
        {
            if(thresholds==null || thresholds.Length==0 || thresholds.Length>1000000 || Single.IsNaN(distanceSquared) || Single.IsInfinity(distanceSquared) || distanceSquared<0)throw new ArgumentException("Finite bounded LOD array and nonnegative distance required.");
            foreach(float value in thresholds)if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentException("Finite LOD thresholds required.");
            int index=0;if(thresholds[0]==0)return 0;
            if(forcedLod==0)
            {
                while(distanceSquared<thresholds[index]){if(++index>=thresholds.Length)throw new ArgumentException("Unterminated LOD walk.");}
            }
            else
            {
                while(thresholds[index]!=0 && index!=forcedLod){if(++index>=thresholds.Length)throw new ArgumentException("Unterminated forced LOD walk.");}
            }
            return index;
        }
        // Native material+9a tag; +1f0 layout identifier. A present table and
        // nonzero tag suppress the global fallback even when that entry is0.
        // Layout mismatch delegates to original5e5020's unresolved clone/cache
        // behavior; this callback is an explicit boundary, not its replacement.
        public static uint ChooseMaterial(RenderPacketMemory m,uint source,uint globalOverride,uint overrideTable,Func<uint,uint,uint> merge)
        {
            byte tag=m.Byte(source+0x9a);uint replacement;
            if(overrideTable==0 || tag==0)replacement=globalOverride;
            else replacement=m.Dword(overrideTable+(uint)tag*4);
            if(replacement==0)return source;
            if(m.Dword(source+0x1f0)==m.Dword(replacement+0x1f0))return replacement;
            if(merge==null)throw new NotSupportedException("Material clone/cache callback required for layout mismatch.");return merge(source,replacement);
        }
        // Preserve linked material order. Mode1 permits A==255 or all three
        // raw gate bytes zero; every other mode permits A!=255.
        public static IList<uint> FilterChain(RenderPacketMemory m,uint first,int mode)
        {
            List<uint> output=new List<uint>();HashSet<uint> visited=new HashSet<uint>();uint current=first;
            while(current!=0)
            {
                if(visited.Count>=1000000 || !visited.Add(current))throw new ArgumentException("Finite acyclic material chain required.");
                byte a=m.Byte(current+248),b=m.Byte(current+249),c=m.Byte(current+250);
                if(mode==1?(a==255 || a+b+c==0):a!=255)output.Add(current);current=m.Dword(current+0x30);
            }
            return output;
        }
    }
}
