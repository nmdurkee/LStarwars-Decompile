// Raw condition initializer pass and script reference binding, preserving live reads and unlink quirks.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptGraphBindingServices
 {
  public abstract uint ResolveScript(TakeoverReleaseMemory m,uint system,uint name,uint fixedOne,uint bitOne,uint bitZero);
  public abstract uint Initialize(TakeoverReleaseMemory m,uint callback,uint system,uint argument,uint script);
  public virtual void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){}
 }
 public static class PreparedScriptGraphBinding
 {
  // Existing512fc0 reads scriptstatehead BEFOREnullnameguard; firstbyte-folded name match wins.
  public static uint FindState(TakeoverReleaseMemory m,uint name,uint script){uint state=m.Read32(script+0x10);if(name==0)return 0;uint budget=0;while(state!=0){if(++budget>4096)throw new ArgumentException("Bounded state list required.");if(PreparedConditionLoading.Equal(m,name,m.Read32(state+0x18)))return state;state=m.Read32(state);}return 0;}
  static uint FindScript(TakeoverReleaseMemory m,uint name,uint list){uint node=m.Read32(list),budget=0;while(node!=0){if(++budget>4096)throw new ArgumentException("Bounded script list required.");if(PreparedConditionLoading.Equal(m,name,m.Read32(node+8)))return node;node=m.Read32(node);}return 0;}
  // New513010 cdecl(system,name,fallbackDefault,searchScoped,searchGlobal). Scopedfirst, then global/default.
  public static uint ResolveScript(TakeoverReleaseMemory m,uint system,uint name,uint fallback,uint scoped,uint global){if(name!=0){uint found;if(scoped!=0&&system!=0){found=FindScript(m,name,system+0x1c);if(found!=0)return found;}if(global!=0){found=FindScript(m,name,0x921ee8);if(found!=0)return found;}}return fallback!=0?FindScript(m,0x757734,0x921ee8):0;}
  // Existing5149b0 initializer returnsFLOATBITS IN EAX, notST0. Null/emptyargument defaults1.
  public static uint AlwaysTrueInitializer(TakeoverReleaseMemory m,uint argument){if(argument==0)return 0x3f800000;string text=PreparedConditionLoading.Text(m,argument);if(text.Length==0)return 0x3f800000;return TakeoverReleaseMemory.Bits(TextParserNumbers.Real(text));}
  static void Unlink(TakeoverReleaseMemory m,uint list,uint node){if(m.Read32(node)==0)m.Write32(list+4,m.Read32(node+4));else m.Write32(m.Read32(node)+4,m.Read32(node+4));if(m.Read32(node+4)!=0)m.Write32(m.Read32(node+4),m.Read32(node));else m.Write32(list,m.Read32(node));}
  static void InitializeList(TakeoverReleaseMemory m,ScriptGraphBindingServices s,uint system,uint script,uint list,bool cached,bool alternate)
  {
   uint node=m.Read32(list),budget=0;while(node!=0){if(++budget>4096)throw new ArgumentException("Bounded condition list required.");uint callback=m.Read32(m.Read32(node+0x1c)+8);if(callback!=0&&(!cached||system==0||(m.Read8(system+0x1386)&4)==0||m.Read32(node+0x18)==0)){uint argument=m.Read32(node+0x14),result=s.Initialize(m,callback,system,argument,script);m.Write32(node+0x18,result);}
    if(alternate){uint other=m.Read32(node+0x28),descriptor=other==0?0:m.Read32(other+0x1c);if(descriptor!=0){callback=m.Read32(descriptor+8);if(callback!=0){uint argument=m.Read32(other+0x14),result=s.Initialize(m,callback,system,argument,script);m.Write32(m.Read32(node+0x28)+0x18,result);}}}node=m.Read32(node);}
  }
  static void ResolveReference(TakeoverReleaseMemory m,ScriptGraphBindingServices s,uint system,uint reference){if((m.Read8(system+0x1386)&4)==0||m.Read32(reference+0xc)==0){uint flags=m.Read32(reference+0x18),name=m.Read32(reference+8);uint target=s.ResolveScript(m,system,name,1,(flags>>1)&1,flags&1);m.Write32(reference+0xc,target);}}
  static void Target(TakeoverReleaseMemory m,ScriptGraphBindingServices s,uint script,uint reference,uint state){uint name=m.Read32(reference+0x10),target=FindState(m,name,script);m.Write32(reference+0x14,target);if(target==0&&m.Read32(reference+0x10)!=0){uint mode=m.Read32(0x922248),freshName=m.Read32(reference+0x10),scriptName=m.Read32(script+8);s.Diagnostic(m,mode==1?0x512860u:0x512850u,state==0?new uint[]{freshName,scriptName}:new uint[]{freshName,scriptName,m.Read32(state+0x18)});}}
  // New514140 cdecl(system,script). State references intentionally unlinkusingSCRIPT+40, asoriginal.
  public static void BindReferences(TakeoverReleaseMemory m,ScriptGraphBindingServices s,uint system,uint script)
  {
   if(system==0||script==0)return;uint reference=m.Read32(script+0x40),budget=0;while(reference!=0){if(++budget>4096)throw new ArgumentException("Bounded reference list required.");uint next=m.Read32(reference);ResolveReference(m,s,system,reference);uint target=m.Read32(reference+0xc);if(target==0||target==script)Unlink(m,script+0x40,reference);else{Target(m,s,script,reference,0);InitializeList(m,s,system,script,reference+0x1c,false,false);}reference=next;}
   uint state=m.Read32(script+0x10);budget=0;while(state!=0){if(++budget>4096)throw new ArgumentException("Bounded state list required.");reference=m.Read32(state+0x1c);uint inner=0;while(reference!=0){if(++inner>4096)throw new ArgumentException("Bounded state reference list required.");uint next=m.Read32(reference);ResolveReference(m,s,system,reference);uint target=m.Read32(reference+0xc);if(target==0||target==script)Unlink(m,script+0x40,reference);Target(m,s,script,reference,state);InitializeList(m,s,system,script,reference+0x1c,false,false);reference=next;}state=m.Read32(state);}
  }
  // New5143a0 cdecl(system). Scoped scripts initializealternates, globalsonlyprimaryandrawcached-value gate.
  public static void BindSystem(TakeoverReleaseMemory m,ScriptGraphBindingServices s,uint system)
  {
   m.Read32(0x921ee8);if(system!=0){uint script=m.Read32(system+0x1c),budget=0;while(script!=0){if(++budget>4096)throw new ArgumentException("Bounded scoped script list required.");uint state=m.Read32(script+0x10),inner=0;while(state!=0){if(++inner>4096)throw new ArgumentException("Bounded scoped state list required.");InitializeList(m,s,system,script,state+8,false,true);state=m.Read32(state);}uint idle=FindState(m,0x753270,script);m.Write32(script+0x38,idle);BindReferences(m,s,system,script);script=m.Read32(script);}}
   uint global=m.Read32(0x921ee8),outer=0;while(global!=0){if(++outer>4096)throw new ArgumentException("Bounded global script list required.");uint state=m.Read32(global+0x10),inner=0;while(state!=0){if(++inner>4096)throw new ArgumentException("Bounded global state list required.");InitializeList(m,s,system,global,state+8,true,false);state=m.Read32(state);}uint idle=FindState(m,0x753270,global);m.Write32(global+0x38,idle);BindReferences(m,s,system,global);global=m.Read32(global);}
  }
 }
 public sealed class RecoveredDefaultGraphBindingServices:ScriptGraphBindingServices
 {
  readonly ScriptGraphBindingServices remaining;public RecoveredDefaultGraphBindingServices(ScriptGraphBindingServices others){remaining=others;}public override uint ResolveScript(TakeoverReleaseMemory m,uint system,uint name,uint one,uint bitOne,uint bitZero){return PreparedScriptGraphBinding.ResolveScript(m,system,name,one,bitOne,bitZero);}public override uint Initialize(TakeoverReleaseMemory m,uint callback,uint system,uint argument,uint script){return callback==0x5149b0?PreparedScriptGraphBinding.AlwaysTrueInitializer(m,argument):remaining.Initialize(m,callback,system,argument,script);}public override void Diagnostic(TakeoverReleaseMemory m,uint callback,uint[] arguments){remaining.Diagnostic(m,callback,arguments);}
 }
}
