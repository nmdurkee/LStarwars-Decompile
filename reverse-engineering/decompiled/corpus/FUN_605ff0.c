/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x605ff0; label: FUN_00605ff0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00605ff0(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6,
                 char param_7,float param_8,int *param_9)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint local_144;
  uint local_12c;
  int local_124;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  undefined4 local_110;
  undefined4 local_10c;
  int local_108;
  int local_104;
  uint local_100;
  float local_fc;
  uint local_f8;
  float local_f4;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  uint local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  float local_8c;
  undefined4 local_88;
  undefined4 local_84;
  float local_80;
  float local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  float local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_e0 = 0x3e800000;
  local_dc = 0x3e800000;
  local_d8 = 0x3e800000;
  local_d4 = 0x3e800000;
  FUN_006e6c40((double)param_8);
  iVar2 = FUN_006e6b90();
  local_f8 = iVar2 * 3;
  local_f0 = (uint)*(ushort *)(DAT_0097382c + 4);
  local_100 = (uint)*(ushort *)(DAT_0097382c + 6);
  FUN_005fa0a0();
  local_124 = 0;
  if (0 < param_6) {
    do {
      if (local_124 == 0) {
        local_144 = param_2;
        iVar2 = param_1;
LAB_00606091:
        if (param_7 == '\0') goto LAB_006060e3;
        local_12c = param_4 + local_124;
        iVar3 = param_3;
      }
      else {
        if (param_7 != '\0') {
          local_144 = local_124 + -1 + param_4;
          iVar2 = param_3;
          goto LAB_00606091;
        }
        iVar2 = (param_4 + local_124) * 0x30 + -0x30 + param_3;
        local_144 = 0;
LAB_006060e3:
        iVar3 = (param_4 + local_124) * 0x30 + param_3;
        local_12c = 0;
      }
      if (0 < param_5) {
        local_f4 = (float)(int)local_f0;
        local_e4 = local_12c & 0xf;
        local_e8 = local_e4 << 4;
        local_fc = (float)(int)local_100;
        local_104 = param_5;
        do {
          local_b8 = (float)(*(ushort *)(iVar2 + 4) >> ((byte)local_144 & 0x1f) & 0xfffe);
          local_80 = param_8 / local_b8;
          uVar6 = *(ushort *)(iVar3 + 4) >> ((byte)local_12c & 0x1f) & 0xfffffffe;
          uVar7 = *(ushort *)(iVar3 + 6) >> ((byte)local_12c & 0x1f) & 0xfffffffe;
          local_b4 = (float)(*(ushort *)(iVar2 + 6) >> ((byte)local_144 & 0x1f) & 0xfffe);
          local_8c = param_8 / local_b4;
          local_88 = 0;
          local_84 = 0;
          local_78 = 0;
          local_74 = 0;
          local_68 = 0;
          local_64 = 0;
          local_58 = 0;
          local_54 = 0;
          local_48 = 0;
          local_44 = 0;
          local_38 = 0;
          local_34 = 0;
          local_28 = 0;
          local_24 = 0;
          local_18 = 0;
          local_14 = 0;
          local_90 = local_80 * -0.5;
          local_70 = local_80 * 0.5;
          local_7c = local_8c * 0.5;
          local_3c = local_8c * -0.5;
          local_6c = local_8c * -1.0;
          local_60 = local_80 * -1.0;
          local_c0 = 0x3f800000;
          local_bc = 0x3f800000;
          local_b8 = _DAT_02857270 / local_b8;
          local_b4 = _DAT_02857270 / local_b4;
          local_d0 = (float)uVar6 / local_f4;
          local_108 = DAT_00973830;
          local_cc = (float)uVar7 / local_fc;
          local_c8 = _DAT_0080e9fc / local_f4;
          local_c4 = _DAT_0080e9fc / local_fc;
          local_ec = uVar6;
          local_5c = local_7c;
          local_50 = local_70;
          local_4c = local_8c;
          local_40 = local_80;
          local_30 = local_90;
          local_2c = local_6c;
          local_20 = local_60;
          local_1c = local_3c;
          FUN_005fb870(DAT_0097382c,0,0);
          *(undefined4 *)(local_108 + 0xa0) = 1;
          FUN_005f8bf0();
          local_110 = 0;
          local_10c = 0x3f800000;
          local_120 = 0;
          local_11c = 0;
          local_118 = uVar6;
          local_114 = uVar7;
          FUN_006e57b0(&local_120);
          FUN_006e5750(0,&local_90,4);
          FUN_006e5750(4,&local_c0,1);
          FUN_006e52e0(0,&local_e0,1);
          puVar5 = (uint *)(iVar2 + 0x20);
          uVar4 = *(uint *)(iVar2 + 0x20) & 0xfca5db00 | local_144 & 0xf |
                  (local_144 & 0xf | 0xa41b0) << 4;
          *puVar5 = uVar4;
          if ((DAT_0097f9b8 != uVar4) || (DAT_0097f9bc != *(int *)(iVar2 + 0x24))) {
            FUN_005fa540(0);
          }
          FUN_006e5630(0);
          if ((DAT_0097f9c0 != *puVar5) || (DAT_0097f9c4 != *(int *)(iVar2 + 0x24))) {
            FUN_005fa540(1);
          }
          FUN_006e5630(1);
          if ((DAT_0097f9c8 != *puVar5) || (DAT_0097f9cc != *(int *)(iVar2 + 0x24))) {
            FUN_005fa540(2);
          }
          FUN_006e5630(2);
          if ((DAT_0097f9d0 != *puVar5) || (DAT_0097f9d4 != *(int *)(iVar2 + 0x24))) {
            FUN_005fa540(3);
          }
          FUN_006e5630(3);
          FUN_006e23e0();
          piVar1 = DAT_02854c28;
          if (DAT_02854c28 == (int *)0x0) {
            FUN_006e5700();
            FUN_006e5290(0);
            DAT_02854c18 = 0;
            DAT_02854c1c = 0;
          }
          else {
            if (DAT_02854c18 != *DAT_02854c28) {
              FUN_006e5700();
              DAT_02854c18 = *piVar1;
            }
            if (DAT_02854c1c != piVar1[1]) {
              FUN_006e5290();
              DAT_02854c1c = piVar1[1];
            }
          }
          if ((DAT_0097f9b8 != *puVar5) || (DAT_0097f9bc != *(int *)(iVar2 + 0x24))) {
            FUN_005fa540(0);
          }
          FUN_006e5630(0);
          if ((int)uVar7 < (int)local_100) {
            local_a0 = 0x3f800000;
            local_9c = 0;
            local_98 = 0;
            local_94 = 0x3f800000;
            FUN_006e5750(0,&local_a0);
            local_110 = 0;
            local_10c = 0x3f800000;
            local_120 = 0;
            local_114 = local_f8;
            local_11c = uVar7;
            local_118 = uVar6;
            FUN_006e57b0(&local_120);
            FUN_006e23e0();
          }
          if ((int)uVar6 < (int)local_f0) {
            local_b0 = 0;
            local_ac = 0x3f800000;
            local_a8 = 0x3f800000;
            local_11c = 0;
            local_118 = local_f8;
            local_a4 = 0;
            local_110 = 0;
            local_10c = 0x3f800000;
            local_120 = uVar6;
            local_114 = uVar7;
            FUN_006e57b0();
            FUN_006e5750(0,&local_b0,1);
            FUN_006e23e0();
          }
          iVar2 = DAT_00973830;
          FUN_005fb870(iVar3,local_12c,0);
          *(undefined4 *)(iVar2 + 0xa0) = 1;
          FUN_005f8bf0();
          local_110 = 0;
          local_10c = 0x3f800000;
          local_120 = 0;
          local_11c = 0;
          local_118 = uVar6;
          local_114 = uVar7;
          FUN_006e57b0(&local_120);
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
          FUN_006e5750(0,&local_50);
          FUN_006e5750(4,&local_d0,1);
          FUN_006e52e0(0,&local_e0,1);
          *(uint *)(iVar3 + 0x20) =
               (*(uint *)(iVar3 + 0x20) & 0xfca5dbf0 | local_e4) & 0xffffff0f | local_e8 | 0xa41b00;
          *(uint *)(DAT_0097382c + 0x20) = *(uint *)(DAT_0097382c + 0x20) & 0xffffdbff | 0x1b00;
          *(uint *)(DAT_0097382c + 0x20) = *(uint *)(DAT_0097382c + 0x20) & 0xfc25ffff | 0x240000;
          if ((DAT_0097382c != 0) &&
             ((DAT_0097f9b8 != *(uint *)(DAT_0097382c + 0x20) ||
              (DAT_0097f9bc != *(int *)(DAT_0097382c + 0x24))))) {
            FUN_005fa540(0);
          }
          FUN_006e5630(0);
          if ((DAT_0097382c != 0) &&
             ((DAT_0097f9c0 != *(uint *)(DAT_0097382c + 0x20) ||
              (DAT_0097f9c4 != *(int *)(DAT_0097382c + 0x24))))) {
            FUN_005fa540(1);
          }
          FUN_006e5630(1);
          if ((DAT_0097382c != 0) &&
             ((DAT_0097f9c8 != *(uint *)(DAT_0097382c + 0x20) ||
              (DAT_0097f9cc != *(int *)(DAT_0097382c + 0x24))))) {
            FUN_005fa540(2);
          }
          FUN_006e5630(2);
          if ((DAT_0097382c != 0) &&
             ((DAT_0097f9d0 != *(uint *)(DAT_0097382c + 0x20) ||
              (DAT_0097f9d4 != *(int *)(DAT_0097382c + 0x24))))) {
            FUN_005fa540(3);
          }
          FUN_006e5630();
          FUN_006e23e0();
          local_104 = local_104 + -1;
          local_144 = local_12c;
          iVar2 = iVar3;
        } while (local_104 != 0);
      }
      local_124 = local_124 + 1;
    } while (local_124 < param_6);
  }
  return;
}

