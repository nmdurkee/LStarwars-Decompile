/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x685c40; label: FUN_00685c40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00685c40(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float local_10c;
  int iStack_100;
  int aiStack_fc [63];
  
  iVar6 = 0;
  uVar8 = 0xffffffff;
  iVar5 = DAT_029620a8;
  if (DAT_029620a8 != 0) {
    do {
      iVar2 = *(int *)(iVar5 + 0x1c8);
      iVar3 = *(int *)(DAT_0296209c + *(short *)(iVar5 + 0x182) * 4);
      if ((*(int *)(iVar5 + 0x2d0) != 1) || (*(char *)(iVar5 + 0x184) == '\x02')) goto LAB_00685e57;
      iVar4 = *(int *)(iVar5 + 0x2d4);
      if (iVar4 == -1) goto switchD_00685cb1_default;
      switch((&DAT_0292fb70)[iVar4]) {
      case 0:
        *(undefined1 *)(iVar5 + 0x184) = 0;
        break;
      case 1:
        *(undefined1 *)(iVar5 + 0x184) = 1;
        break;
      case 2:
        uVar8 = uVar8 + 1 & 0x1f;
        aiStack_fc[uVar8 * 2] = 3;
        goto LAB_00685cf0;
      case 3:
        uVar8 = uVar8 + 1 & 0x1f;
        aiStack_fc[uVar8 * 2] = iVar6;
        goto LAB_00685cf7;
      case 4:
        uVar8 = uVar8 + 1 & 0x1f;
        aiStack_fc[uVar8 * 2] = iVar6;
LAB_00685cf0:
        *(undefined1 *)(iVar5 + 0x184) = 2;
LAB_00685cf7:
        aiStack_fc[uVar8 * 2 + -1] = iVar4;
      }
switchD_00685cb1_default:
      if (*(char *)(iVar5 + 0x184) == '\x02') {
        FUN_00655c30(iVar5,0);
        *(short *)(iVar5 + 0x1d8) = (short)iVar6;
        fVar1 = *(float *)(iVar5 + 0x1e0) - _DAT_0296205c;
        *(float *)(iVar5 + 0x1e0) = *(float *)(iVar5 + 0x1e0) - fVar1;
        *(float *)(iVar5 + 0x1e4) = *(float *)(iVar5 + 0x1e4) - fVar1;
        *(float *)(iVar5 + 0x324) = _DAT_0296205c;
        if (*(char *)(iVar5 + 0x2f5) != '\0') {
          fVar11 = (float10)0;
          fVar9 = fVar11;
          if (DAT_02962080 != iVar6) {
            fVar9 = (float10)FUN_005becc0(iVar5 + 400,DAT_02962080,iVar6);
          }
          *(float *)(iVar5 + 0x31c) = (float)fVar9;
          if (*(float *)(iVar3 + 0x40) == 0.0) {
            if (*(float *)(iVar3 + 0x3c) == 0.0) {
              fVar1 = *(float *)(iVar3 + 0x38);
            }
            else {
              fVar1 = *(float *)(iVar3 + 0x3c);
            }
          }
          else {
            fVar1 = *(float *)(iVar3 + 0x40);
          }
          fVar10 = (float10)fVar1;
          if ((float10)(float)fVar9 < fVar10) {
            piVar7 = (int *)(iVar3 + 0x3e0);
            iVar6 = 4;
            do {
              if (*piVar7 != -1) {
                fVar10 = (float10)FUN_00650570(*piVar7);
              }
              piVar7 = piVar7 + 3;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
            fVar11 = (fVar10 - (float10)*(float *)(iVar5 + 0x31c)) / fVar10;
            iVar6 = 0;
          }
          local_10c = (float)fVar11;
          if ((float10)*(float *)(iVar5 + 0x31c) < fVar10) {
            piVar7 = (int *)(iVar3 + 0x3e0);
            iVar6 = 4;
            do {
              if ((*piVar7 != -1) && (piVar7[1] == 1)) {
                FUN_00650f20(*piVar7,iVar5 + 400,local_10c,0x3f800000);
              }
              piVar7 = piVar7 + 3;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
      }
LAB_00685e57:
      iVar5 = iVar2;
    } while (iVar2 != iVar6);
  }
  iVar5 = 0;
  while (iVar6 <= (int)uVar8) {
    (&DAT_0292fb70)[aiStack_fc[iVar5 * 2 + -1]] = (char)aiStack_fc[iVar5 * 2];
    iVar5 = iVar5 + 1;
    iVar6 = iVar5;
  }
  return;
}

