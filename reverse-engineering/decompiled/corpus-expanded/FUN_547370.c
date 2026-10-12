/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547370; label: FUN_00547370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00547370(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_0297ad54;
  if (*(int *)(param_1 + 0x18) != DAT_0297ad54) {
    (*(code *)PTR_FUN_00800820)();
  }
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_2 + 4) = 0;
  if (*(int *)(param_1 + 0xc) == 0) {
    *(int *)(param_1 + 8) = param_2;
  }
  else {
    *(int *)(*(int *)(param_1 + 0xc) + 4) = param_2;
  }
  *(int *)(param_1 + 0xc) = param_2;
  if (*(int *)(param_1 + 0x18) != iVar1) {
                    /* WARNING: Could not recover jumptable at 0x005473b1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_FUN_00800824)();
    return;
  }
  return;
}

