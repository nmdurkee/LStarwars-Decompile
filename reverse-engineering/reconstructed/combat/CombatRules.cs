// Reconstructed from the supplied PC x86 executable. Not original source.
// See reports/native-combat-contract.json for addresses, evidence and limitations.
using System;
using System.Collections.Generic;

namespace Recovered.Combat
{
    // A projection of verified fields, not the full original 0x10d8-byte object.
    public sealed class CombatObject
    {
        public uint Id;
        public uint Flags;                  // PC +0x1fc
        public uint IdentityFlags;          // PC +0x1f8
        public uint ProtectionFlags;        // PC +0xe24
        public sbyte PlayerSlot = -1;       // PC +0x280
        public sbyte Context;               // PC +0x7b5
        public byte Set;                    // PC +0x378
        public byte MaximumHealth;          // PC +0x107e
        public byte Health;                 // PC +0x107f, read signed by HitPoints
        public byte ShieldHealth;           // PC +0xe38, unsigned damage arithmetic
        public byte DefaultHealth;          // game character +0xf4
        public byte DefaultShieldHealth;    // game character +0xf5
        public uint CharacterFlags94;
        public float InvincibilityTimer;    // PC +0xdec
        public float ProtectionTimer;       // PC +0x1018
        public float ShieldScale;           // PC +0xd30
        public float ShieldFlickerTimer;    // PC +0xd34
        public bool IsPlayer { get { return (Flags & 0x80) != 0; } }
    }
    public enum ShieldFeedback { NoHealthChange, Hit, Broken }
    public static class CombatRules
    {
        // 0x58b720. Bit priority is significant.
        public static uint AttackerHitFlags(CombatObject attacker)
        {
            if (attacker == null) return 0;
            uint value = attacker.IsPlayer ? 0x804u : 2u;
            return value | ((attacker.IdentityFlags & 0x10001) != 0 ? 0x10u :
                           (attacker.IdentityFlags & 4) != 0 ? 0x20u : 8u);
        }
        // 0x58b7f0. Caller supplies CInfo[context].flags from the decoded registry.
        public static bool CannotKill(CombatObject target, uint contextFlags)
        {
            return (contextFlags & 0x2000000) != 0 ||
                ((target.CharacterFlags94 & 0x800) != 0 && target.PlayerSlot == -1);
        }
        // 0x55f1d0 -> 0x56e0f0. Finite timer values have native validation.
        public static bool PlayerInvincible(CombatObject target, uint cheatFlags)
        {
            return (cheatFlags & 0x80) != 0 ||
                (target != null && target.InvincibilityTimer > 0);
        }
        // 0x414ab0.
        public static void SetPostHitProtection(CombatObject target, float seconds)
        {
            target.ProtectionFlags &= 0xfff8ffff;
            target.ProtectionTimer = seconds;
        }
        // Arithmetic/state projection of 0x433be0. Audio, rumble and alert calls are
        // intentionally outside this function; this is not the full hit orchestrator.
        public static ShieldFeedback ApplyShieldDamage(CombatObject attacker,
            CombatObject target, int damage, bool miniCutscene, uint cheatFlags,
            float hitFlickerSeconds)
        {
            if (target == null) return ShieldFeedback.NoHealthChange;
            if (attacker != null && (attacker.Flags & 1) == 0) attacker = null;
            if (target.ShieldScale == 1 && target.ShieldFlickerTimer > 0 &&
                attacker != null && !attacker.IsPlayer && attacker.Context != 57)
                damage = 0;
            if (miniCutscene && target.IsPlayer) damage = 0;
            if (target.ShieldHealth == 0 || damage < 1) return ShieldFeedback.NoHealthChange;
            // Native order matters: an invincible player still resets the flicker timer.
            if (target.IsPlayer && PlayerInvincible(target, cheatFlags)) damage = 0;
            int remaining = unchecked(target.ShieldHealth - damage);
            if (remaining > 0)
            {
                target.ShieldHealth = unchecked((byte)remaining);
                target.ShieldFlickerTimer = hitFlickerSeconds;
                return ShieldFeedback.Hit;
            }
            target.ShieldHealth = 0;
            target.ShieldScale = 0;
            target.ShieldFlickerTimer = 0.5f;
            return ShieldFeedback.Broken;
        }
        // 0x441e20 after direct-object / actor weak-reference resolution.
        public static float HitPoints(CombatObject target)
        {
            return target == null ? 0 : unchecked((sbyte)target.Health);
        }
    }
    public sealed class ScriptActor
    {
        public CombatObject Character;
        public CombatObject Opponent;
    }
    // These adapters are the original external service boundaries, not replacement
    // implementations of numeric-variable lookup, the world registry or ObjHitObj.
    public interface ICombatScriptServices
    {
        int EvaluateInteger(string expression);
        CombatObject FindCharacter(string name);
        bool TryMessageInteger(string name, out int value);
        IEnumerable<CombatObject> Characters { get; }
        void Hit(CombatObject attacker, CombatObject target, int damage,
                 ushort flags, bool probe, int context);
    }
    public static class HealthCommands
    {
        // 0x4f8a70 / 0x4f8b10 use a byte fold, not Unicode case conversion.
        static int Fold(char c)
        {
            if (c > 255) throw new ArgumentException("Original command strings are byte encoded.");
            return (c >= 'a' && c <= 'z') || c >= 0xe0 ? c - 0x20 : c;
        }
        static int Index(string text, string token)
        {
            for (int i = 0; i + token.Length <= text.Length; i++)
            {
                bool matches = true;
                for (int j = 0; j < token.Length; j++)
                    if (Fold(text[i + j]) != Fold(token[j])) { matches = false; break; }
                if (matches) return i;
            }
            return -1;
        }
        static bool Equal(string a, string b) { return a.Length == b.Length && Index(a, b) == 0; }
        // 0x44b150. Default tokens leave the accumulated numeric value unchanged.
        public static int SetHitPoints(ScriptActor actor, string[] tokens, bool firstCall,
                                      ICombatScriptServices services)
        {
            if (!firstCall) return 1;
            CombatObject target = actor == null ? null : actor.Character;
            int value = -1;
            bool setMaximum = true;
            foreach (string token in tokens)
            {
                int at = Index(token, "character=");
                if (at >= 0) { target = services.FindCharacter(token.Substring(at + 10)); continue; }
                at = Index(token, "messageval=");
                if (at >= 0)
                {
                    int message;
                    if (services.TryMessageInteger(token.Substring(at + 11), out message)) value = message;
                }
                else if (Equal(token, "dont_set_max")) setMaximum = false;
                else if (!Equal(token, "default")) value = services.EvaluateInteger(token);
            }
            if (target != null)
            {
                byte health = unchecked((byte)(value == -1 ? target.DefaultHealth : value));
                if (setMaximum) target.MaximumHealth = health;
                target.Health = health;
            }
            return 1;
        }
        // 0x44b290.
        public static int SetShieldHitPoints(ScriptActor actor, string[] tokens, bool firstCall,
                                            ICombatScriptServices services)
        {
            if (!firstCall) return 1;
            CombatObject target = actor == null ? null : actor.Character;
            int value = -1;
            foreach (string token in tokens)
            {
                int at = Index(token, "character=");
                if (at >= 0) target = services.FindCharacter(token.Substring(at + 10));
                else value = services.EvaluateInteger(token);
            }
            if (target != null) target.ShieldHealth = unchecked((byte)(value == -1 ? target.DefaultShieldHealth : value));
            return 1;
        }
        // 0x44fd10. set= is a group selector 1..16; invalid/zero means the resolved target.
        public static int TakeDamage(ScriptActor actor, string[] tokens, bool firstCall,
                                     ICombatScriptServices services)
        {
            if (!firstCall) return 1;
            CombatObject target = actor == null ? null : actor.Character;
            CombatObject attacker = null;
            int damage = 1, set = 0;
            foreach (string token in tokens)
            {
                int at = Index(token, "character=");
                if (at >= 0) { target = services.FindCharacter(token.Substring(at + 10)); continue; }
                at = Index(token, "hitter=");
                if (at >= 0) { attacker = services.FindCharacter(token.Substring(at + 7)); continue; }
                at = Index(token, "damage=");
                if (at >= 0) { damage = services.EvaluateInteger(token.Substring(at + 7)); continue; }
                if (Index(token, "opponent") >= 0)
                {
                    if (actor != null && actor.Opponent != null)
                    {
                        target = actor.Opponent;
                        if (actor.Character != null) attacker = actor.Character;
                    }
                    continue;
                }
                at = Index(token, "set=");
                if (at >= 0)
                {
                    set = services.EvaluateInteger(token.Substring(at + 4));
                    if (set < 0 || set > 16) set = 0;
                }
            }
            if (set != 0)
            {
                foreach (CombatObject candidate in services.Characters)
                    if ((candidate.Flags & 1) != 0 && candidate.Set == set)
                        services.Hit(attacker, candidate, damage, 0, false, 1);
            }
            else if (target != null) services.Hit(attacker, target, damage, 0, false, 1);
            return 1;
        }
    }
}
