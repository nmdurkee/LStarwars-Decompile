/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x45b020; label: FUN_0045b020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045b020(int param_1,int param_2,float param_3)

{
  uint uVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int local_4;
  
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 0:
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    DAT_00876db4._0_2_ = 0;
    *(float *)(param_1 + 0x1c) = _DAT_007f8220 + _DAT_007f8220 + _DAT_007f8224;
    DAT_0087a1e4 = 1;
    return;
  case 1:
    fVar2 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = fVar2;
    if (*(float *)(param_1 + 0x1c) < fVar2 != (*(float *)(param_1 + 0x1c) == fVar2)) {
      *(undefined4 *)(param_1 + 0x14) = 2;
    }
    local_4._0_2_ = (short)(int)ROUND(param_3 * 65536.0 * 8.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + (short)local_4;
    return;
  case 2:
    DAT_00876dd8 = 0;
    DAT_00876db4._0_2_ = 0;
    puVar5 = (uint *)(param_2 + 0x84);
    local_4 = 2;
    do {
      uVar1 = *puVar5;
      if (uVar1 == 0) {
LAB_0045b14b:
        DAT_00876dd8 = DAT_00876dd8 + 1;
      }
      else {
        uVar3 = 100;
        if (99 < uVar1) {
          do {
            uVar3 = uVar3 * 10;
          } while (uVar3 <= uVar1);
        }
        uVar4 = FUN_006e6b90();
        uVar3 = uVar1;
        if ((uVar4 <= uVar1) && (uVar3 = uVar4, (int)uVar4 < 1)) {
          uVar3 = 1;
        }
        *puVar5 = uVar1 - uVar3;
        FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),uVar3,(int)uVar3 >> 0x1f,0);
        if (*puVar5 == 0) goto LAB_0045b14b;
      }
      puVar5 = puVar5 + 1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    FUN_00681f40("PickupCoin",0);
    if (DAT_00876dd8 == 2) {
      *(undefined4 *)(param_1 + 0x14) = 3;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
      if (*(int *)(param_2 + 0x90) + *(int *)(param_2 + 0x8c) == 0) {
        FUN_00547930(0x32,0,0);
      }
      else {
        FUN_00681f40("Shop_BuyCheat",0);
      }
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
    }
    break;
  case 3:
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      *(undefined4 *)(param_1 + 0x14) = 4;
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(float *)(param_1 + 0x1c) = _DAT_007f8220;
      return;
    }
    break;
  case 4:
    fVar2 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = fVar2;
    local_4._0_2_ = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + (short)local_4;
    if (*(float *)(param_1 + 0x1c) < fVar2 != (*(float *)(param_1 + 0x1c) == fVar2)) {
      FUN_004838f0(param_2);
      return;
    }
  }
  return;
}

