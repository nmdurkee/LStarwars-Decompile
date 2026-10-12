// Bounded portable projection of PC SCP state/reference scheduling.
// Conditions, game command handlers, text loading and creature effects are adapters.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class ScriptMatch
    {
        public ScriptState Target;
        public bool KeepBlockedMessages;
    }
    public sealed class ScriptAction
    {
        public ScriptAction Next;
        public Func<ScriptPacket, bool, float, bool> Handler;
        public bool AnimationOverrideOnEntry;
    }
    public sealed class ScriptState
    {
        public string Name;
        public ScriptAction FirstAction;
        // Null represents an empty native list; this is an ordered-condition evaluator adapter.
        public Func<ScriptPacket, ScriptMatch> Conditions;
        public readonly List<ScriptReference> References = new List<ScriptReference>();
    }
    public sealed class ScriptDefinition
    {
        public readonly List<ScriptState> States = new List<ScriptState>();
        public readonly List<ScriptReference> References = new List<ScriptReference>();
        public readonly float[] Parameters = new float[4];
        public readonly string[] ParameterNames = new string[4];
        public ScriptState IdleState;
        public ScriptState Find(string name)
        {
            if (name == null) return null;
            foreach (ScriptState state in States) if (String.Equals(name, state.Name, StringComparison.OrdinalIgnoreCase)) return state;
            return null;
        }
    }
    public sealed class ScriptReference
    {
        public ScriptDefinition Script;
        public ScriptState ReturnState;
        public Func<ScriptPacket, bool> Guard;
    }
    public sealed class ScriptPacket
    {
        public ScriptDefinition BaseScript, Script;
        public ScriptState State, PendingState;
        public ScriptAction Action;
        public readonly float[] Parameters = new float[4];
        public readonly List<ScriptReference> Stack = new List<ScriptReference>();
        public uint Flags;
        public ushort BlockedMessages;
        public float Timer, Deadline, IdleRemaining;
        public byte IdleFrames, DeadlineMarker;
        // Native packet +0xb0; populated by the host independently of actor groups.
        public byte SetId;
        public ScriptState DeadlineState;
        public ScriptMachine Machine;
    }
    public sealed class ScriptEnvironment
    {
        // Represents non-null native system context. Creature/group/name resolution is external.
        public bool HasSystem = true;
        public uint ParameterOverrideMask;
        public readonly float[] ParameterOverrides = new float[4];
        public bool HasParameterOverrides;
        public Action<ScriptPacket> ResetActionScratch;
        public Action<ScriptPacket, ScriptAction> AnimationOverride;
        public Action<ScriptPacket, int> PrepareConditionBank;
        public Action<ScriptPacket> ScriptBound;
    }
    public sealed class ScriptMachine
    {
        public readonly ScriptEnvironment Environment;
        public int MaxActionsPerTick = 100000;
        public ScriptMachine(ScriptEnvironment environment)
        {
            Environment = environment ?? new ScriptEnvironment();
        }
        void Prepare(ScriptPacket packet, int bank)
        {
            if (Environment.PrepareConditionBank != null) Environment.PrepareConditionBank(packet, bank);
        }
        void Advance(ScriptPacket packet)
        {
            packet.Action = packet.Action == null ? (packet.State == null ? null : packet.State.FirstAction) : packet.Action.Next;
            if (packet.Action != null) packet.Flags |= 1;
        }
        public void EnterState(ScriptPacket packet, ScriptState state)
        {
            if (packet == null || state == null) return;
            if ((packet.Flags & 4) == 0) packet.BlockedMessages = 0;
            packet.Flags &= ~4u; packet.State = state; packet.Action = null; packet.PendingState = null;
            Prepare(packet, 0); Advance(packet);
        }
        public void Bind(ScriptPacket packet, ScriptDefinition script, ScriptState state, bool useCharacterParameters)
        {
            if (packet == null || script == null) return;
            packet.Machine = this; packet.Flags &= ~4u; packet.BlockedMessages = 0; packet.Script = script; packet.PendingState = null;
            if (packet.BaseScript == null) packet.BaseScript = script;
            for (int i = 0; i < 4; ++i)
                packet.Parameters[i] = useCharacterParameters && Environment.HasParameterOverrides && (Environment.ParameterOverrideMask & (2u << i)) != 0 ? Environment.ParameterOverrides[i] : script.Parameters[i];
            EnterState(packet, state ?? script.Find("Base"));
            packet.Deadline = 0; packet.DeadlineState = null; packet.DeadlineMarker = 0;
            if (Environment.ScriptBound != null) Environment.ScriptBound(packet);
        }
        void ReturnReference(ScriptPacket packet, int index)
        {
            ScriptReference reference = packet.Stack[index];
            packet.Stack.RemoveRange(index, packet.Stack.Count - index);
            ScriptDefinition owner = index == 0 ? packet.BaseScript : packet.Stack[index - 1].Script;
            Bind(packet, owner, reference.ReturnState, index == 0);
        }
        bool TryReferences(ScriptPacket packet, List<ScriptReference> references)
        {
            foreach (ScriptReference reference in references)
            {
                Prepare(packet, 1);
                if (reference.Guard != null && !reference.Guard(packet)) continue;
                if (reference.Script == null || reference.Script.IdleState == null) continue;
                Prepare(packet, 0);
                ScriptMatch match = reference.Script.IdleState.Conditions == null ? null : reference.Script.IdleState.Conditions(packet);
                if (match == null || match.Target == reference.Script.IdleState) continue;
                packet.Stack.Add(reference); Bind(packet, reference.Script, match.Target, false); return true;
            }
            return false;
        }
        public void Tick(ScriptPacket packet, float delta)
        {
            if (packet == null || packet.Script == null) return;
            packet.Machine = this; packet.Timer = (float)(packet.Timer + delta);
            for (int i = 0; i < packet.Stack.Count; ++i)
            {
                ScriptReference reference = packet.Stack[i];
                if (reference.Guard != null && !reference.Guard(packet)) { ReturnReference(packet, i); break; }
            }
            if (packet.Stack.Count != 0 && packet.PendingState == null && packet.State == packet.Script.IdleState) ReturnReference(packet, packet.Stack.Count - 1);
            if (packet.PendingState != null) EnterState(packet, packet.PendingState);
            else if (packet.State == null && packet.Script.States.Count != 0) EnterState(packet, packet.Script.States[0]);
            int actions = 0;
            while (packet.State != null && packet.Action != null)
            {
                if (++actions > MaxActionsPerTick) throw new InvalidOperationException("Non-yielding SCP action chain.");
                ScriptAction action = packet.Action;
                if (action.Handler == null) packet.Flags &= ~1u;
                else
                {
                    bool first = (packet.Flags & 1) != 0;
                    if (first)
                    {
                        packet.IdleFrames = 0; packet.IdleRemaining = 0;
                        if (Environment.ResetActionScratch != null) Environment.ResetActionScratch(packet);
                        packet.Flags &= ~1u;
                        if (action.AnimationOverrideOnEntry && Environment.AnimationOverride != null) Environment.AnimationOverride(packet, action);
                    }
                    if (!action.Handler(packet, first, delta)) break;
                }
                if ((packet.Flags & 1) == 0) Advance(packet);
            }
            if (Environment.HasSystem && packet.Stack.Count < 4)
            {
                if (TryReferences(packet, packet.Script.References)) return;
                if (packet.State != null && TryReferences(packet, packet.State.References)) return;
            }
            float oldDeadline = packet.Deadline;
            if (oldDeadline > 0) packet.Deadline = (float)(oldDeadline - delta);
            if (oldDeadline > 0 && packet.Deadline <= 0 && packet.DeadlineState != null)
            {
                EnterState(packet, packet.DeadlineState); packet.DeadlineState = null; packet.DeadlineMarker = 0; return;
            }
            ScriptMatch result = packet.State == null || packet.State.Conditions == null ? null : packet.State.Conditions(packet);
            if (result != null)
            {
                packet.Flags = (packet.Flags & ~4u) | (result.KeepBlockedMessages ? 4u : 0u);
                EnterState(packet, result.Target);
            }
        }
    }

    // Numeric forms intentionally accept evaluated operands. The original string/expression
    // parser remains a separate adapter; these methods must not be advertised as that parser.
    public sealed class ScriptRandom
    {
        public uint State;
        public float Next()
        {
            State = unchecked(State * 0x19660du + 0x3c6ef35fu);
            return (State & 0x7fffffu) / 8388608.0f;
        }
    }
    public static class ScriptCommands
    {
        public static float Timer(ScriptPacket packet) { return packet.Timer; }
        public static ScriptAction SetState(params string[] arguments)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta)
            {
                if (first && arguments.Length != 0)
                {
                    packet.Flags &= ~4u; packet.PendingState = packet.Script.Find(arguments[0]);
                    for (int i = 1; i < arguments.Length; ++i)
                        if (String.Equals(arguments[i], "KeepBlockedMessages", StringComparison.OrdinalIgnoreCase)) packet.Flags |= 4;
                }
                return false;
            }};
        }
        static bool IdleTick(ScriptPacket packet, float delta)
        {
            if (packet.IdleFrames != 0) { --packet.IdleFrames; return packet.IdleFrames == 0; }
            if (packet.IdleRemaining > 0)
            {
                packet.IdleRemaining = (float)(packet.IdleRemaining - delta);
                if (packet.IdleRemaining <= 0) { packet.IdleRemaining = 0; return true; }
            }
            return false;
        }
        public static ScriptAction IdleSeconds(float seconds)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta) { if (first) { packet.IdleRemaining = seconds; return false; } return IdleTick(packet, delta); } };
        }
        public static ScriptAction IdleFrames(int frames)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta) { if (first) { packet.IdleFrames = (byte)Math.Max(0, Math.Min(255, frames)); return false; } return IdleTick(packet, delta); } };
        }
        public static ScriptAction IdleRange(float min, float max, ScriptRandom random)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta) { if (first) { if (packet.IdleRemaining == 0 && min < max) packet.IdleRemaining = (float)((double)random.Next() * ((double)max - min) + min); return false; } return IdleTick(packet, delta); } };
        }
        public static ScriptAction ResetTimer(float value)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta) { if (first) packet.Timer = value; return true; } };
        }
        public static ScriptAction ResetTimerRange(float min, float max, ScriptRandom random)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta)
            {
                if (first)
                {
                    if (min == 0 && max == 0) packet.Timer = 0;
                    else { float r1 = random.Next(), r2 = random.Next(); packet.Timer = (float)((1.0 - r1) * min + (double)r2 * max); }
                }
                return true;
            }};
        }
    }
}
