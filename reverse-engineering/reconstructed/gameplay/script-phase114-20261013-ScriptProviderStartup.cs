// Full template provider registration followed by original status inventory callbacks.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptProviderStartup
 {
  public static uint Status(TakeoverReleaseMemory m,uint callback,uint provider){if(callback==0x6dee90)return RecoveredReleaseScriptFileStatus.Poll(provider,0);if(callback==0x6dee70)return RecoveredReleaseScriptFileStatus.CrtClose(provider,0);return RecoveredScriptProviderInventory.OriginalStatus(m,callback,provider);}
  public static uint RegisterAndEnumerate(ConditionParserMemory m,uint root,uint privateSeparator,uint[] templates,uint output,out uint[] registrationReturns){if(templates==null||templates.Length>16||m.Read32(0x297e064)!=0)throw new ArgumentException("Prepared empty provider list and at most16templates required.");RecoveredScriptProviderPaths.SetRoot(m,root,privateSeparator);registrationReturns=new uint[templates.Length];for(int i=0;i<templates.Length;i++)registrationReturns[i]=RecoveredScriptProviderPaths.Register(m,templates[i]);return RecoveredScriptProviderInventory.Enumerate(m,output,Status);}
 }
}
