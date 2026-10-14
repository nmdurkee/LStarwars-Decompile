// Original23-byte vsprintf wrapper and entire124-byte locale-aware child.
namespace Recovered.Gameplay
{
 public static class PreparedScriptVsprintf
 {
  public static uint Execute(TakeoverReleaseMemory m,ScriptPrintfServices s,uint destination,uint format,uint arguments,uint file){return Locale(m,s,destination,format,0,arguments,file);}
  // The supplied private32-byte FILE preserves fields not initialized by the original body.
  public static uint Locale(TakeoverReleaseMemory m,ScriptPrintfServices s,uint destination,uint format,uint locale,uint arguments,uint file){if(format==0||destination==0){uint error=s.Errno(m);m.Write32(error,22);s.Invalid(m,0,0,0,0,0);return 0xffffffff;}m.Write32(file+8,destination);m.Write32(file,destination);m.Write32(file+4,0x7fffffff);m.Write32(file+12,0x42);uint result=s.Output(m,file,format,locale,arguments);uint count=unchecked(m.Read32(file+4)-1);m.Write32(file+4,count);if(unchecked((int)count)<0)s.Flush(m,0,file);else m.Write8(m.Read32(file),0);return result;}
 }
}
