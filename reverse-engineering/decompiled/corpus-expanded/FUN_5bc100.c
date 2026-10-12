/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc100; label: FUN_005bc100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bc100(float *param_1,int param_2)

{
  *param_1 = *(float *)(param_2 + 0x3c) * 2.0 +
             (*(float *)(param_2 + 0x24) * 2.0 - *(float *)(param_2 + 0x30) * 4.0);
  param_1[1] = *(float *)(param_2 + 0x40) * 2.0 +
               (*(float *)(param_2 + 0x28) * 2.0 - *(float *)(param_2 + 0x34) * 4.0);
  param_1[2] = *(float *)(param_2 + 0x44) * 2.0 +
               (*(float *)(param_2 + 0x2c) * 2.0 - *(float *)(param_2 + 0x38) * 4.0);
  return;
}

