// Supporting composition: no new native address credit. Connects recovered
// clone/cache, successful pool constructor and CPU material refresh. Shader
// factory and declaration creation remain explicit external services.
using System;
namespace Recovered.Geometry
{
    public sealed class MaterialLifecycleState
    {
        public uint Cache,CurrentThread,MaterialTypeWord;
        public MaterialPoolState Pool;
        public MaterialRefreshServices Refresh;
    }
    public static class MaterialLifecycle
    {
        public static uint Merge(RenderPacketMemory memory,MaterialLifecycleState state,uint source,uint replacement)
        {
            if(memory==null||state==null||state.Pool==null||state.Refresh==null)throw new ArgumentNullException();
            MaterialCloneServices services=new MaterialCloneServices();services.CurrentThread=state.CurrentThread;services.MaterialTypeWord=state.MaterialTypeWord;
            services.AllocateMaterial=delegate(uint type){return MaterialPool.Allocate(memory,state.Pool,1,type,1);};
            services.ResolveDeclaration=state.Refresh.ResolveDeclaration;
            services.RefreshMaterial=delegate(RenderPacketMemory m,uint material){MaterialRefresh.Refresh(m,material,state.Refresh);};
            return MaterialCloneCache.Merge(memory,state.Cache,source,replacement,services);
        }
    }
}
