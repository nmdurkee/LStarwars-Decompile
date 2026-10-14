// Exact single-byte read helper and register-ABI marker-only parser release.
namespace Recovered.Gameplay
{
 public abstract class ScriptByteReadServices
 {
  // The compiler-local byte starts at zero; return is the raw4fb550 EAX, and value is the surviving local byte.
  public abstract uint Read(TakeoverReleaseMemory m,uint handle,out byte value);
 }
 public static class PreparedScriptByteRead
 {
  public static uint Read(TakeoverReleaseMemory m,ScriptByteReadServices s,uint handle){byte value;uint result=s.Read(m,handle,out value);return (result&0xffffff00u)|value;}
  public static void FreeRegister(TakeoverReleaseMemory m,uint parser){m.Write32(parser,0);}
 }
}
