/* Ghidra pseudocode, not original source.
 * ev_87b0cc36f0a526e4b097042d81b23e73008cbbd7a9cf76d2852b3ccb3adbc9c9
 * Entry: 0x5ddc80; label: FUN_005ddc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ddc80(int param_1,float param_2)

{
  float fVar1;
  float10 fVar2;
  
  if (param_1 != 0) {
    fVar1 = *(float *)(param_1 + 0x2c) + param_2 * *(float *)(param_1 + 0x28) * 0.00390625;
    *(float *)(param_1 + 0x2c) = fVar1;
    if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
      fVar2 = (float10)FUN_005b7d30(fVar1,0x3f800000);
      *(float *)(param_1 + 0x2c) = (float)fVar2;
    }
    *(float *)(param_1 + 0x34) = param_2 * 5.0 + *(float *)(param_1 + 0x34);
    *(float *)(param_1 + 0x30) = param_2 + *(float *)(param_1 + 0x30);
  }
  return;
}

