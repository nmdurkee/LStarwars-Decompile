/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da8d0; label: FUN_005da8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005da8d0(int *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    if (param_1[1] == 0) {
      if (param_1[2] == 0) {
        return;
      }
      iVar3 = *(int *)(param_1[2] + 0xc4);
      if (iVar3 == -1) {
        return;
      }
      if (iVar3 == 0) {
        return;
      }
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1[1] + 0x40) + 0x48);
    }
    if (iVar3 != 0) {
      uVar2 = *(uint *)(iVar3 + 0x50);
      *(undefined4 *)(iVar3 + 0x4c) = param_2;
      if ((uVar2 >> 0x16 != 0) && (iVar1 = *(int *)(iVar1 + 0x1e0), iVar1 != 0)) {
        param_1 = (int *)CONCAT31(param_1._1_3_,(char)(uVar2 >> 0xe));
        FUN_005da480(iVar1 + -0xc + (uVar2 >> 0x16) * 0xc,&param_1,&local_1,param_2);
        *(uint *)(iVar3 + 0x50) = ((uint)param_1 & 0xff) << 0xe | uVar2 & 0xffc03fff;
        return;
      }
    }
  }
  return;
}

