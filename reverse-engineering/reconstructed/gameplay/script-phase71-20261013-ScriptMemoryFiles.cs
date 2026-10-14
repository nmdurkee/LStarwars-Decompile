// Original memory-file transport table and inclusive-end reader; valid allocated slots and disjoint copy backing.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptMemoryFiles
 {
  const uint Table=0x2983740;
  //4f02d0 cdecl(data,signedLength,mode), first inactive of20 slots, modes0/1 only.
  public static uint Open(TakeoverReleaseMemory m,uint data,uint length,uint mode)
  {
   if(unchecked((int)length)<=0||(mode!=0&&mode!=1))return 0;
   for(uint i=0;i<20;i++){uint slot=Table+i*20;if(m.Read32(slot+16)!=0)continue;m.Write32(slot+4,unchecked(data+length-1));m.Write32(slot+12,mode);m.Write32(slot,data);m.Write32(slot+8,data);m.Write32(slot+16,1);return 0x400+i;}
   return 0;
  }
  //4fb4f0 cdecl(handle,destination,signedCount), prepared memory handles400..413.
  //Its800+ compressed tail remains outside this prepared slot domain.
  public static uint Read(TakeoverReleaseMemory m,uint handle,uint destination,uint length)
  {
   if(handle<0x400||handle>=0x414)throw new ArgumentException("Prepared allocated memory-file handle required.");
   uint slot=Table+(handle-0x400)*20,cursor=m.Read32(slot+8);
   int remaining=unchecked((int)(m.Read32(slot+4)-cursor+1)),requested=unchecked((int)length);
   int count=remaining<requested?remaining:requested;
   if(count<0)throw new ArgumentException("Prepared nonnegative copy count required.");
   if(count!=0){for(uint i=0;i<(uint)count;i++)m.Write8(unchecked(destination+i),m.Read8(unchecked(cursor+i)));m.Write32(slot+8,unchecked(m.Read32(slot+8)+(uint)count));}
   return (uint)count;
  }
  //Original4fb550 selectedmemory branch tail-dispatches4fb4f0 unchanged; no extra entry credit.
  public static uint ReadTransport(TakeoverReleaseMemory m,uint handle,uint destination,uint length){return Read(m,handle,destination,length);}
 }
}
