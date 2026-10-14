// Entire original unregistered provider selector; no additional REA function credit.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptProviderSelection
 {
  //4eff40 cdecl(kind,qualifier). kind1/3 alias2; kind-3 returns currentprovider; negative qualifier is wildcard.
  public static uint Select(TakeoverReleaseMemory m,uint kind,uint qualifier){if(kind==0xfffffffd)return m.Read32(0x800478);if(kind==1||kind==3)kind=2;int count=unchecked((int)m.Read32(0x297e064));if(count>16)throw new ArgumentException("Prepared sixteen-provider backing required.");for(int i=0;i<count;i++){uint row=unchecked(0x29803e0+(uint)i*0x234);if(m.Read32(row)==kind&&(unchecked((int)qualifier)<0||m.Read32(row+4)==qualifier))return row;}return 0;}
 }
}
