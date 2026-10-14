// Bind lazy container-parent reopening to the same complete default-provider game filesystem transport.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptContainerFilesystem
 {
  sealed class Services:ScriptGameOpenServices
  {
   readonly ScriptGameOpenServices platform;public RecoveredGameScriptFileIO Files;
   public Services(ScriptGameOpenServices finalPlatform){platform=finalPlatform;if(platform==null)throw new ArgumentNullException("finalPlatform");}
   public override void Format(TakeoverReleaseMemory m,uint c,uint p,uint d,uint n,uint z){platform.Format(m,c,p,d,n,z);}
   public override void EnterCriticalSection(TakeoverReleaseMemory m,uint p){platform.EnterCriticalSection(m,p);}
   public override void LeaveCriticalSection(TakeoverReleaseMemory m,uint p){platform.LeaveCriticalSection(m,p);}
   public override void Diagnostic(TakeoverReleaseMemory m,uint[] args){RecoveredReleaseScriptDiagnostics.FileError();}
   public override uint Open(TakeoverReleaseMemory m,uint p,uint mode,uint container,uint quiet){if(Files==null)throw new InvalidOperationException("Filesystem binding required.");return Files.Open(m,p,mode,container,quiet);}
   public override uint CrtOpen(TakeoverReleaseMemory m,uint a,uint b,uint p,uint mode,uint quiet){return platform.CrtOpen(m,a,b,p,mode,quiet);}
  }
  public static RecoveredGameScriptFileIO Create(ScriptGameOpenServices platform,ScriptOpenHostServices opener,ScriptHostFileServices host,ScriptCloseServices closer,ScriptFileSizeServices sizes,ScriptRemainingSeekServices seeks,ScriptRemainingReadServices reads,uint nameLocal,uint headerLocal,uint findLocal,uint formatLocal){var services=new Services(platform);var files=RecoveredDefaultScriptFileIO.Create(services,opener,host,closer,sizes,seeks,reads,nameLocal,headerLocal,findLocal,formatLocal);services.Files=files;return files;}
 }
}
