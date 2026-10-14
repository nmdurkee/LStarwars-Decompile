// Raw trigger membership uses x86SHL32 followedbyCDQ sign-extension, plus nullable trigger bindings.
namespace Recovered.Gameplay
{
 public abstract class ScriptTriggerBindingServices{public abstract uint Find(TakeoverReleaseMemory m,uint system,uint name);}
 public static class PreparedScriptTriggerPredicates
 {
  static uint Bool(bool b){return b?0x3f800000u:0;}
  static uint Select(TakeoverReleaseMemory m,uint packet,uint bound){return bound!=0?bound:m.Read32(packet+0xa0);}
  static uint Member(TakeoverReleaseMemory m,uint area,uint creature){if(area==0)return 0;uint owner=m.Read32(area+0x38);if(owner==0)return 0;int index=unchecked((int)(area-m.Read32(owner+0x38)))>>6;uint low=1u<<(index&31),high=(low&0x80000000)!=0?0xffffffffu:0;return Bool(((m.Read32(creature+0x2b0)&low)|(m.Read32(creature+0x2b4)&high))!=0);}
  public static uint InTriggerArea(TakeoverReleaseMemory m,uint packet,uint actor,uint bound){if(actor==0)return 0;uint controller=m.Read32(actor+0xd0);return controller==0?0:Member(m,Select(m,packet,bound),controller);}
  public static uint PlayerInTriggerArea(TakeoverReleaseMemory m,uint system,uint packet,uint bound){if(system==0)return 0;uint player=m.Read32(system+0x138c);if(player==0||m.Read32(system+0x38)==0)return 0;return Member(m,Select(m,packet,bound),player);}
  public static uint Player2InTriggerArea(TakeoverReleaseMemory m,uint system,uint packet,uint bound){if(system==0)return 0;uint player=m.Read32(system+0x1390);return player==0?0:Member(m,Select(m,packet,bound),player);}
  public static uint EitherPlayerInTriggerArea(TakeoverReleaseMemory m,uint system,uint packet,uint bound){if(system==0)return 0;uint area=Select(m,packet,bound);if(area==0)return 0;uint player=m.Read32(system+0x138c);if(player!=0&&Member(m,area,player)!=0)return 0x3f800000;player=m.Read32(system+0x1390);return player==0?0:Member(m,area,player);}
  public static uint BaddyInTriggerArea(TakeoverReleaseMemory m,uint packet,uint bound){uint area=Select(m,packet,bound);return Bool(area!=0&&(m.Read8(area+0x2a)&4)!=0);}
  public static uint GoodyInTriggerArea(TakeoverReleaseMemory m,uint packet,uint bound){uint area=Select(m,packet,bound);return Bool(area!=0&&(m.Read8(area+0x2a)&2)!=0);}
  public static uint OpponentInTriggerArea(TakeoverReleaseMemory m,uint packet,uint actor,uint bound){if(actor==0)return 0;uint opponent=m.Read32(actor+0xe4);if(opponent==0||m.Read32(actor+0xd0)==0)return 0;return Member(m,Select(m,packet,bound),opponent);}
  public static uint Bind(TakeoverReleaseMemory m,ScriptTriggerBindingServices s,uint system,uint name){return name==0?0:s.Find(m,system,name);}
  public static bool TryEvaluate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint bound,out uint result){switch(callback){case 0x514bd0:result=InTriggerArea(m,packet,actor,bound);break;case 0x514fb0:result=PlayerInTriggerArea(m,system,packet,bound);break;case 0x515010:result=Player2InTriggerArea(m,system,packet,bound);break;case 0x515070:result=EitherPlayerInTriggerArea(m,system,packet,bound);break;case 0x515100:result=BaddyInTriggerArea(m,packet,bound);break;case 0x515130:result=GoodyInTriggerArea(m,packet,bound);break;case 0x515160:result=OpponentInTriggerArea(m,packet,actor,bound);break;default:result=0;return false;}return true;}
 }
}
