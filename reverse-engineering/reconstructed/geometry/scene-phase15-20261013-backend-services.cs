// Original CPU sampler cache, device wrappers, vendor lookup and lock dispatch.
using System;
namespace Recovered.Geometry
{
 public sealed class BackendComCall
 {
  public readonly byte[] BackendImage;
  public readonly uint Device,VtableOffset;
  public readonly uint[] Arguments;
  public BackendComCall(byte[] image,uint device,uint offset,uint[] args){BackendImage=image;Device=device;VtableOffset=offset;Arguments=args;}
 }
 public sealed class BackendServiceGlobals
 {
  // Cache image resolves297bea0..297c19f; LastResult is its word0.
  public readonly byte[] CacheImage,MarkerImage;
  public readonly byte[] BackendImage;
  public byte Enabled;
  public BackendServiceGlobals(byte[] backend,byte[] cache,byte[] markers){BackendImage=backend;CacheImage=cache;MarkerImage=markers;}
 }
 public sealed class BackendVendorGlobals
 {
  public uint Vendor,Device,EchoVendor,EchoDevice;
  public readonly byte[] Records;
  public BackendVendorGlobals(byte[] records){Records=records;}
 }
 public static class BackendCpuServices
 {
  static void Range(byte[] b,uint at){if(b==null||b.Length<4||at>(uint)(b.Length-4))throw new ArgumentException("Resolved global/backend image required.");}
  static uint Read(byte[] b,uint at){Range(b,at);int i=(int)at;return(uint)b[i]|(uint)b[i+1]<<8|(uint)b[i+2]<<16|(uint)b[i+3]<<24;}
  static void Write(byte[] b,uint at,uint value){Range(b,at);int i=(int)at;b[i]=(byte)value;b[i+1]=(byte)(value>>8);b[i+2]=(byte)(value>>16);b[i+3]=(byte)(value>>24);}
  static uint Forward(BackendServiceGlobals g,uint offset,uint[] args,bool save,Func<BackendComCall,uint> service){if(g==null||service==null)throw new ArgumentException("Explicit final device COM service required.");uint result=service(new BackendComCall(g.BackendImage,Read(g.BackendImage,4),offset,args));if(save)Write(g.CacheImage,0,result);return result;}
  // Original0x6e54e0. Enabled test precedes unconditional marker invalidation.
  // The type upper bound is SIGNED, with no lower bound. Scaled addresses wrap.
  // Images resolve only bounded cells, including retained negative cache aliases.
  public static uint Sampler(BackendServiceGlobals g,uint stage,int type,uint value,Func<BackendComCall,uint> service)
  {
   if(g==null)throw new ArgumentException("Resolved sampler globals required.");bool enabled=g.Enabled!=0;uint marker=unchecked(0x20u+stage*8u);Write(g.MarkerImage,marker,0xffffffff);Write(g.MarkerImage,unchecked(marker+4u),0xffffffff);
   if(enabled&&stage<8&&type<14&&type!=4){uint at=unchecked(0x34u+(uint)type*4u+stage*56u);if(Read(g.CacheImage,at)==value)return stage;Write(g.CacheImage,at,value);}
   return Forward(g,0x114,new uint[]{stage,unchecked((uint)type),value},true,service);
  }
  static readonly uint[] RenderEnums={168,190,191,192,7,14,23,22,15,27,19,20};
  // Actual6e5340 refinement over the same raw cache image as sampler/vendor.
  public static uint RenderState(BackendServiceGlobals g,uint type,uint value,Func<BackendComCall,uint> service)
  {if(g==null)throw new ArgumentException("Resolved cache globals required.");if(g.Enabled!=0)for(uint i=0;i<RenderEnums.Length;++i)if(type==RenderEnums[i]){uint at=0x1f8+i*4;if(Read(g.CacheImage,at)==value)return i;Write(g.CacheImage,at,value);break;}Write(g.CacheImage,0x1f4,0xffffffff);return Forward(g,0xe4,new uint[]{type,value},true,service);}
  // Actual wrappers preserve opaque COM results. Status uniquely leaves LastResult.
  public static uint Status(BackendServiceGlobals g,Func<BackendComCall,uint> service){return Forward(g,0xc,new uint[0],false,service);}
  public static uint EndScene(BackendServiceGlobals g,Func<BackendComCall,uint> service){return Forward(g,0x14,new uint[0],true,service);}
  public static uint Shader(BackendServiceGlobals g,uint value,Func<BackendComCall,uint> service){return Forward(g,0x134,new uint[]{value},true,service);}
  public static uint Clear(BackendServiceGlobals g,uint[] arguments,Func<BackendComCall,uint> service)
  {if(arguments==null||arguments.Length!=6)throw new ArgumentException("Six clear arguments required.");NativeFrustum.Finite(BitConverter.ToSingle(BitConverter.GetBytes(arguments[4]),0));return Forward(g,0xac,(uint[])arguments.Clone(),true,service);}
  // Original0x6e66b0. The original static table contains267 records then a sentinel.
  // Supplied records resolve8283e8; selected pointer is a raw original address.
  public static uint Vendor(BackendServiceGlobals g,BackendVendorGlobals vendor)
  {
   if(g==null||vendor==null||vendor.Records==null)throw new ArgumentException("Resolved vendor globals/table required.");Write(g.CacheImage,0x2d8,1);vendor.EchoVendor=vendor.Vendor;vendor.EchoDevice=vendor.Device;uint selected=0;
   if(vendor.Vendor==0x10de&&vendor.Device!=0xffffffff){bool ended=false;for(uint at=0;at<vendor.Records.Length;at+=16){uint id=Read(vendor.Records,at);if(id==0xffffffff){ended=true;break;}if(selected!=0){ended=true;break;}if(id==vendor.Device)selected=unchecked(0x8283e8u+at);}if(!ended)throw new ArgumentException("Sentinel/selected vendor record must resolve.");if(selected==0)selected=0x8294a8;}
   Write(g.CacheImage,0x2dc,selected);return 0;
  }
  // Original4ffaa0/4ffac0, called by6df300/6df310 with global297ae20.
  // Invalid index returns the raw index. Real OS lock operations stay explicit.
  public static uint Critical(uint index,bool enter,Func<bool,uint,uint> service)
  {if(unchecked(index-1)>11)return index;if(service==null)throw new ArgumentException("Explicit critical-section service required.");return service(enter,unchecked(0x91ef70u+index*24u));}
 }
}
