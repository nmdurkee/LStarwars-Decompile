using System;
namespace Recovered.Gameplay
{
 public sealed class CompactActorWorld
 {
  public OriginPathMemory Memory;
  public int RaceLap;
  public uint RadioState;
 }
 public static class CompactActorConditions
 {
  static uint Actor(OriginPathMemory m,uint creature){if(creature==0)return 0;uint reference=m.U32(creature+0xd0);return reference==0?0:m.U32(reference);}
  public static int CutSceneStatus(OriginPathMemory m,uint state){return(m.U32(state+0x88)&0x1000)!=0?-1:0;}
  public static float CutSceneFinished(CompactActorWorld w,uint record){if(record==0)return 0;uint state=w.Memory.U32(record+4);return state!=0&&CutSceneStatus(w.Memory,state)!=0?1:0;}
  public static float RaceLap(CompactActorWorld w){return(float)w.RaceLap;}
  public static float CanHearRadio(CompactActorWorld w){return w.RadioState==0?0:1;}
  public static float BeingTowed(CompactActorWorld w,uint creature){if(creature==0)return 0;uint reference=w.Memory.U32(creature+0xd0),actor=w.Memory.U32(reference);return(w.Memory.U32(actor+0xef4)&0x200)!=0?1:0;}
  public static float ForcePushing(CompactActorWorld w,uint creature,uint explicitActor){uint actor=explicitActor!=0?explicitActor:Actor(w.Memory,creature);return actor!=0&&w.Memory.U8(actor+0x7b5)==0x1b?1:0;}
  public static float OnGround(CompactActorWorld w,uint creature){uint actor=Actor(w.Memory,creature);return actor!=0&&(w.Memory.U8(actor+0x281)!=0||w.Memory.U8(actor+0x282)!=0)?1:0;}
  public static float PathBlocked(CompactActorWorld w,uint creature){return creature!=0&&(w.Memory.U32(creature+0x1e8)&0x400000)!=0?1:0;}
 }
}
