// Original provider root accessors plus full raw-entry provider registration.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptProviderPaths
 {
  const uint Current=0x800478,Count=0x297e064,Providers=0x29803e0;
  //4f6900 copies currentprovider+ac; EAX high24bits survive and AL ends0.
  public static uint GetRoot(TakeoverReleaseMemory m,uint destination,uint eaxSeed){uint source=unchecked(m.Read32(Current)+0xac);if(source==0){m.Write8(destination,0);return eaxSeed;}PreparedScriptByteStrings.Copy(m,destination,source);return eaxSeed&0xffffff00;}
  //4f6930 appends currentprovider+10 separator only if original input has no trailing slash/backslash.
  public static uint SetRoot(ConditionParserMemory m,uint source,uint privateSeparator){uint provider=m.Read32(Current);if(m.Read8(source)==0){m.Write8(unchecked(provider+0xac),0);return provider;}uint length=PreparedScriptByteStrings.Copy(m,unchecked(provider+0xac),source);byte last=m.Read8(unchecked(source+length-1));if(last==47||last==92)return (length&0xffffff00)|last;provider=m.Read32(Current);byte separator=m.Read8(provider+16);return ScriptCompilerLocals.CString(m,privateSeparator,new string((char)separator,1),delegate(uint local){return PreparedScriptByteStrings.Append(m,unchecked(provider+0xac),local);});}
  //Unregistered4f6820 complete216-byte raw entry; no additional REA function credit.
  //REP MOVSD copies141 live DWORD units before copying three paths from the then-current provider.
  public static uint Register(TakeoverReleaseMemory m,uint template){uint index=m.Read32(Count);int signed=unchecked((int)index);if(signed< -1||signed>17)throw new ArgumentException("Mapped bounded provider backing required.");if(signed>=16)RecoveredReleaseScriptDiagnostics.FileWarning();uint destination=unchecked(Providers+index*0x234);for(uint i=0;i<0x8d;i++)m.Write32(unchecked(destination+i*4),m.Read32(unchecked(template+i*4)));uint current=m.Read32(Current);PreparedScriptByteStrings.Copy(m,unchecked(destination+0xac),unchecked(current+0xac));PreparedScriptByteStrings.Copy(m,unchecked(destination+0x12c),unchecked(current+0x12c));PreparedScriptByteStrings.Copy(m,unchecked(destination+0x1ac),unchecked(current+0x1ac));m.Write32(Count,unchecked(index+1));return destination;}
 }
}
