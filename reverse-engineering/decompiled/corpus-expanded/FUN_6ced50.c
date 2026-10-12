/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6ced50; label: FUN_006ced50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ced50(int param_1,int param_2)

{
  if (((*(char *)(param_2 + 0x53) == '\0') || (*(float *)(param_2 + 0x124) == 0.0)) &&
     (*(int *)(param_1 + 0x40) == 0)) {
    if (*(float *)(param_1 + 0x48) < _DAT_0081fa00) {
      FUN_006c7660();
      return;
    }
    FUN_006c7730();
  }
  return;
}

