// Original file-size taxonomy and allocated-memory seek/close lifecycle.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptFileSizeServices{public abstract uint CrtSize(TakeoverReleaseMemory m,uint descriptor);}
 public static class PreparedScriptFileLifecycle
 {
  const uint Memory=0x2983740,Compressed=0x297dc60;
  static ulong Signed(uint value){return unchecked((ulong)(long)(int)value);}
  static uint Slot(uint handle){if(handle<0x400||handle>=0x414)throw new ArgumentException("Prepared allocated memory-file handle required.");return Memory+(handle-0x400)*20;}
  //4f6b40 cdecl(handle), EDX:EAX size pair. Memory size is inclusiveEnd-base, thus allocationLength-1.
  public static ulong Size(TakeoverReleaseMemory m,ScriptFileSizeServices services,uint handle)
  {
   int h=unchecked((int)handle);
   if(h>=0x1000)return Signed(services.CrtSize(m,handle-0x1000));
   if(h>=0x800){uint slot=unchecked(Compressed+(handle-0x800)*48);return Signed(m.Read32(slot+(m.Read32(slot+40)!=0?28u:24u)));}
   if(h>=0x400){uint slot=unchecked(Memory+(handle-0x400)*20);return Signed(unchecked(m.Read32(slot+4)-m.Read32(slot)));}
   uint address=unchecked(0x8ceb28+(handle<<6));return m.Read32(address)|((ulong)m.Read32(unchecked(address+4))<<32);
  }
  //4f6c70 memory branch cdecl(handle,offsetLo,offsetHi,origin); high ignored, relative result sign-extended.
  public static ulong Seek(TakeoverReleaseMemory m,uint handle,uint low,uint high,uint origin)
  {
   uint slot=Slot(handle),cursor;
   if(origin==1)cursor=unchecked(m.Read32(slot+8)+low);
   else if(origin==2)cursor=unchecked(m.Read32(slot+4)-low);
   else cursor=unchecked(m.Read32(slot)+low);
   m.Write32(slot+8,cursor);return Signed(unchecked(cursor-m.Read32(slot)));
  }
  //4f6bc0 allocated-memory branch clears only live+10 and returns5*index in EAX.
  public static uint Close(TakeoverReleaseMemory m,uint handle){uint slot=Slot(handle);m.Write32(slot+16,0);return (handle-0x400)*5;}
  //Public4f6de0 and4f99e0 memory-handle caller branches delegate these children; no extra entry credit.
  public static ulong SeekTransport(TakeoverReleaseMemory m,uint handle,uint low,uint high,uint origin){return Seek(m,handle,low,high,origin);}
  public static uint CloseTransport(TakeoverReleaseMemory m,uint handle){return Close(m,handle);}
 }
}
