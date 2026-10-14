// Exact byte move used by archive relocation; overlap direction and native EAX are retained.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptByteMove
 {
  //4ef660 cdecl(destination,source,count). Native unsigned address ordering chooses copy direction.
  public static uint Move(TakeoverReleaseMemory m,uint destination,uint source,uint count){if(count>16384)throw new ArgumentException("Prepared bounded mapped move required.");if(destination<source){for(uint i=0;i<count;i++)m.Write8(unchecked(destination+i),m.Read8(unchecked(source+i)));return unchecked(destination+count);}for(uint i=count;i!=0;i--)m.Write8(unchecked(destination+i-1),m.Read8(unchecked(source+i-1)));return 0;}
 }
}
