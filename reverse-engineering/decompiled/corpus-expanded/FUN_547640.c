/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547640; label: FUN_00547640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00547640(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_2 + -8);
  iVar2 = param_2 + -0x10;
  if (iVar1 != 0) {
    if (*(int *)(param_2 + -0xc) == 0) {
      *(int *)(param_1 + 0xc) = iVar1;
    }
    else {
      *(int *)(*(int *)(param_2 + -0xc) + 8) = iVar1;
    }
    *(undefined4 *)(*(int *)(param_2 + -8) + 4) = *(undefined4 *)(param_2 + -0xc);
    iVar1 = *(int *)(*(int *)(param_2 + -8) + 8);
    if (iVar1 == 0) {
      *(int *)(param_1 + 8) = iVar2;
    }
    else {
      *(int *)(iVar1 + 4) = iVar2;
    }
    iVar1 = *(int *)(param_2 + -8);
    *(undefined4 *)(param_2 + -8) = *(undefined4 *)(iVar1 + 8);
    *(int *)(param_2 + -0xc) = iVar1;
    *(int *)(iVar1 + 8) = iVar2;
    return 1;
  }
  return 0;
}

