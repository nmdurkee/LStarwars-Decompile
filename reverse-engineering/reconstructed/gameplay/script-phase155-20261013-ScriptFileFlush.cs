// Complete CRT fileno6F3C74 and flsbuf6EECD9, mutable caller slots and live FILE/descriptor state.
namespace Recovered.Gameplay
{
 public abstract class ScriptFlushServices
 {
  public abstract uint Errno(TakeoverReleaseMemory m);
  public abstract void Invalid(TakeoverReleaseMemory m);
  public abstract uint StandardStreams(TakeoverReleaseMemory m);
  public abstract uint IsTerminal(TakeoverReleaseMemory m,uint descriptor);
  public abstract void Buffer(TakeoverReleaseMemory m,uint file);
  public abstract uint Write(TakeoverReleaseMemory m,uint descriptor,uint bytes,uint count);
  public abstract ulong Seek(TakeoverReleaseMemory m,uint descriptor,uint low,uint high,uint origin);
 }
 public static class PreparedScriptFileFlush
 {
  public static uint FileNumber(TakeoverReleaseMemory m,ScriptFlushServices services,uint file){if(file!=0)return m.Read32(file+0x10);uint error=services.Errno(m);m.Write32(error,22);services.Invalid(m);return 0xffffffff;}
  static uint Error(TakeoverReleaseMemory m,uint file){m.Write32(file+12,m.Read32(file+12)|0x20);return 0xffffffff;}
  // Captures FILE pointer before original function overwrites its caller argument slot with the descriptor.
  public static uint Flush(TakeoverReleaseMemory m,ScriptFlushServices services,uint characterSlot,uint fileSlot)
  {
   uint file=m.Read32(fileSlot),descriptor=FileNumber(m,services,file);m.Write32(fileSlot,descriptor);uint flags=m.Read32(file+12);
   if((flags&0x82)==0){m.Write32(services.Errno(m),9);return Error(m,file);}if((flags&0x40)!=0){m.Write32(services.Errno(m),34);return Error(m,file);}
   if((flags&1)!=0){m.Write32(file+4,0);if((flags&0x10)==0){m.Write32(file+12,flags|0x20);return 0xffffffff;}m.Write32(file,m.Read32(file+8));m.Write32(file+12,flags&0xfffffffe);}
   flags=(m.Read32(file+12)&0xffffffef)|2;m.Write32(file+12,flags);m.Write32(file+4,0);uint written=0,amount;
   if((flags&0x10c)==0){bool standard=file==unchecked(services.StandardStreams(m)+0x20);if(!standard)standard=file==unchecked(services.StandardStreams(m)+0x40);if(!standard||services.IsTerminal(m,m.Read32(fileSlot))==0)services.Buffer(m,file);}
   if((m.Read16(file+12)&0x108)!=0)
   {
    uint basePointer=m.Read32(file+8);amount=unchecked(m.Read32(file)-basePointer);m.Write32(file,unchecked(basePointer+1));m.Write32(file+4,unchecked(m.Read32(file+0x18)-1));
    if(unchecked((int)amount)>0)written=services.Write(m,m.Read32(fileSlot),basePointer,amount);
    else{descriptor=m.Read32(fileSlot);uint row;if(descriptor==0xffffffff||descriptor==0xfffffffe)row=0x829c00;else row=unchecked(m.Read32(unchecked(0x29a9b40+(uint)(unchecked((int)descriptor)>>5)*4))+(descriptor&31)*0x38);if((m.Read8(row+4)&0x20)!=0&&services.Seek(m,descriptor,0,0,2)==0xffffffffffffffffUL)return Error(m,file);}
    m.Write8(m.Read32(file+8),m.Read8(characterSlot));
   }
   else{amount=1;written=services.Write(m,m.Read32(fileSlot),characterSlot,1);}
   if(written!=amount)return Error(m,file);return m.Read32(characterSlot)&0xff;
  }
 }
}
