/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64e550; label: FUN_0064e550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064e550(int param_1,undefined4 param_2,float param_3,float param_4,undefined4 *param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  float **ppfVar9;
  int *piVar10;
  float10 extraout_ST0;
  float10 fVar11;
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
  undefined4 local_124;
  int local_120;
  undefined1 local_11c [12];
  float *local_110 [7];
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 *local_ec;
  int local_e8;
  uint local_e4;
  int local_b8;
  int local_b0;
  int local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  float local_48 [12];
  float local_18;
  float local_14;
  float local_10;
  
  iVar6 = param_1 * 0x178;
  pcVar7 = &DAT_02913a58 + iVar6;
  if ((*pcVar7 != '\0') && (0.0 < (float)(&DAT_02913b24)[param_1 * 0x5e])) {
    if (param_3 < 0.0 != (param_3 == 0.0)) {
      param_3 = (float)(&DAT_02913b24)[param_1 * 0x5e];
    }
    if (param_5 == (undefined4 *)0x0) {
      param_5 = &DAT_00806680;
    }
    if (param_3 == 0.0) {
      local_148 = 0.0;
    }
    else {
      local_148 = 1.0 / param_3;
    }
    local_128 = _DAT_02920a90 + param_4;
    iVar3 = FUN_006e6b90();
    local_14c = (float)(extraout_ST0 + (float10)(float)((float10)iVar3 * extraout_ST0));
    local_120 = 0;
    if (local_14c <= local_128) {
      while (local_120 = local_120 + 1, local_120 < 100) {
        puVar8 = &DAT_00810210;
        ppfVar9 = local_110;
        for (iVar3 = 0x32; iVar3 != 0; iVar3 = iVar3 + -1) {
          *ppfVar9 = (float *)*puVar8;
          puVar8 = puVar8 + 1;
          ppfVar9 = ppfVar9 + 1;
        }
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_144 = (float)((fVar11 + fVar11) * (float10)*(float *)(&DAT_02913b2c + iVar6) -
                           (float10)*(float *)(&DAT_02913b2c + iVar6));
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_140 = (float)((fVar11 + fVar11) * (float10)*(float *)(&DAT_02913b30 + iVar6) -
                           (float10)*(float *)(&DAT_02913b30 + iVar6));
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_13c = (float)((fVar11 + fVar11) * (float10)*(float *)(&DAT_02913b34 + iVar6) -
                           (float10)*(float *)(&DAT_02913b34 + iVar6));
        FUN_005c11d0(&local_144,&local_144,param_5);
        FUN_005b37d0(&local_144,&local_144,param_2);
        local_130 = 0.0;
        local_110[1] = &local_144;
        local_138 = 0.0;
        local_134 = (float)(&DAT_02913b1c)[param_1 * 0x5e];
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_138 = (float)(((fVar11 + fVar11) * (float10)*(float *)(&DAT_02913b38 + iVar6) -
                            (float10)*(float *)(&DAT_02913b38 + iVar6)) + (float10)local_138);
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_134 = (float)(((fVar11 + fVar11) * (float10)*(float *)(&DAT_02913b3c + iVar6) -
                            (float10)*(float *)(&DAT_02913b3c + iVar6)) + (float10)local_134);
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_130 = (float)(((fVar11 + fVar11) * (float10)*(float *)(&DAT_02913b40 + iVar6) -
                            (float10)*(float *)(&DAT_02913b40 + iVar6)) + (float10)local_130);
        FUN_005c11d0(&local_138,&local_138,param_5);
        local_f4 = (&DAT_02913b20)[param_1 * 0x5e];
        local_f0 = (&DAT_02913b28)[param_1 * 0x5e];
        local_110[2] = &local_138;
        if ((&DAT_02913b08)[iVar6] == '\0') {
          iVar3 = 0;
        }
        else if (((&DAT_02913b09)[iVar6] == '\0') || ((&DAT_02913b09)[iVar6] == '\x01')) {
          FUN_005b9d90(&DAT_008102e8);
          iVar3 = FUN_006e6b90();
          iVar3 = iVar3 % (int)(char)(&DAT_02913b08)[iVar6];
        }
        else {
          iVar3 = 0;
        }
        sVar1 = (&DAT_02913ae8)[param_1 * 0xbc + iVar3];
        local_e8 = (int)sVar1;
        if (sVar1 == 9999) {
          local_ec = (undefined1 *)0x0;
        }
        else if (sVar1 != -1) {
          local_ec = local_11c;
          FUN_005da860(local_ec,(&DAT_029208d0)[pcVar7[iVar3 + 0xa8]],local_e8);
        }
        fVar11 = (float10)FUN_005b9d90(&DAT_008102e8);
        local_6c = (float)(fVar11 * (float10)(float)(&DAT_02913b18)[param_1 * 0x5e] +
                          (float10)(float)(&DAT_02913b14)[param_1 * 0x5e]);
        FUN_005b44e0(local_48);
        FUN_005b9d90(&DAT_008102e8);
        sVar1 = FUN_006e6b90();
        FUN_005b9d90(&DAT_008102e8);
        sVar2 = FUN_006e6b90();
        iVar3 = (&DAT_02913b68)[param_1 * 0x5e];
        local_12c = (float)iVar3;
        local_124 = (&DAT_02913b5c)[param_1 * 0x5e];
        FUN_005b9d90(&DAT_008102e8);
        uVar4 = FUN_006e6b90();
        local_68 = (&DAT_02913b54)[param_1 * 0x5e];
        local_12c = (float)(uVar4 & 0xffff);
        local_64 = (&DAT_02913b58)[param_1 * 0x5e];
        local_5c = (&DAT_02913b60)[param_1 * 0x5e];
        local_58 = (&DAT_02913b64)[param_1 * 0x5e];
        local_60 = local_124;
        local_54 = iVar3;
        FUN_005b4cf0(local_48,(int)sVar1);
        FUN_005b4f70(local_48,(int)sVar2);
        FUN_005b5160(local_48,(int)local_12c._0_2_);
        local_18 = local_144;
        local_14 = local_140;
        local_e4 = (&DAT_02913b6c)[param_1 * 0x5e] & 0xfff9ffff;
        local_110[0] = local_48;
        local_10 = local_13c;
        if ((&DAT_02913b70)[param_1 * 0x5e] != -1) {
          local_e4 = local_e4 | 0x40000;
          local_b0 = (&DAT_02913b70)[param_1 * 0x5e];
        }
        if ((&DAT_02913b74)[param_1 * 0x5e] != -1) {
          local_e4 = local_e4 | 0x40000;
          local_ac = (&DAT_02913b74)[param_1 * 0x5e];
        }
        if ((&DAT_02913b80)[param_1 * 0x5e] != -1) {
          local_e4 = local_e4 | 0x20000;
          local_b8 = (&DAT_02913b80)[param_1 * 0x5e];
        }
        local_a8 = (&DAT_02913b78)[param_1 * 0x5e];
        local_a0 = (&DAT_02913b84)[param_1 * 0x5e];
        local_a4 = (&DAT_02913b7c)[param_1 * 0x5e];
        if (((&DAT_02913b88)[param_1 * 0x5e] == -1) && ((&DAT_02913b8c)[iVar6] != '\0')) {
          uVar5 = FUN_0064afd0(&DAT_02913b8c + iVar6);
          (&DAT_02913b88)[param_1 * 0x5e] = uVar5;
        }
        local_78 = (&DAT_02913bb8)[param_1 * 0x5e];
        local_9c = (&DAT_02913b88)[param_1 * 0x5e];
        local_98 = (&DAT_02913b9c)[param_1 * 0x5e];
        local_74 = (&DAT_02913bbc)[param_1 * 0x5e];
        local_70 = (&DAT_02913bc0)[param_1 * 0x5e];
        FUN_0064d270(local_110);
        iVar3 = 0;
        piVar10 = &DAT_02913ba0 + param_1 * 0x5e;
        do {
          if ((*piVar10 != -1) && (pcVar7[iVar3 + 0x158] == '\x03')) {
            FUN_00681e90(*piVar10,&local_144);
          }
          iVar3 = iVar3 + 1;
          piVar10 = piVar10 + 1;
        } while (iVar3 < 4);
        (&DAT_02913bc4)[param_1 * 0x5e] = local_14c;
        local_14c = local_14c + local_148;
        if (local_128 < local_14c) {
          return;
        }
      }
    }
  }
  return;
}

