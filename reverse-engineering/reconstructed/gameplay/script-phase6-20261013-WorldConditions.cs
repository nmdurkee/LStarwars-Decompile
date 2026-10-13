// Force gizmo output and same-socket scalar distance; producer/lifetime input boundaries explicit.
using System;
using System.Collections.Generic;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public sealed class Phase6ForceAttachment
 {
  public ForceObjectState Fields;
  public short Mode88;
  public bool Link40Present;
  public byte LinkFlags24;
 }
 public sealed class Phase6ForceWorld
 {
  public SceneryWorld Scenery;
  public int ForceType;
  public readonly Dictionary<SceneryObject,Phase6ForceAttachment> Fields=new Dictionary<SceneryObject,Phase6ForceAttachment>();
 }
 public sealed class Phase6SocketRow {public float Scale78,Offset7c;}
 public sealed class Phase6Socket
 {public readonly Dictionary<short,Phase6SocketRow> Segments=new Dictionary<short,Phase6SocketRow>();}
 public sealed class Phase6SocketRegistry
 {public readonly Dictionary<sbyte,Phase6Socket> Sockets=new Dictionary<sbyte,Phase6Socket>();}
 public sealed class Phase6SocketPosition {public sbyte Socket1;public short Segment2;public float Progress4;}
 public sealed class Phase6SocketActor {public Phase6SocketPosition Socket670=new Phase6SocketPosition();}
 public sealed class Phase6SocketReference {public Phase6SocketActor Target;}
 public sealed class Phase6SocketCreature {public Phase6SocketReference ReferenceD0;}
 public sealed class Phase6SocketWorld {public Phase6SocketRegistry Registry;public Phase6SocketActor PrimaryPlayer;}
 public static class Phase6WorldConditions
 {
  static string C(string s)
  {if(s==null)return null;int z=s.IndexOf('\0');if(z>=0)s=s.Substring(0,z);foreach(char c in s)if(c>127)throw new ArgumentException("Bounded native names must be ASCII.");return s;}
  // 0x440a30 returns gizmo record, unlike ForceComplete's physical target binder.
  public static SceneryGizmo BindForceAtEnd(Phase6ForceWorld world,string operand)
  {if(world==null)throw new ArgumentNullException("world");return world.Scenery.Bindings.Find(world.Scenery.Registry,world.ForceType,C(operand));}
  // 0x467b40, all eight Force outputs; output0 always tests state2, not reverse.
  public static uint ForceOutput(Phase6ForceWorld world,SceneryGizmo record,uint output,int includeInactive)
  {
   if(record==null||record.Target==null)throw new ArgumentException("Native Force output dereferences record's target before activity gate.");
   Phase6ForceAttachment state;if(!world.Fields.TryGetValue(record.Target,out state)||state.Fields==null||state.Fields.Shared==null)throw new ArgumentException("Prepared native Force fields required.");
   ForceObjectState fields=state.Fields;uint flags=fields.Shared.FlagsA0;
   if(includeInactive==0&&!(((flags&2)!=0||state.Mode88!=-1)&&(flags&1)!=0))return 0;
   switch(output)
   {
    case 0:return fields.GroupPresent&&fields.GroupState==2?1u:0u;
    case 1:return fields.GroupPresent&&fields.GroupState!=0?1u:0u;
    case 2:return fields.GroupPresent&&fields.GroupState==0?1u:0u;
    case 3:return state.Link40Present&&(state.LinkFlags24&2)!=0?1u:0u;
    case 4:return state.Link40Present&&(state.LinkFlags24&4)!=0?1u:0u;
    case 5:return(flags&0x10000)!=0?1u:0u;
    case 6:return(uint)ForceActions.IsComplete(fields);
    case 7:return(flags&0x200000)!=0?1u:0u;
    default:return 0;
   }
  }
  // 0x440a90 composes existing registered output dispatcher0x55a1b0.
  public static float ForceAtEnd(Phase6ForceWorld world,SceneryGizmo initialized)
  {return initialized!=null&&SceneryRegistry.Output(world.Scenery.Registry,initialized,0,1)!=0?1f:0f;}
  static uint Bits(float x){return BitConverter.ToUInt32(BitConverter.GetBytes(x),0);}
  static float FromBits(uint x){return BitConverter.ToSingle(BitConverter.GetBytes(x),0);}
  // 0x53f7a0: signed socket/segment indices select prepared pointer-table rows.
  // Native FMUL/FADD retains64-bit x87 precision before one FSTP binary32.
  public static float SocketScalar(Phase6SocketRegistry registry,Phase6SocketPosition placement)
  {
   if(registry==null)return 0f;if(placement==null)throw new ArgumentException("Native placement pointer required.");if(placement.Socket1==-1)return 0f;
   Phase6Socket socket;Phase6SocketRow row;if(!registry.Sockets.TryGetValue(placement.Socket1,out socket)||socket==null||!socket.Segments.TryGetValue(placement.Segment2,out row)||row==null)throw new ArgumentException("Prepared native signed-index socket row required.");
   float result=FiniteX87.Dot3PlusConstant(row.Scale78,0f,0f,placement.Progress4,0f,0f,row.Offset7c);
   // Shared finite helper normalizes exact zero. Native affine negativezero survives
   // only when both exact-zero product and offset are negativezero.
   if(Bits(result)==0&&(row.Scale78==0f||placement.Progress4==0f)&&Bits(row.Offset7c)==0x80000000u&&((Bits(row.Scale78)^Bits(placement.Progress4))&0x80000000u)!=0)return FromBits(0x80000000u);
   return result;
  }
  // 0x442790: no target-null guard once player socket is not sentinel-1.
  public static float SockDistanceToPlayer(Phase6SocketWorld world,Phase6SocketCreature creature)
  {
   if(world==null)throw new ArgumentNullException("world");if(creature==null||creature.ReferenceD0==null||world.PrimaryPlayer==null)return 0f;
   Phase6SocketActor self=creature.ReferenceD0.Target;Phase6SocketPosition player=world.PrimaryPlayer.Socket670;
   if(player.Socket1==-1)return 0f;if(self==null)throw new ArgumentException("Native socket compare dereferences null self target.");
   if(player.Socket1!=self.Socket670.Socket1)return 0f;
   float a=SocketScalar(world.Registry,player),b=SocketScalar(world.Registry,self.Socket670);
   if(Single.IsInfinity(a)||Single.IsInfinity(b)||Single.IsNaN(a)||Single.IsNaN(b))throw new ArgumentException("Bounded socket distance requires finite stored scalar results.");
   return(float)((double)a-b);
  }
 }
}
