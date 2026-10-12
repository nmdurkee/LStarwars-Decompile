/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fbd80; label: FUN_005fbd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fbd80(int param_1,int param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float *pfVar9;
  int local_1a0;
  int local_19c;
  uint local_198;
  int local_190;
  uint local_18c;
  int local_184;
  float local_180;
  float local_17c;
  float local_178;
  int local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_150;
  float local_14c;
  float local_148;
  float local_140;
  float local_13c;
  float local_138;
  float local_130;
  float local_12c;
  float local_128;
  float local_120;
  float local_11c;
  float local_118;
  float local_110;
  float local_10c;
  float local_108;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a0;
  float local_9c;
  float local_98;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 local_7c [12];
  float local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  float local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  float local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_1c [24];
  
  local_18c = 0;
  if (*(int *)(param_2 + 8) != 0) {
    local_190 = 0;
    do {
      puVar3 = (uint *)(*(int *)(param_2 + 0x10) + local_190);
      pfVar9 = (float *)(DAT_00973858 + puVar3[2] * 0xc0);
      local_198 = 0;
      if (*puVar3 != 0) {
        do {
          puVar8 = (undefined4 *)((puVar3[1] + local_198) * 0x70 + *(int *)(param_2 + 0xc));
          local_b8 = (float)puVar8[0x12];
          puVar6 = (undefined4 *)(*param_3 * 0x50 + DAT_00973860);
          local_c0 = local_b8 * pfVar9[0x20];
          local_bc = pfVar9[0x21] * local_b8;
          local_b8 = local_b8 * pfVar9[0x22];
          local_108 = (float)puVar8[0x11];
          local_110 = local_108 * pfVar9[0x10];
          local_10c = pfVar9[0x11] * local_108;
          local_108 = local_108 * pfVar9[0x12];
          local_148 = (float)puVar8[0x10];
          local_150 = local_148 * *pfVar9;
          local_14c = pfVar9[1] * local_148;
          local_148 = local_148 * pfVar9[2];
          local_100 = local_150 + local_110;
          local_fc = local_10c + local_14c;
          local_f8 = local_148 + local_108;
          local_a0 = local_100 + local_c0;
          local_9c = local_fc + local_bc;
          local_98 = local_f8 + local_b8;
          local_128 = (float)puVar8[0x12];
          local_130 = local_128 * pfVar9[0x24];
          local_12c = pfVar9[0x25] * local_128;
          local_128 = local_128 * pfVar9[0x26];
          local_118 = (float)puVar8[0x11];
          local_120 = local_118 * pfVar9[0x14];
          local_11c = pfVar9[0x15] * local_118;
          local_118 = local_118 * pfVar9[0x16];
          local_d8 = (float)puVar8[0x10];
          local_e0 = local_d8 * pfVar9[4];
          local_dc = local_d8 * pfVar9[5];
          local_d8 = local_d8 * pfVar9[6];
          local_140 = local_e0 + local_120;
          local_13c = local_dc + local_11c;
          local_138 = local_d8 + local_118;
          local_180 = local_140 + local_130;
          local_17c = local_13c + local_12c;
          local_178 = local_138 + local_128;
          local_88 = (float)puVar8[0x12];
          local_90 = local_88 * pfVar9[0x28];
          local_8c = pfVar9[0x29] * local_88;
          local_88 = local_88 * pfVar9[0x2a];
          local_c8 = (float)puVar8[0x11];
          local_d0 = local_c8 * pfVar9[0x18];
          local_cc = pfVar9[0x19] * local_c8;
          local_c8 = local_c8 * pfVar9[0x1a];
          local_e8 = (float)puVar8[0x10];
          local_f0 = local_e8 * pfVar9[8];
          local_ec = pfVar9[9] * local_e8;
          local_e8 = local_e8 * pfVar9[10];
          local_b0 = local_f0 + local_d0;
          local_ac = local_ec + local_cc;
          local_a8 = local_e8 + local_c8;
          local_160 = local_b0 + local_90;
          local_15c = local_ac + local_8c;
          local_158 = local_a8 + local_88;
          FUN_005b3920(&local_30,&local_180,&local_160);
          if (((int)puVar8[0x18] < 0) || (*(uint *)(param_1 + 8) < 2)) {
            *puVar6 = *puVar8;
            puVar6[1] = puVar8[1];
            puVar6[2] = puVar8[2];
            puVar6[3] = puVar8[3];
            puVar6[4] = puVar8[4];
            puVar6[5] = puVar8[5];
            puVar6[6] = puVar8[6];
            puVar6[7] = puVar8[7];
            puVar6[8] = puVar8[8];
            puVar6[9] = puVar8[9];
            puVar6[10] = puVar8[10];
            puVar6[0xb] = puVar8[0xb];
            puVar6[0xc] = puVar8[0xc];
            puVar6[0xd] = puVar8[0xd];
            puVar6[0xe] = puVar8[0xe];
            puVar6[0xf] = puVar8[0xf];
          }
          else {
            *puVar6 = *puVar8;
            puVar6[1] = puVar8[1];
            puVar6[2] = puVar8[2];
            local_1a0 = 1;
            puVar6[3] = puVar8[3];
            local_164 = (int)puVar8 - (int)puVar6;
            puVar5 = puVar6;
            do {
              puVar7 = puVar5 + 4;
              FUN_005b3800(local_1c,local_164 + (int)puVar7,local_164 + -0x10 + (int)puVar7);
              *puVar7 = *puVar5;
              puVar5[5] = puVar5[1];
              puVar5[6] = puVar5[2];
              puVar5[7] = puVar5[3];
              piVar4 = puVar8 + 0x18;
              local_184 = 0;
              do {
                iVar2 = *piVar4;
                if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 8))) {
                  bVar1 = *(byte *)(local_184 + 0x6c + (int)puVar8);
                  FUN_005b30a0(local_7c,local_1c,
                               (local_1a0 + iVar2 * 3) * 0x40 + -0x40 + *(int *)(param_1 + 0x10));
                  FUN_005b3830(local_7c,local_7c,(float)bVar1 * 0.003921569);
                  FUN_005b37d0(puVar7,puVar7,local_7c);
                }
                local_184 = local_184 + 1;
                piVar4 = piVar4 + 1;
              } while (local_184 < 3);
              local_1a0 = local_1a0 + 1;
              puVar5 = puVar7;
            } while (local_1a0 < 4);
          }
          local_70 = local_160;
          local_19c = 4;
          local_6c = local_15c;
          local_68 = local_158;
          local_64 = 0;
          local_60 = local_30;
          local_5c = local_2c;
          local_58 = local_28;
          local_54 = 0;
          local_50 = local_180;
          local_4c = local_17c;
          local_48 = local_178;
          local_44 = 0;
          local_40 = local_a0;
          local_3c = local_9c;
          local_38 = local_98;
          local_34 = 0x3f800000;
          puVar5 = puVar6;
          do {
            FUN_005b30a0(puVar5,puVar5,&local_70);
            puVar5 = puVar5 + 4;
            local_19c = local_19c + -1;
          } while (local_19c != 0);
          puVar6[0x10] = local_180;
          puVar6[0x11] = local_17c;
          puVar6[0x12] = local_178;
          puVar6[0x13] = 0;
          puVar6[3] = puVar8[0x14];
          puVar6[7] = puVar8[0x15];
          puVar6[0xb] = puVar8[0x16];
          puVar6[0xf] = puVar8[0x17];
          *param_3 = *param_3 + 1;
          local_198 = local_198 + 1;
        } while (local_198 < *puVar3);
      }
      local_190 = local_190 + 0xc;
      local_18c = local_18c + 1;
    } while (local_18c < *(uint *)(param_2 + 8));
  }
  return 1;
}

