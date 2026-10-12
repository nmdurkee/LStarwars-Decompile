/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x683560; label: FUN_00683560
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00683560(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  bool bVar9;
  
  iVar4 = *(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4);
  iVar7 = (int)*(short *)(param_1 + 0x18c) - (int)*(short *)(param_1 + 0x180);
  if (iVar7 == 0) {
    return;
  }
  if (iVar7 < 1) {
    if ((DAT_008108e8 + DAT_008108ec) * 2 < DAT_02947b70 - iVar7) {
      return;
    }
    do {
    } while (DAT_02962058 != 0);
    DAT_02962058 = 1;
    for (iVar3 = iVar7; iVar3 < 0; iVar3 = iVar3 + 1) {
      **(undefined4 **)(DAT_02923198 + DAT_02947b70 * 4) =
           *(undefined4 *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4);
      if (*(char *)(iVar4 + 0x2e) == '\a') {
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 8) = 7;
      }
      else {
        *(undefined4 *)(*(int *)(DAT_02923198 + DAT_02947b70 * 4) + 8) = 0;
      }
      bVar9 = *(char *)(iVar4 + 0x2f1) != '\x04';
      iVar2 = *(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4);
      if (bVar9) {
        iVar6 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
        fVar1 = *(float *)(iVar2 + 0xa4) + _DAT_0296205c +
                (float)(int)*(char *)(iVar2 + 0x410) * *(float *)(iVar2 + 0x414);
      }
      else {
        iVar6 = *(int *)(DAT_02923198 + DAT_02947b70 * 4);
        fVar1 = *(float *)(iVar2 + 0xa4) + _DAT_02962060 +
                (float)(int)*(char *)(iVar2 + 0x410) * *(float *)(iVar2 + 0x414);
      }
      *(float *)(iVar6 + 4) = fVar1;
      FUN_006551d0(*(undefined4 *)(DAT_02923198 + DAT_02947b70 * 4),&DAT_0292fbfc + !bVar9);
      DAT_02947b70 = DAT_02947b70 + 1;
    }
    DAT_02962058 = 0;
    if (iVar7 == -(int)*(short *)(param_1 + 0x180)) {
      iVar4 = 0;
      if (0 < DAT_008108ec + DAT_008108e8) {
        piVar5 = DAT_02961fec;
LAB_00683c70:
        if (*piVar5 != *(int *)(param_1 + 0x100)) goto code_r0x00683c74;
        DAT_02961fec[iVar4 * 0x19 + 1] = *(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4);
        DAT_02961fec[iVar4 * 0x19 + 2] = 0;
        piVar5 = (int *)(param_1 + 0x40);
        piVar8 = DAT_02961fec + iVar4 * 0x19 + 3;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar8 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar8 = piVar8 + 1;
        }
        DAT_02961fec[iVar4 * 0x19 + 0x13] = *(int *)(param_1 + 400);
        DAT_02961fec[iVar4 * 0x19 + 0x14] = *(int *)(param_1 + 0x194);
        DAT_02961fec[iVar4 * 0x19 + 0x15] = *(int *)(param_1 + 0x198);
        *(undefined2 *)(DAT_02961fec + iVar4 * 0x19 + 0x18) = *(undefined2 *)(param_1 + 0x328);
      }
    }
    else {
      FUN_005ffea0(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar7) * 4,-iVar7);
      iVar4 = 0;
      piVar5 = DAT_02961fec;
      if (0 < DAT_008108ec + DAT_008108e8) {
LAB_00683d40:
        if (*piVar5 != 0) goto code_r0x00683d45;
        DAT_02961fec[iVar4 * 0x19] =
             *(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar7) * 4);
        DAT_02961fec[iVar4 * 0x19 + 1] = *(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4);
        DAT_02961fec[iVar4 * 0x19 + 2] = 0;
        piVar5 = (int *)(param_1 + 0x40);
        piVar8 = DAT_02961fec + iVar4 * 0x19 + 3;
        for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
          *piVar8 = *piVar5;
          piVar5 = piVar5 + 1;
          piVar8 = piVar8 + 1;
        }
        DAT_02961fec[iVar4 * 0x19 + 0x13] = *(int *)(param_1 + 400);
        DAT_02961fec[iVar4 * 0x19 + 0x14] = *(int *)(param_1 + 0x194);
        DAT_02961fec[iVar4 * 0x19 + 0x15] = *(int *)(param_1 + 0x198);
        *(undefined2 *)(DAT_02961fec + iVar4 * 0x19 + 0x18) = *(undefined2 *)(param_1 + 0x328);
        if (*(char *)(param_1 + 0x2f6) != '\0') {
          FUN_00654e00(DAT_02961fec + iVar4 * 0x19,
                       &DAT_0292fd30 +
                       *(char *)(*(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4) + 0x2f1));
        }
      }
    }
