// Recovered PC trigger readers and occupancy producer. See gameplay-trigger-contract.json.
using System;
using Recovered.Animation;

namespace Recovered.Gameplay
{
    public sealed class TriggerObject
    {
        public float X, Y, Z;                    // object +0x5c
        public uint StateFlags, EligibilityFlags; // +0x1f8, +0x1fc
        public byte Restricted;                 // +0x28b
        public float RestrictedTimer;           // +0x1010
        public uint MaskLow, MaskHigh;           // +0x2b0, +0x2b4
    }
    public sealed class TriggerArea
    {
        public string Name;                     // NUL-terminated byte name at +0
        public float X, Y, Z, HalfWidth, Height, HalfDepth; // +0x10..+0x24
        public short Yaw;                       // +0x28, full turn is 65536 units
        public byte State;                      // +0x2a
        // Projection of nonnull owner+0x38 and (area-owner.areas)>>6.
        // The producer independently uses the global world's area base.
        public bool HasOwner;
        public int OwnerIndex;
    }
    public sealed class TriggerSystem
    {
        public TriggerArea[] Areas;             // +0x38; null also matters to PlayerInTriggerArea
        public int AreaCount;                   // signed count +0x34
        public TriggerObject Player1, Player2;  // +0x138c, +0x1390
    }
    public static class TriggerConditions
    {
        private static int Fold(int b) { return (b >= 97 && b <= 122) || b >= 224 ? b - 32 : b; }
        private static void RequireByteString(string text)
        {
            if (text == null) return;
            foreach (char c in text) if (c == 0 || c > 255) throw new ArgumentException("Expected non-NUL Latin-1 byte string");
        }
        private static bool SameName(string a, string b)
        {
            if (a == null || b == null || a.Length != b.Length) return false;
            for (int i = 0; i < a.Length; ++i) if (Fold(a[i]) != Fold(b[i])) return false;
            return true;
        }
        // 0x51acd0. First match wins; this is native byte folding, not Unicode folding.
        public static TriggerArea FindArea(TriggerSystem system, string name)
        {
            if (system == null || system.AreaCount <= 0) return null;
            RequireByteString(name);
            if (system.Areas == null || system.AreaCount > system.Areas.Length) throw new ArgumentException("Invalid area backing table");
            for (int i = 0; i < system.AreaCount; ++i)
            {
                TriggerArea area = system.Areas[i];
                if (area == null) throw new ArgumentException("Invalid area record");
                RequireByteString(area.Name);
                if (SameName(name, area.Name)) return area;
            }
            return null;
        }
        // Identical initializer bodies at 0x52d0b0 and 0x52d160.
        public static TriggerArea BindArea(TriggerSystem system, string operand)
        {
            return operand == null ? null : FindArea(system, operand);
        }
        private static bool Member(TriggerObject obj, TriggerArea area)
        {
            if (obj == null || area == null || !area.HasOwner) return false;
            uint low = 1u << (area.OwnerIndex & 31);
            uint high = (low & 0x80000000u) != 0 ? UInt32.MaxValue : 0;
            return ((obj.MaskLow & low) | (obj.MaskHigh & high)) != 0;
        }
        // The fallback is processor+0xa0. The initialized operand takes precedence.
        // InTriggerArea reads creature+0xd0 directly, with no additional dereference.
        public static float InTriggerArea(TriggerObject obj, TriggerArea fallback, TriggerArea initialized)
        {
            return Member(obj, initialized ?? fallback) ? 1 : 0;
        }
        public static float PlayerInTriggerArea(TriggerSystem system, TriggerArea fallback, TriggerArea initialized)
        {
            return system != null && system.Areas != null && Member(system.Player1, initialized ?? fallback) ? 1 : 0;
        }
        public static float Player2InTriggerArea(TriggerSystem system, TriggerArea fallback, TriggerArea initialized)
        {
            return system != null && Member(system.Player2, initialized ?? fallback) ? 1 : 0;
        }
        public static float EitherPlayerInTriggerArea(TriggerSystem system, TriggerArea fallback, TriggerArea initialized)
        {
            TriggerArea area = initialized ?? fallback;
            return system != null && (Member(system.Player1, area) || Member(system.Player2, area)) ? 1 : 0;
        }
        private static PlaybackWide W(float value) { return PlaybackWide.From(value); }
        private static float Subtract(float a, float b) { return PlaybackWide.Add(W(a), W(-b)).Store(); }
        private static float SumProducts(float a, float b, float c, float d)
        {
            return PlaybackWide.Add(PlaybackWide.Multiply(W(a), W(b)), PlaybackWide.Multiply(W(c), W(d))).Store();
        }
        // Complete finite-array branch of 0x43b7c0, including original 0x5b3800/
        // 0x5b3620 math. The caller owns scheduling and supplies the original sine
        // table, global area index, and contiguous object-array projection.
        public static void UpdateArea(TriggerArea area, int worldAreaIndex, TriggerObject[] objects, float[] sineTable)
        {
            if (area == null || objects == null || sineTable == null || sineTable.Length != 32768) throw new ArgumentException("Missing trigger world inputs");
            area.State &= 0xf8;
            int angle = -(int)area.Yaw;
            float cosine = sineTable[((angle + 0x4000) >> 1) & 0x7fff], sine = sineTable[(angle >> 1) & 0x7fff];
            foreach (TriggerObject obj in objects)
            {
                if (obj == null) throw new ArgumentException("Null object-array record");
                uint flags = obj.EligibilityFlags;
                if ((flags & 1) == 0 || (flags & 0x1000) == 0 || (obj.Restricted != 0 && !(obj.RestrictedTimer > 0) && (flags & 0x80) == 0)) continue;
                float x = Subtract(obj.X, area.X), y = Subtract(obj.Y, area.Y), z = Subtract(obj.Z, area.Z);
                float localX = SumProducts(sine, z, cosine, x), localZ = SumProducts(z, cosine, -x, sine);
                if (localX < -area.HalfWidth || y < -0.1f || localZ < -area.HalfDepth || localX > area.HalfWidth || y > area.Height || localZ > area.HalfDepth)
                {
                    // __allshl examines CL, then returns zero for counts >=64.
                    int shift = worldAreaIndex & 255;
                    ulong mask = shift >= 64 ? 0 : 1UL << shift;
                    obj.MaskLow &= ~(uint)mask; obj.MaskHigh &= ~(uint)(mask >> 32);
                }
                else
                {
                    uint low = 1u << (worldAreaIndex & 31);
                    obj.MaskLow |= low; if ((low & 0x80000000u) != 0) obj.MaskHigh = UInt32.MaxValue;
                    if ((flags & 0x80) != 0) area.State |= 1;
                    if ((obj.StateFlags & 1) != 0) area.State |= 4;
                    else if ((obj.StateFlags & 4) == 0) area.State |= 2;
                }
            }
        }
    }
}
