// Original PC 0x46c6e0 and 0x46c4f0, with explicit world/cheat/difficulty inputs.
// This does not create pickups or implement collection/rendering.
using System;
namespace Recovered.Combat
{
    public struct PlayerHealth
    {
        public bool Present, Dead;
        public byte Maximum, Current;
    }
    public static class CombatEconomy
    {
        // Returns the number of studs requested for spawned drops. The wallet can
        // lose studs even when cheat/timer state suppresses that returned quantity.
        public static uint DeductStuds(ref uint wallet, bool walletPresent, int reason,
            bool specialMode, int difficultyAdjustment, uint cheatFlags,
            float invincibilityTimer, uint characterFlags90, float suppressDropTimer)
        {
            if (!walletPresent || (cheatFlags & 0x80) != 0 || invincibilityTimer > 0 ||
                (characterFlags90 & 0x8000) != 0) return 0;
            uint loss = reason == 1 ? (specialMode ? 25000u : 2000u) :
                        reason == 2 ? (specialMode ? 12500u : 1000u) : 0u;
            if (difficultyAdjustment == 1) loss *= 2;
            else if (difficultyAdjustment == -1) loss >>= 1;
            loss = Math.Min(wallet, loss);
            wallet -= loss;
            return (cheatFlags & 0x7c) != 0 || suppressDropTimer > 0 ? 0 : loss;
        }
        static void Accumulate(PlayerHealth p, ref int maximum, ref int missing)
        {
            if (!p.Present || p.Dead || p.Maximum == 0) return;
            maximum += p.Maximum;
            missing += p.Maximum - unchecked((sbyte)p.Current);
        }
        // activeHearts counts original active pickup records whose type is 0xcb.
        // The caller supplies the existing two player states and pickup counter.
        public static bool ShouldDropHeart(PlayerHealth first, PlayerHealth second,
            int activeHearts, byte pickupCounter, int difficultyAdjustment, ref uint randomState)
        {
            if (activeHearts < 0) throw new ArgumentOutOfRangeException("activeHearts");
            int maximum = 0, missing = 0;
            Accumulate(first, ref maximum, ref missing);
            Accumulate(second, ref maximum, ref missing);
            if (maximum == 0) return false;
            if (missing > 0) missing -= activeHearts;
            int numerator = Math.Max(0, Math.Min(maximum,
                missing + (pickupCounter > 5 ? 9 : 8) - pickupCounter));
            int threshold = (numerator << 16) / maximum;
            if (difficultyAdjustment == 1) threshold /= 2;
            else if (difficultyAdjustment == -1) threshold *= 2;
            randomState = unchecked(randomState * 0x24cdu + 1u) & 65535u;
            return randomState < threshold;
        }
    }
}
