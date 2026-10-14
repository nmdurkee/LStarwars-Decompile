// Full archive metadata and memory transport provider for prepared mapped raw archive records.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredRawScriptArchive:ScriptArchiveCatalogIO
 {
  readonly ScriptArchiveCatalogIO remainingFiles;readonly uint informationLocal;
  public RecoveredRawScriptArchive(ScriptArchiveCatalogIO fileFallback,uint privateInformationLocal){remainingFiles=fileFallback;informationLocal=privateInformationLocal;}
  static ConditionParserMemory Shared(TakeoverReleaseMemory m){ConditionParserMemory p=m as ConditionParserMemory;if(p==null)throw new ArgumentException("Shared condition/parser image required.");return p;}
  public override uint Find(TakeoverReleaseMemory m,uint archive,uint name){return PreparedScriptArchiveRecords.Find(Shared(m),archive,name);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint archive,uint entry)
  {
   ScriptArchiveData result=new ScriptArchiveData();
   ScriptCompilerLocals.CString(Shared(m),informationLocal,"\0\0\0\0\0\0\0",delegate(uint output){if(PreparedScriptArchiveRecords.Information(m,archive,entry,output,output+4)==0)throw new ArgumentException("Prepared available archive entry required.");result.Data=m.Read32(output);result.Length=m.Read32(output+4);return 0;});
   return result;
  }
  public override uint OpenMemory(TakeoverReleaseMemory m,uint data,uint length,uint mode){return PreparedScriptMemoryFiles.Open(m,data,length,mode);}
  public override uint OpenCatalogFile(TakeoverReleaseMemory m,string path,uint mode){if(remainingFiles==null)throw new NotSupportedException("Filesystem catalog fallback required.");return remainingFiles.OpenCatalogFile(m,path,mode);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] args){if(remainingFiles!=null)remainingFiles.Diagnostic(m,callback,args);}
 }
}
