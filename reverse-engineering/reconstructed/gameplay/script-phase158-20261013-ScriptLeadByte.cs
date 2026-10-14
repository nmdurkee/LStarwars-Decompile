// Complete __isleadbyte_l6FC0EE with actual locale constructor and owned-thread cleanup.
namespace Recovered.Gameplay
{
 public static class PreparedScriptLeadByte
 {
  public static uint Test(TakeoverReleaseMemory m,ScriptLocaleUpdateServices services,uint characterSlot,uint localeSlot,uint context)
  {
   PreparedScriptLocaleUpdate.Construct(m,services,context,m.Read32(localeSlot));uint table=m.Read32(m.Read32(context)+0xc8);uint result=(uint)(m.Read16(table+(uint)m.Read8(characterSlot)*2)&0x8000);if(m.Read8(context+12)!=0){uint thread=m.Read32(context+8);m.Write32(thread+0x70,m.Read32(thread+0x70)&0xfffffffd);}return result;
  }
 }
}
