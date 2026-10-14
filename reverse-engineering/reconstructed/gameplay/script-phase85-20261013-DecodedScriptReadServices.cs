// Concrete compressed-read service joins recovered header loading and the full prepared codec.
using System;
namespace Recovered.Gameplay
{
 public sealed class RecoveredDecodedScriptReadServices:ScriptRemainingReadServices
 {
  readonly ScriptHostFileServices host;readonly ScriptRemainingReadServices remaining;readonly ScriptRemainingSeekServices seeks;readonly ScriptCompressedChunkServices chunks;
  public RecoveredDecodedScriptReadServices(ScriptHostFileServices h,ScriptRemainingReadServices r,ScriptRemainingSeekServices s,uint privateHeader){host=h;remaining=r;seeks=s;chunks=new RecoveredScriptCompressedChunkServices(h,this,new RecoveredScriptCodec(),privateHeader);}
  public override uint CrtRead(TakeoverReleaseMemory m,uint descriptor,uint destination,uint count,uint mode){return remaining.CrtRead(m,descriptor,destination,count,mode);}
  public override uint CompressedRead(TakeoverReleaseMemory m,uint handle,uint destination,uint count){return PreparedScriptCompressedRead.Read(m,chunks,host,this,seeks,handle,destination,count);}
 }
}
