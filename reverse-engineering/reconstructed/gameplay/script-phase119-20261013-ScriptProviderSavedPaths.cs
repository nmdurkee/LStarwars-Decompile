// Entire original unregistered user/save path accessor bodies; no new REA function credit.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptProviderSavedPaths
 {
  //4f69a0: explicit void projection; native incidental EAX is not asserted.
  public static void SetUser(ConditionParserMemory m,uint source){uint provider=m.Read32(0x800478);if(m.Read8(source)!=0){PreparedScriptByteStrings.Copy(m,provider+0x12c,source);PreparedScriptByteStrings.Append(m,provider+0x12c,0x75a204);}else{PreparedScriptByteStrings.Copy(m,provider+0x12c,0x75ea58);uint executable=unchecked(m.Read32(0x800470)+5);provider=m.Read32(0x800478);uint cursor=unchecked(provider+0x12c+PreparedScriptByteStrings.Length(m,provider+0x12c)),budget=0;while(m.Read8(executable)!=46){if(budget++>=4096)throw new ArgumentException("Prepared filename containing first dot required.");m.Write8(cursor++,m.Read8(executable++));}m.Write8(cursor,92);m.Write8(cursor+1,0);}provider=m.Read32(0x800478);PreparedScriptContainerIndex.Normalize(m,provider,provider+0x12c);}
  //4f6af0: appends original literal backslash for every nonempty string, including trailing separators.
  public static uint SetSaved(TakeoverReleaseMemory m,uint source,uint eaxSeed){uint provider=m.Read32(0x800478);if(m.Read8(source)==0){m.Write8(provider+0x1ac,0);return eaxSeed&0xffffff00;}PreparedScriptByteStrings.Copy(m,provider+0x1ac,source);return PreparedScriptByteStrings.Append(m,unchecked(m.Read32(0x800478)+0x1ac),0x75a204);}
  //4f6a60: concatenate base+saved then normalize only suffix after reloaded live base length.
  public static void GetSaved(ConditionParserMemory m,uint destination){PreparedScriptByteStrings.Copy(m,destination,unchecked(m.Read32(0x800478)+0x4c));PreparedScriptByteStrings.Append(m,destination,unchecked(m.Read32(0x800478)+0x1ac));uint provider=m.Read32(0x800478);PreparedScriptContainerIndex.Normalize(m,provider,unchecked(destination+PreparedScriptByteStrings.Length(m,provider+0x4c)));}
 }
}
