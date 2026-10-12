/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x6271a0; label: FUN_006271a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006271a0(int param_1)

{
  int iVar1;
  
  if (DAT_02912f30 != 0) {
    if (param_1 == 0) {
      if (DAT_02912eb4 == 0) {
        DAT_02912eac = 0;
        return;
      }
      iVar1 = *(int *)(DAT_02912eb4 + 0x3c);
      param_1 = DAT_02912eb4;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x3c);
    }
    if (iVar1 == 0) {
      DAT_02912eac = param_1;
      return;
    }
    DAT_02912eac = FUN_0061f070();
  }
  return;
}

