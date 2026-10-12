/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x6271f0; label: FUN_006271f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006271f0(void)

{
  if (DAT_02912f30 != 0) {
    if (DAT_02912eb4 != 0) {
      if (*(int *)(DAT_02912eb4 + 0x3c) == 0) {
        DAT_02912eac = DAT_02912eb4;
        return 0;
      }
      DAT_02912eac = FUN_0061f070();
      return 0;
    }
    DAT_02912eac = 0;
  }
  return 0;
}

