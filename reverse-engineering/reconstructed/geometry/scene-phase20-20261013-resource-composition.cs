// Same backend/pool composition: no intermediate texture allocation/free graph adapter.
using System;
namespace Recovered.Geometry
{
 public static class RendererResourceComposition
 {
  public static RendererResourceServices Bind(TextureAllocationState s,RendererResourceServices finalServices)
  {
   if(s==null||finalServices==null||finalServices.Call==null)throw new ArgumentException("Shared renderer/ownership state and final services required.");
   RendererResourceServices bound=new RendererResourceServices();bound.ResolveBuffer=finalServices.ResolveBuffer;
   bound.Call=delegate(RendererResourceCall call)
   {
    if(call.Kind=="texture-free"){uint owner=call.Arguments[0];return TextureOwnerCpu.Free(s.Ownership,owner,owner,delegate(uint token){return finalServices.Call(new RendererResourceCall("object",token,8,new uint[0],null));});}
    if(call.Kind=="texture-create")return TextureAllocationCpu.CreateDefault(s,finalServices,call.Arguments[0],call.Arguments[1]);
    if(call.Kind=="texture-format")return TextureAllocationCpu.CreateFormat(s,finalServices,call.Arguments[0],call.Arguments[1],call.Arguments[2]);
    return finalServices.Call(call);
   };return bound;
  }
  // Actual6e2d20 caller with original feature, buffer and texture ownership CPU.
  public static uint Build(TextureAllocationState s,RendererResourceServices finalServices){return RendererResourceProduction.Apply(s.Resource,Bind(s,finalServices));}
  // Actual6e2170 CPU release with original5f7b40 pool/accounting CPU.
  public static uint Release(TextureAllocationState s,RendererResourceServices finalServices){return RendererResourceRelease.Apply(s.Resource.Bootstrap.Pipeline.BackendImage,Bind(s,finalServices));}
 }
}
