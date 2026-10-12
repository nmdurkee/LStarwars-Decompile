// Six original-PC condition readers and three initializers.
// World updates, object lifetime and named resolution are explicit input adapters.
using System;

namespace Recovered.Gameplay
{
    public sealed class ConditionObject
    {
        // Native world object +0xf10. This reader does not establish time units
        // or the renderer/culling rules that update the field.
        public float OffScreenTimer;
    }
    public sealed class ConditionActorReference
    {
        public ConditionObject Object;
    }
    public sealed class ConditionCreature
    {
        // Native script-creature +0xe4 is only tested for nonzero by these readers.
        // This is not a promise that its referenced opponent is alive or valid.
        public bool HasOpponentReference;
        public float OpponentRange;
        public ConditionActorReference ActorReference;
    }
    public sealed class ConditionWorld
    {
        public int FreePlayValue;
        // Models the read at 0x876847+index, not an inferred table allocation.
        // Literal selectors are 1..16; native myset can use any byte index.
        public Func<byte, byte> ReadAliveCount;
        // Native global callback 0x923904; the host owns aliases and lifetimes.
        public Func<string, ConditionActorReference> ResolveCharacter;
    }
    public static class CompactConditions
    {
        public static float GotOpponent(ConditionCreature creature)
        {
            return creature != null && creature.HasOpponentReference ? 1 : 0;
        }
        public static float OpponentRange(ConditionCreature creature)
        {
            return creature != null && creature.HasOpponentReference ? creature.OpponentRange : Single.MaxValue;
        }
        public static ConditionObject BindOffScreenTimer(ConditionWorld world, string operand)
        {
            if (operand == null || world == null || world.ResolveCharacter == null) return null;
            MessageNumbers.RequireAscii(operand);
            ConditionActorReference reference = world.ResolveCharacter(operand);
            return reference == null ? null : reference.Object;
        }
        public static float OffScreenTimer(ConditionCreature creature, ConditionObject initializedObject)
        {
            ConditionObject target = initializedObject;
            if (target == null && creature != null && creature.ActorReference != null) target = creature.ActorReference.Object;
            return target == null ? 0 : target.OffScreenTimer;
        }
        public static float FreePlay(ConditionWorld world)
        {
            if (world == null) throw new ArgumentNullException("world");
            // PC fild returns an extended-precision signed integer; its SCP
            // evaluator stores to float32, which is this API's boundary.
            return MessageNumbers.Round((float)world.FreePlayValue);
        }
        public static int BindNumInSetAlive(string operand)
        {
            if (operand == null) return 0;
            MessageNumbers.RequireAscii(operand);
            if (String.Equals(operand, "myset", StringComparison.OrdinalIgnoreCase)) return -1;
            int i = 0, value = 0; bool negative = operand.Length != 0 && operand[0] == '-';
            if (negative) ++i;
            unchecked
            {
                while (i < operand.Length && operand[i] >= '0' && operand[i] <= '9') { value = value * 10 + operand[i] - '0'; ++i; }
                if (negative) value = -value;
            }
            return value >= 1 && value <= 16 ? value : 0;
        }
        public static float NumInSetAlive(ConditionWorld world, ScriptPacket packet, int initializedSelector)
        {
            int index = initializedSelector;
            if (index == -1)
            {
                if (packet == null) throw new ArgumentNullException("packet");
                index = packet.SetId;
            }
            else if (index < 0 || index > 16)
                throw new ArgumentOutOfRangeException("initializedSelector", "Selector was not produced by BindNumInSetAlive.");
            if (index == 0) return 0;
            if (world == null || world.ReadAliveCount == null) throw new InvalidOperationException("An alive-count read adapter is required.");
            return world.ReadAliveCount((byte)index);
        }
        public static float BindAlwaysTrue(string operand)
        {
            return String.IsNullOrEmpty(operand) ? 1 : MessageNumbers.Parse(operand);
        }
        public static float AlwaysTrue(float initializedValue)
        {
            return initializedValue;
        }
    }
}
