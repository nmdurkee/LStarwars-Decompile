// The original release binary implements these five diagnostic entries as one-byte RET bodies.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredReleaseScriptDiagnostics
 {
  public static void FileWarning(){} //4ef790
  public static void FileError(){} //4ef7b0
  public static void ScriptWarning(){} //512850
  public static void ScriptError(){} //512860
  public static void ScriptArchiveError(){} //512870
  public static void Report(TakeoverReleaseMemory m,uint callback,uint[] args){switch(callback){case 0x4ef790:FileWarning();return;case 0x4ef7b0:FileError();return;case 0x512850:ScriptWarning();return;case 0x512860:ScriptError();return;case 0x512870:ScriptArchiveError();return;default:throw new ArgumentException("Recovered release diagnostic entry required.");}}
 }
 public sealed class RecoveredReleaseScriptArchive:ScriptArchiveCatalogIO
 {
  readonly RecoveredGameScriptArchive inner;
  public RecoveredReleaseScriptArchive(RecoveredGameScriptFileIO files,uint nameLocal,uint informationLocal){inner=new RecoveredGameScriptArchive(files,nameLocal,informationLocal,null);}
  public override uint Find(TakeoverReleaseMemory m,uint a,uint p){return inner.Find(m,a,p);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint a,uint e){return inner.Information(m,a,e);}
  public override uint OpenMemory(TakeoverReleaseMemory m,uint d,uint l,uint mode){return inner.OpenMemory(m,d,l,mode);}
  public override uint OpenCatalogFile(TakeoverReleaseMemory m,string p,uint mode){return inner.OpenCatalogFile(m,p,mode);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] args){RecoveredReleaseScriptDiagnostics.Report(m,c,args);}
 }
}
