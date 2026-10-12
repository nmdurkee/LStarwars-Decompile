/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x695f60; label: FUN_00695f60
 */

undefined4 FUN_00695f60(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if ((in_ECX == 0) || (DAT_02962b8c == 0)) {
    return 0xffffffff;
  }
  if (*(int *)(in_ECX + 0x1d8) == 0) {
    return 0xfffffffe;
  }
  iVar1 = FUN_00693e80(param_1);
  if (iVar1 == 0) {
    return 0xfffffffd;
  }
  iVar3 = *(int *)(in_ECX + 0x1d0);
  if (*(int *)(iVar1 + 0xc + iVar3 * 4) == -1) {
    return 0xfffffffd;
  }
  iVar2 = FUN_00693c90(iVar1);
  if (iVar2 != 0) {
    return 1;
  }
  if ((*(int *)(iVar1 + 0x14) == 8) && (iVar2 = FUN_00693ce0(8), iVar2 != 0)) {
    if (*(int *)(iVar2 + 0x18) == 6) {
      return 0xfffffffb;
    }
    if (*(int *)(iVar2 + 0x18) == 7) {
      return 0xfffffffb;
    }
    iVar3 = FUN_006955e0(iVar1,iVar3);
    if (iVar3 != 0) goto LAB_0069601b;
  }
  iVar3 = FUN_00693da0();
  if ((iVar3 == 0) || (iVar1 = FUN_006955e0(iVar1,*(undefined4 *)(in_ECX + 0x1d0)), iVar1 == 0)) {
    return 0xfffffffb;
  }
LAB_0069601b:
  uVar4 = FUN_00695720();
  return uVar4;
}

