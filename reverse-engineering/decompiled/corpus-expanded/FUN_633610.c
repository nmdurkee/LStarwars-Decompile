/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633610; label: FUN_00633610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00633610(int param_1)

{
  int in_ECX;
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
    iVar1 = *(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 0x14);
    if (iVar1 < *(int *)(in_ECX + 8)) {
      *(int *)(*(int *)(in_ECX + 4) + iVar1 * 4) = param_1;
      return param_1;
    }
  }
  return param_1;
}

