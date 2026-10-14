// Loaded container stream facade joins original filesystem loader, container game-open and complete type2 codec services.
namespace Recovered.Gameplay
{
 public sealed class RecoveredLoadedScriptContainerStream
 {
  public readonly uint Container,Handle;readonly RecoveredGameScriptFileIO files;
  RecoveredLoadedScriptContainerStream(RecoveredGameScriptFileIO io,uint container,uint handle){files=io;Container=container;Handle=handle;}
  public static RecoveredLoadedScriptContainerStream Open(ConditionParserMemory m,RecoveredGameScriptFileIO io,uint path,uint entry,uint top,uint sizeOut,uint headerLocal,uint filenameLocal,uint formatLocal){uint container=RecoveredFilesystemScriptContainerLoader.Load(m,io,path,top,sizeOut,0,headerLocal,filenameLocal,formatLocal);uint handle=container==0?0:io.Open(m,entry,0,container,0);return new RecoveredLoadedScriptContainerStream(io,container,handle);}
  public uint Read(ConditionParserMemory m,uint destination,uint count){return unchecked((uint)files.Read(m.Image,Handle,destination,unchecked((int)count)));}
 }
}
