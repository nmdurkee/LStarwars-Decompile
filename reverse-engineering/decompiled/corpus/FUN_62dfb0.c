/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62dfb0; label: FUN_0062dfb0
 */

void FUN_0062dfb0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    iVar3 = *(int *)(DAT_029130e4 + 0xc);
  }
  else {
    iVar3 = 0;
  }
  if (iVar3 < *(int *)(DAT_029130e4 + 0x10)) {
    iVar4 = iVar3 * 0x54;
    iVar2 = DAT_029130e4;
    do {
      iVar1 = *(int *)(*(int *)(iVar2 + 0x18) + 4 + iVar4);
      if (iVar1 != 0) {
        thunk_FUN_005ef880(iVar1);
        iVar2 = DAT_029130e4;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x54;
    } while (iVar3 < *(int *)(iVar2 + 0x10));
  }
  return;
}

