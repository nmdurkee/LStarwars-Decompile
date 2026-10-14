// Shared private compiler-local byte strings bind full provider/pool/file bodies to catalog and per-file closures.
using System;
namespace Recovered.Gameplay
{
 public static class ScriptCompilerLocals
 {
  public static uint CString(ConditionParserMemory m,uint local,string text,Func<uint,uint> use){if(text==null||use==null)throw new ArgumentNullException("text/use");ulong count=(ulong)text.Length+1;if((ulong)local+count>0x100000000ul)throw new ArgumentException("Compilerlocal must not wrap.");foreach(var region in m.Image.Regions){ulong start=region.Key,end=start+(ulong)region.Value.Length;if((ulong)local<end&&(ulong)local+count>start)throw new ArgumentException("Unaliased private compiler-local backing required.");}byte[] bytes=new byte[text.Length+1];for(int i=0;i<text.Length;i++){if(text[i]>255)throw new ArgumentException("Byte filename required.");bytes[i]=(byte)text[i];}m.Image.Regions.Add(local,bytes);try{return use(local);}finally{m.Image.Regions.Remove(local);}}
 }
 public abstract class ScriptArchiveCatalogIO
 {
  public abstract uint Find(TakeoverReleaseMemory m,uint archive,uint fileName);
  public abstract ScriptArchiveData Information(TakeoverReleaseMemory m,uint archive,uint entry);
  public abstract uint OpenMemory(TakeoverReleaseMemory m,uint data,uint length,uint mode);
  public abstract uint OpenCatalogFile(TakeoverReleaseMemory m,string path,uint mode);
  public abstract void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] args);
 }
 public sealed class RecoveredAllocatedScriptProvider:ScriptFileProviderServices
 {
  readonly ScriptArchiveCatalogIO archive;readonly ScriptParserAllocationServices files;readonly uint pathLocal;
  public RecoveredAllocatedScriptProvider(ScriptArchiveCatalogIO archiveIO,ScriptParserAllocationServices fileIO,uint formattedPathLocal){if(archiveIO==null||fileIO==null)throw new ArgumentNullException("archiveIO/fileIO");archive=archiveIO;files=fileIO;pathLocal=formattedPathLocal;}
  public override uint Find(TakeoverReleaseMemory m,uint a,uint n){return archive.Find(m,a,n);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint a,uint e){return archive.Information(m,a,e);}
  public override uint OpenMemory(TakeoverReleaseMemory m,uint d,uint l,uint mode){return archive.OpenMemory(m,d,l,mode);}
  public override uint AttachParser(TakeoverReleaseMemory m,uint h){return PreparedScriptParserAllocation.Attach(m,files,h);}
  public override uint OpenFileParser(TakeoverReleaseMemory m,string path){ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");return ScriptCompilerLocals.CString(image,pathLocal,path,delegate(uint p){return PreparedScriptParserAllocation.OpenFile(image,files,p);});}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] args){archive.Diagnostic(m,c,args);}
 }
 public sealed class RecoveredAllocatedScriptTransport:ScriptFileTransportServices
 {
  readonly ScriptFileProviderServices provider;readonly ScriptParserAllocationServices io;readonly ScriptArchiveCatalogIO observer;
  public RecoveredAllocatedScriptTransport(ScriptFileProviderServices fileProvider,ScriptParserAllocationServices fileIO,ScriptArchiveCatalogIO diagnostics){provider=fileProvider;io=fileIO;observer=diagnostics;if(provider==null||io==null||observer==null)throw new ArgumentNullException("provider/io/diagnostics");}
  public override uint Open(TakeoverReleaseMemory m,uint path,uint archive,uint name){return PreparedScriptFileProvider.Open(m,provider,path,archive,name);}
  public override void Close(TakeoverReleaseMemory m,uint parser){PreparedScriptParserAllocation.Close(m,io,parser);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] args){observer.Diagnostic(m,c,args);}
  public override void Command(TakeoverReleaseMemory m,uint c,uint parser){throw new NotSupportedException("No remaining builtin parser command expected.");}
 }
 public sealed class RecoveredFullScriptCatalogServices:ScriptCatalogServices
 {
  readonly ScriptArchiveCatalogIO io;readonly ScriptParserAllocationServices allocation;readonly RecoveredTextConditionServices reader;readonly RecoveredTextScriptFileServices body;readonly uint fileNameLocal,outputLocal;
  public RecoveredFullScriptCatalogServices(ScriptArchiveCatalogIO archiveIO,ScriptParserAllocationServices allocator,RecoveredTextScriptFileServices fileBody,Func<SoundSetupImage,uint,uint,int,int> readFile,uint nameLocal,uint normalizedOutputLocal){if(archiveIO==null||allocator==null||fileBody==null)throw new ArgumentNullException("archiveIO/allocator/fileBody");io=archiveIO;allocation=allocator;body=fileBody;fileNameLocal=nameLocal;outputLocal=normalizedOutputLocal;reader=new RecoveredTextConditionServices(readFile,null,null,Diagnostic);}
  public override uint Find(TakeoverReleaseMemory m,uint a,uint n){return io.Find(m,a,n);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint a,uint e){return io.Information(m,a,e);}
  public override uint OpenMemory(TakeoverReleaseMemory m,uint d,uint l,uint mode){return io.OpenMemory(m,d,l,mode);}
  public override uint OpenFile(TakeoverReleaseMemory m,string path,uint mode){return io.OpenCatalogFile(m,path,mode);}
  public override uint AttachParser(TakeoverReleaseMemory m,uint h){return PreparedScriptParserAllocation.Attach(m,allocation,h);}
  public override void FreeParser(TakeoverReleaseMemory m,uint p){PreparedScriptParserAllocation.Free(m,p);}
  public override void Close(TakeoverReleaseMemory m,uint h){allocation.Close(m,h);}
  public override uint NextLine(TakeoverReleaseMemory m,uint p){return reader.NextLine(m,p);}
  public override void NextToken(TakeoverReleaseMemory m,uint p){reader.NextToken(m,p);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint c,uint[] args){io.Diagnostic(m,c,args);}
  public override uint ParseScript(TakeoverReleaseMemory m,string name,uint basePath,uint archive,uint top,uint bottom){ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");return ScriptCompilerLocals.CString(image,fileNameLocal,name,delegate(uint p){return PreparedScriptFileClosure.Parse(image,body,archive,basePath,p,top,bottom,outputLocal);});}
 }
}
