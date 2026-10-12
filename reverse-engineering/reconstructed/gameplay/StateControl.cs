// PC SetScriptState (0x445740) with explicit actor-registry/name adapters.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class ScriptActor
    {
        public ScriptPacket Packet;
        public uint Flags;
        public byte SetId;
    }

    public sealed class StateControlContext
    {
        public ScriptMachine Machine;
        public ScriptActor Self;
        public readonly List<ScriptActor> Actors = new List<ScriptActor>();
        // Native global callback 0x923904. Null means leave the default target.
        public Func<string, ScriptActor> ResolveCharacter;
    }

    public static class StateControl
    {
        static void Rebind(StateControlContext context, ScriptPacket packet, string name)
        {
            ScriptState state = packet.BaseScript.Find(name);
            if (state == null) return;
            if (context.Machine == null) throw new InvalidOperationException("A script machine is required.");
            packet.Stack.Clear();
            context.Machine.Bind(packet, packet.BaseScript, state, false);
        }

        public static bool SetScriptState(StateControlContext context, ScriptPacket caller, string[] tokens, bool firstCall)
        {
            if (!firstCall) return true;
            if (context == null) throw new ArgumentNullException("context");
            ScriptActor target = context.Self;
            string state = null; int set = 0;
            if (tokens != null)
                foreach (string token in tokens)
                {
                    MessageNumbers.RequireAscii(token);
                    int at = token.IndexOf("character=", StringComparison.OrdinalIgnoreCase);
                    if (at >= 0)
                    {
                        if (context.ResolveCharacter != null) target = context.ResolveCharacter(token.Substring(at + 10));
                        continue;
                    }
                    at = token.IndexOf("set=", StringComparison.OrdinalIgnoreCase);
                    if (at >= 0)
                    {
                        float value = MessageNumbers.Resolve(caller, token.Substring(at + 4));
                        // Native fixtures cover finite, int32-representable values.
                        // Reject unspecified overflow/NaN conversion instead of guessing.
                        if (Single.IsNaN(value) || Single.IsInfinity(value) || (double)value < -2147483648.0 || (double)value >= 2147483648.0) throw new ArgumentOutOfRangeException("tokens");
                        set = (int)value;
                        if (set < 0 || set > 16) set = 0;
                        continue;
                    }
                    at = token.IndexOf("state=", StringComparison.OrdinalIgnoreCase);
                    if (at >= 0) state = token.Substring(at + 6);
                }
            if (state == null) return true;
            if (set == 0)
            {
                if (target != null && target.Packet != null && target.Packet.BaseScript != null) Rebind(context, target.Packet, state);
            }
            else
                foreach (ScriptActor actor in context.Actors)
                    if ((actor.Flags & 0x1001) == 0x1001 && actor.SetId == set)
                    {
                        // Original group branch dereferences these without checks.
                        if (actor.Packet == null || actor.Packet.BaseScript == null) throw new InvalidOperationException("Selected group actor has no base script packet.");
                        Rebind(context, actor.Packet, state);
                    }
            return true;
        }

        public static ScriptAction Action(StateControlContext context, string[] tokens)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta) { return SetScriptState(context, packet, tokens, first); } };
        }
    }
}
