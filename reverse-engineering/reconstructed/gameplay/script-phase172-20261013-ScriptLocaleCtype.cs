// Complete locale-aware tolower_l70138E and isdigit_l700F21; original packed multibyte and caller-slot effects.
namespace Recovered.Gameplay
{
 public abstract class ScriptLocaleCtypeServices:ScriptLocaleUpdateServices
 {
  public abstract uint Errno(TakeoverReleaseMemory m);public abstract uint Classify(TakeoverReleaseMemory m,uint character,uint mask,uint locale);
  public abstract uint Map(TakeoverReleaseMemory m,uint locale,uint language,uint flags,uint input,uint inputCount,uint output,uint capacity,uint codepage,uint strict);
 }
 public static class PreparedScriptLocaleCtype
 {
  static void Cleanup(TakeoverReleaseMemory m,uint context){if(m.Read8(context+12)!=0){uint t=m.Read32(context+8);m.Write32(t+0x70,m.Read32(t+0x70)&0xfffffffd);}}
  public static uint Digit(TakeoverReleaseMemory m,ScriptLocaleCtypeServices s,uint characterSlot,uint localeSlot,uint frame)
  {uint context=frame-0x10;PreparedScriptLocaleUpdate.Construct(m,s,context,m.Read32(localeSlot));uint locale=m.Read32(context),value;if(unchecked((int)m.Read32(locale+0xac))<=1)value=(uint)(m.Read8(unchecked(m.Read32(locale+0xc8)+m.Read32(characterSlot)*2))&4);else value=s.Classify(m,m.Read32(characterSlot),4,context);Cleanup(m,context);return value;}
  public static uint Lower(TakeoverReleaseMemory m,ScriptLocaleCtypeServices s,uint characterSlot,uint localeSlot,uint frame)
  {
   uint context=frame-0x18;PreparedScriptLocaleUpdate.Construct(m,s,context,m.Read32(localeSlot));uint character=m.Read32(characterSlot),locale=m.Read32(context),value=character;
   if(character<256)
   {
    uint classification;if(unchecked((int)m.Read32(locale+0xac))<=1)classification=(uint)(m.Read8(m.Read32(locale+0xc8)+character*2)&1);else{classification=s.Classify(m,character,1,context);locale=m.Read32(context);}if(classification!=0)value=m.Read8(m.Read32(locale+0xcc)+character);
   }
   else
   {
    uint input=frame-4,output=frame-8,count=1;bool lead=false;if(unchecked((int)m.Read32(locale+0xac))>1){m.Write32(characterSlot,unchecked((uint)(unchecked((int)character)>>8)));m.Write32(frame-0x28,m.Read32(characterSlot)&255);m.Write32(frame-0x24,context);lead=PreparedScriptLeadByte.Test(m,s,frame-0x28,frame-0x24,frame-0x40)!=0;}
    if(lead){m.Write8(input,m.Read8(characterSlot));m.Write8(input+1,(byte)character);m.Write8(input+2,0);count=2;}else{m.Write32(s.Errno(m),42);m.Write8(input,(byte)character);m.Write8(input+1,0);}
    locale=m.Read32(context);uint mapped=s.Map(m,context,m.Read32(locale+0x14),0x100,input,count,output,3,m.Read32(locale+4),1);if(mapped==1)value=m.Read8(output);else if(mapped!=0)value=((uint)m.Read8(output)<<8)|m.Read8(output+1);
   }
   Cleanup(m,context);return value;
  }
 }
}
