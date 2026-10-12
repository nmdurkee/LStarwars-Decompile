/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d7930; label: FUN_004d7930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d7930(float *param_1,float *param_2,float param_3,int param_4,float param_5,
                 float param_6,float param_7,float param_8)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 fVar8;
  float local_1e8;
  undefined1 local_1e4 [4];
  undefined1 local_1e0 [4];
  float local_1dc;
  float local_1d8;
  float local_1d4;
  float local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  int local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  float local_1b0 [3];
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  float local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  float local_170;
  undefined4 local_16c;
  float local_168;
  undefined4 local_164;
  float local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  float local_144;
  float local_140;
  float local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  float local_128;
  undefined4 local_124;
  float local_120;
  undefined4 local_11c;
  float local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  float local_e0;
  undefined4 local_dc;
  float local_d8;
  undefined4 local_d4;
  float local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  float local_98;
  undefined4 local_94;
  float local_90;
  undefined4 local_8c;
  float local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  undefined4 local_4c;
  double local_48;
  undefined1 local_40 [64];
  
  _DAT_00881cbc = _DAT_007ffc24 * 4.0;
  iVar2 = FUN_0056e160(3);
  if (iVar2 == 0) {
    DAT_007ffcb0 = 0xff505050;
  }
  else {
    DAT_007ffcb0 = DAT_007ffcb4;
  }
  if (param_4 == 0) {
    param_4 = DAT_00881c34;
  }
  if ((param_1 != (float *)0x0) && (param_2 != (float *)0x0)) {
    if (param_3 <= 1.0) {
      local_1e8 = param_3;
    }
    else {
      local_1e8 = 1.0;
    }
    if (0.0 <= local_1e8) {
      if (1.0 < param_3) {
        param_3 = 1.0;
      }
    }
    else {
      param_3 = 0.0;
    }
    local_1bc = *param_2 - *param_1;
    local_1b8 = param_2[1] - param_1[1];
    local_1b4 = param_2[2] - param_1[2];
    fVar5 = (float10)FUN_005bec80(&local_1bc);
    local_198 = DAT_007ffcb0;
    local_174 = DAT_007ffcb0;
    local_188 = (float)(fVar5 * (float10)param_3);
    local_150 = DAT_007ffcb0;
    local_170 = local_188 / _DAT_00881cbc;
    local_1dc = -_DAT_007ffc24;
    local_1b0[1] = 0.0;
    local_1b0[2] = _DAT_007ffc24;
    local_1a4 = 0xbf3504f4;
    local_1a0 = 0;
    local_19c = 0x3f3504f4;
    local_194 = 0;
    local_190 = 0;
    local_184 = _DAT_007ffc24;
    local_180 = 0xbf3504f4;
    local_17c = 0;
    local_178 = 0x3f3504f4;
    local_16c = 0;
    local_168 = _DAT_007ffc24;
    local_160 = _DAT_007ffc24;
    local_164 = 0;
    local_158 = 0;
    local_14c = 0;
    local_15c = 0x3f3504f4;
    local_154 = 0x3f3504f4;
    local_148 = 0x3f800000;
    local_144 = _DAT_007ffc24;
    local_13c = _DAT_007ffc24;
    local_138 = 0x3f3504f4;
    local_130 = 0x3f3504f4;
    local_134 = 0;
    local_12c = DAT_007ffcb0;
    local_124 = 0x3f800000;
    local_108 = DAT_007ffcb0;
    local_e4 = DAT_007ffcb0;
    local_120 = _DAT_007ffc24;
    local_c0 = DAT_007ffcb0;
    local_9c = DAT_007ffcb0;
    local_11c = 0;
    local_78 = DAT_007ffcb0;
    local_110 = 0;
    local_104 = 0;
    local_114 = 0x3f3504f4;
    local_10c = 0xbf3504f4;
    local_100 = 0x40000000;
    local_fc = _DAT_007ffc24;
    local_f0 = 0x3f3504f4;
    local_ec = 0;
    local_e8 = 0xbf3504f4;
    local_dc = 0x40000000;
    local_d4 = 0;
    local_c8 = 0;
    local_bc = 0;
    local_cc = 0xbf3504f4;
    local_c4 = 0xbf3504f4;
    local_b8 = 0x40400000;
    local_a8 = 0xbf3504f4;
    local_a0 = 0xbf3504f4;
    local_a4 = 0;
    local_94 = 0x40400000;
    local_8c = 0;
    local_80 = 0;
    local_74 = 0;
    local_88 = _DAT_007ffc24;
    local_84 = 0xbf3504f4;
    local_7c = 0x3f3504f4;
    local_70 = 0x40800000;
    local_54 = DAT_007ffcb0;
    local_64 = _DAT_007ffc24;
    local_60 = 0xbf3504f4;
    local_5c = 0;
    local_58 = 0x3f3504f4;
    local_4c = 0x40800000;
    local_1b0[0] = local_1dc;
    local_18c = local_1dc;
    local_140 = local_188;
    local_128 = local_170;
    local_118 = local_1dc;
    local_f8 = local_188;
    local_f4 = local_1dc;
    local_e0 = local_170;
    local_d8 = local_1dc;
    local_d0 = local_1dc;
    local_b4 = local_1dc;
    local_b0 = local_188;
    local_ac = local_1dc;
    local_98 = local_170;
    local_90 = local_1dc;
    local_6c = local_1dc;
    local_68 = local_188;
    local_50 = local_170;
    FUN_0054fec0(&local_1bc,local_1e0,local_1e4);
    FUN_004d5770();
    uVar3 = FUN_004d5810();
    FUN_005b4900(uVar3,param_1);
    FUN_005ddad0(local_1b0,10,local_40,param_4);
    iVar2 = FUN_0056e160(3);
    if ((iVar2 != 0) && (DAT_00951288 == 0)) {
      local_1dc = _DAT_00881cbc * param_7;
      local_1cc = DAT_0093b0cc;
      local_1c8 = DAT_0093b0d0;
      local_1c4 = DAT_0093b0d4;
      local_1d8 = DAT_0093b0cc;
      local_1d4 = DAT_0093b0d0;
      local_1d0 = DAT_0093b0d4;
      iVar2 = FUN_006e6b90();
      local_1c8 = 0.0;
      local_48 = (double)extraout_ST0;
      local_1c0 = iVar2;
      if ((float10)0.0 < extraout_ST0) {
        do {
          fVar6 = (float10)param_8;
          fVar7 = (float10)param_6;
          fVar5 = (float10)param_5;
          fVar8 = fVar7;
          if ((DAT_00881cb8 == 1) && (0 < iVar2)) {
            fVar8 = fVar5;
            iVar4 = FUN_006e6b90();
            fVar6 = (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] * fVar7;
            fVar5 = extraout_ST1;
          }
          fVar1 = (float)fVar6;
          if (fVar5 < fVar8 != (fVar5 == fVar8)) {
            iVar4 = FUN_006e6b90();
            fVar1 = (float)((extraout_ST0_00 + (float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff])
                           * (float10)fVar1);
          }
          local_1d8 = fVar1;
          local_1d4 = fVar1;
          local_1d0 = fVar1;
          FUN_005b45a0(local_40,&local_1d8);
          FUN_005b4900(local_40,&local_1cc);
          FUN_004d58f0();
          FUN_004d59d0();
          uVar3 = FUN_004d5810();
          FUN_005b4900(uVar3,param_1);
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x1240,local_40);
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x1250,local_40);
          FUN_005f33b0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x1260,local_40);
          local_1c8 = local_1c8 + local_1dc;
        } while (local_1c8 < (float)local_48);
      }
    }
  }
  return;
}

