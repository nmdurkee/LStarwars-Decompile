// Composition only: connects the previously recovered ScriptMachine.Bind
// projection to ordinary player transfer. No new native function is claimed.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public class PlayerTransferScriptBridge:PlayerTransferServices
    {
        public readonly ScriptMachine Machine;
        public readonly Dictionary<ActorStateRecord,ScriptPacket> Packets=new Dictionary<ActorStateRecord,ScriptPacket>();
        public Action<uint,float> Feedback;
        public PlayerTransferScriptBridge(ScriptMachine machine)
        {if(machine==null)throw new ArgumentNullException("machine");Machine=machine;}
        public override void InitializeBaseScript(ActorStateRecord actor,object script,object state)
        {
            ScriptPacket packet;ScriptDefinition definition=script as ScriptDefinition;ScriptState selected=state as ScriptState;
            if(definition==null||(state!=null&&selected==null)||!Packets.TryGetValue(actor,out packet))throw new ArgumentException("Resolved script, state and embedded packet attachment required.");
            Machine.Bind(packet,definition,selected,false);
            // 0x415000 clears actor+0x32c (packet+0x64 depth) after0x514640.
            // Keep the typed reference stack synchronized with that same field.
            packet.Stack.Clear();
        }
        public override void PlatformFeedback(uint handle,float duration)
        {if(Feedback==null)throw new InvalidOperationException("Platform feedback service required.");Feedback(handle,duration);}
    }
}
