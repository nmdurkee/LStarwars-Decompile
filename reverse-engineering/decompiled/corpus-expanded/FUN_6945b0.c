/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x6945b0; label: FUN_006945b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006945b0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  float10 fVar2;
  
  if (0x7ff < *(int *)(in_ECX + 0x14)) {
    FUN_00693b60();
  }
  fVar2 = (float10)FUN_004f9f60(param_1);
  *(float *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x14) * 4) = (float)fVar2;
  piVar1 = (int *)(*(int *)(in_ECX + 0x20) + 0x1c);
  *piVar1 = *piVar1 + 1;
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  return;
}

