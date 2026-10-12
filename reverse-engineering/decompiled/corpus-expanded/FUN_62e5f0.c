/* Ghidra pseudocode, not original source.
 * ev_be89c5742567956971c64ab2441aea6b3f78c2cf42a7c801ad7bb364f9087e2c
 * Entry: 0x62e5f0; label: FUN_0062e5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0062e5f0(float param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 8);
  if (*(int *)(iVar1 + param_2 * 4) == 0) {
    return (float10)0;
  }
  if (*(int *)(iVar1 + param_3 * 4) == 0) {
    return (float10)0;
  }
  param_1 = *(float *)(*(int *)(iVar1 + param_3 * 4) + 0x10);
  if (*(float *)(*(int *)(iVar1 + param_2 * 4) + 0x14) < param_1) {
    param_1 = *(float *)(*(int *)(iVar1 + param_2 * 4) + 0x14);
  }
  return (float10)param_1;
}

