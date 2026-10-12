/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56fea0; label: FUN_0056fea0
 */

undefined4 FUN_0056fea0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  if (*(int *)(*(int *)(param_1 + 0x50b8) + 8) != 0) {
    return 0;
  }
  iVar2 = FUN_006217e0();
  uVar3 = FUN_006217e0();
  *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 8) = uVar3;
  if (2 < iVar2) {
    uVar3 = FUN_006217e0();
    *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 0x10) = uVar3;
  }
  if (iVar2 < 5) {
    DAT_00950f60 = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 0x18) = 0x3f800000;
  }
  else {
    fVar6 = (float10)FUN_006217a0();
    *(float *)(*(int *)(param_1 + 0x50b8) + 0x14) = (float)fVar6;
    fVar6 = (float10)FUN_006217a0();
    *(float *)(*(int *)(param_1 + 0x50b8) + 0x18) = (float)fVar6;
    if (iVar2 < 6) {
      FUN_0056f930();
      *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 0x18) = DAT_00950f60;
    }
    else {
      DAT_00950f60 = *(undefined4 *)(*(int *)(param_1 + 0x50b8) + 0x18);
    }
  }
  FUN_0056f990(iVar2);
  FUN_0056f9f0(*(undefined4 *)(param_1 + 0x120),*(undefined4 *)(param_1 + 0x11c));
  iVar5 = **(int **)(param_1 + 0x50b8);
  iVar4 = 0;
  if (0 < (*(int **)(param_1 + 0x50b8))[2]) {
    do {
      FUN_006216f0(iVar5,8);
      FUN_00621900(iVar5 + 8);
      uVar1 = FUN_006218c0();
      *(undefined1 *)(iVar5 + 0x14) = uVar1;
      if (1 < iVar2) {
        uVar1 = FUN_006218c0();
        *(undefined1 *)(iVar5 + 0x15) = uVar1;
      }
      if (3 < iVar2) {
        uVar1 = FUN_006218c0();
        *(undefined1 *)(iVar5 + 0x18) = uVar1;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x2c;
    } while (iVar4 < *(int *)(*(int *)(param_1 + 0x50b8) + 8));
  }
  return 1;
}

