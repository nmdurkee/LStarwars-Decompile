using System;
namespace Recovered.Gameplay
{
 public sealed class CategoryWorld
 {
  public ForceActionWorld Capabilities;
  public bool TablePresent=true;
  public string[] Names;
  public OpponentWorld Opponents;
 }
 public static class CategoryCommands
 {
  //0x55bc20: first case-insensitive capability name; null strings never match.
  public static int Find(CategoryWorld world,string name)
  {
   if(!world.TablePresent)return -1;
   for(int i=0;i<world.Capabilities.CapabilityCount;i++)
   {
    if(world.Names==null||i>=world.Names.Length)throw new ArgumentException("Native capability name table must be readable.");
    if(name!=null&&world.Names[i]!=null&&SceneryText.Equal(SceneryText.C(world.Names[i]),SceneryText.C(name)))return i;
   }
   return -1;
  }
  //0x440c00 adds system/name/table gates to the lookup.
  public static int Bind(CategoryWorld world,bool systemPresent,string name){return systemPresent&&name!=null&&world.TablePresent?Find(world,name):-1;}
  //0x440c30 permits a null actor when the capability row needs no actor fields.
  public static float CategoryIs(CategoryWorld world,ActorForceContext context,int bound)
  {
   if(bound==-1||context==null||!context.CreaturePresent||context.Reference==null)return 0;
   if(bound<0||bound>=world.Capabilities.CapabilityCount)return 0;
   if(!world.TablePresent)throw new ArgumentException("Native capability table must be readable.");
   ActorStateRecord actor=context.Reference.WorldObject;ForceActorState fields=null;
   if(actor!=null&&!world.Capabilities.Actors.TryGetValue(actor,out fields))throw new ArgumentException("Missing actor capability fields.");
   return ForceActions.HasCapability(world.Capabilities,fields,bound)!=0?1f:0f;
  }
  //0x455290: non-first calls use defaultfalse and therefore set ef4 bit20.
  public static int UseTimeBasedUpdate(CategoryWorld world,ActorForceContext context,string[] tokens,bool first)
  {
   if(context==null||!context.CreaturePresent||context.Reference==null)return 1;
   ActorStateRecord actor=context.Reference.WorldObject;if(actor==null)throw new ArgumentException("Native update flag write requires a nonnull actor.");bool enabled=false;
   if(first)foreach(string raw in tokens){string token=SceneryText.C(raw);if(SceneryText.Equal(token,"TRUE"))enabled=true;else if(SceneryText.Equal(token,"FALSE"))enabled=false;}
   OpponentFields state=world.Opponents.State(actor);state.FlagsEf4=(state.FlagsEf4&~0x20u)|(enabled?0u:0x20u);return 1;
  }
 }
}
