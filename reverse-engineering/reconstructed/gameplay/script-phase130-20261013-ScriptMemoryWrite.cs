// Original memory-file writer and explicit corrected release CRT endpoint provenance.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptMemoryWrite
 {
  //4f0380 ignores allocation mode; remaining byte count uses inclusive end.
  //Prepared disjoint or identical source/destination and nonnegative bounded memcpy count.
  public static uint Write(TakeoverReleaseMemory m,uint handle,uint source,uint count){if(handle<0x400||handle>=0x414)throw new ArgumentException("Prepared memory-file handle required.");uint slot=0x2983740+(handle-0x400)*20,cursor=m.Read32(slot+8);int available=unchecked((int)(m.Read32(slot+4)-cursor+1)),requested=unchecked((int)count),copied=available<requested?available:requested;if(copied<0||copied>16384)throw new ArgumentException("Prepared bounded nonnegative copy required.");if(copied!=0){for(uint i=0;i<(uint)copied;i++)m.Write8(unchecked(cursor+i),m.Read8(unchecked(source+i)));m.Write32(slot+8,unchecked(m.Read32(slot+8)+(uint)copied));}return(uint)copied;}
 }
 public static class RecoveredActualReleaseCrtEndpoints
 {
  public static uint Write(uint descriptor,uint source,uint count,uint mode){return 0;} //6dee60, existing116 zero body; corrected role.
  public static uint Seek(uint descriptor,uint low,uint origin,uint mode){return 0;} //6dee90, existing112 zero body; actual publicseek target.
 }
 public sealed class RecoveredActualReleaseCrtSeekServices:ScriptRemainingSeekServices
 {
  readonly ScriptRemainingSeekServices remaining;public RecoveredActualReleaseCrtSeekServices(ScriptRemainingSeekServices r){remaining=r;}
  public override uint CrtSeek(TakeoverReleaseMemory m,uint d,uint low,uint origin,uint mode){return RecoveredActualReleaseCrtEndpoints.Seek(d,low,origin,mode);}
  public override ulong CompressedSeek(TakeoverReleaseMemory m,uint h,uint low,uint hi,uint origin){return remaining.CompressedSeek(m,h,low,hi,origin);}
 }
}
