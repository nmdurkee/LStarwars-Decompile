/* Ghidra pseudocode, not original source.
 * ev_e184d5b1c01771fdc7fcde98b9e576adf0de0b497982e0e92263394112c13494
 * Entry: 0x685770; label: FUN_00685770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00685770(undefined4 param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  undefined *puVar8;
  int *piVar9;
  int *piVar10;
  float10 fVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int *local_70;
  undefined4 local_6c;
  int local_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40 [16];
  
  bVar4 = false;
  if (DAT_02962050 == 0) {
    FUN_005d8400(0,0xc,&DAT_0076e1f4);
    *(undefined2 *)(DAT_0292fd68 + 0x74) = DAT_029620b0;
    local_70 = (int *)(&DAT_0292fd30)[param_2];
    if (local_70 != (int *)0x0) {
      do {
        if (*local_70 == 0) {
LAB_00685c02:
          local_70 = (int *)local_70[0x17];
        }
        else {
          iVar12 = local_70[1];
          iVar1 = local_70[2];
          if ((DAT_0296204c == 0) || (*(char *)(iVar12 + 0x12) == '\0')) {
            if ((DAT_00810904 == -1) || ((iVar1 == 0 || (*(int *)(iVar1 + 0x2d4) != DAT_00810904))))
            {
              if (*(int *)(iVar12 + 0x2a8) == 0) {
                if (DAT_02924b44 == DAT_008108fc) {
                  FUN_00657e70();
                }
                FUN_00600260(iVar12);
                if (*(int *)(iVar12 + 0x2a8) == 0) goto LAB_00685c02;
              }
              bVar3 = true;
              if (iVar1 == 0) {
                if (((*(float *)(iVar12 + 0x3c) <= 0.0) || (*(char *)(iVar12 + 0x2f3) != '\0')) ||
                   (fVar11 = (float10)FUN_006585a0(local_70 + 0x13),
                   fVar11 <= (float10)*(float *)(iVar12 + 0x3c))) {
                  piVar9 = local_70 + 3;
                  piVar10 = local_40;
                  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
                    *piVar10 = *piVar9;
                    piVar9 = piVar9 + 1;
                    piVar10 = piVar10 + 1;
                  }
                  local_64 = local_70[0x13];
                  local_60 = local_70[0x14];
                  local_5c = local_70[0x15];
                  goto LAB_00685a6e;
                }
              }
              else {
                bVar2 = false;
                iVar5 = 0;
                psVar7 = (short *)(iVar12 + 0x3d0);
                do {
                  if ((*psVar7 != -1) && (*psVar7 * 0x330 + DAT_029620a4 == iVar1)) {
                    bVar2 = true;
                    goto LAB_006858ce;
                  }
                  iVar5 = iVar5 + 1;
                  psVar7 = psVar7 + 1;
                } while (iVar5 < 8);
                if (((0.0 < *(float *)(iVar12 + 0x3c)) && (*(char *)(iVar12 + 0x2f3) == '\0')) &&
                   (*(float *)(iVar12 + 0x3c) < *(float *)(iVar1 + 0x31c))) {
                  bVar3 = false;
                }
LAB_006858ce:
                if (*(char *)(iVar1 + 0x2f7) == '\0') {
                  bVar3 = false;
                }
                if (param_2 != 4) {
                  if (!bVar3) goto LAB_00685c02;
                  if (((*(char *)(iVar12 + 0x2c) == '\0') && (*(char *)(iVar12 + 0x2f3) == '\0')) &&
                     (!bVar2)) {
                    if ((*(float *)(iVar1 + 0x300) == 0.0) || (*(int *)PTR_DAT_008109d4 != 0)) {
                      FUN_00656e50(iVar12,iVar1);
                    }
                    if (((DAT_02962928 == 0) && (*(int *)(iVar1 + 0x2fc) != 0)) &&
                       ((*(short *)(iVar1 + 0x2f2) != -1 &&
                        (iVar5 = FUN_005da3b0(*(int *)(iVar1 + 0x2fc),iVar1 + 400,
                                              *(undefined4 *)(iVar1 + 0x300),
                                              *(short *)(iVar1 + 0x2f2)), iVar5 == 0)))) {
                      bVar3 = false;
                    }
                    local_4c = *(undefined4 *)(iVar1 + 0x304);
                    local_48 = *(undefined4 *)(iVar1 + 0x308);
                    local_44 = *(undefined4 *)(iVar1 + 0x30c);
                    local_58 = *(undefined4 *)(iVar1 + 0x310);
                    local_54 = *(undefined4 *)(iVar1 + 0x314);
                    local_50 = *(undefined4 *)(iVar1 + 0x318);
                    iVar5 = FUN_006042e0(&local_4c,&local_58,iVar1,0,0);
                    if (iVar5 == 0) goto LAB_00685c02;
                  }
                }
                if (bVar3) {
                  FUN_0064ff80();
                  local_64 = *(int *)(iVar1 + 400);
                  local_60 = *(int *)(iVar1 + 0x194);
                  local_5c = *(int *)(iVar1 + 0x198);
LAB_00685a6e:
                  bVar4 = true;
                  FUN_005b4900(local_40,&local_64);
                  if (param_2 == 4) {
                    uVar6 = FUN_005d6170();
                    FUN_005c0500(local_40,local_40,uVar6);
                    local_6c = _DAT_02962068;
                    uVar6 = _DAT_02962060;
                  }
                  else {
                    local_6c = _DAT_02962064;
                    uVar6 = _DAT_0296205c;
                  }
                  *(undefined4 *)(iVar12 + 0x2ac) = uVar6;
                  if ((iVar1 == 0) || (*(char *)(iVar1 + 0x2fa) == '\0')) {
                    if (*(char *)(iVar12 + 0x412) == '\0') {
                      puVar8 = (undefined *)0x0;
                    }
                    else {
                      puVar8 = &DAT_02947c20;
                    }
                  }
                  else {
                    puVar8 = (undefined *)(iVar1 + 0xc0);
                  }
                  FUN_005ffd40(puVar8);
                  FUN_005b4c90(local_40,_DAT_00810968);
                  if (*(char *)(iVar12 + 0x2e) == '\a') {
                    uVar6 = *(undefined4 *)(iVar12 + 0x44);
                    uVar18 = *(undefined4 *)(iVar12 + 0x38);
                    uVar17 = *(undefined4 *)(iVar12 + 0x144);
                    uVar16 = *(undefined4 *)(iVar12 + 0x140);
                    uVar15 = 4;
                    uVar14 = (&DAT_0292fd4c)[*(char *)(local_70[1] + 0x2e)];
                    uVar13 = *(undefined4 *)(local_70[1] + 0x2a8);
                    iVar12 = *local_70;
                  }
                  else {
                    if (*(char *)(iVar12 + 0x2f3) == '\0') {
                      uVar6 = *(undefined4 *)(iVar12 + 0x44);
                      uVar18 = *(undefined4 *)(iVar12 + 0x38);
                      uVar17 = *(undefined4 *)(iVar12 + 0x144);
                      uVar16 = *(undefined4 *)(iVar12 + 0x140);
                      uVar15 = 0;
                    }
                    else {
                      FUN_005d4380(iVar12 + 0x2f8);
                      uVar6 = *(undefined4 *)(iVar12 + 0x44);
                      uVar18 = *(undefined4 *)(iVar12 + 0x38);
                      uVar17 = *(undefined4 *)(iVar12 + 0x144);
                      uVar16 = *(undefined4 *)(iVar12 + 0x140);
                      uVar15 = 6;
                    }
                    uVar14 = (&DAT_0292fd4c)[*(char *)(local_70[1] + 0x2e)];
                    uVar13 = *(undefined4 *)(local_70[1] + 0x2a8);
                    iVar12 = *local_70;
                  }
                  FUN_0060c410(iVar12,uVar13,uVar14,local_6c,local_40,uVar15,uVar16,uVar17,uVar18,
                               uVar6);
                }
              }
            }
            goto LAB_00685c02;
          }
          local_70 = (int *)local_70[0x17];
        }
      } while (local_70 != (int *)0x0);
      if (bVar4) {
        DAT_029620c4 = (uint)(DAT_029620c4 == 0);
      }
    }
    FUN_005d8440(0,0xc);
  }
  return;
}

