/* Ghidra analysis pseudocode, not original source.
 * ev_d93daca17d105ef5f57eb8b76e4a8c3d960b6599f63d34fdaa382c813fb01a39
 * Entry: 0x578140; label: FUN_00578140
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00578140(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 param_7,undefined4 *param_8,
                 undefined4 param_9,float param_10,float param_11,undefined4 param_12,float param_13
                 ,float param_14,undefined4 param_15,int param_16,undefined4 param_17,char param_18,
                 char param_19)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  *(undefined4 *)(PTR_DAT_008021b4 + 0x1bc) = 0;
  if ((param_1 & 0x200) != 0) {
    _memset(&DAT_00951500,0,0x3fc);
    uVar3 = DAT_0093b0d4;
    uVar2 = DAT_0093b0d0;
    uVar1 = DAT_0093b0cc;
    FUN_00576c60(1,param_10,0,0,DAT_0093b0cc,DAT_0093b0d0,DAT_0093b0d4);
    _DAT_009518f4 = param_15;
    if (((param_1 & 0x80) == 0) || (param_6 == (undefined4 *)0x0)) {
      _DAT_009518c8 = uVar1;
      _DAT_009518d4 = uVar1;
      DAT_009518c4 = (undefined4 *)&DAT_009518d4;
      _DAT_009518cc = uVar2;
      _DAT_009518d0 = uVar3;
      _DAT_009518d8 = uVar2;
      _DAT_009518dc = uVar3;
      DAT_009518e0 = *param_8;
      DAT_009518e4 = param_8[1];
      DAT_009518e8 = param_8[2];
      _DAT_009514f0 = 2;
      _DAT_009514f2 = 0xc;
      _DAT_009514f8 = &DAT_009518fc;
      _DAT_009514fc = param_7;
      _DAT_009518fc = DAT_009518e0;
      _DAT_00951900 = DAT_009518e4;
      _DAT_00951904 = DAT_009518e8;
      FUN_00577790(&DAT_009514f0,param_9,0x4e6e6b28,param_10,0,DAT_00951884,0);
      DAT_00951924 = &DAT_009518e0;
    }
    else {
      DAT_009518c4 = param_6;
      _DAT_009518c8 = uVar1;
      _DAT_009518cc = uVar2;
      _DAT_009518d0 = uVar3;
      _DAT_009518d4 = *param_6;
      _DAT_009518d8 = param_6[1];
      _DAT_009518dc = param_6[2];
      DAT_009518e0 = *param_8;
      DAT_009518e4 = param_8[1];
      DAT_009518e8 = param_8[2];
      FUN_00577880(&DAT_009518e0,&DAT_009518d4,param_7,param_9,0x4e6e6b28,param_10,0,1,1,
                   DAT_00951884);
    }
  }
  uVar3 = DAT_0093b0d4;
  uVar2 = DAT_0093b0d0;
  uVar1 = DAT_0093b0cc;
  if ((param_1 & 0x1c00) == 0) {
    param_1 = param_1 | 0x800;
    param_13 = 0.0;
  }
  if ((char)param_1 < '\0') {
    FUN_00576c60(8,0,0,param_6,DAT_0093b0cc,DAT_0093b0d0,DAT_0093b0d4);
  }
  if ((param_1 & 0x100) == 0) {
    uVar6 = uVar1;
    uVar7 = uVar2;
    uVar8 = uVar3;
    if ((param_1 & 0x2000) != 0) {
      param_2 = 0;
      uVar5 = 0x11;
      goto LAB_005783e8;
    }
    if ((param_1 & 1) != 0) {
      param_17 = 0;
      uVar5 = 9;
      goto LAB_005783e8;
    }
  }
  else {
    param_17 = 0;
    param_2 = 0;
    uVar5 = 0x10;
    uVar6 = *param_8;
    uVar7 = param_8[1];
    uVar8 = param_8[2];
LAB_005783e8:
    FUN_00576c60(uVar5,param_2,0,param_17,uVar6,uVar7,uVar8);
  }
  if ((param_1 & 0x10) == 0) {
    if ((param_1 & 2) != 0) {
      uVar6 = 10;
      goto LAB_00578438;
    }
  }
  else {
    uVar6 = 0xd;
LAB_00578438:
    FUN_00576c60(uVar6,0,param_3,0,uVar1,uVar2,uVar3);
  }
  if ((param_1 & 0x20) == 0) {
    if ((param_1 & 4) != 0) {
      uVar6 = 0xb;
      goto LAB_00578488;
    }
  }
  else {
    uVar6 = 0xe;
LAB_00578488:
    FUN_00576c60(uVar6,0,param_4,0,uVar1,uVar2,uVar3);
  }
  if ((param_1 & 0x40) != 0) {
    FUN_00576c60(0xf,0,param_5,0,uVar1,uVar2,uVar3);
  }
  if ((param_1 & 8) != 0) {
    FUN_00576c60(0xc,0,param_5,0,uVar1,uVar2,uVar3);
  }
  if (param_18 != -1) {
    FUN_00576c60(6,0,(int)param_18,0,uVar1,uVar2,uVar3);
  }
  if (param_19 != -1) {
    FUN_00576c60(7,0,(int)param_19,0,uVar1,uVar2,uVar3);
  }
  if (((((param_1 & 1) != 0) && ((param_1 & 4) != 0)) && (0.0 < param_10)) && (param_13 == 0.0)) {
    param_13 = 0.01;
  }
  uVar4 = param_1 & 0x800;
  if ((uVar4 == 0) || ((param_1 & 0x1000) == 0)) {
    if (uVar4 != 0) goto LAB_00578615;
    if ((param_1 & 0x1000) != 0) {
      FUN_00576c60(5,param_14,0,0,uVar1,uVar2,uVar3);
    }
  }
  else if (param_14 <= param_13) {
LAB_00578615:
    FUN_00576c60(4,param_13,0,0,uVar1,uVar2,uVar3);
  }
  else {
    FUN_00576c60(4,param_13,0,0,uVar1,uVar2,uVar3);
    FUN_00576c60(5,param_14 - param_13,0,0,uVar1,uVar2,uVar3);
  }
  if ((param_1 & 0x400) == 0) goto LAB_00578705;
  _param_18 = param_11;
  if (uVar4 == 0) {
LAB_005786a9:
    if ((param_1 & 0x1000) != 0) {
      _param_18 = param_11 - param_14;
    }
  }
  else if ((param_1 & 0x1000) == 0) {
    if (uVar4 == 0) goto LAB_005786a9;
    _param_18 = param_11 - param_13;
  }
  else if (param_14 <= param_13) {
    _param_18 = param_11 - param_13;
  }
  else {
    _param_18 = param_11 - param_14;
  }
  if (_param_18 < 0.0) {
    _param_18 = 0.0;
  }
  FUN_00576c60(3,_param_18,0,0,uVar1,uVar2,uVar3);
  _DAT_009514ec = param_12;
LAB_00578705:
  if (param_16 != 0) {
    DAT_00951884 = 1;
  }
  return;
}

