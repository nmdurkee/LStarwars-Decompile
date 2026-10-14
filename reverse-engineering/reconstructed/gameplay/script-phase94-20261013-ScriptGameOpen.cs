// Game file open with provider formatting, container lookup, CRT/Win32 handles and size/buffering setup.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptGameOpenServices:ScriptContainerOpenServices
 {
  public abstract void Format(TakeoverReleaseMemory m,uint callback,uint provider,uint destination,uint path,uint capacity);
  public abstract uint CrtOpen(TakeoverReleaseMemory m,uint first,uint second,uint path,uint mode,uint reserved);
 }
 public static class PreparedScriptFilePoll
 {
  //4f01f0: signed h>=400 exits; h<400 then h<800 exits. The remaining graph is unreachable for all32-bit arguments.
  public static uint Poll(TakeoverReleaseMemory m,uint handle){return 0;}
 }
 public static class PreparedScriptGameOpen
 {
  static ulong Seek(ConditionParserMemory m,ScriptGameOpenServices io,ScriptHostFileServices host,ScriptRemainingSeekServices remaining,uint handle,uint origin,uint quiet)
  {for(uint budget=0;budget<1024;budget++){ulong result=PreparedScriptSeekDispatch.Seek(m,host,remaining,handle,0,0,origin);if(unchecked((int)(result>>32))>=0)return result;if(quiet==0)io.Diagnostic(m,new uint[0]);}throw new ArgumentException("Prepared progressing file seek required.");}
  //4fa3f0 cdecl(path,mode,container,quietDiagnostics), unaliased private256-byte formatted filename.
  public static uint Open(ConditionParserMemory m,ScriptGameOpenServices io,ScriptOpenHostServices openHost,ScriptHostFileServices seekHost,ScriptRemainingSeekServices seeks,uint path,uint mode,uint container,uint quiet,uint privateName)
  {
   uint provider=PreparedScriptContainerIndex.Provider(m,path);
   if(provider==0){if(container!=0&&mode!=1&&mode!=2){uint handle=PreparedScriptContainerOpen.Open(m,io,seekHost,seeks,container,path,mode,privateName);if(handle!=0)return handle;}provider=m.Read32(0x800478);}
   uint selected=provider;
   return ScriptCompilerLocals.CString(m,privateName,new string('\0',255),delegate(uint filename){
    io.Format(m,m.Read32(selected+0x22c),selected,filename,path,256);
    if(m.Read32(selected)==2){uint end=filename;while(m.Read8(end)!=0)end++;uint suffix=0x75ebd8;byte c;do{c=m.Read8(suffix++);m.Write8(end++,c);}while(c!=0);}
    if(m.Read32(selected)==1){uint first=unchecked((uint)((int)(sbyte)m.Read8(filename+2)-48)),second=unchecked((uint)((int)(sbyte)m.Read8(filename+3)-48));uint value=io.CrtOpen(m,first,second,unchecked(filename+m.Read32(selected+0x48)),mode,0);return unchecked((int)value)>=0?unchecked(value+0x1000):0;}
    uint index=PreparedScriptStreamOpen.Open(m,openHost,filename,mode);if(unchecked((int)index)<0)return 0;uint stream=unchecked(0x8ceb50+(index<<6));for(uint i=0;i<64;i++)m.Write8(stream+i,0);m.Write32(stream,index);m.Write32(stream+0x34,mode);uint handleValue=unchecked(index+1);
    if(mode==1){m.Write32(stream+0x18,0);m.Write32(stream+0x1c,0);return handleValue;}
    if(unchecked((int)index)<=16){ulong size=Seek(m,io,seekHost,seeks,handleValue,2,quiet);m.Write32(stream+0x18,(uint)size);m.Write32(stream+0x1c,(uint)(size>>32));if(mode==3)PreparedScriptFilePoll.Poll(m,handleValue);Seek(m,io,seekHost,seeks,handleValue,0,quiet);if(mode==3)PreparedScriptFilePoll.Poll(m,handleValue);}
    if(mode==0)m.Write32(stream+0x2c,m.Read32(0x91ee90));return handleValue;
   });
  }
 }
}
