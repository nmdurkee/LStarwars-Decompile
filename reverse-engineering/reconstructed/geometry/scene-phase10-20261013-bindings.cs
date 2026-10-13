// Original render-target caller's concrete screen/origin writer and service order.
using System;
namespace Recovered.Geometry
{
 public sealed class RenderTargetBindingState
 {
  public int BackendWidth,BackendHeight;
  public uint Flag,Primary,Secondary,Active;
  public int[] Screen,Origin;
 }
 public sealed class RenderTargetSurface
 {
  public uint Handle;
  public ushort Width,Height;
 }
 public sealed class RenderTargetBindingServices
 {
  public Func<uint,uint,uint> Bind;
  public Func<uint,uint,uint> State;
  public Func<RenderTargetBindingState,uint> Refresh;
 }
 public static class RenderTargetDimensionBinding
 {
  static uint Resize(RenderTargetBindingState state,int width,int height,RenderTargetBindingServices services)
  {if(services.Refresh==null)throw new ArgumentException("Explicit context refresh required.");state.Screen[0]=width;state.Origin[0]=width/2;state.Screen[1]=height;state.Origin[1]=height/2;return services.Refresh(state);}
  // Original 0x6e3720, thiscall with surface and raw slot, ret8.
  // Bind/state/refresh are explicit host callees. Fields consumed after those
  // calls are read at that point, preserving allowed callback mutation.
  public static uint Apply(RenderTargetBindingState state,RenderTargetSurface surface,uint slot,RenderTargetBindingServices services)
  {
   if(state==null||state.Screen==null||state.Screen.Length!=2||state.Origin==null||state.Origin.Length!=2||services==null||services.Bind==null)throw new ArgumentException("Resolved backend and binding service required.");
   if(surface!=null&&surface.Handle!=0){uint result=services.Bind(slot,surface.Handle);return slot==0?Resize(state,surface.Width,surface.Height,services):result;}
   if(slot!=0)return services.Bind(slot,0);
   if(state.Flag!=0){services.Bind(0,state.Primary);if(services.State==null)throw new ArgumentException("Explicit render-state service required.");services.State(0xa8,0);state.Active=state.Primary;}
   else{services.Bind(0,state.Secondary);state.Active=state.Secondary;}return Resize(state,state.BackendWidth,state.BackendHeight,services);
  }
 }
}
