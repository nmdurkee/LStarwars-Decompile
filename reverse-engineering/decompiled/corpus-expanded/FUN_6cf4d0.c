/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf4d0; label: FUN_006cf4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006cf4d0(undefined4 param_1,int param_2)

{
  _DAT_0081fab4 = *(int *)(param_2 + 0xc);
  if (_DAT_0081fab4 != 0) {
    FUN_006c9bf0(&DAT_0081fab0,0);
    FUN_006cf290();
    FUN_0061e5d0(1);
    if (DAT_02973a7c != 0) {
      if (*(int *)(DAT_02973a7c + 0x40) != 0) {
        *(undefined4 *)(*(int *)(DAT_02973a7c + 0x40) + 0x3c) = 0;
      }
      if (*(int *)(DAT_02973a7c + 0x3c) != 0) {
        *(undefined4 *)(*(int *)(DAT_02973a7c + 0x3c) + 0x40) = 0;
      }
    }
    DAT_02973a88 = 1;
  }
  return;
}

