// Byte string primitives, exact in-place parent-path compaction, and catalog open convenience wrapper.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptByteStrings
 {
  //4f1ff0 cdecl(text), no null-pointer special case.
  public static uint Length(TakeoverReleaseMemory m,uint p){uint n=0;while(m.Read8(p+n)!=0){if(n++>=4096)throw new ArgumentException("Prepared bounded byte string required.");}return n;}
  //4f1f10 cdecl(destination,source), returns copied length; null source writes one NUL.
  public static uint Copy(TakeoverReleaseMemory m,uint destination,uint source)
  {uint original=destination,budget=0;byte c=source==0?(byte)0:m.Read8(source);while(c!=0){if(budget++>=4096)throw new ArgumentException("Prepared progressing byte copy required.");source=unchecked(source+1);m.Write8(destination,c);c=m.Read8(source);destination=unchecked(destination+1);}m.Write8(destination,0);return unchecked(destination-original);}
  //4f1e80 cdecl(destination,source), returns end pointer for null source or one past copied NUL.
  public static uint Append(TakeoverReleaseMemory m,uint destination,uint source)
  {uint cursor=unchecked(destination+Length(m,destination));if(source==0)return cursor;uint budget=0;byte c;do{if(budget++>=4096)throw new ArgumentException("Prepared progressing byte append required.");c=m.Read8(source);m.Write8(cursor,c);c=m.Read8(source);cursor=unchecked(cursor+1);source=unchecked(source+1);}while(c!=0);return cursor;}
 }
 public static class PreparedScriptPathCompaction
 {
  //4efec0 cdecl(context,path), returns terminating output pointer. Original live input/output rewrites preserved.
  public static uint Compact(TakeoverReleaseMemory m,uint context,uint path)
  {
   uint input=path,output=path,budget=0;if(m.Read8(path)!=0)
   {
    do
    {
     if(budget++>=4096)throw new ArgumentException("Prepared progressing mapped path required.");byte separator=m.Read8(context+16);
     if(m.Read8(input)==separator&&m.Read8(input+1)==46&&m.Read8(input+2)==46&&m.Read8(input+3)==separator)
     {
      output=input;
      if(input>path)
      {
       while(true){byte c=m.Read8(output-1);output--;if(c==separator){input=unchecked(input+3);break;}if(c==58){output++;input=unchecked(input+4);break;}if(output<=path)break;}
      }
     }
     m.Write8(output,m.Read8(input));input=unchecked(input+1);output=unchecked(output+1);
    }while(m.Read8(input)!=0);
   }
   m.Write8(output,0);return output;
  }
 }
 public static class PreparedScriptCatalogFileOpen
 {
  //4fa5f0 cdecl(path,mode): snapshots current container91ee88, invokes game open withquiet0.
  public static uint Open(ConditionParserMemory m,ScriptGameOpenServices io,ScriptOpenHostServices hostOpen,ScriptHostFileServices hostSeek,ScriptRemainingSeekServices seeks,uint path,uint mode,uint privateName)
  {uint container=m.Read32(0x91ee88);return PreparedScriptGameOpen.Open(m,io,hostOpen,hostSeek,seeks,path,mode,container,0,privateName);}
 }
}
