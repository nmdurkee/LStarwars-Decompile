/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x696220; label: FUN_00696220
 */

void FUN_00696220(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  FUN_004f7fb0(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x510);
  iVar3 = FUN_006946b0(uVar1);
  if (iVar3 == 0) {
    uVar2 = *(undefined4 *)(in_ECX + 300);
    iVar3 = FUN_004f1ff0(uVar1);
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + iVar3 + 1;
    FUN_004f1f10(uVar2,uVar1);
    *(undefined4 *)(*(int *)(in_ECX + 0x20) + 8) = uVar2;
    return;
  }
  *(int *)(*(int *)(in_ECX + 0x20) + 8) = iVar3;
  return;
}

