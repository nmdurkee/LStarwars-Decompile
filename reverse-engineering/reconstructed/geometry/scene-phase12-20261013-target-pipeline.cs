// One original backend image for target cache, dimension caller and viewport refresh.
using System;
namespace Recovered.Geometry
{
 public sealed class RenderStateCacheGlobals
 {
  public byte Enabled;
  public uint[] Values=new uint[12];
  public uint Marker,LastResult;
 }
 public sealed class RenderStateComCall
 {
  public readonly byte[] BackendImage;
  public readonly uint Device,Index,Value;
  public RenderStateComCall(byte[] backend,uint device,uint index,uint value){BackendImage=backend;Device=device;Index=index;Value=value;}
 }
 public static class RenderStateCacheProduction
 {
  static readonly uint[] Enums={168,190,191,192,7,14,23,22,15,27,19,20};
  // Original0x6e5340. Cache index derives from the original selector/jump tables.
  // A hit returns that index. Misses publish cache/marker before COM and store
  // its opaque HRESULT afterwards, without rollback on failure.
  public static uint Apply(byte[] backend,RenderStateCacheGlobals state,uint index,uint value,Func<RenderStateComCall,uint> setState)
  {
   if(state==null||state.Values==null||state.Values.Length!=12)throw new ArgumentException("Resolved render-state globals required.");
   if(state.Enabled!=0)for(int i=0;i<Enums.Length;++i)if(index==Enums[i]){if(state.Values[i]==value)return(uint)i;state.Values[i]=value;break;}
   if(setState==null)throw new ArgumentException("Explicit render-state COM required.");
   uint device=RenderTargetPipeline.Read(backend,4);state.Marker=0xffffffff;uint result=setState(new RenderStateComCall(backend,device,index,value));state.LastResult=result;return result;
  }
 }
 public sealed class RenderTargetPipelineRuntime
 {
  public readonly byte[] BackendImage;
  public readonly RenderTargetCacheState TargetCache;
  public readonly RenderStateCacheGlobals RenderStates;
  public readonly ViewportSetterRuntime Viewport;
  public readonly ViewportCpuState ViewportBackend;
  public RenderTargetPipelineRuntime(byte[] backend,int configuration,RenderStateCacheGlobals states,ViewportSetterRuntime viewport)
  {BackendImage=backend;TargetCache=new RenderTargetCacheState{Image=backend,Configuration=configuration};RenderStates=states;Viewport=viewport;ViewportBackend=new ViewportCpuState(backend,viewport.Input.Screen);}
 }
 public sealed class RenderTargetPipelineServices
 {
  public Func<uint,uint,uint,uint> Target;
  public Func<RenderStateComCall,uint> State;
  public Func<ViewportComCall,uint> Viewport;
 }
 public static class RenderTargetPipeline
 {
  static void Range(byte[] image,uint offset,int count){if(image==null||image.Length<count||offset>(uint)(image.Length-count))throw new ArgumentException("Resolved backend/surface byte image required.");}
  internal static uint Read(byte[] image,uint offset){Range(image,offset,4);int i=(int)offset;return(uint)image[i]|(uint)image[i+1]<<8|(uint)image[i+2]<<16|(uint)image[i+3]<<24;}
  static ushort Short(byte[] image,uint offset){Range(image,offset,2);int i=(int)offset;return(ushort)(image[i]|image[i+1]<<8);}
  static void Write(byte[] image,uint offset,uint value){Range(image,offset,4);int i=(int)offset;image[i]=(byte)value;image[i+1]=(byte)(value>>8);image[i+2]=(byte)(value>>16);image[i+3]=(byte)(value>>24);}
  static uint Resize(RenderTargetPipelineRuntime runtime,int width,int height,RenderTargetPipelineServices services)
  {runtime.Viewport.Input.Screen[0]=width;runtime.Viewport.Origin[0]=width/2;runtime.Viewport.Input.Screen[1]=height;runtime.Viewport.Origin[1]=height/2;return ContextViewportRefresh.Refresh(runtime.BackendImage,runtime.ViewportBackend,runtime.Viewport,services.Viewport);}
  // Original0x6e3720 with actual0x6e2880/0x6e5340/0x6e2510 CPU callees.
  // The caller and fixed global backend0x29765c8 are the SAME resolved image.
  // Surface offsets8/14/16 are read at their actual pre/post-service points.
  public static uint Apply(RenderTargetPipelineRuntime runtime,byte[] surface,uint slot,RenderTargetPipelineServices services)
  {
   if(runtime==null||services==null||!Object.ReferenceEquals(runtime.TargetCache.Image,runtime.BackendImage)||!Object.ReferenceEquals(runtime.ViewportBackend.Screen,runtime.Viewport.Input.Screen))throw new ArgumentException("One stable backend image and screen globals required.");
   uint handle=surface==null?0:Read(surface,8);
   if(handle!=0){uint result=RenderTargetCacheProduction.Apply(runtime.TargetCache,slot,handle,services.Target);return slot==0?Resize(runtime,Short(surface,0x14),Short(surface,0x16),services):result;}
   if(slot!=0)return RenderTargetCacheProduction.Apply(runtime.TargetCache,slot,0,services.Target);
   if(Read(runtime.BackendImage,0x638)!=0){RenderTargetCacheProduction.Apply(runtime.TargetCache,0,Read(runtime.BackendImage,0x6b0),services.Target);RenderStateCacheProduction.Apply(runtime.BackendImage,runtime.RenderStates,168,0,services.State);Write(runtime.BackendImage,0x6e8,Read(runtime.BackendImage,0x6b0));}
   else{RenderTargetCacheProduction.Apply(runtime.TargetCache,0,Read(runtime.BackendImage,0x6c4),services.Target);Write(runtime.BackendImage,0x6e8,Read(runtime.BackendImage,0x6c4));}
   return Resize(runtime,unchecked((int)Read(runtime.BackendImage,0x138)),unchecked((int)Read(runtime.BackendImage,0x13c)),services);
  }
 }
}
