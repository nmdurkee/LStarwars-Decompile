// Handwritten reconstruction of bounded original-PC named-message behavior.
// Evidence: reports/gameplay-message-contract.json. ASCII names and arguments.
using System;
using System.Collections.Generic;

namespace Recovered.Gameplay
{
    public sealed class MessageRecord
    {
        public string Name { get; internal set; }
        // CopyMessage preserves bits, including negative zero and NaN payloads.
        public uint ValueBits;
        public float Value
        {
            get { return BitConverter.ToSingle(BitConverter.GetBytes(ValueBits), 0); }
            set { ValueBits = BitConverter.ToUInt32(BitConverter.GetBytes(value), 0); }
        }
    }

    public sealed class MessageRegistry
    {
        readonly Queue<MessageRecord> free = new Queue<MessageRecord>();
        readonly List<MessageRecord> active = new List<MessageRecord>();
        public IList<MessageRecord> Active { get { return active.AsReadOnly(); } }

        // Allocation and lifetime are host adapters. Native Resolve does not reset
        // a free record's value; supplying initial bits preserves that distinction.
        public MessageRegistry(uint[] initialValueBits)
        {
            if (initialValueBits == null) throw new ArgumentNullException("initialValueBits");
            foreach (uint bits in initialValueBits) free.Enqueue(new MessageRecord { ValueBits = bits });
        }

        public MessageRecord Resolve(string name, MessageRecord cached)
        {
            if (cached != null) return cached;
            if (name == null) return null;
            MessageNumbers.RequireAscii(name);
            string canonical = name;
            if (name.IndexOf("msg_", StringComparison.OrdinalIgnoreCase) < 0)
            {
                if (name.Length > 26) return null;
                canonical = "msg_" + name;
            }
            // Intentional host guard: native's already-prefixed branch is an
            // unbounded sprintf into 32 bytes, so overflow is not reproduced.
            if (canonical.Length > 31) throw new ArgumentOutOfRangeException("name");
            foreach (MessageRecord record in active)
                if (String.Equals(record.Name, canonical, StringComparison.OrdinalIgnoreCase)) return record;
            if (free.Count == 0) return null;
            MessageRecord result = free.Dequeue();
            result.Name = canonical;
            active.Add(result);
            return result;
        }
    }

    public static class MessageNumbers
    {
        internal static void RequireAscii(string text)
        {
            foreach (char c in text) if (c == 0 || c > 127) throw new ArgumentException("Expected non-NUL ASCII text.");
        }
        // The memory round-trip requires binary32 storage even on x87 CLR hosts.
        internal static float Round(float value) { return BitConverter.ToSingle(BitConverter.GetBytes(value), 0); }

        public static float Parse(string text)
        {
            if (text == null) return 0;
            RequireAscii(text);
            int i = 0; float value = 0, divisor = 1;
            if (text.Length != 0 && text[0] == '-') { divisor = -1; ++i; }
            while (i < text.Length && text[i] >= '0' && text[i] <= '9')
            {
                value = Round(Round(value * 10) + (text[i] - '0')); ++i;
            }
            if (i < text.Length && text[i] == '.')
            {
                ++i;
                while (i < text.Length && text[i] >= '0' && text[i] <= '9')
                {
                    divisor = Round(divisor * 10);
                    value = Round(Round(value * 10) + (text[i] - '0')); ++i;
                }
            }
            return Round(value / divisor);
        }

        public static float Resolve(ScriptPacket packet, string text)
        {
            if (text == null) return 0;
            RequireAscii(text);
            if (packet != null)
            {
                // PC passes the start of "param" to its integer parser. The
                // first letter is not a digit, so every such match selects 0.
                if (text.IndexOf("param", StringComparison.OrdinalIgnoreCase) >= 0) return packet.Parameters[0];
                if (packet.Script != null)
                    for (int i = 0; i < 4; ++i)
                        if (packet.Script.ParameterNames[i] != null && String.Equals(packet.Script.ParameterNames[i], text, StringComparison.OrdinalIgnoreCase)) return packet.Parameters[i];
            }
            return Parse(text);
        }
    }

