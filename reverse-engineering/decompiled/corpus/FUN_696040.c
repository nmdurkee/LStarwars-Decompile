/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x696040; label: FUN_00696040
 */

undefined4 FUN_00696040(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  if ((in_ECX == 0) || (DAT_02962b8c == 0)) {
    return 0xffffffff;
  }
  if (*(int *)(in_ECX + 0x1d8) == 0) {
    return 0xfffffffe;
  }
  iVar1 = FUN_00693e80(param_1);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc + *(int *)(in_ECX + 0x1d0) * 4) != -1)) {
    iVar4 = *(int *)(iVar1 + 0x14);
    if ((iVar4 != 0x10) &&
       ((iVar2 = FUN_00693d30(0x10,6), iVar2 != 0 || (iVar2 = FUN_00693d30(0x10,7), iVar2 != 0)))) {
      uVar3 = FUN_00695f60(param_1);
      return uVar3;
    }
    iVar2 = FUN_00693c90(iVar1);
    if (iVar2 != 0) {
      uVar3 = FUN_006957d0();
      return uVar3;
    }
    if ((iVar4 == 8) && (iVar2 = FUN_00693ce0(8), iVar2 != 0)) {
      if ((*(int *)(iVar2 + 0x18) != 1) && (*(int *)(iVar2 + 0x18) != 3)) {
        return 0xfffffffb;
      }
      iVar1 = FUN_006955e0(iVar1,*(undefined4 *)(in_ECX + 0x1d0));
      if (iVar1 == 0) {
        return 0xfffffffb;
      }
    }
    else {
      if (iVar4 == 0x10) {
        FUN_00693fd0(0);
      }
      iVar4 = FUN_00693da0();
      if (((iVar4 == 0) || (iVar1 = FUN_006955e0(iVar1,*(undefined4 *)(in_ECX + 0x1d0)), iVar1 == 0)
          ) || (param_2 != 0)) {
        return 0xfffffffb;
      }
    }
    uVar3 = FUN_006957d0();
    return uVar3;
  }
  return 0xfffffffd;
}

