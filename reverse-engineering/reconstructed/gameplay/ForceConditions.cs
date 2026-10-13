using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class ForcePlatformState
 {
  public uint FlagsA0;
  public readonly List<short> GroundObjectIndices=new List<short>();
 }
 public sealed class ForceConditionWorld
 {
  public SceneryWorld Scenery;
  public int ForceType;
  public TerrainObjectWorld Terrain;
  // Host-only observation hook; callbacks must not mutate recovered state.
  public Action<ActorStateRecord,SceneryObject> ObserveUsingForce;
  public readonly Dictionary<SceneryObject,ForcePlatformState> Platforms=new Dictionary<SceneryObject,ForcePlatformState>();
  public readonly Dictionary<ActorStateRecord,SceneryObject> ForceTargets=new Dictionary<ActorStateRecord,SceneryObject>();
 }
 public static class ForceConditions
 {
  //0x440ff0: lookup record then return its first-pointer physical object.
  public static SceneryObject BindUsingForce(ForceConditionWorld world,string name)
  {
   SceneryGizmo record=world.Scenery.Bindings.Find(world.Scenery.Registry,world.ForceType,SceneryText.C(name));return record==null?null:record.Target;
  }
  //0x4410b0 adds physical flags+a0 bit100 eligibility.
  public static SceneryObject BindForcePlatform(ForceConditionWorld world,string name)
  {
   SceneryObject target=BindUsingForce(world,name);if(target==null)return null;ForcePlatformState state;if(!world.Platforms.TryGetValue(target,out state))throw new ArgumentException("Missing force-platform attachment.");return(state.FlagsA0&0x100)!=0?target:null;
  }
  //0x4678f0: mode8 plus exact physical-object identity.
  public static int IsUsingForce(ForceConditionWorld world,ActorStateRecord actor,SceneryObject target)
  {
   if(world.ObserveUsingForce!=null)world.ObserveUsingForce(actor,target);
   if(target==null||actor==null||world.Terrain.Actors.Get(actor).State7b5!=8)return 0;
   SceneryObject current;if(!world.ForceTargets.TryGetValue(actor,out current))throw new ArgumentException("Missing actor force-target field.");return Object.ReferenceEquals(current,target)?1:0;
  }
  //0x441050: global primary player only.
  public static float PlayerUsingForce(ForceConditionWorld world,SceneryObject bound){return IsUsingForce(world,world.Terrain.Actors.Tags.Actors.PrimaryPlayer,bound)!=0?1f:0f;}
  //0x441180: grounded inclusive-height check, then ordered member-object scan.
  public static float PlayerOnForcePlatform(ForceConditionWorld world,SceneryObject bound)
  {
   if(bound==null)return 0;ActorStateRecord player=world.Terrain.Actors.Tags.Actors.PrimaryPlayer;if(player==null)return 0;
   ActorStatusState status=world.Terrain.Actors.Get(player);if(status.Ground281==0&&status.Ground282==0)return 0;
   short ground;if(!world.Terrain.GroundObjects.TryGetValue(player,out ground))throw new ArgumentException("Missing player ground-object field.");
   if(ground==-1||TerrainObjectConditions.PlayerOnObject(world.Terrain,ground)==0)return 0;
   ForcePlatformState state;if(!world.Platforms.TryGetValue(bound,out state))throw new ArgumentException("Native bound platform requires a member-list attachment.");
   foreach(short index in state.GroundObjectIndices)if(index==ground)return 1;return 0;
  }
 }
}
