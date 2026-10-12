/* Ghidra pseudocode, not original source.
 * ev_2a2c0e65abfb9c10d1e5708a86db983babfd8b559b68eb98bb3f20c083d0e5d5
 * Entry: 0x5d02e0; label: FUN_005d02e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005d02e0(int *param_1)

{
  float10 fVar1;
  
  if (param_1[1] != 0) {
    return (float10)*(float *)(*(int *)(*(int *)(*param_1 + 0x18) +
                                       *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4) + 0x14);
  }
  fVar1 = (float10)FUN_005bec80(param_1[2] + 0xa0);
  return (float10)(float)(fVar1 + (float10)*(float *)(param_1[2] + 0xac));
}

