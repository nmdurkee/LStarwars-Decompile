/* Ghidra analysis pseudocode, not original source.
 * ev_c1ca6a36f678473ebb33648a43a5c1c2c83c1c89260a3af1d5a93a85b2681cef
 * Entry: 0x547240; label: FUN_00547240
 */

int FUN_00547240(int *param_1)

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
    *(int *)(iVar1 + 8) = param_1[3];
    if (param_1[3] == 0) {
      param_1[2] = iVar1;
    }
    else {
      *(int *)(param_1[3] + 4) = iVar1;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    param_1[3] = iVar1;
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) | 1;
    *(short *)((int)param_1 + 0x16) = *(short *)((int)param_1 + 0x16) + 1;
    if (param_1[6] != iVar3) {
      (*(code *)PTR_FUN_00800824)();
    }
    return iVar1 + 0x10;
  }
  return 0;
}

