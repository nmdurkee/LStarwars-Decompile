// Legacy PC shadow CPU scheduling. Device calls remain explicit services.
using System;
namespace Recovered.Animation
{
    public sealed class LegacyShadowAllocation
    {
        public uint Vertices,GroupStarts,GroupEdgeCounts;
    }
    public sealed class LegacyShadowRenderState
    {
        public uint VolumeShader,OverlayShader,OverlayBuffer;
        public uint[] StencilValues;
        // These are inline words at963f88 and96e568, NOT the arrays addressed
        // by pointers stored there. Native5f9c30 makes that distinction.
        public uint[] InlineStarts,InlineEdgeCounts;
        public Action<uint,uint[]> DeviceCall;
    }
    public static class LegacyShadowFlush
    {
        // PC5e28c0; disjoint caller-owned cursor. Pointer arithmetic wraps.
        public static LegacyShadowAllocation Allocate(ref uint cursor)
        {
            uint start=unchecked(cursor+3)&0xfffffffcu;var result=new LegacyShadowAllocation{Vertices=start,GroupStarts=unchecked(start+0x36b00u),GroupEdgeCounts=unchecked(start+0x372d0u)};cursor=unchecked(start+0x37aa0u);return result;
        }
        static void Call(LegacyShadowRenderState s,uint entry,params uint[] args){if(s==null||s.DeviceCall==null)throw new ArgumentException("Nonmutating device-call service required.");s.DeviceCall(entry,args);}
        static void State(LegacyShadowRenderState s,uint key,uint value){Call(s,0x6e5340,key,value);}
        // PC5f9b20. Values are opaque native device handles/state words.
        public static void Overlay(LegacyShadowRenderState s)
        {
            if(s==null||s.StencilValues==null||s.StencilValues.Length!=3)throw new ArgumentException("Three stencil words required.");
            Call(s,0x6e5700,0);Call(s,0x6e5290,0);State(s,0x1b,1);State(s,0xe,0);State(s,0x89,0);State(s,0x1d,0);Call(s,0x6e5630,0,0);
            Call(s,0x6e5670,0,1,2);Call(s,0x6e5670,0,2,0);Call(s,0x6e5670,0,4,2);Call(s,0x6e5670,0,5,0);Call(s,0x6e5670,1,1,1);Call(s,0x6e5670,1,4,1);
            State(s,0x38,s.StencilValues[0]);State(s,0x37,s.StencilValues[1]);State(s,0x39,s.StencilValues[2]);State(s,7,0);State(s,0x16,1);State(s,0xab,1);State(s,0x13,5);State(s,0x14,6);
            Call(s,0x6e56c0,s.OverlayShader);Call(s,0x6e5590,0,s.OverlayBuffer,0,0x1c);Call(s,0x6e4980,6,0,2);
        }
        // PC5f9c30. Preserve native immediate-address arguments even though
        // the geometry producers dereference pointer slots at those addresses.
        public static void DrawVolumes(LegacyShadowGeometryState geometry,LegacyShadowRenderState s)
        {
            if(geometry==null||s==null)throw new ArgumentNullException();uint vc=geometry.VertexCount,gc=geometry.GroupCount;
            if((vc&3)!=0||vc>14000||gc>250)throw new ArgumentException("Bounded legacy draw counts required.");
            if(gc!=0&&(s.InlineStarts==null||s.InlineEdgeCounts==null||s.InlineStarts.Length<gc||s.InlineEdgeCounts.Length<gc))throw new ArgumentException("Inline native metadata words required.");
            Call(s,0x6e56c0,s.VolumeShader);State(s,0xe,0);State(s,0x1b,1);State(s,0x13,1);State(s,0x14,2);State(s,7,1);State(s,0x36,1);State(s,0x34,1);State(s,0x38,8);State(s,0x37,4);State(s,0x39,1);State(s,0x16,3);
            for(int pass=0;pass<2;++pass)
            {
                if(pass!=0){State(s,0x16,2);State(s,0x37,5);}
                for(uint i=0;i<vc;i+=4)Call(s,0x6e49b0,6,2,unchecked(0x963f94u+i*16),16);
                for(uint i=0;i<gc;++i)Call(s,0x6e49b0,6,unchecked(s.InlineEdgeCounts[i]-2),unchecked(0x963f94u+s.InlineStarts[i]*16),64);
            }
        }
        // PC5f9da0. BuildGeometry may update geometry's counters; all device
        // services are nonmutating. Inactive paths still consume queue.Count.
        public static void Flush(CharacterShadowQueueState queue,LegacyShadowGeometryState geometry,LegacyShadowRenderState s,Action<uint,uint> buildGeometry)
        {
            if(queue==null||geometry==null)throw new ArgumentNullException();
            if(queue.Enabled!=0&&queue.Mode==1&&queue.Count!=0)
            {
                Call(s,0x6e5700,0);Call(s,0x6e5290,0);State(s,15,0);State(s,23,4);Call(s,0x6e5630,0,0);Call(s,0x6df8b0);
                if(buildGeometry==null)throw new ArgumentNullException("buildGeometry");buildGeometry(128,0);DrawVolumes(geometry,s);Overlay(s);
                State(s,7,1);State(s,0x34,0);State(s,14,1);State(s,0x1b,0);State(s,0x16,3);geometry.VertexCount=0;geometry.GroupCount=0;
            }
            queue.Count=0;
        }
    }
}
