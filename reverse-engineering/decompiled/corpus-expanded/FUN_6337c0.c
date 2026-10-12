/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x6337c0; label: FUN_006337c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006337c0(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    do {
      if ((*(int *)(*(int *)(in_ECX + 4) + iVar1 * 4) != 0) &&
         ((~(*(uint *)(*(int *)(*(int *)(in_ECX + 4) + iVar1 * 4) + 8) >> 1) & 1) != 0)) {
        (**(code **)(**(int **)(*(int *)(in_ECX + 4) + iVar1 * 4) + 0xc))(param_1);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0xc));
  }
  return;
}

