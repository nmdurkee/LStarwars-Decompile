// CPU release ownership and texture/stream cache wrappers from original x86.
using System;
namespace Recovered.Geometry
{
 public static class RendererResourceRelease
 {
  static uint Read(byte[] b,uint o){if(b==null||b.Length<4||o>(uint)(b.Length-4))throw new ArgumentException("Resolved backend/cache image required.");int p=(int)o;return(uint)b[p]|(uint)b[p+1]<<8|(uint)b[p+2]<<16|(uint)b[p+3]<<24;}
  static void Write(byte[] b,uint o,uint v){Read(b,o);int p=(int)o;b[p]=(byte)v;b[p+1]=(byte)(v>>8);b[p+2]=(byte)(v>>16);b[p+3]=(byte)(v>>24);}
  // Original6e45a0, fixed global backend resolved by the supplied image.
  public static uint DeviceMissing(byte[] backend){return Read(backend,4)==0?1u:0u;}
  // Original6e5630. Cache hit leaves EAX unchanged: caller must supply it.
  public static uint Texture(BackendServiceGlobals g,uint stage,uint texture,uint incomingEax,Func<BackendComCall,uint> com)
  {
   if(g==null)throw new ArgumentException("Resolved backend/cache globals required.");bool enabled=g.Enabled!=0;
   if(enabled&&stage<5){uint at=0x20+stage*4;if(Read(g.CacheImage,at)==texture)return incomingEax;Write(g.CacheImage,at,texture);}
   if(com==null)throw new ArgumentException("Final texture COM required.");uint result=com(new BackendComCall(g.BackendImage,Read(g.BackendImage,4),0x104,new uint[]{stage,texture}));Write(g.CacheImage,0,result);return result;
  }
  // Original6e5590 uses one four-word cache, including stream number.
  public static uint Stream(BackendServiceGlobals g,uint stream,uint buffer,uint offset,uint stride,uint incomingEax,Func<BackendComCall,uint> com)
  {
   if(g==null)throw new ArgumentException("Resolved backend/cache globals required.");bool enabled=g.Enabled!=0;
   if(enabled){if(Read(g.CacheImage,0x10)==buffer&&Read(g.CacheImage,0x14)==stride&&Read(g.CacheImage,0x18)==stream&&Read(g.CacheImage,0x1c)==offset)return incomingEax;Write(g.CacheImage,0x10,buffer);Write(g.CacheImage,0x18,stream);Write(g.CacheImage,0x14,stride);Write(g.CacheImage,0x1c,offset);}
   if(com==null)throw new ArgumentException("Final stream COM required.");uint result=com(new BackendComCall(g.BackendImage,Read(g.BackendImage,4),0x190,new uint[]{stream,buffer,offset,stride}));Write(g.CacheImage,0,result);return result;
  }
  static uint Call(RendererResourceServices services,string kind,uint token,uint off,uint[] args){if(services==null||services.Call==null)throw new ArgumentException("Explicit ownership service required.");return services.Call(new RendererResourceCall(kind,token,off,args,null));}
  static void Release(byte[] b,RendererResourceServices services,uint at){uint token=Read(b,at);if(token!=0){Call(services,"object",token,8,new uint[0]);Write(b,at,0);}}
  // Whole6e2170. Free graph5f7b40 stays explicit; ownership/cache clears are CPU.
  public static uint Apply(byte[] backend,RendererResourceServices services)
  {
   foreach(uint at in new uint[]{0x6b0,0x6ec,0x690,0x694,0x698,0x688})Release(backend,services,at);uint result=0;
   for(uint i=0;i<4;++i){Release(backend,services,0x6c4+i*4);result=Call(services,"texture-free",0,0,new uint[]{Read(backend,0x6b4+i*4)});Write(backend,0x6b4+i*4,0);Write(backend,0x6f0+i*4,0);}return result;
  }
 }
}
