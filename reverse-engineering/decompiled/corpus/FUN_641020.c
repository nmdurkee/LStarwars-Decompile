/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x641020; label: FUN_00641020
 */

undefined4 FUN_00641020(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  float10 fVar7;
  
  iVar1 = param_2;
  if (param_2 == 0) {
    return 0;
  }
  FUN_006211c0(1);
  iVar2 = FUN_00621270(param_1,0);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_006211b0(1);
  iVar2 = FUN_006217e0();
  if (5 < iVar2) {
    FUN_006211b0(0);
    FUN_006213e0();
    return 0;
  }
  iVar3 = FUN_006217e0();
  fVar7 = (float10)FUN_006217a0();
  *(float *)(param_2 + 0x24) = (float)fVar7;
  fVar7 = (float10)FUN_006217a0();
  *(float *)(param_2 + 0x14) = (float)fVar7;
  fVar7 = (float10)FUN_006217a0();
  *(float *)(param_2 + 0x1c) = (float)fVar7;
  if (iVar2 < 2) {
    *(undefined4 *)(param_2 + 0xb8) = 0x3f800000;
    *(undefined4 *)(param_2 + 0xbc) = 0x40800000;
    *(undefined4 *)(param_2 + 0xc0) = 0x3e4ccccd;
    *(undefined4 *)(param_2 + 0xc4) = 0x3f000000;
    *(undefined4 *)(param_2 + 200) = 0x3ff33333;
    fVar7 = (float10)0;
  }
  else {
    fVar7 = (float10)FUN_006217a0();
    *(float *)(param_2 + 0xb8) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(param_2 + 0xbc) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(param_2 + 0xc0) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(param_2 + 0xc4) = (float)fVar7;
    if (iVar2 == 2) {
      *(float *)(param_2 + 0xc4) = (float)fVar7 - 1.0;
    }
    fVar7 = (float10)FUN_006217a0();
    *(float *)(param_2 + 200) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
  }
  *(float *)(param_2 + 0xcc) = (float)fVar7;
  if (0x20 < *(int *)(param_2 + 0x550) + iVar3) {
    iVar3 = 0x20 - *(int *)(param_2 + 0x550);
  }
  iVar6 = 0;
  param_2 = iVar3;
  if (0 < iVar3) {
    do {
      piVar4 = (int *)(iVar1 + 0xd0 + iVar6 * 0x24);
      iVar3 = *(int *)(iVar1 + 0xd0 + iVar6 * 0x24);
      while (iVar3 != 0) {
        if (0x1f < iVar6) goto LAB_006411ec;
        piVar4 = piVar4 + 9;
        iVar6 = iVar6 + 1;
        iVar3 = *piVar4;
      }
      if (iVar6 < 0x20) {
        iVar3 = iVar1 + iVar6 * 0x24;
        *(undefined4 *)(iVar3 + 0xd0) = 1;
        FUN_00621900(iVar3 + 0xd4);
        fVar7 = (float10)FUN_006217a0();
        *(float *)(iVar3 + 0xe0) = (float)fVar7;
        fVar7 = (float10)FUN_006217a0();
        *(float *)(iVar3 + 0xe4) = (float)fVar7;
        fVar7 = (float10)FUN_006217a0();
        *(float *)(iVar3 + 0xe8) = (float)fVar7;
        fVar7 = (float10)FUN_006217a0();
        *(float *)(iVar3 + 0xec) = (float)fVar7;
        fVar7 = (float10)FUN_006217a0();
        *(float *)(iVar3 + 0xf0) = (float)fVar7;
        *(int *)(iVar1 + 0x550) = *(int *)(iVar1 + 0x550) + 1;
      }
LAB_006411ec:
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  if (4 < iVar2) {
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 4) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 8) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0xc) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x10) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x20) = (float)fVar7;
    uVar5 = FUN_006217e0();
    *(undefined4 *)(iVar1 + 0x28) = uVar5;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x2c) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x30) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x34) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x38) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x3c) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x40) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x44) = (float)fVar7;
    fVar7 = (float10)FUN_006217a0();
    *(float *)(iVar1 + 0x48) = (float)fVar7;
  }
  FUN_006211b0(0);
  FUN_006213e0();
  *(undefined4 *)(iVar1 + 0x554) = 0xffffffff;
  FUN_0063c1b0(0x3f800000,iVar1);
  *(undefined4 *)(iVar1 + 0xb4) = 1;
  return 1;
}

