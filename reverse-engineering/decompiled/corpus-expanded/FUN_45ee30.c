/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45ee30; label: FUN_0045ee30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_0045ee30(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined2 uVar5;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x14);
  uVar5 = (undefined2)(uVar4 >> 0x10);
  switch(uVar4) {
  case 0:
    DAT_0087a18c = *(int *)(param_2 + 0x94);
    uVar4 = (uint)*(byte *)(*(int *)(param_2 + 0x14) + 0x7c);
    if (DAT_0087a18c < 1) {
      DAT_0087a1a0 = (uint)(byte)(&DAT_0086e0f9)[uVar4 * 0xc];
    }
    else {
      uVar4 = (uint)(byte)(&DAT_0086e0f9)[uVar4 * 0xc] - DAT_0087a18c;
      DAT_0087a1a0 = uVar4;
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
    return uVar4;
  case 1:
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    fVar1 = *(float *)(param_1 + 0x1c);
    uVar4 = CONCAT22(uVar5,(ushort)(fVar1 < param_3) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_3)) << 10 |
                           (ushort)(fVar1 == param_3) << 0xe);
    if (fVar1 < param_3 != (fVar1 == param_3)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      if (DAT_0087a18c != 0) {
        *(undefined4 *)(param_1 + 0x14) = 2;
        *(undefined4 *)(param_1 + 0x1c) = 0x3f000000;
        _DAT_0087a1ac = 0x3f800000;
        return uVar4;
      }
      uVar4 = FUN_00681f40("TrueJedi_NOT",0);
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
      *(undefined4 *)(param_1 + 0x14) = 4;
      return uVar4;
    }
    break;
  case 2:
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    fVar1 = *(float *)(param_1 + 0x1c);
    uVar4 = CONCAT22(uVar5,(ushort)(fVar1 < param_3) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_3)) << 10 |
                           (ushort)(fVar1 == param_3) << 0xe);
    if (fVar1 < param_3 != (fVar1 == param_3)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      uVar3 = _DAT_007f865c;
      *(undefined4 *)(param_1 + 0x14) = 3;
      *(undefined4 *)(param_1 + 0x1c) = uVar3;
      uVar4 = FUN_00681f40("Jp_Ana_Jump",0);
      return uVar4;
    }
    break;
  case 3:
    if (DAT_0087a18c < 1) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0x40400000;
LAB_0045f02c:
      *(undefined4 *)(param_1 + 0x14) = 4;
    }
    else {
      fVar1 = *(float *)(param_1 + 0x18);
      param_3 = *(float *)(param_1 + 0x18) + param_3;
      *(float *)(param_1 + 0x18) = param_3;
      fVar2 = *(float *)(param_1 + 0x1c) - _DAT_007fa4b8;
      if ((fVar1 < fVar2) &&
         ((!NAN(fVar2) && !NAN(param_3)) && fVar2 < param_3 != (fVar2 == param_3))) {
        FUN_004836f0(0xffffffff,0,0x3dcccccd,0);
        FUN_00681f40("MK-Panel",0);
      }
      uVar4 = FUN_00485120(param_2,param_1);
      if (uVar4 == 1) {
        if ((int)(uint)*(byte *)(param_2 + 0xb5) <= (int)DAT_0087a1a0) {
          *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
          *(undefined4 *)(param_1 + 0x18) = 0;
          goto LAB_0045f02c;
        }
        *(undefined4 *)(param_1 + 0x14) = 2;
        *(undefined4 *)(param_1 + 0x1c) = 0x3f000000;
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
    }
    if (*(int *)(param_1 + 0x14) == 4) {
      if ((*(byte *)(param_2 + 0xb0) & 0x10) == 0) {
        uVar4 = FUN_00681f40("TrueJedi_NOT",0);
        return uVar4;
      }
      *(undefined4 *)(param_1 + 0x14) = 6;
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
    }
    break;
  case 4:
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    fVar1 = *(float *)(param_1 + 0x1c);
    uVar4 = CONCAT22(uVar5,(ushort)(fVar1 < param_3) << 8 |
                           (ushort)(NAN(fVar1) || NAN(param_3)) << 10 |
                           (ushort)(fVar1 == param_3) << 0xe);
    if (fVar1 < param_3 != (fVar1 == param_3)) {
      uVar4 = FUN_004838f0(param_2);
      return uVar4;
    }
    break;
  case 5:
    break;
  case 6:
    FUN_00482f10(param_2,(int)*(char *)(param_2 + 0xb8));
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 == (*(float *)(param_1 + 0x1c) == param_3)) {
      uVar4 = DAT_00925068 % 6;
      if ((uVar4 < 3) && (uVar4 = (DAT_00925068 - 1) / 6, 2 < (DAT_00925068 - 1) % 6)) {
        uVar4 = FUN_004836f0(0xffffffff,0,0,2);
        return uVar4;
      }
    }
    else {
      if (fVar1 < *(float *)(param_1 + 0x1c)) {
        FUN_004857d0();
        FUN_004836f0(0xffffffff,0x3f800000,0x3dcccccd,0);
        uVar4 = FUN_00681f40("Explode1",0);
        return uVar4;
      }
      uVar4 = FUN_005618e0(1,0,0xffffffff,0);
      if (uVar4 == 0) {
        FUN_00681f40("Shop_BuyCheat",0);
        uVar4 = FUN_004838f0(param_2);
        return uVar4;
      }
    }
    break;
  default:
    goto switchD_0045ee43_default;
  }
switchD_0045ee43_default:
  return uVar4;
}

