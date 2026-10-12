/* Ghidra pseudocode, not original source.
 * ev_45200ba16e8ef520c819c849d12b8874968ca721432c6a61fa3b24bce95adf30
 * Entry: 0x696900; label: thunk_FUN_00696040
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 thunk_FUN_00696040(undefined4 param_1,int param_2)

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

