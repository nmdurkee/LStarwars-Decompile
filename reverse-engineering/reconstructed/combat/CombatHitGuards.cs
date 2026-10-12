// Verified branch projections from ObjHitObj (PC 0x438230), not its full orchestration.
namespace Recovered.Combat
{
    public static class CombatHitGuards
    {
        public static bool MenuProtectsPlayer(int menuState, bool player)
        {
            return player && (menuState == 8 || (menuState >= 12 && menuState <= 17));
        }
        public static bool RejectContext(int context, int action, int stunSubstate,
            uint characterFlags90, uint contextParameterFlags, int damage,
            ushort hitFlags, bool hasAttacker, uint attackerFlags)
        {
            if ((characterFlags90 & 0x8000) != 0 || context == 95 || context == 96) return true;
            // This precedes inactive-attacker normalization in the original routine.
            if (context == 90 && (stunSubstate == 0 || (hasAttacker && (attackerFlags & 0x80) == 0))) return true;
            bool landingGuard = (context == 0 && (action == 3 || action == 4)) || context == 13 || context == 14;
            if (landingGuard && !(damage == -1 && (hitFlags & 0x200) != 0)) return true;
            return (contextParameterFlags & 4) != 0;
        }
        public static int ApplyContextDamageOverride(int context, int damage)
        {
            return context == 76 || context == 81 ? 0 : damage;
        }
        public static bool RejectPostHitDamage(float protectionTimer, int damage,
                                               CombatObject attacker)
        {
            if (damage == -1 || !(protectionTimer > 0)) return false;
            return attacker == null || (attacker.Flags & 0x81) != 0x81;
        }
    }
}
