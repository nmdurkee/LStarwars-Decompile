using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class GraphActorPlacement
 {
  // Position storage is shared: the native callee receives buildit+34, not a copy.
  public uint[] PositionWords;
  public ushort Heading;
 }
 public abstract class GraphActorServices
 {
  public abstract ActorStateRecord Activate(string name,GraphActorPlacement placement,ushort heading);
  public abstract void Deactivate(string name);
  public abstract void Release(ActorStateRecord actor);
  public abstract void BuildFailureEffects(SceneryObject buildIt);
 }
 public sealed class GraphActorGlobals
 {
  public ActorStateWorld Current;
  public TagControlWorld Tags;
  public SceneryWorld Scenery;
  public int BuildItType;
  public GraphActorServices Services;
  public readonly Dictionary<SceneryObject,GraphActorPlacement> Placements=new Dictionary<SceneryObject,GraphActorPlacement>();
 }
 public static class GraphActorActivation
 {
  //0x55f450, the current-world pointer is read once before parsing.
  public static ActorStateWorld GetCurrent(GraphActorGlobals globals){return globals.Current;}
  static bool Eligible(GraphActorGlobals globals,ActorStateRecord actor)
  {return actor!=null&&(actor.Flags1fc&0x1000)!=0&&globals.Tags.Get(actor).Blocked28b==0&&actor.SpawnIndex!=255;}
  static bool SpawnNameMatches(ActorStateWorld world,ActorStateRecord actor,string name)
  {
   if(world==null||actor==null)throw new ArgumentException("Native name lookup requires current world and primary actor.");
   return SceneryText.Equal(SceneryText.C(world.SpawnAt(actor.SpawnIndex).Name),name);
  }
  //0x4648e0: graph ActivateChar. Lifecycle and effect services stay explicit.
  public static void Execute(GraphActorGlobals globals,string[] tokens)
  {
   ActorStateWorld current=GetCurrent(globals);string name=null;bool active=true;SceneryObject buildIt=null;
   foreach(string raw in tokens)
   {
    string token=SceneryText.C(raw);int at=SceneryText.Index(token,"name=");
    if(at>=0)name=token.Substring(at+5);
    else if(SceneryText.Equal(token,"TRUE"))active=true;
    else if(SceneryText.Equal(token,"FALSE"))active=false;
    else if((at=SceneryText.Index(token,"buildit="))>=0)
    {
     SceneryGizmo found=globals.Scenery.Bindings.Find(globals.Scenery.Registry,globals.BuildItType,token.Substring(at+8));
     if(found!=null&&found.Target!=null)buildIt=found.Target;
    }
   }
   if(name==null)return;
   if(active)
   {
    GraphActorPlacement placement=null;
    if(buildIt!=null&&!globals.Placements.TryGetValue(buildIt,out placement))throw new ArgumentException("Missing buildit placement backing.");
    ushort heading=placement==null?(ushort)0:placement.Heading;
    if(globals.Services.Activate(name,placement,heading)==null&&buildIt!=null)globals.Services.BuildFailureEffects(buildIt);
    return;
   }
   ActorStateRecord primary=globals.Tags.Actors.Players[0];
   if(Eligible(globals,primary)&&SpawnNameMatches(current,primary,name))globals.Services.Release(globals.Tags.Actors.Players[0]);
   ActorStateRecord secondary=globals.Tags.Actors.Players[1];
   //Original464a88 gates on secondary but uses PRIMARY's spawn index.
   if(Eligible(globals,secondary)&&SpawnNameMatches(current,globals.Tags.Actors.Players[0],name))globals.Services.Release(globals.Tags.Actors.Players[1]);
   globals.Services.Deactivate(name);
  }
 }
}
