/* Ghidra analysis pseudocode, not original source.
 * ev_8be49e78861dfe08cca82ea9c09c813f64ee3632778122cedbbea2ab2ea39171
 * Entry: 0x606d20; label: FUN_00606d20
 */

uint FUN_00606d20(int param_1,int param_2,int *param_3)

{
  float *pfVar1;
  int iVar2;
  uint uVar3;
  int extraout_EDX;
  int iVar4;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int iVar8;
  float *pfVar9;
  float *local_1bc;
  int local_1b8;
  float *local_1b4;
  float local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a0;
  float local_19c;
  float local_198;
  float local_190;
  float local_18c;
  float local_188;
  uint local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
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
  float local_80;
  float local_7c;
  float local_78;
  float *local_68;
  undefined1 local_5c [12];
  float local_50 [19];
  
  iVar4 = *(int *)(param_1 + 4);
  if ((iVar4 <= DAT_00973854) && (DAT_00973858 != 0)) {
    FUN_005f75a0();
    pfVar6 = *(float **)(extraout_EDX + 0xc);
    local_1b4 = pfVar6;
    if (param_3 == (int *)0x0) {
      local_1b4 = (float *)0x0;
    }
    local_174 = 0;
    if (iVar4 != 0) {
      local_1b8 = 0;
      iVar4 = extraout_EDX;
      do {
        iVar8 = DAT_00973858;
        puVar7 = (undefined4 *)(*(int *)(iVar4 + 0x14) + local_1b8);
        if ((((local_1b4 == (float *)0x0) && (*(char *)(puVar7 + 0xf) == -1)) &&
            (*(char *)((int)puVar7 + 0x3d) == -1)) && (*(char *)((int)puVar7 + 0x3e) == -1)) {
          *(undefined4 *)(DAT_00973858 + local_1b8) = *puVar7;
          *(undefined4 *)(iVar8 + 4 + local_1b8) = puVar7[1];
          *(undefined4 *)(iVar8 + 8 + local_1b8) = puVar7[2];
          *(undefined4 *)(iVar8 + local_1b8 + 0xc) = puVar7[3];
          iVar8 = DAT_00973858;
          *(undefined4 *)(local_1b8 + 0x10 + DAT_00973858) = puVar7[4];
          *(undefined4 *)(local_1b8 + 0x14 + iVar8) = puVar7[5];
          iVar8 = local_1b8 + 0x10 + iVar8;
          *(undefined4 *)(iVar8 + 8) = puVar7[6];
          *(undefined4 *)(iVar8 + 0xc) = puVar7[7];
          pfVar6 = (float *)(local_1b8 + 0x20 + DAT_00973858);
          *pfVar6 = (float)puVar7[8];
          pfVar6[1] = (float)puVar7[9];
          pfVar6[2] = (float)puVar7[10];
          pfVar6[3] = (float)puVar7[0xb];
        }
        else {
          local_170 = *puVar7;
          local_16c = puVar7[1];
          local_168 = puVar7[2];
          local_164 = puVar7[3];
          if (0 < (int)local_1b4) {
            iVar2 = local_174 * 0x10;
            iVar5 = 0;
            iVar8 = 8;
            local_1bc = local_1b4;
            do {
              FUN_005b3830(local_5c,*(int *)(*(int *)(iVar4 + 0x18) + 8 + iVar5) + iVar2,
                           *(undefined4 *)(*param_3 + iVar8));
              FUN_005b37d0(&local_170,&local_170,local_5c);
              iVar8 = iVar8 + 4;
              iVar5 = iVar5 + 0xc;
              local_1bc = (float *)((int)local_1bc + -1);
              iVar4 = param_1;
            } while (local_1bc != (float *)0x0);
          }
          if (*(byte *)(puVar7 + 0xf) == 0xff) {
            local_68 = local_50;
          }
          else {
            local_68 = (float *)((uint)*(byte *)(puVar7 + 0xf) * 0x40 + param_2);
          }
          if (*(byte *)((int)puVar7 + 0x3d) == 0xff) {
            pfVar6 = local_50;
          }
          else {
            pfVar6 = (float *)((uint)*(byte *)((int)puVar7 + 0x3d) * 0x40 + param_2);
          }
          if (*(byte *)((int)puVar7 + 0x3e) == 0xff) {
            pfVar9 = local_50;
          }
          else {
            pfVar9 = (float *)((uint)*(byte *)((int)puVar7 + 0x3e) * 0x40 + param_2);
          }
          FUN_005b30a0(&local_190,&local_170,local_68);
          FUN_005b30a0(&local_1a0,&local_170,pfVar6);
          FUN_005b30a0(&local_1b0,&local_170,pfVar9);
          local_b8 = (float)puVar7[0xe];
          pfVar1 = (float *)(local_1b8 + DAT_00973858);
          local_c0 = local_b8 * local_1b0;
          local_bc = local_1ac * local_b8;
          local_b8 = local_b8 * local_1a8;
          local_98 = (float)puVar7[0xd];
          local_a0 = local_98 * local_1a0;
          local_9c = local_19c * local_98;
          local_98 = local_98 * local_198;
          local_f8 = (float)puVar7[0xc];
          local_100 = local_f8 * local_190;
          local_fc = local_18c * local_f8;
          local_f8 = local_f8 * local_188;
          local_e0 = local_100 + local_a0;
          local_dc = local_fc + local_9c;
          local_d8 = local_f8 + local_98;
          local_140 = local_e0 + local_c0;
          *pfVar1 = local_140;
          local_13c = local_dc + local_bc;
          local_138 = local_d8 + local_b8;
          pfVar1[1] = local_13c;
          pfVar1[2] = local_138;
          pfVar1[3] = local_134;
          pfVar1 = (float *)(local_1b8 + 0x10 + DAT_00973858);
          local_e8 = (float)puVar7[0xe];
          local_f0 = local_e8 *
                     ((float)puVar7[6] * pfVar9[8] +
                     (float)puVar7[4] * *pfVar9 + (float)puVar7[5] * pfVar9[4]);
          local_ec = (pfVar9[9] * (float)puVar7[6] +
                     (float)puVar7[5] * pfVar9[5] + (float)puVar7[4] * pfVar9[1]) * local_e8;
          local_e8 = local_e8 *
                     (pfVar9[10] * (float)puVar7[6] +
                     (float)puVar7[4] * pfVar9[2] + (float)puVar7[5] * pfVar9[6]);
          local_118 = (float)puVar7[0xd];
          local_120 = local_118 *
                      ((float)puVar7[6] * pfVar6[8] +
                      (float)puVar7[5] * pfVar6[4] + (float)puVar7[4] * *pfVar6);
          local_11c = ((float)puVar7[6] * pfVar6[9] +
                      pfVar6[5] * (float)puVar7[5] + (float)puVar7[4] * pfVar6[1]) * local_118;
          local_118 = local_118 *
                      ((float)puVar7[6] * pfVar6[10] +
                      (float)puVar7[5] * pfVar6[6] + pfVar6[2] * (float)puVar7[4]);
          local_128 = (float)puVar7[0xc];
          local_130 = local_128 *
                      ((float)puVar7[6] * local_68[8] +
                      (float)puVar7[4] * *local_68 + (float)puVar7[5] * local_68[4]);
          local_12c = (local_68[9] * (float)puVar7[6] +
                      (float)puVar7[4] * local_68[1] + (float)puVar7[5] * local_68[5]) * local_128;
          local_128 = local_128 *
                      ((float)puVar7[6] * local_68[10] +
                      (float)puVar7[5] * local_68[6] + local_68[2] * (float)puVar7[4]);
          local_110 = local_130 + local_120;
          local_10c = local_12c + local_11c;
          local_108 = local_128 + local_118;
          local_150 = local_110 + local_f0;
          *pfVar1 = local_150;
          local_14c = local_10c + local_ec;
          pfVar1[1] = local_14c;
          local_148 = local_108 + local_e8;
          pfVar1[2] = local_148;
          pfVar1[3] = local_144;
          local_190 = local_68[8] * (float)puVar7[10] +
                      (float)puVar7[8] * *local_68 + local_68[4] * (float)puVar7[9];
          local_18c = local_68[9] * (float)puVar7[10] +
                      local_68[5] * (float)puVar7[9] + (float)puVar7[8] * local_68[1];
          local_188 = (float)puVar7[10] * local_68[10] +
                      local_68[6] * (float)puVar7[9] + local_68[2] * (float)puVar7[8];
          local_1a0 = (float)puVar7[10] * pfVar6[8] +
                      *pfVar6 * (float)puVar7[8] + (float)puVar7[9] * pfVar6[4];
          local_19c = (float)puVar7[10] * pfVar6[9] +
                      pfVar6[1] * (float)puVar7[8] + (float)puVar7[9] * pfVar6[5];
          local_198 = (float)puVar7[10] * pfVar6[10] +
                      pfVar6[2] * (float)puVar7[8] + (float)puVar7[9] * pfVar6[6];
          local_1b0 = (float)puVar7[10] * pfVar9[8] +
                      (float)puVar7[8] * *pfVar9 + (float)puVar7[9] * pfVar9[4];
          local_1ac = (float)puVar7[10] * pfVar9[9] +
                      (float)puVar7[9] * pfVar9[5] + (float)puVar7[8] * pfVar9[1];
          pfVar6 = (float *)(local_1b8 + 0x20 + DAT_00973858);
          local_1a8 = pfVar9[10] * (float)puVar7[10] +
                      pfVar9[2] * (float)puVar7[8] + (float)puVar7[9] * pfVar9[6];
          local_a8 = (float)puVar7[0xe];
          local_b0 = local_a8 * local_1b0;
          local_ac = local_1ac * local_a8;
          local_a8 = local_a8 * local_1a8;
          local_78 = (float)puVar7[0xd];
          local_80 = local_78 * local_1a0;
          local_7c = local_19c * local_78;
          local_78 = local_78 * local_198;
          local_c8 = (float)puVar7[0xc];
          local_d0 = local_c8 * local_190;
          local_cc = local_18c * local_c8;
          local_c8 = local_c8 * local_188;
          local_90 = local_d0 + local_80;
          local_8c = local_cc + local_7c;
          local_88 = local_c8 + local_78;
          local_160 = local_90 + local_b0;
          *pfVar6 = local_160;
          local_15c = local_8c + local_ac;
          pfVar6[1] = local_15c;
          local_158 = local_88 + local_a8;
          pfVar6[2] = local_158;
          pfVar6[3] = local_154;
          iVar4 = param_1;
        }
        local_174 = local_174 + 1;
        local_1b8 = local_1b8 + 0x40;
      } while (local_174 < *(uint *)(iVar4 + 4));
    }
    return CONCAT31((int3)((uint)pfVar6 >> 8),1);
  }
  uVar3 = FUN_005f7490();
  return uVar3 & 0xffffff00;
}

