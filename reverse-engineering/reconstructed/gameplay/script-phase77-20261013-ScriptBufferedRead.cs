// Complete raw transport reader with recovered memory/buffer/stream children; final CRT/compressed/Win32 APIs explicit.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptRemainingReadServices
 {
  public abstract uint CrtRead(TakeoverReleaseMemory m,uint descriptor,uint destination,uint count,uint mode);
  public abstract uint CompressedRead(TakeoverReleaseMemory m,uint handle,uint destination,uint count);
 }
 public static class PreparedScriptBufferedRead
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(unchecked(p+4))<<32);}
  static void Quad(TakeoverReleaseMemory m,uint p,ulong value){m.Write32(p,(uint)value);m.Write32(unchecked(p+4),(uint)(value>>32));}
  static bool Less(ulong a,ulong b){return unchecked((long)a)<unchecked((long)b);}
  //4fb550 cdecl(gameHandle,destination,signedCount). Prepared bounded-progress buffered copies and allocatedmemory handles.
  public static uint Read(TakeoverReleaseMemory m,ScriptHostFileServices host,ScriptRemainingReadServices remaining,uint handle,uint destination,uint count)
  {
   int h=unchecked((int)handle);
   if(h>=0x1000)return remaining.CrtRead(m,handle-0x1000,destination,count,0);
   if(h>=0x400)return h>=0x800?remaining.CompressedRead(m,handle,destination,count):PreparedScriptMemoryFiles.Read(m,handle,destination,count);
   uint index=unchecked(handle-1),stream=unchecked(0x8ceb50+(index<<6));
   if(m.Read32(stream+0x2c)==0)return PreparedScriptStreamFiles.Read(m,host,index,destination,count);
   if(m.Read32(stream+0x38)==0)PreparedScriptStreamBuffers.Acquire(m,host,stream);
   int needed=unchecked((int)count);uint total=0,budget=0;
   while(needed>0)
   {
    if(++budget>8192)throw new ArgumentException("Prepared bounded-progress read required; zero refill before declared EOF can loop in original.");
    ulong current=Quad(m,stream+8);
    if(!Less(current,Quad(m,stream+0x18)))break;
    ulong start=Quad(m,stream+0x20),end=unchecked(start+(ulong)(long)(int)m.Read32(stream+0x28));
    if(Less(current,start)||!Less(current,end))
    {
     if(current!=Quad(m,stream+0x10)){PreparedScriptStreamFiles.Seek(m,host,m.Read32(stream),(uint)current,(uint)(current>>32),0);Quad(m,stream+0x10,Quad(m,stream+8));}
     uint value=PreparedScriptStreamFiles.Read(m,host,m.Read32(stream),unchecked(m.Read32(stream+0x38)+8),1024);
     ulong before=Quad(m,stream+0x10);m.Write32(stream+0x28,value);Quad(m,stream+0x20,before);Quad(m,stream+0x10,unchecked(before+(ulong)(long)(int)value));
    }
    int available=unchecked((int)(m.Read32(stream+0x28)-m.Read32(stream+8)+m.Read32(stream+0x20))),copied=available<needed?available:needed;
    if(copied<0)throw new ArgumentException("Prepared nonnegative disjoint memcpy count required.");
    if(copied!=0){uint source=unchecked(m.Read32(stream+0x38)-m.Read32(stream+0x20)+m.Read32(stream+8)+8);for(uint i=0;i<(uint)copied;i++)m.Write8(unchecked(destination+i),m.Read8(unchecked(source+i)));}
    destination=unchecked(destination+(uint)copied);total=unchecked(total+(uint)copied);needed-=copied;Quad(m,stream+8,unchecked(Quad(m,stream+8)+(uint)copied));
   }
   return total;
  }
 }
}
