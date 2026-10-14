// Filesystem/parser transport now uses recovered existence, game open, read, seek, size and close bodies.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredGameScriptFileIO:ScriptParserAllocationServices
 {
  readonly ScriptGameOpenServices game;readonly ScriptOpenHostServices open;readonly ScriptHostFileServices host;readonly ScriptCloseServices close;readonly ScriptFileSizeServices size;readonly ScriptRemainingSeekServices seek;readonly ScriptRemainingReadServices read;readonly uint filenameLocal,prefixLocal,indexLocal;
  sealed class ExistsFiles:ScriptExistsServices{readonly RecoveredGameScriptFileIO io;public ExistsFiles(RecoveredGameScriptFileIO owner){io=owner;}public override uint Find(TakeoverReleaseMemory m,uint c,uint p){return PreparedHierarchicalScriptContainerIndex.Find(Image(m),c,p,io.indexLocal);}public override uint Open(TakeoverReleaseMemory m,uint p,uint mode,uint c,uint r){return io.Open(m,p,mode,c,r);}}
  static ConditionParserMemory Image(TakeoverReleaseMemory m){ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared condition image required.");return image;}
  public RecoveredGameScriptFileIO(ScriptGameOpenServices g,ScriptOpenHostServices o,ScriptHostFileServices h,ScriptCloseServices c,ScriptFileSizeServices z,ScriptRemainingSeekServices s,ScriptRemainingReadServices r,uint nameLocal,uint bomLocal,uint findLocal){game=g;open=o;host=h;close=c;size=z;seek=new RecoveredScriptCompressedSeekServices(h,s);filenameLocal=nameLocal;prefixLocal=bomLocal;indexLocal=findLocal;read=new RecoveredDecodedScriptReadServices(h,r,seek,findLocal);}
  public override ushort Prefix(TakeoverReleaseMemory m,uint h){return (ushort)ScriptCompilerLocals.CString(Image(m),prefixLocal,"\0",delegate(uint p){PreparedScriptBufferedRead.Read(m,host,read,h,p,2);return m.Read16(p);});}
  public override uint Byte(TakeoverReleaseMemory m,uint h){return ScriptCompilerLocals.CString(Image(m),prefixLocal,"",delegate(uint p){uint value=PreparedScriptBufferedRead.Read(m,host,read,h,p,1);return (value&0xffffff00)|m.Read8(p);});}
  public override void Seek(TakeoverReleaseMemory m,uint h,uint l,uint hi,uint origin){PreparedScriptSeekDispatch.Seek(m,host,seek,h,l,hi,origin);}
  public override uint Size(TakeoverReleaseMemory m,uint h){return (uint)PreparedScriptFileLifecycle.Size(m,size,h);}
  public override uint Exists(TakeoverReleaseMemory m,uint p){return PreparedScriptExists.Exists(m,new ExistsFiles(this),close,p);}
  public override uint Open(TakeoverReleaseMemory m,uint p,uint mode,uint options,uint reserved){return PreparedScriptGameOpen.Open(Image(m),game,open,host,seek,p,mode,options,reserved,filenameLocal);}
  public override void Close(TakeoverReleaseMemory m,uint h){PreparedScriptCloseDispatch.Close(m,close,h);}
  public int Read(SoundSetupImage image,uint h,uint buffer,int count){return unchecked((int)PreparedScriptBufferedRead.Read(new ConditionParserMemory(image),host,read,h,buffer,unchecked((uint)count)));}
 }
}
