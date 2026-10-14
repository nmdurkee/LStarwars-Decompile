// Provider enumeration copies complete 234-byte records when callback AL bit1 is clear.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptProviderInventory
 {
  //4eff30: exact global word getter; interpretation of91eea4 is kept opaque.
  public static uint GlobalWord(TakeoverReleaseMemory m){return m.Read32(0x91eea4);}
  public static uint OriginalStatus(TakeoverReleaseMemory m,uint callback,uint provider){if(callback==0x4eff30)return GlobalWord(m);if(callback==0x4ef790||callback==0x4ef7b0||callback==0x512850||callback==0x512860||callback==0x512870){RecoveredReleaseScriptDiagnostics.Report(m,callback,new uint[]{provider});return callback;}throw new ArgumentException("Prepared original status callback required.");}
  //4effb0 cdecl(outputPointer), EAX copied row count; normal ABI direction flag is clear.
  public static uint Enumerate(TakeoverReleaseMemory m,uint output,Func<TakeoverReleaseMemory,uint,uint,uint> status){if(status==null)throw new ArgumentNullException("status");uint chosen=0,index=0,destination=0x297e080;int total=unchecked((int)m.Read32(0x297e064));if(total>0){do{if(index>=16)throw new ArgumentException("Prepared sixteen-provider backing required.");uint provider=unchecked(0x29803e0+index*0x234),value=status(m,m.Read32(provider+0x230),provider);if((value&2)==0){chosen++;for(uint word=0;word<0x8d;word++)m.Write32(destination+word*4,m.Read32(provider+word*4));destination+=0x234;}index++;}while(unchecked((int)index)<unchecked((int)m.Read32(0x297e064)));}m.Write32(output,0x297e080);m.Write32(0x29838d0,chosen);return chosen;}
 }
}
