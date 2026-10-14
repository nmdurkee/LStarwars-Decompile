// Win32 stream handle allocation, including native full-table write to preceding word.
namespace Recovered.Gameplay
{
 public abstract class ScriptOpenHostServices
 {
  public abstract uint CreateFile(TakeoverReleaseMemory m,uint path,uint access,uint share,uint security,uint disposition,uint flags,uint template);
 }
 public static class PreparedScriptStreamOpen
 {
  //4ff2f0 cdecl(path,mode). Full64slot table still calls CreateFile and writes table[-1].
  public static uint Open(TakeoverReleaseMemory m,ScriptOpenHostServices host,uint path,uint mode)
  {
   uint access=0,disposition=0;if(mode==0){access=0x80000000;disposition=3;}else if(mode==1){access=0x40000000;disposition=2;}else if(mode==2){access=0x40000000;disposition=4;}
   uint selected=0xffffffff;for(uint i=0;i<64;i++)if(m.Read32(0x8007a0+i*4)==0xffffffff){selected=i;break;}
   uint value=host.CreateFile(m,path,access,1,0,disposition,0,0);m.Write32(unchecked(0x8007a0+(selected<<2)),value);return value==0xffffffff?value:selected;
  }
 }
}
