/* Ghidra pseudocode, not original source.
 * ev_586220d7ac6b37fe8b0c159ff03e90627c1db9a143c695a82bf037091d09cd88
 * Entry: 0x459b50; label: FUN_00459b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00459b50(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  undefined2 uVar4;
  uint uVar3;
  short local_4;
  
  if (0.0 < _DAT_0087a1a8) {
    _DAT_0087a1a8 = _DAT_0087a1a8 - param_3;
  }
  uVar3 = *(uint *)(param_1 + 0x14);
  uVar4 = (undefined2)(uVar3 >> 0x10);
  switch(uVar3) {
  case 0:
    DAT_0087a18c = *(int *)(param_2 + 0x94);
    uVar3 = (uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c);
    if (DAT_0087a18c < 1) {
      DAT_0087a1a0 = (uint)(byte)(&DAT_0086e0f9)[uVar3 * 0xc];
    }
    else {
      uVar3 = (uint)(byte)(&DAT_0086e0f9)[uVar3 * 0xc] - DAT_0087a18c;
      DAT_0087a1a0 = uVar3;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
    DAT_00876db4._0_2_ = 0;
    return uVar3;
  case 1:
    local_4 = (short)(int)ROUND(param_3 * 65536.0 * 4.0);
    DAT_00876db4._0_2_ = (short)DAT_00876db4 + local_4;
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    fVar1 = *(float *)(param_1 + 0x1c);
    uVar3 = (uint)(ushort)((ushort)(fVar1 < param_3) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_3)) << 10 |
                          (ushort)(fVar1 == param_3) << 0xe);
    if (fVar1 < param_3 != (fVar1 == param_3)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      if ((DAT_0087a18c == 0) &&
         (uVar3 = (uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c),
         (&DAT_0086e0f8)[uVar3 * 0xc] == '\0')) {
        uVar3 = FUN_00681f40("TrueJedi_NOT",0);
        *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
        *(undefined4 *)(param_1 + 0x14) = 4;
        _DAT_00876dd4 = 0;
        return uVar3;
      }
      *(undefined4 *)(param_1 + 0x14) = 2;
      *(undefined4 *)(param_1 + 0x1c) = 0x3f000000;
      _DAT_0087a1ac = 0x3f800000;
      return uVar3;
    }
    break;
  case 2:
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    DAT_00876db4._0_2_ = 0;
    *(float *)(param_1 + 0x18) = param_3;
    fVar1 = *(float *)(param_1 + 0x1c);
    uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < param_3) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_3)) << 10 |
                           (ushort)(fVar1 == param_3) << 0xe);
    if (fVar1 < param_3 != (fVar1 == param_3)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = _DAT_007f8248;
      *(undefined4 *)(param_1 + 0x14) = 3;
      uVar3 = FUN_00681f40(&DAT_00758774,0);
      return uVar3;
    }
    break;
  case 3:
    if (DAT_0087a18c < 1) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0x40400000;
LAB_00459dcb:
      _DAT_00876dd4 = 0;
      *(undefined4 *)(param_1 + 0x14) = 4;
    }
    else {
      fVar1 = *(float *)(param_1 + 0x18);
      param_3 = param_3 + *(float *)(param_1 + 0x18);
      *(float *)(param_1 + 0x18) = param_3;
      fVar2 = *(float *)(param_1 + 0x1c) - _DAT_007fa4b8;
      if ((fVar1 < fVar2) &&
         ((!NAN(fVar2) && !NAN(param_3)) && fVar2 < param_3 != (fVar2 == param_3))) {
        FUN_004836f0(0xffffffff,0,0x3dcccccd,0);
        FUN_00681f40("MK-Panel",0);
      }
      uVar3 = FUN_00485120(param_2,param_1);
      if (uVar3 == 1) {
        if ((int)((uint)*(byte *)(param_2 + 0xb5) + *(int *)(param_2 + 0x94)) <= (int)DAT_0087a1a0)
        {
          *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
          *(undefined4 *)(param_1 + 0x18) = 0;
          goto LAB_00459dcb;
        }
        *(undefined4 *)(param_1 + 0x14) = 2;
        *(undefined4 *)(param_1 + 0x1c) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
    }
    if (*(int *)(param_1 + 0x14) == 4) {
      if ((*(byte *)(param_2 + 0xb0) & 0x10) == 0) {
        uVar3 = FUN_00681f40("TrueJedi_NOT",0);
        return uVar3;
      }
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x14) = 5;
      return uVar3;
    }
    break;
  case 4:
    DAT_00876db4._0_2_ = 0;
    param_3 = param_3 + *(float *)(param_1 + 0x18);
    *(float *)(param_1 + 0x18) = param_3;
    fVar1 = *(float *)(param_1 + 0x1c);
    uVar3 = CONCAT22(uVar4,(ushort)(fVar1 < param_3) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_3)) << 10 |
                           (ushort)(fVar1 == param_3) << 0xe);
    if (fVar1 < param_3 != (fVar1 == param_3)) {
      uVar3 = FUN_004838f0(param_2);
      return uVar3;
    }
    break;
  case 5:
    FUN_00482f10(param_2,5);
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 == (*(float *)(param_1 + 0x1c) == param_3)) {
      uVar3 = DAT_00925068 % 6;
      if ((uVar3 < 3) && (uVar3 = (DAT_00925068 - 1) / 6, 2 < (DAT_00925068 - 1) % 6)) {
        uVar3 = FUN_004836f0(0xffffffff,0,0,2);
        return uVar3;
      }
    }
    else {
      if (fVar1 < *(float *)(param_1 + 0x1c)) {
        FUN_004857d0();
        FUN_004836f0(0xffffffff,0x3f800000,0x3dcccccd,0);
        uVar3 = FUN_00681f40("Explode1",0);
        return uVar3;
      }
      uVar3 = FUN_005618e0(1,0,0xffffffff,0);
      if (uVar3 == 0) {
        FUN_00681f40("Shop_BuyCheat",0);
        uVar3 = FUN_004838f0(param_2);
        return uVar3;
      }
    }
    break;
  default:
    return uVar3;
  }
  return uVar3;
}

