// Complete CRT sprintf6E69EF ownbody. Output parser, errno/invalid-parameter and flush children remain explicit.
namespace Recovered.Gameplay
{
 public abstract class ScriptPrintfServices
 {
  public abstract uint Output(TakeoverReleaseMemory m,uint file,uint format,uint locale,uint arguments);
  public abstract uint Errno(TakeoverReleaseMemory m);
  public abstract void Invalid(TakeoverReleaseMemory m,uint expression,uint function,uint source,uint line,uint reserved);
  public abstract uint Flush(TakeoverReleaseMemory m,uint value,uint file);
 }
 public static class PreparedScriptSprintf
 {
  // Private32-byteFILE retains caller-supplied untouched bytes; varargs points to original first argument slot.
  public static uint Execute(TakeoverReleaseMemory m,ScriptPrintfServices services,uint destination,uint format,uint arguments,uint file)
  {
   if(format==0||destination==0){uint error=services.Errno(m);m.Write32(error,22);services.Invalid(m,0,0,0,0,0);return 0xffffffff;}
   m.Write32(file+8,destination);m.Write32(file,destination);m.Write32(file+4,0x7fffffff);m.Write32(file+12,0x42);uint result=services.Output(m,file,format,0,arguments);uint count=unchecked(m.Read32(file+4)-1);m.Write32(file+4,count);if(unchecked((int)count)<0)services.Flush(m,0,file);else m.Write8(m.Read32(file),0);return result;
  }
 }
}
