/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc560; label: FUN_005bc560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bc560(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    if ((-1 < param_2) && (param_2 < *(char *)(param_1 + 1))) {
      return (float10)*(float *)(param_1 + 0x24 + param_2 * 4);
    }
    if (param_2 == -1) {
      return (float10)((*(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x28)) +
                      *(float *)(param_1 + 0x24));
    }
    if (param_2 == *(char *)(param_1 + 1)) {
      iVar1 = (int)*(char *)(param_1 + 1);
      return (float10)((*(float *)(param_1 + 0x24 + iVar1 * 4) -
                       *(float *)(param_1 + 0x20 + iVar1 * 4)) +
                      *(float *)(param_1 + 0x24 + iVar1 * 4));
    }
  }
  return (float10)0;
}

