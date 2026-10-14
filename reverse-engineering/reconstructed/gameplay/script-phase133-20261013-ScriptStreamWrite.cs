// Entire original Win32 stream write wrapper, only final platform WriteFile explicit.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptWriteHostServices
 {
  //numberWritten represents the surviving initialized0 native local if the OS does not write it.
  public abstract uint WriteFile(TakeoverReleaseMemory m,uint handle,uint source,uint count,uint overlapped,out uint numberWritten);
 }
 public static class RecoveredScriptStreamWrite
 {
  //4ff3f0 cdecl(index,source,count): only nonzero Boolean returns writtenDWORD; no clamp tocount.
  public static uint Write(TakeoverReleaseMemory m,ScriptWriteHostServices host,uint index,uint source,uint count){if(index>=64)throw new ArgumentException("Prepared stream index required.");uint raw=m.Read32(0x8007a0+index*4),number;uint success=host.WriteFile(m,raw,source,count,0,out number);return success!=0?number:0;}
 }
}
