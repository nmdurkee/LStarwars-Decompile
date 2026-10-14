// LZ2K block header fields and payload loading through the recovered game reader.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptCompressedHeaders
 {
  static bool Signature(TakeoverReleaseMemory m,uint p){for(uint i=0;i<4;i++)if(m.Read8(p+i)!=m.Read8(0x75ea44+i))return false;return true;}
  public static uint PlainLength(TakeoverReleaseMemory m,uint p){return Signature(m,p)?m.Read32(p+4)&m.Read32(0x800540):0;}
  public static uint BlockLength(TakeoverReleaseMemory m,uint p){if(!Signature(m,p))return 0;uint value=m.Read32(p+8)&m.Read32(0x800540);return value==0?0:unchecked(value+12);}
 }
 public static class PreparedScriptCompressedChunk
 {
  //4f6760 no arguments. Full twelve-byte private header and valid progressing payload domain.
  public static uint Load(ConditionParserMemory m,ScriptHostFileServices host,ScriptRemainingReadServices reads,uint privateHeader)
  {
   return ScriptCompilerLocals.CString(m,privateHeader,new string('\0',11),delegate(uint header){
    uint parent=m.Read32(0x917844);
    if(PreparedScriptBufferedRead.Read(m,host,reads,m.Read32(parent),header,12)!=12)throw new ArgumentException("Prepared complete twelve-byte block header required.");
    m.Write32(0x91784c,PreparedScriptCompressedHeaders.PlainLength(m,header));
    m.Write32(0x917840,unchecked(PreparedScriptCompressedHeaders.BlockLength(m,header)-12));
    PreparedScriptBufferedRead.Read(m,host,reads,m.Read32(m.Read32(0x917844)),0x88ab50,m.Read32(0x917840));
    uint delta=unchecked(m.Read32(0x917840)+12),low=m.Read32(m.Read32(0x91ce60)+0x10),high=m.Read32(m.Read32(0x91ce60)+0x14),sum=unchecked(low+delta);
    uint record=m.Read32(0x91ce60);m.Write32(record+0x10,sum);m.Write32(record+0x14,unchecked(high+(uint)((int)delta>>31)+(sum<low?1u:0u)));
    low=m.Read32(record+0x10);high=m.Read32(m.Read32(0x91ce60)+0x14);parent=m.Read32(0x917844);m.Write32(parent+8,low);m.Write32(parent+12,high);return parent;
   });
  }
 }
 public sealed class RecoveredScriptCompressedChunkServices:ScriptCompressedChunkServices
 {
  readonly ScriptHostFileServices host;readonly ScriptRemainingReadServices reads;readonly ScriptCompressedChunkServices codec;readonly uint header;
  public RecoveredScriptCompressedChunkServices(ScriptHostFileServices h,ScriptRemainingReadServices r,ScriptCompressedChunkServices c,uint local){host=h;reads=r;codec=c;header=local;}
  public override void Fill(TakeoverReleaseMemory m){ConditionParserMemory image=m as ConditionParserMemory;if(image==null)throw new ArgumentException("Shared parser image required.");PreparedScriptCompressedChunk.Load(image,host,reads,header);}
  public override uint Decode(TakeoverReleaseMemory m,uint p,uint d,uint packed,uint plain){return codec.Decode(m,p,d,packed,plain);}
 }
}
