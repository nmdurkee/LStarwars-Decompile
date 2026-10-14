// Actual release CRT file endpoint leaves: no input reads, no I/O, zero EAX.
namespace Recovered.Gameplay
{
 public static class RecoveredReleaseCrtFiles
 {
  public static uint Open(uint first,uint second,uint path,uint mode,uint reserved){return 0;} //6dee30
  public static uint Size(uint descriptor){return 0;} //6dee40
  public static uint Read(uint descriptor,uint destination,uint count,uint mode){return 0;} //6dee50
  public static uint Seek(uint descriptor,uint low,uint origin,uint mode){return 0;} //6dee60
 }
 public sealed class RecoveredReleaseCrtSizeServices:ScriptFileSizeServices
 {public override uint CrtSize(TakeoverReleaseMemory m,uint d){return RecoveredReleaseCrtFiles.Size(d);}}
 public sealed class RecoveredReleaseCrtReadServices:ScriptRemainingReadServices
 {
  readonly ScriptRemainingReadServices remaining;public RecoveredReleaseCrtReadServices(ScriptRemainingReadServices r){remaining=r;}
  public override uint CrtRead(TakeoverReleaseMemory m,uint d,uint p,uint c,uint mode){return RecoveredReleaseCrtFiles.Read(d,p,c,mode);}
  public override uint CompressedRead(TakeoverReleaseMemory m,uint h,uint p,uint c){return remaining.CompressedRead(m,h,p,c);}
 }
 public sealed class RecoveredReleaseCrtSeekServices:ScriptRemainingSeekServices
 {
  readonly ScriptRemainingSeekServices remaining;public RecoveredReleaseCrtSeekServices(ScriptRemainingSeekServices r){remaining=r;}
  public override uint CrtSeek(TakeoverReleaseMemory m,uint d,uint l,uint o,uint mode){return RecoveredReleaseCrtFiles.Seek(d,l,o,mode);}
  public override ulong CompressedSeek(TakeoverReleaseMemory m,uint h,uint l,uint hi,uint o){return remaining.CompressedSeek(m,h,l,hi,o);}
 }
}
