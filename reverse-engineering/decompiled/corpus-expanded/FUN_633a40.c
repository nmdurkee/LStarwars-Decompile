/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633a40; label: FUN_00633a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633a40(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0xc)) {
    do {
      if ((*(int *)(*(int *)(in_ECX + 4) + iVar2 * 4) != 0) &&
         (iVar1 = *(int *)(*(int *)(in_ECX + 4) + iVar2 * 4),
         (~(*(uint *)(iVar1 + 8) >> 8) & 1) != 0)) {
        if (*(int *)(iVar1 + 0xc) != 0) {
          FUN_005d8400(*(undefined4 *)(in_ECX + 0x18),3,&PTR_DAT_0076b274);
        }
        (**(code **)(**(int **)(*(int *)(in_ECX + 4) + iVar2 * 4) + 0x28))(param_1);
        if (*(int *)(*(int *)(*(int *)(in_ECX + 4) + iVar2 * 4) + 0xc) != 0) {
          FUN_005d8440(*(undefined4 *)(in_ECX + 0x18),3);
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(in_ECX + 0xc));
  }
  return;
}

