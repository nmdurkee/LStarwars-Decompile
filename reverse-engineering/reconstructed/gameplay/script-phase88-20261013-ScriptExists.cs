// Existence query saves the global archive-search flag, checks container metadata, or opens/closes a file.
namespace Recovered.Gameplay
{
 public abstract class ScriptExistsServices
 {
  public abstract uint Find(TakeoverReleaseMemory m,uint container,uint path);
  public abstract uint Open(TakeoverReleaseMemory m,uint path,uint mode,uint container,uint reserved);
 }
 public static class PreparedScriptExists
 {
  //4fa610 cdecl(path), returning container row size or Boolean fallback.
  public static uint Exists(TakeoverReleaseMemory m,ScriptExistsServices files,ScriptCloseServices close,uint path)
  {
   if(path==0||m.Read8(path)==0)return 0;uint saved=m.Read32(0x91ee90),container=m.Read32(0x91ee88);m.Write32(0x91ee90,0);
   if(container!=0){uint index=files.Find(m,container,path);if(unchecked((int)index)>=0){m.Write32(0x91ee90,saved);return m.Read32(unchecked(m.Read32(container+8)+(index<<4)+8));}}
   uint handle=files.Open(m,path,0,container,1);if(handle!=0)PreparedScriptCloseDispatch.Close(m,close,handle);m.Write32(0x91ee90,saved);return handle!=0?1u:0u;
  }
  //4ff120 tail jump, same caller ABI.
  public static uint Transport(TakeoverReleaseMemory m,ScriptExistsServices files,ScriptCloseServices close,uint path){return Exists(m,files,close,path);}
 }
}
