/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x601030; label: FUN_00601030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601030(int param_1)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  
  FUN_006df300();
  if (0 < *(short *)(param_1 + 0x74)) {
    *(int *)(param_1 + 0xb8) = (int)*(short *)(param_1 + 0x74);
    if (*(char *)(param_1 + 0x15c) == '\0') {
      *(undefined1 *)(param_1 + 0x15c) = 1;
    }
    if ((*(uint *)(param_1 + 0x1f0) & 0x3800) == 0) {
      *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) & 0xffffcfff | 0x800;
    }
  }
  if (((*(uint *)(param_1 + 0x44) & 0x800000) != 0) && (*(int *)(param_1 + 0x3c) == 0)) {
    *(uint *)(param_1 + 0x1f0) = *(uint *)(param_1 + 0x1f0) | 0x40000;
  }
  if (0 < *(short *)(param_1 + 500)) {
    uVar1 = FUN_00741620((int)*(short *)(param_1 + 500));
    FUN_007415b0(uVar1);
  }
  if (0 < *(short *)(param_1 + 0x1f6)) {
    uVar1 = FUN_00741620((int)*(short *)(param_1 + 0x1f6));
    FUN_007415b0(uVar1);
  }
  if (((*(uint *)(param_1 + 0x44) & 0x800000) == 0) || (*(int *)(param_1 + 0x3c) != 0)) {
    uVar1 = FUN_006e27d0();
    puVar2 = (undefined2 *)FUN_00741790(param_1 + 0xb4,param_1,uVar1);
    uVar1 = FUN_006e27f0();
    puVar3 = (undefined2 *)FUN_00741790(param_1 + 0xb4,param_1,uVar1);
    *(undefined2 *)(param_1 + 500) = *puVar2;
    *(undefined2 *)(param_1 + 0x1f6) = *puVar3;
  }
  else {
    puVar2 = (undefined2 *)FUN_00741770(param_1 + 0xb4,param_1);
    *(undefined2 *)(param_1 + 500) = *puVar2;
  }
  uVar1 = FUN_007418c0(*(undefined4 *)(param_1 + 0x1f0));
  *(undefined4 *)(param_1 + 700) = uVar1;
  if (*(short *)(param_1 + 0x74) == 0) {
    *(uint *)(param_1 + 200) =
         (((int)ROUND(*(float *)(param_1 + 0x5c) * 255.0) & 0xffU | 0xffffff00) << 8 |
         (int)ROUND(*(float *)(param_1 + 0x58) * 255.0) & 0xffU) << 8 |
         (int)ROUND(*(float *)(param_1 + 0x54) * 255.0) & 0xffU;
  }
  FUN_006df310();
  return;
}

