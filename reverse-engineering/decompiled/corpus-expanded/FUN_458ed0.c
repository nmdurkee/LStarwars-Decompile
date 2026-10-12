/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x458ed0; label: FUN_00458ed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00458ed0(float param_1,int param_2,float param_3)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  short local_4;
  
  iVar3 = (int)param_1;
  switch(*(undefined4 *)((int)param_1 + 0x14)) {
  case 0:
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    *(undefined4 *)((int)param_1 + 0x14) = 1;
    DAT_00876db4._0_2_ = 0;
    *(undefined4 *)((int)param_1 + 0x1c) = _DAT_007f8220;
    *(undefined4 *)(param_2 + 0x58) = 0;
    return;
  case 1:
    fVar1 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = fVar1;
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)((int)param_1 + 0x1c) < fVar1 != (*(float *)((int)param_1 + 0x1c) == fVar1)) {
      *(undefined4 *)((int)param_1 + 0x14) = 2;
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x1c) = _DAT_007f8220;
      return;
    }
    break;
  case 2:
    fVar1 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = fVar1;
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)((int)param_1 + 0x1c) < fVar1 != (*(float *)((int)param_1 + 0x1c) == fVar1)) {
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      uVar2 = _DAT_007f8224;
      *(undefined4 *)((int)param_1 + 0x14) = 3;
      *(undefined4 *)((int)param_1 + 0x1c) = uVar2;
      *(undefined4 *)(param_2 + 0x58) = 0;
      _DAT_007f8268 = 5.0;
      return;
    }
    break;
  case 3:
    DAT_00876db4._0_2_ = 0;
    param_3 = *(float *)((int)param_1 + 0x18) + param_3;
    *(float *)((int)param_1 + 0x18) = param_3;
    if (*(float *)((int)param_1 + 0x1c) < param_3 != (*(float *)((int)param_1 + 0x1c) == param_3)) {
      *(undefined4 *)((int)param_1 + 0x14) = 4;
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x1c) = _DAT_007f8220;
      return;
    }
    break;
  case 4:
    fVar1 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = fVar1;
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)((int)param_1 + 0x1c) < fVar1 != (*(float *)((int)param_1 + 0x1c) == fVar1)) {
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x14) = 5;
      *(undefined4 *)((int)param_1 + 0x1c) = 0x40400000;
      return;
    }
    break;
  case 5:
    FUN_00482f10(param_2,3);
    if ((*(byte *)(param_2 + 0xb0) & 4) == 0) {
      param_1 = (*(float *)(param_2 + 0x50) * 100.0) / *(float *)(param_2 + 0x54);
      if (99.0 < param_1) {
        param_1 = 99.0;
      }
    }
    else {
      param_1 = 100.0;
    }
    *(float *)(iVar3 + 0x18) = param_3 + *(float *)(iVar3 + 0x18);
    fVar1 = param_3 * (100.0 / *(float *)(iVar3 + 0x1c)) + *(float *)(param_2 + 0x58);
    *(float *)(param_2 + 0x58) = fVar1;
    if (fVar1 <= param_1) {
      if (_DAT_007f8268 < fVar1 != (_DAT_007f8268 == fVar1)) {
        FUN_00681f40("Status_GoldBarDec",0);
        _DAT_007f8268 = _DAT_007f8268 + 10.0;
      }
    }
    else {
      *(float *)(param_2 + 0x58) = param_1;
    }
    if (*(float *)(iVar3 + 0x1c) < *(float *)(iVar3 + 0x18)) {
      *(undefined4 *)(iVar3 + 0x18) = 0;
      *(undefined4 *)(iVar3 + 0x1c) = 0x3f800000;
      if (*(int *)(*(int *)(param_2 + 0x124) + 0xc) != 2) {
        *(undefined4 *)(iVar3 + 0x14) = 6;
        FUN_00681f40("TrueJedi_100pc",0);
        return;
      }
      *(undefined4 *)(iVar3 + 0x14) = 7;
      FUN_00681f40("TrueJedi_NOT",0);
    }
    return;
  case 6:
    if (*(float *)((int)param_1 + 0x18) == 0.0) {
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
    }
    DAT_00876db4._0_2_ = 0;
    param_3 = *(float *)((int)param_1 + 0x18) + param_3;
    *(float *)((int)param_1 + 0x18) = param_3;
    if (*(float *)((int)param_1 + 0x1c) < param_3 != (*(float *)((int)param_1 + 0x1c) == param_3)) {
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x14) = 8;
      *(undefined4 *)((int)param_1 + 0x1c) = 0x3f800000;
      return;
    }
    break;
  case 7:
    DAT_00876db4._0_2_ = 0;
    param_3 = *(float *)((int)param_1 + 0x18) + param_3;
    *(float *)((int)param_1 + 0x18) = param_3;
    if (*(float *)((int)param_1 + 0x1c) < param_3 != (*(float *)((int)param_1 + 0x1c) == param_3)) {
      *(undefined4 *)((int)param_1 + 0x14) = 8;
      *(undefined4 *)((int)param_1 + 0x18) = 0;
      *(undefined4 *)((int)param_1 + 0x1c) = 0x3f800000;
      return;
    }
    break;
  case 8:
    fVar1 = param_3 + *(float *)((int)param_1 + 0x18);
    *(float *)((int)param_1 + 0x18) = fVar1;
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    if (*(float *)((int)param_1 + 0x1c) < fVar1 != (*(float *)((int)param_1 + 0x1c) == fVar1)) {
      FUN_004838f0(param_2);
      return;
    }
  }
  return;
}

