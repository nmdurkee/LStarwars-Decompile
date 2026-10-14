// Complete locale decimal insertion/cropping helpers; preserves native EAX side effects despite C void prototypes.
namespace Recovered.Gameplay
{
 public abstract class ScriptDecimalFormattingServices:ScriptLocaleUpdateServices
 {public abstract uint Lower(TakeoverReleaseMemory m,uint character);public abstract uint Digit(TakeoverReleaseMemory m,uint character);}
 public static class PreparedScriptDecimalEditing
 {
  static byte Decimal(TakeoverReleaseMemory m,uint locale){return m.Read8(m.Read32(m.Read32(locale+0xbc)));}
  static uint Cleanup(TakeoverReleaseMemory m,uint context,uint eax){if(m.Read8(context+12)!=0){eax=m.Read32(context+8);m.Write32(eax+0x70,m.Read32(eax+0x70)&0xfffffffd);}return eax;}
  static uint Signed(byte v){return unchecked((uint)(int)(sbyte)v);}
  public static uint Force(TakeoverReleaseMemory m,ScriptDecimalFormattingServices s,uint bufferSlot,uint localeSlot,uint context)
  {
   PreparedScriptLocaleUpdate.Construct(m,s,context,m.Read32(localeSlot));uint p=m.Read32(bufferSlot),eax=s.Lower(m,Signed(m.Read8(p)));bool again=eax!=101;while(again){p++;eax=s.Digit(m,m.Read8(p));again=eax!=0;}eax=s.Lower(m,Signed(m.Read8(p)));if(eax==120)p+=2;
   byte carry=m.Read8(p),decimalByte=Decimal(m,m.Read32(context));m.Write8(p,decimalByte);do{p++;byte next=m.Read8(p);m.Write8(p,carry);carry=next;eax=(eax&0xffffff00)|carry;}while(m.Read8(p)!=0);return Cleanup(m,context,eax);
  }
  public static uint Crop(TakeoverReleaseMemory m,ScriptDecimalFormattingServices s,uint bufferSlot,uint localeSlot,uint context)
  {
   PreparedScriptLocaleUpdate.Construct(m,s,context,m.Read32(localeSlot));uint p=m.Read32(bufferSlot),locale=m.Read32(context);byte c=m.Read8(p);if(c!=0){byte decimalByte=Decimal(m,locale);while(c!=decimalByte){p++;c=m.Read8(p);if(c==0)break;}}
   c=m.Read8(p);p++;if(c!=0){while(true){c=m.Read8(p);if(c==0||c==101||c==69)break;p++;}uint tail=p;do{p--;}while(m.Read8(p)==48);if(m.Read8(p)==Decimal(m,locale))p--;do{c=m.Read8(tail);p++;tail++;m.Write8(p,c);}while(c!=0);}return Cleanup(m,context,p);
  }
 }
}
