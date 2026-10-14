// Archive metadata remains explicit; memory handles use original allocator/read/seek/size/close bodies.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredMemoryScriptArchive:ScriptArchiveCatalogIO
 {
  readonly ScriptArchiveCatalogIO metadata;
  public RecoveredMemoryScriptArchive(ScriptArchiveCatalogIO remaining){metadata=remaining;}
  public override uint Find(TakeoverReleaseMemory m,uint a,uint name){return metadata.Find(m,a,name);}
  public override ScriptArchiveData Information(TakeoverReleaseMemory m,uint a,uint entry){return metadata.Information(m,a,entry);}
  public override uint OpenMemory(TakeoverReleaseMemory m,uint data,uint length,uint mode){return PreparedScriptMemoryFiles.Open(m,data,length,mode);}
  public override uint OpenCatalogFile(TakeoverReleaseMemory m,string path,uint mode){return metadata.OpenCatalogFile(m,path,mode);}
  public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] args){metadata.Diagnostic(m,callback,args);}
 }
 public sealed class RecoveredMemoryScriptAllocation:ScriptParserAllocationServices
 {
  readonly ScriptParserAllocationServices remaining;readonly Func<SoundSetupImage,uint,uint,int,int> fallback;readonly uint local;
  public RecoveredMemoryScriptAllocation(ScriptParserAllocationServices otherFiles,Func<SoundSetupImage,uint,uint,int,int> otherReads,uint compilerLocal){remaining=otherFiles;fallback=otherReads;local=compilerLocal;}
  public static bool MemoryHandle(uint h){return h>=0x400&&h<0x414;}
  public override ushort Prefix(TakeoverReleaseMemory m,uint h){if(!MemoryHandle(h))return remaining.Prefix(m,h);ConditionParserMemory p=m as ConditionParserMemory;if(p==null)throw new ArgumentException("Shared condition image required.");return (ushort)ScriptCompilerLocals.CString(p,local,"\0",delegate(uint temporary){PreparedScriptMemoryFiles.Read(m,h,temporary,2);return m.Read16(temporary);});}
  public override uint Byte(TakeoverReleaseMemory m,uint h){if(!MemoryHandle(h))return remaining.Byte(m,h);ConditionParserMemory p=m as ConditionParserMemory;if(p==null)throw new ArgumentException("Shared condition image required.");return ScriptCompilerLocals.CString(p,local,"",delegate(uint temporary){uint count=PreparedScriptMemoryFiles.Read(m,h,temporary,1);return (count&0xffffff00)|m.Read8(temporary);});}
  public override void Seek(TakeoverReleaseMemory m,uint h,uint lo,uint hi,uint origin){if(MemoryHandle(h))PreparedScriptFileLifecycle.SeekTransport(m,h,lo,hi,origin);else remaining.Seek(m,h,lo,hi,origin);}
  public override uint Size(TakeoverReleaseMemory m,uint h){return MemoryHandle(h)?(uint)PreparedScriptFileLifecycle.Size(m,null,h):remaining.Size(m,h);}
  public override uint Exists(TakeoverReleaseMemory m,uint name){return remaining.Exists(m,name);}
  public override uint Open(TakeoverReleaseMemory m,uint name,uint mode,uint options,uint reserved){return remaining.Open(m,name,mode,options,reserved);}
  public override void Close(TakeoverReleaseMemory m,uint h){if(MemoryHandle(h))PreparedScriptFileLifecycle.CloseTransport(m,h);else remaining.Close(m,h);}
  public int Read(SoundSetupImage image,uint h,uint buffer,int count){if(!MemoryHandle(h))return fallback(image,h,buffer,count);return (int)PreparedScriptMemoryFiles.ReadTransport(new ConditionParserMemory(image),h,buffer,(uint)count);}
 }
 public sealed class RecoveredMemoryScriptLifecycle:ScriptParserLifecycleServices
 {
  readonly ScriptParserAllocationServices files;readonly ScriptParserLifecycleServices remaining;
  public RecoveredMemoryScriptLifecycle(ScriptParserAllocationServices memoryFiles,ScriptParserLifecycleServices otherErrors){files=memoryFiles;remaining=otherErrors;}
  public override ScriptFileErrorRegisters Error(TakeoverReleaseMemory m){return remaining.Error(m);}
  public override void Close(TakeoverReleaseMemory m,uint h){files.Close(m,h);}
  public override uint Open(TakeoverReleaseMemory m,uint path,uint mode,uint options,uint reserved){return files.Open(m,path,mode,options,reserved);}
  public override void Seek(TakeoverReleaseMemory m,uint h,uint low,uint high,uint origin){files.Seek(m,h,low,high,origin);}
 }
}
