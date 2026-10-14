// Actual release file status leaves and complete public-close composition.
namespace Recovered.Gameplay
{
 public static class RecoveredReleaseScriptFileStatus
 {
  public static uint CrtClose(uint descriptor,uint mode){return 0;} //6dee70 XOR EAX,EAX;RET
  public static uint Poll(uint handle,uint operation){return 0;} //6dee90 XOR EAX,EAX;RET; no input reads
 }
 public sealed class RecoveredReleaseScriptCloseServices:ScriptCloseServices
 {
  readonly ScriptCloseServices platform;
  public RecoveredReleaseScriptCloseServices(ScriptCloseServices host){platform=host;}
  public override uint CloseHandle(TakeoverReleaseMemory m,uint handle){return platform.CloseHandle(m,handle);}
  public override uint CrtClose(TakeoverReleaseMemory m,uint descriptor,uint mode){return RecoveredReleaseScriptFileStatus.CrtClose(descriptor,mode);}
 }
}
