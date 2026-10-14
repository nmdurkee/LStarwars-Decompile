// Stream CloseHandle wrapper and public close taxonomy through recovered memory/container release.
namespace Recovered.Gameplay
{
 public abstract class ScriptCloseServices
 {
  public abstract uint CloseHandle(TakeoverReleaseMemory m,uint handle);
  public abstract uint CrtClose(TakeoverReleaseMemory m,uint descriptor,uint mode);
 }
 public static class PreparedScriptCloseDispatch
 {
  //4ff380 cdecl(index). Native Boolean false becomes1, every nonzero becomes0.
  public static uint Stream(TakeoverReleaseMemory m,ScriptCloseServices io,uint index)
  {uint slot=unchecked(0x8007a0+(index<<2)),value=io.CloseHandle(m,m.Read32(slot));m.Write32(slot,0xffffffff);return value==0?1u:0u;}
  //4f99e0 cdecl(gameHandle). Actual stream child returns only0/1, so signed-negative retry is unreachable.
  public static uint Close(TakeoverReleaseMemory m,ScriptCloseServices io,uint handle)
  {
   if(unchecked((int)handle)>=0x1000)return io.CrtClose(m,unchecked(handle-0x1000),0);
   if(unchecked((int)handle)>=0x400)return handle>=0x800?PreparedScriptCompressedLifecycle.Close(m,handle):PreparedScriptFileLifecycle.Close(m,handle);
   uint index=unchecked(handle-1);Stream(m,io,index);uint stream=unchecked(0x8ceb50+(index<<6)),buffer=m.Read32(stream+0x38);if(buffer!=0)m.Write32(buffer,0);for(uint i=0;i<64;i++)m.Write8(stream+i,0);return stream;
  }
 }
}
