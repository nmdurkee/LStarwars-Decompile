/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x555a70; label: FUN_00555a70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00555a70(undefined4 param_1,undefined4 param_2,float *param_3,undefined4 *param_4,
                undefined4 param_5,float *param_6,float *param_7,float param_8,float param_9,
                int param_10)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  float10 fVar10;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  int local_6c;
  int local_68;
  float local_64;
  float local_60;
  float local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  int local_48;
  float local_44;
  float local_40 [2];
  float local_38;
  int local_34;
  float local_30;
  float local_28;
  float local_24;
  float local_1c;
  float local_18;
  float local_10;
  float local_c [2];
  float local_4;
  
  iVar3 = FUN_0055f450();
  local_64 = *param_7;
  local_60 = param_7[1];
  local_5c = param_7[2];
  local_58 = 0;
  if (*(int *)(iVar3 + 0x46e0) != 0) {
    local_44 = 0.0;
    local_50 = 0;
    local_24 = *param_6 - param_8;
    local_1c = param_6[2] - param_8;
    local_18 = *param_6 + param_8;
    local_10 = param_8 + param_6[2];
    iVar4 = **(int **)(iVar3 + 0x2ac8) + DAT_008025d4 * 0x14;
    if (0 < *(int *)(**(int **)(iVar3 + 0x2ac8) + 4 + DAT_008025d4 * 0x14)) {
      local_68 = 0;
      iVar6 = DAT_008025d4;
      local_54 = iVar3;
      do {
        iVar8 = *(int *)(iVar3 + 0x46e0) + local_68;
        local_34 = *(int *)(iVar4 + 0xc) + local_50 * 8;
        if (((((*(byte *)(iVar8 + 0xac) != 0) && ((*(byte *)(iVar8 + 0xac) & 0x26) == 0)) &&
             ((*(byte *)(iVar8 + 0x84) & 8) == 0)) &&
            ((local_24 <= *(float *)(iVar8 + 0x5c) && (*(float *)(iVar8 + 0x5c) <= local_18)))) &&
           ((local_1c <= *(float *)(iVar8 + 100) && (*(float *)(iVar8 + 100) <= local_10)))) {
          local_74 = *(float *)(iVar8 + 0x98) + *(float *)(iVar8 + 0x60);
          bVar2 = *(byte *)(iVar8 + 0x8b);
          if (bVar2 == 0) {
            local_4c = 0x4000;
          }
          else {
            local_4c = (uint)(0x10000 / (ulonglong)(longlong)(int)(uint)bVar2) & 0xffff;
          }
          local_48 = 0;
          uVar9 = (uint)(ushort)(*(short *)(iVar8 + 0x8c) + *(short *)(iVar8 + 0x82) +
                                *(short *)(iVar8 + 0x7c));
          uVar7 = uVar9 + 0x4000 & 0xffff;
          iVar3 = local_54;
          if (bVar2 != 0) {
            do {
              local_78 = (float)(&DAT_029899a0)[(uVar9 & 0xffff) >> 1] * *(float *)(iVar8 + 0x94) +
                         *(float *)(iVar8 + 0x5c);
              local_70 = (float)(&DAT_029899a0)[(int)((uVar9 & 0xffff) + 0x4000) >> 1 & 0x7fff] *
                         *(float *)(iVar8 + 0x94) + *(float *)(iVar8 + 100);
              local_30 = (float)(&DAT_029899a0)[(uVar7 & 0xffff) >> 1];
              local_28 = (float)(&DAT_029899a0)[(int)((uVar7 & 0xffff) + 0x4000) >> 1 & 0x7fff];
              if (param_10 == 0) {
                uVar5 = FUN_005be2d0(*(float *)(iVar8 + 0x5c) - *param_6,
                                     *(float *)(iVar8 + 100) - param_6[2]);
                FUN_005b3620(local_c,&DAT_0080250c,uVar5);
                local_7c = local_c[0] * local_30 + local_4 * local_28;
              }
              else {
                local_7c = *param_7 * local_30 + param_7[2] * local_28;
              }
              local_7c = ABS(local_7c);
              if (DAT_029959a0 < local_7c) {
                fVar10 = (float10)FUN_005b3c50(&local_78,param_6,local_40);
                fVar1 = (float)fVar10;
                if (fVar1 < param_9) {
                  if (param_10 == 0) {
                    uVar5 = FUN_005be2d0(local_78 - *param_6,local_70 - param_6[2]);
                    FUN_005b3620(&local_64,&DAT_0080250c,uVar5);
                  }
                  else {
                    local_64 = *param_7;
                    local_60 = param_7[1];
                    local_5c = param_7[2];
                  }
                  FUN_005b3b30(local_40,local_40);
                  fVar10 = (float10)FUN_005b39e0(local_40,&local_64);
                  if ((_DAT_0087a930 <= fVar1) || (param_10 == 0)) {
                    if (_DAT_0087aa54 <= fVar1) {
                      local_6c = CONCAT22(local_6c._2_2_,DAT_0087a838);
                    }
                    else {
                      local_6c = CONCAT22(local_6c._2_2_,DAT_0087a834);
                    }
                  }
                  else {
                    local_6c = CONCAT22(local_6c._2_2_,DAT_0087a958);
                  }
                  if ((float)(&DAT_029899a0)[local_6c + 0x4000 >> 1 & 0x7fff] < (float)fVar10) {
                    uVar5 = FUN_005be2d0(local_78 - *param_6,local_70 - param_6[2]);
                    FUN_005b3620(local_40,&DAT_0080250c,uVar5);
                    fVar1 = local_64 * local_40[0] + local_5c * local_38;
                    if (local_44 < fVar1) {
                      *param_4 = DAT_0093b0cc;
                      param_4[1] = DAT_0093b0d0;
                      param_4[2] = DAT_0093b0d4;
                      *param_3 = local_78;
                      param_3[1] = local_74;
                      param_3[2] = local_70;
                      local_58 = local_34;
                      local_44 = fVar1;
                    }
                  }
                }
              }
              uVar9 = uVar9 + local_4c;
              uVar7 = uVar7 + local_4c;
              local_48 = local_48 + 1;
              iVar6 = DAT_008025d4;
              iVar3 = local_54;
            } while (local_48 < (int)(uint)*(byte *)(iVar8 + 0x8b));
          }
        }
        local_68 = local_68 + 0x304;
        local_50 = local_50 + 1;
        iVar4 = **(int **)(iVar3 + 0x2ac8) + iVar6 * 0x14;
      } while (local_50 < *(int *)(**(int **)(iVar3 + 0x2ac8) + 4 + iVar6 * 0x14));
    }
    return local_58;
  }
  return 0;
}

