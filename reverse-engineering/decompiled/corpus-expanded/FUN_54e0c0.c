/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54e0c0; label: FUN_0054e0c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054e0c0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  float *pfVar8;
  float10 fVar9;
  int local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  int local_28;
  float *local_20;
  float *local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar7 = *(int *)(param_1 + 0x5080);
  local_28 = 0;
  if (0 < *(int *)(param_1 + 0x5084)) {
    local_2c = 0;
    local_30 = 0;
    do {
      if (((*(byte *)(iVar7 + 0x1e) & 1) != 0) && ((*(byte *)(iVar7 + 0x1e) & 2) != 0)) {
        if (0.0 < *(float *)(iVar7 + 0x58)) {
          *(float *)(iVar7 + 0x58) = *(float *)(iVar7 + 0x58) - _DAT_00925018;
        }
        iVar3 = FUN_005cfac0(iVar7 + 0xec);
        if (iVar3 != 0) {
          puVar4 = (undefined4 *)FUN_005cf9e0(iVar7 + 0xec);
          puVar6 = (undefined4 *)(iVar7 + 0x30);
          *puVar6 = *puVar4;
          *(undefined4 *)(iVar7 + 0x34) = puVar4[1];
          *(undefined4 *)(iVar7 + 0x38) = puVar4[2];
          *(undefined4 *)(iVar7 + 0x3c) = *puVar6;
          *(float *)(iVar7 + 0x40) = *(float *)(iVar7 + 0x34) - 0.1;
          *(undefined4 *)(iVar7 + 0x44) = *(undefined4 *)(iVar7 + 0x38);
          *(undefined4 *)(iVar7 + 0x24) = *puVar6;
          *(undefined4 *)(iVar7 + 0x2c) = *(undefined4 *)(iVar7 + 0x38);
          fVar9 = (float10)FUN_005506f0(0,puVar6,0x40a00000,0xffffffff);
          fVar1 = (float)fVar9;
          *(float *)(iVar7 + 0x28) = fVar1;
          if (fVar1 != 2e+06) {
            *(float *)(iVar7 + 0x28) = fVar1 + 0.005;
            FUN_0054fec0(&DAT_0292fdb8,iVar7 + 0x48,iVar7 + 0x4a);
          }
        }
        if ((*(byte *)(iVar7 + 0x1e) & 4) != 0) {
          iVar3 = FUN_0054d410(iVar7,0,0);
          if (iVar3 == 0) {
            fVar1 = *(float *)(iVar7 + 0x50);
            fVar2 = *(float *)(iVar7 + 0x50) * 0.0125;
            fVar9 = (float10)FUN_005b7d30(_DAT_0092505c,0x3fc00000);
            local_18 = (float)(&DAT_029899a0)
                              [(int)(((int)ROUND((fVar9 / (float10)1.5) * (float10)65536.0) &
                                     0xffffU) + local_30) >> 1 & 0x7fff] * fVar2 +
                       *(float *)(iVar7 + 0x30);
            local_14 = *(float *)(iVar7 + 0x34) - fVar1 * 0.333;
            fVar9 = (float10)FUN_005b7d30(_DAT_0092505c,0x3f9bc6a8);
            local_10 = (float)(&DAT_029899a0)
                              [(int)(((int)ROUND((fVar9 / (float10)1.2170000076293945) *
                                                 (float10)65536.0) & 0xffffU) + local_2c) >> 1 &
                               0x7fff] * fVar2 + *(float *)(iVar7 + 0x38);
          }
          else {
            iVar5 = FUN_0054dc30();
            pfVar8 = local_1c;
            if (iVar5 != 2) {
              pfVar8 = local_20;
            }
            local_18 = *pfVar8;
            local_14 = pfVar8[1];
            local_10 = pfVar8[2];
          }
          fVar9 = (float10)FUN_005becc0(&local_18,iVar7 + 0x30,&local_c);
          local_34 = (float)fVar9;
          if (*(float *)(iVar7 + 0x50) <= local_34) {
            local_34 = 0.0;
            local_38 = 0.0;
          }
          else {
            fVar1 = 1.0 / local_34;
            local_c = fVar1 * local_c;
            local_8 = local_8 * fVar1;
            local_4 = fVar1 * local_4;
            local_34 = *(float *)(iVar7 + 0x50) - local_34;
            local_38 = local_34 / 6.0;
          }
          local_3c = 0;
          pfVar8 = (float *)(iVar7 + 0xa4);
          do {
            fVar1 = (float)local_3c * local_38 + local_38;
            *pfVar8 = local_18 + fVar1 * local_c;
            pfVar8[1] = local_8 * fVar1 + local_14;
            pfVar8[2] = fVar1 * local_4 + local_10;
            if ((iVar3 != 0) && (0.0 < local_34)) {
              fVar1 = ((float)(local_3c + 1) / 6.0) * local_34 * 0.1;
              fVar9 = (float10)FUN_005b7d30(_DAT_0092505c,0x3fc00000);
              *pfVar8 = (float)(&DAT_029899a0)
                               [(int)(((int)ROUND((fVar9 / (float10)1.5) * (float10)65536.0) &
                                      0xffffU) + local_30) >> 1 & 0x7fff] * fVar1 + *pfVar8;
              fVar9 = (float10)FUN_005b7d30(_DAT_0092505c,0x3f9bc6a8);
              pfVar8[2] = (float)(&DAT_029899a0)
                                 [(int)(((int)ROUND((fVar9 / (float10)1.2170000076293945) *
                                                    (float10)65536.0) & 0xffffU) + local_2c) >> 1 &
                                  0x7fff] * fVar1 + pfVar8[2];
            }
            local_3c = local_3c + 1;
            pfVar8 = pfVar8 + 3;
          } while (local_3c < 6);
          puVar6 = &DAT_00802468;
          iVar3 = iVar7 + 0x5c;
          do {
            FUN_0054fb80(iVar3,iVar3,iVar3 + 0x48,*puVar6);
            puVar6 = puVar6 + 1;
            iVar3 = iVar3 + 0xc;
          } while ((int)puVar6 < 0x802480);
        }
      }
      local_30 = local_30 + 0x2000;
      local_2c = local_2c + 0x2666;
      local_28 = local_28 + 1;
      iVar7 = iVar7 + 0xf8;
    } while (local_28 < *(int *)(param_1 + 0x5084));
  }
  pfVar8 = (float *)&DAT_00926cb0;
  iVar3 = 4;
  iVar7 = DAT_00802858;
  do {
    if (0.0 < *pfVar8) {
      *pfVar8 = *pfVar8 - _DAT_00925018;
    }
    fVar1 = pfVar8[-1];
    if ((fVar1 != 0.0) && (*(char *)((int)pfVar8 + -0x3b) == '\0')) {
      if (((*(uint *)((int)fVar1 + 0x1fc) & 1) == 0) ||
         (((*(uint *)((int)fVar1 + 0x1fc) & 0x1000) == 0 || (*(char *)((int)fVar1 + 0x28b) != '\0'))
         )) {
        pfVar8[-1] = 0.0;
      }
      else if (((*(int *)((int)fVar1 + 0xcd0) != 0) && (iVar7 != -1)) &&
              (*(char *)(*(int *)((int)fVar1 + 0xcd0) + 0x7b5) == iVar7)) {
        pfVar8[-0x12] = *(float *)((int)fVar1 + 0x19c);
        pfVar8[-0x11] = *(float *)((int)fVar1 + 0x1a0);
        pfVar8[-0x10] = *(float *)((int)fVar1 + 0x1a4);
        *(short *)(pfVar8 + -0xe) = *(short *)((int)fVar1 + 0x27a) + -0x8000;
        FUN_0054d1d0();
        iVar7 = DAT_00802858;
        *(undefined1 *)(pfVar8 + -0xf) = 1;
        goto LAB_0054e612;
      }
      *(byte *)((int)pfVar8 + -0x3a) = *(byte *)((int)pfVar8 + -0x3a) & 0xfd;
    }
LAB_0054e612:
    pfVar8 = pfVar8 + 0x3e;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}

