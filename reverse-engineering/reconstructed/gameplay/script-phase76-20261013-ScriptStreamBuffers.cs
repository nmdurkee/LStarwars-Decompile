// Original stream wrappers and signed-stamp four-buffer assignment; final Win32 API values remain explicit.
namespace Recovered.Gameplay
{
 public abstract class ScriptHostFileServices
 {
  //Outputs reflect the surviving zero-initialized native local when API does not write it.
  public abstract uint ReadFile(TakeoverReleaseMemory m,uint handle,uint destination,uint count,uint overlapped,out uint numberRead);
  public abstract uint SetFilePointerEx(TakeoverReleaseMemory m,uint handle,uint low,uint high,uint origin,out ulong position);
 }
 public static class PreparedScriptStreamFiles
 {
  //4ff3b0 cdecl(index,destination,count). ReadFile Boolean return is ignored; initialized byte count survives.
  public static uint Read(TakeoverReleaseMemory m,ScriptHostFileServices io,uint index,uint destination,uint count)
  {uint handle=m.Read32(unchecked(0x8007a0+(index<<2))),number;io.ReadFile(m,handle,destination,count,0,out number);return number;}
  //4ff430 cdecl(index,offsetLo,offsetHi,origin), EDX:EAX position; origins other than0/1 mapto2.
  public static ulong Seek(TakeoverReleaseMemory m,ScriptHostFileServices io,uint index,uint low,uint high,uint origin)
  {uint mode=origin==0?0u:origin==1?1u:2u,handle=m.Read32(unchecked(0x8007a0+(index<<2)));ulong position;uint success=io.SetFilePointerEx(m,handle,low,high,mode,out position);return success!=0?position:ulong.MaxValue;}
 }
 public static class PreparedScriptStreamBuffers
 {
  //4f0230 customEDI=stream, no stackargs; stamps compared signed and strictly below globalcounter/defaultbuffer0.
  public static uint Acquire(TakeoverReleaseMemory m,ScriptHostFileServices io,uint stream)
  {
   uint counter=m.Read32(0x91ee8c),minimum=counter,index=0;
   for(uint i=0;i<4;i++){uint stamp=m.Read32(0x915fb0+i*0x408+4);if(unchecked((int)stamp)<unchecked((int)minimum)){minimum=stamp;index=i;}}
   uint selected=0x915fb0+index*0x408,owner=m.Read32(selected);
   if(owner!=0)m.Write32(unchecked(owner+0x38),0);
   m.Write32(selected+4,counter);m.Write32(selected,stream);
   uint cached=m.Read32(unchecked(stream+0x28));m.Write32(0x91ee8c,unchecked(counter+1));m.Write32(unchecked(stream+0x38),selected);
   if(cached==0)return 0;
   uint negative=unchecked(0u-cached);
   PreparedScriptStreamFiles.Seek(m,io,m.Read32(stream),negative,unchecked((int)negative)<0?uint.MaxValue:0,1);
   return PreparedScriptStreamFiles.Read(m,io,m.Read32(stream),selected+8,m.Read32(unchecked(stream+0x28)));
  }
 }
}
