/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc500; label: FUN_005bc500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005bc500(int param_1,int param_2)

{
  float *pfVar1;
  
  if (param_1 != 0) {
    if ((-1 < param_2) && (param_2 < *(char *)(param_1 + 1))) {
      return (float10)*(float *)(param_1 + 4 + param_2 * 4);
    }
    if (param_2 == -1) {
      return (float10)((*(float *)(param_1 + 4) - *(float *)(param_1 + 8)) + *(float *)(param_1 + 4)
                      );
    }
    if (param_2 == *(char *)(param_1 + 1)) {
      pfVar1 = (float *)(param_1 + *(char *)(param_1 + 1) * 4);
      return (float10)((*(float *)(param_1 + 4 + *(char *)(param_1 + 1) * 4) - *pfVar1) + pfVar1[1])
      ;
    }
  }
  return (float10)0;
}

