// Per-file script wrapper: preserve customregister contexts, targetfinalization andduplicate diagnostics.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptFileProgramServices
 {
  //52bcb0(outScript,context,fileName,archive,topPointer,bottomPointer); outputlocalnormalized toreturn value.
  public abstract uint Parse(TakeoverReleaseMemory m,uint context,uint fileName,uint archive,uint topPointer,uint bottomPointer);
  public virtual void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){}
 }
 public static class PreparedScriptFileProgram
 {
  //52c320 customECX=context,EAX=archive; cdecl(fileName,topPointer,bottomPointer), EAX scriptpointer.
  public static uint Parse(TakeoverReleaseMemory m,ScriptFileProgramServices s,uint context,uint archive,uint fileName,uint top,uint bottom)
  {
   m.Write32(0x92223c,archive);m.Write32(0x922240,context);uint script=s.Parse(m,context,fileName,archive,top,bottom);m.Write32(0x92223c,0);m.Write32(0x922240,0);if(script==0)return 0;
   uint state=m.Read32(script+0x10),budget=0;while(state!=0){if(++budget>4096)throw new ArgumentException("Bounded script state list required.");uint node=m.Read32(state+8),inner=0;while(node!=0){if(++inner>4096)throw new ArgumentException("Bounded condition list required.");uint name=m.Read32(node+0x20),target=PreparedScriptGraphBinding.FindState(m,name,script);name=m.Read32(node+0x20);m.Write32(node+0x24,target);if(name!=0&&target==0){uint mode=m.Read32(0x922248),stateName=m.Read32(state+0x18),scriptName=m.Read32(script+8);s.Diagnostic(m,mode==1?0x512860u:0x512850u,new uint[]{name,scriptName,stateName});}node=m.Read32(node);}
    uint other=m.Read32(state),scan=0;while(other!=0){if(++scan>4096)throw new ArgumentException("Bounded duplicate-state scan required.");if(PreparedConditionLoading.Equal(m,m.Read32(state+0x18),m.Read32(other+0x18))){uint mode=m.Read32(0x922248),scriptName=m.Read32(script+8),stateName=m.Read32(state+0x18);s.Diagnostic(m,mode==1?0x512860u:0x512850u,new uint[]{stateName,scriptName});}other=m.Read32(other);}state=m.Read32(state);
   }return script;
  }
 }
}
