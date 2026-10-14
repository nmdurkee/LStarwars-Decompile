// Native inheritance: scope-specific parent resolve, missing-state deepcopy, parameter defaults and target rebinding.
using System;
namespace Recovered.Gameplay
{
 public static class PreparedScriptInheritance
 {
  static bool NamesEqual(TakeoverReleaseMemory m,uint a,uint b){return a!=0&&b!=0&&PreparedConditionLoading.Equal(m,a,b);}
  static void Append(TakeoverReleaseMemory m,uint list,uint node){uint tail=m.Read32(list+4);m.Write32(node,0);m.Write32(node+4,tail);if(tail!=0)m.Write32(tail,node);else m.Write32(list,node);m.Write32(list+4,node);}
  static uint DefaultBits(uint value){if((value&0x7f800000)==0x7f800000&&(value&0x007fffff)!=0&&(value&0x00400000)==0)throw new ArgumentException("Signaling NaN default copy is outside the prepared x87 store domain.");return value;}
  //513f20 cdecl(script,topPointer,bottomPointer,system), EAX1 resolved/noop, EAX0 deferred parent.
  public static uint Apply(TakeoverReleaseMemory m,ScriptConditionLoadServices s,uint script,uint top,uint bottom,uint system)
  {
   if(script==0||m.Read32(script+0xc)==0||(m.Read32(script+0x3c)&2)==0)return 1;uint shifted=m.Read32(script+0x3c)>>2;uint parent=PreparedScriptGraphBinding.ResolveScript(m,system,m.Read32(script+0xc),0,shifted&1,(~shifted)&1);
   if(parent==0){s.Diagnostic(m,m.Read32(0x922248)==1?0x512860u:0x512850u,new uint[]{m.Read32(script+8),m.Read32(script+0xc)});m.Write32(script+0x3c,m.Read32(script+0x3c)&0xfffffffdu);return 1;}
   if(parent!=script){if((m.Read8(parent+0x3c)&2)!=0)return 0;uint state=m.Read32(parent+0x10),budget=0;while(state!=0){if(++budget>4096)throw new ArgumentException("Bounded parent states required.");uint child=m.Read32(script+0x10),scan=0;bool exists=false;while(child!=0){if(++scan>4096)throw new ArgumentException("Bounded child states required.");if(NamesEqual(m,m.Read32(state+0x18),m.Read32(child+0x18))){exists=true;break;}child=m.Read32(child);}if(!exists){uint copy=PreparedScriptStateCopy.Copy(m,s,state,top,bottom);if(copy!=0)Append(m,script+0x10,copy);}state=m.Read32(state);}
    for(uint i=0;i<4;i++){uint source=m.Read32(parent+0x18+i*8);if(source!=0&&m.Read32(script+0x18+i*8)==0){uint name=PreparedConditionLoading.CopyString(m,top,source,bottom);m.Write32(script+0x18+i*8,name);m.Write32(script+0x1c+i*8,DefaultBits(m.Read32(parent+0x1c+i*8)));}}
    state=m.Read32(script+0x10);budget=0;while(state!=0){if(++budget>4096)throw new ArgumentException("Bounded resulting states required.");uint condition=m.Read32(state+8),inner=0;while(condition!=0){if(++inner>4096)throw new ArgumentException("Bounded resulting conditions required.");uint target=PreparedScriptGraphBinding.FindState(m,m.Read32(condition+0x20),script);uint name=m.Read32(condition+0x20);m.Write32(condition+0x24,target);if(name!=0&&target==0){uint mode=m.Read32(0x922248),stateName=m.Read32(state+0x18),scriptName=m.Read32(script+8);s.Diagnostic(m,mode==1?0x512860u:0x512850u,new uint[]{name,scriptName,stateName});}condition=m.Read32(condition);}state=m.Read32(state);}
   }m.Write32(script+0x3c,m.Read32(script+0x3c)&0xfffffffdu);return 1;
  }
 }
}
