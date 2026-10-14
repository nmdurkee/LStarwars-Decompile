// Whole registered type1-provider open and release CRT lifecycle, with no I/O ports.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredReleaseCrtGameOpenServices:ScriptGameOpenServices
 {
  readonly uint local;public RecoveredReleaseCrtGameOpenServices(uint privateFormatter){local=privateFormatter;}
  public override void Format(TakeoverReleaseMemory m,uint callback,uint provider,uint output,uint input,uint capacity){if(callback!=0x4ff130)throw new ArgumentException("Prepared original default formatter required.");PreparedScriptDefaultFilename.Format((ConditionParserMemory)m,provider,output,input,capacity,local);}
  public override uint CrtOpen(TakeoverReleaseMemory m,uint a,uint b,uint p,uint mode,uint r){return RecoveredReleaseCrtFiles.Open(a,b,p,mode,r);}
  public override void EnterCriticalSection(TakeoverReleaseMemory m,uint p){throw new ArgumentException("Prepared type1 provider required.");}
  public override void LeaveCriticalSection(TakeoverReleaseMemory m,uint p){throw new ArgumentException("Prepared type1 provider required.");}
  public override uint Open(TakeoverReleaseMemory m,uint p,uint mode,uint c,uint r){throw new ArgumentException("Prepared container-free type1 provider required.");}
  public override void Diagnostic(TakeoverReleaseMemory m,uint[] args){RecoveredReleaseScriptDiagnostics.FileError();}
 }
 public static class RecoveredRegisteredCrtScriptFiles
 {
  public static uint OpenRegistered(ConditionParserMemory m,uint root,uint[] templates,uint path,uint mode,uint quiet,uint privateSeparator,uint privateFilename,uint privateFormatter,out uint[] registrationReturns){if(templates==null||templates.Length>16||m.Read32(0x297e064)!=0)throw new ArgumentException("Prepared empty provider list required.");RecoveredScriptProviderPaths.SetRoot(m,root,privateSeparator);registrationReturns=new uint[templates.Length];for(int i=0;i<templates.Length;i++)registrationReturns[i]=RecoveredScriptProviderPaths.Register(m,templates[i]);uint provider=PreparedScriptContainerIndex.Provider(m,path);if(provider==0)provider=m.Read32(0x800478);if(m.Read32(provider)!=1||m.Read32(provider+0x22c)!=0x4ff130)throw new ArgumentException("Prepared original type1 provider required.");return PreparedScriptGameOpen.Open(m,new RecoveredReleaseCrtGameOpenServices(privateFormatter),null,null,null,path,mode,0,quiet,privateFilename);}
 }
}
