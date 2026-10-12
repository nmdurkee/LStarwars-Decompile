/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x685570; label: FUN_00685570
 */

void FUN_00685570(undefined4 param_1)

{
  int *piVar1;
  short sVar2;
  int *piVar3;
  bool bVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  short *psVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int local_8;
  int local_4;
  
  local_8 = 0;
  if (0 < DAT_02962094) {
    local_4 = 0;
    do {
      sVar2 = *(short *)(local_4 + 0x182 + DAT_029620a4);
      iVar7 = local_4 + DAT_029620a4;
      if (sVar2 != 0) {
        iVar11 = *(int *)(DAT_0296209c + sVar2 * 4);
        bVar4 = false;
        iVar5 = 0;
        psVar8 = (short *)(iVar11 + 0x3d0);
        do {
          if (local_8 == *psVar8) {
            bVar4 = true;
            break;
          }
          iVar5 = iVar5 + 1;
          psVar8 = psVar8 + 1;
        } while (iVar5 < 8);
        if (bVar4) {
          if (*(short *)(iVar7 + 0x188) != 0) {
            iVar5 = 0;
            if (0 < *(short *)(iVar7 + 0x188)) {
              piVar1 = &DAT_0292fbfc + (*(char *)(iVar11 + 0x2f1) == '\x04');
              piVar10 = (int *)(iVar7 + 0x100);
LAB_00685617:
              piVar6 = (int *)*piVar1;
              if (piVar6 != (int *)0x0) {
                do {
                  if (*piVar6 == *piVar10) {
                    piVar9 = piVar1;
                    if (*piVar1 == 0) goto LAB_0068564a;
                    goto LAB_00685634;
                  }
                  piVar6 = (int *)piVar6[4];
                } while (piVar6 != (int *)0x0);
              }
              goto LAB_00685669;
            }
LAB_0068567e:
            *(undefined2 *)(iVar7 + 0x188) = 0;
          }
          FUN_00683e90(local_4 + DAT_029620a4,0);
        }
        else {
          FUN_005b5700(iVar7 + 0x40,param_1,iVar7 + 0x40);
          iVar7 = local_4 + 400 + DAT_029620a4;
          FUN_005b30a0(iVar7,iVar7,param_1);
          *(undefined4 *)(local_4 + 0x300 + DAT_029620a4) = 0;
        }
      }
      local_8 = local_8 + 1;
      local_4 = local_4 + 0x330;
    } while (local_8 < DAT_02962094);
  }
  if (0 < DAT_008108ec + DAT_008108e8) {
    iVar11 = 0;
    iVar5 = 0;
    iVar7 = DAT_02961fec;
    do {
      if ((*(int *)(iVar11 + iVar7) != 0) && (*(int *)(iVar11 + 8 + iVar7) == 0)) {
        iVar7 = iVar11 + 0xc + iVar7;
        FUN_005b5700(iVar7,param_1,iVar7);
        iVar7 = iVar11 + 0x4c + DAT_02961fec;
        FUN_005b30a0(iVar7,iVar7,param_1);
        iVar7 = DAT_02961fec;
      }
      iVar5 = iVar5 + 1;
      iVar11 = iVar11 + 100;
    } while (iVar5 < DAT_008108ec + DAT_008108e8);
  }
  return;
  while (piVar9 = piVar3 + 4, piVar3[4] != 0) {
LAB_00685634:
    piVar3 = (int *)*piVar9;
    if (piVar3 == piVar6) {
      *piVar9 = piVar6[4];
      break;
    }
  }
LAB_0068564a:
  piVar6[4] = 0;
  DAT_02947b70 = DAT_02947b70 + -1;
  *(int **)(DAT_02923198 + DAT_02947b70 * 4) = piVar6;
LAB_00685669:
  iVar5 = iVar5 + 1;
  piVar10 = piVar10 + 1;
  if (*(short *)(iVar7 + 0x188) <= iVar5) goto LAB_0068567e;
  goto LAB_00685617;
}

