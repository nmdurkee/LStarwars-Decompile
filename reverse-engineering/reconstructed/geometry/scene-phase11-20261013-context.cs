// Original integer render-target cache caller and explicit COM edge.
using System;
namespace Recovered.Geometry
{
 public sealed class RenderTargetCacheState
 {
  public byte[] Image;
  public int Configuration;
 }
 public static class RenderTargetCacheProduction
 {
  static void Range(byte[] image,uint offset,int count){if(image==null||image.Length<count||offset>(uint)(image.Length-count))throw new ArgumentException("Resolved backend byte image required.");}
  static uint Read(byte[] image,uint offset){Range(image,offset,4);int at=(int)offset;return(uint)(image[at]|image[at+1]<<8|image[at+2]<<16|image[at+3]<<24);}
  static ushort Short(byte[] image,uint offset){Range(image,offset,2);int at=(int)offset;return(ushort)(image[at]|image[at+1]<<8);}
  static void Write(byte[] image,uint offset,uint value){Range(image,offset,4);int at=(int)offset;image[at]=(byte)value;image[at+1]=(byte)(value>>8);image[at+2]=(byte)(value>>16);image[at+3]=(byte)(value>>24);}
  // Original 0x6e2880, thiscall backend, raw slot/handle, ret8.
  // Signed upper bound and wrapping32-bit scaled address are intentional.
  // Changed targets are cached BEFORE the COM call. HRESULT never causes a
  // rollback, and the device token is read after that cache write.
  public static uint Apply(RenderTargetCacheState state,uint slot,uint handle,Func<uint,uint,uint,uint> setTarget)
  {
   if(state==null)throw new ArgumentNullException("state");int maximum=(Read(state.Image,0x638)==0&&state.Configuration>=2?Short(state.Image,0xf8):1)-1;if(unchecked((int)slot)>maximum)return slot;uint offset=unchecked(0x6f0u+slot*4u);if(Read(state.Image,offset)==handle)return slot;Write(state.Image,offset,handle);if(setTarget==null)throw new ArgumentException("Explicit COM target service required.");return setTarget(Read(state.Image,4),slot,handle);
  }
 }
}
