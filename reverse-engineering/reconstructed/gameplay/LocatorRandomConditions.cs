using System;
namespace Recovered.Gameplay
{
 public static class LocatorRandomConditions
 {
  //0x52d070, nullable condition operand initializer.
  public static LocatorRecord Bind(LocatorWorld world,string name)
  {return name==null||world==null?null:world.Find(SceneryText.C(name));}
  //0x5becc0 nonnull difference-scratch branch, final float32 result.
  public static float Distance(SpawnVector a,SpawnVector b)
  {return (float)Math.Sqrt(LocatorCommands.DistanceSquared(a,b,false));}
  //0x514a00 reads controller+14c, distinct from reference/world position.
  public static float Range(LocatorPacket packet,LocatorCreature creature,LocatorRecord bound)
  {
   if(creature==null||creature.Reference==null)return Single.MaxValue;
   LocatorRecord target=bound??packet.Selected;
   return target==null?Single.MaxValue:Distance(creature.Position,target.Position);
  }
  //0x5149a0 tail-jumps to already recovered5b9dd0. Same shared integer state.
  public static float Random(ScriptRandom state){return state.Next();}
 }
}
