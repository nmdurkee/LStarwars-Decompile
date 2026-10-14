// Entire15-byte original security-cookie gate. Report-gsfailure remains a terminal boundary.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptCookieFailureServices
 {
  //Must terminate by throwing or another host-level failure; this is not an emulated return path.
  public abstract void Report(TakeoverReleaseMemory m,uint cookie,uint eaxSeed);
 }
 public static class RecoveredScriptSecurityCookie
 {
  //Normal native body changes CMP flags only and preserves EAX. Caller supplies its EAX seed.
  public static uint Check(TakeoverReleaseMemory m,ScriptCookieFailureServices failure,uint cookie,uint eaxSeed){if(cookie!=m.Read32(0x829570)){failure.Report(m,cookie,eaxSeed);throw new InvalidOperationException("Report-gsfailure unexpectedly returned.");}return eaxSeed;}
 }
}
