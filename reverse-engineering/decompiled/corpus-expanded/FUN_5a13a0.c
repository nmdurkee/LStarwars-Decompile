/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a13a0; label: FUN_005a13a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005a13a0(int param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)0;
  if (((param_1 == 0) || (*(int *)(param_1 + 0x10) == 0)) || (*(int *)(param_1 + 0x14) == 0)) {
    return (float10)(float)fVar1;
  }
  if (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18)) {
    return (float10)1.0;
  }
  fVar2 = (float10)((*(float *)(*(int *)(param_1 + 0x10) + 0x4c) - *(float *)(param_1 + 0x18)) /
                   (*(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x18)));
  if (fVar2 < fVar1) {
    return (float10)(float)fVar1;
  }
  if ((float10)1 < fVar2) {
    return (float10)(float)(float10)1;
  }
  return fVar2;
}

