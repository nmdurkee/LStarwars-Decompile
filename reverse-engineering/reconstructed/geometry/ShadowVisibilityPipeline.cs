// Supporting composition of recovered original producers and consumers.
// This adapter adds no native entry-point credit and is not a full-frame loop.
using System;
using Recovered.Animation;
namespace Recovered.Geometry
{
    public static class ShadowVisibilityPipeline
    {
        static float F(RenderPacketMemory m,uint p){return BitConverter.ToSingle(BitConverter.GetBytes(m.Dword(p)),0);}
        // Context enabled/registered state is input; original registration decides
        // acceptance. Existing resource pointers and unrelated bytes are retained.
        public static void Prepare(RenderPacketMemory m,ShadowContextRegistryState registry,uint context,uint camera,uint cuts,int cutCount,float[] eye,float[] target,float[] up,float[] extents,float[] sineTable,float[] projection,float[] view)
        {
            ShadowLight.ConfigureView(m,context,eye,target,up);ShadowLight.ConfigureOrthographic(m,context,extents);ShadowExtraction.Extract(m,context,camera,cuts,cutCount,sineTable,projection,view);ShadowContextRegistry.Register(m,registry,context);
        }
        // Reads actual produced plane records, preserving shared cache semantics.
        // A valid unrefreshed cache avoids all endpoint/context memory reads.
        public static int Evaluate(RenderPacketMemory m,ShadowContextRegistryState registry,float[] first,float[] second,int refresh)
        {
            if(registry==null||registry.Count<0||registry.Count>4||registry.Masks==null||registry.Masks.Length<4)throw new ArgumentException("Four-slot registry required.");var state=new SecondaryVisibilityState{Count=registry.Count,CacheFlag=registry.CacheFlag,Masks=registry.Masks};
            if(refresh!=0||registry.CacheFlag==0)
            {
                state.Contexts=new SecondaryVisibilityContext[registry.Count];for(int i=0;i<registry.Count;++i)
                {
                    uint context=ShadowContextRegistry.GetContext(registry,i);int count=unchecked((int)m.Dword(checked(context+0x710)));if(count>2)throw new ArgumentException("Produced context has at most two active volumes.");var volumes=new SecondaryVisibilityVolume[Math.Max(0,count)];
                    for(int vi=0;vi<volumes.Length;++vi)
                    {
                        uint volume=checked(context+(uint)vi*0x380);int planeCount=unchecked((int)m.Dword(checked(volume+0x260)));if(planeCount<0||planeCount>12)throw new ArgumentException("Bounded finite plane table required.");var planes=new float[planeCount][];for(int p=0;p<planeCount;++p){planes[p]=new float[4];for(int j=0;j<4;++j)planes[p][j]=F(m,checked(volume+0x1a0+(uint)p*16+(uint)j*4));}volumes[vi]=new SecondaryVisibilityVolume{Planes=planes};
                    }
                    state.Contexts[i]=new SecondaryVisibilityContext{Volumes=volumes};
                }
            }
            int result=SecondaryVisibility.Evaluate(state,first,second,refresh);registry.CacheFlag=state.CacheFlag;return result;
        }
    }
}
