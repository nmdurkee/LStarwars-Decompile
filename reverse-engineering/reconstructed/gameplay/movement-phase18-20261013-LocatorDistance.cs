using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class LocatorDistanceConditions
 {
  static SpawnVector Vector(OriginPathMemory m,uint p){float[]v=m.Vector(p);return new SpawnVector(v[0],v[1],v[2]);}
  public static float OpponentToLocatorXZ(OriginPathMemory m,uint packet,uint creature,uint locator)
  {
   if(creature==0)return Single.MaxValue;uint opponent=m.U32(creature+0xe4);if(opponent==0)return Single.MaxValue;if(locator==0){locator=m.U32(packet+0xa4);if(locator==0)return Single.MaxValue;}return SpatialConditions.DistanceXZ(Vector(m,opponent+0x5c),Vector(m,locator+0x10));
  }
  public static float NearestPlayerToLocator(OriginPathMemory m,uint world,uint packet,uint creature,uint locator)
  {
   if(creature==0||world==0)return Single.MaxValue;if(locator==0){locator=m.U32(packet+0xa4);if(locator==0)return Single.MaxValue;}
   var projected=new LocatorWorld();for(int j=0;j<2;j++){uint player=m.U32(world+0x138c+(uint)j*4);if(player!=0)projected.Players[j]=new LocatorActor{Position=Vector(m,player+0x5c)};}
   return SpatialConditions.NearestPlayerRange(projected,new LocatorCreature{Reference=new LocatorActor{Position=Vector(m,locator+0x10)}});
  }
 }
}
