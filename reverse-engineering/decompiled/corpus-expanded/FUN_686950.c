/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x686950; label: FUN_00686950
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00686950(float param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  char *pcVar12;
  float *pfVar13;
  float10 fVar14;
  int local_cc;
  int *local_c8;
  int *local_c4;
  int local_c0;
  int local_b8;
  int local_b4;
  int local_b0;
  undefined1 local_a8 [12];
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  float local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar3 = FUN_004f4fc0();
  if (iVar3 == 3) {
    fVar2 = 50.0;
  }
  else {
    fVar2 = 60.0;
  }
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  do {
    if ((*(int *)((int)&DAT_0292fe18 + local_b4) != -1) &&
       ((&DAT_0292fd80)[(char)(&DAT_029300e8)[local_b4]] != 0)) {
      local_cc = 0;
      if ((&DAT_02947c7c)[(char)(&DAT_029300e8)[local_b4]] != 0) {
        FUN_005da860(local_a8,(&DAT_02947c7c)[(char)(&DAT_029300e8)[local_b4]],
                     *(int *)((int)&DAT_0292fe18 + local_b4));
        local_cc = FUN_005d0420(local_a8);
        FUN_005cffb0(local_a8);
        if (local_cc != 0) {
          switch(*(undefined4 *)((int)&DAT_0292fe24 + local_b4)) {
          case 1:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) & 0xfffffffe;
            if ((*(int *)((int)&DAT_0292fe28 + local_b4) != -1) &&
               ((&DAT_0292fb70)[*(int *)((int)&DAT_0292fe28 + local_b4)] != '\0')) {
              *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 1;
            }
            break;
          case 2:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) & 0xfffffff7;
            uVar4 = *(uint *)(local_cc + 0x50);
            if ((*(int *)((int)&DAT_0292fe28 + local_b4) != -1) &&
               ((&DAT_0292fb70)[*(int *)((int)&DAT_0292fe28 + local_b4)] != '\0')) {
LAB_00686a6b:
              if ((uVar4 & 1) == 0) {
                *(undefined4 *)(local_cc + 0x4c) = 0x3f800000;
                *(uint *)(local_cc + 0x50) = uVar4 & 0xfffffff9 | 1;
              }
            }
            break;
          case 3:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 8;
            if ((*(int *)((int)&DAT_0292fe28 + local_b4) != -1) &&
               ((&DAT_0292fb70)[*(int *)((int)&DAT_0292fe28 + local_b4)] != '\0')) {
              *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 1;
            }
            break;
          case 4:
            fVar14 = (float10)FUN_006592e0(local_b8);
            if ((float10)*(float *)((int)&DAT_0292fe2c + local_b4) <= fVar14) goto LAB_00686b41;
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 1;
            break;
          case 5:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) & 0xfffffff7;
            fVar14 = (float10)FUN_006592e0(local_b8);
            if (fVar14 < (float10)*(float *)((int)&DAT_0292fe2c + local_b4)) {
              uVar4 = *(uint *)(local_cc + 0x50);
              goto LAB_00686a6b;
            }
            break;
          case 6:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 8;
            fVar14 = (float10)FUN_006592e0(local_b8);
            if (fVar14 < (float10)*(float *)((int)&DAT_0292fe2c + local_b4))
            goto switchD_00686a0b_caseD_b;
            break;
          case 10:
            *(undefined4 *)(local_cc + 0x4c) = 0x3f800000;
LAB_00686b41:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) & 0xfffffffe;
            break;
          case 0xb:
switchD_00686a0b_caseD_b:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 1;
            break;
          case 0xc:
            *(uint *)(local_cc + 0x50) = *(uint *)(local_cc + 0x50) | 9;
          }
          if ((local_b8 == DAT_02962010) && ((DAT_02961f7c != 0 || (DAT_02924af8 != 0)))) {
            *(undefined4 *)(local_cc + 0x4c) = 0x3f800000;
          }
        }
      }
      iVar3 = FUN_005cfd60(local_a8);
      if (iVar3 != 0) {
        local_c0 = 0;
        if (0 < *(int *)((int)&DAT_0292fe1c + local_b4)) {
          pcVar12 = &DAT_0292fe34 + local_b4;
          local_c8 = (int *)((int)&DAT_0292fed4 + local_b4);
          local_c4 = (int *)((int)&DAT_0292fef4 + local_b4);
          piVar8 = (int *)((int)&DAT_0292feb4 + local_b4);
          puVar9 = (undefined4 *)((int)&DAT_0292ff14 + local_b4);
          do {
            if ((*piVar8 == -1) || (*(int *)(DAT_0296209c + *piVar8 * 4) == 0)) {
              if (*pcVar12 != '\0') {
                iVar3 = FUN_00658330(pcVar12,0,0);
                *piVar8 = iVar3;
                if (iVar3 == -1) {
                  FUN_00659a30(local_b8,local_c0);
                  local_c0 = local_c0 + -1;
                  local_c4 = local_c4 + -1;
                  local_c8 = local_c8 + -1;
                  piVar8 = piVar8 + -1;
                  puVar9 = puVar9 + -3;
                  pcVar12 = pcVar12 + -0x10;
                }
              }
            }
            else if ((*local_c4 == 0) ||
                    ((local_cc != 0 && ((*(byte *)(local_cc + 0x50) & 1) != 0)))) {
              uVar5 = FUN_005cfa20(local_a8);
              FUN_005b5b90(local_40,uVar5);
              uVar5 = FUN_005d0330(local_a8);
              FUN_005b5430(local_40,local_40,uVar5);
              local_9c = *puVar9;
              local_98 = puVar9[1];
              local_94 = puVar9[2];
              FUN_005b30a0(&local_9c,&local_9c,local_40);
              puVar10 = &DAT_00806680;
              puVar11 = local_80;
              for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
                *puVar11 = *puVar10;
                puVar10 = puVar10 + 1;
                puVar11 = puVar11 + 1;
              }
              FUN_005b5160(local_80,(int)(short)(&DAT_0292ff74)[local_b0 + local_c0]);
              FUN_005b4f70(local_80,(int)(short)(&DAT_0292ff84)[local_b0 + local_c0]);
              FUN_005b5430(local_40,local_80,local_40);
              FUN_00656d40(*piVar8,&local_9c,&DAT_0095e5c8,*local_c8,param_1 / fVar2,local_40,
                           &DAT_00806680);
            }
            local_c4 = local_c4 + 1;
            local_c8 = local_c8 + 1;
            local_c0 = local_c0 + 1;
            pcVar12 = pcVar12 + 0x10;
            piVar8 = piVar8 + 1;
            puVar9 = puVar9 + 3;
          } while (local_c0 < *(int *)((int)&DAT_0292fe1c + local_b4));
        }
        iVar3 = 0;
        if (0 < *(int *)((int)&DAT_0292fe20 + local_b4)) {
          piVar8 = (int *)((int)&DAT_02930018 + local_b4);
          local_c4 = (int *)(&DAT_0292ff98 + local_b4);
          local_c8 = (int *)((int)&DAT_02930038 + local_b4);
          pfVar13 = (float *)((int)&DAT_02930058 + local_b4);
          do {
            if (*piVar8 == -1) {
              if ((char)*local_c4 != '\0') {
                *piVar8 = -1;
                FUN_00659860(local_b8,iVar3);
                local_c8 = local_c8 + -1;
                iVar3 = iVar3 + -1;
                pfVar13 = pfVar13 + -1;
                piVar8 = piVar8 + -1;
                local_c4 = (int *)((int)local_c4 + -0x10);
              }
            }
            else {
              iVar7 = -1;
              if (*local_c8 == 1) {
                iVar7 = FUN_006e6b90();
                iVar6 = FUN_006e6b90();
                if (DAT_02962b48 / iVar7 < iVar6 / iVar7) {
LAB_00686e5a:
                  iVar7 = *piVar8;
LAB_00686e5d:
                  if (iVar7 != -1) {
                    uVar5 = FUN_005cfa20(local_a8);
                    FUN_005b5b90(local_80,uVar5);
                    uVar5 = FUN_005d0330(local_a8);
                    FUN_005b5430(local_80,local_80,uVar5);
                    local_8c = *(undefined4 *)(&DAT_02930078 + local_c0 * 0xc + local_b4);
                    iVar7 = local_c0 * 0xc + local_b4;
                    local_88 = *(undefined4 *)(&DAT_02930078 + iVar7 + 4);
                    local_84 = *(undefined4 *)(&DAT_02930078 + iVar7 + 8);
                    FUN_005b30a0(&local_8c,&local_8c,local_80);
                  }
                }
              }
              else if (local_cc != 0) {
                if ((*pfVar13 < *(float *)(local_cc + 0x4c) !=
                     (*pfVar13 == *(float *)(local_cc + 0x4c))) &&
                   (*(float *)((int)&DAT_0292ff94 + local_b4) < *pfVar13)) {
                  iVar7 = *piVar8;
                }
                if ((((*(byte *)(local_cc + 0x50) & 0x10) != 0) &&
                    (*(float *)(local_cc + 0x4c) <= *pfVar13)) &&
                   (local_90 = ABS(*(float *)((int)&DAT_0292ff94 + local_b4)), *pfVar13 < local_90))
                goto LAB_00686e5a;
                goto LAB_00686e5d;
              }
            }
            local_c8 = local_c8 + 1;
            local_c4 = (int *)((int)local_c4 + 0x10);
            iVar3 = iVar3 + 1;
            piVar8 = piVar8 + 1;
            pfVar13 = pfVar13 + 1;
          } while (iVar3 < *(int *)((int)&DAT_0292fe20 + local_b4));
        }
      }
      if (local_cc != 0) {
        fVar1 = *(float *)(local_cc + 0x4c);
        if ((*(byte *)(local_cc + 0x50) & 0x10) != 0) {
          fVar1 = -fVar1;
        }
        *(float *)((int)&DAT_0292ff94 + local_b4) = fVar1;
      }
    }
    local_b0 = local_b0 + 0x16a;
    local_b8 = local_b8 + 1;
    local_b4 = local_b4 + 0x2d4;
    if (0x5a7f < local_b0) {
      iVar3 = FUN_006e6b90();
      DAT_02962b48 = DAT_02962b48 + iVar3;
      return;
    }
  } while( true );
}

