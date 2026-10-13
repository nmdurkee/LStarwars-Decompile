// Actual target/depth reset consumers ending in recovered context refresh.
using System;
namespace Recovered.Geometry
{
 public sealed class RenderTargetResetCapabilities
 {
  public byte FirstEnabled,SecondEnabled;
  public uint FirstMode,SecondMode;
 }
 public sealed class RenderTargetResetServices
 {
  public Func<uint,uint,uint,uint> Target;
  public Func<uint,uint,uint> Depth;
  public Func<ViewportComCall,uint> Viewport;
 }
 public static class RenderTargetResetProduction
 {
  static uint Read(byte[] image,int offset){if(image==null||offset<0||offset>image.Length-4)throw new ArgumentException("Resolved backend image required.");return(uint)image[offset]|(uint)image[offset+1]<<8|(uint)image[offset+2]<<16|(uint)image[offset+3]<<24;}
  static void Write(byte[] image,int offset,uint word){if(image==null||offset<0||offset>image.Length-4)throw new ArgumentException("Resolved backend image required.");image[offset]=(byte)word;image[offset+1]=(byte)(word>>8);image[offset+2]=(byte)(word>>16);image[offset+3]=(byte)(word>>24);}
  static int Maximum(RenderTargetPipelineRuntime runtime){byte[] b=runtime.BackendImage;return(Read(b,0x638)==0&&runtime.TargetCache.Configuration>=2?(b[0xf8]|b[0xf9]<<8):1)-1;}
  static void Validate(RenderTargetPipelineRuntime runtime,RenderTargetResetServices services){if(runtime==null||services==null||services.Depth==null||!Object.ReferenceEquals(runtime.BackendImage,runtime.TargetCache.Image)||!Object.ReferenceEquals(runtime.ViewportBackend.Screen,runtime.Viewport.Input.Screen))throw new ArgumentException("One stable backend image, shared screen globals and explicit final COM services required.");}
  static uint Finish(RenderTargetPipelineRuntime runtime,RenderTargetResetServices services){byte[] b=runtime.BackendImage;services.Depth(Read(b,4),Read(b,0x6ec));int width=unchecked((int)Read(b,0x138)),height=unchecked((int)Read(b,0x13c));runtime.Viewport.Input.Screen[0]=width;runtime.Viewport.Origin[0]=width/2;runtime.Viewport.Input.Screen[1]=height;runtime.Viewport.Origin[1]=height/2;return ContextViewportRefresh.Refresh(b,runtime.ViewportBackend,runtime.Viewport,services.Viewport);}
  // Original0x6e33a0. The initial flag branch stays selected across callbacks.
  // Cache/capability/handle reads within that branch occur at their actual points.
  public static uint Restore(RenderTargetPipelineRuntime runtime,RenderTargetResetCapabilities capabilities,RenderTargetResetServices services)
  {
   Validate(runtime,services);if(capabilities==null)throw new ArgumentException("Resolved capability globals required.");byte[] b=runtime.BackendImage;
   if(Read(b,0x638)!=0){RenderTargetCacheProduction.Apply(runtime.TargetCache,0,Read(b,0x6b0),services.Target);Write(b,0x6e8,Read(b,0x6b0));}
   else for(uint slot=0;slot<4;++slot){if(slot==0){bool secondary=Read(b,0x6c4)!=0;int offset=secondary?0x6c4:0x6b0;RenderTargetCacheProduction.Apply(runtime.TargetCache,0,Read(b,offset),services.Target);Write(b,0x6e8,Read(b,offset));}else{bool multi=slot<=2&&((capabilities.FirstEnabled!=0&&capabilities.FirstMode==2)||(capabilities.SecondEnabled!=0&&capabilities.SecondMode==2));RenderTargetCacheProduction.Apply(runtime.TargetCache,slot,multi?Read(b,0x6c4+(int)slot*4):0,services.Target);}}
   return Finish(runtime,services);
  }
  // Original0x6e3650. Extra cache cells are cleared before their direct COM
  // calls. Limit is recomputed per slot; failures/mutations are not rolled back.
  public static uint ClearAdditional(RenderTargetPipelineRuntime runtime,RenderTargetResetServices services)
  {
   Validate(runtime,services);byte[] b=runtime.BackendImage;RenderTargetCacheProduction.Apply(runtime.TargetCache,0,Read(b,0x6b0),services.Target);Write(b,0x6e8,Read(b,0x6b0));
   for(uint slot=1;slot<4;++slot){int offset=0x6f0+(int)slot*4;if((int)slot<=Maximum(runtime)&&Read(b,offset)!=0){Write(b,offset,0);if(services.Target==null)throw new ArgumentException("Explicit target COM required.");services.Target(Read(b,4),slot,0);}}
   return Finish(runtime,services);
  }
 }
}
