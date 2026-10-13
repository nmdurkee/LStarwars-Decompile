// Original-PC ordinary player transfer (0x4876a0 mode0). Takeover mode1 is
// deliberately not represented. Script initialization and platform feedback
// remain explicit services. Tag controls share the same attached state records.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class PlayerTransferInput
    {
        public uint FeedbackHandle;
    }
    public sealed class PlayerTransferState
    {
        public PlayerTransferInput Input;
        public byte[] Auxiliary800;
        public sbyte PersonalIndex;
        public byte MaximumHealth,Health,AlternateHealth,TuningMaximumHealth;
        public object BaseScript,BaseState;
        // Opaque preserved/swap fields retain native offsets as evidence labels.
        public uint FieldDa8,Field7fc,FieldDec,FieldEa8,Field1000;
        public uint TimerD60,TimerDa4,FieldEe4,FieldEe8,ScriptCounter32c;
        // Fields reached by reset helper4a4ca0 from actor+0x6c4.
        public uint ResetD80,ResetD84,ResetD14,ResetD90,ResetD18,ResetD88;
    }
    public abstract class PlayerTransferServices
    {
        // 0x514640(system,embedded,embedded,0,0,0,0,baseScript,baseState).
        public abstract void InitializeBaseScript(ActorStateRecord actor,object script,object state);
        // 0x698900(handle,duration,0,0,0). No platform API is invoked here.
        public abstract void PlatformFeedback(uint handle,float duration);
    }
    public sealed class PlayerTransferWorld
    {
        public TagControlWorld Tags;
        public PlayerTransferServices Services;
        public readonly Dictionary<ActorStateRecord,PlayerTransferState> State=new Dictionary<ActorStateRecord,PlayerTransferState>();
        public bool Blocked,SpecialLevel;
        public byte DefaultMaximumHealth;
        public uint TransferTimeBits;
        public float FeedbackDivisor;
        public ActorStateRecord PairFrom,PairTo;
        public uint PairWord0,PairWord1;
        internal PlayerTransferState Get(ActorStateRecord actor)
        {PlayerTransferState state;if(actor==null||!State.TryGetValue(actor,out state))throw new ArgumentException("Missing transfer-state attachment.");return state;}
    }
    public static class PlayerTransfer
    {
        static void Swap(ref uint a,ref uint b){uint temp=a;a=b;b=temp;}
        // 0x4a4ca0, projection of its six fields at actor+0x6c4.
        public static void ResetTransientState(PlayerTransferState state)
        {state.ResetD80=state.ResetD84=state.ResetD14=state.ResetD90=state.ResetD18=0;state.ResetD88=0x3e4ccccd;}
        // 0x466820, exact0x630-byte clear of nullable actor+0x800 backing.
        public static void ClearAuxiliary(PlayerTransferState state)
        {
            if(state.Auxiliary800==null)return;
            if(state.Auxiliary800.Length<0x630)throw new ArgumentException("Auxiliary backing is shorter than the native clear.");
            Array.Clear(state.Auxiliary800,0,0x630);
        }
        // 0x415000; full script initializer is a service, wrapper is recovered.
        public static void RebindBaseScript(PlayerTransferWorld world,ActorStateRecord actor)
        {
            PlayerTransferState state=world.Get(actor);if(state.BaseScript==null)return;
            if(world.Services==null)throw new InvalidOperationException("Script initialization service required.");
            world.Services.InitializeBaseScript(actor,state.BaseScript,state.BaseState);state.ScriptCounter32c=0;
        }
        // 0x54a8d0, bounded finite divisor; the duration is stored to binary32.
        public static void Feedback(PlayerTransferWorld world,uint handle,int amount)
        {
            if(handle==0)return;
            if(world.FeedbackDivisor==0||Single.IsNaN(world.FeedbackDivisor)||Single.IsInfinity(world.FeedbackDivisor))throw new ArgumentOutOfRangeException("FeedbackDivisor");
            if(world.Services==null)throw new InvalidOperationException("Platform feedback service required.");
            world.Services.PlatformFeedback(handle,MessageNumbers.Round((float)((double)amount/world.FeedbackDivisor)));
        }
        static void AssignPlayerAndMaximum(PlayerTransferWorld world,ActorStateRecord actor,PlayerTransferState state)
        {
            if(state.PersonalIndex!=-1)
            {
                if(state.PersonalIndex<0||state.PersonalIndex>=8)throw new ArgumentOutOfRangeException("PersonalIndex");
                world.Tags.Actors.Players[state.PersonalIndex]=actor;
            }
            if(state.PersonalIndex==-1||world.Tags.Get(actor).LinkedCd0!=null)state.MaximumHealth=state.TuningMaximumHealth;
            else if(!world.SpecialLevel)state.MaximumHealth=world.DefaultMaximumHealth;
        }
        // 0x4876a0 ordinary mode0. Fourth/fifth native arguments have no effects
        // in this mode. Native body returns only0(blocked) or1(completed).
        public static int Transfer(PlayerTransferWorld world,ActorStateRecord source,ActorStateRecord target)
        {
            if(world.Blocked)return 0;
            PlayerTransferState a=world.Get(source),b=world.Get(target);
            byte healthA=a.Health,healthB=b.Health;uint activeA=source.Flags1fc,activeB=target.Flags1fc;
            ResetTransientState(a);ResetTransientState(b);
            PlayerTransferInput input=a.Input;a.Input=b.Input;b.Input=input;
            source.Flags1fc=(source.Flags1fc&~0x80u)|(activeB&0x80);target.Flags1fc=(target.Flags1fc&~0x80u)|(activeA&0x80);
            Swap(ref a.FieldDa8,ref b.FieldDa8);Swap(ref a.Field7fc,ref b.Field7fc);
            sbyte index=a.PersonalIndex;a.PersonalIndex=b.PersonalIndex;b.PersonalIndex=index;
            Swap(ref a.FieldDec,ref b.FieldDec);
            byte[] auxiliary=a.Auxiliary800;a.Auxiliary800=b.Auxiliary800;b.Auxiliary800=auxiliary;
            ClearAuxiliary(a);ClearAuxiliary(b);
            uint flags=source.Flags1f8;const uint mask=0x46f8;
            source.Flags1f8=(source.Flags1f8&~mask)|(target.Flags1f8&mask);target.Flags1f8=(target.Flags1f8&~mask)|(flags&mask);
            Swap(ref a.FieldEa8,ref b.FieldEa8);Swap(ref a.Field1000,ref b.Field1000);
            RebindBaseScript(world,source);
            a.TimerD60=0;a.TimerDa4=world.TransferTimeBits;source.ProtectionFlagsEf0=(source.ProtectionFlagsEf0&0xffe7ffff)|0x80;a.FieldEe4=a.FieldEe8=0;
            b.TimerD60=0x40000000;target.ProtectionFlagsEf0|=0x80;b.TimerDa4=world.TransferTimeBits;
            if(b.Input==null)throw new ArgumentException("Ordinary transfer requires a target input attachment.");
            Feedback(world,b.Input.FeedbackHandle,2);
            AssignPlayerAndMaximum(world,source,a);AssignPlayerAndMaximum(world,target,b);
            b.Health=healthA;
            // The PC comparison sign-extends the old health byte. Values128..255
            // do not clamp against an unsigned maximum; preserve that behavior.
            if(b.MaximumHealth<unchecked((sbyte)healthA))b.Health=b.MaximumHealth;
            if(b.Health==0&&b.MaximumHealth!=0)b.Health=1;
            if(world.SpecialLevel||(source.Flags1fc&0x80)!=0)a.Health=healthB;
            else
            {
                if(source.Definition==null)throw new ArgumentException("Source character definition required.");
                a.Health=(source.Definition.Flags&0x20)==0?a.MaximumHealth:a.AlternateHealth;
            }
            target.ProtectionFlagsEf0&=0xffe7ffff;b.FieldEe4=b.FieldEe8=0;world.Tags.Get(target).Wait7c0=1;
            if(Object.ReferenceEquals(source,world.PairFrom)&&!Object.ReferenceEquals(target,world.PairTo))
            {world.PairFrom=world.PairTo=null;world.PairWord0=world.PairWord1=0;}
            return 1;
        }
    }
    // Connects the recovered ordinary path directly to the existing tag module.
    // Vehicle/takeover release remains a separately required service.
    public sealed class OrdinaryPlayerTransferAdapter:TagControlServices
    {
        public readonly PlayerTransferWorld World;
        public Action<ActorStateRecord> ReleaseService;
        public OrdinaryPlayerTransferAdapter(PlayerTransferWorld world){World=world;}
        public override int Transfer(ActorStateRecord from,ActorStateRecord to,uint argument)
        {return PlayerTransfer.Transfer(World,from,to);}
        public override void Release(ActorStateRecord actor)
        {if(ReleaseService==null)throw new InvalidOperationException("Vehicle/takeover release service required.");ReleaseService(actor);}
    }
}
