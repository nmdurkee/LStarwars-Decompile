// Ordered prepared-memory Rebind/Bind and native script dispatcher. Child execution is explicit.
using System;
using Recovered.Animation;
namespace Recovered.Gameplay
{
 public static class PreparedScriptBinding
 {
  static float Float(uint bits){return BitConverter.ToSingle(BitConverter.GetBytes(bits),0);}
  static float Finite(uint bits){float value=Float(bits);if(Single.IsNaN(value)||Single.IsInfinity(value))throw new ArgumentOutOfRangeException("finite script float moves");return value;}
  public static uint FindBase(TakeoverReleaseMemory m,uint script)
  {
   uint node=m.Read32(script+0x10);while(node!=0){uint name=m.Read32(node+0x18);if(name!=0){string target="BASE";uint i=0;for(;;i++){byte b=m.Read8(name+i);if(b>127)throw new ArgumentOutOfRangeException("ASCII script names");int folded=b>=97&&b<=122?b-32:b;int wanted=i<4?target[(int)i]:0;if(folded!=wanted)break;if(wanted==0)return node;}}node=m.Read32(node);}return 0;
  }
  public static void Advance(TakeoverReleaseMemory m,uint packet)
  {if(packet==0)return;uint old=m.Read32(packet+0xc),next=old!=0?m.Read32(old):m.Read32(m.Read32(packet+8)+0x10);if(next!=0)m.Write32(packet+0x50,m.Read32(packet+0x50)|1);m.Write32(packet+0xc,next);}
  static ScriptEnvironment Environment(TakeoverReleaseMemory m,uint packet,uint selected,ScriptState state,bool bind)
  {
   ScriptEnvironment result=new ScriptEnvironment();result.PrepareConditionBank=delegate(ScriptPacket p,int bank){uint flags=m.Read32(packet+0x50);if((flags&4)==0)m.Write16(packet+0xb2,0);m.Write32(packet+0x50,flags&0xfffffffbu);m.Write32(packet+8,selected);m.Write32(packet+0xc,0);m.Write32(packet+0x10,0);m.Write8(packet+0x38,1);uint next=m.Read32(m.Read32(packet+8)+0x10);state.FirstAction=next==0?null:new ScriptAction();if(next!=0)m.Write32(packet+0x50,m.Read32(packet+0x50)|1);m.Write32(packet+0xc,next);};
   if(bind)result.ScriptBound=delegate(ScriptPacket p){m.Write8(packet+0xb4,0);m.Write32(packet+0xb8,0);m.Write8(packet+0xb5,0);m.Write32(packet+0xbc,0);m.Write32(packet+0xc0,0);};return result;
  }
  public static void Enter(TakeoverReleaseMemory m,uint packet,uint selected)
  {if(packet==0||selected==0)return;ScriptState state=new ScriptState();ScriptPacket p=new ScriptPacket{Flags=m.Read32(packet+0x50)};new ScriptMachine(Environment(m,packet,selected,state,false)).EnterState(p,state);}
  // Existing514640, supplied nonnull-script path only. Character profile defaults retain sequential raw aliases.
  public static void Bind(TakeoverReleaseMemory m,uint packet,uint script,uint selected,uint profile)
  {
   if(packet==0)return;uint flags=m.Read32(packet+0x50);m.Write32(packet+0x50,flags&0xfffffffbu);m.Write16(packet+0xb2,0);if(script==0)throw new ArgumentOutOfRangeException("nonnull supplied script required; resolver remains external");
   bool empty=m.Read32(packet)==0;m.Write32(packet+4,script);m.Write32(packet+0x10,0);if(empty)m.Write32(packet,script);float[] values=new float[4];
   if(profile==0){for(uint i=0;i<4;i++){uint bits=m.Read32(script+0x1c+i*8);values[i]=Finite(bits);m.Write32(packet+0x14+i*4,bits);}}
   else
   {
    for(uint i=0;i<4;i++){uint bits=m.Read32(profile+0x64+i*4);values[i]=Finite(bits);m.Write32(packet+0x14+i*4,bits);}
    for(uint i=0;i<4;i++)if((m.Read32(profile+0x48)&(2u<<(int)i))==0){uint bits=m.Read32(script+0x1c+i*8);values[i]=Finite(bits);m.Write32(packet+0x14+i*4,bits);}
   }
   bool supplied=selected!=0;if(!supplied)selected=FindBase(m,m.Read32(packet+4));ScriptDefinition definition=new ScriptDefinition();ScriptState state=selected==0?null:new ScriptState{Name=supplied?"Selected":"Base"};if(state!=null)definition.States.Add(state);Array.Copy(values,definition.Parameters,4);
   ScriptPacket p=new ScriptPacket{Flags=flags};new ScriptMachine(Environment(m,packet,selected,state,true)).Bind(p,definition,supplied?state:null,false);
  }
  // 415000 reads idle state before global system. Null base-script exits before both.
  public static void Rebind(TakeoverReleaseMemory m,uint actor)
  {uint packet=actor+0x2c8,script=m.Read32(packet);if(script==0)return;uint idle=m.Read32(script+0x38);uint system=m.Read32(0x802c54);m.Read32(system+0x2ae8);Bind(m,packet,script,idle,0);m.Write32(actor+0x32c,0);}
 }
 public abstract class ScriptDispatcherServices
 {
  public abstract uint Conditions(TakeoverReleaseMemory m,uint bank,uint system,uint list,uint actor,uint packet);
  public abstract uint References(TakeoverReleaseMemory m,uint system,uint actor);
  public abstract void Scratch(TakeoverReleaseMemory m,uint callback,uint system,uint actor,uint packet);
  public abstract void Animation(TakeoverReleaseMemory m,uint action,uint actor);
  public abstract uint Command(TakeoverReleaseMemory m,uint callback,uint system,uint packet,uint actor,uint arg8,uint argC,uint first,uint deltaBits);
 }
 public static class PreparedScriptDispatcher
 {
  static int Signed(uint v){return unchecked((int)v);}static uint Add(uint p,int v){return unchecked(p+(uint)v);}
  static float Float(uint bits){return BitConverter.ToSingle(BitConverter.GetBytes(bits),0);}
  static uint Sum(uint a,uint b,bool subtract){float x=Float(a),y=Float(b);float value=PlaybackWide.Add(PlaybackWide.From(x),PlaybackWide.From(subtract?-y:y)).Store();uint sign=subtract?a&(b^0x80000000u):a&b;if(x==0&&y==0)return sign&0x80000000u;return TakeoverReleaseMemory.Bits(value);}
  static uint Profile(TakeoverReleaseMemory m,uint system,uint actor){byte index=m.Read8(actor+0x138);return index==255?0:m.Read32(system+0x18)+(uint)index*0xa4;}
  static void Return(TakeoverReleaseMemory m,uint system,uint actor,uint packet,uint reference,int index)
  {
   uint state,script,profile=0;if(index==0){profile=Profile(m,system,actor);state=m.Read32(reference+0x14);script=m.Read32(packet);}else{state=m.Read32(reference+0x14);script=m.Read32(m.Read32(Add(packet,index*4+0x50))+0xc);}PreparedScriptBinding.Bind(m,packet,script,state,profile);
  }
  // Existing52cc90. Finite timer/delta/deadline arithmetic; bounded-progress action callbacks.
  public static void Tick(TakeoverReleaseMemory m,ScriptDispatcherServices services,uint system,uint actor,uint packet,uint deltaBits)
  {
   if(packet==0||m.Read32(packet+4)==0)return;uint old=m.Read32(packet+0x24);int initialDepth=Signed(m.Read32(packet+0x64));m.Write32(packet+0x24,Sum(old,deltaBits,false));
   if(initialDepth>0)
   {
    int i=0;do{uint reference=m.Read32(Add(packet,0x54+i*4)),list=reference+0x1c;if(m.Read32(list)!=0&&services.Conditions(m,1,system,list,actor,packet)==0){m.Write32(packet+0x64,(uint)i);Return(m,system,actor,packet,reference,i);break;}i++;}while(i<Signed(m.Read32(packet+0x64)));
   }
   int depth=Signed(m.Read32(packet+0x64));if(depth!=0&&m.Read32(packet+0x10)==0&&m.Read32(m.Read32(packet+4)+0x38)==m.Read32(packet+8))
   {uint reference=m.Read32(Add(packet,depth*4+0x50));depth--;m.Write32(packet+0x64,unchecked((uint)depth));Return(m,system,actor,packet,reference,depth);}
   uint pending=m.Read32(packet+0x10);if(pending!=0){PreparedScriptBinding.Enter(m,packet,pending);m.Write32(packet+0x10,0);}else if(m.Read32(packet+8)==0){uint first=m.Read32(m.Read32(packet+4)+0x10);if(first!=0)PreparedScriptBinding.Enter(m,packet,first);}
   if(m.Read32(packet+8)!=0)
   {
    while(m.Read32(packet+0xc)!=0)
    {
     uint action=m.Read32(packet+0xc),descriptor=m.Read32(action+0x10);uint first=0;
     if(descriptor==0||m.Read32(descriptor+4)==0)m.Write32(packet+0x50,m.Read32(packet+0x50)&0xfffffffeu);
     else
     {
      if((m.Read8(packet+0x50)&1)!=0)
      {
       m.Write32(packet+0x70,0);m.Write8(packet+0x68,0);m.Write32(packet+0x74,0);m.Write8(packet+0x69,0);m.Write32(packet+0x9c,0);m.Write32(packet+0x6c,0);m.Write16(packet+0x6a,0);m.Write16(packet+0xb6,0);m.Write32(packet+0x80,0);m.Write32(packet+0x7c,0);m.Write32(packet+0x78,0);foreach(uint offset in new uint[]{0x84,0x88,0x8c,0x90,0x94,0x98})m.Write32(packet+offset,0);
       if(actor!=0){m.Write32(actor+0x180,0);m.Write8(actor+0x13f,0);m.Write32(actor+0x17c,0);m.Write32(actor+0x1e4,0);uint callback=m.Read32(0x9238ac);if(callback!=0)services.Scratch(m,callback,system,actor,packet);}
       m.Write32(packet+0x50,m.Read32(packet+0x50)&0xfffffffeu);descriptor=m.Read32(action+0x10);first=1;if(m.Read8(descriptor+8)!=0)services.Animation(m,action,actor);
      }
      descriptor=m.Read32(action+0x10);uint argC=m.Read32(action+0xc),arg8=m.Read32(action+8),handler=m.Read32(descriptor+4);if(services.Command(m,handler,system,packet,actor,arg8,argC,first,deltaBits)==0)break;
     }
     if((m.Read8(packet+0x50)&1)==0)PreparedScriptBinding.Advance(m,packet);
    }
   }
   if(services.References(m,system,actor)!=0)return;uint before=m.Read32(packet+0xb8);if(Float(before)>0)m.Write32(packet+0xb8,Sum(m.Read32(packet+0xb8),deltaBits,true));
   if(Float(before)>0&&Float(m.Read32(packet+0xb8))<=0&&m.Read32(packet+0xbc)!=0){PreparedScriptBinding.Enter(m,packet,m.Read32(packet+0xbc));m.Write32(packet+0xbc,0);m.Write8(packet+0xb4,0);return;}
   uint current=m.Read32(packet+8);if(current!=0){uint match=services.Conditions(m,0,system,current+8,actor,packet);if(match!=0){uint message=m.Read16(match+0xe);uint flags=m.Read32(packet+0x50);m.Write32(packet+0x50,flags^(((message*2)^flags)&4));PreparedScriptBinding.Enter(m,packet,m.Read32(match+0x24));}}
  }
 }
 public sealed class RecoveredScriptPipelinePorts:TakeoverPipelinePorts
 {
  readonly TakeoverPipelinePorts remaining;readonly ScriptDispatcherServices dispatch;public RecoveredScriptPipelinePorts(TakeoverPipelinePorts remaining,ScriptDispatcherServices dispatch){this.remaining=remaining;this.dispatch=dispatch;}
  public override void Rebind(TakeoverReleaseMemory m,uint a){PreparedScriptBinding.Rebind(m,a);}public override void RunScript(TakeoverReleaseMemory m,uint s,uint a,uint p,uint d){PreparedScriptDispatcher.Tick(m,dispatch,s,p,p,d);}
  public override int ChangeTakenOverState(TakeoverReleaseMemory m,uint p){return remaining.ChangeTakenOverState(m,p);}public override int ChangeReleasedState(TakeoverReleaseMemory m,uint p){return remaining.ChangeReleasedState(m,p);}public override void Camera(TakeoverReleaseMemory m,uint c,float d){remaining.Camera(m,c,d);}public override void ClearAction(TakeoverReleaseMemory m,uint a){remaining.ClearAction(m,a);}public override void ResetActor(TakeoverReleaseMemory m,uint a){remaining.ResetActor(m,a);}public override void StopActor(TakeoverReleaseMemory m,uint a){remaining.StopActor(m,a);}public override void ResetAnimation(TakeoverReleaseMemory m,uint p){remaining.ResetAnimation(m,p);}public override void PrepareActor(TakeoverReleaseMemory m,uint a){remaining.PrepareActor(m,a);}public override float DistanceFactor(TakeoverReleaseMemory m,uint p,uint t){return remaining.DistanceFactor(m,p,t);}public override void DirectedJump(TakeoverReleaseMemory m,uint a,uint t,float s,float d){remaining.DirectedJump(m,a,t,s,d);}public override void VehicleResponse(TakeoverReleaseMemory m,uint a,uint o){remaining.VehicleResponse(m,a,o);}
 }
}