    public static class MessageCommands
    {
        public static MessageRecord Bind(MessageRegistry registry, bool enabled, string name)
        {
            return enabled && registry != null && name != null ? registry.Resolve(name, null) : null;
        }
        public static float Read(MessageRecord record) { return record == null ? 0 : record.Value; }

        static void Scan(string[] tokens, bool git, ScriptPacket packet, out string name, out float value, out int mode)
        {
            name = null; value = 0; mode = 0;
            string[] keys = git ? new string[] { "Name", "Val", "increment=", "decrement=" } : new string[] { "name=", "value=", "increment=", "decrement=" };
            foreach (string token in tokens)
            {
                if (token == null) throw new ArgumentNullException("tokens");
                MessageNumbers.RequireAscii(token);
                for (int i = 0; i < keys.Length; ++i)
                {
                    int at = token.IndexOf(keys[i], StringComparison.OrdinalIgnoreCase);
                    if (at < 0) continue;
                    int start = at + keys[i].Length + (git && i < 2 ? 1 : 0);
                    if (start > token.Length) throw new ArgumentException("Missing GIT key separator.");
                    string operand = token.Substring(start);
                    if (i == 0) name = operand;
                    else
                    {
                        value = git ? MessageNumbers.Parse(operand) : MessageNumbers.Resolve(packet, operand);
                        if (i >= 2) mode = i == 2 ? 1 : -1;
                    }
                    break;
                }
            }
        }
        static void Apply(MessageRecord record, float value, int mode)
        {
            record.Value = mode == 0 ? value : mode == 1 ? MessageNumbers.Round(record.Value + value) : MessageNumbers.Round(record.Value - value);
        }

        public static bool Set(MessageRegistry registry, ScriptPacket packet, string[] tokens, bool firstCall)
        {
            if (!firstCall || registry == null || tokens == null || tokens.Length == 0) return true;
            string name; float value; int mode;
            Scan(tokens, false, packet, out name, out value, out mode);
            if (name != null)
            {
                MessageRecord record = registry.Resolve(name, null);
                if (record != null) Apply(record, value, mode);
            }
            return true;
        }

        public static void SetAI(MessageRegistry registry, string[] tokens)
        {
            if (tokens == null) tokens = new string[0];
            string name; float value; int mode;
            Scan(tokens, true, null, out name, out value, out mode);
            MessageRecord record = registry == null ? null : registry.Resolve(name, null);
            // Intentional host guard instead of native's failed-lookup dereference.
            if (record == null) throw new InvalidOperationException("SetAIMessage requires an available named record.");
            Apply(record, value, mode);
        }

        public static bool Copy(MessageRegistry registry, string[] tokens, bool firstCall)
        {
            if (!firstCall || registry == null || tokens == null || tokens.Length == 0) return true;
            string from = null, to = null;
            foreach (string token in tokens)
            {
                MessageNumbers.RequireAscii(token);
                int at = token.IndexOf("from=", StringComparison.OrdinalIgnoreCase);
                if (at >= 0) from = token.Substring(at + 5);
                else { at = token.IndexOf("to=", StringComparison.OrdinalIgnoreCase); if (at >= 0) to = token.Substring(at + 3); }
            }
            if (from != null && to != null)
            {
                MessageRecord source = registry.Resolve(from, null);
                MessageRecord destination = registry.Resolve(to, null);
                if (source != null && destination != null) destination.ValueBits = source.ValueBits;
            }
            return true;
        }

        // A convenience binding for the reconstructed scheduler. Registry lifetime
        // and source token loading remain host-owned, rather than hidden globals.
        public static ScriptAction SetAction(MessageRegistry registry, string[] tokens)
        {
            return new ScriptAction { Handler = delegate(ScriptPacket packet, bool first, float delta) { return Set(registry, packet, tokens, first); } };
        }
    }
}
