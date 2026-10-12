/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f380; label: FUN_0053f380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053f380(ushort *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  ushort *puVar4;
  float10 fVar5;
  int local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = DAT_029838e4;
  if (0 < DAT_029838e4) {
    *param_1 = DAT_02983924;
    param_1[1] = DAT_02983926;
    if (1 < iVar3) {
      local_3c = DAT_02983908;
      local_38 = DAT_0298390c;
      local_34 = DAT_02983910;
      puVar4 = &DAT_0298395c;
      iVar3 = iVar3 + -1;
      do {
        local_18 = local_3c;
        local_24 = *(float *)(puVar4 + -0xe);
        local_14 = local_38;
        local_20 = *(float *)(puVar4 + -0xc);
        local_10 = local_34;
        local_1c = *(float *)(puVar4 + -10);
        FUN_005b3800(&local_30,&local_24,&local_18);
        fVar5 = (float10)FUN_005c0240(local_28 * local_28 +
                                      local_30 * local_30 + local_2c * local_2c);
        fVar1 = (float)fVar5;
        if (fVar1 == 0.0) {
          fVar2 = 0.0;
        }
        else {
          fVar2 = 1.0 / fVar1;
        }
        local_30 = fVar2 * local_30;
        local_2c = fVar2 * local_2c;
        local_28 = fVar2 * local_28;
        FUN_005b3800(&local_c,&DAT_029838f0,&local_18);
        fVar2 = local_4 * local_28 + local_c * local_30 + local_8 * local_2c;
        if (0.0 < fVar2) {
          if (NAN(fVar2) || 1.0 < fVar2 == (fVar2 == 1.0)) {
            fVar2 = fVar2 / fVar1;
            local_40 = (uint)*puVar4 - (uint)*param_1;
            if (local_40 < 0x8001) {
              if (local_40 < -0x8000) {
                local_40 = local_40 + 0x10000;
              }
            }
            else {
              local_40 = local_40 + -0x10000;
            }
            local_40._0_2_ = (short)(int)ROUND(fVar2 * (float)local_40);
            *param_1 = (short)local_40 + *param_1;
            local_40 = (uint)puVar4[1] - (uint)param_1[1];
            if (local_40 < 0x8001) {
              if (local_40 < -0x8000) {
                local_40 = local_40 + 0x10000;
              }
            }
            else {
              local_40 = local_40 + -0x10000;
            }
            local_40._0_2_ = (short)(int)ROUND((float)local_40 * fVar2);
            param_1[1] = (short)local_40 + param_1[1];
            local_3c = local_3c + fVar2 * (local_24 - local_3c);
            local_38 = local_38 + fVar2 * (local_20 - local_38);
            local_34 = local_34 + (local_1c - local_34) * fVar2;
          }
          else {
            *param_1 = *puVar4;
            param_1[1] = puVar4[1];
            local_3c = local_24;
            local_38 = local_20;
            local_34 = local_1c;
          }
        }
        puVar4 = puVar4 + 0x1c;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return;
}

