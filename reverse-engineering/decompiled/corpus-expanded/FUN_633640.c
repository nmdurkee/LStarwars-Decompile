/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633640; label: FUN_00633640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633640(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    piVar3 = *(int **)(in_ECX + 4);
    while ((*piVar3 == 0 || (*(int *)(*piVar3 + 4) != param_1))) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      if (*(int *)(in_ECX + 0xc) <= iVar2) {
        return;
      }
    }
    iVar2 = *(int *)(*(int *)(in_ECX + 4) + iVar2 * 4);
    if (param_3 != 0) {
      puVar1 = (uint *)(iVar2 + 8);
      *puVar1 = *puVar1 & ~param_2;
      return;
    }
    puVar1 = (uint *)(iVar2 + 8);
    *puVar1 = *puVar1 | param_2;
  }
  return;
}

