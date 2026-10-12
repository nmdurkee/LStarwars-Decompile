/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c4550; label: FUN_005c4550
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c4550(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 char param_7,float param_8)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_154;
  int local_150;
  int local_14c;
  int local_148;
  int local_144;
  float local_140;
  int local_13c;
  int local_138;
  float local_134;
  double local_130;
  double local_128;
  undefined4 local_120;
  undefined4 local_11c;
  float local_118;
  float local_114;
  undefined4 local_110;
  undefined4 local_10c;
  float local_108;
  float local_104;
  undefined4 local_100;
  float local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  float local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  float local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  float local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  float local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  float local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  float local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90 [5];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  double local_20;
  double local_18;
  
  FUN_005c2760();
  local_148 = 0;
  if (0 < param_6) {
    do {
      if (local_148 == 0) {
        local_154 = param_2;
        iVar4 = param_1;
LAB_005c4584:
        if (param_7 == '\0') goto LAB_005c45c6;
        iVar2 = local_148 + param_4;
        iVar3 = param_3;
      }
      else {
        if (param_7 != '\0') {
          local_154 = local_148 + -1 + param_4;
          iVar4 = param_3;
          goto LAB_005c4584;
        }
        iVar4 = (local_148 + param_4) * 0x30 + -0x30 + param_3;
        local_154 = 0;
LAB_005c45c6:
        iVar3 = (local_148 + param_4) * 0x30 + param_3;
        iVar2 = 0;
      }
      if (0 < param_5) {
        local_13c = param_5;
        local_18 = 1.0;
        do {
          FUN_005f7c60(iVar4,local_154,&local_138,&local_144);
          FUN_005f7c60(iVar3,iVar2,&local_14c,&local_150);
          local_134 = (float)local_138;
          local_90[4] = param_8 / local_134;
          local_140 = (float)local_144;
          local_ec = param_8 / local_140;
          local_90[0] = local_90[4] * 0.0;
          local_90[1] = 0.0;
          local_90[2] = 0.34;
          local_90[3] = 0.0;
          local_100 = 0;
          local_fc = local_ec * 0.0;
          local_f8 = 0x3eae147b;
          local_f4 = 0;
          local_7c = 0;
          local_78 = 0x3e3851ec;
          local_e8 = 0x3e3851ec;
          local_74 = 0;
          local_f0 = 0;
          local_e4 = 0;
          local_70 = local_90[4] * 2.0;
          local_130 = (double)local_70;
          local_6c = 0;
          local_68 = 0x3dcccccd;
          local_64 = 0;
          local_e0 = 0;
          local_dc = local_ec * 2.0;
          local_128 = (double)local_dc;
          local_d8 = 0x3dcccccd;
          local_d4 = 0;
          local_60 = local_90[4] * 3.0;
          local_20 = (double)local_60;
          local_5c = 0;
          local_58 = 0x3d4ccccd;
          local_54 = 0;
          local_d0 = 0;
          local_cc = local_ec * 3.0;
          local_c8 = 0x3d4ccccd;
          local_c4 = 0;
          local_50 = -(local_90[4] * (float)local_18);
          local_4c = 0;
          local_44 = 0;
          local_c0 = 0;
          local_48 = 0x3e3851ec;
          local_bc = -(local_ec * (float)local_18);
          local_b8 = 0x3e3851ec;
          local_b4 = 0;
          local_40 = -local_70;
          local_3c = 0;
          local_34 = 0;
          local_b0 = 0;
          local_38 = 0x3dcccccd;
          local_ac = -local_dc;
          local_a8 = 0x3dcccccd;
          local_a4 = 0;
          local_30 = -local_60;
          local_2c = 0;
          local_24 = 0;
          local_a0 = 0;
          local_28 = 0x3d4ccccd;
          local_9c = -local_cc;
          local_98 = 0x3d4ccccd;
          local_94 = 0;
          local_120 = 0x3f800000;
          local_11c = 0x3f800000;
          local_118 = _DAT_0097accc / local_134;
          local_114 = _DAT_0097accc / local_140;
          local_110 = 0x3f800000;
          local_10c = 0x3f800000;
          local_108 = _DAT_0097acc8 / (float)local_14c;
          local_104 = _DAT_0097acc8 / (float)local_150;
          FUN_00605b60(DAT_00973830,0,iVar3,iVar2);
          FUN_005f8bf0(DAT_00973830);
          FUN_005fa2f0(0,0,local_14c,local_150);
          FUN_005f7ed0(iVar4,2,2);
          if ((local_14c < local_138) || (local_150 < local_144)) {
            uVar6 = 2;
            uVar5 = 2;
          }
          else {
            uVar6 = 1;
            uVar5 = 1;
          }
          FUN_005f7d00(iVar4,uVar5,uVar6,1);
          FUN_005f7cc0(iVar4,local_154,local_154);
          if ((iVar4 != 0) &&
             ((piVar1 = (int *)FUN_005f8460(iVar4), DAT_0097f9b8 != *piVar1 ||
              (DAT_0097f9bc != piVar1[1])))) {
            uVar5 = FUN_005f8460(iVar4);
            FUN_005fa540(0,uVar5);
          }
          FUN_005f8550(iVar4,0);
          FUN_006e5750(0xa0,local_90,7);
          FUN_006e5750(0xad,&local_120,1);
          FUN_005fb550();
          FUN_005f8ba0(0,1);
          FUN_00605b60(DAT_00973830,0,iVar3,iVar2);
          FUN_005f8bf0(DAT_00973830);
          FUN_005fa2f0(0,0,local_14c,local_150);
          FUN_005f7ed0(iVar3,2,2);
          FUN_005f7d00(iVar3,1,1,1);
          FUN_005f7cc0(iVar3,iVar2,iVar2);
          if ((iVar3 != 0) &&
             ((piVar1 = (int *)FUN_005f8460(iVar3), DAT_0097f9b8 != *piVar1 ||
              (DAT_0097f9bc != piVar1[1])))) {
            uVar5 = FUN_005f8460(iVar3);
            FUN_005fa540(0,uVar5);
          }
          FUN_005f8550(iVar3,0);
          FUN_006e5750(0xa0,&local_100,7);
          FUN_006e5750(0xad,&local_110,1);
          FUN_005fb550();
          FUN_005f8ba0(0,1);
          local_13c = local_13c + -1;
          iVar4 = iVar3;
          local_154 = iVar2;
        } while (local_13c != 0);
      }
      local_148 = local_148 + 1;
    } while (local_148 < param_6);
  }
  return;
}

