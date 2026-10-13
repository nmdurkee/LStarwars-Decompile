using System;
using System.Collections.Generic;
namespace Recovered.Gameplay
{
    public sealed class ActivationActorFields
    {
        // Embedded packet at actor+2c8; SetId aliases actor+378.
        public ScriptPacket Packet=new ScriptPacket();
        // Raw companion fields omitted from the older ScriptPacket projection.
        // Their byte/word writes are verified; broader consumers remain separate.
        public byte ConditionBank38,DeadlineB5;
        public uint DeadlineC0;
        public byte Phase406;
        public ActorStateRecord AttachedCd0;
    }
    public abstract class ActorActivationServices
    {
        // 41c120 is the complete spawn/lifecycle reinitialization boundary.
        public abstract void Reinitialize(ActorStateRecord actor,bool systemPresent);
        public abstract void DestroyAttachment(ActorStateRecord attachment,int mode,uint flags);
        public abstract void ReleaseControl(ActorStateRecord actor,bool deactivate);
    }
    public sealed class ActorActivationWorld
    {
        public ActorStateWorld Actors;
        public ScriptMachine Machine;
        public ActorActivationServices Services;
        public readonly Dictionary<ActorStateRecord,ActivationActorFields> Fields=new Dictionary<ActorStateRecord,ActivationActorFields>();
        // Native bytes at 876847+group; increments wrap without saturation.
        public readonly byte[] GroupCounts=new byte[17];
        public byte[] SpawnPhase87;
        public Action<ActorStateRecord,string> ObserveStateChange;
        internal ActivationActorFields Get(ActorStateRecord actor)
        {ActivationActorFields result;if(!Fields.TryGetValue(actor,out result))throw new ArgumentException("Actor activation fields required.");return result;}
        internal bool Change(ActorStateRecord actor,string name)
        {if(ObserveStateChange!=null)ObserveStateChange(actor,name);ActivationActorFields fields=Get(actor);return ActorActivation.ChangeBaseState(Machine,fields.Packet,name,fields);}
    }
    public static class ActorActivation
    {
        // 0x52c790: switch to a named state of the BASE script. Same-script
        // entry preserves parameter/deadline/stack fields; rebinding clears depth.
        public static bool ChangeBaseState(ScriptMachine machine,ScriptPacket packet,string name)
        {return ChangeBaseState(machine,packet,name,null);}
        public static bool ChangeBaseState(ScriptMachine machine,ScriptPacket packet,string name,ActivationActorFields raw)
        {
            if(name==null||packet==null||packet.Script==null)return false;
            if(packet.BaseScript==null)throw new ArgumentException("Native lookup requires a base script.");
            ScriptState state=packet.BaseScript.Find(name);if(state==null)return false;
            if(machine==null)throw new ArgumentNullException("machine");
            if(raw!=null)raw.ConditionBank38=1;
            if(Object.ReferenceEquals(packet.Script,packet.BaseScript))machine.EnterState(packet,state);
            else
            {
                machine.Bind(packet,packet.BaseScript,state,false);packet.Stack.Clear();
                if(raw!=null){raw.DeadlineB5=0;raw.DeadlineC0=0;}
            }
            return true;
        }
        // 0x414bb0: attachment handling precedes active-bit removal. The native
        // state lookup uses the embedded packet, not actor's controller pointer.
        public static void DeactivateActor(ActorActivationWorld world,ActorStateRecord actor)
        {
            if(actor==null)return;ActivationActorFields fields=world.Get(actor);
            if(fields.AttachedCd0!=null)
            {
                if((actor.Flags1f8&0x4000)==0)world.Services.DestroyAttachment(fields.AttachedCd0,4,0);
                else world.Services.ReleaseControl(actor,true);
            }
            actor.Flags1fc&=~0x1000u;
            if(actor.SpawnIndex!=255&&world.Change(actor,"InActive"))
            {
                fields.Phase406=0;
                if(world.SpawnPhase87==null||actor.SpawnIndex>=world.SpawnPhase87.Length)throw new ArgumentException("Loaded spawn-state table required.");
                world.SpawnPhase87[actor.SpawnIndex]=2;return;
            }
            fields.Phase406=4;
        }
        static void ActivateActor(ActorActivationWorld world,ActorStateRecord actor)
        {
            if(actor.SpawnIndex==255){actor.Flags1fc|=0x1000;world.Change(actor,"Base");}
            else world.Services.Reinitialize(actor,world.Actors.SystemPresent);
        }
        static int Group(ScriptPacket packet,string text)
        {
            float value=MessageNumbers.Resolve(packet,text);
            uint word=Single.IsNaN(value)||Single.IsInfinity(value)||(double)value>=9223372036854775808.0||(double)value< -9223372036854775808.0?0u:unchecked((uint)(long)value);
            int number=unchecked((int)word);return number<0||number>16?0:number;
        }
        static int Run(ActorActivationWorld world,ScriptPacket packet,ActorStateRecord reference,string[] tokens,bool firstCall,bool activate)
        {
            if(!firstCall)return 1;ActorStateRecord target=reference==null?null:reference.WorldObject;int group=0;
            if(tokens!=null)foreach(string token in tokens)
            {
                MessageNumbers.RequireAscii(token);int at=token.IndexOf("character=",StringComparison.OrdinalIgnoreCase);
                if(at>=0)target=world.Actors.ResolveObject(token.Substring(at+10));
                else if((at=token.IndexOf("set=",StringComparison.OrdinalIgnoreCase))>=0)group=Group(packet,token.Substring(at+4));
            }
            if(group!=0)
            {
                if(world.Actors.ActiveCount<1)return 1;world.Actors.CheckCount();
                for(int i=0;i<world.Actors.ActiveCount;i++)
                {
                    ActorStateRecord actor=world.Actors.Actors[i];uint required=activate?1u:0x1001u;
                    if((actor.Flags1fc&required)!=required||world.Get(actor).Packet.SetId!=group)continue;
                    if(activate){ActivateActor(world,actor);world.GroupCounts[group]=unchecked((byte)(world.GroupCounts[group]+1));}
                    else DeactivateActor(world,actor);
                }
                return 1;
            }
            if(target!=null)
            {
                if(activate)
                {
                    ActivateActor(world,target);byte selected=world.Get(target).Packet.SetId;
                    if(selected!=0&&selected<17)world.GroupCounts[selected]=unchecked((byte)(world.GroupCounts[selected]+1));
                }
                else DeactivateActor(world,target);
            }
            return 1;
        }
        // 0x4442f0 / 0x444490: ordered name/group selection, first-call only.
        public static int Activate(ActorActivationWorld world,ScriptPacket packet,ActorStateRecord reference,string[] tokens,bool firstCall)
        {return Run(world,packet,reference,tokens,firstCall,true);}
        public static int DeActivate(ActorActivationWorld world,ScriptPacket packet,ActorStateRecord reference,string[] tokens,bool firstCall)
        {return Run(world,packet,reference,tokens,firstCall,false);}
    }
}
