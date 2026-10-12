/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c8030; label: FUN_004c8030
 */

void FUN_004c8030(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  float10 fVar9;
  float local_5c;
  int local_50;
  undefined1 local_4c [12];
  undefined4 local_40 [16];
  
  iVar3 = (int)param_1;
  local_50 = 0;
  if (0 < *(int *)((int)param_1 + 0x5064)) {
    pbVar6 = (byte *)(*(int *)((int)param_1 + 0x5060) + 0x6a);
    do {
      if ((*pbVar6 & 1) != 0) {
        iVar4 = *(int *)(iVar3 + 0x2ac0);
        pbVar7 = pbVar6 + -0x5a;
        puVar8 = local_40;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *(undefined4 *)pbVar7;
          pbVar7 = pbVar7 + 4;
          puVar8 = puVar8 + 1;
        }
        if (*(char *)(iVar4 + 0x36e) != '\0') {
          FUN_005f33b0(iVar4 + 0x360,local_40);
        }
        if ((*pbVar6 & 2) == 0) {
          iVar4 = *(short *)(pbVar6 + -8) * 0x10 + *(int *)(iVar3 + 0x2ac0);
          if (*(char *)(iVar4 + 0xe) != '\0') {
            FUN_005f33b0(iVar4,local_40);
          }
        }
        else {
          iVar4 = *(int *)(iVar3 + 0x2ac0) + *(short *)(pbVar6 + -6) * 0x10;
          if (*(char *)(iVar4 + 0xe) != '\0') {
            FUN_005f33b0(iVar4,local_40);
          }
          if (*(char *)(*(short *)(pbVar6 + -4) * 0x10 + 0xe + *(int *)(iVar3 + 0x2ac0)) != '\0') {
            local_5c = *(float *)(pbVar6 + 2);
            FUN_005b3800(local_4c,PTR_DAT_008021b4 + 0x11c,pbVar6 + -0x1a);
            fVar9 = (float10)FUN_005b39e0(local_4c,pbVar6 + 10);
            fVar1 = (float)fVar9;
            fVar9 = (float10)FUN_005bec80(local_4c);
            fVar2 = (float)fVar9 * (float)fVar9 - fVar1 * fVar1;
            if (fVar2 < 2.25) {
              if (0.5625 < fVar2) {
                fVar9 = (float10)FUN_005c0240(fVar2);
                param_1 = (float)((fVar9 - (float10)0.75) / (float10)0.75);
              }
              else {
                param_1 = 0.0;
              }
              if ((fVar1 < 0.0) || (2.0 < fVar1)) {
                if (fVar1 < 0.0) {
                  fVar1 = -fVar1;
                }
                else {
                  fVar1 = fVar1 - 2.0;
                }
                if (0.75 <= fVar1) {
                  local_5c = local_5c * 1.0;
                }
                else {
                  local_5c = (param_1 + (1.0 - param_1) * (fVar1 / 0.75)) * local_5c;
                }
              }
              else {
                local_5c = param_1 * local_5c;
              }
            }
            if (0.0 < *(float *)(pbVar6 + 6) * local_5c) {
              FUN_005ff7a0(*(short *)(pbVar6 + -4) * 0x10 + *(int *)(iVar3 + 0x2ac0),local_40,
                           *(float *)(pbVar6 + 6) * local_5c);
            }
          }
        }
      }
      local_50 = local_50 + 1;
      pbVar6 = pbVar6 + 0x94;
    } while (local_50 < *(int *)(iVar3 + 0x5064));
  }
  return;
}

