// Original CRT narrow-byte reverse search and bounded padded copy.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptCrtByteStrings
 {
  //6e7d30 searches the terminator too and only uses the low byte of the int target; native restores DF=0.
  public static uint Last(TakeoverReleaseMemory m,uint source,uint target){uint p=source,result=0;byte wanted=(byte)target;while(true){byte b=m.Read8(p);if(b==wanted)result=p;if(b==0)return result;p=unchecked(p+1);}}
  //6e7c00: exact disjoint/identical buffers, readable optimized DWORD padding. No partial-overlap claim.
  //Count0 does not read source or destination, including null/unmapped pointers.
  public static uint Copy(TakeoverReleaseMemory m,uint destination,uint source,uint count){if(count==0)return destination;if(count>16384)throw new ArgumentException("Prepared bounded copy count required.");ulong de=(ulong)destination+count,se=(ulong)source+count;if(destination!=source&&(ulong)destination<se&&(ulong)source<de)throw new ArgumentException("Partial overlap is outside prepared strncpy domain.");bool ended=false;for(uint i=0;i<count;i++){byte b=ended?(byte)0:m.Read8(source+i);m.Write8(destination+i,b);if(b==0)ended=true;}return destination;}
 }
}
