// Original16-byte-block memory wrappers; existing world memset/SSE and memmove reused.
namespace Recovered.Gameplay
{
 public static class RecoveredScriptBlockMemory
 {
  public static uint Fill(ConditionParserMemory m,uint destination,uint value,uint blocks){return PtlRuntimeMemory.Fill(m.Image,destination,unchecked((byte)value),unchecked(blocks<<4));}
  //Raw4ef700 scales count, then tail-jumps to original4ef660 whose native EAX is direction-dependent.
  public static uint Move(TakeoverReleaseMemory m,uint destination,uint source,uint blocks){return RecoveredScriptByteMove.Move(m,destination,source,unchecked(blocks<<4));}
  public static uint Zero(){return 0;}
  public static uint Arena(TakeoverReleaseMemory m){return m.Read32(0x88ab28);}
 }
}
