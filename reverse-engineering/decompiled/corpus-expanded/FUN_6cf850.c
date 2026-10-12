/* Ghidra pseudocode, not original source.
 * ev_b393d28c9e9a0ec683edd3b274f1828e861e17aa87a3660c9a4e9e0f17cff856
 * Entry: 0x6cf850; label: FUN_006cf850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cf850(undefined4 param_1,int param_2)

{
  if (param_2 != 0) {
    DAT_02974644 = *(undefined2 *)(param_2 + 0xc);
    if (DAT_02973a18 == -1) {
      if (DAT_0081fa94 != 0) {
        FUN_006d2450(DAT_0081fa94 + 8);
      }
    }
    else {
      FUN_006cf470(DAT_02973a18);
    }
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

