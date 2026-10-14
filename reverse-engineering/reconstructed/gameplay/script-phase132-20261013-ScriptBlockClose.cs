// Complete original block-close body on bounded memory and release CRT handles.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptBlockClose
 {
  static ulong Quad(TakeoverReleaseMemory m,uint p){return m.Read32(p)|((ulong)m.Read32(p+4)<<32);}
  static uint Write(ConditionParserMemory m,uint h,uint source,uint count){return h>=0x1000?RecoveredActualReleaseCrtEndpoints.Write(h-0x1000,source,count,0):RecoveredScriptMemoryWrite.Write(m,h,source,count);}
  static void LocalWrite(ConditionParserMemory m,uint h,uint privateLocal,char[] bytes,uint count){ScriptCompilerLocals.CString(m,privateLocal,new string(bytes),delegate(uint p){return Write(m,h,p,count);});}
  //4f6f60 decrements global block depth, rounds signed low32 payload length, patches length atbegin+4,
  //then restores adjusted current position. Alignments1..12; memory padding<=11 preserves zero/current locals.
  public static ulong Close(ConditionParserMemory m,uint handle,uint privateLocal){uint depth=m.Read32(0x800468);int alignment=unchecked((int)m.Read32(0x80046c));bool crt=unchecked((int)handle)>=0x1000;if(depth<1||depth>64||alignment<1||alignment>12||(!crt&&(handle<0x400||handle>=0x414)))throw new ArgumentException("Prepared block stack, alignment and memory/CRT handle required.");depth--;m.Write32(0x800468,depth);uint record=0x918e60+depth*16;ulong current=RecoveredScriptFilePosition.Public(m,null,handle),begin=Quad(m,record+8);int length=unchecked((int)((uint)current-(uint)begin)),pad=alignment-length%alignment;if(!crt&&(length<0||(uint)(begin>>32)!=0))throw new ArgumentException("Prepared nonnegative memory block length required.");if(pad!=alignment){current=unchecked(current+(ulong)(long)pad);length=unchecked(length+pad);if(crt)Write(m,handle,0,(uint)pad);else{char[] bytes=new char[12];for(int i=4;i<12;i++)bytes[i]=(char)((current>>((i-4)*8))&255);LocalWrite(m,handle,privateLocal,bytes,(uint)pad);}}if(unchecked((int)m.Read32(record+4))<0)length=unchecked(-length);ulong patch=unchecked(begin+4);ScriptRemainingSeekServices seek=new RecoveredActualReleaseCrtSeekServices(null);PreparedScriptSeekDispatch.Seek(m,null,seek,handle,(uint)patch,(uint)(patch>>32),0);char[] header=new char[4];for(int i=0;i<4;i++)header[i]=(char)((length>>(i*8))&255);LocalWrite(m,handle,privateLocal,header,4);return PreparedScriptSeekDispatch.Seek(m,null,seek,handle,(uint)current,(uint)(current>>32),0);}
 }
}
