// Complete tolower7014A5 and isdigit700F70 own bodies, raw32-bit arguments and locale-mode dispatch.
namespace Recovered.Gameplay
{
 public abstract class ScriptCtypeServices
 {public abstract uint LocaleLower(TakeoverReleaseMemory m,uint character,uint locale);public abstract uint LocaleDigit(TakeoverReleaseMemory m,uint character,uint locale);}
 public static class PreparedScriptCtype
 {
  public static uint Lower(TakeoverReleaseMemory m,ScriptCtypeServices s,uint character)
  {if(m.Read32(0x297cb10)!=0)return s.LocaleLower(m,character,0);return unchecked(character-65)<=25?unchecked(character+32):character;}
  public static uint Digit(TakeoverReleaseMemory m,ScriptCtypeServices s,uint character)
  {if(m.Read32(0x297cb10)!=0)return s.LocaleDigit(m,character,0);return(uint)(m.Read8(unchecked(m.Read32(0x82a668)+character*2))&4);}
 }
}
