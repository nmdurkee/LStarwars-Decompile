// Actual UTF16 command narrowing coexists with unchanged byte names and catalog entries.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredFilesystemWideCatalog:ScriptCatalogServices
 {
  readonly RecoveredFullScriptCatalogServices inner;readonly RecoveredGameScriptFileIO files;
  public RecoveredFilesystemWideCatalog(ScriptArchiveCatalogIO archive,RecoveredGameScriptFileIO io,RecoveredTextScriptFileServices body,uint nameLocal,uint outputLocal){files=io;inner=new RecoveredFullScriptCatalogServices(archive,io,body,io.Read,nameLocal,outputLocal);}
  static SoundSetupImage Image(TakeoverReleaseMemory m){ConditionParserMemory shared=m as ConditionParserMemory;if(shared==null)throw new ArgumentException("Shared condition image required.");return shared.Image;}
  public override uint Find(TakeoverReleaseMemory m,uint a,uint p){return inner.Find(m,a,p);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint a,uint e){return inner.Information(m,a,e);}
  public override uint OpenMemory(TakeoverReleaseMemory m,uint d,uint l,uint mode){return inner.OpenMemory(m,d,l,mode);}
  public override uint OpenFile(TakeoverReleaseMemory m,string p,uint mode){return inner.OpenFile(m,p,mode);}
  public override uint AttachParser(TakeoverReleaseMemory m,uint h){return inner.AttachParser(m,h);}
  public override void FreeParser(TakeoverReleaseMemory m,uint p){inner.FreeParser(m,p);}
  public override void Close(TakeoverReleaseMemory m,uint h){inner.Close(m,h);}
  public override uint NextLine(TakeoverReleaseMemory m,uint p){return RecoveredFilesystemWideScripts.NextLine(Image(m),p,files);}
  public override void NextToken(TakeoverReleaseMemory m,uint p){RecoveredFilesystemWideScripts.NextToken(Image(m),p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] a){inner.Diagnostic(m,c,a);}
  public override uint ParseScript(TakeoverReleaseMemory m,string name,uint basePath,uint archive,uint top,uint bottom){return inner.ParseScript(m,name,basePath,archive,top,bottom);}
 }
 public static class RecoveredFilesystemScriptSemantics
 {
  //52c320 EAX=basePath, ECX=archiveHandle; preserve those concrete transport roles through existing opaque parameters.
  public static uint Parse(ConditionParserMemory m,RecoveredTextScriptFileServices body,uint basePath,uint archive,uint name,uint top,uint bottom,uint local){return PreparedScriptFileClosure.Parse(m,body,archive,basePath,name,top,bottom,local);}
 }
}
