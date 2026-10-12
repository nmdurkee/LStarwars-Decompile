/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x5474d0; label: FUN_005474d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005474d0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = DAT_0297ad54;
  piVar3 = (int *)(param_1 + -0x10);
  puVar1 = (undefined4 *)*piVar3;
  if (puVar1[6] != DAT_0297ad54) {
    (*(code *)PTR_FUN_00800820)();
  }
  if (*(int *)(param_1 + -0xc) == 0) {
    puVar1[3] = *(undefined4 *)(param_1 + -8);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + -0xc) + 8) = *(undefined4 *)(param_1 + -8);
  }
  if (*(int *)(param_1 + -8) == 0) {
    puVar1[2] = *(undefined4 *)(param_1 + -0xc);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + -8) + 4) = *(undefined4 *)(param_1 + -0xc);
  }
  *(undefined4 *)(param_1 + -8) = puVar1[1];
  *(undefined4 *)(param_1 + -0xc) = 0;
  if (puVar1[1] == 0) {
    *puVar1 = piVar3;
    puVar1[1] = piVar3;
  }
  else {
    *(int **)(puVar1[1] + 4) = piVar3;
  }
  *(short *)((int)puVar1 + 0x16) = *(short *)((int)puVar1 + 0x16) + -1;
  puVar1[1] = piVar3;
  *(ushort *)(param_1 + -2) = *(ushort *)(param_1 + -2) & 0xfffe;
  if (puVar1[6] != iVar2) {
                    /* WARNING: Could not recover jumptable at 0x0054754b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_FUN_00800824)();
    return;
  }
  return;
}

