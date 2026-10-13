using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class NamedLocatorReservationSet
 {
  public string Name;
  public LocatorReservationSet Set;
 }
 public static class LocatorSetTraversal
 {
  // 0x51ac70: first matching inline name, signed collection count.
  public static LocatorReservationSet Find(bool systemPresent,IList<NamedLocatorReservationSet> sets,int count,string name)
  {
   if(!systemPresent)return null;
   for(int i=0;i<count;i++)if(SceneryText.Equal(SceneryText.C(sets[i].Name),SceneryText.C(name)))return sets[i].Set;
   return null;
  }
  // 0x440660: native actor argument is EDI, followed by five stack args.
  // Already-selected ownership is released before choosing the next entry.
  public static void Next(LocatorReservationWorld world,LocatorReservationSet set,LocatorReservationActor actor,bool looping,bool finishAtEnd,bool ignoreAssigned,QRandom random)
  {
   if(set==null||set.Count<=1||actor==null)return;
   if(!actor.PacketPresent)throw new ArgumentException("Native traversal requires an attached packet.");
   if(ignoreAssigned)LocatorReservations.Refresh(world,set);
   int count=set.Count,index=count,direction=(actor.Actor.Flags1fc&0x100000)!=0?-1:1;
   if(actor.SelectedLocatorIndex.HasValue)
    for(int i=0;i<count;i++)if(set.Indices[i]==actor.SelectedLocatorIndex.Value){set.Owners[i]=255;index=i;break;}
   if(index==count){if(random==null)throw new ArgumentNullException("random");index=(int)random.Next()/(65535/count+1);}
   int start=index,returns=0;
   for(;;)
   {
    index+=direction;
    if(index>=count)
    {
     if(finishAtEnd){actor.SelectedLocatorIndex=null;return;}
     if(looping)index=0;else{index=count-2;direction=-1;actor.Actor.Flags1fc|=0x100000;}
    }
    else if(index<0)
    {
     if(looping)index=count-1;else{index=1;direction=1;actor.Actor.Flags1fc&=0xffefffff;}
    }
    if(index==start){if(looping||++returns>=2)break;}
    else if(!ignoreAssigned||set.Owners[index]==255)break;
   }
   actor.SelectedLocatorIndex=set.Indices[index];set.Owners[index]=actor.OwnerId;
  }
 }
}
