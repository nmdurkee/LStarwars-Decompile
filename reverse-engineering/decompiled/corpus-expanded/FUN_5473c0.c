/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x5473c0; label: FUN_005473c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005473c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = DAT_0297ad54;
  piVar1 = *(int **)(param_1 + -0x10);
  if (piVar1[6] != DAT_0297ad54) {
    (*(code *)PTR_FUN_00800820)();
  }
  iVar2 = *piVar1;
  if (iVar2 != 0) {
    iVar3 = *(int *)(iVar2 + 4);
    *piVar1 = iVar3;
    if (iVar3 == 0) {
      piVar1[1] = 0;
    }
    else {
      *(undefined4 *)(iVar3 + 8) = 0;
    }
    *(int **)(iVar2 + 4) = (int *)(param_1 + -0x10);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(param_1 + -8);
    *(int *)(param_1 + -8) = iVar2;
    if (*(int *)(iVar2 + 8) == 0) {
      piVar1[2] = iVar2;
    }
    else {
      *(int *)(*(int *)(iVar2 + 8) + 4) = iVar2;
    }
    *(ushort *)(iVar2 + 0xe) = *(ushort *)(iVar2 + 0xe) | 1;
    *(short *)((int)piVar1 + 0x16) = *(short *)((int)piVar1 + 0x16) + 1;
    if (piVar1[6] != iVar4) {
      (*(code *)PTR_FUN_00800824)();
    }
    return iVar2 + 0x10;
  }
  if (piVar1[6] != iVar4) {
    (*(code *)PTR_FUN_00800824)();
  }
  return 0;
}

