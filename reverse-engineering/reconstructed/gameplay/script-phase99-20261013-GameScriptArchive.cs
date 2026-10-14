// Raw archive metadata and concrete filesystem catalog fallback share the recovered game file transport.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredGameScriptArchive:ScriptArchiveCatalogIO
 {
  readonly RecoveredRawScriptArchive raw;readonly RecoveredGameScriptFileIO files;readonly uint pathLocal;readonly Action<TakeoverReleaseMemory,uint,uint[]> diagnostic;
  public RecoveredGameScriptArchive(RecoveredGameScriptFileIO io,uint filenameLocal,uint informationLocal,Action<TakeoverReleaseMemory,uint,uint[]> report){files=io;pathLocal=filenameLocal;diagnostic=report;raw=new RecoveredRawScriptArchive(null,informationLocal);}
  public override uint Find(TakeoverReleaseMemory m,uint a,uint p){return raw.Find(m,a,p);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint a,uint index){return raw.Information(m,a,index);}
  public override uint OpenMemory(TakeoverReleaseMemory m,uint data,uint length,uint mode){return raw.OpenMemory(m,data,length,mode);}
  //Existing4fa5f0 semantics: current91ee88 container snapshot, quiet0; concrete game open via file transport.
  public override uint OpenCatalogFile(TakeoverReleaseMemory m,string path,uint mode){ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared condition image required.");return ScriptCompilerLocals.CString(image,pathLocal,path,delegate(uint p){uint container=m.Read32(0x91ee88);return files.Open(m,p,mode,container,0);});}
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] args){if(diagnostic!=null)diagnostic(m,callback,args);}
 }
}
