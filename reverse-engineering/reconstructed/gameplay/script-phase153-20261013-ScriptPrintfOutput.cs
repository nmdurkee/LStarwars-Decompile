// Complete printf byte, repeated-byte and byte-span output helpers with original register/slot ABI.
namespace Recovered.Gameplay
{
 public static class PreparedScriptPrintfOutput
 {
  // 6EEE39: ECX=file, ESI=counter, AL=byte; upperEAX survives count-only stream branch.
  public static uint Byte(TakeoverReleaseMemory m,ScriptPrintfServices services,uint file,uint counter,uint eax)
  {
   if((m.Read8(file+12)&0x40)!=0&&m.Read32(file+8)==0){m.Write32(counter,unchecked(m.Read32(counter)+1));return eax;}
   uint count=unchecked(m.Read32(file+4)-1);m.Write32(file+4,count);if(unchecked((int)count)>=0){m.Write8(m.Read32(file),(byte)eax);m.Write32(file,unchecked(m.Read32(file)+1));eax=(byte)eax;}else eax=services.Flush(m,unchecked((uint)(int)(sbyte)(byte)eax),file);
   if(eax==0xffffffff)m.Write32(counter,m.Read32(counter)|eax);else m.Write32(counter,unchecked(m.Read32(counter)+1));return eax;
  }
  // 6EEE6C: EAX=counter; threecdecl argument slots character,count,file are read/written live.
  public static uint Repeat(TakeoverReleaseMemory m,ScriptPrintfServices services,uint counter,uint characterSlot,uint countSlot,uint fileSlot)
  {
   uint eax=counter;while(unchecked((int)m.Read32(countSlot))>0){uint file=m.Read32(fileSlot);eax=(eax&0xffffff00)|m.Read8(characterSlot);m.Write32(countSlot,unchecked(m.Read32(countSlot)-1));eax=Byte(m,services,file,counter,eax);if(m.Read32(counter)==0xffffffff)break;}return eax;
  }
  // 6EEE90: EAX=counter, ECX=source, EDI=file; mutable cdecl count slot.
  public static uint Span(TakeoverReleaseMemory m,ScriptPrintfServices services,uint counter,uint source,uint file,uint countSlot)
  {
   uint eax=counter;if((m.Read8(file+12)&0x40)!=0&&m.Read32(file+8)==0){eax=m.Read32(countSlot);m.Write32(counter,unchecked(m.Read32(counter)+eax));return eax;}
   while(unchecked((int)m.Read32(countSlot))>0){eax=(eax&0xffffff00)|m.Read8(source);m.Write32(countSlot,unchecked(m.Read32(countSlot)-1));eax=Byte(m,services,file,counter,eax);source=unchecked(source+1);if(m.Read32(counter)==0xffffffff){eax=services.Errno(m);if(m.Read32(eax)!=42)break;eax=Byte(m,services,file,counter,(eax&0xffffff00)|0x3f);}}
   return eax;
  }
 }
}
