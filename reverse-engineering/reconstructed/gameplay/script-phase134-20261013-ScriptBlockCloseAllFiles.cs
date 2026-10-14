// Complete block-close for raw/buffered Win32, memory and release CRT domains; exact live record reloads.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptBlockCloseAllFiles
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(p+4)<<32);}
  static uint Write(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint source,uint count){if(unchecked((int)h)>=0x1000)return RecoveredActualReleaseCrtEndpoints.Write(h-0x1000,source,count,0);if(h>=0x400)return RecoveredScriptMemoryWrite.Write(m,h,source,count);return RecoveredScriptStreamWrite.Write(m,host,h-1,source,count);}
  static void LocalWrite(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint local,char[] bytes,uint count){ScriptCompilerLocals.CString(m,local,new string(bytes),delegate(uint source){return Write(m,host,h,source,count);});}
  //Same4f6f60 body, refinement0credit. File backing may alias the global block record.
  //Alignment/length read after position; marker/begin read again after padding callbacks/copies.
  public static ulong Close(ConditionParserMemory m,ScriptHostFileServices seekHost,ScriptWriteHostServices writeHost,uint h,uint privateLocal){uint depth=m.Read32(0x800468);bool crt=unchecked((int)h)>=0x1000;if(depth<1||depth>64||(!crt&&!((h>=1&&h<=64)||(h>=0x400&&h<0x414))))throw new ArgumentException("Prepared block stack and stream/memory/CRT handle required.");depth--;m.Write32(0x800468,depth);uint record=0x918e60+depth*16;ulong current=RecoveredScriptFilePosition.Public(m,seekHost,h);int alignment=unchecked((int)m.Read32(0x80046c)),length=unchecked((int)((uint)current-m.Read32(record+8)));if(alignment<1||alignment>12||(!crt&&length<0))throw new ArgumentException("Prepared bounded alignment/nonnegative payload required.");int pad=alignment-length%alignment;if(pad!=alignment){current=unchecked(current+(ulong)(long)pad);length=unchecked(length+pad);if(crt)Write(m,writeHost,h,0,(uint)pad);else{char[] bytes=new char[12];for(int i=4;i<12;i++)bytes[i]=(char)((current>>((i-4)*8))&255);LocalWrite(m,writeHost,h,privateLocal,bytes,(uint)pad);}}if(unchecked((int)m.Read32(record+4))<0)length=unchecked(-length);ulong patch=unchecked(Quad(m,record+8)+4);ScriptRemainingSeekServices remaining=new RecoveredActualReleaseCrtSeekServices(null);PreparedScriptSeekDispatch.Seek(m,seekHost,remaining,h,(uint)patch,(uint)(patch>>32),0);char[] header=new char[4];for(int i=0;i<4;i++)header[i]=(char)((length>>(i*8))&255);LocalWrite(m,writeHost,h,privateLocal,header,4);return PreparedScriptSeekDispatch.Seek(m,seekHost,remaining,h,(uint)current,(uint)(current>>32),0);}
 }
}
