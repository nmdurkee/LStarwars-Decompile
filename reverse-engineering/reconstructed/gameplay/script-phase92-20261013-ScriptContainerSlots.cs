// Container record/parent allocation, critical-section ID routing, lazy parent open and signed base offsets.
namespace Recovered.Gameplay
{
 public abstract class ScriptContainerSlotServices
 {
  public abstract void EnterCriticalSection(TakeoverReleaseMemory m,uint section);
  public abstract void LeaveCriticalSection(TakeoverReleaseMemory m,uint section);
  public abstract uint Open(TakeoverReleaseMemory m,uint path,uint mode,uint container,uint reserved);
 }
 public static class PreparedScriptContainerSlots
 {
  //4ffaa0/4ffac0 cdecl(id); invalid IDs are no-ops, valid1..12 use indexed24-byte Win32 object.
  public static void Enter(TakeoverReleaseMemory m,ScriptContainerSlotServices io,uint id){if(unchecked(id-1)<=11)io.EnterCriticalSection(m,unchecked(0x91ef70+id*24));}
  public static void Leave(TakeoverReleaseMemory m,ScriptContainerSlotServices io,uint id){if(unchecked(id-1)<=11)io.LeaveCriticalSection(m,unchecked(0x91ef70+id*24));}
  //4f0bd0 no arguments. Claim first empty+24 marker among20 compressed48-byte records.
  public static uint Record(TakeoverReleaseMemory m,ScriptContainerSlotServices io)
  {Enter(m,io,m.Read32(0x88ab48));uint selected=0xffffffff;for(uint i=0;i<20;i++)if(m.Read32(0x297dc84+i*48)==0){selected=i;m.Write32(0x297dc84+i*48,1);break;}Leave(m,io,m.Read32(0x88ab48));return selected;}
  //4f0c40 cdecl(container,recordIndex). Claim first exactFFFFFFFF of8 parent markers.
  public static uint Parent(TakeoverReleaseMemory m,ScriptContainerSlotServices io,uint container,uint recordIndex)
  {Enter(m,io,m.Read32(0x88ab48));uint selected=0xffffffff;for(uint i=0;i<8;i++)if(m.Read32(container+0x34+i*16)==0xffffffff){selected=i;m.Write32(container+0x34+i*16,recordIndex);break;}Leave(m,io,m.Read32(0x88ab48));return selected;}
  //4f0cb0 customEAX=container,ECX=parentIndex; existing nonzero handle avoids open and position writes.
  public static uint EnsureParent(TakeoverReleaseMemory m,ScriptContainerSlotServices io,uint container,uint index)
  {uint parent=unchecked(container+((index+3)<<4)),handle=m.Read32(parent);if(handle!=0)return handle;uint mode=unchecked((uint)(int)(short)(m.Read8(container+0xb2)|(m.Read8(container+0xb3)<<8))),path=m.Read32(container+0xb8);handle=io.Open(m,path,mode,0,0);m.Write32(parent,handle);m.Write32(parent+8,0);m.Write32(parent+12,0);return handle;}
  //4f0a80 cdecl(container,entryOffset), EDX:EAX. Markers<=-2 use256-byte units, plus signed global base.
  public static ulong Offset(TakeoverReleaseMemory m,uint container,uint offset)
  {ulong value=unchecked((ulong)(long)(int)offset);if(unchecked((int)m.Read32(container))<=-2)value=unchecked(value<<8);return unchecked(value+(ulong)(long)(int)m.Read32(0x91ee9c));}
 }
}
