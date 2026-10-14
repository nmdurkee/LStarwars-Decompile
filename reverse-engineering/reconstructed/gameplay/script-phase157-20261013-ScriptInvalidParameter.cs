// Complete invalid-parameter dispatch6E9FC2. Original five argument slots stay live through tail transfer.
namespace Recovered.Gameplay
{
 public abstract class ScriptInvalidParameterServices
 {
  public abstract uint Decode(TakeoverReleaseMemory m,uint encoded);
  public abstract uint Handler(TakeoverReleaseMemory m,uint callback,uint arguments);
  public abstract void Report(TakeoverReleaseMemory m,uint reason);
  public abstract uint Fatal(TakeoverReleaseMemory m,uint arguments);
 }
 public static class PreparedScriptInvalidParameter
 {
  public static uint Dispatch(TakeoverReleaseMemory m,ScriptInvalidParameterServices services,uint arguments)
  {
   uint callback=services.Decode(m,m.Read32(0x297c19c));if(callback!=0)return services.Handler(m,callback,arguments);services.Report(m,2);return services.Fatal(m,arguments);
  }
 }
}
