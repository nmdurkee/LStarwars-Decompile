/* Ghidra pseudocode, not original source.
 * ev_d58eb7bbc0b728a6aebb219ddf07867fbf193ab17bd10fe9485a456632c89c4f
 * Entry: 0x5b4900; label: FUN_005b4900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005b4900(int param_1,float *param_2)

{
  *(float *)(param_1 + 0x30) = *param_2 + *(float *)(param_1 + 0x30);
  *(float *)(param_1 + 0x34) = param_2[1] + *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x38) = param_2[2] + *(float *)(param_1 + 0x38);
  return;
}

