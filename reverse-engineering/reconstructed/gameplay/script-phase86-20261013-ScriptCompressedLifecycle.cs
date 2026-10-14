// Compressed record seeking through recovered public/memory seek, and direct record release.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptCompressedLifecycle
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(p+4)<<32);}
  //4f0ae0 cdecl(handle,offsetLow,offsetHigh,origin); original caller may replace high with sign(low).
  public static ulong Seek(TakeoverReleaseMemory m,ScriptHostFileServices host,ScriptRemainingSeekServices remaining,uint handle,uint low,uint high,uint origin)
  {
   uint record=unchecked(0x297dc60+(handle-0x800)*48),parent=unchecked(m.Read32(record)+((m.Read32(record+0x20)+3)<<4));ulong offset=low|((ulong)high<<32),target;
   if(origin==1)target=unchecked(Quad(m,record+0x10)+offset);else if(origin==2)target=unchecked(Quad(m,record+8)+(ulong)(long)(int)m.Read32(record+0x18)-offset);else target=unchecked(Quad(m,record+8)+offset);
   ulong value=PreparedScriptSeekDispatch.Seek(m,host,remaining,m.Read32(parent),(uint)target,(uint)(target>>32),0);
   m.Write32(record+0x14,(uint)(value>>32));m.Write32(record+0x10,(uint)value);m.Write32(parent+8,(uint)value);m.Write32(parent+12,m.Read32(record+0x14));return Quad(m,record+0x10);
  }
  //Existing4f6bc0 compressed branch, prepared nonnegative parent slot, no additional entry credit.
  public static uint Close(TakeoverReleaseMemory m,uint handle)
  {uint record=unchecked(0x297dc60+(handle-0x800)*48),index=m.Read32(record+0x20);if(unchecked((int)index)<0)throw new ArgumentException("Prepared nonnegative parent slot required.");m.Write32(unchecked(m.Read32(record)+(index<<4)+0x34),0xffffffff);m.Write32(record+0x24,0);return record;}
 }
 public sealed class RecoveredScriptCompressedSeekServices:ScriptRemainingSeekServices
 {
  readonly ScriptHostFileServices host;readonly ScriptRemainingSeekServices remaining;public RecoveredScriptCompressedSeekServices(ScriptHostFileServices h,ScriptRemainingSeekServices r){host=h;remaining=r;}
  public override uint CrtSeek(TakeoverReleaseMemory m,uint h,uint l,uint o,uint mode){return remaining.CrtSeek(m,h,l,o,mode);}
  public override ulong CompressedSeek(TakeoverReleaseMemory m,uint h,uint l,uint hi,uint o){return PreparedScriptCompressedLifecycle.Seek(m,host,this,h,l,hi,o);}
 }
}