joined_r0x00683e2b:
    for (; iVar7 < 0; iVar7 = iVar7 + 1) {
      *(undefined4 *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar7) * 4) = 0;
    }
    *(short *)(param_1 + 0x180) = *(short *)(param_1 + 0x18c);
    *(short *)(param_1 + 0x186) = *(short *)(param_1 + 0x18e);
    if (*(short *)(param_1 + 0x18e) == 0) {
      return;
    }
    iVar4 = (int)*(short *)(param_1 + 0x18c);
  }
  else if (*(char *)(iVar4 + 0x2e) == '\a') {
    if (DAT_008108ec <= DAT_02947d84 + iVar7) {
      return;
    }
    iVar3 = 0;
    if (0 < iVar7) {
      do {
        *(undefined4 *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) =
             *(undefined4 *)(DAT_029211fc + (DAT_02947d84 + iVar3) * 4);
        iVar2 = 0;
        do {
          iVar2 = iVar2 + 0xc0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x94 + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x84 + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x74 + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -100 + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x54 + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x44 + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x34 + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x24 + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -0x14 + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + -4 + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xc + iVar2) = 0
          ;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x1c + iVar2) =
               0x47000000;
        } while (iVar2 < 0x180);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar7);
    }
    if (*(short *)(param_1 + 0x180) == 0) {
      iVar3 = 0;
      piVar5 = DAT_02961fec;
      if (0 < DAT_008108e8 + DAT_008108ec) {
        do {
          if (*piVar5 == 0) {
            DAT_02961fec[iVar3 * 0x19] = *(int *)(param_1 + 0x100);
            DAT_02961fec[iVar3 * 0x19 + 1] = iVar4;
            DAT_02961fec[iVar3 * 0x19 + 2] = param_1;
            *(undefined2 *)(DAT_02961fec + iVar3 * 0x19 + 0x18) = *(undefined2 *)(param_1 + 0x328);
            if (*(char *)(param_1 + 0x2f6) != '\0') {
              FUN_00654e00(DAT_02961fec + iVar3 * 0x19,&DAT_0292fd30 + *(char *)(iVar4 + 0x2f1));
            }
            break;
          }
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 0x19;
        } while (iVar3 < DAT_008108e8 + DAT_008108ec);
      }
    }
    *(short *)(param_1 + 0x180) = *(short *)(param_1 + 0x180) + (short)iVar7;
    if (*(short *)(param_1 + 0x180) == *(short *)(param_1 + 0x18c)) {
      *(undefined2 *)(param_1 + 0x186) = *(undefined2 *)(param_1 + 0x18e);
      DAT_02947d84 = DAT_02947d84 + iVar7;
      iVar4 = (int)*(short *)(param_1 + 0x180);
    }
    else {
      *(short *)(param_1 + 0x186) = *(short *)(param_1 + 0x186) + 0xc;
      DAT_02947d84 = DAT_02947d84 + iVar7;
      iVar4 = (int)*(short *)(param_1 + 0x180);
    }
  }
  else {
    if (DAT_008108e8 <= DAT_02948e98 + iVar7) {
      return;
    }
    iVar3 = 0;
    if (0 < iVar7) {
      do {
        *(undefined4 *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) =
             *(undefined4 *)(DAT_02921200 + (DAT_02948e98 + iVar3) * 4);
        iVar2 = 0;
        do {
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x2c + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x3c + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x4c + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x5c + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x6c + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x7c + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x8c + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x9c + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xac + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xbc + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xcc + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xdc + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xec + iVar2) =
               0;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0xfc + iVar2) =
               0x47000000;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x10c + iVar2) =
               0;
          iVar2 = iVar2 + 0x100;
          *(undefined4 *)
           (*(int *)(param_1 + 0x100 + (*(short *)(param_1 + 0x180) + iVar3) * 4) + 0x1c + iVar2) =
               0x47000000;
        } while (iVar2 < 0x400);
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar7);
    }
    if (*(short *)(param_1 + 0x180) == 0) {
      iVar3 = 0;
      piVar5 = DAT_02961fec;
      if (0 < DAT_008108ec + DAT_008108e8) {
        do {
          if (*piVar5 == 0) {
            DAT_02961fec[iVar3 * 0x19] = *(int *)(param_1 + 0x100);
            DAT_02961fec[iVar3 * 0x19 + 1] = iVar4;
            DAT_02961fec[iVar3 * 0x19 + 2] = param_1;
            *(undefined2 *)(DAT_02961fec + iVar3 * 0x19 + 0x18) = *(undefined2 *)(param_1 + 0x328);
            if (*(char *)(param_1 + 0x2f6) != '\0') {
              FUN_00654e00(DAT_02961fec + iVar3 * 0x19,&DAT_0292fd30 + *(char *)(iVar4 + 0x2f1));
            }
            break;
          }
          iVar3 = iVar3 + 1;
          piVar5 = piVar5 + 0x19;
        } while (iVar3 < DAT_008108ec + DAT_008108e8);
      }
    }
    *(short *)(param_1 + 0x180) = *(short *)(param_1 + 0x180) + (short)iVar7;
    if (*(short *)(param_1 + 0x180) == *(short *)(param_1 + 0x18c)) {
      *(undefined2 *)(param_1 + 0x186) = *(undefined2 *)(param_1 + 0x18e);
      DAT_02948e98 = DAT_02948e98 + iVar7;
      iVar4 = (int)*(short *)(param_1 + 0x180);
    }
    else {
      *(short *)(param_1 + 0x186) = *(short *)(param_1 + 0x186) + 0x20;
      DAT_02948e98 = DAT_02948e98 + iVar7;
      iVar4 = (int)*(short *)(param_1 + 0x180);
    }
  }
  FUN_005ffea0(param_1 + 0x100,iVar4);
  return;
code_r0x00683d45:
  iVar4 = iVar4 + 1;
  piVar5 = piVar5 + 0x19;
  if (DAT_008108ec + DAT_008108e8 <= iVar4) goto joined_r0x00683e2b;
  goto LAB_00683d40;
code_r0x00683c74:
  iVar4 = iVar4 + 1;
  piVar5 = piVar5 + 0x19;
  if (DAT_008108ec + DAT_008108e8 <= iVar4) goto joined_r0x00683e2b;
  goto LAB_00683c70;
}

