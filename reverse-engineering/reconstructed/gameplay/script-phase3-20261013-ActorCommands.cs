// Bounded PC actor flag and input commands. Evidence: script-phase3-20261013-contract.json.
using System;
namespace Recovered.Gameplay
{
 public sealed class Phase3ActorInput { public uint Flags8; }
 public sealed class Phase3Actor { public uint Flags1fc,FlagsEec,FlagsEf0,Flags1044; public Phase3ActorInput InputCa4; }
 public sealed class Phase3ActorReference { public Phase3Actor Target; }
 public sealed class Phase3ScriptCreature { public Phase3ActorReference ReferenceD0; }
 public sealed class Phase3ActorWorld
 {
  public bool SystemPresent=true;
  public uint JumpButtonMask;
  // Native callback0x923904 returns a reference first word, not an actor directly.
  public Func<string,Phase3ActorReference> ResolveCharacter;
 }
 public static class Phase3ActorCommands
 {
  static string C(string s)
  {if(s==null)return null;int z=s.IndexOf('\0');if(z>=0)s=s.Substring(0,z);foreach(char c in s)if(c>127)throw new ArgumentException("Bounded native tokens must be ASCII.");return s;}
  static bool Equal(string a,string b){return a!=null&&b!=null&&String.Equals(C(a),C(b),StringComparison.OrdinalIgnoreCase);}
  static Phase3Actor Self(Phase3ScriptCreature creature){return creature==null||creature.ReferenceD0==null?null:creature.ReferenceD0.Target;}
  // 0x449970 does not read firstCall. Input pointer is unchecked after actor gates.
  public static int PressJumpButton(Phase3ActorWorld world,Phase3ScriptCreature creature)
  {
   Phase3Actor actor=Self(creature);if(actor!=null){if(actor.InputCa4==null)throw new ArgumentException("Native jump input write requires input+0xca4 backing.");if(world==null)throw new ArgumentNullException("world");actor.InputCa4.Flags8|=world.JumpButtonMask;}return 1;
  }
  // 0x44f1b0 also ignores firstCall. TRUE never reverses a FALSE in this call.
  public static int PrefersPlayers(Phase3ScriptCreature creature,string[] tokens)
  {Phase3Actor actor=Self(creature);if(actor!=null){actor.FlagsEec|=0x40000000u;foreach(string token in tokens)if(Equal(token,"FALSE"))actor.FlagsEec&=0xbfffffffu;}return 1;}
  static int Ordered1044(Phase3ScriptCreature creature,string[] tokens,bool firstCall,uint bit)
  {
   Phase3Actor actor=Self(creature);if(actor!=null&&firstCall){actor.Flags1044|=bit;foreach(string token in tokens){if(Equal(token,"TRUE"))actor.Flags1044|=bit;else if(Equal(token,"FALSE"))actor.Flags1044&=~bit;}}return 1;
  }
  public static int CanOpenDoors(Phase3ScriptCreature creature,string[] tokens,bool firstCall){return Ordered1044(creature,tokens,firstCall,1);}
  public static int CanShootOffScreen(Phase3ScriptCreature creature,string[] tokens,bool firstCall){return Ordered1044(creature,tokens,firstCall,4);}
  static int StickyFalseEec(Phase3ScriptCreature creature,string[] tokens,bool firstCall,uint bit)
  {Phase3Actor actor=Self(creature);if(actor!=null&&firstCall){actor.FlagsEec|=bit;foreach(string token in tokens)if(Equal(token,"FALSE"))actor.FlagsEec&=~bit;}return 1;}
  public static int CanDefend(Phase3ScriptCreature creature,string[] tokens,bool firstCall){return StickyFalseEec(creature,tokens,firstCall,2);}
  public static int SetBoss(Phase3ScriptCreature creature,string[] tokens,bool firstCall){return StickyFalseEec(creature,tokens,firstCall,0x8000000);}
  // 0x4447a0 resets origin bit and sets respawn bit, then independently handles tokens.
  public static int Respawnable(Phase3ScriptCreature creature,string[] tokens,bool firstCall)
  {
   Phase3Actor actor=Self(creature);if(actor!=null&&firstCall){actor.FlagsEec=(actor.FlagsEec&0xffdfffffu)|0x100000u;foreach(string token in tokens){if(Equal(token,"origin"))actor.FlagsEec|=0x200000u;else if(Equal(token,"FALSE"))actor.FlagsEec&=0xffefffffu;}}return 1;
  }
  // 0x445b70 scans a case-insensitive character substring anywhere. It advances
  // ten bytes from the match, then resolves a new reference on every occurrence.
  // In the non-character branch it compares FALSE against tokens[0], not token.
  public static int SetDontMove(Phase3ActorWorld world,Phase3ScriptCreature creature,string[] tokens,bool firstCall)
  {
   if(!firstCall)return 1;Phase3Actor actor=Self(creature);bool enabled=true;
   foreach(string raw in tokens)
   {
    string token=C(raw);int at=token==null?-1:token.IndexOf("character",StringComparison.OrdinalIgnoreCase);
    if(at>=0)
    {
     if(world==null)throw new ArgumentNullException("world");
     if(world.ResolveCharacter==null)actor=null;
     else
     {
      if(at+10>token.Length)throw new ArgumentException("Native token points beyond its terminator after character+10.");
      Phase3ActorReference reference=world.ResolveCharacter(token.Substring(at+10));actor=reference==null?null:reference.Target;
     }
    }
    else if(Equal("FALSE",tokens[0]))enabled=false;
   }
   if(actor!=null)actor.FlagsEf0=(actor.FlagsEf0&0xffffffefu)|(enabled?0x10u:0u);return 1;
  }
  // 0x443250: operand/system/callback gates before reference first-pointer extraction.
  public static Phase3Actor BindUnderPlayerControl(Phase3ActorWorld world,string operand)
  {
   if(world==null)throw new ArgumentNullException("world");operand=C(operand);if(!world.SystemPresent||operand==null||world.ResolveCharacter==null)return null;
   Phase3ActorReference reference=world.ResolveCharacter(operand);return reference==null?null:reference.Target;
  }
  // 0x443280 has no self fallback when the initialized pointer is null.
  public static float UnderPlayerControl(Phase3Actor initialized)
  {return initialized!=null&&(initialized.Flags1fc&0x80u)!=0?1f:0f;}
 }
}
