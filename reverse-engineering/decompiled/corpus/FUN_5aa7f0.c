/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5aa7f0; label: FUN_005aa7f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aa7f0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float10 fVar8;
  float10 extraout_ST0;
  float10 extraout_ST1;
  int local_54;
  int local_50;
  int local_4c;
  float local_3c;
  float local_38;
  float local_34;
  int local_30 [12];
  
  if (DAT_0095df30 != 0) {
    local_30[9] = *(int *)(param_1 + 0x5044);
    local_30[0xb] = (uint)*(byte *)(*(int *)(param_1 + 0x5040) + 0x1c) * DAT_0095df38 * 0x40;
    iVar4 = local_30[9] + local_30[0xb];
    local_30[0xb] = local_30[0xb] + iVar4;
    local_30[5] = 0;
    local_30[4] = 0;
    local_30[3] = 0;
    local_30[0] = local_30[9];
    local_30[1] = iVar4;
    local_30[2] = local_30[0xb];
    local_30[6] = 0;
    local_30[7] = 0;
    local_30[8] = 0;
    local_4c = 0;
    if (0 < DAT_0095df38) {
      local_50 = 0;
      iVar5 = DAT_0095df38;
      do {
        iVar7 = *(int *)(param_1 + 0x5040) + local_50;
        if (((*(uint *)(iVar7 + 0x20) & 4) != 0) && ((*(uint *)(iVar7 + 0x20) & 1) != 0)) {
          *(undefined4 *)(iVar7 + 8) = 0;
          local_54 = 0;
          if (*(char *)(iVar7 + 0x1c) != '\0') {
            pfVar6 = (float *)(*(int *)(iVar7 + 0x40) + 0x18);
            do {
              local_3c = pfVar6[-1];
              local_34 = pfVar6[1];
              if ((_DAT_00805d38 & DAT_00925068 + local_54) == 0) {
                if (*(float *)(iVar7 + 0x30) == 2e+06) {
                  local_38 = 10.0;
                  fVar8 = (float10)FUN_005506f0(0,&local_3c,0x40a00000,0xffffffff);
                  local_38 = (float)fVar8;
                  *pfVar6 = local_38;
                }
                else {
                  local_38 = *(float *)(iVar7 + 0x30);
                  *pfVar6 = local_38;
                }
              }
              else {
                local_38 = *pfVar6;
              }
              *(float *)(iVar7 + 8) = *(float *)(iVar7 + 8) + *pfVar6;
              iVar5 = *(int *)(&DAT_00805c94 + (*(byte *)((int)pfVar6 + -0x17) >> 2 & 3) * 4);
              iVar1 = local_30[iVar5];
              FUN_005a87d0();
              iVar3 = FUN_006e6b90();
              local_38 = ABS((float)(&DAT_029899a0)
                                    [(uint)(int)ROUND((float10)(ushort)((ushort)(*(byte *)((int)
                                                  pfVar6 + -0x17) >> 2 & 3) << 0xe) +
                                                  extraout_ST0 *
                                                  (extraout_ST1 -
                                                  ((float10)(float)(&DAT_029899a0)
                                                                   [iVar3 >> 1 & 0x7fff] +
                                                  extraout_ST1) * (float10)0.5)) >> 1 & 0x7fff]) *
                         _DAT_00805d34 + local_38;
              FUN_005b4900(iVar1,&local_3c);
              local_30[iVar5 + 3] = local_30[iVar5 + 3] + 1;
              uVar2 = *(uint *)(iVar7 + 0x18);
              local_30[iVar5] = iVar1 + 0x40;
              if ((uVar2 & 0x2000000) == 0) {
                local_30[iVar5 + 6] = local_30[iVar5 + 6] + 1;
              }
              local_54 = local_54 + 1;
              pfVar6 = pfVar6 + 8;
              iVar5 = DAT_0095df38;
            } while (local_54 < (int)(uint)*(byte *)(iVar7 + 0x1c));
          }
          *(float *)(iVar7 + 8) = *(float *)(iVar7 + 8) / (float)*(byte *)(iVar7 + 0x1c);
        }
        local_50 = local_50 + 0x54;
        local_4c = local_4c + 1;
      } while (local_4c < iVar5);
    }
    iVar5 = 0;
    local_30[0] = local_30[9];
    local_30[1] = iVar4;
    local_30[2] = local_30[0xb];
    iVar4 = 0;
    do {
      iVar7 = *(int *)((int)local_30 + iVar4);
      iVar1 = *(int *)((int)local_30 + iVar4 + 0x18);
      FUN_005ea510(iVar5 + DAT_0095df30,iVar1,iVar7,1);
      *(int *)((int)local_30 + iVar4 + 0x24) = iVar1 * 0x40 + iVar7;
      iVar5 = iVar5 + 0xc;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 0x24);
    iVar5 = 0x24;
    iVar4 = 0;
    do {
      FUN_005ea510(iVar5 + DAT_0095df30,
                   *(int *)((int)local_30 + iVar4 + 0xc) - *(int *)((int)local_30 + iVar4 + 0x18),
                   *(undefined4 *)((int)local_30 + iVar4 + 0x24),1);
      iVar5 = iVar5 + 0xc;
      iVar4 = iVar4 + 4;
    } while (iVar5 < 0x48);
  }
  return;
}

