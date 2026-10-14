// Original archive/container reader and mode2 global decoded-chunk cache; chunk/decode services explicit.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptCompressedChunkServices
 {
  public abstract void Fill(TakeoverReleaseMemory m);
  public abstract uint Decode(TakeoverReleaseMemory m,uint packed,uint destination,uint packedLength,uint plainLength);
 }
 public static class PreparedScriptCompressedRead
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(unchecked(p+4))<<32);}
  static void Quad(TakeoverReleaseMemory m,uint p,ulong value){m.Write32(p,(uint)value);m.Write32(unchecked(p+4),(uint)(value>>32));}
  //4faf60 cdecl(handle,destination,count). Prepared valid records, mapped disjoint copy and progressing chunks.
  public static uint Read(TakeoverReleaseMemory m,ScriptCompressedChunkServices chunks,ScriptHostFileServices host,ScriptRemainingReadServices reads,ScriptRemainingSeekServices seeks,uint handle,uint destination,uint count)
  {
   uint record=unchecked(0x297dc60+(handle-0x800)*48),parent=unchecked(m.Read32(record)+((m.Read32(record+0x20)+3)<<4));
   if(m.Read32(record+0x28)==2)
   {
    if(count==0)return 0;uint available=m.Read32(0x90fba4),total=0,budget=0;
    while(count!=0)
    {
     if(++budget>8192)throw new ArgumentException("Prepared progressing positive chunks required.");
     if(available==0){chunks.Fill(m);uint packed=m.Read32(0x917840),plain=m.Read32(0x91784c);if(packed==plain){for(uint i=0;i<packed;i++)m.Write8(0x8cf598+i,m.Read8(0x88ab50+i));}else chunks.Decode(m,0x88ab50,0x8cf598,packed,plain);available=m.Read32(0x91784c);m.Write32(0x8cf390,0);}
     int copied=Math.Min(unchecked((int)count),unchecked((int)available));if(copied<0)throw new ArgumentException("Prepared nonnegative chunk copy required.");uint source=unchecked(0x8cf598+m.Read32(0x8cf390));for(uint i=0;i<(uint)copied;i++)m.Write8(unchecked(destination+i),m.Read8(unchecked(source+i)));
     m.Write32(0x8cf390,unchecked(m.Read32(0x8cf390)+(uint)copied));total=unchecked(total+(uint)copied);available=unchecked(available-(uint)copied);count=unchecked(count-(uint)copied);destination=unchecked(destination+(uint)copied);m.Write32(0x90fba4,available);
    }
    return total;
   }
   ulong current=Quad(m,record+0x10);
   if(current!=Quad(m,parent+8)){PreparedScriptSeekDispatch.Seek(m,host,seeks,m.Read32(parent),(uint)current,(uint)(current>>32),0);Quad(m,parent+8,Quad(m,record+0x10));}
   long remaining=unchecked((long)(Quad(m,record+8)+(ulong)(long)(int)m.Read32(record+0x18)-Quad(m,record+0x10)));if(remaining<0)remaining=0;
   uint chosen=unchecked((uint)Math.Min((long)(int)count,remaining));if(chosen==0)return 0;
   uint value=PreparedScriptBufferedRead.Read(m,host,reads,m.Read32(parent),destination,chosen);
   if(unchecked((int)value)>=0){Quad(m,record+0x10,unchecked(Quad(m,record+0x10)+value));Quad(m,parent+8,Quad(m,record+0x10));}
   return value;
  }
 }
}
