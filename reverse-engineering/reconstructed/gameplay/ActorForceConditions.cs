using System;
namespace Recovered.Gameplay
{
 public sealed class ActorForceContext {public bool CreaturePresent=true;public ActorStateRecord Reference;}
 public static class ActorForceConditions
 {
  //0x441020 dereferences the creature/reference chain without null guards.
  public static float UsingForce(ForceConditionWorld world,ActorForceContext context,SceneryObject bound)
  {
   if(context==null||!context.CreaturePresent||context.Reference==null)throw new ArgumentException("Native creature and reference pointers must be readable.");
   return ForceConditions.IsUsingForce(world,context.Reference.WorldObject,bound)!=0?1f:0f;
  }
  //0x441070 uses the two distinct globals93d810/93d814, in order.
  public static float EitherPlayerUsingForce(ForceConditionWorld world,ActorStateRecord secondPlayer,SceneryObject bound)
  {
   if(ForceConditions.IsUsingForce(world,world.Terrain.Actors.Tags.Actors.PrimaryPlayer,bound)!=0)return 1;
   return ForceConditions.IsUsingForce(world,secondPlayer,bound)!=0?1f:0f;
  }
  //0x441b00 guards every pointer in the creature/reference/actor chain.
  public static float OnObject(TerrainObjectWorld world,ActorForceContext context,int bound)
  {
   if(context==null||!context.CreaturePresent||context.Reference==null||context.Reference.WorldObject==null||bound==-1)return 0;
   ActorStateRecord actor=context.Reference.WorldObject;ActorStatusState status=world.Actors.Get(actor);if(status.Ground281==0&&status.Ground282==0)return 0;
   short ground;if(!world.GroundObjects.TryGetValue(actor,out ground))throw new ArgumentException("Missing actor ground index.");if(ground!=bound)return 0;
   if(!world.TerrainPresent||ground<0||ground>=world.Terrain.Count||!world.Terrain[ground].HasTransform)throw new ArgumentException("Native terrain transform requires readable backing.");
   return world.Terrain[ground].Height<=actor.Y?1f:0f;
  }
  //0x4410f0 guards creature/reference but dereferences a nonnull actor.
  public static float OnForcePlatform(ForceConditionWorld world,ActorForceContext context,SceneryObject bound)
  {
   if(bound==null||context==null||!context.CreaturePresent||context.Reference==null)return 0;
   ActorStateRecord actor=context.Reference.WorldObject;if(actor==null)throw new ArgumentException("Native platform query requires its actor pointer.");
   ActorStatusState status=world.Terrain.Actors.Get(actor);if(status.Ground281==0&&status.Ground282==0)return 0;
   short ground;if(!world.Terrain.GroundObjects.TryGetValue(actor,out ground))throw new ArgumentException("Missing actor ground index.");if(OnObject(world.Terrain,context,ground)==0)return 0;
   ForcePlatformState state;if(!world.Platforms.TryGetValue(bound,out state))throw new ArgumentException("Native platform member-list attachment is required.");
   foreach(short index in state.GroundObjectIndices)if(index==ground)return 1;return 0;
  }
 }
}
