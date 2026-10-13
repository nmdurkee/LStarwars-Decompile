// Bounded PC player-reference identity, group liveness and aggregate readers.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class Phase5LifeGroup
 {
  public byte Count7;
  public readonly List<Phase5ActorRecord> Members=new List<Phase5ActorRecord>();
 }
 public sealed class Phase5ActorDefinition { public Phase5LifeGroup Group144; }
 public sealed class Phase5ActorRecord
 {
  // Native reference first pointer; identity predicates compare the record itself.
  public Phase5ActorRecord WorldObject;
  public Phase5ActorDefinition Definition4;
  public uint Flags1f8,Flags1fc;
  public byte Dead28b,SplineFinishedE6b;
  public bool HasSplineE64;
 }
 public sealed class Phase5ScriptCreature { public Phase5ActorRecord ReferenceD0; }
 public sealed class Phase5ConditionWorld
 {
  public bool SystemPresent=true;
  public Phase5ActorRecord Player1Reference138c,Player2Reference1390;
  // Native callback0x923904 returns reference identity, not first-pointer actor.
  public Func<string,Phase5ActorRecord> ResolveCharacter;
  public int ActorCount,BaddiesSeeingPlayers;
  public readonly List<Phase5ActorRecord> Actors=new List<Phase5ActorRecord>();
 }
 public static class Phase5Conditions
 {
  static string C(string s)
  {if(s==null)return null;int z=s.IndexOf('\0');if(z>=0)s=s.Substring(0,z);foreach(char c in s)if(c>127)throw new ArgumentException("Bounded native operands must be ASCII.");return s;}
  // 0x440f10 /0x441690 require operand/callback but allow null native system.
  public static Phase5ActorRecord BindReference(Phase5ConditionWorld world,string operand)
  {if(world==null)throw new ArgumentNullException("world");operand=C(operand);return operand==null||world.ResolveCharacter==null?null:world.ResolveCharacter(operand);}
  public static float EitherPlayerIs(Phase5ConditionWorld world,Phase5ActorRecord initialized)
  {return world!=null&&world.SystemPresent&&initialized!=null&&(Object.ReferenceEquals(world.Player1Reference138c,initialized)||Object.ReferenceEquals(world.Player2Reference1390,initialized))?1f:0f;}
  public static float Player1Is(Phase5ConditionWorld world,Phase5ActorRecord initialized)
  {return world!=null&&world.SystemPresent&&initialized!=null&&Object.ReferenceEquals(world.Player1Reference138c,initialized)?1f:0f;}
  public static float Player2Is(Phase5ConditionWorld world,Phase5ActorRecord initialized)
  {return world!=null&&world.SystemPresent&&initialized!=null&&Object.ReferenceEquals(world.Player2Reference1390,initialized)?1f:0f;}
  // 0x4429d0: absent self chain returns-1, present unsplined actor returns1.
  public static float FinishedSpline(Phase5ScriptCreature creature)
  {
   Phase5ActorRecord actor=creature==null||creature.ReferenceD0==null?null:creature.ReferenceD0.WorldObject;
   if(actor==null)return -1f;return actor.HasSplineE64&&actor.SplineFinishedE6b==0?0f:1f;
  }
  // 0x442260 initializes0 with no parameters or state; aggregate reader ignores it.
  public static int BindNumBaddies(){return 0;}
  // 0x442270: global actor array+0x1fc flags, preceding+0x1f8 baddie bit.
  public static float NumBaddies(Phase5ConditionWorld world)
  {
   if(world==null)throw new ArgumentNullException("world");int count=0;
   for(int i=0;i<world.ActorCount;i++)
   {
    if(i>=world.Actors.Count||world.Actors[i]==null)throw new ArgumentException("Native counted actor backing required.");
    Phase5ActorRecord actor=world.Actors[i];if((actor.Flags1fc&0x1001u)==0x1001u&&(actor.Flags1f8&1u)!=0)++count;
   }
   return BitConverter.ToSingle(BitConverter.GetBytes((float)count),0);
  }
  // 0x4416b0: initialized record definition is read without a null guard.
  // Solo requires live bit1000 and dead byte0; group members additionally need bit1.
  public static float IsAlive(Phase5ActorRecord initialized)
  {
   if(initialized==null)return 0f;if(initialized.Definition4==null)throw new ArgumentException("Native IsAlive dereferences missing initialized definition+4.");
   Phase5LifeGroup group=initialized.Definition4.Group144;
   if(group==null)return(initialized.Flags1fc&0x1000u)!=0&&initialized.Dead28b==0?1f:0f;
   for(int i=0;i<group.Count7;i++)
   {
    if(i>=group.Members.Count)throw new ArgumentException("Native group member backing required.");Phase5ActorRecord member=group.Members[i];
    if(member!=null&&(member.Flags1fc&0x1001u)==0x1001u&&member.Dead28b==0)return 1f;
   }
   return 0f;
  }
  // 0x440b30: packet+0xb0 byte, no packet-null guard.
  public static float MySet(ScriptPacket packet)
  {if(packet==null)throw new ArgumentException("Native MySet dereferences null packet+0xb0.");return packet.SetId;}
  // 0x442d00 fild signed global dword0x876840; only storage boundary modeled.
  public static float NumBaddiesThatCanSeePlayers(Phase5ConditionWorld world)
  {if(world==null)throw new ArgumentNullException("world");return BitConverter.ToSingle(BitConverter.GetBytes((float)world.BaddiesSeeingPlayers),0);}
 }
}
