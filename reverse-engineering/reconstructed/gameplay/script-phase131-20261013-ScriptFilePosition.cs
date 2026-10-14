// Whole original current-position taxonomy, with only final Win32 seek explicit.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptFilePosition
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(p+4)<<32);}
  //4f6c20 relative position: memory32bit diff sign-extended, compressed64bit diff with borrow.
  public static ulong Prepared(TakeoverReleaseMemory m,uint handle){if(handle>=0x800){if(handle>=0x814)throw new ArgumentException("Prepared compressed-file record required.");uint record=0x297dc60+(handle-0x800)*48;return unchecked(Quad(m,record+16)-Quad(m,record+8));}if(handle<0x400||handle>=0x414)throw new ArgumentException("Prepared memory-file record required.");uint slot=0x2983740+(handle-0x400)*20;return unchecked((ulong)(long)(int)(m.Read32(slot+8)-m.Read32(slot)));}
  //4f6d10 calls CRTseek withorigin2, preparedchild for400+, orbufferedcursor/rawWin32seek(origin1).
  //TEST EAX clears CF before its JNC; low sign is not a failure condition. Only signedhigh<0 retries.
  public static ulong Public(TakeoverReleaseMemory m,ScriptHostFileServices host,uint handle){if(unchecked((int)handle)>=0x1000)return unchecked((ulong)(long)(int)RecoveredActualReleaseCrtEndpoints.Seek(handle-0x1000,0,2,0));if(unchecked((int)handle)>=0x400)return Prepared(m,handle);if(handle<1||handle>64)throw new ArgumentException("Prepared stream handle required.");uint index=handle-1,stream=0x8ceb50+index*64;if(m.Read32(stream+44)!=0)return Quad(m,stream+8);for(uint attempts=0;attempts<1024;attempts++){ulong result=PreparedScriptStreamFiles.Seek(m,host,index,0,0,1);if(unchecked((int)(result>>32))>=0)return result;}throw new ArgumentException("Prepared progressing position query required.");}
 }
}
