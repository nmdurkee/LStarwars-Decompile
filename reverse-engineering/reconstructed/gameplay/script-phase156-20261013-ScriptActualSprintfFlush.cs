// Sprintf uses the actual recovered flush/fileno bodies; private nested argument slots stay scoped.
namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptSprintfFlushServices:ScriptPrintfServices
 {
  readonly ScriptPrintfServices output;readonly ScriptFlushServices flush;
  public RecoveredScriptSprintfFlushServices(ScriptPrintfServices outputServices,ScriptFlushServices flushServices){output=outputServices;flush=flushServices;}
  sealed class Arguments:TakeoverReleaseMemory
  {
   readonly TakeoverReleaseMemory outer;readonly byte[] bytes=new byte[8];public Arguments(TakeoverReleaseMemory m,uint value,uint file){outer=m;Write32(0xfff60000,value);Write32(0xfff60004,file);}
   public override byte Read8(uint p){uint at=unchecked(p-0xfff60000);return at<8?bytes[at]:outer.Read8(p);}
   public override void Write8(uint p,byte value){uint at=unchecked(p-0xfff60000);if(at<8)bytes[at]=value;else outer.Write8(p,value);}
  }
  public override uint Output(TakeoverReleaseMemory m,uint file,uint format,uint locale,uint arguments){return output.Output(m,file,format,locale,arguments);}
  public override uint Errno(TakeoverReleaseMemory m){return output.Errno(m);}
  public override void Invalid(TakeoverReleaseMemory m,uint expression,uint function,uint source,uint line,uint reserved){output.Invalid(m,expression,function,source,line,reserved);}
  public override uint Flush(TakeoverReleaseMemory m,uint value,uint file){var arguments=new Arguments(m,value,file);return PreparedScriptFileFlush.Flush(arguments,flush,0xfff60000,0xfff60004);}
 }
}
