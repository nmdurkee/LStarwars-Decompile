// Entire356-byte original application allocation canary scan.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptAllocationCanaryScan
 {
  static bool Equal(TakeoverReleaseMemory m,uint p,uint pattern){for(uint i=0;i<12;i++)if(m.Read8(p+i)!=m.Read8(pattern+i))return false;return true;}
  //Follows older allocation links at offset0. Prefix first, suffix second, then next record.
  //Corrupt prefix returns block base; corrupt suffix returns payload end; intact/empty list returns0.
  public static uint Scan(TakeoverReleaseMemory m){uint block=m.Read32(0x88ab18);while(block!=0){uint suffix=unchecked(block+m.Read32(block+16)+32);if(!Equal(m,block+20,0x800444)){RecoveredScriptAllocationDiagnostics.Diagnostic();return block;}if(!Equal(m,suffix,0x800454)){RecoveredScriptAllocationDiagnostics.Diagnostic();return suffix;}block=m.Read32(block);}return 0;}
 }
}
