// Complete old wctomb local/standard wrappers and current multibyte capacity getter, using actual recovered wide core.
namespace Recovered.Gameplay
{
 public static class PreparedScriptWideWrappers
 {
  public static uint Capacity(TakeoverReleaseMemory m,ScriptLocaleUpdateServices s)
  {uint thread=s.Thread(m),locale=m.Read32(thread+0x6c);if(locale!=m.Read32(0x82a678)&&(m.Read32(thread+0x70)&m.Read32(0x82a594))==0)locale=s.Locale(m);return m.Read32(locale+0xac);}
  static void Cleanup(TakeoverReleaseMemory m,uint context){if(m.Read8(context+12)!=0){uint thread=m.Read32(context+8);m.Write32(thread+0x70,m.Read32(thread+0x70)&0xfffffffd);}}
  // Original caller slots buffer,wchar,locale; frame is ordinary EBP. Child and locale frames are private/disjoint.
  public static uint Local(TakeoverReleaseMemory m,ScriptWideCharacterServices s,uint caller,uint frame)
  {
   uint locale=m.Read32(caller+8),result=frame-4,context=frame-0x14,child=frame-0x28;m.Write32(result,0xffffffff);PreparedScriptLocaleUpdate.Construct(m,s,context,locale);
   m.Write32(child+16,context);m.Write32(child+12,m.Read32(caller+4));m.Write32(child+8,m.Read32(m.Read32(context)+0xac));m.Write32(child+4,m.Read32(caller));m.Write32(child,result);uint status=PreparedScriptWideCharacter.Local(m,s,child,frame-0x40),value=status==0?m.Read32(result):0xffffffff;Cleanup(m,context);return value;
  }
  // wchar is captured before capacity getter, buffer read after it, matching original push order.
  public static uint Standard(TakeoverReleaseMemory m,ScriptWideCharacterServices s,uint caller,uint frame)
  {
   uint result=frame-4,child=frame-0x18;m.Write32(result,0xffffffff);m.Write32(child+16,0);m.Write32(child+12,m.Read32(caller+4));uint size=Capacity(m,s);m.Write32(child+8,size);m.Write32(child+4,m.Read32(caller));m.Write32(child,result);uint status=PreparedScriptWideCharacter.Local(m,s,child,frame-0x30);return status==0?m.Read32(result):0xffffffff;
  }
 }
}
