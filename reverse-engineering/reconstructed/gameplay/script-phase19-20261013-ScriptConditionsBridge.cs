// Ordered raw-memory condition caches and custom-register reference scan; reused native addresses.
using System;
namespace Recovered.Gameplay
{
 public abstract class ScriptConditionServices
 {
  public abstract uint Predicate(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint arg14,uint arg18);
  public abstract uint Expression(TakeoverReleaseMemory m,uint actor,uint packet,uint expression);
 }
 public static class PreparedScriptConditions
 {
  static uint Add(uint p,int offset){return unchecked(p+(uint)offset);}static int Slot(TakeoverReleaseMemory m,uint node){return unchecked((sbyte)m.Read8(node+0xd));}
  static uint Cache(uint packet,uint bank,int slot){return unchecked(packet+(bank*5+10+(uint)slot)*4);}static uint Flag(uint packet,uint bank){return unchecked(packet+0x38+bank*20);}
  static float Float(uint bits){if((bits&0x7f800000)==0x7f800000&&(bits&0x7fffff)!=0&&(bits&0x400000)==0)throw new ArgumentOutOfRangeException("signaling NaN x87 stores/status outside prepared domain");return BitConverter.ToSingle(BitConverter.GetBytes(bits),0);}
  static uint Next(TakeoverReleaseMemory m,uint list,uint current){return m.Read32(current==0?list:current);}
  static uint Expression(TakeoverReleaseMemory m,ScriptConditionServices s,uint bank,uint actor,uint packet,uint node)
  {uint expression=m.Read32(node+0x10);uint result=s.Expression(m,actor,packet,expression);Float(result);uint destination=Cache(packet,bank,Slot(m,node));m.Write32(destination,result);return result;}
  // Existing52c800; customEDI=bank,ECX=current; cdecl(list,actor,packet).
  public static void Finish(TakeoverReleaseMemory m,ScriptConditionServices s,uint bank,uint list,uint actor,uint packet,uint current)
  {
   uint flag=Flag(packet,bank);if(m.Read8(flag+1)==0)return;if(m.Read8(flag)!=0){uint node=Next(m,list,current);while(node!=0){if((m.Read8(node+0xe)&8)!=0)Expression(m,s,bank,actor,packet,node);node=Next(m,list,node);}}m.Write8(flag+1,0);
  }
  // Existing52c880; customEAX=bank; cdecl(system,list,actor,packet). Finite, infinity and quietNaN values; acyclic bounded lists.
  public static uint Evaluate(TakeoverReleaseMemory m,ScriptConditionServices s,uint bank,uint system,uint list,uint actor,uint packet)
  {
   if(packet==0||list==0)return 0;uint node=m.Read32(list),left=0;uint flag=Flag(packet,bank);
   while(node!=0)
   {
    uint descriptor=m.Read32(node+0x1c);bool match=false;
    if(descriptor!=0)
    {
     uint callback=m.Read32(descriptor+4);if(callback!=0){uint arg18=m.Read32(node+0x18),arg14=m.Read32(node+0x14);left=s.Predicate(m,callback,system,packet,actor,arg14,arg18);Float(left);}
     uint rightNode=m.Read32(node+0x28),rightDescriptor=rightNode==0?0:m.Read32(rightNode+0x1c),right;
     if(rightDescriptor!=0){callback=m.Read32(rightDescriptor+4);if(callback!=0){uint arg18=m.Read32(node+0x18),arg14=m.Read32(node+0x14);right=s.Predicate(m,callback,system,packet,actor,arg14,arg18);Float(right);}else right=left;}
     else{ushort flags=m.Read16(node+0xe);if((flags&8)!=0){if(m.Read8(flag)!=0)Expression(m,s,bank,actor,packet,node);right=m.Read32(Cache(packet,bank,Slot(m,node)));}else if((flags&4)!=0)right=m.Read32(Add(packet,0x14+Slot(m,node)*4));else right=m.Read32(node+8);}
     int op=unchecked((sbyte)m.Read8(node+0xc));float a=Float(left),b=Float(right);switch(op){case 0:match=a==b;break;case 1:match=a<b;break;case 2:match=a>b;break;case 3:match=a<=b;break;case 4:match=a>=b;break;case 5:match=a!=b;break;}
    }
    if(match){if((m.Read8(node+0xe)&1)==0){Finish(m,s,bank,list,actor,packet,node);m.Write8(flag,0);return node;}}
    else{while((m.Read8(node+0xe)&1)!=0){node=Next(m,list,node);if(node==0)break;if(m.Read8(flag)!=0&&(m.Read8(node+0xe)&8)!=0){Expression(m,s,bank,actor,packet,node);uint cached=m.Read32(Cache(packet,bank,Slot(m,node)));Float(cached);m.Write32(node+8,cached);}}if(node==0)break;}
    node=Next(m,list,node);
   }
   Finish(m,s,bank,list,actor,packet,0);m.Write8(flag,0);return 0;
  }
 }
 public static class PreparedScriptReferences
 {
  // Existing52caf0: customESI=packet, cdecl(system,actor); signed depth<4 includes negatives and unchecked stack aliases.
  public static uint Scan(TakeoverReleaseMemory m,ScriptConditionServices services,uint system,uint actor,uint packet)
  {
   if(system==0||packet==0)return 0;uint script=m.Read32(packet+4);if(script==0||unchecked((int)m.Read32(packet+0x64))>=4)return 0;
   uint node=m.Read32(script+0x40),stateList=0;bool statePass=false;
   for(;;)
   {
    while(node!=0)
    {
     m.Write8(packet+0x4c,1);m.Write8(packet+0x4d,1);uint guard=node+0x1c,match=0;
     if(m.Read32(guard)==0||PreparedScriptConditions.Evaluate(m,services,1,system,guard,actor,packet)!=0)
     {
      if(m.Read32(node+0xc)!=0){m.Write8(packet+0x38,1);m.Write8(packet+0x39,1);uint other=m.Read32(node+0xc),idle=m.Read32(other+0x38);match=PreparedScriptConditions.Evaluate(m,services,0,system,idle+8,actor,packet);if(match!=0){other=m.Read32(node+0xc);uint target=m.Read32(match+0x24);if(target!=m.Read32(other+0x38)){uint depth=m.Read32(packet+0x64);m.Write32(unchecked(packet+0x54+depth*4),node);m.Write32(packet+0x64,m.Read32(packet+0x64)+1);target=m.Read32(match+0x24);other=m.Read32(node+0xc);PreparedScriptBinding.Bind(m,packet,other,target,0);return 1;}}}
     }
     if(!statePass)m.Read32(packet+4);node=m.Read32(node);
    }
    if(statePass)return 0;uint state=m.Read32(packet+8);if(state==0)return 0;stateList=state+0x1c;node=m.Read32(stateList);statePass=true;
   }
  }
 }
 public sealed class RecoveredConditionDispatcherServices:ScriptDispatcherServices
 {
  readonly ScriptDispatcherServices remaining;readonly ScriptConditionServices conditions;readonly uint packet;
  public RecoveredConditionDispatcherServices(ScriptDispatcherServices remaining,ScriptConditionServices conditions,uint packet){this.remaining=remaining;this.conditions=conditions;this.packet=packet;}
  public override uint Conditions(TakeoverReleaseMemory m,uint bank,uint system,uint list,uint actor,uint p){return PreparedScriptConditions.Evaluate(m,conditions,bank,system,list,actor,p);}
  public override uint References(TakeoverReleaseMemory m,uint system,uint actor){return PreparedScriptReferences.Scan(m,conditions,system,actor,packet);}
  public override void Scratch(TakeoverReleaseMemory m,uint callback,uint system,uint actor,uint p){remaining.Scratch(m,callback,system,actor,p);}public override void Animation(TakeoverReleaseMemory m,uint action,uint actor){remaining.Animation(m,action,actor);}public override uint Command(TakeoverReleaseMemory m,uint callback,uint system,uint p,uint actor,uint a,uint b,uint first,uint delta){return remaining.Command(m,callback,system,p,actor,a,b,first,delta);}
 }
 public static class PreparedEvaluatedScriptDispatcher
 {
  // Fresh adapter per invocation carries actual ESI packet through phase18's native two-argument References port.
  public static void Tick(TakeoverReleaseMemory m,ScriptDispatcherServices remaining,ScriptConditionServices conditions,uint system,uint actor,uint packet,uint deltaBits){PreparedScriptDispatcher.Tick(m,new RecoveredConditionDispatcherServices(remaining,conditions,packet),system,actor,packet,deltaBits);}
 }
 public sealed class RecoveredEvaluatedScriptPipelinePorts:TakeoverPipelinePorts
 {
  readonly TakeoverPipelinePorts remaining;readonly ScriptDispatcherServices dispatch;readonly ScriptConditionServices conditions;public RecoveredEvaluatedScriptPipelinePorts(TakeoverPipelinePorts remaining,ScriptDispatcherServices dispatch,ScriptConditionServices conditions){this.remaining=remaining;this.dispatch=dispatch;this.conditions=conditions;}
  public override void Rebind(TakeoverReleaseMemory m,uint a){PreparedScriptBinding.Rebind(m,a);}public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){PreparedEvaluatedScriptDispatcher.Tick(m,dispatch,conditions,s,p,p,d);}
  public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return remaining.ChangeTakenOverState(m,p);}public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return remaining.ChangeReleasedState(m,p);}public override void Camera(TakeoverReleaseMemory m,uint c,float d){remaining.Camera(m,c,d);}public override void ClearAction(TakeoverReleaseMemory m,uint a){remaining.ClearAction(m,a);}public override void ResetActor(TakeoverReleaseMemory m,uint a){remaining.ResetActor(m,a);}public override void StopActor(TakeoverReleaseMemory m,uint a){remaining.StopActor(m,a);}public override void ResetAnimation(TakeoverReleaseMemory m,uint p){remaining.ResetAnimation(m,p);}public override void PrepareActor(TakeoverReleaseMemory m,uint a){remaining.PrepareActor(m,a);}public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return remaining.DistanceFactor(m,p,t);}public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){remaining.DirectedJump(m,a,t,s,d);}public override void VehicleResponse(TakeoverReleaseMemory m,uint a,uint o){remaining.VehicleResponse(m,a,o);}
 }
}
