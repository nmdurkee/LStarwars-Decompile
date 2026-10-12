/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59a6b0; label: FUN_0059a6b0
 */

void FUN_0059a6b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (iVar2 = *(int *)(param_1 + 4), iVar2 != 0)) && (param_2 != 0)) {
    if (iVar2 == param_2) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 0x38);
      *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 8);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      *(int *)(param_1 + 8) = param_2;
      return;
    }
    if (*(int *)(iVar2 + 0x38) != 0) {
      while (iVar1 = *(int *)(iVar2 + 0x38), iVar1 != param_2) {
        iVar2 = iVar1;
        if (*(int *)(iVar1 + 0x38) == 0) {
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
          return;
        }
      }
      *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
      *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 8);
      *(int *)(param_1 + 8) = param_2;
    }
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  }
  return;
}

