using System;
namespace Recovered.Gameplay
{
 public static class SpatialConditions
 {
  //0x52d090: this initializer has its own registered native entry.
  public static LocatorRecord BindCurrent(LocatorWorld world,string name){return LocatorRandomConditions.Bind(world,name);}
  //0x514bb0 compares nonnull bound identity, not coordinates or names.
  public static float CurrentLocatorIs(LocatorPacket packet,LocatorRecord bound){return bound!=null&&Object.ReferenceEquals(packet.Selected,bound)?1f:0f;}
  //0x514b20: controller byte+166, bit0; no path pointer or world gate.
  public static float OnPath(LocatorCreature creature){return creature!=null&&(creature.NodeFlags&1)!=0?1f:0f;}
  //0x5bed80: float32 differences and squared sum before native sqrt.
  public static float DistanceXZ(SpawnVector a,SpawnVector b){return (float)Math.Sqrt(LocatorCommands.DistanceSquared(a,b,true));}
  //0x514a50 uses controller+14c, with reference presence as a gate only.
  public static float LocatorRangeXZ(LocatorPacket packet,LocatorCreature creature,LocatorRecord bound)
  {
   if(creature==null||creature.Reference==null)return Single.MaxValue;
   LocatorRecord target=bound??packet.Selected;
   return target==null?Single.MaxValue:DistanceXZ(creature.Position,target.Position);
  }
  //0x514c30 uses actor-reference+5c and system player0+5c.
  public static float PlayerRange(LocatorWorld world,LocatorCreature creature)
  {
   if(creature==null||creature.Reference==null||world==null||world.Players[0]==null)return Single.MaxValue;
   return LocatorRandomConditions.Distance(world.Players[0].Position,creature.Reference.Position);
  }
  //0x514c80: compare squared distances first, preserve max-finite sentinel.
  public static float NearestPlayerRange(LocatorWorld world,LocatorCreature creature)
  {
   if(creature==null||creature.Reference==null||world==null)return Single.MaxValue;
   float best=Single.MaxValue;
   if(world.Players[0]!=null)best=LocatorCommands.DistanceSquared(world.Players[0].Position,creature.Reference.Position,false);
   if(world.Players[1]!=null){float other=LocatorCommands.DistanceSquared(world.Players[1].Position,creature.Reference.Position,false);if(other<best)best=other;}
   return best==Single.MaxValue?best:(float)Math.Sqrt(best);
  }
 }
}
