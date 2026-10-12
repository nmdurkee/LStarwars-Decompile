/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53d3a0; label: FUN_0053d3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053d3a0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_004ef660(*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 4),param_1,1);
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  }
  return;
}

