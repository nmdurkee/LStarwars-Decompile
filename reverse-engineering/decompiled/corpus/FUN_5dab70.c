/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5dab70; label: FUN_005dab70
 */

int FUN_005dab70(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(param_2 + 400)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(param_1,*(undefined4 *)(iVar3 + *(int *)(param_2 + 0x194)));
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x14;
    } while (iVar2 < *(int *)(param_2 + 400));
  }
  return -1;
}

