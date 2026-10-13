using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
 public sealed class AiOverrideState
 {
  public uint Field1008,Timer1010;
  public byte Source107e,Copy107f,StateE38,StateE39,DefaultE38;
 }
 public sealed class AiOverridePacket {public ActorStateRecord CachedReference;}
 public sealed class AiOverrideWorld
 {
  public TagControlWorld Tags;
  public readonly Dictionary<ActorStateRecord,AiOverrideState> State=new Dictionary<ActorStateRecord,AiOverrideState>();
  internal AiOverrideState Get(ActorStateRecord actor){AiOverrideState state;if(!State.TryGetValue(actor,out state))throw new ArgumentException("Missing actor lifecycle attachment.");return state;}
 }
 public static class PartyControlCommands
 {
  static string Tail(string text,int at,int skip){if(at+skip>text.Length)throw new ArgumentException("Native operand passes terminator.");return text.Substring(at+skip);}
  static int Restrict(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first,bool dropIn)
  {
   if(!first)return 1;
   ActorStateRecord target=reference==null?null:reference.WorldObject;bool enabled=true;
   foreach(string raw in tokens)
   {
    string token=SceneryText.C(raw);MessageNumbers.RequireAscii(token);int at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase);
    if(at>=0)target=world.ResolveObject(Tail(token,at,10));
    else
    {
     at=dropIn?token.IndexOf("tag_to=",StringComparison.OrdinalIgnoreCase):-1;
     if(at>=0){if(world.NameCallback)world.FindReference(Tail(token,at,7));}
     else if(ActorStateWorld.Equal(token,"FALSE"))enabled=false;
    }
   }
   if(target!=null){if(dropIn)target.WeaponFlagsEec=(target.WeaponFlagsEec&~0x4000000u)|(enabled?0x4000000u:0u);else target.ProtectionFlagsEf0=(target.ProtectionFlagsEf0&~0x1000000u)|(enabled?0x1000000u:0u);}
   return 1;
  }
  //0x44fa90. tag_to lookup runs, but its return value is unused.
  public static int CannotDropIn(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first){return Restrict(world,reference,tokens,first,true);}
  //0x44fb90.
  public static int NotWithParty(ActorStateWorld world,ActorStateRecord reference,string[] tokens,bool first){return Restrict(world,reference,tokens,first,false);}
  static void Reset(AiOverrideWorld world,ActorStateRecord actor)
  {
   AiOverrideState state=world.Get(actor);TagControlState tag=world.Tags.Get(actor);state.Timer1010=state.Field1008=0;
   if(tag.Blocked28b!=0){state.Copy107f=state.Source107e;tag.Blocked28b=0;state.StateE38=state.DefaultE38;state.StateE39=4;}
  }
  //0x445910: cache reference identity on entry, not the referenced world object.
  public static int SetAIOverrideControl(AiOverrideWorld world,AiOverridePacket packet,ActorStateRecord reference,string[] tokens,bool first)
  {
   bool enabled=true;
   if(first)
   {
    ActorStateRecord target=reference;
    foreach(string raw in tokens)
    {
     string token=SceneryText.C(raw);MessageNumbers.RequireAscii(token);int at=token.IndexOf("character",StringComparison.OrdinalIgnoreCase);
     if(at>=0){if(world.Tags.Actors.NameCallback)target=world.Tags.Actors.FindReference(Tail(token,at,10));}
     else if(ActorStateWorld.Equal(token,"FALSE"))enabled=false;
    }
    packet.CachedReference=target;
   }
   ActorStateRecord selected=packet.CachedReference;
   if(selected!=null)
   {
    if(enabled&&selected.WorldObject!=null)
    {
     ActorStateRecord actor=selected.WorldObject;Reset(world,actor);
     ActorStateRecord linked=world.Tags.Get(actor).LinkedCd0;if(linked!=null)Reset(world,linked);
    }
    selected.Flags1fc=(selected.Flags1fc&~0x100u)|(enabled?0x100u:0u);
   }
   return 1;
  }
 }
}
