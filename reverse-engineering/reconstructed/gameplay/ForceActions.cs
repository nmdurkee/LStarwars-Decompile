using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class ForceObjectState
 {
  // FlagsA0 is shared with ForceConditions through ForcePlatformState.
  public ForcePlatformState Shared;
  public uint Flags74;
  public float Timer4c;
  public bool GroupPresent;
  public int GroupState;
 }
 public sealed class ForceActorState
 {
  public bool DefinitionPresent=true,ClassPresent=true,InputPresent=true;
  public uint DefinitionFlags4,ClassFlags90,ClassFlags94,Input8;
  public ushort Input5a;
 }
 public sealed class ForceCapability {public uint DefinitionMask,ClassMask;}
 public sealed class ForceActionPacket
 {
  public byte Throwable68,InRange69;
  public SceneryObject Selected6c;
  public float Timer9c;
 }
 public sealed class ForceActionContext
 {
  public bool CreaturePresent=true,AttachmentD4;
  public ActorStateRecord Reference;
  // Native stores address selected+1c; the projection retains its owner.
  public SceneryObject Goal1e4;
 }
 public sealed class ForceActionWorld
 {
  public ForceConditionWorld Conditions;
  public QRandom Random;
  public bool RetryEnabled;
  public uint RetryInputMask;
  public int CapabilityCount;
  public readonly List<ForceCapability> Capabilities=new List<ForceCapability>();
  public readonly Dictionary<SceneryObject,ForceObjectState> Objects=new Dictionary<SceneryObject,ForceObjectState>();
  public readonly Dictionary<ActorStateRecord,ForceActorState> Actors=new Dictionary<ActorStateRecord,ForceActorState>();
 }
 public static class ForceActions
 {
  //0x467890: flags, timer, then optional playback group completion.
  public static int IsComplete(ForceObjectState target)
  {
   uint flags=target.Shared.FlagsA0;
   if((target.Flags74&2)!=0||(target.Timer4c>0&&(flags&0x2000)==0)||((target.Flags74&0x40)!=0&&(flags&0x800)==0))return 0;
   if(target.GroupPresent&&target.GroupState!=((flags&0x40)!=0?0:2))return 0;return 1;
  }
  //0x55bc80: capability row lookup with the bit8 class exclusion.
  public static int HasCapability(ForceActionWorld world,ForceActorState actor,int index)
  {
   if(index<0||index>=world.CapabilityCount)return 0;
   if(index>=world.Capabilities.Count)throw new ArgumentException("Missing capability table backing.");ForceCapability capability=world.Capabilities[index];uint mask=capability.DefinitionMask;
   if(mask!=0)
   {
    if(actor==null||!actor.DefinitionPresent)throw new ArgumentException("Missing actor definition.");
    if((mask&8)!=0){if(!actor.ClassPresent)throw new ArgumentException("Missing actor class.");if((actor.ClassFlags94&0x8000)!=0)return 0;}
    if((actor.DefinitionFlags4&mask)!=mask)return 0;
   }
   if(capability.ClassMask!=0){if(actor==null||!actor.DefinitionPresent||!actor.ClassPresent)throw new ArgumentException("Missing actor class.");if((actor.ClassFlags90&capability.ClassMask)!=capability.ClassMask)return 0;}
   return 1;
  }
  //0x441570 distinct native entry, identical lookup to440ff0.
  public static SceneryObject BindComplete(ForceActionWorld world,string name){return ForceConditions.BindUsingForce(world.Conditions,name);}
  //0x4415a0.
  public static float Complete(ForceActionWorld world,SceneryObject bound){return bound!=null&&IsComplete(world.Objects[bound])!=0?1f:0f;}
  //0x450030: first-call target selection and subsequent persistent request writes.
  public static int UseForce(ForceActionWorld world,ForceActionContext context,ForceActionPacket packet,string[] tokens,bool first,float delta)
  {
   if(context==null||!context.CreaturePresent||context.Reference==null||context.Reference.WorldObject==null)return 1;
   ActorStateRecord actor=context.Reference.WorldObject;bool triggered=false;
   if(first)
   {
    packet.Selected6c=null;List<SceneryObject> choices=new List<SceneryObject>();
    foreach(string raw in tokens)
    {
     string token=SceneryText.C(raw);
     if(SceneryText.Equal(token,"throwable"))packet.Throwable68=1;
     else if(SceneryText.Equal(token,"inrange"))packet.InRange69=1;
     else if(SceneryText.Equal(token,"triggered_by_hit"))triggered=true;
     else if(choices.Count<16)
     {
      int at=token.IndexOf("name=",StringComparison.OrdinalIgnoreCase);string name=at<0?token:token.Substring(at+5);
      SceneryObject target=ForceConditions.BindUsingForce(world.Conditions,name);
      if(target!=null){uint flags=world.Objects[target].Shared.FlagsA0;if((flags&2)!=0&&(flags&0x10000)==0)choices.Add(target);}
     }
    }
    if(choices.Count!=0){if(world.Random==null)throw new ArgumentException("Missing shared random state.");packet.Selected6c=choices[(int)world.Random.Next()/(65535/choices.Count+1)];}
   }
   SceneryObject selected=packet.Selected6c;if(selected==null)return 1;
   ForceObjectState state=world.Objects[selected];if((state.Shared.FlagsA0&1)==0)return 0;
   ForceActorState own=world.Actors[actor];bool allowed=HasCapability(world,own,(state.Flags74&0x10)!=0?1:0)!=0;
   if(triggered){state.Shared.FlagsA0|=0x8000;return 0;}
   if(allowed)
   {
    if(!own.InputPresent)throw new ArgumentException("Missing actor input backing.");context.Goal1e4=selected;own.Input5a|=4;world.Conditions.ForceTargets[actor]=selected;
    if(packet.Throwable68!=0){if(context.AttachmentD4)return 1;own.Input5a=(ushort)(own.Input5a&0xfffb);world.Conditions.ForceTargets[actor]=null;return 1;}
    if(IsComplete(state)!=0)return 1;
   }
   else if(world.RetryEnabled)
   {
    double approximate=(double)packet.Timer9c-delta;packet.Timer9c=PlaybackWide.Add(PlaybackWide.From(packet.Timer9c),PlaybackWide.From(-delta)).Store();if(packet.Timer9c==0&&BitConverter.DoubleToInt64Bits(approximate)<0)packet.Timer9c=PcObjectImage.FromBits(0x80000000u);
    if(packet.Timer9c<0){packet.Timer9c=.5f;if(!own.InputPresent)throw new ArgumentException("Missing actor input backing.");own.Input8|=world.RetryInputMask;}
   }
   return 0;
  }
 }
}
