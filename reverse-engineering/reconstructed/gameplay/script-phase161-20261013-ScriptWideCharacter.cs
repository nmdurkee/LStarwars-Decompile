// Complete wctomb_s701EA2 wrapper and __wctomb_s_l701D43 own body; Windows conversion imports remain services.
namespace Recovered.Gameplay
{
 public abstract class ScriptWideCharacterServices:ScriptLocaleUpdateServices
 {
  public abstract uint Errno(TakeoverReleaseMemory m);public abstract void Invalid(TakeoverReleaseMemory m);
  public abstract void Fill(TakeoverReleaseMemory m,uint buffer,uint capacity);
  public abstract uint Windows(TakeoverReleaseMemory m,uint codepage,uint flags,uint character,uint characters,uint buffer,uint capacity,uint defaultCharacter,uint usedDefault);
  public abstract uint LastError(TakeoverReleaseMemory m);
 }
 public static class PreparedScriptWideCharacter
 {
  static void Cleanup(TakeoverReleaseMemory m,uint context){if(m.Read8(context+12)!=0){uint t=m.Read32(context+8);m.Write32(t+0x70,m.Read32(t+0x70)&0xfffffffd);}}
  static uint Range(TakeoverReleaseMemory m,ScriptWideCharacterServices s,uint context){m.Write32(s.Errno(m),34);s.Invalid(m);Cleanup(m,context);return 34;}
  // Original cdecl five live argument slots result,buffer,capacity,wchar,locale. buffer/capacity are captured before result writes.
  public static uint Local(TakeoverReleaseMemory m,ScriptWideCharacterServices s,uint arguments,uint context)
  {
   uint buffer=m.Read32(arguments+4),capacity=m.Read32(arguments+8),result=m.Read32(arguments);
   if(buffer==0&&capacity!=0){if(result!=0)m.Write32(result,0);return 0;}
   if(result!=0)m.Write32(result,0xffffffff);
   if(capacity>0x7fffffff){m.Write32(s.Errno(m),22);s.Invalid(m);return 22;}
   PreparedScriptLocaleUpdate.Construct(m,s,context,m.Read32(arguments+16));uint locale=m.Read32(context);
   if(m.Read32(locale+0x14)==0)
   {
    ushort character=m.Read16(arguments+12);
    if(character<=255){if(buffer!=0){if(capacity==0)return Range(m,s,context);m.Write8(buffer,(byte)character);}result=m.Read32(arguments);if(result!=0)m.Write32(result,1);Cleanup(m,context);return 0;}
    if(buffer!=0&&capacity!=0)s.Fill(m,buffer,capacity);
   }
   else
   {
    m.Write32(arguments+4,0);uint count=s.Windows(m,m.Read32(locale+4),0,arguments+12,1,buffer,capacity,0,arguments+4);
    if(count==0){if(s.LastError(m)==122){if(buffer!=0&&capacity!=0)s.Fill(m,buffer,capacity);return Range(m,s,context);}}
    else if(m.Read32(arguments+4)==0){result=m.Read32(arguments);if(result!=0)m.Write32(result,count);Cleanup(m,context);return 0;}
   }
   m.Write32(s.Errno(m),42);uint error=m.Read32(s.Errno(m));Cleanup(m,context);return error;
  }
  // Four live caller slots copied right-to-left into disjoint private five-slot child frame; wchar keeps its full original word until child loads16.
  public static uint Standard(TakeoverReleaseMemory m,ScriptWideCharacterServices s,uint caller,uint child,uint context)
  {m.Write32(child+16,0);m.Write32(child+12,m.Read32(caller+12));m.Write32(child+8,m.Read32(caller+8));m.Write32(child+4,m.Read32(caller+4));m.Write32(child,m.Read32(caller));return Local(m,s,child,context);}
 }
}
