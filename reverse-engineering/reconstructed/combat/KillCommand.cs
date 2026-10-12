// Reconstructed bounded PC Kill command. Not original source.
// Native entry 0x445230; evidence: reports/native-combat-kill.json.
using System;
using System.Collections.Generic;
namespace Recovered.Combat
{
    // Projection of the fields read/written by Kill; service adapters can share
    // these with their world actor model. This is not a complete character object.
    public sealed class KillTarget
    {
        public uint Flags;          // +0x1fc
        public uint IdentityFlags;  // +0x1f8
        public byte DeathState;     // +0x28b
        public byte Set;            // +0x378
        public uint HitFlags;       // +0xeec
        public float SpawnTimer;    // +0x1010
    }
    public interface IKillServices
    {
        // Ordered contiguous native actor pool, projected to managed objects.
        IEnumerable<KillTarget> Characters { get; }
        KillTarget FindCharacter(string name);       // global 0x923904 callback
        KillTarget ResolveReference(string name);    // 0x440120
        int EvaluateInteger(string expression);      // 0x5147c0 then 0x6e6b90
        void ActivateParts(KillTarget target, int first, int second,
                           int enabled, int fourth, int fifth, int sixth);
        void DeathCleanup(KillTarget target, int mode, int argument);
    }
    public static class KillCommand
    {
        static int Fold(char value)
        {
            if (value > 255) throw new ArgumentException("Native command text must be byte encoded.");
            return ((value >= 'a' && value <= 'z') || value >= 0xe0) ? value - 0x20 : value;
        }
        static int Index(string text, string token)
        {
            for (int i = 0; i + token.Length <= text.Length; i++)
            {
                bool same = true;
                for (int j = 0; j < token.Length; j++)
                    if (Fold(text[i+j]) != Fold(token[j])) { same = false; break; }
                if (same) return i;
            }
            return -1;
        }
        static bool Equal(string text, string token) { return text.Length == token.Length && Index(text, token) == 0; }
        static void Apply(KillTarget target, uint respawnBits, bool parts, bool debris, IKillServices services)
        {
            target.HitFlags = (target.HitFlags & 0xffcfffffu) | respawnBits;
            if (parts) services.ActivateParts(target, -1, -1, 1, 0, 0, 0);
            services.DeathCleanup(target, debris ? 2 : 4, 0);
        }
        // Opponent null represents either missing weak reference or null payload.
        // The native handler retains the current target when the weak reference
        // itself is absent, but replaces it with null when that reference exists.
        public static int Execute(KillTarget self, KillTarget opponent, bool hasOpponentReference,
                                  string[] tokens, bool firstCall, IKillServices services)
        {
            if (!firstCall) return 1;
            KillTarget target = self, exception = null;
            bool allAi = false, checkDead = false, parts = false, debris = false;
            uint respawn = 0, origin = 0;
            int set = 0;
            foreach (string rawToken in tokens)
            {
                int terminator = rawToken.IndexOf('\0');
                string token = terminator < 0 ? rawToken : rawToken.Substring(0, terminator);
                int at = Index(token, "character");
                if (at >= 0) { target = services.FindCharacter(token.Substring(at + 10)); continue; }
                at = Index(token, "opponent");
                if (at >= 0) { if (hasOpponentReference) target = opponent; continue; }
                if (Equal(token, "respawn")) { respawn = 1; continue; }
                if (Equal(token, "respawn_at_origin")) { respawn = 1; origin = 1; continue; }
                at = Index(token, "all_ai_except");
                if (at >= 0) { exception = services.ResolveReference(token.Substring(at + 14)); allAi = true; continue; }
                if (Equal(token, "all_ai")) { allAi = true; continue; }
                if (Equal(token, "check_if_dead")) { checkDead = true; continue; }
                if (Equal(token, "debris")) { debris = true; continue; }
                if (Equal(token, "parts_on")) { parts = true; continue; }
                at = Index(token, "set=");
                if (at >= 0)
                {
                    set = services.EvaluateInteger(token.Substring(at + 4));
                    if (set < 0 || set > 16) set = 0;
                }
            }
            uint respawnBits = ((origin * 2) | respawn) << 20;
            if (allAi || set != 0)
            {
                foreach (KillTarget candidate in services.Characters)
                {
                    if ((candidate.Flags & 0x1001u) != 0x1001u) continue;
                    if (allAi)
                    {
                        if ((candidate.IdentityFlags & 0x400u) == 0 || Object.ReferenceEquals(candidate, exception)) continue;
                    }
                    else if (candidate.Set != set) continue;
                    if (checkDead && (candidate.DeathState != 0 || !(candidate.SpawnTimer <= 0))) continue;
                    Apply(candidate, respawnBits, parts, debris, services);
                }
            }
            else if (target != null && (!checkDead || (target.DeathState == 0 && target.SpawnTimer <= 0)))
                Apply(target, respawnBits, parts, debris, services);
            return 1;
        }
    }
}
