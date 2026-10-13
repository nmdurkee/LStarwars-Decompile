// Recovered locator ownership gates and commands. See native-locator-reservations-contract.json.
using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class LocatorReservationActor
 {
  public ActorStateRecord Actor;
  public bool PacketPresent=true;
  public int? SelectedLocatorIndex;
  public uint ReservationToken;
  public byte State406,DeathState,OwnerId;
  public float DeathTimer;
 }
 public sealed class LocatorReservationSet
 {
  public sbyte Count;
  public byte[] Indices,Owners;
 }
 public sealed class LocatorFormation { public uint Flags; }
 public sealed class LocatorReservationWorld
 {
  public ActorStateWorld Actors;
  public bool IndexCallback=true;
  public readonly Dictionary<ActorStateRecord,LocatorReservationActor> Views=new Dictionary<ActorStateRecord,LocatorReservationActor>();
  public LocatorReservationActor View(ActorStateRecord actor){return actor==null?null:Views[actor];}
  // 0x43c7a0. Input is truncated to a byte before the signed count comparison.
  public LocatorReservationActor FindActor(int index)
  {
   index=unchecked((byte)index);
   if(index>=Actors.ActiveCount)return null;
   LocatorReservationActor view=View(Actors.Actors[index]);
   uint flags=view.Actor.Flags1fc;
   if((flags&1)==0||((flags&0x1000)==0&&view.State406!=3))return null;
   if(view.DeathState!=0&&!(view.DeathTimer>0))return null;
   return view;
  }
 }
 public static class LocatorReservations
 {
  // 0x51fe60. Owner255 is free;128 is a reserved sentinel. Compare the low
  // byte of the selected locator index, including the missing-value255 case.
  public static void Refresh(LocatorReservationWorld world,LocatorReservationSet set)
  {
   if(set==null||!world.IndexCallback)return;
   for(int i=0;i<set.Count;i++)
   {
    byte owner=set.Owners[i];if(owner==255||owner==128)continue;
    LocatorReservationActor actor=world.FindActor(owner);byte selected=255;
    if(actor!=null&&actor.PacketPresent&&actor.SelectedLocatorIndex.HasValue)selected=unchecked((byte)actor.SelectedLocatorIndex.Value);
    if(selected!=set.Indices[i])set.Owners[i]=255;
   }
  }
  // 0x453810 clears actor+36c, not packet+a4. Last character= token wins.
  public static int Release(LocatorReservationWorld world,ActorStateRecord reference,string[] tokens,bool firstCall)
  {
   if(!firstCall)return 1;
   ActorStateRecord target=reference==null?null:reference.WorldObject;
   foreach(string raw in tokens)
   {
    string text=SceneryText.C(raw);int at=text.IndexOf("character=",StringComparison.OrdinalIgnoreCase);
    if(at>=0)target=world.Actors.ResolveObject(text.Substring(at+10));
   }
   if(target!=null)world.View(target).ReservationToken=0;
   return 1;
  }
  // 0x449c90 is ungated by the command first-call flag.
  public static int BreakFormation(LocatorFormation formation)
  {if(formation!=null)formation.Flags&=0xfffffff7;return 1;}
 }
}
