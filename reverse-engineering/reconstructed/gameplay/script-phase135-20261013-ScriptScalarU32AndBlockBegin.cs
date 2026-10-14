// Original U32 scalar writer and entire raw-entry block begin.
using System;
namespace Recovered.Gameplay
{
 public static class RecoveredScriptScalarU32Write
 {
  //4f04b0: every nonzero91eea0 selects reverse byte order; each invocation reloads flag.
  public static uint Write(ConditionParserMemory m,ScriptWriteHostServices host,uint h,uint value,uint privateLocal){bool crt=unchecked((int)h)>=0x1000;if(!crt&&!((h>=1&&h<=64)||(h>=0x400&&h<0x414)))throw new ArgumentException("Prepared stream/memory/CRT handle required.");bool reverse=m.Read32(0x91eea0)!=0;char[] bytes=new char[4];for(int i=0;i<4;i++)bytes[i]=(char)((value>>((reverse?3-i:i)*8))&255);return ScriptCompilerLocals.CString(m,privateLocal,new string(bytes),delegate(uint p){if(crt)return RecoveredActualReleaseCrtEndpoints.Write(h-0x1000,p,4,0);if(h>=0x400)return RecoveredScriptMemoryWrite.Write(m,h,p,4);return RecoveredScriptStreamWrite.Write(m,host,h-1,p,4);});}
 }
 public static class RecoveredScriptBlockBegin
 {
  //Unregistered4f6f00 whole94byteentry,0extra credit. Both emittedDWORDs are the same tag.
  //The second is later replaced by block-close's little-endian length, regardless of91eea0.
  public static uint Begin(ConditionParserMemory m,ScriptHostFileServices seekHost,ScriptWriteHostServices writeHost,uint h,uint tag,uint flag,uint privateLocal){uint index=m.Read32(0x800468);if(index>=64)throw new ArgumentException("Prepared sixty-four-block backing required.");m.Write32(0x800468,index+1);ulong position=RecoveredScriptFilePosition.Public(m,seekHost,h);uint record=0x918e60+index*16;m.Write32(record+8,(uint)position);m.Write32(record+12,(uint)(position>>32));m.Write32(record,tag);m.Write32(record+4,flag==1?0xffffffff:1);RecoveredScriptScalarU32Write.Write(m,writeHost,h,tag,privateLocal);return RecoveredScriptScalarU32Write.Write(m,writeHost,h,tag,privateLocal);}
 }
}
