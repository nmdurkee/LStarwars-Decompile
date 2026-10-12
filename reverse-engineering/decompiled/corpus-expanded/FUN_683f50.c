/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x683f50; label: FUN_00683f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00683f50(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  
  if ((*param_1 != -1) &&
     (iVar4 = *param_1 * 0x330, *(char *)(iVar4 + 0x185 + DAT_029620a4) == '\0')) {
    *(undefined1 *)(iVar4 + 0x185 + DAT_029620a4) = 1;
    if (DAT_029211e8 < DAT_02962094) {
      iVar4 = DAT_029211e8;
      do {
        if ((int)*(short *)(DAT_02962084 + iVar4 * 2) == *param_1) {
          *(undefined1 *)(*param_1 * 0x330 + 0x185 + DAT_029620a4) = 0;
          *param_1 = -1;
          return;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < DAT_02962094);
    }
    iVar4 = *param_1 * 0x330 + DAT_029620a4;
    if (*(short *)(iVar4 + 0x182) == 0) {
      *(undefined1 *)(iVar4 + 0x185) = 0;
      return;
    }
    iVar1 = *(int *)(DAT_0296209c + *(short *)(iVar4 + 0x182) * 4);
    if (*(short *)(iVar4 + 0x180) != 0) {
      do {
      } while (DAT_02962058 != 0);
      iVar4 = 0;
      DAT_02962058 = 1;
      if (0 < *(short *)(*param_1 * 0x330 + 0x180 + DAT_029620a4)) {
        do {
          FUN_00655250(*(undefined4 *)(DAT_029620a4 + 0x100 + (*param_1 * 0xcc + iVar4) * 4));
          **(undefined4 **)(DAT_02923198 + DAT_02947b70 * 4) =
               *(undefined4 *)(DAT_029620a4 + 0x100 + (*param_1 * 0xcc + iVar4) * 4);
          iVar7 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
          if (*(char *)(iVar1 + 0x2e) == '\a') {
            *(undefined4 *)(iVar7 + 8) = 7;
          }
          else {
            *(undefined4 *)(iVar7 + 8) = 0;
          }
          *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 0xc) = 0;
          bVar10 = *(char *)(iVar1 + 0x2f1) != '\x04';
          iVar7 = *(int *)(DAT_0296209c + *(short *)(*param_1 * 0x330 + 0x182 + DAT_029620a4) * 4);
          if (bVar10) {
            iVar6 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
            fVar3 = *(float *)(iVar7 + 0xa4) + _DAT_0296205c +
                    (float)(int)*(char *)(iVar7 + 0x410) * *(float *)(iVar7 + 0x414);
          }
          else {
            iVar6 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
            fVar3 = *(float *)(iVar7 + 0xa4) + _DAT_02962060 +
                    (float)(int)*(char *)(iVar7 + 0x410) * *(float *)(iVar7 + 0x414);
          }
          bVar10 = !bVar10;
          *(float *)(iVar6 + 4) = fVar3;
          iVar6 = (&DAT_0292fbfc)[bVar10];
          iVar7 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
          piVar8 = &DAT_0292fbfc + bVar10;
          while ((iVar6 != 0 && (iVar2 = *piVar8, *(float *)(iVar2 + 4) < *(float *)(iVar7 + 4)))) {
            iVar6 = *(int *)(iVar2 + 0x10);
            piVar8 = (int *)(iVar2 + 0x10);
          }
          *(int *)(iVar7 + 0x10) = *piVar8;
          *piVar8 = iVar7;
          DAT_02947b70 = DAT_02947b70 + 1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(short *)(*param_1 * 0x330 + 0x180 + DAT_029620a4));
      }
      DAT_02962058 = 0;
      iVar4 = 0;
      if (0 < DAT_008108ec + DAT_008108e8) {
        piVar8 = DAT_02961fec;
LAB_006841f2:
        if (*piVar8 != *(int *)(*param_1 * 0x330 + 0x100 + DAT_029620a4)) goto code_r0x006841f6;
        DAT_02961fec[iVar4 * 0x19 + 1] = iVar1;
        DAT_02961fec[iVar4 * 0x19 + 2] = 0;
        piVar8 = (int *)(*param_1 * 0x330 + 0x40 + DAT_029620a4);
        piVar9 = DAT_02961fec + iVar4 * 0x19 + 3;
        for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        DAT_02961fec[iVar4 * 0x19 + 0x13] = *(int *)(*param_1 * 0x330 + 400 + DAT_029620a4);
        DAT_02961fec[iVar4 * 0x19 + 0x14] = *(int *)(*param_1 * 0x330 + 0x194 + DAT_029620a4);
        DAT_02961fec[iVar4 * 0x19 + 0x15] = *(int *)(*param_1 * 0x330 + 0x198 + DAT_029620a4);
      }
    }
LAB_006842a0:
    bVar10 = false;
    psVar5 = (short *)(iVar1 + 0x3d0);
    iVar4 = 8;
    do {
      if ((int)*psVar5 == *param_1) {
        bVar10 = true;
        *psVar5 = -1;
      }
      psVar5 = psVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (!bVar10) {
      iVar4 = *param_1 * 0x330 + DAT_029620a4;
      if (*(int *)(iVar4 + 0x1cc) == 0) {
        DAT_029620a8 = *(int *)(iVar4 + 0x1c8);
        if (DAT_029620a8 != 0) {
          *(undefined4 *)(DAT_029620a8 + 0x1cc) = 0;
        }
      }
      else {
        *(undefined4 *)(*(int *)(iVar4 + 0x1cc) + 0x1c8) = *(undefined4 *)(iVar4 + 0x1c8);
        if (*(int *)(iVar4 + 0x1c8) != 0) {
          *(undefined4 *)(*(int *)(iVar4 + 0x1c8) + 0x1cc) = *(undefined4 *)(iVar4 + 0x1cc);
        }
      }
      *(undefined4 *)(iVar4 + 0x1cc) = 0;
      *(undefined4 *)(iVar4 + 0x1c8) = 0;
    }
    iVar4 = 0;
    if (0 < *(short *)(*param_1 * 0x330 + 0x180 + DAT_029620a4)) {
      do {
        *(undefined4 *)(DAT_029620a4 + 0x100 + (*param_1 * 0xcc + iVar4) * 4) = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(short *)(*param_1 * 0x330 + 0x180 + DAT_029620a4));
    }
    *(undefined2 *)(*param_1 * 0x330 + 0x180 + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x182 + DAT_029620a4) = 0;
    *(undefined2 *)(*param_1 * 0x330 + 0x32a + DAT_029620a4) = 0xffff;
    DAT_029211e8 = DAT_029211e8 + -1;
    *(short *)(DAT_02962084 + DAT_029211e8 * 2) = (short)*param_1;
    *(undefined1 *)(*param_1 * 0x330 + 0x185 + DAT_029620a4) = 0;
    *param_1 = -1;
  }
  return;
code_r0x006841f6:
  iVar4 = iVar4 + 1;
  piVar8 = piVar8 + 0x19;
  if (DAT_008108ec + DAT_008108e8 <= iVar4) goto LAB_006842a0;
  goto LAB_006841f2;
}

