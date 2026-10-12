/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x6336a0; label: FUN_006336a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006336a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 0xc) + -1;
  if (*(int *)(in_ECX + 0x10) <= iVar2) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(in_ECX + 4) + iVar2 * 4);
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(1);
      }
      *(undefined4 *)(*(int *)(in_ECX + 4) + iVar2 * 4) = 0;
      iVar2 = iVar2 + -1;
    } while (*(int *)(in_ECX + 0x10) <= iVar2);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x10);
    return;
  }
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x10);
  return;
}

