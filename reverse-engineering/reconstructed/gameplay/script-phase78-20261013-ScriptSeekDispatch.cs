// Complete native game-handle seek taxonomy: distinct CRT/memory/compressed/buffered/Win32 offset handling.
namespace Recovered.Gameplay
{
 public abstract class ScriptRemainingSeekServices
 {
  public abstract uint CrtSeek(TakeoverReleaseMemory m,uint descriptor,uint low,uint origin,uint mode);
  public abstract ulong CompressedSeek(TakeoverReleaseMemory m,uint handle,uint low,uint signHigh,uint origin);
 }
 public static class PreparedScriptSeekDispatch
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(unchecked(p+4))<<32);}
  static void Quad(TakeoverReleaseMemory m,uint p,ulong value){m.Write32(p,(uint)value);m.Write32(unchecked(p+4),(uint)(value>>32));}
  //4f6de0 cdecl(handle,offsetLo,offsetHi,origin), EDX:EAX result.
  public static ulong Seek(TakeoverReleaseMemory m,ScriptHostFileServices host,ScriptRemainingSeekServices remaining,uint handle,uint low,uint high,uint origin)
  {
   int h=unchecked((int)handle);
   if(h>=0x1000)return unchecked((ulong)(long)(int)remaining.CrtSeek(m,handle-0x1000,low,origin,0));
   if(h>=0x400){uint signHigh=unchecked((int)low)<0?uint.MaxValue:0;return h>=0x800?remaining.CompressedSeek(m,handle,low,signHigh,origin):PreparedScriptFileLifecycle.Seek(m,handle,low,signHigh,origin);}
   uint index=unchecked(handle-1),stream=unchecked(0x8ceb50+(index<<6));
   if(m.Read32(stream+0x2c)==0)return PreparedScriptStreamFiles.Seek(m,host,index,low,high,origin);
   ulong offset=low|((ulong)high<<32),position;
   if(origin==1)position=unchecked(Quad(m,stream+8)+offset);
   else if(origin==2)position=unchecked(Quad(m,stream+0x18)-offset);
   else position=offset;
   Quad(m,stream+8,position);return position;
  }
 }
}
