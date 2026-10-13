// Bounded PC set-count mutation and vehicle-state predicate.
// Numeric resolution composes the previously recovered MessageNumbers contract.
using System;
namespace Recovered.Gameplay
{
 public sealed class Phase4Vehicle { public short Type1064; }
 public sealed class Phase4Actor { public byte Set378,Context7b5; public Phase4Vehicle LinkedCd0; }
 public sealed class Phase4ActorReference { public Phase4Actor Target; }
 public sealed class Phase4ScriptCreature { public Phase4ActorReference ReferenceD0; }
 public sealed class Phase4ScriptWorld
 {
  public bool SystemPresent=true;
  public short SpeederBikeType;
  public Func<string,Phase4ActorReference> ResolveCharacter;
  // Index1..16 writes model native bytes0x876847+index; producers and actual
  // allocation size remain external. Reset never decrements any count.
  public byte[] AliveCounts;
 }
 public static class Phase4ScriptCommands
 {
  static string C(string s)
  {if(s==null)return null;int z=s.IndexOf('\0');if(z>=0)s=s.Substring(0,z);foreach(char c in s)if(c>127)throw new ArgumentException("Bounded native tokens must be ASCII.");return s;}
  // 0x4499b0: ordered writes and increments; no previous-membership correction.
  public static int AddToSet(Phase4ScriptWorld world,ScriptPacket packet,Phase4ScriptCreature creature,string[] tokens,bool firstCall)
  {
   if(!firstCall||creature==null||creature.ReferenceD0==null||creature.ReferenceD0.Target==null)return 1;
   Phase4Actor actor=creature.ReferenceD0.Target;
   foreach(string raw in tokens)
   {
    string token=C(raw);
    if(token!=null&&String.Equals(token,"Reset",StringComparison.OrdinalIgnoreCase))actor.Set378=0;
    else
    {
     float number=MessageNumbers.Resolve(packet,token);
     if(Single.IsNaN(number)||Single.IsInfinity(number)||number<-2147483648f||number>=2147483648f)
      throw new ArgumentOutOfRangeException("tokens","Native numeric-to-integer behavior outside finite int32 conversion range is not covered.");
     int selected=(int)number;
     if(selected>=1&&selected<=16)
     {
      if(world==null||world.AliveCounts==null||world.AliveCounts.Length<=selected)throw new ArgumentException("Native selected alive-count byte must have backing.");
      actor.Set378=(byte)selected;unchecked{world.AliveCounts[selected]=(byte)(world.AliveCounts[selected]+1);}
     }
    }
   }
   return 1;
  }
  // 0x4431d0: named reference first-pointer extraction, system/name/callback gates.
  public static Phase4Actor BindOnSpeederBike(Phase4ScriptWorld world,string operand)
  {
   if(world==null)throw new ArgumentNullException("world");operand=C(operand);
   if(!world.SystemPresent||operand==null||world.ResolveCharacter==null)return null;
   Phase4ActorReference reference=world.ResolveCharacter(operand);return reference==null?null:reference.Target;
  }
  // 0x443200: initialized actor wins; null initialization falls back to self
  // through an unchecked creature pointer. Native crashes if creature is null.
  public static float OnSpeederBike(Phase4ScriptWorld world,Phase4ScriptCreature creature,Phase4Actor initialized)
  {
   Phase4Actor actor=initialized;
   if(actor==null)
   {
    if(creature==null)throw new ArgumentException("Native fallback dereferences a null script creature.");
    actor=creature.ReferenceD0==null?null:creature.ReferenceD0.Target;
   }
   if(actor==null||actor.LinkedCd0==null||actor.Context7b5!=0x3b)return 0f;
   if(world==null)throw new ArgumentNullException("world");return actor.LinkedCd0.Type1064==world.SpeederBikeType?1f:0f;
  }
 }
}
