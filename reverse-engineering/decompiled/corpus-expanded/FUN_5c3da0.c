/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c3da0; label: FUN_005c3da0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c3da0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 char param_7,float param_8,int *param_9)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  int local_190;
  int local_18c;
  float local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  float local_170;
  int local_16c;
  int local_168;
  float local_164;
  double local_160;
  float local_154;
  double local_150;
  float local_144;
  undefined4 local_140;
  undefined4 local_13c;
  float local_138;
  float local_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  float local_110;
  float local_10c;
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
  
  fVar5 = (float10)FUN_006e6c40((double)param_8);
  local_188 = (float)fVar5;
  local_174 = FUN_006e6b90();
  local_174 = local_174 * 3;
  local_17c = FUN_005f7c40(DAT_0097382c);
  local_180 = FUN_005f7c50(DAT_0097382c);
  FUN_005c2760();
  local_188 = 0.0;
  if (0 < param_6) {
    do {
      iVar2 = param_2;
      iVar4 = param_1;
      if (local_188 == 0.0) {
LAB_005c3e15:
        if (param_7 == '\0') goto LAB_005c3e50;
        local_184 = (int)local_188 + param_4;
        iVar3 = param_3;
      }
      else {
        if (param_7 != '\0') {
          iVar2 = (int)local_188 + -1 + param_4;
          iVar4 = param_3;
          goto LAB_005c3e15;
        }
        iVar4 = (param_4 + (int)local_188) * 0x30 + -0x30 + param_3;
        iVar2 = 0;
LAB_005c3e50:
        iVar3 = ((int)local_188 + param_4) * 0x30 + param_3;
        local_184 = 0;
      }
      if (0 < param_5) {
        local_16c = param_5;
        local_18 = 1.0;
        local_154 = (float)local_17c;
        local_144 = (float)local_180;
        do {
          FUN_005f7c60(iVar4,iVar2,&local_178,&local_168);
          FUN_005f7c60(iVar3,local_184,&local_18c,&local_190);
          local_170 = (float)local_178;
          local_90[4] = param_8 / local_170;
          local_164 = (float)local_168;
          local_ec = param_8 / local_164;
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
          local_160 = (double)local_70;
          local_6c = 0;
          local_68 = 0x3dcccccd;
          local_64 = 0;
          local_e0 = 0;
          local_dc = local_ec * 2.0;
          local_150 = (double)local_dc;
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
          local_140 = 0x3f800000;
          local_13c = 0x3f800000;
          local_138 = _DAT_0080bf2c / local_170;
          local_134 = _DAT_0080bf2c / local_164;
          local_110 = (float)local_18c / local_154;
          local_10c = (float)local_190 / local_144;
          local_108 = _DAT_0080bf28 / local_154;
          local_104 = _DAT_0080bf28 / local_144;
          FUN_00605b60(DAT_00973830,0,DAT_0097382c,0);
          FUN_005f8bf0(DAT_00973830);
          FUN_005fa2f0(0,0,local_18c,local_190);
          FUN_006e5750(0xa0,local_90);
          FUN_006e5750(0xad,&local_140,1);
          FUN_005f7ed0(iVar4,2,2);
          if ((local_18c < local_178) || (local_190 < local_168)) {
            uVar7 = 0x100000002;
            uVar6 = 2;
          }
          else {
            uVar7 = 0x100000001;
            uVar6 = 1;
          }
          FUN_005f7d00(iVar4,uVar6,uVar7);
          FUN_005f7cc0(iVar4,iVar2);
          if ((iVar4 != 0) &&
             ((piVar1 = (int *)FUN_005f8460(), DAT_0097f9b8 != *piVar1 ||
              (DAT_0097f9bc != piVar1[1])))) {
            uVar6 = FUN_005f8460();
            FUN_005fa540(0,uVar6);
          }
          FUN_005f8550(iVar4);
          FUN_005fb550();
          piVar1 = DAT_00973818;
          if (DAT_00973818 == (int *)0x0) {
            FUN_006e5700();
            FUN_006e5290(0);
            DAT_02854c18 = 0;
            DAT_02854c1c = 0;
          }
          else {
            if (DAT_02854c18 != *DAT_00973818) {
              FUN_006e5700();
              DAT_02854c18 = *piVar1;
            }
            if (DAT_02854c1c != piVar1[1]) {
              FUN_006e5290();
              DAT_02854c1c = piVar1[1];
            }
          }
          if ((iVar4 != 0) &&
             ((piVar1 = (int *)FUN_005f8460(), DAT_0097f9b8 != *piVar1 ||
              (DAT_0097f9bc != piVar1[1])))) {
            uVar6 = FUN_005f8460();
            FUN_005fa540(0,uVar6);
          }
          FUN_005f8550(iVar4);
          if (local_190 < local_180) {
            uStack_120 = 0x3f800000;
            uStack_11c = 0;
            uStack_118 = 0;
            uStack_114 = 0x3f800000;
            FUN_006e5750(0x80,&uStack_120);
            FUN_005fa2f0(0,local_190,local_18c,local_174);
            FUN_005fb550();
          }
          if (local_18c < local_17c) {
            uStack_130 = 0;
            uStack_12c = 0x3f800000;
            uStack_128 = 0x3f800000;
            uStack_124 = 0;
            FUN_005fa2f0(local_18c,0,local_174);
            FUN_006e5750(0x80,&uStack_130,1);
            FUN_005fb550();
          }
          FUN_005f8ba0(0);
          iVar2 = local_184;
          FUN_00605b60(DAT_00973830,0,iVar3,local_184);
          FUN_005f8bf0(DAT_00973830);
          FUN_005fa2f0(0,0,local_18c,local_190);
          if (param_9 == (int *)0x0) {
            FUN_006e5700();
            FUN_006e5290(0);
            DAT_02854c18 = 0;
            DAT_02854c1c = 0;
          }
          else {
            if (DAT_02854c18 != *param_9) {
              FUN_006e5700();
              DAT_02854c18 = *param_9;
            }
            if (DAT_02854c1c != param_9[1]) {
              FUN_006e5290();
              DAT_02854c1c = param_9[1];
            }
          }
          FUN_006e5750(0xa0,&local_100);
          FUN_006e5750(0xad,&local_110,1);
          FUN_005f7ed0(iVar3,2,2);
          FUN_005f7d00(iVar3,1,1,1);
          FUN_005f7cc0(iVar3,iVar2,iVar2);
          FUN_005f7ed0(DAT_0097382c,2);
          FUN_005f7d00(DAT_0097382c,1,1,0);
          if ((DAT_0097382c != 0) &&
             ((piVar1 = (int *)FUN_005f8460(), DAT_0097f9b8 != *piVar1 ||
              (DAT_0097f9bc != piVar1[1])))) {
            uVar6 = FUN_005f8460();
            FUN_005fa540(0,uVar6);
          }
          FUN_005f8550();
          FUN_005fb550();
          FUN_005f8ba0(0,1);
          local_16c = local_16c + -1;
          iVar4 = iVar3;
        } while (local_16c != 0);
      }
      local_188 = (float)((int)local_188 + 1);
    } while ((int)local_188 < param_6);
  }
  return;
}

