// Complete _LocaleUpdate constructor6EB53D, thiscall ECXobject/one argument/RET4, live locale state.
namespace Recovered.Gameplay
{
 public abstract class ScriptLocaleUpdateServices
 {
  public abstract uint Thread(TakeoverReleaseMemory m);
  public abstract uint Locale(TakeoverReleaseMemory m);
  public abstract uint Multibyte(TakeoverReleaseMemory m);
 }
 public static class PreparedScriptLocaleUpdate
 {
  public static uint Construct(TakeoverReleaseMemory m,ScriptLocaleUpdateServices services,uint instance,uint locale)
  {
   m.Write8(instance+12,0);
   if(locale!=0){m.Write32(instance,m.Read32(locale));m.Write32(instance+4,m.Read32(locale+4));return instance;}
   uint thread=services.Thread(m);m.Write32(instance+8,thread);m.Write32(instance,m.Read32(thread+0x6c));m.Write32(instance+4,m.Read32(thread+0x68));
   if(m.Read32(instance)!=m.Read32(0x82a678)&&(m.Read32(thread+0x70)&m.Read32(0x82a594))==0)m.Write32(instance,services.Locale(m));
   if(m.Read32(instance+4)!=m.Read32(0x82a498)&&(m.Read32(m.Read32(instance+8)+0x70)&m.Read32(0x82a594))==0)m.Write32(instance+4,services.Multibyte(m));
   thread=m.Read32(instance+8);if((m.Read8(thread+0x70)&2)==0){m.Write32(thread+0x70,m.Read32(thread+0x70)|2);m.Write8(instance+12,1);}return instance;
  }
 }
}
