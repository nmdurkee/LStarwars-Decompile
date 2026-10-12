/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x45d3d0; label: FUN_0045d3d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045d3d0(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  short local_8;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    DAT_00876db4._0_2_ = 0;
    *(float *)(param_1 + 0x1c) = _DAT_007f8220 * 3.0 + 3.0;
    return;
  }
  if (*(int *)(param_1 + 0x14) != 1) {
    return;
  }
  FUN_00482f10(param_2,1);
  fVar1 = *(float *)(param_1 + 0x18);
  fVar2 = param_3 + *(float *)(param_1 + 0x18);
  *(float *)(param_1 + 0x18) = fVar2;
  if (fVar2 < _DAT_007f8220) {
    local_8 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_8;
    goto LAB_0045d52b;
  }
  if (_DAT_007f8224 + _DAT_007f8220 <= fVar2) {
    if (*(float *)(param_1 + 0x18) < _DAT_007f8220 * 2.0 + _DAT_007f8224) {
      local_8 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
      DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_8;
      goto LAB_0045d52b;
    }
    if (*(float *)(param_1 + 0x1c) - _DAT_007f8220 < *(float *)(param_1 + 0x18)) {
      local_8 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
      DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_8;
      goto LAB_0045d52b;
    }
  }
  DAT_00876db4._0_2_ = 0;
LAB_0045d52b:
  if (*(float *)(param_1 + 0x1c) < *(float *)(param_1 + 0x18) !=
      (*(float *)(param_1 + 0x1c) == *(float *)(param_1 + 0x18))) {
    if ((*(int *)(*(int *)(param_2 + 0x124) + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')
       ) {
      **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
    }
    if ((*(int *)(*(int *)(param_2 + 0x124) + 0xc) == 0x17) && (*(char *)(param_2 + 0xa6) == '\x02')
       ) {
      **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
    }
    FUN_004838f0(param_2);
    return;
  }
  if ((_DAT_007f8220 <= fVar1) || (*(float *)(param_1 + 0x18) < _DAT_007f8220)) {
    fVar2 = _DAT_007f8220 * 2.0 + _DAT_007f8224;
    if ((fVar2 <= fVar1) || (*(float *)(param_1 + 0x18) < fVar2)) {
      if (((*(int *)(*(int *)(param_2 + 0x124) + 0xc) == 0x1a) &&
          (*(char *)(param_2 + 0xa7) == '\x02')) ||
         ((*(int *)(param_1 + 0xc) == 0x17 && (*(char *)(param_2 + 0xa6) == '\x02')))) {
        fVar2 = *(float *)(param_1 + 0x1c) - 0.75;
        if ((fVar1 < fVar2) && (fVar2 <= *(float *)(param_1 + 0x18))) {
          _DAT_0087b93c = 0x3fc00000;
          FUN_004836f0(0xffffffff,0,0x3dcccccd,0);
          FUN_00681f40("Shop_BuyCheat",0);
          return;
        }
        fVar1 = *(float *)(param_1 + 0x18);
        if ((!NAN(fVar1) && 0.75 < fVar1 != (fVar1 == 0.75)) && (*(float *)(param_1 + 0x18) < fVar2)
           ) {
          FUN_00681f40("PickupCoin",0);
          return;
        }
      }
      return;
    }
    iVar3 = *(int *)(*(int *)(param_2 + 0x124) + 0xc);
  }
  else {
    iVar3 = *(int *)(*(int *)(param_2 + 0x124) + 0xc);
  }
  if (((iVar3 == 0x17) && (*(char *)(param_2 + 0xa6) == '\x03')) ||
     ((iVar3 == 0x1a && (*(char *)(param_2 + 0xa7) == '\x03')))) {
    FUN_00547930(0x32,0,0,0);
  }
  else {
    FUN_00681f40("StatusAward",0);
  }
  FUN_004836f0(0xffffffff,0x3f19999a,0,0);
  return;
}

