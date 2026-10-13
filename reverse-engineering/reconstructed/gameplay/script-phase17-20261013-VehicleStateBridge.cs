// Vehicle timer/re-entry and lazy prepared-memory hydration of existing script state core.
using System;
using System.Text;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class VehicleResponseTimer
 {
  // 5a03d0: matching signed byte vs full DWORD ticks; otherwise sentinel context can re-enter.
  public static void Update(TakeoverReleaseMemory m,VehicleResponseServices services,uint actor,uint retry)
  {
   int configured=unchecked((int)m.Read32(0x8028a8));int context;
   if(configured!=-1&&(context=unchecked((sbyte)m.Read8(actor+0x7b5)))==configured)
   {
    uint old=m.Read32(actor+0x77c),delta=m.Read32(0x925018);float a=BitConverter.ToSingle(BitConverter.GetBytes(old),0),b=BitConverter.ToSingle(BitConverter.GetBytes(delta),0);
    float value=PlaybackWide.Add(PlaybackWide.From(a),PlaybackWide.From(-b)).Store();if(a==0&&b==0)value=BitConverter.ToSingle(BitConverter.GetBytes(old&(delta^0x80000000u)&0x80000000u),0);
    m.Write32(actor+0x77c,TakeoverReleaseMemory.Bits(value));if(value<=0)m.Write8(actor+0x7b5,255);return;
   }
   if(m.Read8(actor+0x7b5)==255&&retry!=0)VehicleResponseProducer.Respond(m,services,actor,m.Read32(actor+0xcd0));
  }
 }
 public static class PreparedBaseScriptState
 {
  // ASCII names and acyclic native linked state lists. Stop at first mismatch/match: later bytes/nodes remain lazy.
  static bool Match(TakeoverReleaseMemory m,uint requested,uint candidate,out string name)
  {
   name=null;if(candidate==0)return false;StringBuilder text=new StringBuilder();
   for(uint i=0;;i++){byte a=m.Read8(requested+i),b=m.Read8(candidate+i);if(a>127||b>127)throw new ArgumentOutOfRangeException("ASCII state names required");int fa=a>=97&&a<=122?a-32:a,fb=b>=97&&b<=122?b-32:b;if(fa!=fb)return false;if(a==0){name=text.ToString();return true;}text.Append((char)a);}
  }
  // 52c790 existing address. Uses unchanged ActorActivation.ChangeBaseState and ScriptMachine state/bind core.
  // Raw prefix commits precede lazy first-action hydration; aliases/default copies and partial faults stay ordered.
  public static int Change(TakeoverReleaseMemory m,uint packet,uint requested)
  {
   if(requested==0||packet==0)return 0;uint current=m.Read32(packet+4);if(current==0)return 0;uint script=m.Read32(packet);uint node=m.Read32(script+0x10);string matched=null;
   while(node!=0){if(Match(m,requested,m.Read32(node+0x18),out matched))break;node=m.Read32(node);}if(node==0)return 0;
   // Native re-reads base/current after lookup, before selecting enter/bind.
   script=m.Read32(packet);current=m.Read32(packet+4);bool same=current==script;uint initialFlags=m.Read32(packet+0x50);
   ScriptDefinition definition=new ScriptDefinition();ScriptState state=new ScriptState{Name=matched};definition.States.Add(state);
   ScriptPacket projection=new ScriptPacket{BaseScript=definition,Script=same?definition:new ScriptDefinition(),Flags=initialFlags};
   if(!same)
   {
    m.Write32(packet+0x50,initialFlags&0xfffffffbu);m.Write16(packet+0xb2,0);bool emptyBase=m.Read32(packet)==0;m.Write32(packet+4,script);m.Write32(packet+0x10,0);if(emptyBase)m.Write32(packet,script);
    for(uint i=0;i<4;i++){uint value=m.Read32(script+0x1c+i*8);float f=BitConverter.ToSingle(BitConverter.GetBytes(value),0);if(Single.IsNaN(f)||Single.IsInfinity(f))throw new ArgumentOutOfRangeException("finite script default float moves");m.Write32(packet+0x14+i*4,value);definition.Parameters[i]=f;}
   }
   ScriptEnvironment environment=new ScriptEnvironment();
   environment.PrepareConditionBank=delegate(ScriptPacket p,int bank)
   {
    uint flags=m.Read32(packet+0x50);if((flags&4)==0)m.Write16(packet+0xb2,0);m.Write32(packet+0x50,flags&0xfffffffbu);m.Write32(packet+8,node);m.Write32(packet+0xc,0);m.Write32(packet+0x10,0);m.Write8(packet+0x38,1);
    uint action=m.Read32(m.Read32(packet+8)+0x10);state.FirstAction=action==0?null:new ScriptAction();if(action!=0)m.Write32(packet+0x50,m.Read32(packet+0x50)|1);m.Write32(packet+0xc,action);
   };
   bool changed=ActorActivation.ChangeBaseState(new ScriptMachine(environment),projection,matched,new ActivationActorFields());
   if(!same){m.Write8(packet+0xb4,0);m.Write32(packet+0xb8,0);m.Write8(packet+0xb5,0);m.Write32(packet+0xbc,0);m.Write32(packet+0xc0,0);m.Write32(packet+0x64,0);}return changed?1:0;
  }
 }
 public sealed class RecoveredBaseStatePipelinePorts:TakeoverPipelinePorts
 {
  readonly TakeoverPipelinePorts remaining;public RecoveredBaseStatePipelinePorts(TakeoverPipelinePorts remaining){this.remaining=remaining;}
  public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return PreparedBaseScriptState.Change(m,p,0x759958);}public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return PreparedBaseScriptState.Change(m,p,0x759978);}
  public override void Camera(TakeoverReleaseMemory m,uint c,float d){remaining.Camera(m,c,d);}public override void Rebind(TakeoverReleaseMemory m,uint a){remaining.Rebind(m,a);}public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){remaining.RunScript(m,s,a,p,d);}public override void ClearAction(TakeoverReleaseMemory m,uint a){remaining.ClearAction(m,a);}public override void ResetActor(TakeoverReleaseMemory m,uint a){remaining.ResetActor(m,a);}public override void StopActor(TakeoverReleaseMemory m,uint a){remaining.StopActor(m,a);}public override void ResetAnimation(TakeoverReleaseMemory m,uint p){remaining.ResetAnimation(m,p);}public override void PrepareActor(TakeoverReleaseMemory m,uint a){remaining.PrepareActor(m,a);}public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return remaining.DistanceFactor(m,p,t);}public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){remaining.DirectedJump(m,a,t,s,d);}public override void VehicleResponse(TakeoverReleaseMemory m,uint a,uint o){remaining.VehicleResponse(m,a,o);}
 }
}
