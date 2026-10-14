// Fixed four-parser pool, BOM attachment, marker-only free, file close and filesystem parser constructor.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptParserAllocationServices
 {
  //4fb550 into zeroed compilerlocal two-byte word, partial/failedreads normalize surviving low16bits.
  public abstract ushort Prefix(TakeoverReleaseMemory m,uint handle);
  public abstract uint Byte(TakeoverReleaseMemory m,uint handle);
  public abstract void Seek(TakeoverReleaseMemory m,uint handle,uint low,uint high,uint origin);
  public abstract uint Size(TakeoverReleaseMemory m,uint handle);
  public abstract uint Exists(TakeoverReleaseMemory m,uint path);
  public abstract uint Open(TakeoverReleaseMemory m,uint path,uint mode,uint options,uint reserved);
  public abstract void Close(TakeoverReleaseMemory m,uint handle);
 }
 public static class PreparedScriptParserAllocation
 {
  static void Zero(TakeoverReleaseMemory m,uint p,uint size){for(uint i=0;i<size;i++)m.Write8(p+i,0);}
  public static uint Allocate(TakeoverReleaseMemory m){uint first=m.Read32(0x91eebc);if(first==0){first=0x917850;m.Write32(0x91eebc,first);Zero(m,first,0x1610);m.Write32(0x91eec0,0x8cab50);}for(uint i=0;i<4;i++){uint p=first+i*0x584;if(m.Read32(p)==0){Zero(m,p,0x584);uint buffer=unchecked(m.Read32(0x91eec0)+i*0x1000);m.Write32(p,buffer);Zero(m,buffer,0x1000);return p;}}return 0;}
  public static uint Attach(TakeoverReleaseMemory m,ScriptParserAllocationServices s,uint handle){uint p=Allocate(m);if(p==0)return 0;m.Write32(p+0x52c,0xffffffff);m.Write32(p+0x51c,0xffffffff);m.Write32(p+0x570,0xffffffff);m.Write32(p+0x50c,p+0x108);m.Write32(p+4,handle);m.Write32(p+0x57c,0);m.Write32(p+0x580,0);m.Write32(p+0x510,p+0x30a);m.Write32(p+0x514,0x200);m.Write32(p+0x518,0x200);ushort prefix=s.Prefix(m,handle);m.Write8(p+0x578,0);m.Write8(p+0x579,0);if(prefix==0xfffe)m.Write8(p+0x578,2);else if(prefix==0xfeff)m.Write8(p+0x578,1);else if(prefix==0xbbef){if((byte)s.Byte(m,handle)==0xbf)m.Write8(p+0x579,1);}else if(prefix==0xefbb){if((byte)s.Byte(m,handle)==0xbf)m.Write8(p+0x579,2);}if(m.Read8(p+0x578)==0&&m.Read8(p+0x579)==0)s.Seek(m,handle,0,0,0);uint size=s.Size(m,handle);m.Write32(p+0x574,size);return p;}
  public static void Free(TakeoverReleaseMemory m,uint parser){m.Write32(parser,0);}
  public static void Close(TakeoverReleaseMemory m,ScriptParserAllocationServices s,uint parser){m.Write32(parser,0);uint handle=m.Read32(parser+4);s.Close(m,handle);}
  public static uint OpenFile(TakeoverReleaseMemory m,ScriptParserAllocationServices s,uint path){if(s.Exists(m,path)==0)return 0;uint handle=s.Open(m,path,0,m.Read32(0x91ee88),0);if(handle==0)return 0;uint parser=Attach(m,s,handle);if(parser==0){s.Close(m,handle);return 0;}for(uint i=0;i<256;i++){byte c=m.Read8(path+i);m.Write8(parser+8+i,c);if(c==0)return parser;}throw new ArgumentException("Native256-byte parser filename backing required.");}
 }
}
