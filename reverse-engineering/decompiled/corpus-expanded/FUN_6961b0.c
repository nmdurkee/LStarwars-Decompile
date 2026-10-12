/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x6961b0; label: FUN_006961b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006961b0(undefined4 param_1,int param_2)

{
  int *piVar1;
  float10 fVar2;
  
  if (0x7ff < *(int *)(param_2 + 0x14)) {
    FUN_00693b60();
  }
  fVar2 = (float10)FUN_004f9f60(param_1);
  *(float *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x14) * 4) = (float)fVar2;
  piVar1 = (int *)(*(int *)(param_2 + 0x20) + 0x1c);
  *piVar1 = *piVar1 + 1;
  *(int *)(param_2 + 0x14) = *(int *)(param_2 + 0x14) + 1;
  return;
}

