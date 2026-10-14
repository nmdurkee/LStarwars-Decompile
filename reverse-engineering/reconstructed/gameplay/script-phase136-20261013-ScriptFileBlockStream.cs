// Reusable facade over actual begin/scalar/close bodies; nesting remains in the original global block stack.
namespace Recovered.Gameplay
{
 public sealed class RecoveredScriptFileBlockStream
 {
  readonly ConditionParserMemory memory;readonly ScriptHostFileServices seek;readonly ScriptWriteHostServices write;readonly uint handle,local;
  public RecoveredScriptFileBlockStream(ConditionParserMemory image,ScriptHostFileServices seekHost,ScriptWriteHostServices writeHost,uint gameHandle,uint privateLocal){memory=image;seek=seekHost;write=writeHost;handle=gameHandle;local=privateLocal;}
  public uint Begin(uint tag,uint flag){return RecoveredScriptBlockBegin.Begin(memory,seek,write,handle,tag,flag,local);}
  public uint Word(uint value){return RecoveredScriptScalarU32Write.Write(memory,write,handle,value,local);}
  public ulong End(){return RecoveredScriptBlockCloseAllFiles.Close(memory,seek,write,handle,local);}
 }
}
