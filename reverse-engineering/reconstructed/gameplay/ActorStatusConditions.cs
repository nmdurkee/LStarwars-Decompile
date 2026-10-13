using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class ActorStatusState
 {
  public ActorStateRecord OpponentReference,TakeoverTarget;
  public byte State7b5,Ground281,Ground282;
  public float HitTimer1018;
 }
 public sealed class ActorStatusWorld
 {
  public TagControlWorld Tags;
  public readonly Dictionary<ActorStateRecord,ActorStatusState> State=new Dictionary<ActorStateRecord,ActorStatusState>();
  internal ActorStatusState Get(ActorStateRecord actor){ActorStatusState state;if(actor==null||!State.TryGetValue(actor,out state))throw new ArgumentException("Missing actor status attachment.");return state;}
 }
 public static class ActorStatusConditions
 {
  //0x441d50: native allows a null system; registered lookup has player fallbacks.
  public static ActorStateRecord BindBeenHit(ActorStateWorld world,string operand){return operand==null?null:world.ResolveObject(SceneryText.C(operand));}
  //0x443020 adds a nonnull system gate before invoking the same callback.
  public static ActorStateRecord BindTakenOver(ActorStateWorld world,string operand){return world.SystemPresent?BindBeenHit(world,operand):null;}
  //0x441d80: explicit bound world object precedes self-reference fallback.
  public static float BeenHit(ActorStatusWorld world,ActorStateRecord reference,ActorStateRecord bound)
  {
   ActorStateRecord actor=bound??(reference==null?null:reference.WorldObject);
   return actor!=null&&(world.Get(actor).HitTimer1018>0||(actor.WeaponFlagsEec&1)!=0)?1f:0f;
  }
  //0x443050: named special operands are dynamic only when initializer is null.
  public static float TakenOver(ActorStatusWorld world,ActorStateRecord reference,string operand,ActorStateRecord bound)
  {
   ActorStateRecord actor=bound;
   if(actor==null)
   {
    if(operand==null)actor=reference==null?null:reference.WorldObject;
    else
    {
     operand=SceneryText.C(operand);
     if(ActorStateWorld.Equal(operand,"Opponent"))
     {
      if(reference==null||reference.WorldObject==null)throw new ArgumentException("Native Opponent operand requires attached self reference/world.");
      ActorStateRecord opponent=world.Get(reference.WorldObject).OpponentReference;actor=opponent==null?null:opponent.WorldObject;
     }
     else if(ActorStateWorld.Equal(operand,"TakeoverTarget"))
     {
      if(reference==null)throw new ArgumentException("Native TakeoverTarget operand requires attached self reference.");
      actor=reference.WorldObject==null?null:world.Get(reference.WorldObject).TakeoverTarget;
     }
     else return 0;
    }
   }
   return actor!=null&&world.Tags.Get(actor).LinkedCd0!=null&&world.Get(actor).State7b5!=59?1f:0f;
  }
  //0x4435e0: complete self-chain gates, then pointer presence only.
  public static float HasTakeOverTarget(ActorStatusWorld world,ActorStateRecord reference){return reference!=null&&reference.WorldObject!=null&&world.Get(reference.WorldObject).TakeoverTarget!=null?1f:0f;}
  //0x441830: primary player global, two byte-presence tests.
  public static float PlayerOnGround(ActorStatusWorld world)
  {
   ActorStateRecord player=world.Tags.Actors.PrimaryPlayer;if(player==null)return 0;ActorStatusState state=world.Get(player);return state.Ground281!=0||state.Ground282!=0?1f:0f;
  }
 }
}
