/* Ghidra pseudocode, not original source.
 * ev_f078e74f3672802c4578b8fbf1fdb2968ffe8ab04b5a400d7e6a18af3d5b4204
 * Entry: 0x5d0130; label: FUN_005d0130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0130(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    iVar1 = param_1[2];
    if (iVar1 != 0) {
      *param_2 = *(undefined4 *)(iVar1 + 0x80);
      param_2[1] = *(undefined4 *)(iVar1 + 0x84);
      param_2[2] = *(undefined4 *)(iVar1 + 0x88);
      iVar1 = param_1[2];
      *param_3 = *(undefined4 *)(iVar1 + 0x90);
      param_3[1] = *(undefined4 *)(iVar1 + 0x94);
      param_3[2] = *(undefined4 *)(iVar1 + 0x98);
    }
    return;
  }
  iVar1 = *(int *)(*(int *)(*param_1 + 0x18) + *(short *)(*(int *)(param_1[1] + 0x40) + 0x40) * 4);
  for (iVar2 = *(int *)(iVar1 + 0x4c); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x4c)) {
    iVar1 = iVar2;
  }
  *param_2 = *(undefined4 *)(iVar1 + 0x1c);
  param_2[1] = *(undefined4 *)(iVar1 + 0x20);
  param_2[2] = *(undefined4 *)(iVar1 + 0x24);
  *param_3 = *(undefined4 *)(iVar1 + 0x28);
  param_3[1] = *(undefined4 *)(iVar1 + 0x2c);
  param_3[2] = *(undefined4 *)(iVar1 + 0x30);
  return;
}

