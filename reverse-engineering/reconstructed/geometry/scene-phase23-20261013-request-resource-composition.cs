// Actual device request/bootstrap/resource CPU sharing backend and texture owner images.
using System;
namespace Recovered.Geometry
{
 public static class DeviceRequestResourceComposition
 {
  public static uint Apply(TextureAllocationState s,uint width,uint height,uint refresh,uint windowMode,uint moveWindow,uint callerStack,Func<DeviceBootstrapCall,uint> finalServices,Func<uint,RawViewportView> resolveBuffer)
  {
   if(s==null||finalServices==null||resolveBuffer==null)throw new ArgumentException("Shared renderer ownership and final service/buffer lifetimes required.");
   RendererResourceServices resourceServices=new RendererResourceServices();resourceServices.ResolveBuffer=resolveBuffer;
   resourceServices.Call=delegate(RendererResourceCall call){return finalServices(new DeviceBootstrapCall(call.Kind,call.Receiver,call.Offset,call.Arguments,call.Output,null));};
   Func<DeviceBootstrapCall,uint> bootstrapServices=delegate(DeviceBootstrapCall call)
   {
    if(call.Kind=="resources"){
     // Original bootstrap subESP8 plus four saved registers, then CALL6e2d20.
     // Preserve exact nested output pointer diagnostics; no managed stack claim.
     s.Resource.CallerStack=unchecked(s.Resource.Bootstrap.CallerStack-28);
     return RendererResourceComposition.Build(s,resourceServices);
    }
    return finalServices(call);
   };
   return DeviceRequestCaller.Apply(s.Resource.Bootstrap,width,height,refresh,windowMode,moveWindow,callerStack,bootstrapServices);
  }
 }
}
