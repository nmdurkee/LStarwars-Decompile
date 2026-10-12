/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x602810; label: FUN_00602810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602810(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_02854da0)[iVar1] == param_1 - param_2) {
      (&DAT_02854da0)[iVar1] = param_1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 100);
  return;
}

