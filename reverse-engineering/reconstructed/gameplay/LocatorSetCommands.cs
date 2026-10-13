using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class LocatorSetCommandWorld
 {
  public LocatorSelectionContext Selection;
  public bool GlobalSetSystemPresent=true;
  public int SetCount;
  public readonly List<NamedLocatorReservationSet> Sets=new List<NamedLocatorReservationSet>();
  public ActorStateRecord PrimaryPlayer,SecondaryPlayer;
  public readonly Dictionary<ActorStateRecord,ActorStateRecord> Opponents=new Dictionary<ActorStateRecord,ActorStateRecord>();
  public QRandom Random;
 }
 public static class LocatorSetCommands
 {
  static float[] Position(ActorStateRecord a){return new float[]{a.X,a.Y,a.Z};}
  //0x453aa0. Caller packet+a8 supplies the default set; a name resolves through
  // the world-owned set collection. The selected set is not saved back toa8.
  public static int Get(LocatorSetCommandWorld world,ScriptPacket numbers,LocatorReservationSet currentSet,ActorStateRecord reference,string[] tokens,bool firstCall)
  {
   if(!firstCall)return 1;
   ActorStateWorld actors=world.Selection.Reservations.Actors;ActorStateRecord target=reference==null?null:reference.WorldObject;
   float range=0,radius=0;int ignore=-1;string name=null;
   bool random=false,next=false,first=false,looping=false,finish=false,primary=false,secondary=false,opponent=false,farthest=false;
   foreach(string raw in tokens)
   {
    string text=SceneryText.C(raw);int at;
    if((at=text.IndexOf("character=",StringComparison.OrdinalIgnoreCase))>=0)target=actors.ResolveObject(text.Substring(at+10));
    else if((at=text.IndexOf("max_range=",StringComparison.OrdinalIgnoreCase))>=0)range=MessageNumbers.Resolve(numbers,text.Substring(at+10));
    else if((at=text.IndexOf("max_player_range=",StringComparison.OrdinalIgnoreCase))>=0){range=MessageNumbers.Resolve(numbers,text.Substring(at+17));primary=true;}
    else if((at=text.IndexOf("max_opponent_range=",StringComparison.OrdinalIgnoreCase))>=0){range=MessageNumbers.Resolve(numbers,text.Substring(at+19));opponent=true;}
    else if((at=text.IndexOf("off_screen_radius=",StringComparison.OrdinalIgnoreCase))>=0)radius=MessageNumbers.Resolve(numbers,text.Substring(at+18));
    else if((at=text.IndexOf("name=",StringComparison.OrdinalIgnoreCase))>=0)name=text.Substring(at+5);
    else if(SceneryText.Equal(text,"random"))random=true;
    else if(SceneryText.Equal(text,"next"))next=true;
    else if(SceneryText.Equal(text,"first"))first=true;
    else if(SceneryText.Equal(text,"looping"))looping=true;
    else if(SceneryText.Equal(text,"finish_at_end"))finish=true;
    else if(SceneryText.Equal(text,"ignore_assigned=TRUE"))ignore=1;
    else if(SceneryText.Equal(text,"ignore_assigned=FALSE"))ignore=0;
    else if(SceneryText.Equal(text,"furthest_from_opponent")){opponent=true;farthest=true;}
    else if(SceneryText.Equal(text,"furthest_from_either_player")){primary=true;secondary=true;farthest=true;}
    else if(SceneryText.Equal(text,"nearest_either_player")){primary=true;secondary=true;}
   }
   if(ignore<0)ignore=next?0:1;
   if(target==null)return 1;
   LocatorReservationSet set=name==null?currentSet:LocatorSetTraversal.Find(world.GlobalSetSystemPresent,world.Sets,world.SetCount,name);
   if(set==null)return 1;
   ActorStateRecord referenceActor=target,enemy;
   if(primary)referenceActor=world.PrimaryPlayer;
   else if(opponent&&world.Opponents.TryGetValue(target,out enemy)&&enemy!=null)referenceActor=enemy;
   LocatorReservationActor actor=world.Selection.Reservations.View(target);
   if(first){if(set.Count!=0){if(!actor.PacketPresent)throw new ArgumentException("First locator requires actor packet.");actor.SelectedLocatorIndex=set.Indices[0];set.Owners[0]=actor.OwnerId;}return 1;}
   else if(next){LocatorSetTraversal.Next(world.Selection.Reservations,set,actor,looping,finish,ignore!=0,world.Random);return 1;}
   float[] point=Position(referenceActor),second=secondary&&world.SecondaryPlayer!=null?Position(world.SecondaryPlayer):null;
   if(random)LocatorSetSelection.Random(world.Selection,set,actor,range,point,radius,ignore!=0);
   else if(farthest)LocatorSetSelection.Farthest(world.Selection,set,actor,range,point,second,radius,ignore!=0);
   else LocatorSetSelection.Nearest(world.Selection,set,actor,range,point,second,radius,ignore!=0);
   return 1;
  }
 }
}
