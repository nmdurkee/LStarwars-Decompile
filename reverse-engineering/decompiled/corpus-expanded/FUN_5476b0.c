/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x5476b0; label: thunk_FUN_005471c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int thunk_FUN_005471c0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_0297ad54;
  if (*param_1 != 0) {
    if (param_1[6] != DAT_0297ad54) {
      (*(code *)PTR_FUN_00800820)();
    }
    iVar1 = *param_1;
    iVar2 = *(int *)(iVar1 + 4);
    *param_1 = iVar2;
    if (iVar2 == 0) {
      param_1[1] = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 0;
    }
    *(int *)(iVar1 + 4) = param_1[2];
    if (param_1[2] == 0) {
      param_1[3] = iVar1;
    }
    else {
      *(int *)(param_1[2] + 8) = iVar1;
    }
    *(undefined4 *)(iVar1 + 8) = 0;
    *(short *)((int)param_1 + 0x16) = *(short *)((int)param_1 + 0x16) + 1;
    param_1[2] = iVar1;
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) | 1;
    if (param_1[6] != iVar3) {
      (*(code *)PTR_FUN_00800824)();
    }
    return iVar1 + 0x10;
  }
  return 0;
}

