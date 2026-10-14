// Raw path lookup and binding refinements; original byte counts and sequential writes preserved.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptPathLookup
 {
  // 0x51ad80, cdecl(system, explicitPath, byteName).
  public static uint Find(TakeoverReleaseMemory m,uint system,uint path,uint name)
  {
   if(path==0){if(system==0)return 0;uint r=m.Read32(system+0x10);if(r==0||m.Read8(r)==0)return 0;path=m.Read32(r+8);if(path==0)return 0;}
   if(m.Read8(path+0x10)==0)return 0;uint offset=0;for(uint i=0;;i++,offset+=0x5c){uint text=m.Read32(m.Read32(path+0x7c)+offset);if(text!=0&&PreparedScriptByteLookup.Equal(m,text,name))return unchecked(m.Read32(path+0x7c)+i*0x5c);if(i+1>=m.Read8(path+0x10))return 0;}
  }
  // 0x51a7c0. Void return; path count and masks are read after every preceding write.
  public static void Bind(TakeoverReleaseMemory m,uint actor,uint path)
  {
   if(m.Read32(actor+0x158)==path)return;
   foreach(uint p in new uint[]{0x15c,0x160,0x164,0x168,0x16c})m.Write32(actor+p,0);
   m.Write32(actor+0x158,path);m.Write8(actor+0x161,255);m.Write16(actor+0x13a,0);m.Write16(actor+0x124,65535);m.Write8(actor+0x13c,255);m.Write8(actor+0x13d,0);m.Write32(actor+0x17c,0);
   if(path==0||m.Read8(path+0x14)==0)return;
   for(uint i=0,offset=0;;i++,offset+=0x28){uint rows=m.Read32(path+0x88);if(((m.Read32(rows+offset+0x18)&m.Read32(actor+0x130))|(m.Read32(rows+offset+0x1c)&m.Read32(actor+0x134)))!=0){ushort bit=i<16?(ushort)(1u<<(int)i):(ushort)0;m.Write16(actor+0x13a,(ushort)(m.Read16(actor+0x13a)|bit));}if(i+1>=m.Read8(path+0x14))return;}
  }
 }
}
